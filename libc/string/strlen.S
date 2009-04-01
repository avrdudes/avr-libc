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
    \fn size_t strlen(const char *src)
    \brief Calculate the length of a string.

    The strlen() function calculates the length of the string src, not
    including the terminating '\\0' character.

    \returns The strlen() function returns the number of characters in
    src.  */

#if !defined(__DOXYGEN__)

#include "macros.inc"

#define src_hi r25
#define src_lo r24

; 10 words, (14 + strlen(src) * 5) cycles

	ASSEMBLY_CLIB_SECTION
	.global	_U(strlen)
	.type	_U(strlen), @function
_U(strlen):
	X_movw	ZL, src_lo
.L_strlen_loop:
	ld	__tmp_reg__, Z+
	tst	__tmp_reg__
	brne	.L_strlen_loop
; Z points one character past the terminating NUL
; return Z - 1 - src = (-1 - src) + Z = ~src + Z
	com	src_lo
	com	src_hi
	add	src_lo, ZL
	adc	src_hi, ZH
	ret
.L_strlen_end:
	.size	_U(strlen), .L_strlen_end - _U(strlen)

#endif /* not __DOXYGEN__ */
