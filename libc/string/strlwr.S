/* Copyright (c) 2002, 2007 Reiner Patommel
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

/*
   strlwr.S
   convert a string to lower case

   Contributors:
     Created by Reiner Patommel
*/

/** \file */

/** \ingroup avr_string
    \fn char *strlwr(char *s)
    \brief Convert a string to lower case.

    The strlwr() function will convert a string to lower case. Only the upper
    case alphabetic characters [A .. Z] are converted.  Non-alphabetic
    characters will not be changed.

    \returns The strlwr() function returns a pointer to the converted
    string. */

#if !defined(__DOXYGEN__)

#include "macros.inc"

#define str_hi r25
#define str_lo r24
#define temp   r22

	ASSEMBLY_CLIB_SECTION
	.global	_U(strlwr)
	.type	_U(strlwr), @function

_U(strlwr):
	X_movw	XL, str_lo

1:	ld	temp, X
	subi	temp, 'A'
	cpi	temp, 'Z'-'A'+1
	brlo	2f		; if tepm is A..Z, then temp += 'a'-'A'
	subi	temp, 'a'-'A'	; else restore temp
2:	subi	temp, -'a'
	st	X+, temp
	brne	1b		; Z for temp
	ret

	.size	_U(strlwr), . - _U(strlwr)

#endif /* not __DOXYGEN__ */
