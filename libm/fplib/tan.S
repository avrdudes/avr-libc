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
    tan.S is part of     FPlib V 0.3.0       ported to avr-as
    for details see readme.fplib

 *----------------------------------------------------------------------------------------
 * A = tan(A)
 *
 * tan( x ) = tan( fmod(x,PI) )
 * tan(-x ) = - tan(x)
 *
 * since the power series of tangens converts quite slow for bigger values
 * the formula tan(x) = 1/tan(PI/2 - x) is used for values > PI/4
 */

#if !defined(DOXYGEN)

#include "gasava.inc"
#include "fplib.inc"

          TEXT_SEG(fplib, tan)
          FUNCTION(tan)

GLOBAL(tan)
       PUSH    rSI0

       MOV     rSI0,rA3		; keep sign tan(x) = -tan(-x)
       ANDI    rSI0,0x80	; assume inversion flag zero
       ANDI    rA3,0x7F
       CPI     rA3,0x39
       BRCS    _tan_100		; (tan(A < 0x39000000)=A)

       LDI     rB3,0x40
       LDI     rB2,0x49
       LDI     rB1,0x0F
       LDI     rB0,0xDB		; load PI
       RCALL   _U(fmod)		; X = x [0..PI[

       LDI     rB3,0x3F
       LDI     rB2,0xC9
       LDI     rB1,0x0F
       LDI     rB0,0xDB		; load PI/2
       CP      rB0,rA0
       CPC     rB1,rA1
       CPC     rB2,rA2
       CPC     rB3,rA3		; B(=PI/2) - A
       BREQ    _tan_INF
       BRCC    _tan_10
       LDI     rB3,0x40
       LDI     rB2,0x49		; load PI
       ORI     rA3,0x80		; A = -A
       RCALL   _U(__addsf3)	; A = A+B = B + (-A)
       LDI     rB3,0x80
       EOR     rSI0,rB3
 _tan_10:
       LDI     rB3,0x3F
       LDI     rB2,0x49
       LDI     rB1,0x0F
       LDI     rB0,0xDB		; load PI/4
       CP      rB0,rA0
       CPC     rB1,rA1
       CPC     rB2,rA2
       CPC     rB3,rA3		; B(=PI/4) - A
       BRCC    _tan_00
       INC     rSI0
       ORI     rA3,0x80		; negate A
       LDI     rB2,0xC9		; P/4 -> PI/2
       RCALL   _U(__addsf3)	; PI/2 - A
 _tan_00:
       PUSH    rA3
       PUSH    rA2
       PUSH    rA1
       PUSH    rA0
       RCALL   _U(square)		; xý
       ORI     rA3,0x80 		; -xý
       LDI     ZL,LOW(table_tan)
       LDI     ZH,HIGH(table_tan)
       RCALL   _U(fp_powerseries)
       POP     rB0
       POP     rB1
       POP     rB2
       POP     rB3
       RCALL   _U(__mulsf3)
       SBRS    rSI0,0
       RJMP    _tan_100
       RCALL   _U(inverse)
 _tan_100:
       SBRC    rSI0,7
       ORI     rA3,0x80
       POP     rSI0
       RET
 _tan_INF:
       POP     rSI0
       RJMP    _U(__fp_nan)

          ENDFUNC

/*
 *
 * see cephes22: tan.c
 * and FPlib doc
 *                 1 - xý(f1 - xý(f2 - xýf3))
 * tan(x) =    x * --------------------------
 *                 1 - xý(h1 - xý(h2 - xýh3))
 *
 * f3  : 1.09079E-5
 * f2  : 0.00310705
 * f1  : 0.130906
 * 1.0 :
 *
 * h3  : 0.000253971
 * h2  : 0.0245202
 * h1  : 0.464239
 */

	PGM_SECTION

	/* these constants are *no* IEEE float values:	exponent unpacked allready
	 *						first byte : exponent
	 *						2nd byte   : msb of mantissa with sign as bit 7
	 *						3rd & 4th byte : mantissa
	 */
 table_tan:  DCB 3 ; no of table entries - 1 (preload value)
             DCB 0x73, 0x05, 0x27, 0x60     ; h - first calculate denominator
             DCB 0x79, 0x48, 0xDE, 0x92
             DCB 0x7D, 0x6D, 0xB0, 0xCA
             DCB 0x7F, 0x00, 0x00, 0x00
             DCB 3 ; no of table entries - 1 (preload value)
             DCB 0x6E, 0x37, 0x00, 0xF3     ; f
             DCB 0x76, 0x4B, 0x9F, 0xB8
             DCB 0x7C, 0x06, 0x0C, 0x3E
             DCB 0x7F, 0x00, 0x00, 0x00

#endif /* not DOXYGEN */
