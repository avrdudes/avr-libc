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

/* double ceil (double x);
     The ceil() function rounds x up to the nearest integer.

   Examples:
     ceil(1.9) --> 2.0
     ceil(-1.9) --> -1.0
 */


#if !defined(__AVR_TINY__)

#include "fp32def.h"
#include "asmdef.h"

#define FL_P1	0x3f800000	/* +1.0	*/

ENTRY   ceil
	XCALL	_U(__fp_trunc)
	brcs	.L_nf
  ; A is finite
	cpi	rA3, 127
	brsh	2f
  ; fabs(A) < 1.0
	cpse	rA3, r1
	brtc	1f
	XJMP	_U(__fp_szero)		; ceil(-0.0) is -0.0
  ; 0.0 < A < 1.0 --> +1.0
1:	ldi	rA0,  lo8(FL_P1)
	ldi	rA1,  hi8(FL_P1)
	ldi	rA2, hlo8(FL_P1)
	ldi	rA3, hhi8(FL_P1)
	ret
  ; positive values are rounded into +Inf direction
2:	brts	3f		; if negative
	cp	r1, rAE		; C = 1 if fraction != 0
	adc	rA0, r1
	adc	rA1, r1
	adc	rA2, r1		; rA2 was < 0x80, overflow is impossible
3:	XJMP	_U(__fp_mintl)

.L_nf:	XJMP	_U(__fp_mpack)	; pass nonfinite arg as is
ENDFUNC

#endif /* !defined(__AVR_TINY__) */
