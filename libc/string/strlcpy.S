/*
   AVR LIBC
   strlcpy()

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
    \fn size_t strlcpy (char *dst, const char *src, size_t siz)
    \brief Copy a string.

    Copy \p src to string \p dst of size \p siz.  At most \p siz-1
    characters will be copied.  Always NULL terminates (unless \p siz == 0).

    \returns The strlcpy() function returns strlen(src). If retval >= siz,
    truncation occurred.  */


#if !defined(__AVR_TINY__)

#if !defined(__DOXYGEN__)

#include "asmdef.h"

#define dst_lo		r24
#define src_hi		r23
#define src_lo		r22
#define siz_hi		r21
#define siz_lo		r20
#define rslt_lo		r24


ENTRY strlcpy
	X_movw	XL, dst_lo		; X = dst
	X_movw	ZL, src_lo		; Z = src

  ; copy loop
1:	subi	siz_lo, lo8(1)
	sbci	siz_hi, hi8(1)
	brcs	4f			; is possible with siz == 0
	breq	3f			; --> siz chars copied
	ld	__tmp_reg__, Z+
	st	X+, __tmp_reg__
	tst	__tmp_reg__
	brne	1b

  ; calculate result (Z - 1 - src) and return
2:	sub	ZL, src_lo
	sbc	ZH, src_hi
	sbiw	ZL, 1
	X_movw	rslt_lo, ZL
	ret

  ; terminate dst
3:	st	X, __zero_reg__

  ; find src end
4:	ld	__tmp_reg__, Z+
	tst	__tmp_reg__
	brne	4b
	rjmp	2b

ENDFUNC

#endif /* not __DOXYGEN__ */

#endif /* !defined(__AVR_TINY__) */
