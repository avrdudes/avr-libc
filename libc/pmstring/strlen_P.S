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
    \fn size_t strlen_P(PGM_P src)

    The strlen_P() function is similar to strlen(), except that src is a
    pointer to a string in program space.

    \returns The strlen() function returns the number of characters in src.
    
    \note strlen_P() is implemented as an inline function in the avr/pgmspace.h
    header file, which will check if the length of the string is a constant
    and known at compile time. If it is not known at compile time, the macro
    will issue a call to __strlen_P() which will then calculate the length
    of the string as normal.
*/

#if !defined(__AVR_TINY__)

#if !defined(__DOXYGEN__)

#include "macros.inc"

#define src_hi r25
#define src_lo r24

; 11 words, (14 + __strlen_P(src) * 8) cycles

	ASSEMBLY_CLIB_SECTION
	.global	_U(__strlen_P)
	.type	_U(__strlen_P), @function
_U(__strlen_P):
	X_movw	ZL, src_lo
.L_strlen_P_loop:
	X_lpm	r0, Z+
	tst	r0
	brne	.L_strlen_P_loop
; return Z - 1 - src = (-1 - src) + Z = ~src + Z
	com	src_lo
	com	src_hi
	add	src_lo, ZL
	adc	src_hi, ZH
	ret
.L_strlen_P_end:
	.size	_U(__strlen_P), .L_strlen_P_end - _U(__strlen_P)

#endif /* not __DOXYGEN__ */

#endif /* !defined(__AVR_TINY__) */
