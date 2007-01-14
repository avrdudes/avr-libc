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

/*  double sqrt (double);
    Square root function.
 */

FUNCTION sqrt

.L_nf:	brne	.L_pk		; NaN, return as is
	brtc	.L_pk		; sqrt(+Inf) --> +Inf
.L_nan:	rjmp	_U(__fp_nan)
.L_pk:	rjmp	_U(__fp_mpack)

ENTRY sqrt
  ; split and check arg.
	rcall	_U(__fp_splitA)
	brcs	.L_nf		; !isfinite(A)
	tst	rA3
	breq	.L_pk		; return 0 with original sign
	brts	.L_nan		; sqrt(negative) --> NaN
  ; exponent bias
	subi	rA3, 127
	sbc	rB3, rB3	; exponent high byte
  ; normalize, if A is subnormal
	sbrs	rA2, 7
	rcall	_U(__fp_norm2)
  ; calculate result exponent
	lsr	rB3
	ror	rA3
  ; expand A mantissa to rAE.rA2.rA1.rA0
	ldi	rAE, 0
	brcc	1f		; after 'ror rA3'
	lsl	rA0
	rol	rA1
	rol	rA2
	rol	rAE
1:

#define	mvb0	ZL
#define mvb1	ZH
#define mvb2	rBE
#define	rem0	r16
#define	rem1	r17
#define	rem2	r0
#define	rem3	rB3
  ; save temporary regs.
	push	rem1
	push	rem0
  ; init variables
	/* arg's mantissa:	rAE.rA2.rA1.rA0
	   result:		rB2.rB2.rB0
	   moving bit:		mvb2.mvb1.mvb0
	   remain value:	rem3.rem2.rem1.rem0	*/
	clr	r0
	X_movw	rB0, r0
	X_movw	rB2, r0
	X_movw	rem0, r0
	X_movw	mvb0, r0
	ldi	mvb2, 0x80
.Loop:
  ; rem += mvb
	add	rem0, mvb0
	adc	rem1, mvb1
	adc	rem2, mvb2
	adc	rem3, r1
  ; A -= rem
	sub	rA0, rem0
	sbc	rA1, rem1
	sbc	rA2, rem2
	sbc	rAE, rem3
	brsh	1f
  ; restore A
	add	rA0, rem0
	adc	rA1, rem1
	adc	rA2, rem2
	adc	rAE, rem3
  ; restore rem
	sub	rem0, mvb0
	sbc	rem1, mvb1
	sbc	rem2, mvb2
	sbc	rem3, r1
	rjmp	2f
  ; B += mvb
1:	add	rB0, mvb0
	adc	rB1, mvb1
	adc	rB2, mvb2
  ; rem += mvb
	add	rem0, mvb0
	adc	rem1, mvb1
	adc	rem2, mvb2
	adc	rem3, r1
  ; A <<= 1
2:	lsl	rA0
	rol	rA1
	rol	rA2
	rol	rAE
  ; while (mvb >>= 1)
	lsr	mvb2
	ror	mvb1
	ror	mvb0
	brcc	.Loop
  ; round
	cp	rem0, rA0
	cpc	rem1, rA1
	cpc	rem2, rA2
	cpc	rem3, rAE	; C is set if rem < A
	adc	rB0, r1
	adc	rB1, r1
	adc	rB2, r1
  ; pop temporary regs.
	pop	rem0
	pop	rem1
  ; merge result and return
	X_movw	rA0, rB0
	mov	rA2, rB2
	subi	rA3, lo8(-127)		; exponent bias
	lsl	rA2
	lsr	rA3
	ror	rA2
	ret
ENDFUNC
