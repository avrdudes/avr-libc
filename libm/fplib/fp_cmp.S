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
    fp_cmp.S is part of     FPlib V 0.3.0       ported to avr-as
    for details see readme.fplib

 *----------------------------------------------------------------------------------------
 */

#include "gasava.inc"
#include "fplib.inc"

/* GCC expects all these functions to return -1/0/1 as for __cmpsf2 -
   compare with gcc/config/fp-bit.c (the only difference is with NaNs
   where we should always return nonzero for EQ/NE, -1 for GT/GE,
   1 for LT/LE).  -MM 2000-11-18 */

          TEXT_SEG(fplib, __fp_cmp)

          FUNCTION(__eqsf2)

GLOBAL(__eqsf2)                  ; equal : true, if Z set (and T clear)
GLOBAL(__nesf2)
GLOBAL(__ltsf2)
GLOBAL(__lesf2)
    rcall   .fp_cmp
    brts    .fp_cmp_gt  ; return 1 (not equal / false) if we got a NaN
    rjmp    .fp_cmp_ret

          ENDFUNC

          FUNCTION(__gtsf2)

GLOBAL(__gtsf2)                  ; greater than : true, if Z clear and C clear
GLOBAL(__gesf2)
    rcall   .fp_cmp
    brts    .fp_cmp_lt
    rjmp    .fp_cmp_ret

          ENDFUNC

          FUNCTION(__cmpsf2)

GLOBAL(__cmpsf2)  ; returns 1 for A > B ; 0 for A == B ; -1 for A < B ; NaN ?
    rcall   .fp_cmp
.fp_cmp_ret:
    breq    .fp_cmp_eq
    brcc    .fp_cmp_gt
.fp_cmp_lt:
    ldi     retByte,0xFF
    ret
.fp_cmp_eq:
    ldi     retByte,0x00
    ret
.fp_cmp_gt:
    ldi     retByte,0x01
    ret

          ENDFUNC

/*------------------------------------------------------------------------
 * compare  A == B
 *                                   { C = 1 Z = 0 T = 0 A < B
 * compares x to y and sets flags :  { C = 0 Z = 1 T = 0 A == B
 *                                   { C = 0 Z = 0 T = 0 A > B,
 *                                   {             T = 1 NAN
 */

          .func .fp_cmp

.fp_cmp:
    BST    rA3,7
    MOV    rT0,rA3
    EOR    rT0,rB3
    BLD    rT0,0		; rT0.7 = sign(A) EOR sign(B), rT0.0 = sign(A)
    SET
    RCALL  _U(__fp_split2)	; does not return on NaN (T set then)
    CLT
    SBRC   rT0,7
    RJMP   .fp_cmp_10		; different signs

    ; same signs : compare
    CP     rA0,rB0
    CPC    rA1,rB1
    CPC    rA2,rB2
    CPC    rA3,rB3		; A - B ; set Z if equal, sets C if A < B (unsigned)
    BREQ   .fp_cmp_20
    BRCC   .fp_cmp_10	; A > B (unsigned)
    COM    rT0		; A < B (unsigned)
.fp_cmp_10:			; different signs (-0 < +0!)
		;  sign(A) == 0 (positive) -> A > B, C = 0 , Z = 0
		;  sign(A) == 1 (negative) -> A < B, C = 1 , Z = 0
    ROR    rT0		; C = sign(A)
    CLZ			; Z = 0
.fp_cmp_20:
    ret

          ENDFUNC

