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
    \fn char *strcpy_P(char *dest, PGM_P src)

    The strcpy_P() function is similar to strcpy() except that src is a
    pointer to a string in program space.

    \returns The strcpy_P() function returns a pointer to the destination
    string dest. */


#if !defined(__AVR_TINY__)

#if !defined(__DOXYGEN__)

#include "macros.inc"

#define dest_hi r25
#define dest_lo r24
#define src_hi r23
#define src_lo r22

; 10 words, (17 + strlen_P(src) * 10) cycles

	ASSEMBLY_CLIB_SECTION
	.global	_U(strcpy_P)
	.type	_U(strcpy_P), @function
_U(strcpy_P):
	X_movw	ZL, src_lo
	X_movw	XL, dest_lo
.L_strcpy_P_loop:
	X_lpm	r0, Z+
	st	X+, r0
	tst	r0
	brne	.L_strcpy_P_loop
; return dest (unchanged)
	ret
.L_strcpy_P_end:
	.size	_U(strcpy_P), .L_strcpy_P_end - _U(strcpy_P)

#endif /* not __DOXYGEN__ */

#endif /* !defined(__AVR_TINY__) */
