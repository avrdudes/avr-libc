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
    fixsfsi.S is part of     FPlib V 0.3.0       ported to avr-as
    for details see readme.fplib

 *------------------------------------------------------------------------------------------
 * data conversion section
 *------------------------------------------------------------------------------------------
 *
 * A = (long)A
 */

#include "gasava.inc"
#include "fplib.inc"

          TEXT_SEG(fplib, __fixsfsi)
          FUNCTION(__fixsfsi)

GLOBAL(__fixsfsi)
GLOBAL(__fixunssfsi)
   BST     rA3,7
   RCALL   _U(__fp_split1)
   cpi     rA3,0x7F
   brcs    1f		; fabs(x) < 1.0, shift count >= 32
   LDI     rTI0,0x7F+31
   SUB     rTI0,rA3
   MOV     rA3,rA2
   MOV     rA2,rA1
   MOV     rA1,rA0
   MOV     rA0,rAE
   RJMP    5f

1:
   rjmp    _U(__fp_zero)

2:
   LSR    rA3
   ROR    rA2
   ROR    rA1
   ROR    rA0
5:
   SUBI   rTI0,1
   BRCC   2b
   BRTC   1f
   /* TEXT_SEG(fp_lneg) */
GLOBAL(__fp_lneg)
   COM     rA3
   COM     rA2
   COM     rA1
   NEG     rA0
   SBCI    rA1,0xFF
   SBCI    rA2,0xFF
   SBCI    rA3,0xFF
1:
   RET

          ENDFUNC


