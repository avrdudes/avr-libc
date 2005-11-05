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
   strupr.S
   Convert a string to upper case

   Contributors:
     Created by Reiner Patommel
*/

#include "macros.inc"

#define str_hi r25
#define str_lo r24
#define temp   r21

/** \ingroup avr_string
    \fn char *strupr(char *string)
    \brief Convert a string to upper case.

    The strupr() function will convert a string to upper case. Only the lower
    case alphabetic characters [a .. z] are converted.  Non-alphabetic
    characters will not be changed.

    \returns The strupr() function returns a pointer to the converted
    string.  The pointer is the same as that passed in since the operation is
    perform in place. */

#if !defined(__DOXYGEN__)

	.text
	.global	_U(strupr)
	.type	_U(strupr), @function

_U(strupr):
	X_movw	XL, str_lo
.L_strupr_loop:
	LD	temp, X		; get 1st character
	TST	temp		; is it end of string
	BREQ	.L_strupr_done
	ANDI	temp, 0xDF	; make upper case
	CPI	temp, 'A'	; test on [a .. z]
	BRLT	.L_strupr_next
	CPI	temp, 'Z'+1
	BRGE	.L_strupr_next
	ST	X, temp		; ok, it is a char --> store it
.L_strupr_next:
	ADIW	XL, 1		; point to next character
	RJMP	.L_strupr_loop
.L_strupr_done:
	RET
.L_strupr_end:
	.size	_U(strupr), .L_strupr_end - _U(strupr)

#endif /* not __DOXYGEN__ */
