/*
   AVR LIBC
   strlcat()

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


/** \ingroup avr_pmstring
    \fn size_t strlcat_P (char *dst, PGM_P, size_t siz)
    \brief Concatenate two strings.

    The strlcat_P() function is similar to strlcat(), except that the \e src
    string must be located in program space (flash).

    Appends src to string dst of size siz (unlike strncat(), siz is the
    full size of dst, not space left).  At most siz-1 characters
    will be copied.  Always NULL terminates (unless siz <= strlen(dst)).

    \returns The strlcat_P() function returns strlen(src) + MIN(siz,
    strlen(initial dst)).  If retval >= siz, truncation occurred.  */

#if !defined(DOXYGEN)

#include "gasava.inc"
#include "macros.inc"

#define dst_hi		r25
#define dst_lo		r24
#define src_hi		r23
#define src_lo		r22
#define siz_hi		r21
#define siz_lo		r20
#define dlen_hi		r19
#define dlen_lo		r18
#define rWord_hi	r25
#define rWord_lo	r24
#define Z_hi		r31
#define Z_lo		r30
#define X_hi		r27
#define X_lo		r26

	.text
	.global _U(strlcat_P)
	.type	 _U(strlcat_P),@function

_U(strlcat_P):
	LOAD_X	(dst_lo, dst_hi)	; X = dst
	LOAD_Z	(src_lo, src_hi)	; Z = src

.strlcat_P_dlen:			; Find end of dst string
	ld	__tmp_reg__, X+		; get next char from dst
	cp	siz_lo, __zero_reg__	;  and calc dlen = len of dst
	cpc	siz_hi, __zero_reg__	; size == 0 ?
	breq	 1f			; --> done
	tst	__tmp_reg__		; end of dst ?
	breq	 1f			; --> done
	subi	siz_lo, lo8(-(-1))
	sbci	siz_hi, hi8(-(-1))	; siz--
	rjmp	.strlcat_P_dlen		; --> next char
1:	sbiw	X_lo, 1			; undo post increment
#if __AVR_ENHANCED__
	movw	dlen_lo, X_lo
#else
	mov	dlen_lo, X_lo
	mov	dlen_hi, X_hi
#endif
	sub	dlen_lo, dst_lo
	sbc	dlen_hi, dst_hi		; dlen = X - dst
	cp	siz_lo, __zero_reg__
	cpc	siz_hi, __zero_reg__	; size == 0 ?
	breq	.strlcat_P_slen		; --> done
	subi	siz_lo, lo8(-(-1))
	sbci	siz_hi, hi8(-(-1))	; siz--

.strlcat_P_concat:			; Concatenate
	LPM_R0_ZP			; get next char from src
	cp	siz_lo, __zero_reg__
	cpc	siz_hi, __zero_reg__	; size == 0 ?
	breq	1f			; --> done
	tst	__tmp_reg__		; end of src ?
	breq	1f			; --> done
	st	X+, __tmp_reg__		; store in dest
	subi	siz_lo, lo8(-(-1))
	sbci	siz_hi, hi8(-(-1))	; siz--
	rjmp	.strlcat_P_concat		; --> next char
1:	st	X, __zero_reg__		; *X = '\0'
	sbiw	Z_lo, 1			; undo post increment

.strlcat_P_slen:
	LPM_R0_ZP			; get next char from src
	tst	__tmp_reg__		; end of src ?
	brne	.strlcat_P_slen		; --> next char
	sbiw	Z_lo, 1			; undo post increment
#if __AVR_ENHANCED__
	movw	rWord_lo, dlen_lo
#else
	mov	rWord_lo, dlen_lo
	mov	rWord_hi, dlen_hi
#endif
	add	rWord_lo, Z_lo
	adc	rWord_hi, Z_hi
	sub	rWord_lo, src_lo
	sbc	rWord_hi, src_hi	; return(dlen + (Z - src))
	ret

.strlcat_P_end:
.size	_U(strlcat_P), .strlcat_P_end - _U(strlcat)

#endif /* not DOXYGEN */
