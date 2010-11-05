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
    \fn void *memcpy_P(void *dest, PGM_VOID_P src, size_t n)

    The memcpy_P() function is similar to memcpy(), except the src string
    resides in program space.

    \returns The memcpy_P() function returns a pointer to dest.  */


#if !defined(__AVR_TINY__)

#if !defined(__DOXYGEN__)

#include "macros.inc"

#define dest_hi r25
#define dest_lo r24
#define src_hi r23
#define src_lo r22
#define len_hi r21
#define len_lo r20

	ASSEMBLY_CLIB_SECTION
	.global	_U(memcpy_P)
	.type	_U(memcpy_P), @function
_U(memcpy_P):
	X_movw	ZL, src_lo
	X_movw	XL, dest_lo
#if OPTIMIZE_SPEED
; 17 words, (14 + len * 9 - (len & 1)) cycles
	sbrs	len_lo, 0
	rjmp	.L_memcpy_P_start
	rjmp	.L_memcpy_P_odd
.L_memcpy_P_loop:
	X_lpm	r0, Z+
	st	X+, r0
.L_memcpy_P_odd:
	X_lpm	r0, Z+
	st	X+, r0
.L_memcpy_P_start:
	subi	len_lo, lo8(2)
	sbci	len_hi, hi8(2)
#else
; 12 words, (13 + len * 11) cycles
	rjmp	.L_memcpy_P_start
.L_memcpy_P_loop:
	X_lpm	r0, Z+
	st	X+, r0
.L_memcpy_P_start:
	subi	len_lo, lo8(1)
	sbci	len_hi, hi8(1)
#endif
	brcc	.L_memcpy_P_loop
; return dest (unchanged)
	ret
.L_memcpy_P_end:
	.size	_U(memcpy_P), .L_memcpy_P_end - _U(memcpy_P)

#endif /* not __DOXYGEN__ */

#endif /* !defined(__AVR_TINY__) */
