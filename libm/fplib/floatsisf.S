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

/*
    floatsisf.S is part of     FPlib V 0.3.0       ported to avr-as
    for details see readme.fplib

 *------------------------------------------------------------------------------------------
 * data conversion section
 *------------------------------------------------------------------------------------------
 * A = (float)(unsigned long)A
 */

#if !defined(DOXYGEN)

#include "gasava.inc"
#include "fplib.inc"

          TEXT_SEG(fplib, __floatsisf)
          FUNCTION(__floatunssisf)

GLOBAL(__floatunssisf)           ; - convert signed long to float
           CLT                   ; fp_merge expects T:sign
           RJMP    ___floatsisf_10

/*-------------------------------------------------------------------------------------------
 * A = (float)(signed long)A
 */

GLOBAL(__floatsisf)              ; - convert signed long to float
           BST     rA3,7         ; fp_merge expects T:sign
           BRTC    ___floatsisf_10
           RCALL   _U(__fp_lneg)
 ___floatsisf_10:
           MOV     rAE,rA0       ; rA2::rA0:rAE mantissa
           MOV     rA0,rA1
           MOV     rA1,rA2
           MOV     rA2,rA3       ; rA3:exponent
           LDI     rA3,0x7F+31   ; 1L = 00 00 00 01   =>
                                 ; 0:7F+31:00 00 00 01 =>
                                 ; 0:7F:80 00 00       => 3F 80 00 00
           CLR     rT0           ; clear extended rounding precision
           RJMP    _U(__fp_merge)

          ENDFUNC

#endif /* not DOXYGEN */
