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
    floatsisf.S is part of     FPlib V 0.3.0       ported to avr-as
    for details see readme.fplib

 *------------------------------------------------------------------------------------------
 * data conversion section
 *------------------------------------------------------------------------------------------
 * A = (float)(unsigned long)A
 */

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

