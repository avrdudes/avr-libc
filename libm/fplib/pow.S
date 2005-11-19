/*  -*- Mode: Asm -*-  */

/* Copyright (c) 2002  Michael Stumpf  <mistumpf@de.pepperl-fuchs.com>
   Copyright (c) 2005  Dmitry Xmelkov
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
    pow.S is part of     FPlib V 0.3.0       ported to avr-as
    for details see readme.fplib

 *---------------------------------------------------------------------
 *
 *	A = pow(x,y)

    double pow (double x, double y)
    {
	return
	      !isfinite(x) || !isfinite(y)  ?  NaN
	    : (x > 0)                  ?  exp(log(x)*y)
	    : (x == 0 && y > 0)        ?  0
	    : (x == 0 && y <= 0)       ?  NaN
	    : (is_int(y) && (y % 2))   ?  sign(x)*exp(log(fabs(x))*y)
	    : (is_int(y) && !(y % 2))  ?  exp(log(fabs(x))*y)
	    : NaN ;
    }

 Notes:
   * C99 says:
    "A domain error occurs if the result cannot be represented when x is
    zero and y is less than or equal to zero. A range error may occur."
    In this implementation pow(0,0)=NaN (shortest code).
   *  To do not enlarge program size, the case y==0 is not analized
    separatly.
   *  __fp_tstA, __fp_tstB will global in future.
 */

#include "gasava.inc"
#include "macros.inc"
#include "fplib.inc"

          TEXT_SEG(fplib, pow)
          FUNCTION(pow)
GLOBAL(pow)
  /* Check for NaN right here, before calling exp() as the latter
     is known to be buggy for NaN arguments. */
	rcall	__fp_tstB
	brcs	.L_nan		; isfinite(y)
	rcall	__fp_tstA
	brcs	.L_ret		; !isfinite(x)
	brts	.L_negx		; x < 0
	brne	.L_pow
  /* x == 0	*/
	rcall	__fp_tstB
	breq	.L_nan		; y == 0
	brtc	.L_ret		; y > 0  -->  return 0
.L_nan:
	rjmp	__fp_nan

.L_pow:
	push	rB3
	push	rB2
	push	rB1
	push	rB0
	rcall	log
	pop	rB0
	pop	rB1
	pop	rB2
	pop	rB3
	rcall	__mulsf3
	rjmp	exp

.L_negx:
	rcall	__fp_tstB
	brcs	.L_pow		; --> NaN, as x < 0
	breq	.L_absx
  /* Now we have:
     y is normal, nonzero value
     ZL == (rB2 << 1)
     ZH == exponenta,  ZH <= 254	*/
	sec		; hidden bit
	ror	ZL	; This is incorrect for subnormals, no sense:
			;   result would NaN.
  /* ffs().  Next two loops are finite due to above 'sec'.	*/
	X_movw	XL, rB0
  /* Byte search loop.	*/
1:	tst	XL
	brne	2f
	mov	XL, XH
	mov	XH, ZL
	subi	ZH, -8
	brcs	1b
	rjmp	.L_pow		; mantisa too big
  /* Bit search loop.	*/
2:	subi	ZH, -1
	brcc	.L_pow		; mantisa too big
	lsr	XL
	brcc	2b
  /* Check exponent, is y an integral value?
     Example:  1.0 == 0x3f800000:
	    __fp_tstB:	 ZH := 0x7f
	    byte search: ZH += 2*8       --> 0x8f
	    bit search:  ZH += 8         --> 0x97	*/
	cpi	ZH, 0x97
	brlo	.L_nan
	breq	3f		; y % 2 == 1
.L_absx:
	andi	rA3, 0x7f	; y is integral, y % 2 == 0
3:	push	rA3
	andi	rA3, 0x7f
	rcall	.L_pow
	pop	ZL
	andi	ZL, 0x80
	eor	rA3, ZL
.L_ret:
	ret

/* Test of 32-bits float value in rA0..rA3 registers.
   Return:
	C = 1	Z = 0	T = *	, if NaN
	C = 0	Z = 1	T = 0	, if 0.0 (or -0.0)
	C = 0	Z = 0	T = 1	, if < 0.0
	C = 0	Z = 0	T = 0	, if > 0.0
	ZL = (rA2 << 1)
	ZH = exponent (without subnormals correction)
   Value and other registers are not changed.
 */
__fp_tstA:
	clt
	X_movw	ZL, rA2
	lsl	ZL
	rol	ZH
	adiw	ZL, 0
	cpc	rA0, __zero_reg__
	cpc	rA1, __zero_reg__
	breq	1f		; C == 0, Z == 1
	inc	ZH
	sbci	ZH, 1		; C == 0/1, Z == 0
	bst	rA3, 7		; sign bit
1:	ret

/* Test of 32-bits float value in rB0..rB3 registers.
   Return:
	C = 1	Z = 0	T = *	, if NaN
	C = 0	Z = 1	T = 0	, if 0.0 (or -0.0)
	C = 0	Z = 0	T = 1	, if < 0.0
	C = 0	Z = 0	T = 0	, if > 0.0
	ZL = (rB2 << 1)
	ZH = exponent (without subnormals correction)
   Value and other registers are not changed.
 */
__fp_tstB:
	clt
	X_movw	ZL, rB2
	lsl	ZL
	rol	ZH
	adiw	ZL, 0
	cpc	rB0, __zero_reg__
	cpc	rB1, __zero_reg__
	breq	1f		; C == 0, Z == 1
	inc	ZH
	sbci	ZH, 1		; C == 0/1, Z == 0
	bst	rB3, 7		; sign bit
1:	ret

          ENDFUNC
