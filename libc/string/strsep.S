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
     \fn char *strsep(char **string, const char *delim)
     \brief Parse a string into tokens.
 
     The strsep() function locates, in the string referenced by *string,
     the first occurrence of any character in the string delim (or the
     terminating '\\0' character) and replaces it with a '\\0'.  The location
     of the next character after the delimiter character (or NULL, if the
     end of the string was reached) is stored in *string. An ``empty''
     field, i.e. one caused by two adjacent delimiter characters, can be
     detected by comparing the location referenced by the pointer returned
     in *string to '\\0'.
   
     \returns The strtok_r() function returns a pointer to the original
     value of *string.  If *stringp is initially NULL, strsep() returns NULL.
 */
     
#if !defined(__DOXYGEN__)

#include "gasava.inc"
#include "macros.inc"
#define X_hi		r27
#define X_lo		r26
#define p_str_hi	r25
#define p_str_lo	r24
#define del_hi		r23
#define del_lo		r22
#define str_hi		r21
#define str_lo		r20
#define str_c		r19
#define del_c		r18

	.text
	.global _U(strsep)
	.type	 _U(strsep),@function

_U(strsep):				; Check on NULL pointers
	LOAD_X	(p_str_lo, p_str_hi)
	LD	str_lo, X+
	LD	str_hi, X		; str = *p_str
	CP	str_lo, __zero_reg__
	CPC	str_hi, __zero_reg__	; str == NULL ?
	BRNE	.str_scan_init
	CLR	p_str_lo
	CLR	p_str_hi
	RET				; return(NULL)

.str_scan_init:				; scan string
	LOAD_X	(str_lo, str_hi)	; X = str
	PUSH	X_lo
	PUSH	X_hi			; save pointer to token

.scan_str_loop:				; next str char, 1st del char
	LD	str_c, X+		; str_c = *str++
	LOAD_Z	(del_lo, del_hi)	; Z = del

.scan_del_loop:
	LD	del_c, Z+		; del_c = *Z
	CP	del_c, str_c		; if (del_c == str_c)
	BRNE	3f
	TST	str_c			; end of str ?
	BRNE	1f
	CLR	X_lo
	CLR	X_hi			; str = NULL
	RJMP	2f
1:	ST	-X, __zero_reg__	; str[-1] = \0
	ADIW	X_lo, 1			; undo auto decrement
2:	LOAD_Z	(p_str_lo, p_str_hi)
	ST	Z+, X_lo
	ST	Z, X_hi			; *string = str
	POP	p_str_hi
	POP	p_str_lo
	RET				; return(token)
3:	TST	del_c			; end of del string ?
	BRNE	.scan_del_loop		; next del char, same str_char
	RJMP	.scan_str_loop		; next str char, 1st del char

.strsep_end:
	.size	_U(strsep), .strsep_end - _U(strsep)

#endif /* not __DOXYGEN__ */
