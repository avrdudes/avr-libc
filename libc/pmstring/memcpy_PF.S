/* Copyright (c) 2006, Carlos Lamas

   based on libc/pmstring/memcpy_P.S which is
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
    \fn void *memcpy_PF (void *dest, uint_farptr_t src, size_t n)
    \brief Copy a memory block from flash to SRAM

    The memcpy_PF() function is similar to memcpy(), except the data
    is copied from the program space and is addressed using a far pointer

	\param dst A pointer to the destination buffer
	\param src A far pointer to the origin of data in flash memory
	\param n The number of bytes to be copied

    \returns The memcpy_PF() function returns a pointer to \e dst. The contents
    of RAMPZ SFR are undefined when the function returns */

#if !defined(__DOXYGEN__)

	.text
	.global	_U(memcpy_PF)
	.type	_U(memcpy_PF), @function

_U(memcpy_PF):

	LPM_R0_ZPLUS_INIT src_b2
	X_movw	ZL, src_b0
	X_movw	XL, dest_b0

#if OPTIMIZE_SPEED

	sbrs	len_b0, 0
	rjmp	.L_memcpy_PF_start
	rjmp	.L_memcpy_PF_odd

.L_memcpy_PF_loop:

	LPM_R0_ZPLUS_NEXT src_b2
	st	X+, r0

.L_memcpy_PF_odd:

	LPM_R0_ZPLUS_NEXT src_b2
	st	X+, r0

.L_memcpy_PF_start:

	subi	len_b0, lo8(2)
	sbci	len_b1, hi8(2)

#else

	rjmp	.L_memcpy_PF_start

.L_memcpy_PF_loop:

	LPM_R0_ZPLUS_NEXT src_b2
	st	X+, r0

.L_memcpy_PF_start:

	subi	len_b0, lo8(1)
	sbci	len_b1, hi8(1)

#endif

	brcc	.L_memcpy_PF_loop

; return dest (unchanged)

	ret

.L_memcpy_PF_end:

	.size	_U(memcpy_PF), .L_memcpy_PF_end - _U(memcpy_PF)

#endif /* not __DOXYGEN__ */

#endif /* !defined(__AVR_TINY__) */
