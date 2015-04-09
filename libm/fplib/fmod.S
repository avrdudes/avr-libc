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

/* double fmod (double x, double y);
     The fmod() function computes the remainder of dividing x by y. The
     return value is x - n*y, where n is the quotient of x/y, rounded
     towards zero to an integer.
 */

FUNCTION fmod

0:	XCALL	_U(__fp_pscA)
	brcs	.L_nan		; isnan(A)
	breq	.L_nan		; isinf(A)
	XCALL	_U(__fp_pscB)
	brcc	1f		; isinf(B) -- legal arg: return A

.L_nan:	XJMP	_U(__fp_nan)
.L_sz:	XJMP	_U(__fp_szero)

ENTRY fmod
  ; split and check exceptions
	mov	ZL, rA3		; save
	XCALL	_U(__fp_split3)
	brcs	0b
	tst	rB3
	breq	.L_nan		; B == 0
1:	bst	ZL, 7		; sign(A)
  ; compare A & B (in absolute value)
	cp	rA0, rB0
	cpc	rA1, rB1
	cpc	rA2, rB2
	cpc	rA3, rB3
	brlo	.L_pk		; fabs(A) < fabs(B) --> return A
	breq	.L_sz		; fabs(A) == fabs(B) --> return sign(A)*0
  ; ZH.ZL = ilogb(A), normalize A
	mov	ZL, rA3
	clr	ZH
	tst	rA2
	brmi	2f
1:	sbiw	ZL, 1
	lsl	rA0
	rol	rA1
	rol	rA2
	brpl	1b
  ; rB3.rA3 = ilogb(B), normalize B
2:	mov	rA3, rB3
	clr	rB3
	tst	rB2
	brmi	4f
3:	subi	rA3, lo8(1)
	sbci	rB3, hi8(1)
	lsl	rB0
	rol	rB1
	rol	rB2
	brpl	3b
  ; prepare loop
4:	clr	rAE		; highest A byte
	sub	ZL, rA3		; ZH.ZL = ilogb(A) - ilogb(B)
	sbc	ZH, rB3
.Loop:
	sub	rA0, rB0
	sbc	rA1, rB1
	sbc	rA2, rB2
	sbc	rAE, r1
	breq	.L_sz
	brpl	5f
	add	rA0, rB0
	adc	rA1, rB1
	adc	rA2, rB2
	adc	rAE, r1
5:	sbiw	ZL, 1
	brmi	6f
	lsl	rA0
	rol	rA1
	rol	rA2
	rol	rAE
	rjmp	.Loop
6:
	subi	rA3, lo8(1)
	sbci	rB3, hi8(1)
	brmi	9f
	breq	8f
7:	tst	rA2
	brmi	8f
	lsl	rA0
	rol	rA1
	rol	rA2
	subi	rA3, lo8(1)
	sbci	rB3, hi8(1)
	brne	7b
8:	inc	rA3
.L_pk:
	XJMP	_U(__fp_mpack)
9:	lsr	rA2
	ror	rA1
	ror	rA0
	subi	rA3, -1
	brne	9b
	rjmp	8b
ENDFUNC

#endif /* !defined(__AVR_TINY__) */
