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

/* float __fp_mintl (<non-standart>);
     Normalize value by shifting to left (only left) and merge parts of
     float value. Mainly, this function is intended for integral values,
     as a last stage of functions floor(), floatsisf(). Its functionality
     is very restricted: no subnormals, no rounding, no Inf/NaN.

   Input:
     T			- sign
     rA3		- exponent
     rA2.rA1.rA0	- mantissa
   Output:
     rA3.rA2.rA1.rA0	- float value

   Notes:
     * Underflow of exponent is NOT checked: result would undefined.
     * In zero case mantissa must be 0.
     * Sign bit is set in any case. -0.0 is possible.
     * Shifts are optimized for speed.
 */

ENTRY __fp_mintl

	tst	rA2
	brne	.L_bm
	tst	rA1
	breq	1f
  ; mantissa is 0x00XXXX
	subi	rA3, 8
	or	rA2, rA1	; to obtain N flag (rA2 was 0)
	mov	rA1, rA0
	rjmp	.L_a0
  ; mantissa is 0x0000XX
1:	tst	rA0
	brne	2f
	clr	rA3
	rjmp	.L_sign
  ; low mantissa byte != 0	
2:	subi	rA3, 16
	or	rA2, rA0	; to obtain N flag (rA2 was 0)
	ldi	rA1, 0
.L_a0:	ldi	rA0, 0
.L_bm:	brmi	.L_pack		; N flag is from rA2
  ; shift to left (1..7 positions)
.Loop:	dec	rA3
	lsl	rA0
	rol	rA1
	rol	rA2
	brpl	.Loop
.L_pack:
	lsl	rA2
	lsr	rA3
	ror	rA2
.L_sign:
	bld	rA3, 7		; sign
	ret
ENDFUNC
