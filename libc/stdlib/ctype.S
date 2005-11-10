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

#include "gasava.inc"
#include "macros.inc"
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

#define rHigh    rP0
#define rLow     rP1

#if defined (Lisascii)
          TEXT_SEG(ctype, isascii)
          FUNCTION(isascii)

GLOBAL(isascii)
          CPSE    rHigh,__zero_reg__
          RJMP    _U(__ctype_isfalse)
          COM     rLow
          ANDI    rLow, 0x80
          RET

          ENDFUNC
#endif

#if defined (Ltoascii)
          TEXT_SEG(ctype, toascii)
          FUNCTION(toascii)

GLOBAL(toascii)
          CLR     rHigh
          ANDI    rLow, 0x7F
          RET

          ENDFUNC
#endif

#if defined (Lisalnum)
          TEXT_SEG(ctype, isalnum)
          FUNCTION(isalnum)

GLOBAL(isalnum)
          CPSE  rHigh,__zero_reg__
          RJMP  _U(__ctype_isfalse)
          PUSH  rLow               ; save, destroyed by isdigit returning 0
          RCALL _U(isdigit)
          TST   rLow
          POP   rLow
          BREQ  1f
          RET                      ; true
1:
          RJMP  _U(isalpha)

          ENDFUNC
#endif

#if defined (Lcty_isfalse)
          TEXT_SEG(ctype, __ctype_isfalse)
          FUNCTION(__ctype_isfalse)

GLOBAL(__ctype_isfalse)
          CLR   rHigh
          CLR   rLow
GLOBAL(__ctype_istrue)
          RET

          ENDFUNC
#endif

;-------------------------------------------------------------------

#if defined (Lisalpha)
          TEXT_SEG(ctype, isalpha)
          FUNCTION(isupper)

GLOBAL(isupper)
          ;CPSE  rHigh,__zero_reg__
          ;RJMP  _U(__ctype_isfalse)    ; checked by _islower later on
          SBRC  rLow,5       ; if bit 5 is set it is no upper
          RJMP  _U(__ctype_isfalse)     ; bit 5 is clear, so if isalpha is true it is an upper
GLOBAL(isalpha)
          ORI     rLow,0x20        ; make a lower out of an upper (all others are changed but do not get alpha)
GLOBAL(islower)
          CPSE  rHigh,__zero_reg__
1:
          RJMP  _U(__ctype_isfalse)
          CPI   rLow,'a'
          BRLT  1b
          CPI   rLow,'z'+1
          BRGE  1b
          RET                      ; 'a' <= rLow <= 'z' (!= 0!!, Z=0)

          ENDFUNC
#endif

;-------------------------------------------------------------------

#if defined (Lisdigit)
          TEXT_SEG(ctype, isdigit)
          FUNCTION(isdigit)

GLOBAL(isdigit)
          CPSE  rHigh,__zero_reg__
1:        
          RJMP  _U(__ctype_isfalse)
          SUBI  rLow,'0'
          SUBI  rLow,10
          BRSH  1b
          RET                      ; rLow: -10..-1

          ENDFUNC
#endif

;-------------------------------------------------------------------

#if defined (Lisxdigit)
          TEXT_SEG(ctype, isxdigit)
          FUNCTION(isxdigit)

GLOBAL(isxdigit)
          MOV   __tmp_reg__,rLow
          ORI   rLow,0x20
          CPI   rLow,'a'
          BRLT  0f
          CPI   rLow,'f'+1
          BRGE  1f
          RET                      ; 'a' <= rLow <= 'f' (!= 0!!)
1:
          RJMP  _U(__ctype_isfalse)
0:
          MOV   rLow,__tmp_reg__
          RJMP  _U(isdigit)

          ENDFUNC
#endif

;-------------------------------------------------------------------

#if defined (Liscntrl)
          TEXT_SEG(ctype, iscntrl)
          FUNCTION(iscntrl)

GLOBAL(iscntrl)
          CPSE  rHigh,__zero_reg__
