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
    divsf3.S is part of     FPlib V 0.3.0       ported to avr-as
    for details see readme.fplib

 *----------------------------------------------------------------------------------------
 *
 * divides two numbers R = A / B
 * stored in T by ___divsf3
 * A  rA3 : rA2:rA1:rA0
 * B  rB3 : rB2:rB1:rB0
 * R  rA3 : rA2:rA1:rA0
 */

#include "gasava.inc"
#include "fplib.inc"

          TEXT_SEG(fplib, __divsf3)
          FUNCTION(inverse)

GLOBAL(inverse)
     MOV     rB3,rA3
     MOV     rB2,rA2
     MOV     rB1,rA1
     MOV     rB0,rA0
     LDI     rA3,0x3F
     LDI     rA2,0x80
     CLR     rA1
     CLR     rA0           ; 1.0 / x
GLOBAL(__divsf3)
     RCALL   _U(__fp_split3)
     RCALL   _U(__divsf3x)
     RJMP    _U(__fp_merge)

          ENDFUNC


