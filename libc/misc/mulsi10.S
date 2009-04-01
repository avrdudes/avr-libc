/* Copyright (c) 2002, Reiner Patommel
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
   mulsi10.S - optimized 32-bit multiply by 10

   Contributors:
     Created by Reiner Patommel <rpatop@post4.tele.dk> based on
	 mul10.S by Marek Michalkiewicz <marekm@linux.org.pl>
 */

#if !defined(__DOXYGEN__)

#include "macros.inc"

#define r_hi_hi 		r25
#define r_hi_lo 		r24
#define r_lo_hi 		r23
#define r_lo_lo 		r22

#define r_tmp_hi_hi		r21
#define r_tmp_hi_lo		r20
#define r_tmp_lo_hi		r19
#define r_tmp_lo_lo		r18

/*
   r_hi_hi:r_hi_lo:r_lo_hi:r_lo_lo *= 10

 */

	ASSEMBLY_CLIB_SECTION
	.global _U(__mulsi_const_10)

_U(__mulsi_const_10):
	mov r_tmp_hi_hi, r_hi_hi
	mov r_tmp_hi_lo, r_hi_lo
	mov r_tmp_lo_hi, r_lo_hi
	mov r_tmp_lo_lo, r_lo_lo
	add r_lo_lo, r_lo_lo
	adc	r_lo_hi, r_lo_hi
	adc	r_hi_lo, r_hi_lo
	adc	r_hi_hi, r_hi_hi			; d *= 2
	add r_lo_lo, r_lo_lo
	adc	r_lo_hi, r_lo_hi
	adc	r_hi_lo, r_hi_lo
	adc	r_hi_hi, r_hi_hi			; d *= 4
	add r_lo_lo, r_tmp_lo_lo
	adc	r_lo_hi, r_tmp_lo_hi
	adc	r_hi_lo, r_tmp_hi_lo
	adc	r_hi_hi, r_tmp_hi_hi		; d *= 5
	add r_lo_lo, r_lo_lo
	adc	r_lo_hi, r_lo_hi
	adc	r_hi_lo, r_hi_lo
	adc	r_hi_hi, r_hi_hi			; d *= 10

	ret

#endif /* not __DOXYGEN__ */
