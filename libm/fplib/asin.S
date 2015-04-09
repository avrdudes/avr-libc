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

/* float asin (float A);
     The asin() function returns the arc sine in radians and the value is
     mathematically defined to be between -PI/2 and PI/2 (inclusive).
 */


#if !defined(__AVR_TINY__)

#include "fp32def.h"
#include "asmdef.h"

#define	X2SMALL     0x3e78ffff
#define HI40_PI_2   0x3fc90fda		/* high 4 bytes of Pi/2	*/
#define	LO40_PI_2   0xa2		/* lowest byte of Pi/2	*/

ENTRY asin
  ; save A sign
	push	rA3
  ; A = fabs(A)
	andi	rA3, 0x7f
  ; is A too small ?
	ldi	ZL,  hhi8(X2SMALL + 1)
	cpi	rA2, hlo8(X2SMALL + 1)
	cpc	rA3, ZL
	brsh	1f
  ; for small x
	ldi	ZL, lo8 (.L_table)
	ldi	ZH, hi8 (.L_table)
	XCALL	_U(__fp_powsodd)
	rjmp	2f
  ; arcsin(x) = Pi/2 - arccos(x)
1:	XCALL	_U(__fp_arccos)
	subi	rA3, 0x80
	ldi	rBE, LO40_PI_2
	ldi	rB0,  lo8(HI40_PI_2)
	ldi	rB1,  hi8(HI40_PI_2)
	ldi	rB2, hlo8(HI40_PI_2)
	ldi	rB3, hhi8(HI40_PI_2)
	XCALL	_U(__addsf3x)
	XCALL	_U(__fp_round)
  ; restore sign
2:	pop	r0
	sbrc	r0, 7
	subi	rA3, 0x80
	ret
ENDFUNC

	PGM_SECTION
.L_table:
	.byte	3
	.byte	     0x6e,0xdb,0x36,0x3d	; 15/336
	.byte	0x9a,0x99,0x99,0x99,0x3d	; 3/40
	.byte	0xab,0xaa,0xaa,0x2a,0x3e	; 1/6
	.byte	0x00,0x00,0x00,0x80,0x3f	; 1
	.end

#endif /* !defined(__AVR_TINY__) */
