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
    fp_merge.S is part of     FPlib V 0.3.0       ported to avr-as
    for details see readme.fplib

 *------------------------------------------------------------------------------------------
 * merge up in sign : exponent : fraction   : fraction extention
 *          x     T   rA3        rA2:rA1:rA0:rAE
 */

#if !defined(DOXYGEN)

#include "gasava.inc"
#include "fplib.inc"

          TEXT_SEG(fplib, __fp_merge)
          .func fp_merge_10

 fp_merge_10:
    DEC     rA3
    ADD     rAE,rAE
    adc     rA0,rA0
    adc     rA1,rA1
    adc     rA2,rA2
		; normalize (?) does any split number comes here unnormal? ; yes, _floor, _ceil!
GLOBAL(__fp_merge)
    CLR     rT1c           ; clr rT1c on all return paths
    TST     rA3            ; exponent == 0
    BREQ    fp_merge300  ; underflow
    TST     rA2
    BRPL    fp_merge_10  ; shift left until MSB set

    CPI     rA3,0xFF
    BREQ    fp_merge200  ; keep exp == 0xFF, no rounding

 ;  if rAE == 0x80 (exactely 0.5 LSB, half way between two numbers )
 ;  choose the one which makes the lsb of the answer 0.
 ;  what about rAE:rr1:rr0 of mul
    ADD   rAE,rAE
    BRCC  fp_merge200        ; no LSB : round to lower number
    BRNE  fp_merge100        ; rAE > 0x80 : round to upper number
    TST   rT0
    BRNE  fp_merge100        ; rAE=0x80:NN:MM , rT1c = NN | MM
    SBRS  rA0,0              ; R1 == 0x80 : round to even
    RJMP  fp_merge200        ;
 fp_merge100:                ;
    SUBI  rA0,0xFF
    SBCI  rA1,0xFF
    SBCI  rA2,0xFF
    SBCI  rA3,0xFF
 fp_merge200:                ; pack expanded FP number
    ROL     rA2              ; MSB is hidden 1
    ROR     rA3
    ROR     rA2
    BLD     rA3,7            ; get sign
    RET
 fp_merge300:
    RJMP    _U(__fp_zero)   ; merge segments

          ENDFUNC

#endif /* not DOXYGEN */
