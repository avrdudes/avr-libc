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

/* double log (double A)
   The log() function returns the natural logarithm of A.
 */

#define	FL_M1	0xbf800000	/* -1.0	*/
#define	LN_2	0x3f317218	/* ln(2.0) = 0.69314718	*/

#define	rC3	YH
#define	rC2	YL		/* adiw,sbiw are used	*/
#define	rC1	r17
#define	rC0	r16
#define	rCE	r15

FUNCTION log

.L_nf:	brts	.L_nan		; branch, if -Inf
	XJMP	_U(__fp_mpack)	; pass as is: NaN --> NaN, +Inf --> +Inf
.L_nan:	XJMP	_U(__fp_nan)
.L_min:	set
	XJMP	_U(__fp_inf)

ENTRY log
	XCALL	_U(__fp_splitA)
	brcs	.L_nf		; !isfinite(A)
	tst	rA3
	breq	.L_min		; -Inf
	brts	.L_nan		; log(negative)
	
	push	rC3
	push	rC2
	push	rC1
	push	rC0
	push	rCE
  ; normalize (if Subnormal)
	mov	rC2, rA3	; place exponent to pair rC3.rC2
	clr	rC3
	tst	rA2
	brmi	2f
1:	sbiw	rC2, 1
	lsl	rA0
	rol	rA1
	rol	rA2
	brpl	1b
2:
  ; calculate log(1+x) for x:  -0x0.20p+0 <= x < 0.E0p+0
	/* Different tables are used:
	     .L_tlow  - for small values: -0x0.20p+0 <= x < + 0x0.18p+0
	     .L_thigh - for others	*/
	ldi	rB0,  lo8(FL_M1)
	ldi	rB1,  hi8(FL_M1)
	ldi	rB2, hlo8(FL_M1)
	ldi	rB3, hhi8(FL_M1)
	ldi	rA3, 0x3f
	cpi	rA2, 0x98
	brlo	3f
	cpi	rA2, 0xE0
	brlo	4f
	adiw	rC2, 1
	andi	rA2, ~0x80
3:	XCALL	_U(__addsf3)
	ldi	ZL, lo8(.L_tlow)
	ldi	ZH, hi8(.L_tlow)
	rjmp	5f
4:	XCALL	_U(__addsf3)
	ldi	ZL, lo8(.L_thigh)
	ldi	ZH, hi8(.L_thigh)
5:	XCALL	_U(__fp_powser)

	X_movw	rC0, rA0
	X_movw	rA0, rC2	; rA1.rA0 = exponent (possible negative)
	X_movw	rC2, rA2
	mov	rCE, rAE
  ; calculate log() of exponent
	subi	rA0, 127	; 127 is exponent field of 1.0
	sbc	rA1, r1
	asr	rA1
	rol	rA1		; C = rA1 sign bit
	sbc	rA2, rA2
	sbc	rA3, rA3
	XCALL	_U(__floatsisf)
	ldi	rB0,  lo8(LN_2)
	ldi	rB1,  hi8(LN_2)
	ldi	rB2, hlo8(LN_2)
	ldi	rB3, hhi8(LN_2)
	XCALL	_U(__mulsf3x)
	
	mov	rBE, rCE
	X_movw	rB0, rC0
	X_movw	rB2, rC2

	pop	rCE
	pop	rC0
	pop	rC1
	pop	rC2
	pop	rC3
	
	XCALL	_U(__addsf3x)
	XJMP	_U(__fp_round)
ENDFUNC
	
	PGM_SECTION

.L_tlow:		; __fp_powser() table for small values
	.byte	8
	.byte        0x00,0x00,0x00,0xbe        ; -0.1250000000
	.byte   0x92,0x24,0x49,0x12,0x3e        ;  0.1428571429
	.byte   0xab,0xaa,0xaa,0x2a,0xbe        ; -0.1666666667
	.byte   0xcd,0xcc,0xcc,0x4c,0x3e        ;  0.2000000000
	.byte   0x00,0x00,0x00,0x80,0xbe        ; -0.2500000000
	.byte   0xab,0xaa,0xaa,0xaa,0x3e        ;  0.3333333333
	.byte   0x00,0x00,0x00,0x00,0xbf        ; -0.5000000000
	.byte   0x00,0x00,0x00,0x80,0x3f        ;  1.0000000000
	.byte   0x00,0x00,0x00,0x00,0x00        ;  0.0000000000

.L_thigh:		; __fp_powser() table for other values
	.byte	8
	.byte        0x41,0x78,0xd3,0xbb        ; -0.0064535442
	.byte   0x43,0x87,0xd1,0x13,0x3d        ;  0.0360884937
	.byte   0x19,0x0e,0x3c,0xc3,0xbd        ; -0.0953293897
	.byte   0x42,0x82,0xad,0x2b,0x3e        ;  0.1676540711
	.byte   0x68,0xec,0x82,0x76,0xbe        ; -0.2407338084
	.byte   0xd9,0x8f,0xe1,0xa9,0x3e        ;  0.3317990258
	.byte   0x4c,0x80,0xef,0xff,0xbe        ; -0.4998741238
	.byte   0x01,0xc4,0xff,0x7f,0x3f        ;  0.9999964239
	.byte   0x00,0x00,0x00,0x00,0x00        ;  0.0000000000
											
	.end

#endif /* !defined(__AVR_TINY__) */
