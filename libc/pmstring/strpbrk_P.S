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
/** \ingroup avr_pgmspace
    \fn char *strpbrk_P(const char *s, PGM_P accept)
    
    The strpbrk_P() function locates the first occurrence in the string
    \p s of any of the characters in the flash string \p accept. This
    function is similar to strpbrk() except that \p accept is a pointer
    to a string in program space.

    \return  The strpbrk_P() function returns a pointer to the character
    in \p s that matches one of the characters in \p accept, or \c NULL
    if no such character is found. The terminating zero is not considered
    as a part of string: if one or both args are empty, the result will
    \c NULL.	*/


#if !defined(__AVR_TINY__)

#ifndef	__DOXYGEN__

#include "macros.inc"

#define str_lo	r24
#define acc_lo	r22

#define ret_lo	r24
#define ret_hi	r25

/* This realization is compact, but is not very fast: an accept string
   is not cashed.	*/

	ASSEMBLY_CLIB_SECTION
	.global _U(strpbrk_P)
	.type   _U(strpbrk_P), @function

_U(strpbrk_P):
	X_movw	XL, str_lo
	clr	ret_hi		; a trick to save 1 word
  ; get next symbol from s[]
1:	ld	ret_lo, X+	; *s++
	tst	ret_lo
	breq	3f
  ; check an occurance
	X_movw	ZL, acc_lo
2:	X_lpm	r0, Z+
	cp	r0, ret_lo
	cpse	r0, __zero_reg__
	brne	2b
	brne	1b		; branch if end of accept[] is reached
  ; OK, is found
	sbiw	XL, 1
	X_movw	ret_lo, XL
3:	ret

	.size _U(strpbrk_P), . - _U(strpbrk_P)
#endif	/* !__DOXYGEN__ */

#endif /* !defined(__AVR_TINY__) */
