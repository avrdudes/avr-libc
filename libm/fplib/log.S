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
    log.S is part of     FPlib V 0.3.0       ported to avr-as
    for details see readme.fplib

 *----------------------------------------------------------------------------------------
 *
 *	A = log(A)
 *
 * log( x ) = exponent(x)*ln(2) + log(matissae(x))
 *
 *
 * x = [0.5,1.0[
 * z = (x*sqrt(2)-1)/(x*sqrt(2)+1) = (x - 1/sqrt(2)/(x+1/sqrt(2))
 * log( x ) =  ((F2 * z*z + F1)*z*z + F0)*z - ln(sqrt(2))
 *             P0 + x (P1 + x * (P2 + x * (P3 + x * (P4 + x * P5))))
 *          =  -----------------------------------------------------
 *             Q0 + x (Q1 + x * (Q2 + x * (Q3 + x * (Q4 + x * Q5))))
 * P0 = -3.42819 [C0 5B 67 82]
 * P1 = -7.05769 [C0 E1 D8 A1]
 * P2 = -20.5693 [C1 A4 8D D9]
 * P3 = 9.48417  [41 17 BF 24]
 * P4 = 6.09923  [40 C3 2C E2]
 * P5 = 15.4718  [41 77 8C 4F]
 * Q0 = 1        [3F 80 00 00]
 * Q1 = 7.07107  [40 E2 46 30]
 * Q2 = 20       [41 A0 00 00]
 * Q3 = 28.2843  [41 E2 46 32]
 * Q4 = 20       [41 A0 00 01]
 * Q5 = 5.65685  [40 B5 04 F4]
 */

#if !defined(DOXYGEN)

#include "gasava.inc"
#include "fplib.inc"

          TEXT_SEG(fplib, log)
          FUNCTION(log)

GLOBAL(log)
   SBRC  rA3,7
   RJMP  _U(__fp_nanEDOM)	; A < 0 argument range error
 _log_10:
   RCALL _U(__fp_split1)
   TST   rA3
   BRNE  _log_20
   RJMP  _U(__fp_nanEDOM)	; A == 0 argument range error

 _log_20:
   PUSH  rS0
   PUSH  rS1
   PUSH  rS2
   PUSH  rS3
   MOV   rS3,rA3
   LDI   rA3,0x3F		; load 0x7E as exponent =>
   ANDI  rA2,0x7F		; 2^-1 * 1.m = [0.5..1.0[

   LDI     ZL,LOW(table_log)
   LDI     ZH,HIGH(table_log)
   RCALL   _U(fp_powerseries)

   MOV    rT0,rS3
   MOV    rS3,rA3
   MOV    rS2,rA2
   MOV    rS1,rA1
   MOV    rS0,rA0
   MOV    rA0,rT0
   SUBI   rA0,0x7E
   SBC    rA1,rA1
   MOV    rA2,rA1
   MOV    rA3,rA1
   RCALL  _U(__floatsisf)
   LDI    rB3,0x3F
   LDI    rB2,0x31
   LDI    rB1,0x72
   LDI    rB0,0x18		; ln(2)
   RCALL  _U(__mulsf3)
   MOV    rB3,rS3
   MOV    rB2,rS2
   MOV    rB1,rS1
   MOV    rB0,rS0
   POP    rS3
   POP    rS2
   POP    rS1
   POP    rS0
   RJMP   _U(__addsf3)

          ENDFUNC

	PGM_SECTION

	/* these constants are *no* IEEE float values:	exponent unpacked allready
	 *						first byte : exponent
	 *						2nd byte   : msb of mantissa with sign as bit 7
	 * 						3rd & 4th byte : mantissa
	 */

 table_log:
   DCB 5		; no of table entries - 1 (preload value)
   DCB 0x81,0x35,0x04,0xF4 /* Q5 = 5.65685   */
   DCB 0x83,0x20,0x00,0x01 /* Q4 = 20        */
   DCB 0x83,0x62,0x46,0x32 /* Q3 = 28.2843   */
   DCB 0x83,0x20,0x00,0x00 /* Q2 = 20        */
   DCB 0x81,0x62,0x46,0x30 /* Q1 = 7.07107   */
   DCB 0x7F,0x00,0x00,0x00 /* Q0 = 1         */
   DCB 5
   DCB 0x82,0x77,0x8C,0x4F /* P5 = 15.4718   */
   DCB 0x81,0x43,0x2C,0xE2 /* P4 = 6.09923   */
   DCB 0x82,0x17,0xBF,0x24 /* P3 = 9.48417   */
   DCB 0x83,0xA4,0x8D,0xD9 /* P2 = -20.5693  */
   DCB 0x81,0xE1,0xD8,0xA1 /* P1 = -7.05769  */
   DCB 0x80,0xDB,0x67,0x82 /* P0 = -3.42819  */

#endif /* not DOXYGEN */
