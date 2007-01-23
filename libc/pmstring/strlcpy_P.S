/*
   AVR LIBC
   strlcpy_P()

   Copyright (c) 2003, 2005, 2006, 2007 Eric B. Weddington
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

/** \file */

/** \ingroup avr_pgmspace
    \fn size_t strlcpy_P (char *dst, PGM_P, size_t siz)
    \brief Copy a string from progmem to RAM.

    Copy src to string dst of size siz.  At most siz-1 characters will be
    copied.  Always NULL terminates (unless siz == 0).

    \returns The strlcpy_P() function returns strlen(src). If retval >= siz,
    truncation occurred.  */

#if !defined(__DOXYGEN__)

#include "macros.inc"

#define dst_hi		r25
#define dst_lo		r24
#define src_hi		r23
#define src_lo		r22
#define siz_hi		r21
#define siz_lo		r20
#define rWord		r24
#define rWord_hi	r25
#define rWord_lo	r24
#define Z_hi		r31
#define Z_lo		r30

	.text
	.global	_U(strlcpy_P)
	.type	_U(strlcpy_P), @function

_U(strlcpy_P):
	X_movw	XL, dst_lo		; X = dst
	X_movw	ZL, src_lo		; Z = src
	cp	siz_lo, __zero_reg__
	cpc	siz_hi, __zero_reg__	; size == 0 ?
	breq	.L_strlcpy_P_truncated

.L_strlcpy_P_copy_loop:			; copy src to dst
	subi	siz_lo, lo8(-(-1))
	sbci	siz_hi, hi8(-(-1))	; decrement siz
	breq	1f 			; --> siz chars copied
	X_lpm	r0, Z+			; get next src char
	st	X+, r0			; copy char
	tst	r0			; end of src string ?
	breq	.L_strlcpy_P_len	; --> all src chars copied
	rjmp	.L_strlcpy_P_copy_loop	; next char
1:	st	X, __zero_reg__		; truncate dst string

.L_strlcpy_P_truncated:			; find Z = end of src string
	X_lpm	r0, Z+			; get next char from src
	tst	r0			; end of src string ?
	brne	.L_strlcpy_P_truncated	; next char

.L_strlcpy_P_len:			; calculate strlen(src)
	sub	Z_lo, src_lo
	sbc	Z_hi, src_hi		; Z points past \0
	sbiw	Z_lo, 1
	X_movw	rWord, Z_lo
	ret

.L_strlcpy_P_end:
	.size	_U(strlcpy_P), .L_strlcpy_P_end - _U(strlcpy_P)

#endif /* not __DOXYGEN__ */
