/*  -*- Mode: Asm -*-  */

/* Copyright (c) 2002  Michael Stumpf  <Michael.Stumpf@t-online.de>

   This file is free software; you can redistribute it and/or modify it under
   the terms of the GNU General Public License as published by the Free
   Software Foundation; either version 2, or (at your option) any later
   version.

   In addition to the permissions in the GNU General Public License, the
   author gives you unlimited permission to link the compiled version of this
   file into combinations with other programs, and to distribute those
   combinations without any restriction coming from the use of this file.
   (The General Public License restrictions do apply in other respects; for
   example, they cover modification of the file, and distribution when not
   linked into a combine executable.)

   This file is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
   FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
   more details. */

/*
    exp.S is part of     FPlib V 0.3.0       ported to avr-as
    for details see readme.fplib

 *----------------------------------------------------------------------------------------
 *
 *	A = exp(A)
 */

#include "gasava.inc"
#include "fplib.inc"

          TEXT_SEG(fplib, exp)
          FUNCTION(exp)

/* exp( x ) = 2^fract(x/ln2) * 2^(int(x/ln2))
 */

GLOBAL(exp)
   MOV   rT0,rA3
   TST   rA3
   BRMI  _exp_100
   LDI   rB3,0x42
   LDI   rB2,0xB1
   LDI   rB1,0x72
   CPI   rA0,0x18
   CPC   rA1,rB1
   CPC   rA2,rB2
   CPC   rA3,rB3		; compare with 88.72283935546875 = | ln(FLT_MAX) |
   BRCS  _exp_200		; no overflow
   RJMP  _U(__fp_nanERANGE)

 _exp_100: ; A < 0, check for underflow
   ANDI  rA3,0x7F
   LDI   rB3,0x42
   LDI   rB2,0xAE
   LDI   rB1,0xAC
   CPI   rA0,0x50
   CPC   rA1,rB1
   CPC   rA2,rB2
   CPC   rA3,rB3		; compare with 87.3365478515625 = | ln(FLT_MIN) |
   BRCS  _exp_200		; no underflow
   RJMP  _U(__fp_zero)

 _exp_200:
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
   RCALL   _U(fp_powerseries)

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
   RJMP   _exp_300
 _exp_200_1:
   LSR    rB2
   ROR    rB1
   ROR    rB0
   ROR    rB3
 _exp_300:
   DEC    rTI0
   BRPL   _exp_200_1
			; now rB2::rB0:rB3 = long integer (only rB3 should be set)
   MOV    rB2,rB3
   ADD    rB3,rB3
   SBC    rB3,rB3		; sign expand exponent
   RCALL  _U(ldexp)

   POP   rT0
   SBRC  rT0,7
   RJMP  _U(inverse)
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

