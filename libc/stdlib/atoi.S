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
   $Id$

   Contributors:
     Created by Reiner Patommel
     Changes: Jochen Pernsteiner, Marek Michalkiewicz
     Changes: Reiner Patommel, 8 Feb 2003
     Changes: Reiner Patommel, 13 May 2003 (DOXYGEN)
 */

#include "macros.inc"

#define str_hi	r25
#define str_lo	r24
#define num_hi	r25
#define num_lo	r24
#define tmp	r18


/** \ingroup avr_stdlib
    \fn int atoi(const char *string)
    \brief Convert a string to an integer.
        
    The atoi() function converts the initial portion of the string
    pointed to by \c nptr to integer representation.

    It is equivalent to:

           \code (int)strtol(nptr, (char **)NULL, 10); \endcode
           except that atoi() does not detect errors.	   
*/

	.text
	.global _U(atoi)
	.type   _U(atoi), @function

/*
   Skip leading spaces and tabs.  Process optional sign.  Stop conversion
   on detection of a non-numeric character.  Return 0 if string contains
   no numeric characters. No check is performed whether the value is within
   the range of an 'int' i.e. 32768 becomes -32768.
 */

_U(atoi):
	LOAD_Z	(str_lo, str_hi)	; set pointer to string
	CLR	num_lo
	CLR	num_hi			; clear number
	CLT				; clear sign flag

.atoi_loop:
	LD	tmp, Z+			; get (next) character
	TST	tmp			; is it end of string?
	BREQ	.atoi_sig
	CPI	tmp, ' '		; skip whitespace
	BREQ	.atoi_loop
	CPI	tmp, '\t'
	BREQ	.atoi_loop
	CPI	tmp, '\n'
	BREQ	.atoi_loop
	CPI	tmp, '\f'
	BREQ	.atoi_loop
	CPI	tmp, '\r'
	BREQ	.atoi_loop
	CPI	tmp, '\v'
	BREQ	.atoi_loop
	CPI	tmp, '+'		; if '+' convert
	BREQ	.atoi_loop2
	CPI	tmp, '-'		; if '-' remember sign
	BRNE	.atoi_digit

.atoi_neg:
	SET				; remember number is negative

.atoi_loop2:
	LD	tmp, Z+
	TST	tmp
	BREQ	.atoi_sig

.atoi_digit:
	CPI	tmp, '0'		; test on [0 .. 9]
	BRLT	.atoi_sig
	CPI	tmp, '9'+1
	BRGE	.atoi_sig
	SUBI	tmp, '0'		; make figure a number
	XCALL	__mulhi_const_10	; r25:r24 *= 10
	ADD	num_lo, tmp		; num = (num * 10) + (tmp - '0')
	ADC	num_hi, __zero_reg__
	RJMP	.atoi_loop2		; next figure

.atoi_sig:
	CP	num_lo, __zero_reg__
	CPC	num_hi, __zero_reg__	; did we get a number?
	BREQ	.atoi_done		; no, drop sign and return
	BRTC	.atoi_done		; positive number? -> return
	COM	num_lo
	COM	num_hi
	ADIW	num_lo, 1		; make number negative

.atoi_done:
	RET

.atoi_end:
	.size _U(atoi), .atoi_end - _U(atoi)


