;; Copyright (c) 1999, 2000, 2001, 2002, 2005 Michael Stumpf
;; All rights reserved.
;;
;; Redistribution and use in source and binary forms, with or without
;; modification, are permitted provided that the following conditions are met:
;;
;; * Redistributions of source code must retain the above copyright
;;   notice, this list of conditions and the following disclaimer.
;; * Redistributions in binary form must reproduce the above copyright
;;   notice, this list of conditions and the following disclaimer in
;;   the documentation and/or other materials provided with the
;;   distribution.
;; * Neither the name of the copyright holders nor the names of
;;   contributors may be used to endorse or promote products derived
;;   from this software without specific prior written permission.
;;
;; THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
;; AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
;; IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
;; ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
;; LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
;; CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
;; SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
;; INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
;; CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
;; ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
;; POSSIBILITY OF SUCH DAMAGE.

;; $Id$

#if !defined(__DOXYGEN__)

#include "asmdef.h"

;================================================================================
; ctype.s
;
; Character handling - ctype.h
;
; Author : Michael Stumpf  (c) 1999
;          Michael.Stumpf@t-online.de
;
; Versions : V0.1.0
;
; adapted to avr-as
;          Michael Rickmann, Feb. 2000
;          **changed**: changes to code
;
; int isalnum(int c)      Letter or digit equality.
; int isalpha(int c)      Letter equality.
; int iscntrl(int c)      Control code equality.
; int isdigit(int c)      Digit equality.
; int isgraph(int c)      Printable non-space character equality.
; int islower(int c)      Lower case equality.
; int isprint(int c)      Printable character equality.
; int ispunct(int c)      Punctuation character equality.
; int isspace(int c)      White-space character equality.
;
; int isupper(int c)      Upper case equality.
; int isxdigit(int c)     Hex digit equality.
; int tolower(int c)      Converts to lower case.
; int toupper(int c)      Converts to upper case.
; int isblank(int c)      Blank-space character test.
;
; realized as functions, not as macro with a 256 - byte large bit-table
;
; gives a total of 182 bytes code and short function calls
;
;================================================================================

#define rHigh    r25   /* first incoming parameter (MSB) */
#define rLow     r24   /* first incoming parameter (LSB) */

#if defined (Lisascii)

ENTRY isascii
#ifdef __AVR_ERRATA_SKIP_JMP_CALL__
          TST     rHigh
          BREQ    0f
#else
          CPSE    rHigh,__zero_reg__
#endif
          XJMP    _U(__ctype_isfalse)
0:
          COM     rLow
          ANDI    rLow, 0x80
          RET
ENDFUNC

#endif

#if defined (Ltoascii)

ENTRY toascii
          CLR     rHigh
          ANDI    rLow, 0x7F
          RET
ENDFUNC

#endif

#if defined (Lisalnum)

ENTRY isalnum
#ifdef __AVR_ERRATA_SKIP_JMP_CALL__
	tst	rHigh
	breq	0f
#else
	cpse	rHigh, __zero_reg__
#endif
	XJMP	_U(__ctype_isfalse)
0:      subi	rLow, '0'
	subi	rLow, '9'-'0'+1
	brlo	2f			; rLow is digit, return negative val.
	subi	rLow, lo8(-'9'-1)	; restore rLow
	XJMP	_U(isalpha)
2:	ret
ENDFUNC

#endif

#if defined (Lcty_isfalse)

ENTRY __ctype_isfalse
          CLR   rHigh
          CLR   rLow
ENTRY __ctype_istrue
          RET
ENDFUNC

#endif

;-------------------------------------------------------------------

#if defined (Lisalpha)

ENTRY isupper
          ;CPSE  rHigh,__zero_reg__
          ;XJMP  _U(__ctype_isfalse)    ; checked by _islower later on
#ifdef __AVR_ERRATA_SKIP_JMP_CALL__
          SBRS  rLow,5
          RJMP  _U(isalpha)
#else
          SBRC  rLow,5       ; if bit 5 is set it is no upper
#endif
          XJMP  _U(__ctype_isfalse)     ; bit 5 is clear, so if isalpha is true it is an upper
ENTRY isalpha
          ORI     rLow,0x20        ; make a lower out of an upper (all others are changed but do not get alpha)
ENTRY islower
#ifdef __AVR_ERRATA_SKIP_JMP_CALL__
          TST   rHigh
          BREQ  0f
#else
          CPSE  rHigh,__zero_reg__
#endif
1:
          XJMP  _U(__ctype_isfalse)
0:
          SUBI	rLow, 'a'
          SUBI	rLow, 'z'-'a'+1
          BRSH	1b
          RET			; TRUE: rLow is in -26..-1
ENDFUNC

#endif

;-------------------------------------------------------------------

#if defined (Lisdigit)

ENTRY isdigit
#ifdef __AVR_ERRATA_SKIP_JMP_CALL__
          TST   rHigh
          BREQ  0f
#else
          CPSE  rHigh,__zero_reg__
#endif
1:
          XJMP  _U(__ctype_isfalse)
0:
          SUBI  rLow,'0'
          SUBI  rLow,10
          BRSH  1b
          RET                      ; rLow: -10..-1
ENDFUNC

#endif

;-------------------------------------------------------------------

#if defined (Lisxdigit)

