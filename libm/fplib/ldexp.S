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

/* double ldexp (double x, int exp)
   The ldexp() function returns the result of multiplying the
   floating-point number x by 2 raised to the power exp.
 */
#define	exp_lo	r20
#define	exp_hi	r21

FUNCTION ldexp

.L_inf:	XJMP	_U(__fp_inf)
.L_pk:	XJMP	_U(__fp_mpack)

ENTRY ldexp
	XCALL	_U(__fp_splitA)
	brcs	.L_pk			; as is
	tst	rA3
	breq	.L_pk			; ldexp(0,*) is always 0

.ifnc  rB3, exp_hi
  .err	; rB3 and exp_hi are different
.endif
	add	rA3, exp_lo		; rB3.rA3 := new exponent
	adc	rB3, r1
	brvs	.L_inf		    ; overflow is possible for exp > 0 only

  ; check exponent for minus and zero
	subi	rA3, lo8(1)
	sbci	rB3, hi8(1)
	brlt	5f		; denormalization is needed
	breq	.L_pack		; normalization is impossible
1:	tst	rA2
	brmi	2f
	lsl	rA0
	rol	rA1
	rol	rA2
	subi	rA3, lo8(1)
	sbci	rB3, hi8(1)
	brne	1b		; C == 0, Z == 0
  ; check to overflow
2:	cpi	rA3, 254
	cpc	rB3, r1
	brge	.L_inf
.L_pack:
	lsl	rA2
	adc	rA3, r1		; restore exponent for normal numbers
	lsr	rA3
	ror	rA2
	bld	rA3, 7		; sign
	ret
  ; exponent <= 0
5:	cpi	rB3, hi8(-24)
	brlt	.L_zero
	cpi	rA3, lo8(-24)
	brlt	.L_zero
  ; denormalize A
	clr	rAE
6:	lsr	rA2
	ror	rA1
	ror	rA0
	ror	rAE
	brcc	7f
	ori	rAE, 1
7:	inc	rA3
	brne	6b
.L_round:
	lsl	rAE
	brcc	.L_pack
	brne	4f
	sbrs	rA0, 0
	rjmp	.L_pack
4:	subi	rA0, -1
	sbci	rA1, -1
	sbci	rA2, -1
	sbci	rA3, -1
	rjmp	.L_pack
.L_zero:
	XJMP	_U(__fp_szero)
ENDFUNC

#endif /* !defined(__AVR_TINY__) */
