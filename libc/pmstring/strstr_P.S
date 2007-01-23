/* Copyright (c) 2002, Philip Soeberg
   Copyright (c) 2005, 2006, 2007 Werner Boellmann
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
   strstr_P.S
   Search string contained in a string

   Originally contributed by:
     Philip Soeberg <philip@soeberg.net>
     
   Modified for string s2 in program space by: 
     Werner Boellmann <wb@muekno.de>
*/

#include "macros.inc"

/** \file */

/** \ingroup avr_pgmspace
    \fn char *strstr_P(const char *s1, PGM_P s2)
    \brief Locate a substring.

    The strstr_P() function finds the first occurrence of the substring \c s2
    in the string \c s1.  The terminating '\\0' characters are not
    compared.
    The strstr_P() function is similar to strstr() except that \c s2 is pointer
    to a string in program space.

    \returns The strstr_P() function returns a pointer to the beginning of the
    substring, or NULL if the substring is not found.
    If \c s2 points to a string of zero length, the function returns \c s1. */

#if !defined(__DOXYGEN__)

#define s1_hi r25
#define s1_lo r24
#define s2_hi r23
#define s2_lo r22

; first char of str1 (updated in loop)
#define chr1 r18

#define ret_hi r25
#define ret_lo r24

.text
.global _U(strstr_P)
.type _U(strstr_P), @function
_U(strstr_P):

	X_movw	XL, s1_lo
	X_movw	ZL, s2_lo
	X_lpm	r0, Z
	tst	r0		; is str2 empty?
	brne	.L_findstart_P
	ret			; return original string (req'd by standard)

.L_findstart_P:
	X_movw	ZL, s2_lo	; reset Z pointer
	X_lpm	r0, Z+		; fetch first char

.L_findstart_loop_P:		; Find first char
	ld	chr1, X+
	tst	chr1		; Is str1 @ end?
	breq	.L_no_match_P	; then return
	cp	chr1, r0	; Is chr1 == r0?
	X_movw	ret_lo, XL	; store return value
	brne	.L_findstart_loop_P	; If, then start checking string

.L_stringloop_P:
	X_lpm	r0, Z+
	tst	r0
	breq	.L_match_P
	ld	chr1, X
	tst	chr1
	breq	.L_no_match_P
	cp	chr1, r0
	brne	.L_findstart_P
	adiw	XL, 1		; Increment X with one
	rjmp	.L_stringloop_P

.L_no_match_P:
	clr	ret_lo
	clr	ret_hi
	ret

.L_match_P:
	sbiw	ret_lo, 1
	ret


.L_strstr_end_P:
.size _U(strstr_P), .L_strstr_end_P - _U(strstr_P)

#endif /* not __DOXYGEN__ */
