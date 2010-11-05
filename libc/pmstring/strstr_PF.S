/* Copyright (c) 2006, Carlos Lamas

   based on libc/pmstring/strstr_P.S which is
   Copyright (c) 2005, Werner Boellmann
   Copyright (c) 2002, Philip Soeberg

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

#include "macros.inc"

/** \ingroup avr_pgmspace
    \fn char *strstr_PF (const char *s1, uint_farptr_t s2)
    \brief Locate a substring.

    The strstr_PF() function finds the first occurrence of the substring \c s2
    in the string \c s1.  The terminating '\\0' characters are not
    compared.
    The strstr_PF() function is similar to strstr() except that \c s2 is a
    far pointer to a string in program space.

    \returns The strstr_PF() function returns a pointer to the beginning of the
    substring, or NULL if the substring is not found.
    If \c s2 points to a string of zero length, the function returns \c s1. The
    contents of RAMPZ SFR are undefined when the function returns */

#if !defined(__AVR_TINY__)

#if !defined(__DOXYGEN__)

#define s1_b1 r25
#define s1_b0 r24
#define s2_b3 r23
#define s2_b2 r22
#define s2_b1 r21
#define s2_b0 r20

; first char of str1 (updated in loop)
#define chr1 s2_b3	/* MSB not used */

#define ret_b1 r25
#define ret_b0 r24

	.text
	.global _U(strstr_PF)
	.type _U(strstr_PF), @function

_U(strstr_PF):

	X_movw	ZL, s2_b0
	LPM_R0_ZPLUS_INIT s2_b2
	X_movw	XL, s1_b0
	LPM_R0_ZPLUS_NEXT s2_b2
	tst	r0		; is str2 empty?
	brne	.L_findstart_P
	ret			; return original string (req'd by standard)

.L_findstart_P:

	X_movw	ZL, s2_b0	; reset Z pointer
	LPM_R0_ZPLUS_INIT s2_b2
	LPM_R0_ZPLUS_NEXT s2_b2	; fetch first char

.L_findstart_loop_P:		; Find first char

	ld	chr1, X+
	tst	chr1		; Is str1 @ end?
	breq	.L_no_match_P	; then return
	cp	chr1, r0	; Is chr1 == r0?
	X_movw	ret_b0, XL	; store return value
	brne	.L_findstart_loop_P	; If, then start checking string

.L_stringloop_P:

	LPM_R0_ZPLUS_NEXT s2_b2
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

	clr	ret_b0
	clr	ret_b1
	ret

.L_match_P:
	sbiw	ret_b0, 1
	ret

.L_strstr_end_P:

	.size _U(strstr_PF), .L_strstr_end_P - _U(strstr_PF)

#endif /* not __DOXYGEN__ */

#endif /* !defined(__AVR_TINY__) */
