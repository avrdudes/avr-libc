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
    negsf2.S is part of     FPlib V 0.3.0       ported to avr-as
    for details see readme.fplib

 *----------------------------------------------------------------------------------------
 * negate  A = -A
 */

#include "gasava.inc"
#include "fplib.inc"

          TEXT_SEG(fplib, __negsf2)
          FUNCTION(__negsf2)

GLOBAL(__negsf2)
#if 0 /* XXX why so complicated?  Just flip the sign bit... -MM 2000-11-18 */
     ADD     rA2,rA2
     adc     rA3,rA3
     BREQ    ___negsf2_100
     SBC     rT0,rT0        ; if C = 1 (negative) -> rT0 = 0xFF = ~0
                            ; if C = 0 (positive) -> rT0 = 0x00 = ~0xFF
     COM     rT0
     ROR     rT0
 ___negsf2_100: ; zero, negate
     ROR     rA3
     ROR     rA2
#else
     ldi     rTI0,0x80
     eor     rA3,rTI0
#endif
     RET

          ENDFUNC


