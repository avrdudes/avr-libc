/* Copyright (c) 2006, Carlos Lamas

   based on libc/pmstring/strlcpy_P.S which is
   Copyright (c) 2003, Eric B. Weddington

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
  POSSIBILITY OF SUCH DAMAGE.

*/

/* $Id$ */

/** \ingroup avr_pgmspace
    \fn size_t strlcpy_PF (char *dst, uint_farptr_t src, size_t siz)
    \brief Copy a string from progmem to RAM.

    Copy src to string dst of size siz.  At most siz-1 characters will be
    copied. Always NULL terminates (unless siz == 0).

    \returns The strlcpy_PF() function returns strlen(src). If retval >= siz,
    truncation occurred.  The contents of RAMPZ SFR are undefined when the
    function returns */

#if !defined(__AVR_TINY__)

#if !defined(__DOXYGEN__)

#include "macros.inc"

#define dst_b1		r25
#define dst_b0		r24
#define src_b3		r23
#define src_b2		r22
#define src_b1		r21
#define src_b0		r20
#define siz_b1		r19
#define siz_b0		r18

#define rWord_b1	r25
#define rWord_b0	r24

	.text
	.global	_U(strlcpy_PF)
	.type	_U(strlcpy_PF), @function

_U(strlcpy_PF):

	X_movw	ZL, src_b0		; Z = src
	LPM_R0_ZPLUS_INIT src_b2
	X_movw	XL, dst_b0		; X = dst
	cp	siz_b0, __zero_reg__
	cpc	siz_b0, __zero_reg__	; size == 0 ?
	breq	.L_strlcpy_PF_truncated

.L_strlcpy_PF_copy_loop:		; copy src to dst

	subi	siz_b0, lo8(1)
	sbci	siz_b1, hi8(1)		; decrement siz
	breq	1f 			; --> siz chars copied
	LPM_R0_ZPLUS_NEXT src_b2	; get next src char
	st	X+, r0			; copy char
	tst	r0			; end of src string ?
	breq	.L_strlcpy_PF_len	; --> all src chars copied
	rjmp	.L_strlcpy_PF_copy_loop	; next char
1:	st	X, __zero_reg__		; truncate dst string

.L_strlcpy_PF_truncated:		; find Z = end of src string

	LPM_R0_ZPLUS_NEXT src_b2	; get next char from src
	tst	r0			; end of src string ?
	brne	.L_strlcpy_PF_truncated	; next char

.L_strlcpy_PF_len:			; calculate strlen(src)

	sub	ZL, src_b0
	sbc	ZH, src_b1		; Z points past \0
	sbiw	ZL, 1
	X_movw	rWord_b0, ZL
	ret

.L_strlcpy_PF_end:

	.size	_U(strlcpy_PF), .L_strlcpy_PF_end - _U(strlcpy_PF)

#endif /* not __DOXYGEN__ */

#endif /* !defined(__AVR_TINY__) */