; This fact is used below.
.if	'a' - 'A' - 0x20
  .err
.endif

ENTRY isxdigit
#ifdef __AVR_ERRATA_SKIP_JMP_CALL__
	tst	rHigh
	breq	0f
#else
	cpse	rHigh, __zero_reg__
#endif
1:	XJMP	_U(__ctype_isfalse)
0:      subi	rLow, '0'
	subi	rLow, '9'-'0'+1
	brlo	2f			; decimal digit
	subi	rLow, lo8(-'9'-1)	; restore rLow
	ori	rLow, 'a' - 'A'		; rLow := tolower(rLow)
	subi	rLow, 'a'
	subi	rLow, 'f'-'a'+1
	brsh	1b
2:	ret				; OK: return a negative value
ENDFUNC

#endif

;-------------------------------------------------------------------

#if defined (Liscntrl)

ENTRY iscntrl
#ifdef __AVR_ERRATA_SKIP_JMP_CALL__
          TST   rHigh
          BREQ  0f
#else
          CPSE  rHigh,__zero_reg__
#endif
1:
          XJMP  _U(__ctype_isfalse)
0:
          CPI   rLow,0x7F
          BREQ  2f
          SUBI  rLow, ' '
          BRSH  1b		; iscntrl('\0') --> true
2:
          RET			; TRUE: rLow is 0x7F or negative value
ENDFUNC

#endif

;-------------------------------------------------------------------

#if defined (Lisprint)

ENTRY isgraph
          CPI   rLow,' '
          BREQ  1f
ENTRY isprint
#ifdef __AVR_ERRATA_SKIP_JMP_CALL__
	  TST	rHigh
	  BREQ	0f
#else
	  CPSE	rHigh, __zero_reg__
#endif
1:	  XJMP	_U(__ctype_isfalse)
0:	  SUBI	rLow, ' '
	  SUBI	rLow, 0x7E - ' ' + 1
	  BRSH	1b
	  RET			; TRUE: rlow is negative value
ENDFUNC

#endif

;-------------------------------------------------------------------

#if defined (Lisspace)

/* This fact is used below.	*/
.if	('\t'-9) | ('\n'-10) | ('\f'-12) | ('\r'-13)	; '\v' is 11
  .err
.endif

ENTRY isspace
#ifdef __AVR_ERRATA_SKIP_JMP_CALL__
          TST   rHigh
          BREQ  0f
#else
          CPSE  rHigh,__zero_reg__
#endif
1:
          XJMP  _U(__ctype_isfalse)
0:
          CPI   rLow,' '           ; blank
          BREQ  2f
	  SUBI	rLow, '\t'
	  SUBI	rLow, '\r'-'\t'+1
	  BRSH	1b
2:	  RET			; TRUE result: rLow is -5..-1 or ' '
ENDFUNC

#endif

;-------------------------------------------------------------------

#if defined (Lispunct)

ENTRY ispunct
#ifdef __AVR_ERRATA_SKIP_JMP_CALL__
	tst	rHigh
	breq	0f
#else
	cpse	rHigh, __zero_reg__
#endif
1:	XJMP	_U(__ctype_isfalse)
0:	subi	rLow, ' ' + 1
	subi	rLow, 0x7e - ' '
	brsh	1b			; if (!isgraph(c)) return 0
	subi	rLow, lo8(-0x7e - 1)	; restore rLow
	XCALL	_U(isalnum)
	tst	rLow
	brne	1b			; if (isalnum(c)) return 0
	ldi	rLow, 1
	ret
ENDFUNC

#endif

;-------------------------------------------------------------------

#if defined (Lisblank)

ENTRY isblank
#ifdef __AVR_ERRATA_SKIP_JMP_CALL__
          TST   rHigh
          BREQ  0f
#else
          CPSE  rHigh,__zero_reg__
#endif
1:
          XJMP  _U(__ctype_isfalse)
0:
          CPI   rLow,' '           ; blank
          BREQ  2f
          CPI   rLow,0x09    ;'\t' ; tab
          BRNE  1b
2:
          RET
ENDFUNC

#endif

;-------------------------------------------------------------------

#if defined (Ltolower)

ENTRY tolower
#ifdef __AVR_ERRATA_SKIP_JMP_CALL__
	tst	rHigh
	breq	0f
#else
	cpse	rHigh, __zero_reg__
#endif
	ret				; return as is
0:	subi	rLow, 'A'
	subi	rLow, 'Z'-'A'+1
	brsh	1f			; return as is
	subi	rLow, lo8('A'-'a')	; conversion
1:	subi	rLow, lo8(-'Z'-1)	; restore
	ret
ENDFUNC

#endif

;-------------------------------------------------------------------

#if defined (Ltoupper)

ENTRY toupper
#ifdef __AVR_ERRATA_SKIP_JMP_CALL__
	tst	rHigh
	breq	0f
#else
	cpse	rHigh, __zero_reg__
#endif
	ret				; return as is
0:	subi	rLow, 'a'
	subi	rLow, 'z'-'a'+1
	brsh	1f			; return as is
	subi	rLow, lo8('a'-'A')	; conversion
1:	subi	rLow, lo8(-'z'-1)	; restore
	ret
ENDFUNC

#endif

#endif /* not __DOXYGEN__ */
