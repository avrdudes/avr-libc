/*  -*- Mode: Asm -*-  */

/* Copyright (c) 2002  Michael Stumpf  <Michael.Stumpf@t-online.de>

   This file is free software; you can redistribute it and/or modify it under
   the terms of the GNU General Public License as published by the Free
   Software Foundation; either version 2, or (at your option) any later
   version.

   In addition to the permissions in the GNU General Public License, the
   author gives you unlimited permission to link the compiled version of this
   file into combinations with other programs, and to distribute those
   combinations without any restriction coming from the use of this file.
   (The General Public License restrictions do apply in other respects; for
   example, they cover modification of the file, and distribution when not
   linked into a combine executable.)

   This file is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
   FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
   more details. */

/*
    strtod.S is an addition to     FPlib V 0.3.0       ported to avr-as
    for details see readme.strtod

  double[rP0:rP1:rP2:rP3] strtod(const char * s[rP0:rP1], char ** endptr[rP2:rP3] )

 *----------------------------------------------------------------------------------------------
 */

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

_10p1:    DCB  0x41,0x20,0x00,0x00
_10p2:    DCB  0x42,0xC8,0x00,0x00
_10p4:    DCB  0x46,0x1C,0x40,0x00
_10p8:    DCB  0x4C,0xBE,0xBC,0x20
_10p16:   DCB  0x5A,0x0E,0x1B,0xCA
_10p32:   DCB  0x74,0x9D,0xC5,0xAE

_10p_1:   DCB  0x3D,0xCC,0xCC,0xCD
_10p_2:   DCB  0x3C,0x23,0xD7,0x0A
_10p_4:   DCB  0x38,0xD1,0xB7,0x17
_10p_8:   DCB  0x32,0x2B,0xCC,0x77
_10p_16:  DCB  0x24,0xE6,0x95,0x95
_10p_32:  DCB  0x0A,0x4F,0xB1,0x1F

          TEXT_SEG(fplib, strtod)

          .func strtod_prologue

strtod_prologue:
  clr	XL			; no locals
  clr	XH
  pop	ZH
  pop	ZL   
	PROLOGUE_SAVES(6)

GLOBAL(atof)
  clr	rP2
  clr	rP3			; clear *endptr
GLOBAL(strtod)
  rcall	strtod_prologue

__strtod00:
   MOV     YL,rP1           ;
   MOV     YH,rP0           ; load pointer to Y in case displacement is needed
   PUSH    rP2
   PUSH    rP3              ; needed at end of function
   MOV     rEndptrH,YH
   MOV     rEndptrL,YL      ; assume no valid float at all

_skipWhitespace:
   LD      rCh,Y+
   CPI     rCh,' '
   BREQ    _skipWhitespace
   CPI     rCh,'\t'
   BREQ    _skipWhitespace
   CPI     rCh,'\v'
   BREQ    _skipWhitespace
   CPI     rCh,'\f'
   BREQ    _skipWhitespace
   CPI     rCh,'\n'
   BREQ    _skipWhitespace
   CPI     rCh,'\r'
   BREQ    _skipWhitespace

   ; now scan fraction
   RCALL   _scanSign
   RCALL   _scanDigits

   ; if T set now there must be a fraction failure : rA still 0!
   BRTS    __doneProlong

   RCALL   _U(__floatunssisf)
   BST     rFlags,bitNegative
   BLD     rA3,7                  ; set sign
   MOV     rS3,rA3
   MOV     rS2,rA2
   MOV     rS1,rA1
   MOV     rS0,rA0

   ; now scan for exponent
   CLR     rA2             ; preset exponent

   ORI     rCh,0x20        ; 'E' -> 'e'
   CPI     rCh,'e'
   BRNE    _scanExponentDone ; is there any ?

   LD      rCh,Y+          ;
   RCALL   _scanSign
   RCALL   _scanExponent

   BRTC    _scanExponentOK ; found something invalid exponent
__doneProlong:
   RJMP    __done
_scanExponentOK:
   TST     rA3
   BREQ    _noExponentOverflow
   SBRC    rFlags,bitNegative  ; set sign
   RJMP    _underflow
   RJMP    _overflow
_noExponentOverflow:
   SBRC    rFlags,bitNegative  ; set sign
   NEG     rA2
_scanExponentDone:

   ; now evaluate fp number
   ; we got a string         -123.456e+2
   ; what we have is         fraction(rS3::rS0) = 123456.0    with rFracPower = 5
   ;                         exponent(rA2)      = +2          with rDPshift = -3
   ;                         the result is fraction * 10**(exponent+rDPshift)
   ;                         overflow/underflow control must include rFracPower
   LDI     ZL,LOW(_10p1)
   LDI     ZH,HIGH(_10p1)    ; pointer to array with 10^n

   #define rExp rFlags

   MOV     rExp,rA2

   MOV     rA3,rS3
   MOV     rA2,rS2
   MOV     rA1,rS1
   MOV     rA0,rS0            ; move fraction to rA
   ANDI    rA3,0x7F           ; positive

   CP      rA3,rA2
   CPC     rA2,rA1
   CPC     rA1,rA0
   CPC     rA0,__zero_reg__
   BREQ    __done             ; test for zero

   ADD     rExp,rDPshift      ; exponent correction
   BRPL    _expPositive

_expNegative:
   NEG     rExp
   ADIW    ZL,(_10p_1-_10p1)

   MOV     rA3,rExp
   SUB     rA3,rFracPower
   CPI     rA3,39
   BRGE    _underflow
   RJMP    _combineExponent

_expPositive:
   MOV     rA3,rExp
   ADD     rA3,rFracPower
   CPI     rA3,39
   BRGE    _overflow
   ; RJMP    _combineExponent
