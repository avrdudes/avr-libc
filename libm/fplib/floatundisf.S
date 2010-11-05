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

/* float __floatundisf (unsigned long long x)

   Input:
     rA3.rA2.rA1.rA0.rB3.rB2.rB1.rB0	- an 'x' arg
   Output:
     rA3.rA2.rA1.rA0
 */


#if !defined(__AVR_TINY__)

#include "fp32def.h"
#include "asmdef.h"

ENTRY   __floatundisf
	clt			; result sign
	
ENTRY   __fp_di2sf
	mov	ZH, rA3
	ldi	rA3, 127 + 55	; exponent for 00.80.00.00.00.00.00.00
	tst	ZH
	breq	.L_tstA2

/* Shift to right is needed by 1..8 positions.
   Optimization: accumulate an info about tail into rB2.	*/
	cp	r1, rB0
	cpc	r1, rB1
	cpc	r1, rB2
	sbc	rB2, rB2
  ; shift to right
1:	inc	rA3		; exponent += 1
	lsr	ZH
	ror	rA2
	ror	rA1
	ror	rA0
	ror	rB3
	sbci	rB2, 0		; set rB2[7] if C was 1
	tst	ZH
	brne	1b
	rjmp	.L_round

  ; x == 0
2:	clr	rA3
	ret
  ; check: is fast shift possible?
.L_tstA2:
	tst	rA2
	brne	4f
  ; fast shift to left
3:	subi	rA3, 8
	brpl	2b		; 127+55 - 7*8 --> 126
	or	rA2, rA1	; obtain Z flag
	mov	rA1, rA0
	mov	rA0, rB3
	mov	rB3, rB2
	mov	rB2, rB1
	mov	rB1, rB0
	ldi	rB0, 0
	breq	3b		; Z is result of 'or rA2,rA1'
	
/* rA2 is not 0.  It is needed shift to left by 0..7 positions.
   Optimization: rB2..rB0 are not shifted. Instead, save an info
   about tail in rB2.	*/
4:	cp	r1, rB0
	cpc	r1, rB1
	cpc	r1, rB2
	sbc	rB2, rB2
	tst	rA2
	brmi	.L_round
5:	dec	rA3		; exponent -= 1
	lsl	rB2
	rol	rB3
	rol	rA0
	rol	rA1
	rol	rA2
	brpl	5b

/* Round and pack. Now we have:
     rA3		- mantissa
     rA2.rA1.rA0.rB3	- fraction
     rB2		- is negative if tail is not equal 0	*/
.L_round:
	tst	rB3
	brpl	7f
	lsl	rB2
	rol	rB3
	brne	6f
	sbrs	rA0, 0		; round to even
	rjmp	7f
6:	subi	rA0, -1
	sbci	rA1, -1
	sbci	rA2, -1
	sbci	rA3, -1
  ; pack
7:	lsl	rA2
	lsr	rA3
	ror	rA2
	bld	rA3, 7		; sign
	ret
ENDFUNC

#endif /* !defined(__AVR_TINY__) */
