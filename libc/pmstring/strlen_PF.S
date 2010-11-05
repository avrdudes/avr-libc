/* Copyright (c) 2006, Carlos Lamas

   based on libc/pmstring/strlen_P.S which is
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

#define src_b3 r25	/* MSB, ignored */
#define src_b2 r24
#define src_b1 r23
#define src_b0 r22

/** \ingroup avr_pgmspace
    \fn size_t strlen_PF (uint_farptr_t s)
    \brief Obtain the length of a string

    The strlen_PF() function is similar to strlen(), except that \e s is a
    far pointer to a string in program space

    \param s A far pointer to the string in flash

    \returns The strlen_PF() function returns the number of characters in
    \e s. The contents of RAMPZ SFR are undefined when the function returns */

#if !defined(__DOXYGEN__)

	.text
	.global	_U(strlen_PF)
	.type	_U(strlen_PF), @function

_U(strlen_PF):

	LPM_R0_ZPLUS_INIT src_b2
	X_movw	ZL, src_b0

.L_strlen_PF_loop:

	LPM_R0_ZPLUS_NEXT src_b2
	tst	r0
	brne	.L_strlen_PF_loop

; return RAMPZ:Z - 1 - src = (-1 - src) + RAMPZ:Z = ~src + RAMPZ:Z

	com	src_b0
	com	src_b1
	add	src_b0, ZL
	adc	src_b1, ZH
	X_movw	src_b2, src_b0	; size_t is 16 bits
	ret

.L_strlen_PF_end:

	.size	_U(strlen_PF), .L_strlen_PF_end - _U(strlen_PF)

#endif /* not __DOXYGEN__ */

#endif /* !defined(__AVR_TINY__) */
