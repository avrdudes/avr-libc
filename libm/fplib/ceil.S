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
    ceil.S is part of     FPlib V 0.3.0       ported to avr-as
    for details see readme.fplib

 *----------------------------------------------------------------------------------------
 *
 *	A = ceil(A)
 *
 * gr˜òter ganzzahliger Wert, der nicht kleiner als arg ist
 * fÅr X > 4B 7F FF FF : X = X (Zahlen haben keinen Bruchteil mehr)
 *     X >= 0
 *      X == (float)(long)X   X = X (Zahlen hat keinen Bruchteil)
 *      X != (float)(long)X   X = (float)(long)X+1 (Zahlen hat einen Bruchteil)
 *     X <  0 then
 *      X =  (float)(long)X
 *
 * comments on ceil & floor
 * 1.0       =  7F:80 00 00 00 ->
 * denormalize to LSB of mantissa == 1.0
 *              96:00 00 01
 * 2.0       =  80:80 00 00 00 ->
 *              96:00 00 02
 */

#include "gasava.inc"
#include "fplib.inc"

          TEXT_SEG(fplib, ceil)
          FUNCTION(ceil)

GLOBAL(ceil)
    BST     rA3,7
    RCALL   _U(__fp_split1)   ; split up in sign : exp : fraction   : fraction extention
                              ;          x  T      R19   R18:rSI0:R16: R1
    CPI     rA3,0x7F          ; Exp >= 0x7F -> arg >= 1.0
    BRCC    _ceil_100         ;
    BRTS    _ceil_01          ; |arg| < 1.0 -> ceil  = / 1.0  fÅr X >  0.0
    TST     rA3               ;                        \ 0.0  fÅr X <= 0.0
    BREQ    _ceil_01
    LDI     rA3,0x3F
    LDI     rA2,0x80
    CLR     rA1
    CLR     rA0
    RET
 _ceil_01:
    RJMP    _U(__fp_zero)
 _ceil_100_1:
    LSR     rA2        ;
    ROR     rA1        ; shift out fractional bits to the right
    ROR     rA0        ; until mantissa is a normalized unsigned
    adc     rAE,rT1c   ; rAE cleard by fp_split1, rT1c = __zero_reg__
    INC     rA3        ;
    ; |arg| >= 1.0
 _ceil_100:            ; |arg| >= 1.0
    CPI     rA3,0x96   ;
    BRCS    _ceil_100_1;

 _ceil_200:
    BRTS    _ceil_300  ; LSB now is exactely 1 or greater
    TST     rAE        ; any bit shiftet out? if LSB > 1 then rAE is zero
    BREQ    _ceil_300  ; no!
    SUBI    rA0,0xFF   ; else next bigger value
    SBCI    rA1,0xFF
    SBCI    rA2,0xFF
 _ceil_300:
    CLR     rAE        ; rT0 must not be cleared : rAE=0 no rounding anyway
    RJMP    _U(__fp_merge)

          ENDFUNC


