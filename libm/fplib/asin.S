/* Copyright (c) 2002, Reiner Patommel
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

 * ----------------------------------------------------------------------------
 *  asin.S
 *-----------------------------------------------------------------------------

   Contributors:
     Created by Reiner Patommel, 01 Dec 2002

 -*- Mode: Asm -*-

 * Accuracy:  0.00000  <= |x| <= 0.99999:  better than +/-3*10^-7
 *            0.99999  <= |x| <  1.00000:  better than +/-5*10^-5

 * ----------------------------------------------------------------------------
 *  A = asin(A)
 *--------------------------------------------------------------------------*/

/* $Id$ */

#if !defined(DOXYGEN)

#include "gasava.inc"
#include "fplib.inc"

#define sign	r26

	TEXT_SEG(fplib, asin)
	FUNCTION(asin)

GLOBAL(asin)
	CLR	sign
	SBRC	rA3, 7
	ORI	sign, 1
	PUSH	sign		; remember sign of x (bit 0 set: x < 0)
	ANDI	rA3, 0x7F	; x = |x|
	LDI	rB3, 0x3F
	LDI	rB2, 0x80
	CPI	rA0, 0x01
	CPC	rA1, __zero_reg__
	CPC	rA2, rB2
	CPC	rA3, rB3	; A - 1.0000001192092896
	BRCS	_asin_calc	; A <= 1.0
	XCALL	(__fp_nanEDOM)	; A > 1.0 -> argument range error
	POP	sign		; clean-up
	RET			; return with NAN
 _asin_calc:			; here x <= 1.0
	PUSH	rA3
	PUSH	rA2
	PUSH	rA1
	PUSH	rA0		; save x
	LDI	ZL,LOW(table_asin)
	LDI	ZH,HIGH(table_asin)	; point to table
	XCALL	_U(__fp_powerseries)	; A = P0 + x(P1 + x(P2 + x(P3 + x(P4 +
					;  x(P5 + x(P6 + x(P7)))))))
	POP	rB0
	POP	rB1
	POP	rB2
	POP	rB3		; get x again
	PUSH	rA3
	PUSH	rA2
	PUSH	rA1
	PUSH	rA0		; save A
	LDI	rA3, 0x3F
	LDI	rA2, 0x80
	CLR	rA1
	CLR	rA0		; A = 1.0
	ORI	rB3, 0x80	; B = -x
	XCALL	_U(__addsf3)	; A = 1 + (-x)
	XCALL	_U(sqrt)	; A = sqrt(1-x)
	POP	rB0
	POP	rB1
	POP	rB2
	POP	rB3		; get A again
	XCALL	_U(__mulsf3)	; A = (1 - x)^2 (P0 + x(P1 + x(P2 + x(P3 +
				;  x(P4 + x(P5 + x(P6 + x(P7))))))))
	LDI	rB3, 0x3F
	LDI	rB2, 0xC9
	LDI	rB1, 0x0F
	LDI	rB0, 0xDB	; B = PI/2
	ORI	rA3, 0x80	; A = -A
	XCALL	_U(__addsf3)	; A = pi/2 - (1 - x)^2 (P0 + x(P1 + x(P2 +
				; x(P3 + x(P4 + x(P5 + x(P6 + x(P7))))))))
	POP	sign		; get sign of x again
	SBRC	sign, 0
	ORI	rA3, 0x80	; asin(x) = -asin(-x)
	RET
	ENDFUNC
/*----------------------------------------------------------------------------

 asin(x) = pi/2 - (1 - x)^2 (P0 + x(P1 + x(P2 + x(P3 + x(P4 + x(P5 +
                                                       x(P6 + x(P7))))))))
 *
 * P0 :  1.57079 63050    [3FC90FDA]
 * P1 : -0,21459 88016    [BE5BBFCA]
 * P2 :  0.08897 89874    [3DB63A9E]
 * P3 : -0.05017 43046    [BD4D8392]
 * P4 :  0.03089 18810    [3CFD10F8]
 * P5 : -0.01708 81256    [BC8BFC66]
 * P6 :  0.00667 00901    [3BDA90C5]
 * P7 : -0.00126 24911    [BAA57A2C]
 */

	PGM_SECTION

 table_asin: DCB 7
	DCB 0x75, 0xA5, 0x7A, 0x2C  ; P7
	DCB 0x77, 0x5A, 0x90, 0xC5  ; P6
	DCB 0x79, 0x8B, 0xFC, 0x66  ; P5
	DCB 0x79, 0x7D, 0x10, 0xF8  ; P4
	DCB 0x7A, 0xCD, 0x83, 0x92  ; P3
	DCB 0x7B, 0x36, 0x3A, 0x9E  ; P2
	DCB 0x7C, 0xDB, 0xBF, 0xCA  ; P1
	DCB 0x7F, 0x49, 0x0F, 0xDA  ; P0
	DCB 0x00                    ; 0.0

 /*--------------------------------------------------------------------------*/

#endif /* not DOXYGEN */
