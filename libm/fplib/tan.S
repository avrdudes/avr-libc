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
       RCALL   _U(__fp_powerseries)
       POP     rB0
       POP     rB1
       POP     rB2
       POP     rB3
       RCALL   _U(__mulsf3)
       SBRS    rSI0,0
       RJMP    _tan_100
       RCALL   _U(__fp_inverse)
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
