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
    sinh.S is part of     FPlib V 0.3.0       ported to avr-as
    for details see readme.fplib

 *----------------------------------------------------------------------------------------
 *
 *
 *	A = sinh(A) = 1/2 ( exp(A) - exp(-A) )
 */

#include "gasava.inc"
#include "fplib.inc"

          TEXT_SEG(fplib, sinh)
          FUNCTION(sinh)

GLOBAL(sinh)
   RCALL _U(exp)
   PUSH  rA0
   PUSH  rA1
   PUSH  rA2
   PUSH  rA3
   RCALL _U(inverse)
   ORI   rA3,0x80		; exp(-x) = -exp(-x)
   POP   rB3
   POP   rB2
   POP   rB1
   POP   rB0
   RCALL _U(__addsf3)		; -exp(-x) + exp(x)
			; check for NaN
   LDI   rB2,0xFF		;
   LDI   rB3,0xFF		; decrement exponent by 1 = * 0.5
   RJMP  _U(ldexp)

          ENDFUNC


