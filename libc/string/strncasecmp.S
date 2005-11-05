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
   strncasecmp.S
   Case insensitive compare

   Contributors:
     Created by Reiner Patommel
*/
#include "macros.inc"

#define s1_hi r25
#define s1_lo r24
#define s2_hi r23
#define s2_lo r22
#define len_hi r21
#define len_lo r20
#define tmp r19
#define cht r18

#define ret_hi r25
#define ret_lo r24

/** \ingroup avr_string
    \fn int strncasecmp(const char *s1, const char *s2, size_t len)
    \brief Compare two strings ignoring case.

    The strncasecmp() function is similar to strcasecmp(), except it only
    compares the first n characters of s1.

    \returns The strncasecmp() function returns an integer less than, equal to,
    or greater than zero if s1 (or the first n bytes thereof) is found,
    respectively, to be less than, to match, or be greater than s2.  */

#if !defined(__DOXYGEN__)

	.text
	.global	_U(strncasecmp)
	.type	_U(strncasecmp), @function
	
_U(strncasecmp):
	X_movw	ZL, s2_lo
	X_movw	XL, s1_lo
.L_strncasecmp_loop:
	SUBI    len_lo, lo8(1)
	SBCI    len_hi, hi8(1)
	BRCS	.L_strncasecmp_equal
	LD      ret_lo, X+		; load *s1
	LD      tmp, Z+			; load *s2
	MOV     cht, tmp		; copy of *s2 to cht
	ORI     cht, 0x20		; make it lower case
	CPI     cht, 'a'		; test on [a .. z]
	BRLT	.L_strncasecmp_tst
	CPI     cht, 'z'+1
	BRGE    .L_strncasecmp_tst
	ORI     tmp, 0x20		; we got an alpha in s2
	ORI     ret_lo, 0x20		; make *s1, *s2 lower case
.L_strncasecmp_tst:
	SUB     ret_lo, tmp		; compare chars
	BRNE	.L_strncasecmp_done
	TST     tmp			; end of s2?
	BRNE	.L_strncasecmp_loop
.L_strncasecmp_equal:
	SUB     ret_lo, ret_lo		; clear ret_lo and C flag
.L_strncasecmp_done:
; ret_hi = SREG.C ? 0xFF : 0
	SBC     ret_hi, ret_hi
	RET
.L_strncasecmp_end:
	.size	_U(strncasecmp), .L_strncasecmp_end - _U(strncasecmp)

#endif /* not __DOXYGEN__ */
