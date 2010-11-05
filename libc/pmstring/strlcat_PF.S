/* Copyright (c) 2006, Carlos Lamas

   based on libc/pmstring/strlcat_P.S which is
   Copyright (c) 2003, Eric B. Weddington, R. Patommel

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
    \fn size_t strlcat_PF (char *dst, uint_farptr_t src, size_t n)
    \brief Concatenate two strings

    The strlcat_PF() function is similar to strlcat(), except that the \e src
    string must be located in program space (flash) and is addressed using
	a far pointer

    Appends src to string dst of size \e n (unlike strncat(), \e n is the
    full size of \e dst, not space left).  At most \e n-1 characters
    will be copied.  Always NULL terminates (unless \e n <= strlen(\e dst))

    \param dst A pointer to the destination string in SRAM
    \param src A far pointer to the source string in Flash
    \param n The total number of bytes allocated to the destination string

    \returns The strlcat_PF() function returns strlen(\e src) + MIN(\e n,
    strlen(initial \e dst)).  If retval >= \e n, truncation occurred. The
    contents of RAMPZ SFR are undefined when the funcion returns */

#if !defined(__AVR_TINY__)

#if !defined(__DOXYGEN__)

#include "macros.inc"

#define dst_b1		r25
#define dst_b0		r24
#define src_b30		r23	/* ignored */
#define src_b20		r22	/* moved to src_b2 in the code */
#define src_b1		r21
#define src_b0		r20
#define siz_b1		r19
#define siz_b0		r18

#define src_b2		r28	/* must be preserved */
#define dlen_b1		src_b30
#define dlen_b0		src_b20
#define rWord_b1	r25
#define rWord_b0	r24

	.text
	.global _U(strlcat_PF)
	.type	_U(strlcat_PF),@function

_U(strlcat_PF):

	push	src_b2
	mov	src_b2, src_b20
	X_movw	XL, dst_b0		; X = dst
	X_movw	ZL, src_b0		; Z = src
	LPM_R0_ZPLUS_INIT src_b2

.L_strlcat_PF_dlen:			; Find end of dst string

	ld	r0, X+			; get next char from dst
	cp	siz_b0, __zero_reg__	; and calc dlen = len of dst
	cpc	siz_b1, __zero_reg__	; size == 0 ?
	breq	 1f			; --> done
	tst	r0			; end of dst ?
	breq	 1f			; --> done
	subi	siz_b0, lo8(1)
	sbci	siz_b1, hi8(1)		; siz--
	rjmp	.L_strlcat_PF_dlen	; --> next char
1:	sbiw	XL, 1			; undo post increment
	X_movw	dlen_b0, XL
	sub	dlen_b0, dst_b0
	sbc	dlen_b1, dst_b1		; dlen = X - dst
	cp	siz_b0, __zero_reg__
	cpc	siz_b1, __zero_reg__	; size == 0 ?
	breq	.L_strlcat_PF_slen	; --> done
	subi	siz_b0, lo8(1)
	sbci	siz_b1, hi8(1)		; siz--

.L_strlcat_PF_concat:			; Concatenate

	LPM_R0_ZPLUS_NEXT src_b2	; get next char from src
	cp	siz_b0, __zero_reg__
	cpc	siz_b1, __zero_reg__	; size == 0 ?
	breq	1f			; --> done
	tst	r0			; end of src ?
	breq	1f			; --> done
	st	X+, r0			; store in dest
	subi	siz_b0, lo8(1)
	sbci	siz_b1, hi8(1)		; siz--
	rjmp	.L_strlcat_PF_concat	; --> next char
1:	st	X, __zero_reg__		; *X = '\0'
	sbiw	ZL, 1			; undo post increment
#ifdef RAMPZ
	in	r0, _SFR_IO_ADDR(RAMPZ)
	sbc	r0, __zero_reg__
	out	_SFR_IO_ADDR(RAMPZ), r0
#endif

.L_strlcat_PF_slen:

	LPM_R0_ZPLUS_NEXT src_b2	; get next char from src
	tst	r0			; end of src ?
	brne	.L_strlcat_PF_slen	; --> next char
	sbiw	ZL, 1			; undo post increment
#ifdef RAMPZ
	in	r0, _SFR_IO_ADDR(RAMPZ)
	sbc	r0, __zero_reg__
	out	_SFR_IO_ADDR(RAMPZ), r0
#endif
	X_movw	rWord_b0, dlen_b0
	add	rWord_b0, ZL
	adc	rWord_b1, ZH
	sub	rWord_b0, src_b0
	sbc	rWord_b1, src_b1	; return(dlen + (Z - src))
	pop	src_b2
	ret

.L_strlcat_PF_end:

	.size	_U(strlcat_PF), .L_strlcat_PF_end - _U(strlcat_PF)

#endif /* not __DOXYGEN__ */

#endif /* !defined(__AVR_TINY__) */
