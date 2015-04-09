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

/* float fdim (float x, float y);
     The fdim() function  return max(x-y,0). If x or y or both are NaN,
     NaN is returned.

   Notes:
     * In case 'A == B' subtraction is called to save flash space.
     Contrary it is needed to check 'Inf - Inf'.  And the __subsf3()
     is fast if both arguments are equal.
 */

ENTRY fdim
  ; sign(A) | sign(B)
	mov	r0, rA3
	or	r0, rB3
	brmi	2f
  ; A >= 0 and B >= 0
	cp	rA0, rB0
	cpc	rA1, rB1
	cpc	rA2, rB2
	cpc	rA3, rB3
	brcs	3f
1:	XJMP	_U(__subsf3)
  ; A < 0 or B < 0
2:	cp	rB0, rA0
	cpc	rB1, rA1
	cpc	rB2, rA2
	cpc	rB3, rA3
	brcc	1b
  ; before 0 return, check a NaN
3:	ldi	ZL, 0x80	; hlo8(Inf)
	ldi	ZH, 0xfe	; hhi8(Inf) after 'lsl'
	lsl	rA3
	cp	r1, rA0
	cpc	r1, rA1
	cpc	ZL, rA2
	cpc	ZH, rA3
	brlo	.L_nan
  ; check B for NaN
	lsl	rB3
	cp	r1, rB0
	cpc	r1, rB1
	cpc	ZL, rB2
	cpc	ZH, rB3
	brlo	.L_nan
  ; return 0
	XJMP	_U(__fp_zero)

.L_nan:	XJMP	_U(__fp_nan)
ENDFUNC

#endif /* !defined(__AVR_TINY__) */
