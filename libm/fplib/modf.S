/*  -*- Mode: Asm -*-  */

/* Copyright (c) 2002  Michael Stumpf  <mistumpf@de.pepperl-fuchs.com>
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

/*
    modf.S is part of     FPlib V 0.3.0       ported to avr-as
    for details see readme.fplib

 *----------------------------------------------------------------------------------------
 *
 * A = modf(A,&B) *B = integral part of A
 *                 A = fractional part of A
 */

#include "gasava.inc"
#include "fplib.inc"

          TEXT_SEG(fplib, modf)
          FUNCTION(modf)

GLOBAL(modf)
        BST     rA3,7
        RCALL   _U(__fp_split1)	; clears rAE

        PUSH    YL
        PUSH    YH
        MOV     YH,rPH
        MOV     YL,rPL		; pointer to double
        CLR     rB3
        CLR     rB2
        CLR     rB1
        CLR     rB0		; preset zero integral part

        TST     rA3		; if zero return zero for *int and mantissa
        BREQ    10f
        CPI     rA3,0x7F	; Exp < 0x7F -> arg < 1.0 -> no integer part
        BRCS    10f

        MOV     rTI0,rA3	; keep temporarily
        RCALL   _U(__fp_merge)	; rT0 must not be cleared : rAE=0 no rounding anyway
        MOV     rB3,rA3
        MOV     rB2,rA2
        MOV     rB1,rA1
        MOV     rB0,rA0

        CPI     rTI0,0x96	; rA3 >= 0x96 -> no fractional part
        BRCC    2f
        RCALL   _U(__fixsfsi)	;
        RCALL   _U(__floatsisf)	;
        CPI     YL,0
        CPC     YL,YH
        BREQ    1f
        ST      Y+,rA0
        ST      Y+,rA1
        ST      Y+,rA2
        ST      Y+,rA3		; A = integer part
1:
        SUBI    rA3,0x80	; A = -int(x)
        POP     YH
        POP     YL
        RJMP    _U(__addsf3)
2:
        CLR     rA3
        CLR     rA2
        CLR     rA1
        CLR     rA0
10:
        CPI     YL,0
        CPC     YL,YH
        BREQ    1f
        ST      Y+,rB0
        ST      Y+,rB1
        ST      Y+,rB2
        ST      Y+,rB3		; no fractional part
1:
        POP     YH
        POP     YL
        RJMP    _U(__fp_merge)	; rT0 must not be cleared : rAE=0 no rounding anyway

          ENDFUNC


