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

/* Return:
     rA3.rA2.rA1.rA0  - value, negate is done, if needed
     C                - set, if Infinity or overflow
     T                - sign of input value, cleared for -0.0
   Notes:
     * Infinity or overflow:  return 0xffffffff with C = 1
 */
ENTRY   __fixsfsi
ENTRY   __fixunssfsi
	rcall	_U(__fp_splitA)
	brcc	1f		; isfinite(A)
	breq	.L_ovfl		; Inf
.L_zero:
	rjmp	_U(__fp_zero)

1:	subi	rA3, 127	; 1.0 exponent field
	brlo	.L_zero		; too small

	ldi	rAE, 31
	sub	rAE, rA3
	brlo	.L_ovfl		; fabs(A) >= 1.0 * 2**32
	/* Now rAE:
	     31 - exponent was 127+0, shift >>23 is needed,
	      0 - exponent was 127+31, shift <<8 is needed.	*/
	clr	rA3
	subi	rAE, 8		; rAE= -8..+23
	brpl	3f
  ; fabs(A) >= 1.0 * 2**24  Shift to left is needed.
	/* Shift to 8 is not optimized specialy as an exotic.	*/
2:	lsl	rA0
	rol	rA1
	rol	rA2
	rol	rA3
	inc	rAE
	brmi	2b
	rjmp	.L_sign
  ; Shift to right is needed
3:	/* Now rAE:
	     23 - exponent was 127+0, shift >>23 is needed,
	      1 - exponent was 127+22, shift >>1 is needed,
	      0 - exponent was 127+23, no shift is needed.	*/
	subi	rAE, 8
	brmi	5f
  ; quick shift by 8
4:	mov	rA0, rA1
	mov	rA1, rA2
	clr	rA2
	subi	rAE, 8
	brpl	4b
	
5:	subi	rAE, -8		; rAE = 0..7
	breq	.L_sign
  ; shift to 1..7 positions
6:	lsr	rA2
	ror	rA1
	ror	rA0
	dec	rAE
	brne	6b
.L_sign:
	brtc	7f
	com	rA3
	com	rA2
	com	rA1
	neg	rA0
	sbci	rA1, -1
	sbci	rA2, -1
	sbci	rA3, -1
7:	clc
	ret
  ; overflow, C is set already
.L_ovfl:
	ldi	rA0, 0xff
	ldi	rA1, 0xff
	X_movw	rA2, rA0
	ret
ENDFUNC
