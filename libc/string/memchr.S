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
	\fn void *memchr(const void *src, int val, size_t len)
    \brief Scan memory for a character.

    The memchr() function scans the first len bytes of the memory area pointed
    to by src for the character val.  The first byte to match val (interpreted
    as an unsigned character) stops the operation.

    \returns The memchr() function returns a pointer to the matching byte or
    NULL if the character does not occur in the given memory area.  */

#if !defined(__AVR_TINY__)

#if !defined(__DOXYGEN__)

#include "macros.inc"

#define src_hi r25
#define src_lo r24
; #define val_hi r23
#define val_lo r22
#define len_hi r21
#define len_lo r20

#define ret_hi r25
#define ret_lo r24

	ASSEMBLY_CLIB_SECTION
	.global	_U(memchr)
	.type	_U(memchr), @function
_U(memchr):
	X_movw	ZL, src_lo
.L_memchr_loop:
	subi	len_lo, lo8(1)
	sbci	len_hi, hi8(1)
	brcs	.L_memchr_notfound
	ld	__tmp_reg__, Z+
	cp	__tmp_reg__, val_lo
	brne	.L_memchr_loop
	sbiw	ZL, 1		; undo post-increment
	X_movw	ret_lo, ZL
	ret
.L_memchr_notfound:
	clr	ret_lo
	clr	ret_hi
	ret
.L_memchr_end:
	.size	_U(memchr), .L_memchr_end - _U(memchr)

#endif /* not __DOXYGEN__ */

#endif /* !defined(__AVR_TINY__) */
