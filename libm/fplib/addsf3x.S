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
    addsf3x.S is part of     FPlib V 0.3.0       ported to avr-as
    for details see readme.fplib

 *----------------------------------------------------------------------------------------
 *
 *--- addition kernel : used by other high level functions
 * add two extended numbers RX = AX + BX
 * AX  rA3 : rA2:rA1:rA0:rAE sign stored in rT1c.7, rAE cleared by fp_split1
 * BX  rB3 : rB2:rB1:rB0:rBE sign(A) ^ sign(B) stored in T
 * RX  rA3 : rA2:rA1:rA0:rAE resulting sign stored in rT1c.7 (rT1c.7 complemented, if B > A)
 */

#if !defined(DOXYGEN)

#include "gasava.inc"
#include "macros.inc"
#include "fplib.inc"

          TEXT_SEG(fplib, __addsf3x)
          FUNCTION(__addsf3x)

GLOBAL(__addsf3x)
    CP      rAE,rBE         ; some high level functions use ___addsf3x
    CPC     rA0,rB0         ; directely with preset rAE,rBE
    CPC     rA1,rB1         ;
    CPC     rA2,rB2         ;
    CPC     rA3,rB3         ; A - B
    BREQ    300f
    BRCC    100f            ; A >= B

    BRTC    1f              ; if T clear the A & B of same sign
    COM     rT1c            ; else complement sign
1:
    MOV     rT0,rAE
    MOV     rAE,rBE
    MOV     rBE,rT0
    MOV     rT0,rA0
    MOV     rA0,rB0
    MOV     rB0,rT0
    MOV     rT0,rA1
    MOV     rA1,rB1
    MOV     rB1,rT0
    MOV     rT0,rA2
    MOV     rA2,rB2
    MOV     rB2,rT0
    MOV     rT0,rA3
    MOV     rA3,rB3
    MOV     rB3,rT0

 ; now A > B
100:                           ; denormalize lower mantissa until exponents are the same
    CLR     rTI0               ; holds mantissa extension beyond rBE
    TST     rB3                ;
    BREQ    50f                ; A + 0

    SUB     rB3,rA3            ; get difference, rB3 negative
    BREQ    2f                 ; same : no shift
    CPI     rB3,LOW(-25)       ; no significant digits left after shift
    BRCS    50f                ;
1:                                                     ;
    LSR     rB2                                                      ;
    ROR     rB1                                                      ;
    ROR     rB0                                                      ;
    ROR     rBE                ; fraction >> 1                       ;
    SBCI    rTI0,0             ; mark if any overflow beyond rBE     ;
    INC     rB3                ; exponent ++
    BRNE    1b

2:
    BRTS    200f               ; branch if different sign
    ADD     rAE,rBE            ; maybe rAE and rBE are preset
    adc     rA0,rB0            ;
    adc     rA1,rB1            ;
    adc     rA2,rB2            ; add both mantissae
    BRCC    50f                ; no fraction overflow if C = 0
    ROR     rA2                ; correct overflow
    ROR     rA1
    ROR     rA0
    ROR     rAE               ; fraction >> 1
    SBCI    rTI0,0            ; mark if any overflow beyond rBE
    INC     rA3               ; exponent++
50:
    BST     rT1c,7
    MOV     rT0,rTI0
    RET

200:
    SUB     rAE,rTI0          ; extended mantissa : 0 - lost bits
    CLR     rAE
    SBC     rAE,rBE           ; subtract the lower from the larger
    SBC     rA0,rB0           ; extended mantissa : if rBE == 0x80 -> rAE = 0x80
    SBC     rA1,rB1           ;
    SBC     rA2,rB2           ;
    RJMP    50b               ;

 ; A == B
300:
    BRTC    100b              ; same sign, test for zero & add
    RJMP    _U(__fp_zerox)     ; different signs

          ENDFUNC

#endif /* not DOXYGEN */
