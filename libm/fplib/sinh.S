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

/* float sinh (float x);
     The sinh() function returns the hyperbolic sine of x, which is
     defined mathematically as (exp(x) - exp(-x)) / 2.

   Notes:
     ldexp() is used twice to avoid overflow for big x.
 */

#define	X2SMALL	0x3e9fffff	/* < 0.3125	*/

#define	exp_lo	r20		/* float ldexp (float, int exp);	*/
#define	exp_hi	r21

ENTRY sinh
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
  ; exp(-fabs(x))	// negative to exclude an extra inversion
1:	ori	rA3, 0x80
	XCALL	_U(exp)
  ; exp(-fabs(x)) / 2
	ldi	exp_lo, lo8(-1)
	ldi	exp_hi, hi8(-1)
	XCALL	_U(ldexp)
  ; save
	push	rA3
	push	rA2
	push	rA1
	push	rA0
  ; exp(fabs(x)) / 2
	ldi	exp_lo, lo8(2)
	ldi	exp_hi, hi8(2)
	XCALL	_U(ldexp)
	XCALL	_U(inverse)
  ; result (in absolute value)
	pop	rB0
	pop	rB1
	pop	rB2
	pop	rB3
	XCALL	_U(__subsf3)
  ; set sign
2:	pop	r0
	sbrc	r0, 7
	ori	rA3, 0x80
	ret
ENDFUNC
	
	PGM_SECTION
.L_table:
	.byte	2
	.byte	     0x89,0x88,0x08,0x3c	; 1/120
	.byte	0xab,0xaa,0xaa,0x2a,0x3e	; 1/6
	.byte	0x00,0x00,0x00,0x80,0x3f	; 1
	.end

#endif /* !defined(__AVR_TINY__) */
