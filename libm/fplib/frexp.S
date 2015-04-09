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

/* float frexp (float A, int *pexp);
     The frexp() function is used to split the number A into a normalized
     fraction and an exponent which is stored by pexp.

   Return:
     If A is a normal float point number, the frexp() function returns the
     value v, such that v has a magnitude in the interval [1/2, 1) or zero,
     and A equals v times 2 raised to the power *pexp. If A is zero, both
     parts of the result are zero. If A is not a finite number, the frexp()
     returns A as is and stores 0 by pexp.

   Note:
     This implementation permits a zero pointer as a directive to skip
     a storing the exponent.
 */

#define	pexp_lo	r20

ENTRY frexp

	X_movw	ZL, pexp_lo

  ; Write 0 for next cases: Zero, Inf or NaN.
#if  defined(__AVR_XMEGA__) && __AVR_XMEGA__
	adiw	ZL, 0
	breq	1f
#endif
	st	Z, r1
	std	Z+1, r1
1:
	XCALL	_U(__fp_splitA)
	brcs	.L_nf			; return the same value
	tst	rA3
	breq	3f
	subi	rA3, 126
	sbc	rB3, rB3

	sbrs	rA2, 7
	XCALL	_U(__fp_norm2)

#if  defined(__AVR_XMEGA__) && __AVR_XMEGA__
	adiw	ZL, 0
	breq	2f
	st	Z, rA3
	std	Z+1, rB3
2:
#else
  ; NULL is a legal address. Instead to check Z==0, will simply
  ; write and restore r1.
	st	Z, rA3
	std	Z+1, rB3
	clr	r1		; protection to Z == 0
#endif

	andi	rA2, 0x7f
	ldi	rA3, 0x3f

3:	bld	rA3, 7		; restore sign
	ret
.L_nf:
	XJMP	_U(__fp_mpack)
ENDFUNC

#endif /* !defined(__AVR_TINY__) */