1:
          RJMP  _U(__ctype_isfalse)
          CPI   rLow,0x7F
          BREQ  2f
          CPI   rLow,0x1F+1
          BRGE  1b
          SER   rLow               ; 0 is cntrl, too! -> return true
2:
          RET

          ENDFUNC
#endif

;-------------------------------------------------------------------

#if defined (Lisprint)
          TEXT_SEG(ctype, isprint)
          FUNCTION(isgraph)

GLOBAL(isgraph)
          CPI   rLow,' '
          BREQ  1f
GLOBAL(isprint)
          TST   rHigh
          BRNE  1f
          CPI   rLow,' '
          BRLT  1f
          CPI   rLow,0x7E+1
          BRGE  1f                 ;  ' ' <= rLow <= 0x7E (!= 0!!)
          RET
1:
          RJMP  _U(__ctype_isfalse)

          ENDFUNC
#endif

;-------------------------------------------------------------------

#if defined (Lisspace)
          TEXT_SEG(ctype, isspace)
          FUNCTION(isspace)

GLOBAL(isspace)
          CPSE  rHigh,__zero_reg__
1:
          RJMP  _U(__ctype_isfalse)
          CPI   rLow,' '           ; blank
          BREQ  2f
          CPI   rLow,0x0A    ;'\n' ; line feed
          BREQ  2f
          CPI   rLow,0x0C    ;'\f' ; form feed
          BREQ  2f
          CPI   rLow,0x0D    ;'\r' ; carriage return
          BREQ  2f
          CPI   rLow,0x09    ;'\t' ; tab
          BREQ  2f
          CPI   rLow,0x0B    ;'\v' ; vertical tab
          BRNE  1b
2:
          RET

          ENDFUNC
#endif

;-------------------------------------------------------------------

#if defined (Lispunct)
          TEXT_SEG(ctype, ispunct)
          FUNCTION(ispunct)

GLOBAL(ispunct)
          mov   __tmp_reg__, rLow    ; **changed** they do not use it
          RCALL _U(isprint)          ; false: CLR rLow -> EQ, rLow changed
          BREQ  0f		; true : CPI rLow,0x7E+1 -> NE, rLow unchanged

          RCALL _U(isspace)
          CPSE  rLow,__zero_reg__
1:
          RJMP  _U(__ctype_isfalse)
          mov   rLow, __tmp_reg__    ; **changed**
          RCALL _U(isalnum)
          TST   rLow
          BRNE  1b
          SER   rLow
0:
          RET

          ENDFUNC
#endif

;-------------------------------------------------------------------

#if defined (Lisblank)
          TEXT_SEG(ctype, isblank)
          FUNCTION(isblank)

GLOBAL(isblank)
          CPSE  rHigh,__zero_reg__
1:
          RJMP  _U(__ctype_isfalse)
          CPI   rLow,' '           ; blank
          BREQ  2f
          CPI   rLow,0x09    ;'\t' ; tab
          BREQ  2f
          CPI   rLow,0x0B    ;'\v' ; vertical tab
          BRNE  1b
2:
          RET

          ENDFUNC
#endif

;-------------------------------------------------------------------

#if defined (Ltolower)
          TEXT_SEG(ctype, tolower)
          FUNCTION(tolower)

GLOBAL(tolower)
          PUSH  rLow
          RCALL _U(isalpha)
          POP   rLow         ; does not change Z
          BREQ  0f
          ORI   rLow,0x20
0:
          RET

          ENDFUNC
#endif

;-------------------------------------------------------------------

#if defined (Ltoupper)
          TEXT_SEG(ctype, toupper)
          FUNCTION(toupper)

GLOBAL(toupper)
          PUSH  rLow
          RCALL _U(isalpha)
          POP   rLow         ; does not change Z
          BREQ  0f
          ANDI  rLow,0xDF
0:
          RET

          ENDFUNC
#endif

#endif /* not __DOXYGEN__ */
