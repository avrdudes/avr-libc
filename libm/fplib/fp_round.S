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

/* float __fp_round (<non_standart>);
     The __fp_round() function rounds an input number. This is an internal
     function intended to run after __addsf3x() and like.
   Input:
     rA3.rA2.rA1.rA0.rAE  - number in the flt40_t format
     ZH			  - more lower bits are nonzero flag
 */
ENTRY   __fp_round
  ; is A finite ?
	mov	r0, rA3
	inc	r0
	lsl	r0
	brne	1f
	tst	rA2
	brmi	3f		; no, A is not a finite number
  ; rounding
1:	lsl	rAE
	brcc	3f
	or	rAE, ZH
	brne	2f
	sbrs	rA0, 0		; round to even
	rjmp	3f
2:	subi	rA0, -1
	sbci	rA1, -1
	sbci	rA2, -1
	sbci	rA3, -1

3:	ret
ENDFUNC

#endif /* !defined(__AVR_TINY__) */
