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
   BRCS  _tanh_00
   LDI   rA3,0x3F
   LDI   rA2,0x80
   LDI   rA1,0x00
   LDI   rA0,0x00 	; load 1
   BLD   rA3,7		; if x positivive _tanh(x) = 1
   RET

 _tanh_00:
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
