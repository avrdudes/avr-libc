/* Copyright (c) 2007  Dmitry Xmelkov
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

/* double round (double A);
     The round() function rounds A to the nearest integer, but rounds
     halfway cases away from zero (instead of to the nearest even
     integer). Overflow is impossible.
   Return:
     The rounded value. If A is an integral or infinite, A itself is
     returned. If A is NaN, then NaN is returned.

   Algorithm roughly:
     - split
     - shift right to obtain the 0.5 at the little bit
     - if the little bit is set, add 1 to mantissa
     - merge to float
   This is a balance between space and speed.
 */
ENTRY round
	XCALL	_U(__fp_splitA)
	brcs	.L_nf
  ; A is finite
	cpi	rA3, 126	; exponent field of 0.5
	brlo	.L_zr		; A is too small
  ; fabs(A) >= 0x0.800000p+00
	cpi	rA3, 126+24
	brsh	4f		; A is too big
  ; fabs(A) <= 0x0.ffffffp+23
1:	cpi	rA3, 126+16
	brsh	3f		; shift by 0..7 positions is needed
  ; quick shift by 8
	mov	rA0, rA1
	mov	rA1, rA2
	clr	rA2
	subi	rA3, -8
	rjmp	1b
  ; slow shift
2:	lsr	rA2
	ror	rA1
	ror	rA0
	inc	rA3
3:	cpi	rA3, 126+23
	brlo	2b
  ; round
	mov	rAE, rA0
	andi	rAE, 1
	add	rA0, rAE
	adc	rA1, r1
	adc	rA2, r1
  ; check and correct a possible overflow
	brcc	4f
	ror	rA2
	ror	rA1
	ror	rA0
	inc	rA3
  ; merge
4:	XJMP	_U(__fp_mintl)

.L_nf:	XJMP	_U(__fp_mpack)	; pass nonfinite arg "as is"
.L_zr:	XJMP	_U(__fp_szero)	; return +0.0/-0.0

ENDFUNC

#endif /* !defined(__AVR_TINY__) */
