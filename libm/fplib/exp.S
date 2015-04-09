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

/* float exp (float x);
     The exp() function returns the value of e (the base of natural
     logarithms) raised to the power of x.
 */

#define	X2BIG	 0x43000000	/* exp(-X2BIG) < 0x00000001	*/
#define	FL_1_LN2 0x3fb8aa3b	/* 1 / ln(2)			*/

/* second arg for modf(), ldexp() functions.	*/
#define	exp_lo	r20
#define	exp_hi	r21

FUNCTION exp

.L_nf:	brne	.L_nan
.L_tb:	brts	.L_zr
	XJMP	_U(__fp_inf)
.L_zr:	XJMP	_U(__fp_zero)
.L_nan:	XJMP	_U(__fp_nan)

ENTRY exp
  ; split and analize A
	XCALL	_U(__fp_splitA)
	brcs	.L_nf		; A is not a finite number
	cpi	rA3, hhi8(X2BIG << 1)
	brsh	.L_tb		; A is too big (in absolute value)
  ; save sign and jump to positive
	bld	r0, 7
	push	r0
	clt
  ; A = A / ln(2)
	ldi	rB0,  lo8(FL_1_LN2)
	ldi	rB1,  hi8(FL_1_LN2)
	ldi	rB2, hlo8(FL_1_LN2 | 0x800000)		; hidden '1'
	ldi	rB3, hhi8(FL_1_LN2 << 1)		; exponent
	XCALL	_U(__mulsf3_pse)
  ; split A into fraction and integral parts
	push	r0
	push	r0
	push	r0
	in	exp_lo, SPL_IO_ADDR
	in	exp_hi, SPH_IO_ADDR
	push	r0
	XCALL	_U(modf)
  ; calculate 2**(-x) for 0 <= x < 1
	ldi	ZL, lo8(.L_table)
	ldi	ZH, hi8(.L_table)
	XCALL	_U(__fp_powser)
  ; get integral part
	pop	exp_lo
	pop	exp_hi
	pop	ZL
	pop	ZH
  ; cast to integer
	asr	ZL
	rol	ZL
	rol	ZH
	breq	2f
	subi	ZH, 0x7e
	ori	ZL, 0x80
	clr	exp_lo
1:	lsl	ZL
	rol	exp_lo
	dec	ZH
	brne	1b
  ; negate and scale
	neg	exp_lo
	sbc	exp_hi, exp_hi
2:	XCALL	_U(ldexp)
  ; inverse for positive arg.
	pop	r0
	sbrs	r0, 7
	XJMP	_U(inverse)
	ret
ENDFUNC
	
	PGM_SECTION
.L_table:
	.byte	7
	.byte	     0x63,0x42,0x36,0xb7	; -0.0000108635
	.byte	0x9b,0xd8,0xa7,0x1a,0x39	;  0.0001474911
	.byte	0x68,0x56,0x18,0xae,0xba	; -0.0013282400
	.byte	0xab,0x55,0x8c,0x1d,0x3c	;  0.0096159779
	.byte	0xb7,0xcc,0x57,0x63,0xbd	; -0.0555036542
	.byte	0x6d,0xed,0xfd,0x75,0x3e	;  0.2402264688
	.byte	0xf6,0x17,0x72,0x31,0xbf	; -0.6931471802
	.byte	0x00,0x00,0x00,0x80,0x3f	;  1.0000000000
	.end

#endif /* !defined(__AVR_TINY__) */
