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
    tanh.S is part of     FPlib V 0.3.0       ported to avr-as
    for details see readme.fplib

 *----------------------------------------------------------------------------------------
 *
 * A = tanh(A)
 *
 * tanh( x ) = sinh(x)/cosh(x)
 *             (exp(x) - exp(-x))     1 - exp(-2x)   (exp(2x) - 1
 *           = ------------------- = ------------- = -------------
 *             (exp(x) + exp(-x)) =   1 + exp(-2x)   (exp(2x) + 1
 *
 * if exp(x) +- exp(-x) == exp(x) => exp(2x) +- 1 == exp(2x) => exp(2x) >= 2^24 -> x = ln(2^24)/2
 */

#if !defined(DOXYGEN)

#include "gasava.inc"
#include "macros.inc"
#include "fplib.inc"

          TEXT_SEG(fplib, tanh)
          FUNCTION(tanh)

GLOBAL(tanh)
	/* check for x > 8.3177661895751953 [41051592]
	 */
   BST   rA3,7
   ANDI  rA3,0x7F
   LDI   rB3,0x41
   LDI   rB2,0x05
   LDI   rB1,0x15
   CPI   rA0,0x92+1
   CPC   rA1,rB1
   CPC   rA2,rB2
   CPC   rA3,rB3	; compare with 8.3177661895751953 = | ln(2^24)/2 |
   BRCS  1f
   LDI   rA3,0x3F
   LDI   rA2,0x80
   LDI   rA1,0x00
   LDI   rA0,0x00 	; load 1
   BLD   rA3,7		; if x positivive _tanh(x) = 1
   RET

1:
   BLD   rA3,7

   PUSH  rA0			/* LDI    rB3,1                 */
   PUSH  rA1			/* RCALL  _ldexp    ; x -> 2x   */
   PUSH  rA2			/*                              */
   PUSH  rA3			/* RCALL  _exp                  */
   RCALL _U(cosh)		/* PUSH   rA0                   */
   POP   rB3			/* PUSH   rA1                   */
   POP   rB2			/* PUSH   rA2                   */
   POP   rB1			/* PUSH   rA3                   */
   POP   rB0			/* CLR    rB0                   */
   PUSH  rA3			/* CLR    rB1                   */
   PUSH  rA2			/* LDI    rB2,0x80              */
   PUSH  rA1			/* LDI    rB3,0x3F ; B = 1.0    */
   PUSH  rA0			/* RCALL  ___addsf3              */
   MOV   rA3,rB3		/* POP    rB3                   */
   MOV   rA2,rB2		/* POP    rB2                   */
   MOV   rA1,rB1		/* POP    rB1                   */
   MOV   rA0,rB0		/* POP    rB0  ; B = exp(2x)    */
   RCALL _U(sinh)		/* PUSH   rA0                   */
   POP   rB0			/* PUSH   rA1                   */
   POP   rB1			/* PUSH   rA2                   */
   POP   rB2			/* PUSH   rA3                   */
   POP   rB3			/* CLR    rA0                   */
   RJMP  _U(__divsf3)		/* CLR    rA1                   */
				/* LDI    rA2,0x80              */
				/* LDI    rA3,0xBF ; A = -1.0   */
				/* RCALL  ___addsf3              */
				/* POP    rB3                   */
				/* POP    rB2                   */
				/* POP    rB1                   */
				/* POP    rB0  ; B = exp(2x)+1  */
				/* RJMP  ___divsf3               */

          ENDFUNC

#endif /* not DOXYGEN */
