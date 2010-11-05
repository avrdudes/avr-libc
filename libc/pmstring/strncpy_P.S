/* Copyright (c) 2002, 2005, 2006, 2007 Marek Michalkiewicz
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
    \fn char *strncpy_P(char *dest, PGM_P src, size_t n)

    The strncpy_P() function is similar to strcpy_P() except that not more
    than n bytes of src are copied.  Thus, if there is no null byte among the
    first n bytes of src, the result will not be null-terminated.

    In the case where the length of src is less than that of n, the remainder
    of dest will be padded with nulls.

    \returns The strncpy_P() function returns a pointer to the destination
    string dest.  */


#if !defined(__AVR_TINY__)

#if !defined(__DOXYGEN__)

#include "macros.inc"

#define dest_hi r25
#define dest_lo r24
#define src_hi r23
#define src_lo r22
#define len_hi r21
#define len_lo r20

	ASSEMBLY_CLIB_SECTION
	.global	_U(strncpy_P)
	.type	_U(strncpy_P), @function
_U(strncpy_P):
	X_movw	ZL, src_lo
	X_movw	XL, dest_lo
.L_strncpy_P_loop:
	subi	len_lo, lo8(1)
	sbci	len_hi, hi8(1)
	brcs	.L_strncpy_P_done
	X_lpm	r0, Z+
	st	X+, r0
	tst	r0
	brne	.L_strncpy_P_loop
; store null characters up to the end of dest
; as the glibc manual says:
; This behavior is rarely useful, but it is specified by the ISO C standard.
	rjmp	.L_strncpy_P_clr_start
.L_strncpy_P_clr_loop:
	st	X+, __zero_reg__
.L_strncpy_P_clr_start:
	subi	len_lo, lo8(1)
	sbci	len_hi, hi8(1)
	brcc	.L_strncpy_P_clr_loop
.L_strncpy_P_done:
; return dest (unchanged)
	ret
.L_strncpy_P_end:
	.size	_U(strncpy_P), .L_strncpy_P_end - _U(strncpy_P)

#endif /* not __DOXYGEN__ */

#endif /* !defined(__AVR_TINY__) */
