/* Copyright (c) 2002, Philip Soeberg
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

/*
   strstr.S
   Search string contained in a string

   Contributed by:
     Philip Soeberg <philip@soeberg.net>
*/

#include "macros.inc"

#define s1_hi r25
#define s1_lo r24
#define s2_hi r23
#define s2_lo r22

#ifndef DOXYGEN
; first char of str1 (updated in loop)
#define chr1 r18
; first char of str2 (updated in loop)
#define chr2 r20
#endif

#define ret_hi r25
#define ret_lo r24

/** \ingroup avr_string
    \fn char *strstr(const char *s1, const char *s2)
    \brief Locate a substring.

    The strstr() function finds the first occurrence of the substring \c s2
    in the string \c s1.  The terminating `\\0' characters are not
    compared.

    \returns The strstr() function returns a pointer to the beginning of the
    substring, or NULL if the substring is not found.
    If s2 points to a string of zero length, the function returns s1. */

#if !defined(DOXYGEN)

.text
.global _U(strstr)
.type _U(strstr), @function
_U(strstr):

	LOAD_X(s1_lo, s1_hi)
	LOAD_Z(s2_lo, s2_hi)
	ld	chr2, Z+
	tst	chr2		; is str2 empty?
	brne	.L_findstart
	ret			; return original string (req'd by standard)

.L_findstart:
	LOAD_Z(s2_lo, s2_hi)	; reset Z pointer
	ld	chr2, Z+	; fetch first char

.L_findstart_loop:		; Find first char
	ld	chr1, X+
	tst	chr1		; Is str1 @ end?
	breq	.L_no_match	; then return
	cp	chr1, chr2	; Is chr1 == chr2?

	mov	ret_lo, XL	; store return value
	mov	ret_hi, XH

	brne	.L_findstart_loop ; If, then start checking string

.L_stringloop:
	ld	chr2, Z+
	tst	chr2
	breq	.L_match
	ld	chr1, X
	tst	chr1
	breq	.L_no_match
	cp	chr1, chr2
	brne	.L_findstart
	adiw	XL, 1		; Increment X with one
	rjmp	.L_stringloop

.L_no_match:
	clr	ret_lo
	clr	ret_hi
	ret

.L_match:
	sbiw	ret_lo, 1
	ret


.strstr_end:
.size _U(strstr), .strstr_end - _U(strstr)

#endif /* not DOXYGEN */
