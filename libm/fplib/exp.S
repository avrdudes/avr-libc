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
    exp.S is part of     FPlib V 0.3.0       ported to avr-as
    for details see readme.fplib

 *----------------------------------------------------------------------------------------
 *
 *	A = exp(A)
 */

#if !defined(DOXYGEN)

#include "gasava.inc"
#include "fplib.inc"

          TEXT_SEG(fplib, exp)
          FUNCTION(exp)

/* exp( x ) = 2^fract(x/ln2) * 2^(int(x/ln2))
 */

GLOBAL(exp)
   MOV   rT0,rA3
   TST   rA3
   BRMI  1f
   LDI   rB3,0x42
   LDI   rB2,0xB1
   LDI   rB1,0x72
   CPI   rA0,0x18
   CPC   rA1,rB1
   CPC   rA2,rB2
   CPC   rA3,rB3		; compare with 88.72283935546875 = | ln(FLT_MAX) |
   BRCS  2f			; no overflow
   RJMP  _U(__fp_nanERANGE)

1: ; A < 0, check for underflow
   ANDI  rA3,0x7F
   LDI   rB3,0x42
   LDI   rB2,0xAE
   LDI   rB1,0xAC
   CPI   rA0,0x50
   CPC   rA1,rB1
   CPC   rA2,rB2
   CPC   rA3,rB3		; compare with 87.3365478515625 = | ln(FLT_MIN) |
   BRCS  2f			; no underflow
   RJMP  _U(__fp_zero)

2:
   PUSH  rT0			; push sign only
   LDI   rB3,0x3F
   LDI   rB2,0xB8
   LDI   rB1,0xAA
   LDI   rB0,0x3B ; 1/ln(2)
   RCALL _U(__mulsf3)
   PUSH  rS0
   PUSH  rS1
   PUSH  rS2
   PUSH  rS3
   LDI   rB3,HIGH( 12 )		; memory mapped registers : _modf stores integer part to there
   LDI   rB2,LOW( 12 )		;
   RCALL _U(modf)		; split A into S0::S3 = int(A) and A = fract(A)

   LDI     ZL,LOW(table_exp)
   LDI     ZH,HIGH(table_exp)
   RCALL   _U(__fp_powerseries)

   MOV   rB3,rS0
   MOV   rB2,rS1		;
   MOV   rB1,rS2
   MOV   rB0,rS3		;
   POP   rS3
   POP   rS2
   POP   rS1
   POP   rS0			; load sign

			; transform B into an integer
   LDI     rTI0,0x7F+31
   ASR     rB2
   adc     rB2,rB2
   adc     rB3,rB3
   SUB     rTI0,rB3	;
   CLR     rB3
   ORI     rB2,0x80
   RJMP   2f
1:
   LSR    rB2
   ROR    rB1
   ROR    rB0
   ROR    rB3
2:
   DEC    rTI0
   BRPL   1b
			; now rB2::rB0:rB3 = long integer (only rB3 should be set)
   MOV    rB2,rB3
   ADD    rB3,rB3
   SBC    rB3,rB3		; sign expand exponent
   RCALL  _U(ldexp)

   POP   rT0
   SBRC  rT0,7
   RJMP  _U(__fp_inverse)
   RET

          ENDFUNC

	PGM_SECTION

	/* these constants are *no* IEEE float values:	exponent unpacked allready
	 *						first byte : exponent
	 *						2nd byte   : msb of mantissa with sign as bit 7
	 *						3rd & 4th byte : mantissa
	 */

 table_exp:  DCB 6 ; no of table entries - 1 (preload value)
             DCB 0x72, 0x65, 0x2C, 0x03     ; 0.000218555        E5 2C 02 FD 74 E4 30
             DCB 0x75, 0x22, 0x3B, 0x59     ; 0.00123773         A2 3B 59 0A 98 98 48
             DCB 0x78, 0x1E, 0xBA, 0xE0     ; 0.00968811         9E BA E0 18 C7 63 00
             DCB 0x7A, 0x63, 0x3B, 0xF4     ; 0.0554771          E3 3B F3 D9 EE 36 C8
             DCB 0x7C, 0x75, 0xFF, 0x4E     ; 0.240232           F5 FF 4D AD AC 35 08
             DCB 0x7E, 0x31, 0x72, 0x11     ; 0.693147           B1 72 11 69 BD 3D 90
             DCB 0x7F, 0x00, 0x00, 0x00     ; 1.0
             DCB 0x00

#endif /* not DOXYGEN */