_combineExponent:
   MOV    rA3,rS3    ; load right sign again
_expPower10:
   TST    rExp
   BREQ   __done
   ASR    rExp
   BRCC   _nextPower

   RCALL  fp_flashconst              ; load constnat to B

   PUSH   R30
   PUSH   R31
   RCALL  _U(__mulsf3)                ; AX *= BX, sign stays untouched
   POP    R31
   POP    R30
#ifdef __ERRNO__
   BST    rA2,7			; if ERRNO
   MOV    rB3,rA3		; check for overflow / underflow
   ADD    rB3,rB3
   BLD    rB3,0
   TST    rB3
   BREQ   _underflow
   CPI    rB3,0xFF
   BREQ   _overflow
#endif
   RJMP    _expPower10
_nextPower:
   ADIW    ZL,4
   RJMP    _expPower10

__done:
   POP     ZL
   POP     ZH
   CPI     ZL,0
   CPC     ZL,ZH
   BREQ    __done00
   ST      Z+,rEndptrH
   ST      Z,rEndptrL
__done00:
   LDI     ZL,18-6 ; number of all 'pushed' registers - not pushed ones
   IN      YL,_SFR_IO_ADDR(SPL)
   IN      YH,_SFR_IO_ADDR(SPH)
	EPILOGUE_RESTORES(6)

_overflow:
   MOV     rA3,rS3                    ; correct
   ORI     rA3,0x7F
   LDI     rA2,0x7F
   SER     rA1
   SER     rA0
#ifdef __ERRNO__
   RJMP    _errnoERANGE
#else
   RJMP    __done
#endif
_underflow:
   RCALL   _U(__fp_zero)
#ifdef __ERRNO__
_errnoERANGE:
   extern errno
   LDI     rB3,ERANGE
   STS     errno,rB3
   STS     errno+1,__zero_reg__
#endif
   RJMP    __done

_scanSign:
   CLR     rFlags
   CPI     rCh,'+'
   BREQ    _nextChar
   CPI     rCh,'-'
   BRNE    _keepChar
   ORI     rFlags,_BV(bitNegative)    ; negative sign
_nextChar:
   LD      rCh,Y+
_keepChar:
   RET


_scanExponent:
   SET
   RCALL   _U(__fp_zero)    /* initialize rA3::rA0 with 0 */
_scanExponent_10:           /* scan until (possibly) decimal point found  */
   CPI     rCh,'0'
   BRLT    _scanExponent_Done
   BRNE    _scanExponent_20         /* look for leading zeros */
   CLT
   SBRS    rFlags,bitDigit
   RJMP    _scanExponent_40         /* no valid digits yet -> skip zero */
_scanExponent_20:
   CPI     rCh,'9'+1
   BRGE    _scanExponent_Done       /* no digit, no integer part */
   ORI     rFlags,_BV(bitDigit)
   TST     rA3
   BRNE    _scanExponent_30         /* overflow allready */
			/* mul rA3::rA2 by 10 and add rCh */
   CLT				; digit validates fraction
   XCALL   __mulhi_const_10	; r25:r24 *= 10
   ANDI    rCh,0x0F
   ADD     rA2,rCh
   adc     rA3,__zero_reg__
_scanExponent_30:
   MOV     rEndptrH,YH
   MOV     rEndptrL,YL            /* valid float up to now */
_scanExponent_40:
   LD      rCh,Y+
   RJMP    _scanExponent_10
_scanExponent_Done:
   RET


_scanDigits:
   SET
   RCALL   _U(__fp_zero)    /* initialize result with 0.0 */
   CLR     rFracPower
   DEC     rFracPower
   CLR     rDPshift
_scanDigits_10:     ; scan until (possibly) decimal point found
   CPI     rCh,'.'
   BRNE    _scanDigits_20
   SBRC    rFlags,bitPoint
   RJMP    _scanDigits_Done       ; just found the second point
   ORI     rFlags,_BV(bitPoint)
   RJMP    _scanDigits_50
_scanDigits_20:
   CPI     rCh,'0'                ;
   BRLT    _scanDigits_Done       ;
   BRNE    _scanDigits_30         ; look for leading zeros
   CLT
   SBRS    rFlags,bitDigit
   RJMP    _scanDigits_35         ; leading zero, but check rDPshift if left of dp
_scanDigits_30:
   CPI     rCh,'9'+1              ;
   BRGE    _scanDigits_Done       ; no digit, no integer part
   ORI     rFlags,_BV(bitDigit)

   CPI     rA3,0x0F               ; 0xF FF FF FF = 268 435 455 -> min 8 digits precision
   BRGE    _scanDigits_40         ; truncate ?

   INC     rFracPower
   ; mul rA3::rA0 by 10 and add rCh
   CLT                            ; digit validates fraction
   CLR     rB3                    ;
   CLR     rB2                    ;
   CLR     rB1                    ;
   LDI     rB0,10                 ;
   XCALL   __mulsi3               ;
   ANDI    rCh,0x0F               ;
   ADD     rA0,rCh                ;
   adc     rA1,__zero_reg__       ;
   adc     rA2,__zero_reg__       ;
   adc     rA3,__zero_reg__       ;
   MOV     rEndptrH,YH
   MOV     rEndptrL,YL            ; valid float up to now
_scanDigits_35:
   SBRC    rFlags,bitPoint
   ; scan left of decimal point : decrement exponent
   DEC     rDPshift
   RJMP    _scanDigits_50
_scanDigits_40:
   ; scan vor dem Komma, aber keine Digits mehr auswerten : inkrementiere
   SBRS    rFlags,bitPoint
   INC     rDPshift
_scanDigits_50:
   LD      rCh,Y+
   RJMP    _scanDigits_10
_scanDigits_Done:
   RET

