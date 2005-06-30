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
    dtostre.S is an addition to     FPlib V 0.3.0       ported to avr-as
    for details see readme.dtostre

  const char * dtostre( double f[r22::r25], char * s[r20:r21], byte prec[r18],
	byte flags[r16] )

 *------------------------------------------------------------------------------*/

#if !defined(DOXYGEN)

#include "gasava.inc"
#include "macros.inc"
#include "fplib.inc"

#include <stdlib.h>

/* Verify assumptions implied in the code below. */
#if DTOSTR_ALWAYS_SIGN != 0x01
#error "DTOSTR_ALWAYS_SIGN must be 0x01"
#endif
#if DTOSTR_PLUS_SIGN != 0x02
#error "DTOSTR_PLUS_SIGN must be 0x02"
#endif
#if DTOSTR_UPPERCASE != 0x04
#error "DTOSTR_UPPERCASE must be 0x04"
#endif

#define FP_0_1     0x3dcccccd
#define	FP_0_30103 0x3e9a209b
#define FP_0_5     0x3f000000
#define FP_10      0x41200000

          TEXT_SEG(fplib, dtostre)
          FUNCTION(dtostre)

GLOBAL(dtostre)
/* new call convention, move last two args of type "char" */
	mov	rP6, r18	/* rP6 == r19 */
	mov	rP7, r16	/* rP7 == r18 */

	push	r11
	push	r12
	push	r13
	push	r14
	push	r15
	push	r16
	push	r17
	push	YH
	push	YL
	push	rP4		; return this
	push	rP5
	mov	YH, rP4
	mov	YL, rP5

	mov	rSI0, rA3	; copy sign
	mov	rSI1, rA2	; and ..
	add	rSI1, rSI1
	adc	rSI0, rSI0
	brne	3f		; not zero

	ldi	rSI1, ' '
	sbrc	rP7, 1
	ldi	rSI1, '+'	; rSI1 = (flags & DTOSTRE_PLUS_SIGN?'+':' ')
	sbrc	rP7, 0		; if (!(flags & DTOSTRE_ALWAYS_SIGN)) skip
	st	Y+, rSI1
	ldi	rA3, '0'
	ldi	rA2, '.'
	ldi	rA1, 'E'
	sbrs	rP7, 2		; if DTOSTRE_UPPERCASE was set
	ori	rA1, 'E' ^ 'e'
	ldi	rA0, '+'
	st	Y+,rA3
	tst	rP6		; if (prec == 0) don't print ".0"
	breq	2f
	dec	rP6
	st	Y+,rA2
1:	st	Y+, rA3
	dec	rP6
	brpl	1b
2:	st	Y+, rA1		/* 'E' */
	st	Y+, rA0		/* '+' */
	st	Y+, rA3		/* '0' */
	st	Y+, rA3		/* '0' */
	rjmp	99f		; exit

3:
	cpi	rSI0, 0xff
	brne	4f		; check for zero and NaN

	ldi	rA3, 'N'
	ldi	rA2, 'a'
	st	Y+, rA3		/* 'N' */
	st	Y+, rA2		/* 'a' */
	st	Y+, rA3		/* 'N' */
	rjmp	99f		; exit

4:				; not NaN
	tst	rA3
	brpl	5f
	ldi	rSI1, '-'
	andi	rA3, 0x7F	; now f is positive
	rjmp	6f
5:	ldi	rSI1, ' '
	sbrc	rP7, 1
	ldi	rSI1, '+'	; rSI1 = (flags & DTOSTRE_PLUS_SIGN?'+':' ')
	sbrc	rP7, 0		; if (!(flags & DTOSTRE_ALWAYS_SIGN)) skip
6:
	st	Y+, rSI1

	mov	rSI0, rP6	; store prec
	push	rP7		; and flags

	mov	rS0, rA0	; store dblno
	mov	rS1, rA1
	mov	rS2, rA2
	mov	rS3, rA3

; frexp(dblno, (int*) dest);
	mov	rB2, YL
	mov	rB3, YH
	XCALL	_U(frexp)	; destroys argument_1

; iexp = *(int*) dest * log10(2);
	ldd	rA0, Y+0
	ldd	rA1, Y+1	; exponent
	eor	rA2, rA2	; to longint argument
	sbrc	rA1, 7
	com	rA2
	mov	rA3, rA2
	XCALL	_U(__floatsisf)	; to float
	FPLOAD(rB, FP_0_30103)
	XCALL	_U(__mulsf3)	; multiply
	XCALL	_U(__fixsfsi)	; to integer
	mov	rS4, rA0	; save exponent, 1 byte only

