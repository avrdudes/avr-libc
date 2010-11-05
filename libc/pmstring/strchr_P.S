/* Copyright (c) 2002, 2007 Marek Michalkiewicz
   Copyright (c) 2007  Dmitry Xmelkov
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
    \fn PGM_P strchr_P(PGM_P s, int val)
    \brief Locate character in program space string.

    The strchr_P() function locates the first occurrence of \p val
    (converted to a char) in the string pointed to by \p s in program
    space. The terminating null character is considered to be part of
    the string.
    
    The strchr_P() function is similar to strchr() except that \p s is
    pointer to a string in program space.

    \returns The strchr_P() function returns a pointer to the matched
    character or \c NULL if the character is not found. */


#if !defined(__AVR_TINY__)

#if !defined(__DOXYGEN__)

#include "macros.inc"

#define str_hi	r25
#define str_lo	r24
#define val_lo	r22

#define ret_hi	r25
#define ret_lo	r24

	ASSEMBLY_CLIB_SECTION
	.global	_U(strchr_P)
	.type	_U(strchr_P), @function
_U(strchr_P):
	X_movw	ZL, str_lo
1:
	X_lpm	r0, Z+
	cp	r0, val_lo
	breq	2f
	tst	r0
	brne	1b
  ; not found, return NULL pointer
	X_movw	ret_lo, r0
	ret
2:
	sbiw	ZL, 1		; undo post-increment
	X_movw	ret_lo, ZL
	ret

	.size	_U(strchr_P), . - _U(strchr_P)

#endif /* not __DOXYGEN__ */

#endif /* !defined(__AVR_TINY__) */
