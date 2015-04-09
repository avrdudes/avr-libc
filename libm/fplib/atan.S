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

/* float atan (float A);
     The atan() function calculates the arc tangent of A; that is
     the value whose tangent is A.

   Algorithm:
	if (x > 1)
	    return Pi/2 - atan(1/x)
	elif (x < -1)
	    return -Pi/2 - atan(1/x)
	else
	    return x * (1 - C1 * x**2 + ... + C8 * x**16)
 */


#if !defined(__AVR_TINY__)

#include "fp32def.h"
#include "asmdef.h"

#define FL_1	    0x3f800000		/* +1.0	*/
#define HI40_PI_2   0x3fc90fda		/* high 4 bytes of Pi/2	*/
#define LO40_PI_2   0xa2		/* lowest byte of Pi/2	*/

#define	corr	YH

ENTRY atan
	push	corr
	clr	corr
  ; inverse A, if needed
	mov	rAE, rA3
	andi	rAE, 0x7f		; rAE.rA2.rA1.rA0 == fabs(A)
	ldi	rB2, hlo8(FL_1)
	ldi	rB3, hhi8(FL_1)
	cp	r1, rA0
	cpc	r1, rA1
	cpc	rB2, rA2
	cpc	rB3, rAE
	brsh	1f
	mov	corr, rA3		; rA3 != 0
	XCALL	_U(inverse)
  ; calculate atan(A) for -1.0 <= A <= +1.0
1:	push	rA3
	push	rA2
	push	rA1
	push	rA0
	XCALL	_U(square)
	ldi	ZL, lo8(.L_table)
	ldi	ZH, hi8(.L_table)
	XCALL	_U(__fp_powser)
	XCALL	_U(__fp_round)
	pop	rB0
	pop	rB1
	pop	rB2
	pop	rB3
	XCALL	_U(__mulsf3x)
  ; is correction needed ?
	tst	corr
	breq	2f
  ; add/sub Pi/2
	subi	rA3, 0x80
	ldi	rBE, LO40_PI_2
	ldi	rB0,  lo8(HI40_PI_2)
	ldi	rB1,  hi8(HI40_PI_2)
	ldi	rB2, hlo8(HI40_PI_2)
	ldi	rB3, hhi8(HI40_PI_2)
	andi	corr, 0x80
	eor	rB3, corr
	XCALL	_U(__addsf3x)
  ; restore and round
2:	pop	corr
	XJMP	_U(__fp_round)
ENDFUNC

	PGM_SECTION
.L_table:
	.byte	8
	.byte	     0x4a,0xd7,0x3b,0x3b	;  0.0028662257
	.byte	0xce,0x01,0x6e,0x84,0xbc	; -0.0161657367
	.byte	0xbf,0xfd,0xc1,0x2f,0x3d	;  0.0429096138
	.byte	0x6c,0x74,0x31,0x9a,0xbd	; -0.0752896400
	.byte	0x56,0x83,0x3d,0xda,0x3d	;  0.1065626393
	.byte	0x00,0xc7,0x7f,0x11,0xbe	; -0.1420889944
	.byte	0xd9,0xe4,0xbb,0x4c,0x3e	;  0.1999355085
	.byte	0x91,0x6b,0xaa,0xaa,0xbe	; -0.3333314528
	.byte	0x00,0x00,0x00,0x80,0x3f	;  1.0000000000
	.end

#endif /* !defined(__AVR_TINY__) */
