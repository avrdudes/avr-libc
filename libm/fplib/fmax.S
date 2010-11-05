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

/* float fmax (float x, float y);
     The fmax() function returns the greater of the two values x and y.
     If an argument is NaN, the other argument is returned. If both
     arguments are NaN, NaN is returned.
 */

ENTRY fmax
	lsl	rA3
	sbc	rAE, rAE	; rAE = (A < 0) ? -1 : 0
	lsl	rB3
	sbc	rBE, rBE	; rBE = (B < 0) ? -1 : 0
  ; isnan(A) ?
	ldi	ZL, 0x80	; NaN: 0x{f/7}f800001..0x{f/7}fffffff
	ldi	ZH, 0xfe
	cp	r1, rA0
	cpc	r1, rA1
	cpc	ZL, rA2
	cpc	ZH, rA3
	brlo	.L_retB		; A is NaN
  ; isnan(B) ?
	cp	r1, rB0
	cpc	r1, rB1
	cpc	ZL, rB2
	cpc	ZH, rB3
	brlo	.L_retA
  ; compare signs
	cp	rAE, rBE
	brlt	.L_retB		; A < 0, B >= 0
	brne	.L_retA		; A >= 0, B < 0
  ; compare absolute values
	cp	rA0, rB0
	cpc	rA1, rB1
	cpc	rA2, rB2
	cpc	rA3, rB3	; C is set, if A < B
  ; analize
	ror	rBE		; V = C ^ sign
	brvc	.L_retA
.L_retB:
	X_movw	rA0, rB0
	X_movw	rA2, rB2
	mov	rAE, rBE
.L_retA:
	lsr	rAE
	ror	rA3
	ret
ENDFUNC

#endif /* !defined(__AVR_TINY__) */
