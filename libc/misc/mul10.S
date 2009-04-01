/* Copyright (c) 2002, 2006, 2007 Marek Michalkiewicz
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

/*
   mul10.S - optimized 16-bit multiply by 10

   Contributors:
     Created by Marek Michalkiewicz <marekm@linux.org.pl>
 */

#if !defined(__DOXYGEN__)

#include "macros.inc"

#define r_hi r25
#define r_lo r24
#define r_tmp2 r23
#define r_tmp_lo r22
#define r_tmp_hi r23

/* 
   r_hi:r_lo *= 10

   Optimized version, without calling __mulhi3 (which is slow for
   non-enhanced core, and not present in libgcc.a for enhanced core).
 */

	ASSEMBLY_CLIB_SECTION
	.global _U(__mulhi_const_10)

_U(__mulhi_const_10):
#if defined(__AVR_HAVE_MUL__)
	ldi r_tmp2,10
	mul r_hi,r_tmp2
	mov r_hi,r0
	mul r_lo,r_tmp2
	mov r_lo,r0
	add r_hi,r1
	clr r1	; __zero_reg__
#else
	X_movw	r_tmp_lo, r_lo 
	add r_lo,r_lo
	adc r_hi,r_hi
	add r_lo,r_lo
	adc r_hi,r_hi
	add	r_lo, r_tmp_lo
	adc	r_hi, r_tmp_hi
	add r_lo,r_lo
	adc r_hi,r_hi
#endif
	ret

#endif /* not __DOXYGEN__ */
