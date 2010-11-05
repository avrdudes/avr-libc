/* Copyright (c) 2002, 2005, 2006, 2007 Marek Michalkiewicz
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
    \fn int strncmp_P(const char *s1, PGM_P s2, size_t n)

    The strncmp_P() function is similar to strcmp_P() except it only compares
    the first (at most) n characters of s1 and s2.

    \returns The strncmp_P() function returns an integer less than, equal to,
    or greater than zero if s1 (or the first n bytes thereof) is found,
    respectively, to be less than, to match, or be greater than s2.  */

#if !defined(__AVR_TINY__)

#if !defined(__DOXYGEN__)

#include "macros.inc"

#define s1_hi r25
#define s1_lo r24
#define s2_hi r23
#define s2_lo r22
#define len_hi r21
#define len_lo r20

#define ret_hi r25
#define ret_lo r24

	ASSEMBLY_CLIB_SECTION
	.global	_U(strncmp_P)
	.type	_U(strncmp_P), @function
_U(strncmp_P):
	X_movw	ZL, s2_lo
	X_movw	XL, s1_lo
.L_strncmp_P_loop:
	subi	len_lo, lo8(1)
	sbci	len_hi, hi8(1)
	brcs	.L_strncmp_P_equal
	ld	ret_lo, X+
	X_lpm	r0, Z+
	sub	ret_lo, r0
	brne	.L_strncmp_P_done
	tst	r0
	brne	.L_strncmp_P_loop
.L_strncmp_P_equal:
	sub	ret_lo, ret_lo
.L_strncmp_P_done:
; ret_hi = SREG.C ? 0xFF : 0
	sbc	ret_hi, ret_hi
	ret
.L_strncmp_P_end:
	.size	_U(strncmp_P), .L_strncmp_P_end - _U(strncmp_P)

#endif /* not __DOXYGEN__ */

#endif /* !defined(__AVR_TINY__) */
