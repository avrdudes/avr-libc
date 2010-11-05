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

/* float __floatsisf (long)
   float __floatunsisf (unsigned long)
 */

#if !defined(__AVR_TINY__)

#include "fp32def.h"
#include "asmdef.h"

ENTRY   __floatunsisf
	clt
	rjmp	1f
	
ENTRY   __floatsisf
	bst	rA3, 7		; sign
	brtc	1f
  ; negate A
	com	rA3
	com	rA2
	com	rA1
	neg	rA0
	sbci	rA1, -1
	sbci	rA2, -1
	sbci	rA3, -1
1:
	tst	rA3
	breq	4f
  ; shift to right
	mov	ZH, rA3
	ldi	rA3, 127 + 23	; exponent
	clr	rAE
2:	inc	rA3
	lsr	ZH
	ror	rA2
	ror	rA1
	ror	rA0
	ror	rAE
	cpse	ZH, r1
	rjmp	2b
  ; rounding
	brpl	.L_pack		; flags from 'ror rAE'
	lsl	rAE
	brne	3f
	sbrs	rA0, 0		; round to even
	rjmp	.L_pack
3:	subi	rA0, -1
	sbci	rA1, -1
	sbci	rA2, -1
	sbci	rA3, -1
	rjmp	.L_pack

4:	tst	rA2
	breq	5f
	ldi	rA3, 127 + 23
	rjmp	8f

5:	tst	rA1
	breq	6f
	ldi	rA3, 127 + 15
	mov	rA2, rA1
	mov	rA1, rA0
	rjmp	7f
	
6:	tst	rA0
	breq	9f		; 0.0
	ldi	rA3, 127 + 7
	mov	rA2, rA0
	ldi	rA1, 0
7:
	ldi	rA0, 0
	brmi	.L_pack		; flag from 'tst rA*'
  ; shift to left by 1..7 positions
10:	dec	rA3
	lsl	rA0
	rol	rA1
	rol	rA2
8:	brpl	10b

.L_pack:
	lsl	rA2
	lsr	rA3
	ror	rA2
	bld	rA3, 7		; sign
9:	ret
ENDFUNC

#endif /* !defined(__AVR_TINY__) */
