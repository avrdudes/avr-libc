/* Copyright (c) 2002  Michael Stumpf  <mistumpf@de.pepperl-fuchs.com>
   Copyright (c) 2006,2008  Dmitry Xmelkov
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

/* GCC expects all these functions to return -1/0/1 as for __cmpsf2 -
   compare with gcc/config/fp-bit.c (the only difference is with NaNs
   where we should always return nonzero for EQ/NE, -1 for GT/GE,
   1 for LT/LE).  -MM 2000-11-18 */

#define	ret_lo	r24	/* return value (signed byte)	*/
.ifnc	ret_lo, rA2	; This is used in __fp_cmp() function.
  .err
.endif

/* The base compare function.
   Return:
     if (A < B)
        rA2 = -1, C = 0
     elif (A == B)
        rA2 = 0, C = 0
     elif (A > B)
        rA2 = 1, C = 0
     else // isnan(A) || isnan(B)
        C = 1
 */
ENTRY	__fp_cmp
	lsl	rA3
	sbc	r0, r0		; r0 = (A < 0) ? -1 : 0
	lsl	rB3
	sbc	rBE, rBE	; rBE = (B < 0) ? -1 : 0
  ; isnan(A) ?
	ldi	ZL, 0x80	; NaN: 0x{f/7}f800001..0x{f/7}fffffff
	ldi	ZH, 0xfe
	cp	r1, rA0
	cpc	r1, rA1
	cpc	ZL, rA2
	cpc	ZH, rA3
	brlo	9f		; branch, if C == 1
  ; isnan(B) ?
	cp	r1, rB0
	cpc	r1, rB1
	cpc	ZL, rB2
	cpc	ZH, rB3
	brlo	9f		; branch, if C == 1
  ; compare
	sub	rA0, rB0
	sbc	rA1, rB1
	sbc	rA2, rB2
	sbc	rA3, rB3	; C is set, if A < B
	brne	1f
  ; absolute values are equal, check signs
	eor	r0, rBE
	breq	9f		; if branch, rA2 = 0, C = 0
  ; force -0.0 == +0.0
	or	rB0, rB1
	or	rB0, rB2
	or	rB0, rB3
	brne	2f		; evaluate sign(B)
	ret
  ; view argument signes
1:	eor	r0, rBE		; C is not changed
	brne	2f		; signs are different
	sbci	rBE, 1		; rBE[0] = (A < B && A > 0) ? 0 : 1
2:	lsr	rBE		; C = above result OR sign(B)
  ; build return value, C is set, if A > B
	ldi	rA2, -1
	adc	rA2, r1
	adc	rA2, r1		; C = 0 at any case
9:	ret
ENDFUNC

#endif /* !defined(__AVR_TINY__) */
