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

#define dest_hi r25
#define dest_lo r24
#define src_hi r23
#define src_lo r22
; #define val_hi r21
#define val_lo r20
#define len_hi r19
#define len_lo r18

#define ret_hi r25
#define ret_lo r24

/** \ingroup avr_string
	\fn void *memccpy(void *dest, const void *src, int val, size_t len)
    \brief Copy memory area.

	The memccpy() function copies no more than n bytes from memory area src to
	memory area dest, stopping when the character c is found.

	\returns The memccpy() function returns a pointer to the next character in
	dest after c, or NULL if c was not found in the first n characters of src.  */

	.text
	.global	_U(memccpy)
	.type	_U(memccpy), @function
_U(memccpy):
	LOAD_Z(src_lo, src_hi)
	LOAD_X(dest_lo, dest_hi)
.memccpy_loop:
	subi	len_lo, lo8(1)
	sbci	len_hi, hi8(1)
	brcs	.memccpy_notfound
	ld	__tmp_reg__, Z+
	st	X+, __tmp_reg__
	cp	__tmp_reg__, val_lo
	brne	.memccpy_loop
	mov	ret_lo, XL	; XXX use movw if available
	mov	ret_hi, XH
	ret
.memccpy_notfound:
	clr	ret_lo
	clr	ret_hi
	ret
.memccpy_end:
	.size	_U(memccpy), .memccpy_end - _U(memccpy)

