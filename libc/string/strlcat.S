/*
   AVR LIBC
   strlcat()

   Copyright (c) 2003, 2007 Eric B. Weddington, R. Patommel
   Copyright (c) 2009  Dmitry Xmelkov
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

/** \ingroup avr_string
    \fn size_t strlcat (char *dst, const char *src, size_t siz)
    \brief Concatenate two strings.

    Appends \p src to string \p dst of size \p siz (unlike strncat(),
    \p siz is the full size of \p dst, not space left).  At most \p siz-1
    characters will be copied.  Always NULL terminates (unless \p siz <=
    \p strlen(dst)).

    \returns The strlcat() function returns strlen(src) + MIN(siz,
    strlen(initial dst)).  If retval >= siz, truncation occurred.  */

#if !defined(__AVR_TINY__)

#if !defined(__DOXYGEN__)

#include "asmdef.h"

/*  size_t strlcat (char *dst, const char *src, size_t siz)
    {
	char *d = dst;
	const char *s = src;

	do {
	    if (--siz == ~0u)
		goto Len;			// siz <= strlen(dst)
	} while (*d++);
	d -= 1;

	goto m;
	do {
	    if (!(*d++ = *s++))
		return (d - dst - 1);		// normal end
	  m: ;
	} while (--siz != ~0u);
	*d = 0;

      Len:
        return (d - dst + strlen (s));
    }
 */

#define dst_lo	r24
#define dst_hi	r25
#define src_lo	r22
#define src_hi	r23
#define siz_lo	r20
#define siz_hi	r21
#define ret_lo	r24

ENTRY strlcat
	X_movw	XL, dst_lo		; X = dst
	X_movw	ZL, src_lo		; Z = src

  ; find end of dst: X := dst + strlen(dsr)
1:	subi	siz_lo, lo8(1)
	sbci	siz_hi, hi8(1)
	brlo	.Len			; siz <= strlen(dst)
	ld	__tmp_reg__, X+
	tst	__tmp_reg__
	brne	1b
	sbiw	XL, 1
	rjmp	3f

  ; copy loop
2:	ld	__tmp_reg__, Z+
	st	X+, __tmp_reg__
	tst	__tmp_reg__
	breq	.Ldd
3:	subi	siz_lo, lo8(1)
	sbci	siz_hi, hi8(1)
	brsh	2b
	st	X, __zero_reg__

  ; return (d - dst + strlen(s))
	X_movw	src_lo, ZL		; update for strlen(s) calculation
.Len:	ld	__tmp_reg__, Z+		; find end of src
	tst	__tmp_reg__
	brne	.Len
	sub	ZL, src_lo		; Z := strlen(s) + 1
	sbc	ZH, src_hi
	add	XL, ZL			; d += strlen(s) + 1
	adc	XH, ZH
.Ldd:	sec				; d -= dst + 1
	sbc	XL, dst_lo
	sbc	XH, dst_hi
	X_movw	ret_lo, XL		; return value
	ret

ENDFUNC
#endif /* not __DOXYGEN__ */

#endif /* not __AVR_TINY__ */
