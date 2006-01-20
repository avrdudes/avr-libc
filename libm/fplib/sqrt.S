/*  -*- Mode: Asm -*-  */

/* Copyright (c) 2002  Michael Stumpf  <mistumpf@de.pepperl-fuchs.com>
   Copyright (c) 2006  Anatoly Sokolov <aesok@post.ru>
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
    sqrt.S is part of     FPlib V 0.3.0       ported to avr-as
    for details see readme.fplib

 *----------------------------------------------------------------------------------------
 *
 *	A = sqrt(A)
 */

#include "gasava.inc"
#include "macros.inc"
#include "fplib.inc"

; Abak
#define rAbak3	rS0
#define rAbak2	rS1
#define rAbak1	rS2
#define rAbak0	rS3

; Bbak
#define rBbak3	rS4
#define rBbak2	rS5
#define rBbak1	rS6
#define rBbak0	rS7


	TEXT_SEG(fplib, sqrt)
	FUNCTION(sqrt)

GLOBAL(sqrt)

	SBRC	rA3, 7
	RJMP	_U(__fp_nanEDOM)	; sign bit is set -> argument range error

   /* A = sign(=0):(exp+7F):[1].mant = 2^(exp)*1.mant
    *   =          (LSB(exp)+7F) + (exp>>1) + (exp>>1):[1].mant = (2^(exp>>1))^2 * 2^(LSB(exp))*1.mant
    *                                                           = 2^(exp>>1)^2 * A'
    * A' = [2^0*1.0... 2^1*1.1111111] = [1.0...4.0[
    *
    * sqrt(A) = 2^(exp>>1) * sqrt( A' )
    * sqrt(A') = [1.0...2.0[  -> result of srqt(A') has definetely exponent 7F! -> exp(X0) = 7F
    *
    * the matissa of X0 is taken as ( 0.mant >> 1 )     0.0mant
    *  plus if LSB(exp)==1 [LSB(exp-7F)==0]             0.100000
    *  plus the implicit one                            1.000000
    */

	TST	rA3
	BRNE	2f		; sqrt(0) = 0
	RET
2:
	MOV	rB2, rA2	; needed later on

	RCALL	_U(__fp_split_a)	; does not return on NaN

	MOV	rTI0, rA3
	SUBI	rTI0, 0x7F
	ASR	rTI0		; this is dExp!
	SUB	rA3, rTI0
	SUB	rA3, rTI0

	PUSH	rTI0		; exponent offset

	RCALL	_U(__fp_merge)

	PUSH	rS0
	PUSH	rS1
	PUSH	rS2
	PUSH	rS3
	PUSH	rS4
	PUSH	rS5
	PUSH	rS6
	PUSH	rS7

	X_movw	rAbak0, rA0
	X_movw	rAbak2, rA2	; Abak = A

	SUBI    rB2, 0x80	; == EOR 0x80
	ROR	rB2
	CLR	rB1		; a slightly smaller X(0) than the calculated is better
	CLR	rB0		; and saves 2 right shifts
	ORI	rB2, 0x80	; 
	LDI	rB3, 0x3F	; load exponent 7F

1:
	X_movw	rA0, rAbak0
	X_movw	rA2, rAbak2 	; A = Abak

	X_movw	rBbak0, rB0
	X_movw	rBbak2, rB2 	; Bbak = B

	XCALL	__divsf3	; FP1X = arg/xn

    	X_movw	rB0, rBbak0
	X_movw	rB2, rBbak2 	; B = Bbak

	XCALL	__addsf3	; FP1X = arg/xn + xn

	LDI	rPL, lo8(-1)
	LDI	rPH, hi8(-1)
	RCALL	_U(ldexp)	; div by 2 := Xn+1

	X_movw	rB0, rA0
	X_movw	rB2, rA2	; B = A

	CP	rBbak0, rB0
	CPC	rBbak1, rB1
	CPC	rBbak2, rB2
	CPC	rBbak3, rB3	; cmp B to Bbak
	BRNE	1b

	POP	rS7
	POP	rS6
	POP	rS5
	POP	rS4
	POP	rS3
	POP	rS2
	POP	rS1
	POP	rS0

	POP	rB3
	
	RCALL	_U(__fp_split_a)	; does not return on NaN

	ADD	rA3, rB3

	RJMP	_U(__fp_merge)

	ENDFUNC


