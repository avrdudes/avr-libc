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
    \fn char *strcat(char *dest, const char *src)
    \brief Concatenate two strings.

    The strcat() function appends the src string to the dest string
    overwriting the '\\0' character at the end of dest, and then adds a
    terminating '\\0' character.  The strings may not overlap, and the dest
    string must have enough space for the result.

    \returns The strcat() function returns a pointer to the resulting string
    dest.  */

#if !defined(__AVR_TINY__)

#if !defined(__DOXYGEN__)

#include "macros.inc"

#define dest_hi r25
#define dest_lo r24
#define src_hi r23
#define src_lo r22

	ASSEMBLY_CLIB_SECTION
	.global	_U(strcat)
	.type	_U(strcat), @function
_U(strcat):
	X_movw	ZL, src_lo
	X_movw	XL, dest_lo
.L_strcat_skip:
	ld	__tmp_reg__, X+
	tst	__tmp_reg__
	brne	.L_strcat_skip
	sbiw	XL, 1		; undo post-increment
.L_strcat_loop:
	ld	__tmp_reg__, Z+
	st	X+, __tmp_reg__
	tst	__tmp_reg__
	brne	.L_strcat_loop
; return dest (unchanged)
	ret
.L_strcat_end:
	.size	_U(strcat), .L_strcat_end - _U(strcat)

#endif /* not __DOXYGEN__ */

#endif /* !defined(__AVR_TINY__) */
