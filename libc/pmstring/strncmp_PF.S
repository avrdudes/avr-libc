/* Copyright (c) 2006, Carlos Lamas

   based on libc/pmstring/strncmp_P.S which is
   Copyright (c) 2002, Marek Michalkiewicz

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

#if !defined(__AVR_TINY__)

#include "macros.inc"

#define s1_b1 r25
#define s1_b0 r24
#define s2_b3 r23
#define s2_b2 r22
#define s2_b1 r21
#define s2_b0 r20
#define len_b1 r19
#define len_b0 r18

#define ret_b1 r25
#define ret_b0 r24

/** \ingroup avr_pgmspace
    \fn int strncmp_PF (const char *s1, uint_farptr_t s2, size_t n)
    \brief Compare two strings with limited length

    The strncmp_PF() function is similar to strcmp_PF() except it only
    compares the first (at most) \e n characters of \e s1 and \e s2

    \param s1 A pointer to the first string in SRAM
    \param s2 A far pointer to the second string in Flash
    \param n The maximum number of bytes to compare

    \returns The strncmp_PF() function returns an integer less than, equal
    to, or greater than zero if \e s1 (or the first \e n bytes thereof) is found,
    respectively, to be less than, to match, or be greater than \e s2. The
    contents of RAMPZ SFR are undefined when the function returns */

#if !defined(__DOXYGEN__)

	.text
	.global	_U(strncmp_PF)
	.type	_U(strncmp_PF), @function

_U(strncmp_PF):

	X_movw	ZL, s2_b0
	LPM_R0_ZPLUS_INIT s2_b2
	X_movw	XL, s1_b0

.L_strncmp_PF_loop:

	subi	len_b0, lo8(1)
	sbci	len_b1, hi8(1)
	brcs	.L_strncmp_PF_equal
	ld	ret_b0, X+
	LPM_R0_ZPLUS_NEXT s2_b2
	sub	ret_b0, r0
	brne	.L_strncmp_PF_done
	tst	r0
	brne	.L_strncmp_PF_loop

.L_strncmp_PF_equal:

	sub	ret_b0, ret_b0

.L_strncmp_PF_done:
; ret_hi = SREG.C ? 0xFF : 0

	sbc	ret_b1, ret_b1
	ret

.L_strncmp_PF_end:

	.size	_U(strncmp_PF), .L_strncmp_PF_end - _U(strncmp_PF)

#endif /* not __DOXYGEN__ */

#endif /* !defined(__AVR_TINY__) */
