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
    fmod.S is part of     FPlib V 0.3.0       ported to avr-as
    for details see readme.fplib

 *----------------------------------------------------------------------------------------
 * A = remainder( A/B )
 */

#if !defined(DOXYGEN)

#include "gasava.inc"
#include "fplib.inc"

          TEXT_SEG(fplib, fmod)
          FUNCTION(fmod)

GLOBAL(fmod)
	/* fmod = x % y = x - (floor)(x/y)*y ??
	 *
	 * fmod   x  10.5     -10.5
	 * y   PI    1.075..  -1.075..
	 *    -PI    1.075..  -1.075..
	 */
    ANDI    rB3,0x7F	; fmod(x,y) = sgn(x) * fmod(|x|,|y|)
    TST     rB3		; -0 ?
    BRNE    _fmod_01
    TST     rB2
    BRMI    _fmod_01
    RJMP    _U(__fp_nanERANGE)
 _fmod_01:
    PUSH    rB0
    PUSH    rB1
    PUSH    rB2
    PUSH    rB3
    RCALL   _U(__divsf3)	; A = x/y
    CLR     rP4
    CLR     rP5			; point to NUL
    RCALL   _U(modf)		; A = fraction( x/y )
    POP     rB3
    POP     rB2
    POP     rB1
    POP     rB0			; B = y
    RJMP    _U(__mulsf3)	; A = y * fraction( x/y )

          ENDFUNC

#endif /* not DOXYGEN */
