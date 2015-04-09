/* Copyright (c) 2009 Dmitry Xmelkov
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

/* $Id$	*/

#if !defined(__AVR_TINY__)

#include "fp32def.h"
#include "asmdef.h"

/* double cbrt (double)
   Cube root function.
 */

#define RCNT	r25

#define RA0	r22
#define RA1	r23
#define RA2	r24

#define RM0	r26
#define RM1	r27
#define RM2	r28
#define RM3	r29
#define RM4	RA0
#define RM5	RA1
#define RM6	RA2

#define RY0	r30
#define RY1	r31
#define RY2	r15

#define RQ0	r16
#define RQ1	r17
#define RQ2	r18
#define RQ3	r19
#define RQ4	r8
#define RQ5	r9

#define RD0	r20
#define RD1	r21
#define RD2	r10
#define RD3	r11
#define RD4	r12
#define RD5	r13
#define RD6	r14

#define	REM	RD0

FUNCTION cbrt

/* Division by 3.
   Input:
	rA3	- arg
   Output:
	rA3	- quotient
	REM	- remainder
	RY0	- zero (was counter)
   Scratch:
	r0
 */
#if  defined(__AVR_ENHANCED__) && __AVR_ENHANCED__
.Ldiv3:	mov	REM, rA3	; save
	ldi	RY0, 85
	inc	rA3
	mul	rA3, RY0
	mov	rA3, r1		; quotient (((rA3 + 1) * 85) / 256)
	ldi	RY0, 3
	mul	RY0, rA3	; r1 := 0, as the result is less than 256
	sub	REM, r0		; remainder
	clr	RY0		; API
	ret
#else
.Ldiv3:	sub	REM, REM	; clear remainder and carry
	ldi	RY0, 8		; loop counter
	rol	rA3
1:	rol	REM
	cpi	REM, 3
	brlo	2f
	subi	REM, 3
2:	rol	rA3
	dec	RY0
	brne	1b
	com	rA3		; because C flag was complemented in loop
	ret
#endif

0:	XJMP	_U(__fp_mpack)

ENTRY cbrt
  ; split and check arg.
	XCALL	_U(__fp_splitA)
	brcs	0b		; !isfinite(A)
	tst	rA3
	breq	0b		; return 0 with original sign

  ; save registers
	.irp	.L_reg, r29,r28,r17,r16,r15,r14,r13,r12,r11,r10,r9,r8
	push	\.L_reg
	.endr

/* Calculate exponent.
 */
	subi	rA3, 127	; bias
	brsh	5f
  ; exponent was < 0
	neg	rA3
  ; normalize, if A is subnormal
	tst	rA2
	brmi	2f
1:	inc	rA3	; increment absolute value of negative exponent
	lsl	rA0
	rol	rA1
	rol	rA2
	brpl	1b
  ; division
2:	rcall	.Ldiv3
  ; reverse remainder
	dec	REM
	brmi	4f		; remainder was 0
	brne	3f		; REM: 2 --> 1
	subi	REM, -2		; REM: 1 --> 2
3:	inc	rA3		; correct quotient
  ; restore sign of exponent
4:	neg	rA3
	rjmp	6f
  ; exponent was >= 0
5:	rcall	.Ldiv3
  ; save result exponent
6:	subi	rA3, lo8(-127)
	push	rA3

  ; clear
	clr	RY1		; RY0 == 0 after .Ldiv3 function
	clr	RY2
	X_movw	RQ0, RY0
	X_movw	RQ2, RY0
	X_movw	RQ4, RY0
	X_movw	RM0, RY0
	X_movw	RM2, RY0

  ; shift mantissa by 1..3 positions
7:	lsl	RA0
	rol	RA1
	rol	RA2
	rol	RM0
	dec	REM
	brpl	7b

/* --------------------------------------------------------------------
   Register usage:
	RCNT
	RA0..RA2
	RM0..RM2
	RY0
	RQ0..RQ1
	RD0..RD2
   Free registers for temporary values:
	RD4..RD6
 */
	ldi	RCNT, 8