; if ( iexp  != 0 )
	tst	rA0
	breq	1f

; dblno *= pow(10.0, -(double) iexp)
	XCALL	_U(__floatsisf)	; to float
	XCALL	_U(__negsf2)	; negative
	FPMOV(rB, rA)
	FPLOAD(rA, FP_10)
	XCALL	_U(pow)
	FPMOV(rB, rS)		; argument_2 = dblno
	XCALL	_U(__mulsf3)
	FPMOV(rS, rA)		; new dblno
1:
; determine rounding:
; if (prec < ACCURACY) { t = .5; t *= 0.1**prec; dblno += t; }
	cpi	rSI0, ACCURACY
	brcc	1f
	FPLOAD(rA, FP_0_5)
	eor	rSI1, rSI1	; for (rSI1 = 0; rSI1 < prec; rSI1++)
	rjmp	3f
2:	FPLOAD(rB, FP_0_1)
	XCALL	_U(__mulsf3)	; t *= 0.1
	inc	rSI1
3:	cp	rSI1, rSI0
	brlo	2b
	FPMOV(rB, rS)
	XCALL	_U(__addsf3)	; dblno += t
	FPMOV(rS, rA)		; new dblno
1:
; The algorithm to determine the decimal exponent above has the
; potential to erroneously return an exponent that might be too
; large.  So we need to give it a try before applying the rounding
; below.  If we find the first digit to become 0, we decrease the
; exponent, and multiply our number again by 10.

	FPMOV(rA, rS)
	mov	rB2, YL
	mov	rB3, YH
	XCALL	_U(modf)
	ldd	rSI1, Y+3	; no need to convert from float to int,
	tst	rSI1		; float 0.0 always has 0 in the MSB
	brne	1f

	dec	rS4		; exp--
	FPLOAD(rB, FP_10)
	XCALL	_U(__mulsf3)
	FPMOV(rS, rA)		; dblno
	rjmp	1b

1:
				; for (rSI1 = 0; rSI1 <= prec; rSI1++)
	eor	rSI1, rSI1
	rjmp	8f
2:
	cpi	rSI1, ACCURACY
	brcc	5f		; more digits than accuracy => pad 0s

; dblno = modf(dblno, (double *) dest) * 10.0;
	FPMOV(rA, rS)		; next digit
	mov	rB2, YL
	mov	rB3, YH
	XCALL	_U(modf)
	FPLOAD(rB, FP_10)
	XCALL	_U(__mulsf3)
	FPMOV(rS, rA)		; dblno

; *dest++ = '0' + (char)(*(double *) dest);
	ldd	rA0, Y+0
	ldd	rA1, Y+1
	ldd	rA2, Y+2
	ldd     rA3, Y+3
	XCALL   _U(__fixsfsi)	; to long int
	mov	rA2, rA0
	subi	rA2, -'0'
	st	Y+, rA2

; if (i == 0)
	tst	rSI1
	brne	7f
	tst	rSI0		; if (prec == 0) don't print "."
	breq	7f
	ldi	rA2, '.'
	rjmp	6f
5:				; pad with zeros
	ldi	rA2, '0'
6:	st	Y+, rA2
7:	inc	rSI1		; rSI1++
8:				; loop test rSI1 <= rSI0
	cp	rSI0, rSI1	; compare count - prec
	brcc	2b

	pop	rA2		; and flags
	ldi	rA1, 'E'
	sbrs	rA2, 2		; if DTOSTRE_UPPERCASE was set
	ori	rA1, 'E' ^ 'e'
	ST	Y+, rA1		; put exponent
	ldi	rA1, '+'	;
	tst	rS4		; exponent
	brpl	1f
	neg	rS4
	ldi	rA1, '-'
1:
	st	Y+, rA1

	; dividend in r24, divisor in r22
	mov	r24, rS4
	ldi	r22, 10		; divisor
	XCALL	_U(__udivmodqi4)
	; quotient in r24, remainder in r25

	subi	rByte, -'0'
	st	Y+, rByte
	subi	r25, -'0'
	st	Y+, r25
99:
	st	Y,__zero_reg__

	pop	rByte		; char *dest
	pop	r25
	pop	YL		; frame pointer
	pop	YH
	pop	r17
	pop	r16
	pop	r15
	pop	r14
	pop	r13
	pop	r12
	pop	r11
	ret

          ENDFUNC

#endif /* not DOXYGEN */
