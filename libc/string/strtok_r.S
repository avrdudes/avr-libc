/* Copyright (c) 2003, Reiner Patommel
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

/** \ingroup avr_string
    \char *strtok_r(char *string, const char *delim, char **last)
    \brief Parses the string s into tokens.

    strtok_r parses the string s into tokens. The first call to strtok_r
    should have string as its first argument. Subsequent calls should have
    the first argument set to NULL. If a token ends with a delimiter, this
    delimiting character is overwritten with a \0 and a pointer to the next
    character is saved for the next call to strtok_r. The delimiter string
    delim may be different for each call. last is a user allocated char*
    pointer. It must be the same while parsing the same string. strtok_r is
    a reentrant version of strtok().
    
    \returns The strtok_r() function returns a pointer to the next token or
    NULL when no more tokens are found. */

#include "gasava.inc"
#include "macros.inc"

#define X_hi		r27
#define X_lo		r26
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
	.type	 _U(strtok_r), @function

_U(strtok_r):				; Check on NULL pointers
	SBIW	str_lo, 0		; str == NULL ?
	BRNE	.del_lead_init		; here 1st call to strtok_r
	LOAD_X	(last_lo, last_hi)
	LD	str_lo, X+
	LD	str_hi, X		;
	SBIW	str_lo, 0		; last == NULL ?
	BRNE	.del_lead_init		; here nth call to strtok_r
	RJMP	2f			; no more to do

.del_lead_init:				; Remove leading delimiters
	LOAD_X	(str_lo, str_hi)

.del_str_loop:
	LOAD_Z	(del_lo, del_hi)	; Z = *delim
	LD	str_c, X+		; str_c = *string++

.del_loop:
	LD	del_c, Z+		; del_c = *Z
	TST	del_c			; end of del string ?
	BREQ	1f			; yes: -> done with leading delimiters
	CP	str_c, del_c
	BREQ	.del_str_loop		; match:  -> next str_char, 1st del_char
	RJMP	.del_loop		; next del_char, same str_char
1:	TST	str_c			; end of str ?
	BRNE	.str_scan_init		; no: -> scan
	LOAD_X	(last_lo, last_hi)
	ST	X+, __zero_reg__
	ST	X, __zero_reg__		; last = NULL
2:	CLR	str_lo
	CLR	str_hi
	RET				; return(NULL)

.str_scan_init:				; scan string
	SBIW	X_lo, 1			; X points to token
	PUSH	X_lo
	PUSH	X_hi			; save pointer to token

.scan_str_loop:				; next str char, 1st del char
	LOAD_Z	(del_lo, del_hi)	; Z points to del str
	LD	str_c, X+		; str_c = *string++

.scan_del_loop:
	LD	del_c, Z+		; del_c = *Z
	CP	str_c, del_c
	BRNE	3f
	TST	str_c			; end of str ?
	BRNE	1f
	CLR	str_lo
	CLR	str_hi			; str = NULL
	SBIW	X_lo, 1			; undo auto increment
	RJMP	2f
1:	ST	-X, __zero_reg__	; str[-1] = \0
	ADIW	X_lo, 1			; undo auto decrement
2:	LOAD_Z	(last_lo, last_hi)
	ST	Z+, X_lo
	ST	Z, X_hi			; *last = str
	POP	str_hi
	POP	str_lo			; get pointer to token again
	RET				; return(token)
3:	TST	del_c			; end of del string ?
	BRNE	.scan_del_loop		; next del char, same str_char
	RJMP	.scan_str_loop		; next str char, 1st del char

.strtok_r_end:
	.size	_U(strtok_r), .strtok_r_end - _U(strtok_r)

