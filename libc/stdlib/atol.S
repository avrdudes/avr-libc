/* Copyright (c) 2002, 2007 Reiner Patommel
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
   atol.S

   Contributors:
     Created by Reiner Patommel
     Modified by Reiner Patommel 8 Feb 2003, Bug #2481
     Modified by Reiner Patommel 13 May 2003, (DOXYGEN)

   TODO: this implementation uses an inline isspace(). If Avr-libc will
   use locales other than C/POSIX it is needed to call an external isspace().
   
   ATTENTION: an external __mulsi_const_10() function is used: nonstandart
   call conventions: some registers and bit T must be nochanged.
 */

/** \file */
/** \ingroup avr_stdlib
    \fn long atol(const char *s)
    \brief Convert a string to a long integer.

    The atol() function converts the initial portion of the string
    pointed to by \p s to long integer representation. In contrast to

        \code strtol(s, (char **)NULL, 10); \endcode

    this function does not detect overflow (\c errno is not changed and
    the result value is not predictable), uses smaller memory (flash and
    stack) and works more quickly.
*/

#if !defined(__DOXYGEN__)

#include "macros.inc"

#define str_hi		r25
#define str_lo		r24
#define num_hi_hi	r25
#define num_hi_lo	r24
#define num_lo_hi	r23
#define num_lo_lo	r22
#define tmp		r17

	ASSEMBLY_CLIB_SECTION
	.global _U(atol)
	.type   _U(atol), @function

/*
   Skip leading spaces and tabs.  Process optional sign.  Stop conversion
   on detection of a non-numeric character.  Return 0 if string contains
   no numeric characters.
 */

/* This fact is used below.	*/
.if	('\t'-9) | ('\n'-10) | ('\f'-12) | ('\r'-13)	; '\v' is 11
  .err
.endif

_U(atol):
	PUSH	tmp
	X_movw	ZL, str_lo		; set pointer to string
	CLR	num_hi_hi
	CLR	num_hi_lo
	X_movw	num_lo_lo, num_hi_lo	; clear number
	CLT				; clear sign

.L_atol_loop:
	LD	tmp, Z+			; get (next) character
	CPI	tmp, ' '		; skip whitespace
	BREQ	.L_atol_loop
	CPI	tmp, '\t'
	BRLO	1f
	CPI	tmp, '\r'+1
	BRLO	.L_atol_loop
1:
	CPI	tmp, '+'		; if '+' go on
	BREQ	.L_atol_loop2
	CPI	tmp, '-'		; if '-' remember sign
	BRNE	.L_atol_digit
	SET				; remember number is negative
	RJMP	.L_atol_loop2

2:	XCALL	__mulsi_const_10	; r25:r24:r23:r22 *= 10
	ADD	num_lo_lo, tmp		; num = (num * 10) + (tmp - '0')
	ADC	num_lo_hi, __zero_reg__
	ADC	num_hi_lo, __zero_reg__
	ADC	num_hi_hi, __zero_reg__
.L_atol_loop2:
	LD	tmp, Z+
.L_atol_digit:
	SUBI	tmp, '0'		; make figure a number
	CPI	tmp, 10
	BRLO	2b

	BRTC	.L_atol_done		; positive number? -> return
	COM	num_hi_hi
	COM	num_hi_lo
	COM	num_lo_hi
	NEG	num_lo_lo
	SBCI	num_lo_hi, 0xff
	SBCI	num_hi_lo, 0xff
	SBCI	num_hi_hi, 0xff		; make number negative

.L_atol_done:
	POP	tmp
	RET

.L_atol_end:
	.size _U(atol), .L_atol_end - _U(atol)

#endif /* not __DOXYGEN__ */
