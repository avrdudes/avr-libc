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
    floor.S is part of     FPlib V 0.3.0       ported to avr-as
    for details see readme.fplib

 *----------------------------------------------------------------------------------------
 *	A = floor(A)
 *
 * gr˜òter ganzzahliger Wert, der nicht gr˜òer als arg ist
 * fÅr X > 4B 7F FF FF : X = X (Zahlen haben keinen Bruchteil mehr)
 *     X >= 0            X = (float)(long)X
 *     X <  0 then
 *      X == (float)(long)X   X = X (Zahlen hat keinen Bruchteil)
 *      X != (float)(long)X   X = (float)(long)X-1 (Zahlen hat einen Bruchteil)
 */

#include "gasava.inc"
#include "macros.inc"
#include "fplib.inc"

          TEXT_SEG(fplib, floor)
          FUNCTION(floor)

GLOBAL(floor)
    BST     rA3,7
    RCALL   _U(__fp_split1)  ; split up in sign : exp : fraction   : fraction extention
                                              ;          x  T      R19   R18:rSI0:R16: R1
    CPI     rA3,0x7F         ; Exp >= 0x7F -> arg >= 1.0
    BRCC    3f
    BRTS    1f               ; |arg| < 1.0 -> floor = / 0.0  fÅr X >= 0.0
    RJMP    _U(__fp_zero)    ;                           \ -1.0 fÅr X <  0.0
1:
    LDI     rA3,0xBF
    LDI     rA2,0x80
    CLR     rA1
    CLR     rA0
    RET
2:
    LSR     rA2              ;
    ROR     rA1              ; shift out fractional bits to the right
    ROR     rA0              ; until mantissa is a normalized unsigned
    adc     rAE,rT1c         ; rAE cleard by fp_split1, rT1c = __zero_reg__
    INC     rA3
3:                           ; |arg| >= 1.0
    CPI     rA3,0x96         ;
    BRCS    2b

    BRTC    1f               ; LSB now is exactely 1
    TST     rAE
    BREQ    1f
    SUBI    rA0,0xFF
    SBCI    rA1,0xFF
    SBCI    rA2,0xFF
1:
    CLR     rAE              ; rT0 must not be cleared : rAE=0 no rounding anyway
    RJMP    _U(__fp_merge)

          ENDFUNC


