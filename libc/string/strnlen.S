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
#define len_hi r23
#define len_lo r22

/** \ingroup avr_string
    \fn size_t strnlen(const char *src, size_t len)
    \brief Determine the length of a fixed-size string.

    The strnlen function returns the number of characters in the string
    pointed to by s, not including the terminating '\0' character, but at most
    maxlen. In doing this, strnlen looks only at the first maxlen characters
    at s and never beyond s+maxlen.

    \returns The strnlen function returns strlen(s), if that is less than
    maxlen, or maxlen if there is no '\0' character among the first maxlen
    characters pointed to by s. */

	.text
	.global	_U(strnlen)
	.type	_U(strnlen), @function
_U(strnlen):
	LOAD_Z(src_lo, src_hi)
.strnlen_loop:
	subi	len_lo, lo8(1)
	sbci	len_hi, hi8(1)
	ld	__tmp_reg__, Z+
	cpse	__tmp_reg__, __zero_reg__
	brcc	.strnlen_loop
; Z points one character past the terminating NUL
; return Z - 1 - src = (-1 - src) + Z = ~src + Z
	com	src_lo
	com	src_hi
	add	src_lo, ZL
	adc	src_hi, ZH
	ret
.strnlen_end:
	.size	_U(strnlen), .strnlen_end - _U(strnlen)

