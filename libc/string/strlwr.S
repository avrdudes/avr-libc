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

/* $Id$ */

/*
   strlwr.S
   convert a string to lower case

   Contributors:
     Created by Reiner Patommel
*/

#include "macros.inc"

#define str_hi r25
#define str_lo r24
#define temp   r21

/** \ingroup avr_string
    \fn char *strlwr(char *string)
    \brief Convert a string to lower case.

    The strlwr() function will convert a string to lower case. Only the upper
    case alphabetic characters [A .. Z] are converted.  Non-alphabetic
    characters will not be changed.

    \returns The strlwr() function returns a pointer to the converted
    string. */

#if !defined(__DOXYGEN__)

	.text
	.global	_U(strlwr)
	.type	_U(strlwr), @function

_U(strlwr):
	X_movw	XL, str_lo
.L_strlwr_loop:
	LD	temp, X		; get 1st character
	TST	temp		; is it end of string
	BREQ	.L_strlwr_done
	ORI	temp, 0x20	; make lower case
	CPI	temp, 'a'	; test on [a .. z]
	BRLT	.L_strlwr_next
	CPI	temp, 'z'+1
	BRGE	.L_strlwr_next
	ST	X, temp		; ok, it is a char --> store it
.L_strlwr_next:
	ADIW	XL, 1		; point to next character
	RJMP	.L_strlwr_loop
.L_strlwr_done:
	RET
.L_strlwr_end:
	.size	_U(strlwr), .L_strlwr_end - _U(strlwr)

#endif /* not __DOXYGEN__ */
