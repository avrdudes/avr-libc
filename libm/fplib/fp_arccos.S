/* Copyright (c) 2002, Reiner Patommel
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

/* flt40_t __fp_arccos (float x);
     This is an Arccos internal function. Arg must:  0 <= x <= 1.
 */

#define	FL_1	    0x3f800000		/* +1.0	*/
#define HI40_PI_2   0x3fc90fda		/* high 4 bytes of Pi/2	*/
#define	LO40_PI_2   0xa2		/* lowest byte of Pi/2	*/

#define	rC0	r16
#define	rC1	r17
#define	rC2	YL
#define	rC3	YH

ENTRY __fp_arccos

#if	defined(__AVR_HAVE_MOVW__) && __AVR_HAVE_MOVW__

  ; push
	push	rC3
	push	rC2
	push	rC1
	push	rC0
  ; calculate: sqrt(1-A), (C0 + A*(C1 + ...))
	movw	rC0, rA0
	movw	rC2, rA2

	ldi	ZL, lo8(.L_table)
	ldi	ZH, hi8(.L_table)
	XCALL	_U(__fp_powser)
	XCALL	_U(__fp_round)

	movw	rB0, rC0
	movw	rB2, rC2

	movw	rC0, rA0
	movw	rC2, rA2

	ldi	rA0,  lo8(FL_1)
	ldi	rA1,  hi8(FL_1)
	ldi	rA2, hlo8(FL_1)
	ldi	rA3, hhi8(FL_1)
	XCALL	_U(__subsf3)
	XCALL	_U(sqrt)

	movw	rB0, rC0
	movw	rB2, rC2
	
  ; restore and multiply
	pop	rC0
	pop	rC1
	pop	rC2
	pop	rC3
	XJMP	_U(__mulsf3x)

#else	/* to __AVR_HAVE_MOVW__ */

  ; save A
	push	rA3
	push	rA2
	push	rA1
	push	rA0
  ; calculate: C0 + A*(C1 + ...)
	ldi	ZL, lo8(.L_table)
	ldi	ZH, hi8(.L_table)
	XCALL	_U(__fp_powser)
	XCALL	_U(__fp_round)
  ; restore A
	pop	rB0
	pop	rB1
	pop	rB2
	pop	rB3
  ; save calculation result
	push	rA3
	push	rA2
	push	rA1
	push	rA0
  ; sqrt(1-A)	
	ldi	rA0,  lo8(FL_1)
	ldi	rA1,  hi8(FL_1)
	ldi	rA2, hlo8(FL_1)
	ldi	rA3, hhi8(FL_1)
	XCALL	_U(__subsf3)
	XCALL	_U(sqrt)
  ; multiply
	pop	rB0
	pop	rB1
	pop	rB2
	pop	rB3
	XJMP	_U(__mulsf3x)

#endif
ENDFUNC
	
	PGM_SECTION
.L_table:
	.byte	7
	.byte	     0x2c,0x7a,0xa5,0xba	; -0.0012624911
	.byte	0x6c,0xc5,0x90,0xda,0x3b	;  0.0066700901
	.byte	0x93,0x65,0xfc,0x8b,0xbc	; -0.0170881256
	.byte	0x53,0xf8,0x10,0xfd,0x3c	;  0.0308918810
	.byte	0x56,0x92,0x83,0x4d,0xbd	; -0.0501743046
	.byte	0x87,0x9d,0x3a,0xb6,0x3d	;  0.0889789874
	.byte	0xcb,0xc9,0xbf,0x5b,0xbe	; -0.2145988016
	.byte	0x73,0xda,0x0f,0xc9,0x3f	;  1.5707963050
	.end
