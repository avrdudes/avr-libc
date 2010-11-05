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
    \fn char *strncat(char *dest, const char *src, size_t len)
    \brief Concatenate two strings.

    The strncat() function is similar to strcat(), except that only the first
    n characters of src are appended to dest.

    \returns The strncat() function returns a pointer to the resulting string
    dest.  */

#if !defined(__AVR_TINY__)

#if !defined(__DOXYGEN__)

#include "macros.inc"

#define dest_hi r25
#define dest_lo r24
#define src_hi r23
#define src_lo r22
#define len_hi r21
#define len_lo r20

	ASSEMBLY_CLIB_SECTION
	.global	_U(strncat)
	.type	_U(strncat), @function
_U(strncat):
	X_movw	ZL, src_lo
	X_movw	XL, dest_lo
.L_strncat_skip:
	ld	__tmp_reg__, X+
	tst	__tmp_reg__
	brne	.L_strncat_skip
	sbiw	XL, 1		; undo post-increment (point the the NUL)
.L_strncat_loop:
	subi	len_lo, lo8(1)
	sbci	len_hi, hi8(1)
	brcs	.L_strncat_done
	ld	__tmp_reg__, Z+
	tst	__tmp_reg__
	st	X+, __tmp_reg__
	brne	.L_strncat_loop
; return dest (unchanged)
	ret
.L_strncat_done:
	st	X, __zero_reg__
; return dest (unchanged)
	ret
.L_strncat_end:
	.size	_U(strncat), .L_strncat_end - _U(strncat)

#endif /* not __DOXYGEN__ */

#endif /* !defined(__AVR_TINY__) */
