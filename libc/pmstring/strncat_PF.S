/* Copyright (c) 2006, Carlos Lamas

   based on libc/pmstring/strncat_P.S which is
   Copyright (c) 2003, Reiner Patommel

   based on strncat by Marek Michalkiewicz

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
    \fn char *strncat_PF (char *dst, uint_farptr_t src, size_t n)
    \brief Concatenate two strings

    The strncat_PF() function is similar to strncat(), except that the \e src
    string must be located in program space (flash) and is addressed using a
    far pointer

    \param dst A pointer to the destination string in SRAM
    \param src A far pointer to the source string in Flash
    \param n The maximum number of bytes to append

    \returns The strncat_PF() function returns a pointer to the resulting
    string \e dst. The contents of RAMPZ SFR are undefined when the function
    returns */

#if !defined(__DOXYGEN__)

	.text
	.global	_U(strncat_PF)
	.type	_U(strncat_PF), @function

_U(strncat_PF):

	X_movw	ZL, src_b0
	LPM_R0_ZPLUS_INIT src_b2
	X_movw	XL, dest_b0

.L_strncat_PF_skip:

	ld	r0, X+
	tst	r0
	brne	.L_strncat_PF_skip
	sbiw	XL, 1		; undo post-increment (point the the NUL)

.L_strncat_PF_loop:

	subi	len_b0, lo8(1)
	sbci	len_b1, hi8(1)
	brcs	.L_strncat_PF_done
	LPM_R0_ZPLUS_NEXT src_b2
	tst	r0
	st	X+, r0
	brne	.L_strncat_PF_loop

; return dest (unchanged)

	ret

.L_strncat_PF_done:

	st	X, __zero_reg__

; return dest (unchanged)

	ret

.L_strncat_PF_end:

	.size	_U(strncat_PF), .L_strncat_PF_end - _U(strncat_PF)

#endif /* not __DOXYGEN__ */

#endif /* !defined(__AVR_TINY__) */
