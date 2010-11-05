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

/* <non_standart> __fp_split3 (float A, float B);
     It splits two float numbers.

   Return:
     rA3, rA2.rA1.rA0	- exponent and mantissa of A (see __fp_splitA)
     rB3, rB2.rB1.rB0	- exponent and mantissa of B (see __fp_splitA)
     Flags:
        C = 0	- both numbers are finite
	C = 1   - A and/or B is Inf/NaN
	T = sign(A) ^ sign(B)

   Notes:
     * Flag is different sense vs __fp_splitA()
     * All other registers are not changed.
 */
ENTRY   __fp_split3
  ; rA3[7] := sign(A) ^ sign(B)
	sbrc	rB3, 7
	subi	rA3, 0x80
  ; split B
	lsl	rB2
	rol	rB3		; exponent
	breq	4f
	cpi	rB3, 0xff	; C = 1, if rB3 != 0xff
	breq	5f
1:	ror	rB2		; restore rB2 and (possible) hidden bit

/* <non_standart> __fp_splitA (float A);
     It splits an A float number.

   Return:
     rA3 - exponent:
        0	for +0.0/-0.0
	1..254	for finite number
	255	for Inf/NaN
     rA2.rA1.rA0 - mantissa:
        0			for +0.0/-0.0
	0x000001..0x7fffff	for subnormal (and rA3 = 1)
	0x800000..0xffffff	for normal (rA3 = 1..254)
	0x000000		for Inf
	0x000001..0x7fffff	for NaN
     Flags:
        C = 0		for finite number
	C = 1, Z = 1	for Inf
	C = 1, Z = 0	for NaN
        T = sign

   Notes:
     * Other registers are not scratched.
 */
ENTRY   __fp_splitA
	lsl	rA2
2:	bst	rA3, 7
	rol	rA3
	breq	6f
	cpi	rA3, 0xff
	breq	7f
3:	ror	rA2
	ret

  ; B is zero or subnormal
4:	cp	r1, rB0
	cpc	r1, rB1
	cpc	r1, rB2		; C = 1, if B is not a zero
	rol	rB3		; C = 0
	rjmp	1b
  ; B is not a finite
5:	lsr	rB2
	rcall	__fp_splitA
	rjmp	8f

  ; A is zero or subnormal
6:	cp	r1, rA0
	cpc	r1, rA1
	cpc	r1, rA2
	rol	rA3
	rjmp	3b
  ; A is not a finite
7:	lsr	rA2		; C = 0
	cpc	rA1, r1
	cpc	rA0, r1
8:	sec
	ret
ENDFUNC

#endif /* !defined(__AVR_TINY__) */
