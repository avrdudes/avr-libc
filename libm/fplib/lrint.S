/* Copyright (c) 2007  Dmitry Xmelkov
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

/* long lrint (double A);
     The lrint() function rounds A to the nearest integer, rounding the
     halfway cases to the even integer direction. (That is both 1.5 and
     2.5 values are rounded to 2). This function is similar to rint()
     function, but it differs in type of return value and in that an
     overflow is possible.
   Return:
     The rounded long integer value. If A is not a finite number or an
     overflow was, this realization returns the LONG_MIN value (0x80000000).

   Algorithm roughly:
     - split
     - shift mantissa according to exponent
     - round (if shift was to right)
     - restore the sign
 */

ENTRY lrint
	XCALL	_U(__fp_splitA)
	brcs	.L_err
  ; A is finite
	subi	rA3, 126	; exponent field of 0.5
	brlo	.L_zr		; A is too small
  ; fabs(A) >= 0x0.800000p+00
	subi	rA3, 24
	brlo	.L_right	; shtft to right and round
	breq	.L_sign		; no shift
  ; fabs(A) >= 0x0.800000p+25
	cpi	rA3, 8
	brsh	.L_err		; fabs(A) is too big

  ; 0x0.800000p+25 <= fabs(A) <= 0x0.ffffffp+31  --> shift to left by 1..7
	mov	r0, rA3		; shift counter
	clr	rA3		; MSB
  ; rA3.2.1.0 <<= r0
1:	lsl	rA0
	rol	rA1
	rol	rA2
	rol	rA3
	dec	r0
	brne	1b
	rjmp	.L_sign

  ; 0x0.800000p+00 <= fabs(A) <= 0x0.ffffffp+23
  ; Shift A to right by 1 (rA3 == -1) .. 24 (rA3 == -24) positions and
  ; round.
.L_right:
	clr	rAE		; accumulator for lower bits
2:	cpi	rA3, -7
	brge	3f
  ; Quick shift to right by 8. The trick with rAE is needed to save info
  ; about the lowerest bits. This will be used to compare fraction with
  ; 0.5 value.
	cpse	rAE, r1
	ldi	rAE, 1
	or	rAE, rA0
	mov	rA0, rA1
	mov	rA1, rA2
	clr	rA2
	subi	rA3, -8
	brne	2b
	rjmp	.L_round
  ; shift to right by 1..7 (slow)
3:	lsr	rA2
	ror	rA1
	ror	rA0
	ror	rAE
	brcc	4f
	ori	rAE, 1		; save flag that lowerst bits are not all 0
4:	inc	rA3
	brne	3b
  ; round
.L_round:
	lsl	rAE
	brcc	.L_sign		; fraction < 0.5
	brne	7f		; fraction > 0.5
	sbrs	rA0, 0
	rjmp	.L_sign		; fraction == 0.5 and value is even
7:	subi	rA0, -1
	sbci	rA1, -1
	sbci	rA2, -1		; rA2 was <= 0x7f, so rA3 will not changed

  ; restore the sign and return
.L_sign:
	brtc	6f
	com	rA3
	com	rA2
	com	rA1
	neg	rA0
	sbci	rA1, -1
	sbci	rA2, -1
	sbci	rA3, -1
6:	ret

.L_err:	set			; force return 0x80000000
	XJMP	_U(__fp_szero)

.L_zr:	XJMP	_U(__fp_zero)	; return 0x00000000

ENDFUNC

#endif /* !defined(__AVR_TINY__) */
