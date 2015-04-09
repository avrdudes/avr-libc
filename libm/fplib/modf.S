/* Copyright (c) 2002  Michael Stumpf  <mistumpf@de.pepperl-fuchs.com>
   Copyright (c) 2006,2009  Dmitry Xmelkov
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

/*  double modf (double x, double *iptr);

    The modf() function breaks the argument x into an integral part and a
    fractional part, each of which has the same sign as x. The integral part
    is stored in iptr.
	This implementation skips writing by zero pointer.
 */

#define	iptr_lo	r20

ENTRY modf
ENTRY modff
  ; save iptr
	X_movw	ZL, iptr_lo
  ; XH = exponent field
	X_movw	XL, rA2
	lsl	XL
	rol	XH
  ; B = A
	X_movw	rB0, rA0
	X_movw	rB2, rA2
  ; Is there an integral part?
	subi	XH, 127		; exp of 1.0
	brsh	1f
  ; fabs(x) < 1.0:	*iptr = copysign(0, x),  return x
	clr	rB0
	clr	rB1
	clr	rB2
	andi	rB3, 0x80
	rjmp	.L_write
  ; Is there a fraction part?
1:	subi	XH, 23
	brsh	4f		; no fraction part
  ; check fraction:  B >>= 23 - (exp-127)
	mov	XL, XH		; Now XH is -23..-1
	clr	r0		; to control, is the fraction zero?
2:	lsr	rB2
	ror	rB1
	ror	rB0
	adc	r0, r1
	inc	XL
	brmi	2b
	tst	r0
	breq	.L_nfrc		; fraction == 0
  ; restore and clear fraction:  B <<= 23 - (exp-127)
3:	lsl	rB0
	rol	rB1
	rol	rB2
	inc	XH
	brmi	3b
  ; write B
	rcall	.L_write
  ; return nonzero fraction:  A - B
	XJMP	_U(__subsf3)
  ; exponent too big:  compare with smallest NaN (0x7f800001)
4:	cpi	rA0, 1
	cpc	rA1, r1
	ldi	XL, 0x80
	cpc	rA2, XL
	sbci	XH, 128 - 23
	brsh	.L_write	; NaN: write and return as is
  ; fraction == 0
.L_nfrc:
	X_movw	rB0, rA0
	X_movw	rB2, rA2
  ; A = 0.0 with sign
	clr	rA0
	clr	rA1
	clr	rA2
	andi	rA3, 0x80
.L_write:
	adiw	ZL, 0		; skip writing with NULL pointer
	breq	1f
	st	Z,   rB0
	std	Z+1, rB1
	std	Z+2, rB2
	std	Z+3, rB3
1:	ret
ENDFUNC

#endif /* !defined(__AVR_TINY__) */
