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
    floor.S is part of     FPlib V 0.3.0       ported to avr-as
    for details see readme.fplib

 *----------------------------------------------------------------------------------------
 *	A = floor(A)
 *
 * gr˜òter ganzzahliger Wert, der nicht gr˜òer als arg ist
 * fÅr X > 4B 7F FF FF : X = X (Zahlen haben keinen Bruchteil mehr)
 *     X >= 0            X = (float)(long)X
 *     X <  0 then
 *      X == (float)(long)X   X = X (Zahlen hat keinen Bruchteil)
 *      X != (float)(long)X   X = (float)(long)X-1 (Zahlen hat einen Bruchteil)
 */

#include "gasava.inc"
#include "fplib.inc"

          TEXT_SEG(fplib, floor)
          FUNCTION(floor)

GLOBAL(floor)
    BST     rA3,7
    RCALL   _U(__fp_split1)  ; split up in sign : exp : fraction   : fraction extention
                                              ;          x  T      R19   R18:rSI0:R16: R1
    CPI     rA3,0x7F         ; Exp >= 0x7F -> arg >= 1.0
    BRCC    _floor_100       ;
    BRTS    _floor_01        ; |arg| < 1.0 -> floor = / 0.0  fÅr X >= 0.0
    RJMP    _U(__fp_zero)    ;                           \ -1.0 fÅr X <  0.0
 _floor_01:
    LDI     rA3,0xBF
    LDI     rA2,0x80
    CLR     rA1
    CLR     rA0
    RET
 _floor_100_1:
    LSR     rA2              ;
    ROR     rA1              ; shift out fractional bits to the right
    ROR     rA0              ; until mantissa is a normalized unsigned
    adc     rAE,rT1c         ; rAE cleard by fp_split1, rT1c = __zero_reg__
    INC     rA3
 _floor_100: ; |arg| >= 1.0
    CPI     rA3,0x96         ;
    BRCS    _floor_100_1     ;
 _floor_200:
    BRTC    _floor_300       ;      LSB now is exactely 1
    TST     rAE
    BREQ    _floor_300
    SUBI    rA0,0xFF
    SBCI    rA1,0xFF
    SBCI    rA2,0xFF
 _floor_300:
    CLR     rAE              ; rT0 must not be cleared : rAE=0 no rounding anyway
    RJMP    _U(__fp_merge)

          ENDFUNC


