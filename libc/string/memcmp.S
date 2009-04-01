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
    \fn int memcmp(const void *s1, const void *s2, size_t len)
    \brief Compare memory areas
    
    The memcmp() function compares the first len bytes of the memory areas s1
    and s2. The comparision is performed using unsigned char operations.
    
    \returns The memcmp() function returns an integer less than, equal to, or
    greater than zero if the first len bytes of s1 is found, respectively, to be
    less than, to match, or be greater than the first len bytes of s2.

    \note Be sure to store the result in a 16 bit variable since you may get
    incorrect results if you use an unsigned char or char due to truncation.

    \warning This function is not -mint8 compatible, although if you only care
    about testing for equality, this function should be safe to use. */

#if !defined(__DOXYGEN__)

#include "macros.inc"

#define s1_hi r25
#define s1_lo r24
#define s2_hi r23
#define s2_lo r22
#define len_hi r21
#define len_lo r20

#define ret_hi r25
#define ret_lo r24

	ASSEMBLY_CLIB_SECTION
	.global	_U(memcmp)
	.type	_U(memcmp), @function
_U(memcmp):
	X_movw	ZL, s2_lo
	X_movw  XL, s1_lo
	rjmp	.L_memcmp_start
.L_memcmp_loop:
	ld	ret_lo, X+
	ld	__tmp_reg__, Z+
	sub	ret_lo, __tmp_reg__
	brne	.L_memcmp_done
.L_memcmp_start:
	subi	len_lo, lo8(1)
	sbci	len_hi, hi8(1)
	brcc	.L_memcmp_loop
; strings are equal, so clear both ret_lo and carry
	sub	ret_lo, ret_lo
.L_memcmp_done:
; ret_hi = SREG.C ? 0xFF : 0
	sbc	ret_hi, ret_hi
	ret
.L_memcmp_end:
	.size	_U(memcmp), .L_memcmp_end - _U(memcmp)

#endif /* not __DOXYGEN__ */
