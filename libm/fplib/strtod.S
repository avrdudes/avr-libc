/*  -*- Mode: Asm -*-  */

/* Copyright (c) 2002  Michael Stumpf  <mistumpf@de.pepperl-fuchs.com>
   All rights reserved.


   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.
   
   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.
     
   * Neither the name of the copyright holders nor the names of
     contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
   ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
   POSSIBILITY OF SUCH DAMAGE. 
*/

/* $Id$ */

/*
    strtod.S is an addition to     FPlib V 0.3.0       ported to avr-as
    for details see readme.strtod

  double[rP0:rP1:rP2:rP3] strtod(const char * s[rP0:rP1], char ** endptr[rP2:rP3] )

 *----------------------------------------------------------------------------------------------
 */

#if !defined(DOXYGEN)

#include "gasava.inc"
#include "fplib.inc"

#define rFlags   rSI0  /*  */
#define rCh      rSI1

; YH:YL pointer to actual char
; temp : rS3::rS0

#define rFracPower rS4
#define rDPshift rS5
#define rEndptrH rS6
#define rEndptrL rS7

#define bitNegative     7
#define bitPoint        6
#define bitDigit        5
#define bitExpSign      6

#ifndef _BV
  #define _BV(x) (1 << (x))
#endif

	PGM_SECTION

.L_10p1:	DCB	0x41,0x20,0x00,0x00
.L_10p2:	DCB	0x42,0xC8,0x00,0x00
.L_10p4:	DCB	0x46,0x1C,0x40,0x00
.L_10p8:	DCB	0x4C,0xBE,0xBC,0x20
.L_10p16:	DCB	0x5A,0x0E,0x1B,0xCA
.L_10p32:	DCB	0x74,0x9D,0xC5,0xAE

.L_10p_1:	DCB	0x3D,0xCC,0xCC,0xCD
.L_10p_2:	DCB	0x3C,0x23,0xD7,0x0A
.L_10p_4:	DCB	0x38,0xD1,0xB7,0x17
.L_10p_8:	DCB	0x32,0x2B,0xCC,0x77
.L_10p_16:	DCB	0x24,0xE6,0x95,0x95
.L_10p_32:	DCB	0x0A,0x4F,0xB1,0x1F

	TEXT_SEG(fplib, strtod)
	FUNCTION(atof)
GLOBAL(atof)
	clr	rP2
	clr	rP3			; clear *endptr

	.size atof, .-atof
	ENDFUNC

	FUNCTION(strtod)
GLOBAL(strtod)
	rcall	.L_strtod_prologue

	MOV	YL,rP1
	MOV	YH,rP0	 ; load pointer to Y in case displacement is needed
	PUSH	rP2
	PUSH	rP3	 ; needed at end of function
	MOV	rEndptrH,YH
	MOV	rEndptrL,YL ; assume no valid float at all

; skip white space
1:
	LD	rCh,Y+
	CPI	rCh,' '
	BREQ	1b
	CPI	rCh,'\t'
	BREQ	1b
	CPI	rCh,'\v'
	BREQ	1b
	CPI	rCh,'\f'
	BREQ	1b
	CPI	rCh,'\n'
	BREQ	1b
	CPI	rCh,'\r'
	BREQ	1b

	; now scan fraction
	RCALL	.L_scanSign
	RCALL	.L_scanDigits

	; if T set now there must be a fraction failure : rA still 0!
	BRTS	99f

	RCALL	_U(__floatunssisf)
	BST	rFlags,bitNegative
	BLD	rA3,7	       ; set sign
	MOV	rS3,rA3
	MOV	rS2,rA2
	MOV	rS1,rA1
	MOV	rS0,rA0

	; now scan for exponent
	CLR	rA2		; preset exponent

	ORI	rCh,0x20	; 'E' -> 'e'
	CPI	rCh,'e'
	BRNE	4f		; is there any ?

	LD	rCh,Y+
	RCALL	.L_scanSign
	RCALL	.L_scanExponent

	TST	rA3
	BREQ	3f
	SBRC	rFlags,bitNegative  ; set sign
	RJMP	.L_underflow
	RJMP	.L_overflow
3:
	SBRC	rFlags,bitNegative  ; set sign
	NEG	rA2
4:

; now evaluate fp number
; we got a string	  -123.456e+2
; what we have is	  fraction(rS3::rS0) = 123456.0	   with rFracPower = 5
;			  exponent(rA2)	     = +2	   with rDPshift = -3
;			  the result is fraction * 10**(exponent+rDPshift)
;			  overflow/underflow control must include rFracPower
	LDI	ZL,LOW(.L_10p1)
	LDI	ZH,HIGH(.L_10p1) ; pointer to array with 10^n

#define rExp rFlags

	MOV	rExp,rA2

	MOV	rA3,rS3
	MOV	rA2,rS2
	MOV	rA1,rS1
	MOV	rA0,rS0		; move fraction to rA
	ANDI	rA3,0x7F	; positive

	CP	rA3,rA2
	CPC	rA2,rA1
	CPC	rA1,rA0
	CPC	rA0,__zero_reg__
	BREQ	99f		; test for zero

	ADD	rExp,rDPshift	; exponent correction
	BRPL	.L_expPositive

.L_expNegative:
	NEG	rExp
	ADIW	ZL,(.L_10p_1-.L_10p1)

	MOV	rA3,rExp
	SUB	rA3,rFracPower
	CPI	rA3,39
	BRGE	.L_underflow
	RJMP	.L_combineExponent

