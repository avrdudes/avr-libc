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

/* <non_standart> __divsf3x (float A, float B);
   Output:
     T
     rA3
     rA2.rA1.rA0.rAE.ZH
 */

#if !defined(__AVR_TINY__)

#include "fp32def.h"
#include "asmdef.h"

FUNCTION __divsf3x

0:	XCALL	_U(__fp_pscB)
	brcs	.L_nan
	XCALL	_U(__fp_pscA)
	brcs	.L_nan
	brne	.L_zr		; finite / Inf --> 0
.L_infA:
	cpi	rB3, 255
	breq	.L_nan		; Inf / Inf --> NaN
.L_inf:
	XJMP	_U(__fp_inf)
1:
	cpse	rB3, r1		; 0/finite --> 0,  0/0 --> NaN
.L_zr:	XJMP	_U(__fp_szero)
.L_nan:	XJMP	_U(__fp_nan)

ENTRY	__divsf3x
	XCALL	_U(__fp_split3)
	brcs	0b

ENTRY	__divsf3_pse		; post split entry
	tst	rA3
	breq	1b
	tst	rB3
	breq	.L_inf		; finite / 0.0 --> Inf
	
	sub	rA3, rB3
	sbc	rB3, rB3
	
/* Prepare to division:
     A:  rAE.rA2.rA1.rA0	0x00000001..0x00FFFFFF
     B:  rBE.rB2.rB1.rB0	0x00000002..0x01FFFFFE
     A < B
 */
	clr	rAE
	clr	rBE
2:	cp	rA0, rB0
	cpc	rA1, rB1
	cpc	rA2, rB2
	brlo	3f
	subi	rA3, lo8(-1)
	sbci	rB3, hi8(-1)
	lsl	rB0
	rol	rB1
	rol	rB2
	rol	rBE
	breq	2b
3:
	rcall	.L_div
	mov	r0, ZL
	brmi	5f		; N is result of 'com ZL' from .L_div

4:	ldi	ZL, 0x80
	rcall	.L_div1
	subi	rA3, lo8(1)
	sbci	rB3, hi8(1)
	lsr	ZL
	rol	r0
	brpl	4b

5:	rcall	.L_div
	mov	ZH, ZL
	rcall	.L_div

	lsl	rA0
	rol	rA1
	rol	rA2
	rol	rAE
	cp	rB0, rA0
	cpc	rB1, rA1
	cpc	rB2, rA2
	cpc	rBE, rAE
	ldi	rAE, 0x80
	breq	4f
	sbc	rAE, rAE

4:	mov	rA2, r0
	X_movw	rA0, ZL	
	clr	ZH
	
  ; exponent += 125
	subi	rA3, lo8(-125)
	sbci	rB3, hi8(-125)
	brmi	13f		; denormalization is needed
  ; check to overflow
11:	cpi	rA3, 254
	cpc	rB3, r1
	brlo	15f
	XJMP	_U(__fp_inf)
  ; check lowest value of exponent to avoid long operation
12:	XJMP	_U(__fp_szero)
13:	cpi	rB3, hi8(-24)		; here rB3 < 0
	brlt	12b
	cpi	rA3, lo8(-24)
	brlt	12b
  ; mantissa >>= -rA3
14:	lsr	rA2
	ror	rA1
	ror	rA0
	ror	rAE
	ror	ZH
	subi	rA3, -1
	brne	14b
  ; pack
15:	lsl	rA2
	adc	rA3, r1		; restore exponent for normal values
	lsr	rA3
	ror	rA2
	bld	rA3, 7
	ret

.L_div:
	ldi	ZL, 1
.L_div1:
	lsl	rA0
	rol	rA1
	rol	rA2
	rol	rAE
	cp	rA0, rB0
	cpc	rA1, rB1
	cpc	rA2, rB2
	cpc	rAE, rBE
	brcs	2f
	sub	rA0, rB0
	sbc	rA1, rB1
	sbc	rA2, rB2
	sbc	rAE, rBE
2:	rol	ZL
	brcc	.L_div1
	com	ZL
	ret
ENDFUNC

#endif /* !defined(__AVR_TINY__) */