.Loop1:
  ; RQ <<= 2
	lsl	RQ0
	rol	RQ1
	lsl	RQ0
	rol	RQ1
  ; RY <<= 1
	lsl	RY0
  ; RD = RY + RQ
	X_movw	RD0, RQ0
	clr	RD2
	add	RD0, RY0
	adc	RD1, r1
	adc	RD2, r1
  ; save RD
	X_movw	RD4, RD0
	mov	RD6, RD2
  ; RD <<= 1
	lsl	RD0
	rol	RD1
	rol	RD2
  ; RD += RY + RQ
	add	RD0, RD4
	adc	RD1, RD5
	adc	RD2, RD6
  ; RD |= 1
	ori	RD0, 1
  ; RM -= RD
	sub	RM0, RD0
	sbc	RM1, RD1
	sbc	RM2, RD2
	brsh	11f
  ; restore RM
	add	RM0, RD0
	adc	RM1, RD1
	adc	RM2, RD2
	rjmp	12f
  ; RQ += RY << 1
11:	X_movw	RD0, RY0
	lsl	RD0
	rol	RD1
	add	RQ0, RD0
	adc	RQ1, RD1
  ; RQ |= 1
	ori	RQ0, 1
  ; RY |= 1
	ori	RY0, 1
  ; RM = (RM << 3) <-- (RA << 3)
12:	ldi	RD0, 3
13:	lsl	RA0
	rol	RA1
	rol	RA2
	rol	RM0
	rol	RM1
	rol	RM2
	dec	RD0
	brne	13b
  ; ... while (--RCNT)
	dec	RCNT
	brne	.Loop1

/* --------------------------------------------------------------------
 */
	ldi	RCNT, 16
.Loop2:
  ; RQ <<= 2
20:	lsl	RQ0
	rol	RQ1
	rol	RQ2
	rol	RQ3
	rol	RQ4
	rol	RQ5
	com	r1
	brne	20b
  ; RY <<= 1
	lsl	RY0
	rol	RY1
	rol	RY2
  ; RD = 0
	clr	r0
	X_movw	RD0, r0
	X_movw	RD2, r0
	X_movw	RD4, r0
	clr	RD6
  ; RD += RQ
21:	add	RD0, RQ0
	adc	RD1, RQ1
	adc	RD2, RQ2
	adc	RD3, RQ3
	adc	RD4, RQ4
	adc	RD5, RQ5
	adc	RD6, r1
  ; RD += RY
	add	RD0, RY0
	adc	RD1, RY1
	adc	RD2, RY2
	adc	RD3, r1
	adc	RD4, r1
	adc	RD5, r1
	adc	RD6, r1
  ;
	com	r0
	breq	22f
  ; RD <<= 1
	lsl	RD0
	rol	RD1
	rol	RD2
	rol	RD3
	rol	RD4
	rol	RD5
	rol	RD6
	rjmp	21b
  ; RM -= RD
22:	sub	RM0, RD0
	sbc	RM1, RD1
	sbc	RM2, RD2
	sbc	RM3, RD3
	sbc	RM4, RD4
	sbc	RM5, RD5
	sbc	RM6, RD6
	brsh	23f
  ; restore RM
	add	RM0, RD0
	adc	RM1, RD1
	adc	RM2, RD2
	adc	RM3, RD3
	adc	RM4, RD4
	adc	RM5, RD5
	adc	RM6, RD6
	rjmp	24f

  ; RQ += 2*RY
23:	add	RQ0, RY0
	adc	RQ1, RY1
	adc	RQ2, RY2
	adc	RQ3, r1
	adc	RQ4, r1
	adc	RQ5, r1
	com	r0
	brne	23b
  ; RQ |= 1
	ori	RQ0, 1
  ; RY |= 1
	ori	RY0, 1
  ; RM <<= 3
24:	ldi	RD0, 3
25:	lsl	RM0
	rol	RM1
	rol	RM2
	rol	RM3
	rol	RM4
	rol	RM5
	rol	RM6
	dec	RD0
	brne	25b
	
	dec	RCNT
	breq	26f
	rjmp	.Loop2

  ; make result
26:	X_movw	rA0, RY0
	mov	rA2, RY2
	pop	rA3
	lsl	rA2
	lsr	rA3
	ror	rA2
	bld	rA3, 7			; sign

  ; restore registers and return
	.irp	.L_reg, r8,r9,r10,r11,r12,r13,r14,r15,r16,r17,r28,r29
	pop	\.L_reg
	.endr
	ret

ENDFUNC

#endif /* !defined(__AVR_TINY__) */
