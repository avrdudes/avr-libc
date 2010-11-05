/* Copyright (c) 2002, 2007 Marek Michalkiewicz
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
    \fn PGM_P strrchr_P(PGM_P s, int val)
    \brief Locate character in string.

    The strrchr_P() function returns a pointer to the last occurrence of
    the character \p val in the flash string \p s.

    \return The strrchr_P() function returns a pointer to the matched
    character or \c NULL if the character is not found. */


#if !defined(__AVR_TINY__)

#if !defined(__DOXYGEN__)

#include "macros.inc"

#define src_hi	r25
#define src_lo	r24
#define val	r22

#define ret_hi	r25
#define ret_lo	r24

	ASSEMBLY_CLIB_SECTION
	.global	_U(strrchr_P)
	.type	_U(strrchr_P), @function
_U(strrchr_P):
	X_movw  ZL, src_lo
	ldi	ret_lo, lo8(1)		; NULL + 1
	ldi	ret_hi, hi8(1)

1:	X_lpm	r0, Z+
	cp	r0, val
	brne	2f
	X_movw	ret_lo, ZL	; remember this character was here
2:	tst	r0
	brne	1b

	sbiw	ret_lo, 1	; undo post-increment
	ret

	.size	_U(strrchr_P), . - _U(strrchr_P)

#endif /* not __DOXYGEN__ */

#endif /* !defined(__AVR_TINY__) */
