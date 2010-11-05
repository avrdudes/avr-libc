/* Copyright (c) 2006, Carlos Lamas

   based on libc/pmstring/strnlen_P.S which is
   Copyright (c) 2005, Helmut Wallner

   based on libc/pmstring/strnlen.S which is
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

#define src_b3 r25
#define src_b2 r24
#define src_b1 r23
#define src_b0 r22
#define len_b1 r21
#define len_b0 r20

/** \ingroup avr_pgmspace
    \fn size_t strnlen_PF(uint_farptr_t s, size_t len)
    \brief Determine the length of a fixed-size string

    The strnlen_PF() function is similar to strnlen(), except that \e s is a
    far pointer to a string in program space

    \param s A far pointer to the string in Flash
    \param len The maximum number of length to return

    \returns The strnlen_PF function returns strlen_P(\e s), if that is less
    than \e len, or \e len if there is no '\\0' character among the first \e
    len characters pointed to by \e s. The contents of RAMPZ SFR are
    undefined when the function returns */

#if !defined(__DOXYGEN__)

	.text
	.global	_U(strnlen_PF)
	.type	_U(strnlen_PF), @function

_U(strnlen_PF):

	LPM_R0_ZPLUS_INIT src_b2
	X_movw	ZL, src_b0

.L_strnlen_PF_loop:

	LPM_R0_ZPLUS_NEXT src_b2
	subi	len_b0, lo8(1)
	sbci	len_b1, hi8(1)
	cpse	r0, __zero_reg__
	brcc	.L_strnlen_PF_loop

; RAMPZ:Z points one character past the terminating NUL
; return RAMPZ:Z - 1 - src = (-1 - src) + RAMPZ:Z = ~src + RAMPZ:Z

	com	src_b0
	com	src_b1
	add	src_b0, ZL
	adc	src_b1, ZH
	X_movw	src_b2, src_b0		; size_t is 16 bits
	ret

.L_strnlen_PF_end:

	.size	_U(strnlen_PF), .L_strnlen_PF_end - _U(strnlen_PF)

#endif /* not __DOXYGEN__ */

#endif /* !defined(__AVR_TINY__) */
