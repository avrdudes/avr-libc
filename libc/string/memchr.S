/* Copyright (c) 2002, Marek Michalkiewicz
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

#include "macros.inc"

#define src_hi r25
#define src_lo r24
; #define val_hi r23
#define val_lo r22
#define len_hi r21
#define len_lo r20

#define ret_hi r25
#define ret_lo r24

/** \ingroup avr_string
	\fn void *memchr(const void *src, int val, size_t len)
    \brief Scan memory for a character.

    The memchr() function scans the first n bytes of the memory area pointed
    to by s for the character c.  The first byte to match c (interpreted as an
    unsigned character) stops the operation.

    The memrchr() function is like the memchr() function, except that it
    searches backwards from the end of the n bytes pointed to by s instead of
    forwards from the front.

    \returns The memchr() and memrchr() functions return a pointer to the
    matching byte or NULL if the character does not occur in the given memory
    area.  */

	.text
	.global	_U(memchr)
	.type	_U(memchr), @function
_U(memchr):
	LOAD_Z(src_lo, src_hi)
.memchr_loop:
	subi	len_lo, lo8(1)
	sbci	len_hi, hi8(1)
	brcs	.memchr_notfound
	ld	__tmp_reg__, Z+
	cp	__tmp_reg__, val_lo
	brne	.memchr_loop
	sbiw	ZL, 1		; undo post-increment
	mov	ret_lo, ZL	; XXX use movw if available
	mov	ret_hi, ZH
	ret
.memchr_notfound:
	clr	ret_lo
	clr	ret_hi
	ret
.memchr_end:
	.size	_U(memchr), .memchr_end - _U(memchr)

