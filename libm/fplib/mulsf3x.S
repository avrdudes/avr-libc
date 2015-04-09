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

/*
 */

#if !defined(__AVR_TINY__)

#include "fp32def.h"
#include "asmdef.h"

FUNCTION __mulsf3x

#if	defined(__AVR_ENHANCED__) && __AVR_ENHANCED__

0:	XCALL	_U(__fp_pscA)
	brcs	1f
	XCALL	_U(__fp_pscB)
	brcs	1f
	and	rA3, rB3		; one of args is 0xff
	breq	1f
	XJMP	_U(__fp_inf)		; nonzero * Inf --> Inf
1:	XJMP	_U(__fp_nan)		; 0 * Inf --> NaN
2:	clr	r1			; after 'mul rA3,rB3'
	XJMP	_U(__fp_szero)

ENTRY   __mulsf3x
	XCALL	_U(__fp_split3)
	brcs	0b

ENTRY   __mulsf3_pse			; post split entry
  ; check zero
	mul	rA3, rB3		; r1 would be clean
	breq	2b
  ; rB3.rA3 := rA3 + rB3
	add	rA3, rB3
	ldi	rB3, 0
	adc	rB3, rB3

  ; multiplication:  rA2.rA1.rA0 * rB2.rB1.rB0  -->  rA2.rA1.rA0.rAE.ZH.ZL

  ; ZH.ZL = rA0 * rB0
	mul	rA0, rB0
	movw	ZL, r0
  ; rAE.ZH += rA1 * rB0
	mul	rA1, rB0
	clr	rAE
	add	ZH, r0
	adc	rAE, r1
  ; rBE.rAE.ZH = rAE.ZH + rA0 * rB1
	mul	rA0, rB1
	clr	rBE
	add	ZH, r0
	adc	rAE, r1
	adc	rBE, rBE
  ; rA0.rBE.rAE = rBE.rAE + rA0 * rB2
	mul	rA0, rB2
	clr	rA0
	add	rAE, r0
	adc	rBE, r1
	adc	rA0, rA0
  ; rA0.rBE.rAE += rA2 * rB0
	mul	rA2, rB0
	clr	rB0
	add	rAE, r0
	adc	rBE, r1
	adc	rA0, rB0
  ; rA0.rBE.rAE += rA1 * rB1
	mul	rA1, rB1
	add	rAE, r0
	adc	rBE, r1
	adc	rA0, rB0	; rB0 == 0
  ; rB0.rA0.rBE = rA0.rBE + rA2 * rB1
	mul	rA2, rB1
	add	rBE, r0
	adc	rA0, r1
	adc	rB0, rB0	; rB0 was 0
  ; rB0.rA0.rBE += rA1 * rB2
	mul	rA1, rB2
	clr	rB1
	add	rBE, r0
	adc	rA0, r1
	adc	rB0, rB1
  ; rB0.rA0 += rA2 * rB2
	mul	rA2, rB2
	add	rA0, r0
	adc	rB0, r1
  ; move result:  rA2.rA1.rA0.rAE.ZH.ZL = rB0.rA0.rBE.rAE.ZH.ZL
	mov	rA2, rB0
	mov	rA1, rA0
	mov	rA0, rBE
  ; __zero_reg__
	clr	r1

#else	/* to __AVR_ENHANCED__	*/

0:	XCALL	_U(__fp_pscA)
	brcs	1f
	XCALL	_U(__fp_pscB)
	brcs	1f
	and	rA3, rB3		; one of args is 0xff
	breq	1f
	XJMP	_U(__fp_inf)		; nonzero * Inf --> Inf
1:	XJMP	_U(__fp_nan)		; 0 * Inf --> NaN
2:	XJMP	_U(__fp_szero)

ENTRY   __mulsf3x
	XCALL	_U(__fp_split3)
	brcs	0b

ENTRY   __mulsf3_pse			; post split entry
  ; check zero
	tst	rA3
	breq	2b
	tst	rB3
	breq	2b
  ; rB3.rA3 := rA3 + rB3
	add	rA3, rB3
	ldi	rB3, 0
	adc	rB3, rB3

  ; multiplication:  rA2.rA1.rA0 * rB2.rB1.rB0  -->  rA2.rA1.rA0.rAE.ZH.ZL

	clr	rBE		; 4-d byte of rB*
	clr	ZL
	clr	ZH
	clr	rAE
  ; r0.rAE.ZH.ZL += rA0 * rB2.rB1.rB0
	clr	r0
	sec			; to count loops
	ror	rA0
1:	brcc	2f
	add	ZL,  rB0
	adc	ZH,  rB1
	adc	rAE, rB2
	adc	r0,  rBE
2:	lsl	rB0
	rol	rB1
	rol	rB2
	rol	rBE
	lsr	rA0
	brne	1b
  ; rA0.r1.r0.rAE.ZH += rA1 * rBE.rB2.rB1
	ror	rA1		; C was 1
3:	brcc	4f
	add	ZH,  rB1
	adc	rAE, rB2
	adc	r0,  rBE
	adc	r1,  rB0
	brcc	4f
	inc	rA0
4:	lsl	rB1
	rol	rB2
	rol	rBE
	rol	rB0
	lsr	rA1
	brne	3b
  ; rA0.r1.r0.rAE += rA2 * rB0.rBE.rB2
	ror	rA2		; C was 1
5:	brcc	6f
	add	rAE, rB2
	adc	r0,  rBE
	adc	r1,  rB0
	adc	rA0, rB1
6:	lsl	rB2
	rol	rBE
	rol	rB0
	rol	rB1
	lsr	rA2
	brne	5b
  ; move result:  rA2.rA1.rA0.rAE.ZH.ZL := rA0.r1.r0.rAE.ZH.ZL
	mov	rA2, rA0
	mov	rA1, r1
	mov	rA0, r0
  ; __zero_reg__
	clr	r1

#endif	/* not __AVR_ENHANCED__	*/

  ; exponent -= 127	(Why not 126?  For compare conviniency.)
	subi	rA3, lo8(127)
	sbci	rB3, hi8(127)
	brmi	13f		; denormalization is needed
	breq	15f		; normalization is impossible
  ; result exponent > min ==> normalization is possible
10:	tst	rA2
	brmi	11f		; mantissa is normal
  ; mantissa <<= 1
	lsl	ZL
	rol	ZH
	rol	rAE
	rol	rA0
	rol	rA1
	rol	rA2
  ; exponent -= 1
	subi	rA3, lo8(1)
	sbci	rB3, hi8(1)
	brne	10b
  ; check to overflow
11:	cpi	rA3, 254
	cpc	rB3, r1
	brlo	15f
	XJMP	_U(__fp_inf)
  ; check lowest value of exponent to avoid long operation
12:	XJMP	_U(__fp_szero)
13:	cpi	rB3, hi8(-24)		; here rB3 < 0
	brlt	12b
	cpi	rA3, lo8(-24)
	brlt	12b
  ; mantissa >>= -rA3
14:	lsr	rA2
	ror	rA1
	ror	rA0
	ror	rAE
	ror	ZH
	ror	ZL
	subi	rA3, -1
	brne	14b
  ; for rounding
15:	or	ZH, ZL
  ; pack
	lsl	rA2
	adc	rA3, r1		; restore exponent for normal values
	lsr	rA3
	ror	rA2
	bld	rA3, 7		; sign
	ret
ENDFUNC

#endif /* !defined(__AVR_TINY__) */
