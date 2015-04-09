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

/* float tan (float A);
     The tan() function returns the tangent of A, where A is given
     in radians.
 */

/* Calculation:
     0 <= x <= Pi/4	 --> tan(x)		fmod
     Pi/4 < x < Pi/2	 --> 1/tan(Pi/2-x)	fmod, Pi/2-x, 1/x
     Pi/2 <= x <= 3*Pi/4 --> -1/tan(x-Pi/2)	fmod, 1/x, -x
     3*Pi/4 < x < Pi	 --> -tan(Pi-x)		fmod, Pi/2-x, -x
 */
#define	HI40_PIO4	0x3F490FDA	/* (flt40_t) Pi/4	*/
#define	LO40_PIO4	0xA2		/* --"--		*/
#define	HI40_PIO2	0x3FC90FDA	/* (flt40_t) Pi/2	*/
#define	LO40_PIO2	0xA2		/* --"--		*/

#define	rsign	YH

ENTRY tan
  ; save sign
	push	rsign
	mov	rsign, rA3
  ; fmod by Pi/2
	XCALL	_U(__fp_rempio2)
  ; save perion number
	lsr	ZL
	ror	rsign
  ; is A <= Pi/4 ?
#if  LO40_PIO4 == 0xFF		/* HI40_PIO4: increment is not needed	*/
# error
#endif
	ldi	rB0,  lo8(HI40_PIO4)
	ldi	rB1,  hi8(HI40_PIO4)
	ldi	rB2, hlo8(HI40_PIO4)
	ldi	rB3, hhi8(HI40_PIO4)
	cpi	rAE,  LO40_PIO4 + 1
	cpc	rA0, rB0
	cpc	rA1, rB1
	cpc	rA2, rB2
	cpc	rA3, rB3
	ror	rsign		; save comparison result
	brmi	1f		; N == C flag after comparison
  ; for A > Pi/4:  tan(A) == 1/tan(Pi/2 - A)
#if (HI40_PIO4 ^ HI40_PIO2) & 0xFF00FFFF	/* 'ldi' optimization	*/
# error
#endif
	ldi	rBE, LO40_PIO2
	ldi	rB2, hlo8(HI40_PIO2)
	ori	rA3, 0x80
	XCALL	_U(__addsf3x)
	XCALL	_U(__fp_round)
  ; calculate tan(A) for  0 <= A <= Pi/4
1:	ldi	ZL, lo8(.L_table)
	ldi	ZH, hi8(.L_table)
	XCALL	_U(__fp_powsodd)
  ; correct result
	lsl	rsign
	brvs	2f
	XCALL	_U(inverse)
2:	lsl	rsign
	brvc	3f
	subi	rA3, 0x80
3:	pop	rsign
	ret
ENDFUNC
	
	PGM_SECTION
.L_table:
	.byte	6
	.byte	     0x64,0xec,0x1b,0x3c	;  0.0095168091
	.byte	0x04,0xbc,0x16,0x3e,0x3b	;  0.0029005250
	.byte	0xe5,0xb9,0x3c,0xc9,0x3c	;  0.0245650893
	.byte	0x37,0xc2,0x9e,0x5a,0x3d	;  0.0533740603
	.byte	0x66,0x04,0x98,0x08,0x3e	;  0.1333923995
	.byte	0xea,0x69,0xaa,0xaa,0x3e	;  0.3333314036
	.byte	0x00,0x00,0x00,0x80,0x3f	;  1.0000000000
	.end
