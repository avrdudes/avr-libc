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

/* float __fp_sinus (flt40_t A, ZL);
 */

#define	HI40_PIO2	0x3FC90FDA	/* high 4 bytes Pi/2	*/
#define	LO40_PIO2	0xA2

ENTRY __fp_sinus
	push	ZL
	
	sbrs	ZL, 0
	rjmp	1f
	ldi	rBE, LO40_PIO2
	ldi	rB0,  lo8(HI40_PIO2)
	ldi	rB1,  hi8(HI40_PIO2)
	ldi	rB2, hlo8(HI40_PIO2)
	ldi	rB3, hhi8(HI40_PIO2 | 0x80000000)
	XCALL	_U(__addsf3x)

1:	XCALL	_U(__fp_round)

	pop	r0
	inc	r0
	sbrc	r0, 1
	subi	rA3, 0x80

	ldi	ZL, lo8(.L_table)
	ldi	ZH, hi8(.L_table)
	XJMP	_U(__fp_powsodd)
ENDFUNC
	
	PGM_SECTION
.L_table:
	.byte	5
	.byte	     0xa8,0x4c,0xcd,0xb2	; -0.0000000239
	.byte	0xd4,0x4e,0xb9,0x38,0x36	;  0.0000027526
	.byte	0xa9,0x02,0x0c,0x50,0xb9	; -0.0001984090
	.byte	0x91,0x86,0x88,0x08,0x3c	;  0.0083333315
	.byte	0xa6,0xaa,0xaa,0x2a,0xbe	; -0.1666666664
	.byte	0x00,0x00,0x00,0x80,0x3f	;  1.0000000000
	.end				

#endif /* !defined(__AVR_TINY__) */
