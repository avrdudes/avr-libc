/* Copyright (c) 2003, 2007 Reiner Patommel
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
  POSSIBILITY OF SUCH DAMAGE.

*/

/* $Id$ */

/** \file */

/** \ingroup avr_string
    \fn char *strtok_r(char *string, const char *delim, char **last)
    \brief Parses string into tokens.

    strtok_r parses string into tokens. The first call to strtok_r
    should have string as its first argument. Subsequent calls should have
    the first argument set to NULL. If a token ends with a delimiter, this
    delimiting character is overwritten with a '\\0' and a pointer to the next
    character is saved for the next call to strtok_r. The delimiter string
    delim may be different for each call. last is a user allocated char*
    pointer. It must be the same while parsing the same string. strtok_r is
    a reentrant version of strtok().
    
    \returns The strtok_r() function returns a pointer to the next token or
    NULL when no more tokens are found. */

#if !defined(__DOXYGEN__)

#include "macros.inc"

#define str_hi		r25
#define str_lo		r24
#define del_hi		r23
#define del_lo		r22
#define last_hi		r21
#define last_lo		r20
#define str_c		r19
#define del_c		r18

	.text
	.global _U(strtok_r)
	.type	_U(strtok_r), @function

_U(strtok_r):				; Check on NULL pointers
	SBIW	str_lo, 0		; str == NULL ?
	BRNE	.L_del_lead_init	; here 1st call to strtok_r
	X_movw	XL, last_lo
	LD	str_lo, X+
	LD	str_hi, X		;
	SBIW	str_lo, 0		; last == NULL ?
	BRNE	.L_del_lead_init	; here nth call to strtok_r
	RJMP	2f			; no more to do

.L_del_lead_init:			; Remove leading delimiters
	X_movw	XL, str_lo

.L_del_str_loop:
	X_movw	ZL, del_lo		; Z = *delim
	LD	str_c, X+		; str_c = *string++

.L_del_loop:
	LD	del_c, Z+		; del_c = *Z
	TST	del_c			; end of del string ?
	BREQ	1f			; yes: -> done with leading delimiters
	CP	str_c, del_c
	BREQ	.L_del_str_loop		; match:  -> next str_char, 1st del_char
	RJMP	.L_del_loop		; next del_char, same str_char
1:	TST	str_c			; end of str ?
	BRNE	.L_str_scan_init	; no: -> scan
	X_movw	XL, last_lo
	ST	X+, __zero_reg__
	ST	X, __zero_reg__		; last = NULL
2:	CLR	str_lo
	CLR	str_hi
	RET				; return(NULL)

.L_str_scan_init:			; scan string
	SBIW	XL, 1			; X points to token
	PUSH	XL
	PUSH	XH			; save pointer to token

.L_scan_str_loop:			; next str char, 1st del char
	X_movw	ZL, del_lo		; Z points to del str
	LD	str_c, X+		; str_c = *string++

.L_scan_del_loop:
	LD	del_c, Z+		; del_c = *Z
	CP	str_c, del_c
	BRNE	3f
	TST	str_c			; end of str ?
	BRNE	1f
	CLR	str_lo
	CLR	str_hi			; str = NULL
	SBIW	XL, 1			; undo auto increment
	RJMP	2f
1:	ST	-X, __zero_reg__	; str[-1] = \0
	ADIW	XL, 1			; undo auto decrement
2:	X_movw	ZL, last_lo
	ST	Z+, XL
	ST	Z, XH			; *last = str
	POP	str_hi
	POP	str_lo			; get pointer to token again
	RET				; return(token)
3:	TST	del_c			; end of del string ?
	BRNE	.L_scan_del_loop	; next del char, same str_char
	RJMP	.L_scan_str_loop	; next str char, 1st del char

.L_strtok_r_end:
	.size	_U(strtok_r), .L_strtok_r_end - _U(strtok_r)

#endif /* not __DOXYGEN__ */
