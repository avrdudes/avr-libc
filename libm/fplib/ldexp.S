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
    ldexp.S is part of     FPlib V 0.3.0       ported to avr-as
    for details see readme.fplib

 *----------------------------------------------------------------------------------------
 *
 * A = 2^exp * x
 * e.g.
 * double y = ldexp( 3.45, 2 ) = 2^2 * 3.45 = 13.8
 */

#if !defined(DOXYGEN)

#include "gasava.inc"
#include "fplib.inc"

          TEXT_SEG(fplib, ldexp)
          FUNCTION(ldexp)

GLOBAL(ldexp)
        BST     rA3,7
        RCALL   _U(__fp_split1)		; clears rAE
        TST     rA3			;
        BREQ    _ldexp_01		; 2^x*0 = 0
        CPI     rPH,0xFF
        BREQ    _ldexp_10		; negative
        TST     rPH
        BREQ    _ldexp_10
				; overflow or underflow
 _dlexp_00:
        BRPL    _ldexp_NaN		; overflow
 _ldexp_01:
        RJMP    _U(__fp_zero)
 _ldexp_NaN:
        RJMP    _U(__fp_nanERANGE)	; overflow

 _ldexp_10:
        ADD     rA3,rPL
        adc     rT1c,rPH		;
				; check for overflow
        BRNE    _ldexp_20
 _ldexp_20:
        RJMP    _U(__fp_merge)		; rT0 must not be cleared : rAE=0 no rounding anyway

          ENDFUNC

#endif /* not DOXYGEN */
