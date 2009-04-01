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
    \fn void *memmove(void *dest, const void *src, size_t len)
    \brief Copy memory area.

    The memmove() function copies len bytes from memory area src to memory area
    dest.  The memory areas may overlap.

    \returns The memmove() function returns a pointer to dest.  */

#if !defined(__DOXYGEN__)

#include "macros.inc"

#define dest_hi r25
#define dest_lo r24
#define src_hi r23
#define src_lo r22
#define len_hi r21
#define len_lo r20

	.extern _U(memcpy)
	ASSEMBLY_CLIB_SECTION
	.global	_U(memmove)
	.type	_U(memmove), @function
_U(memmove):
; if src < dest, we have to copy in reverse order
; otherwise memcpy will do the right thing
	cp	src_lo, dest_lo
	cpc	src_hi, dest_hi
	brcc	.L_memmove_fwd
	X_movw	ZL, src_lo
	X_movw	XL, dest_lo
	add	ZL, len_lo
	adc	ZH, len_hi
	add	XL, len_lo
	adc	XH, len_hi
	rjmp	.L_memmove_start
.L_memmove_loop:
	ld	__tmp_reg__, -Z
	st	-X, __tmp_reg__
.L_memmove_start:
	subi	len_lo, lo8(1)
	sbci	len_hi, hi8(1)
	brcc	.L_memmove_loop
; return dest (unchanged)
	ret
.L_memmove_fwd:
	XJMP	_U(memcpy)
.L_memmove_end:
	.size	_U(memmove), .L_memmove_end - _U(memmove)

#endif /* not __DOXYGEN__ */
