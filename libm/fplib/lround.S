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

/* long lround (double A);
     The lround() function rounds A to the nearest integer, but rounds
     halfway cases away from zero (instead of to the nearest even integer).
     This function is similar to round() function, but it differs in
     type of return value and in that an overflow is possible.
   Return:
     The rounded long integer value. If A is infinite, NaN or an overflow
     was, this realization returns the LONG_MIN value (0x80000000).

   Algorithm roughly:
     - split
     - shift mantissa according to exponent
     - add 0.5 to round
     - restore the sign

   Objections to saturation are listen in __fixunssfsi.S file.
 */

ENTRY lround
	XCALL	_U(__fp_splitA)
	brcs	.L_err
  ; A is finite
	subi	rA3, 126	; exponent field of 0.5
	brlo	.L_zr		; A is too small
  ; fabs(A) >= 0x0.800000p+00
	subi	rA3, 24
	brlo	2f		; shtft to right and round
	breq	.L_sign		; no shift
  ; fabs(A) >= 0x0.800000p+25
	cpi	rA3, 8
	brsh	.L_err		; A is too big

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

  ; quick shift to right by 8
5:	mov	r0, rA0		; save for possible round
	mov	rA0, rA1
	mov	rA1, rA2
	clr	rA2
	subi	rA3, -8
	brne	2f
	lsl	r0		; restore C
	rjmp	4f		; and round
  ; 0x0.800000p+00 <= fabs(A) <= 0x0.ffffffp+23
  ; Shift A to right by 1 (rA3 == -1) .. 24 (rA3 == -24) positions and
  ; round.
2:	cpi	rA3, -7
	brlt	5b
  ; shift to right by 1..7 (slow)
3:	lsr	rA2
	ror	rA1
	ror	rA0		; --> C
	inc	rA3		; C is not changed
	brne	3b
  ; Round. Now flag C is set if fractional is >= 0.5
4:	adc	rA0, r1
	adc	rA1, r1
	adc	rA2, r1		; rA2 was <= 0x7f, so rA3 will not changed

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
