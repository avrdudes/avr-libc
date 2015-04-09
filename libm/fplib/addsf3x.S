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

/* <non_standart> __addsf3x (float_40 A, float_40 B);
     Internal function to add float point numbers.

   Input:
     rA3.rA2.rA1.rA0.rAE  - arg. A
     rB3.rB2.rB1.rB0.rBE  - arg. B
   Output:
     T
     rA3
     rA2.rA1.rA0.rAE.ZH
 */

#if !defined(__AVR_TINY__)

#include "fp32def.h"
#include "asmdef.h"

FUNCTION __addsf3x

0:	XCALL	_U(__fp_pscA)
	brcs	.L_nan
	XCALL	_U(__fp_pscB)
	brcs	.L_nan
	brne	.L_inf		; B is finite --> return A
	cpi	rA3, 255
	brne	.L_infB		; A is finite --> return B
	brtc	.L_inf		; Inf + Inf with the same sign
.L_nan:
	XJMP	_U(__fp_nan)
.L_infB:
	brtc	.L_inf
	com	ZL
.L_inf:
	bst	ZL, 7
	XJMP	_U(__fp_inf)

ENTRY	__addsf3x
	mov	ZL, rA3		; save sign of A
	XCALL	_U(__fp_split3)
	brcs	0b
  ; compare A and B
	cp	rAE, rBE
	cpc	rA0, rB0
	cpc	rA1, rB1
	cpc	rA2, rB2
	cpc	rA3, rB3
	brlo	2f		; fabs(A) < fabs(B)
	brne	4f		; fabs(A) > fabs(B)
	brtc	.L_add
	XJMP	_U(__fp_zero)	; A + (-A) = +0.0
  ; swap A and B
2:	brtc	3f
	com	ZL		; update sign
3:	mov	r0, rAE
	mov	rAE, rBE
	mov	rBE, r0
#if  defined(__AVR_HAVE_MOVW__) && __AVR_HAVE_MOVW__
	movw	r0, rA0
	movw	rA0, rB0
	movw	rB0, r0
	movw	r0, rA2
	movw	rA2, rB2
	movw	rB2, r0
	clr	r1
#else
	mov	r0, rA0
	mov	rA0, rB0
	mov	rB0, r0
	mov	r0, rA1
	mov	rA1, rB1
	mov	rB1, r0
	mov	r0, rA2
	mov	rA2, rB2
	mov	rB2, r0
	mov	r0, rA3
	mov	rA3, rB3
	mov	rB3, r0
#endif
  ;
4:	clr	ZH
	sub	rB3, rA3
5:	breq	7f		; shift is not needed
	cpi	rB3, -7
	brsh	6f
	cpi	rB3, -32
	brlo	.L_ret
	cp	r1, rBE
	sbci	ZH, 0
	mov	rBE, rB0
	mov	rB0, rB1
	mov	rB1, rB2
	clr	rB2
	subi	rB3, -8
	rjmp	5b
6:	lsr	rB2
	ror	rB1
	ror	rB0
	ror	rBE
	sbci	ZH, 0
	inc	rB3
	brne	6b
7:
  ; direction ?
	brtc	.L_add
  ; A -= B
	cp	r1, ZH
	sbc	rAE, rBE
	sbc	rA0, rB0
	sbc	rA1, rB1
	sbc	rA2, rB2
	brmi	.L_ret
8:	subi	rA3, 1
	breq	9f
	lsl	ZH
	rol	rAE
	rol	rA0
	rol	rA1
	rol	rA2
	brpl	8b
	rjmp	.L_ret

.L_add:
	add	rAE, rBE
	adc	rA0, rB0
	adc	rA1, rB1
	adc	rA2, rB2
	brcc	.L_ret
	ror	rA2
	ror	rA1
	ror	rA0
	ror	rAE
	ror	ZH
	cpi	rA3, 254
	brlo	9f
	rjmp	.L_inf
9:	inc	rA3
.L_ret:
	lsl	rA2
	brcs	1f
	clr	rA3
1:	lsl	ZL		; sign
	ror	rA3
	ror	rA2
	ret
ENDFUNC

#endif /* !defined(__AVR_TINY__) */
