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
    fp_merge.S is part of     FPlib V 0.3.0       ported to avr-as
    for details see readme.fplib

 *------------------------------------------------------------------------------------------
 * merge up in sign : exponent : fraction   : fraction extention
 *          x     T   rA3        rA2:rA1:rA0:rAE
 */

#if !defined(DOXYGEN)

#include "gasava.inc"
#include "fplib.inc"

          TEXT_SEG(fplib, __fp_merge)
          FUNCTION(__fp_merge)

1:
    DEC     rA3
    ADD     rAE,rAE
    adc     rA0,rA0
    adc     rA1,rA1
    adc     rA2,rA2
		; normalize (?) does any split number comes here unnormal? ; yes, _floor, _ceil!
GLOBAL(__fp_merge)
    CLR     rT1c           ; clr rT1c on all return paths
    TST     rA3            ; exponent == 0
    BREQ    3f           ; underflow
    TST     rA2
    BRPL    1b           ; shift left until MSB set

    CPI     rA3,0xFF
    BREQ    2f           ; keep exp == 0xFF, no rounding

 ;  if rAE == 0x80 (exactely 0.5 LSB, half way between two numbers )
 ;  choose the one which makes the lsb of the answer 0.
 ;  what about rAE:rr1:rr0 of mul
    ADD   rAE,rAE
    BRCC  2f                 ; no LSB : round to lower number
    BRNE  1f                 ; rAE > 0x80 : round to upper number
    TST   rT0
    BRNE  1f                 ; rAE=0x80:NN:MM , rT1c = NN | MM
    SBRS  rA0,0              ; R1 == 0x80 : round to even
    RJMP  2f                 ;
1:
    SUBI  rA0,0xFF
    SBCI  rA1,0xFF
    SBCI  rA2,0xFF
    SBCI  rA3,0xFF
2:                           ; pack expanded FP number
    ROL     rA2              ; MSB is hidden 1
    ROR     rA3
    ROR     rA2
    BLD     rA3,7            ; get sign
    RET
3:
    RJMP    _U(__fp_zero)   ; merge segments

          ENDFUNC

#endif /* not DOXYGEN */
