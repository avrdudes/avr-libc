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

/** \ingroup avr_string
    \fn char *strchr(const char *src, int val)
    \brief Locate character in string.

    The strchr() function returns a pointer to the first occurrence of
    the character \p val in the string \p src.

    Here "character" means "byte" - these functions do not work with
    wide or multi-byte characters.

    \returns The strchr() function returns a pointer to the matched
    character or \c NULL if the character is not found. */

#if !defined(__AVR_TINY__)

#if !defined(__DOXYGEN__)

#include "macros.inc"

#define src_hi r25
#define src_lo r24
; #define val_hi r23
#define val_lo r22

#define ret_hi r25
#define ret_lo r24

	ASSEMBLY_CLIB_SECTION
	.global	_U(strchr)
	.type	_U(strchr), @function
_U(strchr):
	X_movw	ZL, src_lo
.L_strchr_loop:
	ld	ret_lo, Z+
	cp	ret_lo, val_lo
	breq	.L_strchr_found
	tst	ret_lo
	brne	.L_strchr_loop
; not found, return NULL pointer
	clr	ret_hi
	ret
.L_strchr_found:
	sbiw	ZL, 1		; undo post-increment
	X_movw	ret_lo, ZL
	ret
.L_strchr_end:
	.size	_U(strchr), .L_strchr_end - _U(strchr)

#endif /* not __DOXYGEN__ */

#endif /* !defined(__AVR_TINY__) */
