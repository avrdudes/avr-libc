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
    \fn void *memset(void *dest, int val, size_t len)
    \brief Fill memory with a constant byte.

    The memset() function fills the first len bytes of the memory area pointed
    to by dest with the constant byte val.

    \returns The memset() function returns a pointer to the memory area dest. */

#if !defined(__DOXYGEN__)

#include "macros.inc"

#define dest_hi r25
#define dest_lo r24
; #define val_hi r23
#define val_lo r22
#define len_hi r21
#define len_lo r20

	ASSEMBLY_CLIB_SECTION
	.global	_U(memset)
	.type	_U(memset), @function
_U(memset):
	X_movw	XL, dest_lo
#if OPTIMIZE_SPEED
; 11 words, (12 + len * 4 - (len & 1)) cycles
	sbrs	len_lo, 0
	rjmp	.L_memset_start
	rjmp	.L_memset_odd
.L_memset_loop:
	st	X+, val_lo
.L_memset_odd:
	st	X+, val_lo
.L_memset_start:
	subi	len_lo, lo8(2)
	sbci	len_hi, hi8(2)
#else
; 8 words, (11 + len * 6) cycles
	rjmp	.L_memset_start
.L_memset_loop:
	st	X+, val_lo
.L_memset_start:
	subi	len_lo, lo8(1)
	sbci	len_hi, hi8(1)
#endif
	brcc	.L_memset_loop
; return dest (unchanged)
	ret
.L_memset_end:
	.size	_U(memset), .L_memset_end - _U(memset)

#endif /* not __DOXYGEN__ */
