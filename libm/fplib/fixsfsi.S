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
   brcs    ___fixsfsi_zero  ; fabs(x) < 1.0, shift count >= 32
   LDI     rTI0,0x7F+31
   SUB     rTI0,rA3
   MOV     rA3,rA2
   MOV     rA2,rA1
   MOV     rA1,rA0
   MOV     rA0,rAE
   RJMP    ___fixsfsi_10

 ___fixsfsi_zero:
   rjmp    _U(__fp_zero)

 ___fixsfsi_05:
   LSR    rA3
   ROR    rA2
   ROR    rA1
   ROR    rA0
 ___fixsfsi_10:
   SUBI   rTI0,1
   BRCC   ___fixsfsi_05
   BRTC   no_neg
   /* TEXT_SEG(fp_lneg) */
GLOBAL(__fp_lneg)
   COM     rA3
   COM     rA2
   COM     rA1
   NEG     rA0
   SBCI    rA1,0xFF
   SBCI    rA2,0xFF
   SBCI    rA3,0xFF
 no_neg:
   RET

          ENDFUNC


