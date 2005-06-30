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
    fp_split.S is part of     FPlib V 0.3.0       ported to avr-as
    for details see readme.fplib

 *----------------------------------------------------------------------------------------------
 * split up in  exponent : fraction   : fraction extention
 *          x   rA3        rA2:rA1:rA0: rAE
 *          y   rB3        rB2:rB1:rB0: rBE
 * signs are lost !
 *
 * if defined FPLIB_CHECK_FOR_NAN
 * does not return to calling function in case of NaN !
 * -> call fp_split before pushing locals to stack!!!
 *
 * split 2 incoming operands , x and y, y first
 */

#if !defined(DOXYGEN)

#include "gasava.inc"
#include "macros.inc"
#include "fplib.inc"

          TEXT_SEG(fplib, __fp_split)
          FUNCTION(__fp_split3)

GLOBAL(__fp_split3)
    MOV     rT0,rB3           ;
    EOR     rT0,rA3           ;
    BST     rT0,7             ; different signs : T = 1
GLOBAL(__fp_split2)
    ADD     rB2,rB2           ; MSB of exponent to carry
    adc     rB3,rB3           ; whole exponent in rB3, sign in C
    CPI     rB3,0xFF          ; check for NAN
    BREQ    fp_split_nan      ; if no jump then C as hidden one is set
    CLR     rBE            ; clear fraction extension
    cp      rBE,rB3        ; set C if nonzero exponent.  -MM 2000-11-25
    brcs    1f
    ldi     rB3,1          ; zero exponent really means 1 with hidden bit = 0
1:
    ROR     rB2            ; sets hidden bit
GLOBAL(__fp_split1)
    ADD     rA2,rA2        ; MSB of exponent to carry
    adc     rA3,rA3        ; whole exponent in rA3, sign in C
    CPI     rA3,0xFF       ; if no jump then C as hidden one is set
    BREQ    fp_split_nan
    CLR     rAE            ; clear fraction extension
    cp      rAE,rA3        ; set C if nonzero exponent.  -MM 2000-11-25
    brcs    1f
    ldi     rA3,1          ; zero exponent really means 1 with hidden bit = 0
1:
    ROR     rA2            ; sets hidden bit
    RET
 fp_split_nan:
    POP     rA3
    POP     rA3            ; pop return adress
 #ifdef __ERRNO__
    LDI     rA3,EDOM       ; NaN is argument domain error !
 #endif
    clr     r1
    RJMP    _U(__fp_nan)

          ENDFUNC

#endif /* not DOXYGEN */