.L_expPositive:
	MOV	rA3,rExp
	ADD	rA3,rFracPower
	CPI	rA3,39
	BRGE	.L_overflow
	; RJMP	  _combineExponent
.L_combineExponent:
	MOV    rA3,rS3		; load right sign again
.L_expPower10:
	TST    rExp
	BREQ   99f
	ASR    rExp
	BRCC   .L_nextPower

	RCALL  __fp_flashconst	; load constnat to B

	PUSH   R30
	PUSH   R31
	RCALL  _U(__mulsf3)	; AX *= BX, sign stays untouched
	POP    R31
	POP    R30
#ifdef __ERRNO__
	BST    rA2,7		; if ERRNO
	MOV    rB3,rA3		; check for overflow / underflow
	ADD    rB3,rB3
	BLD    rB3,0
	TST    rB3
	BREQ   .L_underflow
	CPI    rB3,0xFF
	BREQ   .L_overflow
#endif
	RJMP	.L_expPower10
.L_nextPower:
	ADIW	ZL,4
	RJMP	.L_expPower10

99:
	POP	ZL
	POP	ZH
	CPI	ZL,0
	CPC	ZL,ZH
	BREQ	1f
	ST	Z+,rEndptrL
	ST	Z,rEndptrH
1:
	LDI	ZL,18-6 ; number of all 'pushed' registers - not pushed ones
	IN	YL,_SFR_IO_ADDR(SPL)
	IN	YH,_SFR_IO_ADDR(SPH)
	EPILOGUE_RESTORES(6)

.L_overflow:
	MOV	rA3,rS3		; correct
	ORI	rA3,0x7F
	LDI	rA2,0x7F
	SER	rA1
	SER	rA0
#ifdef __ERRNO__
	RJMP	1f
#else
	RJMP	99b
#endif
.L_underflow:
	RCALL	_U(__fp_zero)
#ifdef __ERRNO__
1:
	extern errno
	LDI	rB3,ERANGE
	STS	errno,rB3
	STS	errno+1,__zero_reg__
#endif
	RJMP	99b

.L_scanSign:
	CLR	rFlags
	CPI	rCh,'+'
	BREQ	1f
	CPI	rCh,'-'
	BRNE	2f
	ORI	rFlags,_BV(bitNegative)	; negative sign
1:
	LD	rCh,Y+
2:
	RET


.L_scanExponent:
	CLR	rA2	; initialize rA3::rA2 with 0
	CLR	rA3
1:
	CPI	rCh,'0'
	BRLT	10f
	BRNE	2f		; look for leading zeros
	SBRS	rFlags,bitDigit
	RJMP	4f		; no valid digits yet -> skip zero
2:
	CPI	rCh,'9'+1
	BRGE	10f		; no digit, no integer part
	ORI	rFlags,_BV(bitDigit)
	TST	rA3
	BRNE	3f		; overflow allready
				; mul rA3::rA2 by 10 and add rCh
	XCALL	__mulhi_const_10 ; r25:r24 *= 10
	ANDI	rCh,0x0F
	ADD	rA2,rCh
	adc	rA3,__zero_reg__
3:
	MOV	rEndptrH,YH
	MOV	rEndptrL,YL	; valid exponent up to now
4:
	LD	rCh,Y+
	RJMP	1b
10:
	RET


.L_scanDigits:
	SET
	RCALL	_U(__fp_zero)	; initialize result with 0.0
	CLR	rFracPower
	DEC	rFracPower
	CLR	rDPshift
1:     ; scan until (possibly) decimal point found
	CPI	rCh,'.'
	BRNE	2f
	SBRC	rFlags,bitPoint
	RJMP	10f		; just found the second point
	ORI	rFlags,_BV(bitPoint)
	RJMP	6f
2:
	CPI	rCh,'0'
	BRLT	10f
	BRNE	3f		; look for leading zeros
	CLT
	SBRS	rFlags,bitDigit
	RJMP	4f		; leading zero, but check rDPshift if left of dp
3:
	CPI	rCh,'9'+1
	BRGE	10f		; no digit, no integer part
	ORI	rFlags,_BV(bitDigit)

	CPI	rA3,0x0F	; 0xF FF FF FF = 268 435 455 -> min 8 digits precision
	BRGE	5f		; truncate ?

	INC	rFracPower
	; mul rA3::rA0 by 10 and add rCh
	CLT			; digit validates fraction
	CLR	rB3
	CLR	rB2
	CLR	rB1
	LDI	rB0,10
	XCALL	__mulsi3
	ANDI	rCh,0x0F
	ADD	rA0,rCh
	adc	rA1,__zero_reg__
	adc	rA2,__zero_reg__
	adc	rA3,__zero_reg__
	MOV	rEndptrH,YH
	MOV	rEndptrL,YL	; valid float up to now
4:
	SBRC	rFlags,bitPoint
	; scan left of decimal point : decrement exponent
	DEC	rDPshift
	RJMP	6f
5:
	; scan vor dem Komma, aber keine Digits mehr auswerten : inkrementiere
	SBRS	rFlags,bitPoint
	INC	rDPshift
6:
	LD	rCh,Y+
	RJMP	1b
10:
	RET

.L_strtod_prologue:
	clr	XL		; no locals
	clr	XH
	pop	ZH
	pop	ZL
	PROLOGUE_SAVES(6)

	.size strtod, .-strtod
	ENDFUNC

#endif /* not DOXYGEN */
