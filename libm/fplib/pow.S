/* Copyright (c) 2002  Michael Stumpf  <mistumpf@de.pepperl-fuchs.com>
   Copyright (c) 2006  Dmitry Xmelkov
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
   POSSIBILITY OF SUCH DAMAGE. */

/* $Id$ */

#if !defined(__AVR_TINY__)

#include "fp32def.h"
#include "asmdef.h"

/* float pow (float x, float y);
     The pow() function returns the value of x raised to the power of y.

   Args combinations:
	x	y		pow(x,y)
	--------------------------------
	+0	NaN		NaN	exp(log(x)*y)
	+0	+0,-0		+1
	+0	+Inf		+0	exp(log(x)*y)
	+0	-Inf		+Inf	exp(log(x)*y)
	+0	y > 0		+0	exp(log(x)*y)
	+0	y < 0		+Inf	exp(log(x)*y)
	
	-0	NaN		NaN	exp(log(x)*y)
	-0	+0,-0		+1
	-0	1,3,5...	-0	-exp(log(x)*y)
	-0	y > 0		+0	exp(log(x)*y)
	-0	-1,-3,-5...	-Inf	-exp(log(x)*y)
	-0	y < 0		+Inf	exp(log(x)*y)
	
	+1	NaN		+1
	+1	+Inf,-Inf	+1
	+1	else		+1	exp(log(x)*y)
	
	-1	+0,-0		+1
	-1	1,3,5...	-1
	-1	-1,-3,-5...	-1
	-1	2,4,6...	+1
	-1	-2,-4,-6...	+1
	-1	else		NaN	exp(log(x)*y)
	
	+Inf	NaN		NaN	exp(log(x)*y)
	+Inf	+0,-0		+1
	+Inf	y > 0		+Inf	exp(log(x)*y)
	+Inf	y < 0		+0	exp(log(x)*y)
	
	-Inf	NaN		NaN	exp(log(x)*y)
	-Inf	+0,-0		+1
	-Inf	1,3,5...	-Inf
	-Inf	y > 0		+Inf
	-Inf	-1,-3,-5...	-0
	-Inf	y < 0		+0
	
	NaN	+0,-0		+1
	NaN	else		NaN	exp(log(x)*y)
	
	(0,1)	NaN		NaN	exp(log(x)*y)
	(0,1)	+0,-0		+1	exp(log(x)*y)
	(0,1)	+Inf		+0	exp(log(x)*y)
	(0,1)	-Inf		+Inf	exp(log(x)*y)
	
	(-1,0)	NaN		NaN
	(-1,0)	+0,-0		+1
	(-1,0)	+Inf		+0
	(-1,0)	-Inf		+Inf
	(-1,0)	nonintegral	NaN
	
	x > 1	NaN		NaN
	x > 1	+0,-0		+1
	x > 1   +Inf		+Inf
	x > 1	-Inf		+0
	
	x < -1	NaN		NaN
	x < -1	+0,-0		+1
	x < -1	+Inf		+Inf
	x < -1	-Inf		+0
	x < -1	nonintegral	NaN
 */

#define	FL_1	0x3f800000	/* +1.0	*/

ENTRY pow
  ; ZH := exponent of y
	X_movw	ZL, rB2
	lsl	ZL
	rol	ZH
  ; y == 0 ?
	adiw	ZL, 0
	cpc	rB0, r1
	cpc	rB1, r1
	breq	.L_one
  ; preliminary check
	cp	rA0, r1
	cpc	rA1, r1
	brne	0f		; skip a bit of comparisons
  ; x == 1.0 ?
	cpi	rA2, hlo8(FL_1)
	ldi	rAE, hhi8(FL_1)
	cpc	rA3, rAE
	breq	.L_ret
  ; x == -0.0 ?
	set			; flag: nonintegral y is a legal value
	cpi	rA3, 0x80
	cpc	rA2, r1
	breq	.L_int
  ; x == -Inf ?
	cpi	rA2, 0x80
	ldi	rAE, 0xff
	cpc	rA3, rAE
	breq	.L_int
  ; x >= 0 ?
0:	tst	rA3
	brpl	.L_pow
  ; isinf(y) ?
	cpi	ZH, 0xff
	cpc	ZL, r1
	cpc	rB1, r1
	cpc	rB0, r1
	breq	.L_big
  ; isintegral(y) ?
	clt			; nonintegral y is not a legal value
.L_int:
	/* Now we have:
	     y is nonzero value
	     ZL == (rB2 << 1)
	     ZH == exponenta,  ZH <= 254	*/
	sec		; hidden bit
	ror	ZL	; This is incorrect for subnormals, no sense:
			;   result would NaN.
  ; ffs().  Next two loops are finite due to above 'sec'.
	X_movw	XL, rB0
  ; Byte search loop.
1:	tst	XL
	brne	2f
	mov	XL, XH
	mov	XH, ZL
	subi	ZH, -8
	brcs	1b
	rjmp	.L_noint	; mantisa too big
  ; Bit search loop.
2:	subi	ZH, -1
	brcc	.L_noint	; mantisa too big
	lsr	XL
	brcc	2b
  ; Check exponent, is y an integral value?
	/* Example:  1.0 == 0x3f800000:
	    exponent:	 ZH := 0x7f
	    byte search: ZH += 2*8       --> 0x8f
	    bit search:  ZH += 8         --> 0x97	*/
	cpi	ZH, 0x97
	brlo	.L_noint
	breq	3f		; y % 2 == 1
	cpi	ZH, 0x97 + 24
	brsh	.L_noint
	andi	rA3, 0x7f	; y is integral, y % 2 == 0
3:	push	rA3
	rcall	.L_pow
	pop	r0
	sbrc	r0, 7
	subi	rA3, 0x80
.L_ret:
	ret
  ; y is not an integral number
.L_noint:
	brts	.L_pow
.L_nan:
	XJMP	_U(__fp_nan)
.L_one:
	ldi	rA0,  lo8(FL_1)
	ldi	rA1,  hi8(FL_1)
	ldi	rA2, hlo8(FL_1)
	ldi	rA3, hhi8(FL_1)
	ret
  ; replace Inf --> big finite (to exclude '0 * Inf' for legal x == -1)
.L_big:
	ldi	rB2, 0x7f
.L_pow:
	andi	rA3, 0x7f
	push	rB3
	push	rB2
	push	rB1
	push	rB0
	XCALL	_U(log)
	pop	rB0
	pop	rB1
	pop	rB2
	pop	rB3
	XCALL	_U(__mulsf3)
	XJMP	_U(exp)
ENDFUNC

#endif /* !defined(__AVR_TINY__) */
