/* Copyright (c) 2002, 2007 Marek Michalkiewicz
   Copyright (c) 2007  Dmitry Xmelkov
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
    \fn int memcmp_P(const void *s1, PGM_VOID_P s2, size_t len)
    \brief Compare memory areas
    
    The memcmp_P() function compares the first \p len bytes of the memory
    areas \p s1 and flash \p s2. The comparision is performed using unsigned
    char operations.
    
    \returns The memcmp_P() function returns an integer less than, equal
    to, or greater than zero if the first \p len bytes of \p s1 is found,
    respectively, to be less than, to match, or be greater than the first
    \p len bytes of \p s2.	*/

#if !defined(__AVR_TINY__)

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
	.global	_U(memcmp_P)
	.type	_U(memcmp_P), @function
_U(memcmp_P):
	X_movw	ZL, s2_lo
	X_movw  XL, s1_lo
	rjmp	2f

1:	ld	ret_lo, X+
	X_lpm	r0, Z+
	sub	ret_lo, r0
	brne	3f
2:	subi	len_lo, lo8(1)
	sbci	len_hi, hi8(1)
	brsh	1b

	sub	ret_lo, ret_lo
3:	sbc	ret_hi, ret_hi
	ret

	.size	_U(memcmp_P), . - _U(memcmp_P)

#endif /* not __DOXYGEN__ */

#endif /* !defined(__AVR_TINY__) */
