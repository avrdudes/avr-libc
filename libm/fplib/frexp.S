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
    frexp.S is part of     FPlib V 0.3.0       ported to avr-as
    for details see readme.fplib

 *----------------------------------------------------------------------------------------
 *
 *	A = mantissa(A)  *integ = exponent(A)
 * e.g.
 * int integ
 * double fract = frexp( 3.45, &integ ) = frexp ( 2^2 * 0.8625 )
 * -> fract = 0.8625; *integ = 2
 *
 * fract(0) -> 0/0
 */

#if !defined(DOXYGEN)

#include "gasava.inc"
#include "fplib.inc"

          TEXT_SEG(fplib, frexp)
          FUNCTION(frexp)

GLOBAL(frexp)
        MOV     ZH,rPH
        MOV     ZL,rPL
        BST     rA3,7

        RCALL   _U(__fp_split1)	;
        TST     rA3
        BREQ    _frexp_200
        SUBI    rA3,0x7E	; 0.5 -> 0.5 * 2^0
				; 1.0 -> 0.5 * 2^1
        SBC     rB0,rB0		; sign expand rA3
        ST      Z,rA3
        STD     Z+1,rB0

        ANDI    rA2,0x7F	; mantissa is normalized
        LDI     rA3,0x3F	; exponent for 0.5
        BLD     rA3,7
        RET

 _frexp_200:
        ST      Z,rA3
        STD     Z+1,rT1c
        RJMP    _U(__fp_zero)	; frexp(0) returns 0 not A = 0x00800000 of fp_split1

          ENDFUNC

#endif /* not DOXYGEN */
