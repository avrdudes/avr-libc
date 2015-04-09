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

/* long long __fixsfdi (float x);

   The __fixsfdi() function converts a float argument x into signed 8-bytes
   value.  If x is nonintegral, then it is rounded down to the nearest
   integer.  If absolute value of x is too big (fabs(x) >= 2**63, or NaN,
   the value 2**63 is returned.  This is similar to Gcc+Glibc in
   'float --> long' conversion case.
 */
ENTRY	__fixsfdi
	ldi	rAE, 62
	rcall	.L_sf2di
	brcc	1f
	ldi	rA3, 0x80
1:	ret

/* unsigned long long __fixunssfdi (float x);

   The __fixunssfdi() function converts a float argument x into unsigned
   8-bytes value.  If x is nonintegral, then it is rounded down to the
   nearest integer.  If absolute value of x is too big (fabs(x) >= 2**64,
   or NaN, the 0 is returned.  For negative x (if fabs(x) < 2**64, result
   is corresponded to signed conversion (with possible overflow). This is
   similar to Gcc+Glibc in 'float --> unsigned long' conversion case.
   
   Examples:
     __fixunssfdi(-1.0)		   --> 0xff..ffLL
     __fixunssfdi(0x0.ffffffp+63)  --> 0x7fffff8000000000LL
     __fixunssfdi(-0x0.ffffffp+63) --> 0x0000008000000000LL
     __fixunssfdi(0x1.000002p+63)  --> 0x8000010000000000LL
     __fixunssfdi(0x1.fffffep+63)  --> 0xffffff0000000000LL
     __fixunssfdi(0x1.000000p+64)  --> 0LL
   
   Note: Gcc+Glibc give the strange results for negative x in such convers.
 */
ENTRY	__fixunssfdi
	ldi	rAE, 63

/* The .L_sf2di() function converts a float value into 8-bytes integer.

   Input:
     rA3.rA2.rA1.rA0	- float input
     rAE		- max power of input: must 62 for signed result
    			and 63 for unsigned result
   Output:
     rA3..rA0.rB3..rB0	- long long output, 0 if overflow was
     flag C		- set if overflow

   Note:  C is set and 0 return in case of:
     - x too large: fabs(x) >= 2**(rAE+1),
     - x is +/- Inf
     - x is NaN
 */
.L_sf2di:
  ; clear LSBytes
	clr	rB0
	clr	rB1
	X_movw	rB2, rB0
  ; split
	XCALL	_U(__fp_splitA)
	brcs	.L_ovfl		; is not finite

	subi	rA3, 127	; 1.0 exponent field
	brlo	.L_zero		; too small

	cp	rAE, rA3
	brlo	.L_ovfl		; fabs(A) >= 2**64 (or 2**63)
	ldi	rAE, 63
	sub	rAE, rA3
	/* Now rAE is, for example:
	     63 - exponent was 127+0, shift >>55 is needed,
	      0 - exponent was 127+63, shift <<8 is needed.	*/
	clr	rA3
	subi	rAE, 8		; rAE= -8..+55
	brpl	3f
  ; fabs(A) >= 1.0 * 2**56  Shift to left is needed.
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
	     55 - exponent was 127+0, shift >>55 is needed,
	      1 - exponent was 127+54, shift >>1 is needed,
	      0 - exponent was 127+55, no shift is needed.	*/
	subi	rAE, 8
	brmi	5f
  ; quick shift by 8
4:	mov	rB0, rB1
	mov	rB1, rB2
	mov	rB2, rB3
	mov	rB3, rA0
	mov	rA0, rA1
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
	ror	rB3
	ror	rB2
	ror	rB1
	ror	rB0
	dec	rAE
	brne	6b
.L_sign:
	brtc	7f
	XCALL	_U(__fp_negdi)
7:	clc
	ret

.L_zero:
	clc
.L_ovfl:			  ; overflow, C is set already
	ldi	rA0, 0
	ldi	rA1, 0
	X_movw	rA2, rA0
	ret
ENDFUNC
