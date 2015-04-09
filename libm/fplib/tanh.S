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

/* float tanh (float x);
     The tanh() function returns the hyperbolic tangent of x, which is
     defined mathematically as sinh(x) / cosh(x).

   Algorithm:
	if (fabs(x) <= X2SMALL)
	    return Polinom(x)
	else
	    return sign(x) * (1 - exp(-2*fabs(x))) / (1 + exp(-2*fabs(x)))
 */

#define	X2SMALL	0x3e0fffff	/* < 0.140625	*/
#define	FL_P1	0x3f800000	/* +1.0	*/

#define	exp_lo	r20		/* float ldexp (float, int exp);	*/
#define	exp_hi	r21

ENTRY tanh
  ; save sign
	push	rA3
  ; is arg too small ?
	andi	rA3, 0x7f
	ldi	ZH,  hhi8 (X2SMALL + 1)
	cpi	rA2, hlo8 (X2SMALL + 1)
	cpc	rA3, ZH
	brsh	1f
  ; for small x
	ldi	ZL, lo8(.L_table)
	ldi	ZH, hi8(.L_table)
	XCALL	_U(__fp_powsodd)
	rjmp	2f
  ; exp(-2*fabs(x))
1:	ori	rA3, 0x80
	ldi	exp_lo, lo8(1)
	ldi	exp_hi, hi8(1)
	XCALL	_U(ldexp)	; possible overflow -- no matter
	XCALL	_U(exp)
  ; save result and calculate 1 + exp(-2*fabs(x))
	push	rA3
	push	rA2
	push	rA1
	push	rA0
	ldi	rB0,  lo8(FL_P1)
	ldi	rB1,  hi8(FL_P1)
	ldi	rB2, hlo8(FL_P1)
	ldi	rB3, hhi8(FL_P1)
	XCALL	_U(__addsf3)
  ; save/restore and calculate 1 - exp(-2*fabs(x))
	pop	rB0
	pop	rB1
	pop	rB2
	pop	rB3
	push	rA3
	push	rA2
	push	rA1
	push	rA0
	ldi	rA0,  lo8(FL_P1)
	ldi	rA1,  hi8(FL_P1)
	ldi	rA2, hlo8(FL_P1)
	ldi	rA3, hhi8(FL_P1)
	XCALL	_U(__subsf3)
  ; restore
	pop	rB0
	pop	rB1
	pop	rB2
	pop	rB3
  ; divide
	XCALL	_U(__divsf3)
  ; sign
2:	pop	r0
	sbrc	r0, 7
	subi	rA3, 0x80
	ret
ENDFUNC

	PGM_SECTION
.L_table:
	.byte	2
	.byte	     0x89,0x88,0x08,0x3e	; 2/15
	.byte	0xab,0xaa,0xaa,0xaa,0xbe	; -1/3
	.byte	0x00,0x00,0x00,0x80,0x3f	; 1
	.end

#endif /* !defined(__AVR_TINY__) */
