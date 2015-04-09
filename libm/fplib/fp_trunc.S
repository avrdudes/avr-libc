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

/* <non_standart> __fp_trunc (float A);
     This is an internal functions. __fp_trunc() splits argument and
     truncates to zero direction. It is intended as first part of work
     in floor(), ceil(), trunc() functions.

   Return:
     T	   - sign bit
     C	   - set if A is not finite (A is splited)
     rA3   - exponent:
    		0	-  A is zero
		1..126	-  fabs(A) < 1
		127..	-  fabs(A) >= 1
     rA2.rA1.rA0  - mantissa (with hidden bit)
     rAE	  - flag of nonzero fraction

   Notes:
     * Return value is not a float value. Function, like __fp_mpack(),
     is needed to merge a float.
     * In case of 'fabs(A) < 1' rA2.rA1.rA0 and rAE are random.
 */

ENTRY __fp_trunc
	XCALL	_U(__fp_splitA)
	brcs	9f
  ; A is finite
	ldi	rAE, 126
	cp	rAE, rA3
	brsh	9f
  ; fabs (A) >= 1.0
	clr	rAE
3:	cpi	rA3, 127+23-7
	brsh	5f		; shift by 1..7 positions or no shift
  ; quick shift by 8
	cp	r1, rA0
	adc	rAE, r1
	mov	rA0, rA1
	mov	rA1, rA2
	clr	rA2
	subi	rA3, -8
	rjmp	3b
  ; slow shift
4:	lsr	rA2
	ror	rA1
	ror	rA0
	adc	rAE, r1
	inc	rA3
5:	cpi	rA3, 127+23
	brlo	4b
9:	ret			; C == 0
ENDFUNC

#endif /* !defined(__AVR_TINY__) */
