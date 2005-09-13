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
   strrev.S
   Reverse a string

   Contributors:
     Created by Reiner Patommel
*/
#include "macros.inc"

#define str_hi r25
#define str_lo r24
#define ltemp  r23
#define rtemp  r22

/** \ingroup avr_string
    \fn char *strrev(char *string)
    \brief Reverse a string.

    The strrev() function reverses the order of the string.

    \returns The strrev() function returns a pointer to the beginning of the
    reversed string.  */

#if !defined(__DOXYGEN__)

    .text
    .global _U(strrev)
    .type   _U(strrev), @function

_U(strrev):
    LOAD_X(str_lo, str_hi)	; X is start of string
	LOAD_Z(str_lo, str_hi)	; Z becomes end of string
.strrev_eos:
	LD    __tmp_reg__, Z+
	TST   __tmp_reg__
	BRNE  .strrev_eos
	SBIW  ZL, 2				; now Z points at end of string
.strrev_loop:
	CP    XL, ZL
	CPC   XH, ZH			; if X >= Z we are done
	BRSH  .strrev_done
	LD    ltemp, X          ; get left character
	LD    rtemp, Z			; get right character
	ST    Z, ltemp
	SBIW  ZL, 1
	ST    X+, rtemp			; swap chars
	RJMP  .strrev_loop		; next pair
.strrev_done:
    RET
.strrev_end:
	.size _U(strrev), .strrev_end - _U(strrev)

#endif /* not __DOXYGEN__ */
