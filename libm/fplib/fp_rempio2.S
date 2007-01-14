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

/* <non_standart> __fp_rempio2 (float x);
     The __fp_rempio2() function computes the remainder of dividing
     absolute value of x by Pi/2. The return value is x - n*Pi/2, where
     n is the quotient of abs(x)/(Pi/2), rounded towards zero to an integer.
   Output:
	rA3.rA2.rA1.rA0.rAE	- flt40_t remainder
	ZL			- low byte of n
 */

#define	HI40_PIO2	0x3FC90FDA	/* (flt40_t) Pi/2	*/
#define	LO40_PIO2	0xA2
#define	MNT32_PIO2	0xC90FDAA2	/* mantissa of Pi/2, 32 bits	*/
#define SPLIT_PIO2	0x7FC80FDA	/* split(HI40_PIO2)	*/

FUNCTION __fp_rempio2

0:	rjmp	_U(__fp_nan)

ENTRY __fp_rempio2
  ; split and check finite
	rcall	_U(__fp_splitA)
	brcs	0b		; only finite numbers are valid
	clt			; ignore a sign
  ; init division result ('com' at the end)
	ldi	ZL, -1
  ; compare A with Pi/2
	clr	rAE
	ldi	rB1,  hi8(SPLIT_PIO2 + 1)
	ldi	rB2, hlo8(SPLIT_PIO2 + 1)
	ldi	rB3, hhi8(SPLIT_PIO2 + 1)
	cpi	rA0,  lo8(SPLIT_PIO2 + 1)
	cpc	rA1, rB1
	cpc	rA2, rB2
	cpc	rA3, rB3
	brlo	.L_pack			; A < Pi/2 ==> return A
  ; prepare loop
	clr	ZH				; highest A byte
	subi	rA3, hhi8(HI40_PIO2 << 1)	; ilogb(A) - ilogb(B)
.Loop:
	subi	rAE,  lo8(MNT32_PIO2)
	sbci	rA0,  hi8(MNT32_PIO2)
	sbci	rA1, hlo8(MNT32_PIO2)
	sbci	rA2, hhi8(MNT32_PIO2)
	sbci	ZH, 0
	brpl	5f
	subi	rAE,  lo8(-MNT32_PIO2)
	sbci	rA0,  hi8(-MNT32_PIO2)
	sbci	rA1, hlo8(-MNT32_PIO2)
	sbci	rA2, hhi8(-MNT32_PIO2)
	sbci	ZH, -1
	sec
5:	rol	ZL
	subi	rA3, 1
	brlo	6f
	lsl	rAE
	rol	rA0
	rol	rA1
	rol	rA2
	rol	ZH
	rjmp	.Loop
6:
  ; normalize
	/* FIXME: Is it possible to obtain a zero value in rA2.1.0.E ?
	   I do't known. So, there is a check in exponent decrement.	*/
	ldi	rA3, hhi8((HI40_PIO2 << 1) - 0x01000000)
7:	tst	rA2
	brmi	8f
	lsl	rAE
	rol	rA0
	rol	rA1
	rol	rA2
	dec	rA3
	brne	7b
8:	inc	rA3
.L_pack:
	com	ZL
	rjmp	_U(__fp_mpack)
ENDFUNC
