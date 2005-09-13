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

#define s1_hi r25
#define s1_lo r24
#define s2_hi r23
#define s2_lo r22

#define ret_hi r25
#define ret_lo r24

/** \ingroup avr_string
    \fn int strcmp(const char *s1, const char *s2)
    \brief Compare two strings.

    The strcmp() function compares the two strings s1 and s2.

    \returns The strcmp() function returns an integer less than, equal to, or
    greater than zero if s1 is found, respectively, to be less than, to match,
    or be greater than s2.  */

#if !defined(__DOXYGEN__)

	.text
	.global	_U(strcmp)
	.type	_U(strcmp), @function
_U(strcmp):
	LOAD_Z(s2_lo, s2_hi)
	LOAD_X(s1_lo, s1_hi)
.strcmp_loop:
	ld	ret_lo, X+
	ld	__tmp_reg__, Z+
	sub	ret_lo, __tmp_reg__
	brne	.strcmp_done
	tst	__tmp_reg__
	brne	.strcmp_loop
.strcmp_done:
; ret_hi = SREG.C ? 0xFF : 0
	sbc	ret_hi, ret_hi
	ret
.strcmp_end:
	.size	_U(strcmp), .strcmp_end - _U(strcmp)

#endif /* not __DOXYGEN__ */
