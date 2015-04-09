/* Copyright (c) 2002  Michael Stumpf  <mistumpf@de.pepperl-fuchs.com>
   Copyright (c) 2006  Dmitry Xmelkov
   Copyright (c) 2008  Ruud v Gessel
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

FUNCTION __fp_rempio2

0:	XJMP	_U(__fp_nan)

ENTRY __fp_rempio2
  ; split and check finite
	XCALL	_U(__fp_splitA)
	brcs	0b		; only finite numbers are valid
	clt			; ignore a sign
  ; init division result
	ldi	ZL, 0
  ; extend A
	clr	rAE
  ; check (and modify) exponent
	subi	rA3, hhi8(HI40_PIO2 << 1)
	brlo	5f		; fabs(A) < 1.0 radian, C is set
  ; prepare loop
	ldi	rB0,  lo8(HI40_PIO2)
	ldi	rB1,  hi8(HI40_PIO2)
	ldi	rB2, hlo8(HI40_PIO2 | 0x800000)		; + hidden bit
	rjmp	1f

.Loop:	lsl	ZL
	lsl	rAE
	rol	rA0
	rol	rA1
	rol	rA2
	brcs	2f
1:	cpi	rAE, lo8(LO40_PIO2)
	cpc	rA0, rB0
	cpc	rA1, rB1
	cpc	rA2, rB2
	brlo	3f
2:	subi	rAE, lo8(LO40_PIO2)
	sbc	rA0, rB0
	sbc	rA1, rB1
	sbc	rA2, rB2
	inc	ZL
3:	dec	rA3
	brpl	.Loop

  ; Normalize, we know that rA2.1.0.E >= 0x0E. You can check this with
  ; a test program below.
	cpi	rA2,0x80
	brcc	5f
4:	dec	rA3
	lsl	rAE
	rol	rA0
	rol	rA1
	rol	rA2			; C := 0
	brpl	4b

5:	sbci	rA3, hhi8((HI40_PIO2<<1) + 0x01000000)	; undo the subi 0x7f
	XJMP	_U(__fp_mpack_finite)
ENDFUNC

#if 0
/* This is a test program to find the smallest value of rA2.1.0.E after
   division. The nonzero value gives a garanty that normalization loop
   is finite.	*/

#include <stdio.h>
#define	MNT32_PIO2	0xC90FDAA2

int main ()
{
    unsigned long rA210;
    unsigned long rA210E;
    int rA3;
    unsigned long c;
    unsigned long amin = 0xffffffff;

    for (rA210 = 0x800000; rA210 <= 0xffffff; rA210 += 1) {
	rA210E = rA210 << 8;
	c = 0;
	rA3 = 127;	/* this is max for finite number	*/
	goto m;
	do {
	    c = rA210E & 0x80000000;
	    rA210E <<= 1;
	  m:
	    if (c || (rA210E >= MNT32_PIO2))
		rA210E -= MNT32_PIO2;
	    if (rA210E < amin) {
		amin = rA210E;
	        printf ("min of rA210E: 0x%08lx\r", amin);
		fflush (stdout);
	    }
	} while (--rA3 >= 0);
    }
    putchar ('\n');
    return 0;
}
#endif
