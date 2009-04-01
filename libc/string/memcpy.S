/* Copyright (c) 2002, 2007 Marek Michalkiewicz
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
/** \ingroup avr_string
    \fn void *memcpy(void *dest, const void *src, size_t len)
    \brief Copy a memory area.

    The memcpy() function copies len bytes from memory area src to memory area
    dest.  The memory areas may not overlap.  Use memmove() if the memory
    areas do overlap.

    \returns The memcpy() function returns a pointer to dest.  */

#if !defined(__DOXYGEN__)

#include "macros.inc"

#define dest_hi r25
#define dest_lo r24
#define src_hi r23
#define src_lo r22
#define len_hi r21
#define len_lo r20

	ASSEMBLY_CLIB_SECTION
	.global	_U(memcpy)
	.type	_U(memcpy), @function
_U(memcpy):
	X_movw	ZL, src_lo
	X_movw	XL, dest_lo
#if OPTIMIZE_SPEED
; 15 words, (14 + len * 6 - (len & 1)) cycles
	sbrs	len_lo, 0
	rjmp	.L_memcpy_start
	rjmp	.L_memcpy_odd
.L_memcpy_loop:
	ld	__tmp_reg__, Z+
	st	X+, __tmp_reg__
.L_memcpy_odd:
	ld	__tmp_reg__, Z+
	st	X+, __tmp_reg__
.L_memcpy_start:
	subi	len_lo, lo8(2)
	sbci	len_hi, hi8(2)
#else
; 11 words, (13 + len * 8) cycles
	rjmp	.L_memcpy_start
.L_memcpy_loop:
	ld	__tmp_reg__, Z+
	st	X+, __tmp_reg__
.L_memcpy_start:
	subi	len_lo, lo8(1)
	sbci	len_hi, hi8(1)
#endif
	brcc	.L_memcpy_loop
; return dest (unchanged)
	ret
.L_memcpy_end:
	.size	_U(memcpy), .L_memcpy_end - _U(memcpy)

#endif /* not __DOXYGEN__ */
