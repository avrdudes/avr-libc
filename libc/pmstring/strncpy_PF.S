/* Copyright (c) 2006, Carlos Lamas

   based on libc/pmstring/strncpy_P.S which is
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

#define dest_b1 r25
#define dest_b0 r24
#define src_b3 r23
#define src_b2 r22
#define src_b1 r21
#define src_b0 r20
#define len_b1 r19
#define len_b0 r18


/** \ingroup avr_pgmspace
    \fn char *strncpy_PF (char *dst, uint_farptr_t src, size_t n)
	\brief Duplicate a string until a limited length

    The strncpy_PF() function is similar to strcpy_PF() except that not more
    than \e n bytes of \e src are copied.  Thus, if there is no null byte among
    the first \e n bytes of \e src, the result will not be null-terminated

    In the case where the length of \e src is less than that of \e n, the
    remainder of \e dst will be padded with nulls

    \param dst A pointer to the destination string in SRAM
    \param src A far pointer to the source string in Flash
    \param n The maximum number of bytes to copy

    \returns The strncpy_PF() function returns a pointer to the destination
    string \e dst. The contents of RAMPZ SFR are undefined when the function
    returns */

#if !defined(__DOXYGEN__)

	.text
	.global	_U(strncpy_PF)
	.type	_U(strncpy_PF), @function

_U(strncpy_PF):

	X_movw	ZL, src_b0
	LPM_R0_ZPLUS_INIT src_b2
	X_movw	XL, dest_b0

.L_strncpy_PF_loop:

	subi	len_b0, lo8(1)
	sbci	len_b1, hi8(1)
	brcs	.L_strncpy_PF_done
	LPM_R0_ZPLUS_NEXT src_b2
	st	X+, r0
	tst	r0
	brne	.L_strncpy_PF_loop

; store null characters up to the end of dest
; as the glibc manual says:
; This behavior is rarely useful, but it is specified by the ISO C standard.

	rjmp	.L_strncpy_PF_clr_start

.L_strncpy_PF_clr_loop:

	st	X+, __zero_reg__

.L_strncpy_PF_clr_start:

	subi	len_b0, lo8(1)
	sbci	len_b1, hi8(1)
	brcc	.L_strncpy_PF_clr_loop

.L_strncpy_PF_done:
; return dest (unchanged)

	ret

.L_strncpy_PF_end:

	.size	_U(strncpy_PF), .L_strncpy_PF_end - _U(strncpy_PF)

#endif /* not __DOXYGEN__ */

#endif /* !defined(__AVR_TINY__) */
