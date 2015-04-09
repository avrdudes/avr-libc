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

#include "fp32def.h"
#include "asmdef.h"

/* float cosh (float x);
     The cosh() function returns the hyperbolic cosine of x, which is
     defined mathematically as (exp(x) + exp(-x)) / 2.

   Notes:
     ldexp() is called twice to avoid overflow with too big x argument.
 */

#define	exp_lo	r20
#define	exp_hi	r21

ENTRY cosh
  ; A = exp(-fabs(x))/2 	negative to exclude an extra inversion
	ori	rA3, 0x80
	XCALL	_U(exp)
	ldi	exp_lo, lo8(-1)
	ldi	exp_hi, hi8(-1)
	XCALL	_U(ldexp)
  ; save A and calculate exp(fabs(x))/2
	push	rA3
	push	rA2
	push	rA1
	push	rA0
	ldi	exp_lo, lo8(2)
	ldi	exp_hi, hi8(2)
	XCALL	_U(ldexp)
	XCALL	_U(inverse)
  ; exp(x)/2 + exp(-x)/2
	pop	rB0
	pop	rB1
	pop	rB2
	pop	rB3
	XJMP	_U(__addsf3)
ENDFUNC
