/* Copyright (c) 2007  Dmitry Xmelkov
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

/** \file */

/** \ingroup avr_string
    \fn char *strcasestr(const char *s1, const char *s2)

    The strcasestr() function finds the first occurrence of the
    substring \p s2 in the string \p s1. This is like strstr(), except
    that it ignores case of alphabetic symbols in searching for the
    substring. (Glibc, GNU extension.)

    \return The strcasestr() function returns a pointer to the beginning
    of the substring, or \c NULL if the substring is not found. If \p s2
    points to a string of zero length, the function returns \p s1. */
    
/** \ingroup avr_pgmspace
    \fn char *strcasestr_P(const char *s1, PGM_P s2)
    
    This funtion is similar to strcasestr() except that \p s2 is pointer
    to a string in program space.	*/

#if !defined(__AVR_TINY__)

#if !defined(__DOXYGEN__)

#include "asmdef.h"

#define s1_hi	r25
#define s1_lo	r24
#define s2_hi	r23
#define s2_lo	r22

#define	beg2	r21	/* begin of s2 (cashed): s2[0]		*/
#define ctmp	r20	/* scratch arg of .Lcmp()		*/
#define csvd	r0	/* second arg of .Lcmp(), nochanged	*/

#ifdef	Lprogmem
# define strcasestr	strcasestr_P
# define LOAD		X_lpm		/* may scratch r0	*/
#else
# define LOAD		ld
#endif

ENTRY strcasestr
	X_movw	ZL, s2_lo
	LOAD	beg2, Z+
	tst	beg2		; is str2 empty?
	breq	.L_ret		; return original string (req'd by standard)
	X_movw	s2_lo, ZL	; save: address of second s2 byte

1:	X_movw	XL, s1_lo
	mov	csvd, beg2	; Find first char

2:	ld	ctmp, X+
	tst	ctmp
	breq	.L_nomatch	; end of s1
	rcall	.Lcmp
	brne	2b

	X_movw	s1_lo, XL	; store return value (decrement is needed)

3:	LOAD	csvd, Z+	; compare strings (csvd is r0)
	tst	csvd
	breq	.L_match	; end of s2
  ; Z==0
	ld	ctmp, X+
	cpse	ctmp, __zero_reg__	; now Z==0
	rcall	.Lcmp
  ; (ctmp==0 && Z==0) ||	- end of s1
  ; (ctmp!=0 && Z==0) ||	- chars are not equal
  ; (Z==1)			- chars are equal
	breq	3b

	X_movw	ZL, s2_lo		; restore s2+1
  ; (ctmp==0 && Z==0) ||	- end of s2
  ; (ctmp!=0 && Z==0)		- chars are not equal
	cpse	ctmp, __zero_reg__	; if equal, then tail(s1) is less
	rjmp	1b			;   then strlen(s2)

.L_nomatch:
	ldi	s1_lo, lo8(1)
	ldi	s1_hi, hi8(1)
.L_match:
	sbiw	s1_lo, 1	; restore after post-increment
.L_ret:
	ret

/* Compare 2 bytes ignoring a case of symbols.
   Input:	ctmp, csvd.
   Return:	if (bytes are equal) Z==1, else (Z==0 && ctmp != 0)
   Scratch:	ctmp only.
 */
.if  ('a'-'A' - 0x20) | ('Z'-'A' - 25) | ('z'-'a' - 25)
    .err
.endif
.Lcmp:	eor	ctmp, csvd
	breq	1f		; OK, bytes are equal
	cpi	ctmp, 0x20
	brne	1f		; bytes are different more than alpha case
  ; now caseless comparison
	or	ctmp, csvd		; ctmp = tolower(csvd)
	subi	ctmp, -(255 - 'z')	; shift a..z to 230..255
	subi	ctmp, 255 - ('z' - 'a')
	brlo	1f			; branch, if not an alpha
	sez
1:	ret

ENDFUNC

#endif /* not __DOXYGEN__ */

#endif /* !defined(__AVR_TINY__) */
