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
    pow.S is part of     FPlib V 0.3.0       ported to avr-as
    for details see readme.fplib

 *----------------------------------------------------------------------------------------
 *
 *
 *	A = pow(x,y) = exp( log(x)*y )  | x > 0
 */

#include "gasava.inc"
#include "fplib.inc"

          TEXT_SEG(fplib, pow)
          FUNCTION(pow)

GLOBAL(pow)
   TST   rB3
   BREQ  10f		; x ^ 0 = 1.0
   TST   rA3
   BRMI  1f
   BREQ  10f

   PUSH  rB3
   PUSH  rB2
   PUSH  rB1
   PUSH  rB0
   RCALL _U(log)
   POP   rB0
   POP   rB1
   POP   rB2
   POP   rB3
   RCALL _U(__mulsf3)
   RJMP  _U(exp)

1:
	/* x < 0 -> no rational power allowed
	 *          check if B is an integer number
	 * if yes then pow(x,y) =
         */
   PUSH  rA3
   PUSH  rA2
   PUSH  rA1
   PUSH  rA0
   PUSH  rB3
   PUSH  rB2
   PUSH  rB1
   PUSH  rB0
   MOV   rA3,rB3
   MOV   rA2,rB2
   MOV   rA1,rB1
   MOV   rA0,rB0
   RCALL _U(__fixsfsi)

   RCALL _U(__subsf3)
   CP    rA3,rT1c
   CPC   rA2,rT1c
   CPC   rA1,rT1c
   CPC   rA0,rT1c
   POP   rB0
   POP   rB1
   POP   rB2
   POP   rB3
   POP   rA0
   POP   rA1
   POP   rA2
   POP   rA3
   BREQ  2f
   ANDI  rA3,0x7F
   SUBI  rB3,0x80
   RCALL 1b
   SUBI  rB3,0x80

2:
   RJMP  _U(__fp_nanEDOM)

10:
   LDI   rA3,0x3F
   LDI   rA2,0x80
   CLR   rA1
   CLR   rA0
   RET

          ENDFUNC


