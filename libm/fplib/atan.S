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
 *  atan.S
 *-----------------------------------------------------------------------------

	Contributors:
	Created by Reiner Patommel, 07 Dec 2002

 -*- Mode: Asm -*-

 *
 * Accuracy:  better than +/-1.5*10^-7 over full range
 *
 * ----------------------------------------------------------------------------
 *	A = atan(A)
 * ----------------------------------------------------------------------------
 *
 * Since the approximation used is defined only for -1 < x < 1
 *	the formula atan(x) = PI/2 - atan(1/x) is used for values > 1
 *	the formula atan(x) = -atan(1/x) - PI/2 is used for values < -1
 */

/* $Id$ */

#include "gasava.inc"
#include "fplib.inc"
#define sign	r17
#define magn	r16
#define FP_PI_2	0x3FC90FDB		/* PI/2		*/

	TEXT_SEG(fplib, atan)
	FUNCTION(atan)

GLOBAL(atan)
	PUSH	sign
	PUSH	magn
	CLR	magn			; clear magnitude flag
	MOV	sign, rA3		; keep sign of x
	ANDI	sign, 0x80		; clear sign and set sign.b7 if x < 0
	ANDI	rA3, 0x7F		; make |x|
	LDI	rB3, 0x3F
	LDI	rB2, 0x80
	CPI	rA0, 0x01
	CPC	rA1, __zero_reg__
	CPC	rA2, rB2
	CPC	rA3, rB3		; A - 1.0000001192092896
	BRCS	1f			; |x| <= 1.0 --> calculate atan(x)
	ORI	magn, 0x80		; set magn.b7 as |x| > 1
	XCALL	_U(inverse)		; A = 1.0 / x
1:
	OR	rA3, sign		; restore sign of x
	FPPUSH	(rA)			; save x
	XCALL	_U(square)		; A = x^2
	LDI	ZL,LOW(.Ltable_atan)
	LDI	ZH,HIGH(.Ltable_atan)	; point to table
	RCALL	_U(fp_powerseries)
	FPPOP	(rB)			; get x again
	XCALL	_U(__mulsf3)		; now A = atan(x) for -1 <= x <= 1
	TST	magn			; |x| > 1 ?
	BREQ	2f
	FPLOAD	(rB, FP_PI_2	)	; B = PI/2
	LDI	magn, 0x80
	EOR	rA3, magn		; A = -A
	SBRC	sign, 7			; x > +1 ?
	ORI	rB3, 0x80		; B = -B
	XCALL	_U(__addsf3)
2:					; clean-up
	POP	magn
	POP	sign
	RET

	ENDFUNC
/*

 * atan(x) = x (1 + x^2(a2 + x^2(a4 + x^2(a6 + x^2(a8 + x^2(a10 +
 *		    x^2(a12 + x^2(a14 + x^2(a16)))))))))
 *
 * a2  = -3.3333147e-1			;[BEAAAA6C]
 * a4  =  1.9993551e-1			;[3E4CBBE5]
 * a6  = -1.4208899e-1			;[BE117FC7]
 * a8  =  1.0656264e-1			;[3DDA3D83]
 * a10 = -7.5289637e-2			;[BD9A3174]
 * a12 =  4.2909615e-2			;[3D2FC1FE]
 * a14 = -1.6165737e-2			;[BC846E02]
 * a16 =  2.8662258e-3			;[3B3BD74A]
 *
 * these constants are *no* IEEE float values:  exponent unpacked already
 *		1st byte	: exponent
 *		2nd byte	: msb of mantissa with sign as bit 7
 *		3rd & 4th byte	: mantissa
 */
.Ltable_atan:
	DCB 8 ; no of table entries - 1 (preload value)
	DCB 0x76, 0x3B, 0xD7, 0x4A	; a16
	DCB 0x79, 0x84, 0x6E, 0x02	; a14
	DCB 0x7A, 0x2F, 0xC1, 0xFE	; a12
	DCB 0x7B, 0x9A, 0x31, 0x74	; a10
	DCB 0x7B, 0x5A, 0x3D, 0x83	; a8
	DCB 0x7C, 0x91, 0x7F, 0xC7	; a6
	DCB 0x7C, 0x4C, 0xBB, 0xE5	; a4
	DCB 0x7D, 0xAA, 0xAA, 0x6C	; a2
	DCB 0x7F, 0x00, 0x00, 0x00	; 1.0
	DCB 0x00

