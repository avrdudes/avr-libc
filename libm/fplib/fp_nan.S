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
    fp_nan.S is part of     FPlib V 0.3.0       ported to avr-as
    for details see readme.fplib

 *----------------------------------------------------------------------------------------*/

#include "gasava.inc"
#include "fplib.inc"

          TEXT_SEG(fplib, __fp_nan)
          FUNCTION(__fp_nan)

GLOBAL(__fp_nanEDOM)
 #ifdef __ERRNO__
   LDI     rA3,EDOM		; the most used errno value
   RJMP    __fp_nan
 #endif
GLOBAL(__fp_nanERANGE)
 #ifdef __ERRNO__
   LDI     rA3,ERANGE		; the most used errno value
 #endif
GLOBAL(__fp_nan)		; -> -NaN
 #ifdef __ERRNO__
   STS     _errno,rA3
   #if __ERRNO__ == 2
     STS     _errno+1,rT1c
   #endif
 #endif
GLOBAL(__fp_nanx)		;
    LDI     rA3,0xFF
    LDI     rA2,0xC0
    RET

          ENDFUNC


