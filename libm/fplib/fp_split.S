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
    fp_split.S is part of     FPlib V 0.3.0       ported to avr-as
    for details see readme.fplib

 *----------------------------------------------------------------------------------------------
 * split up in  exponent : fraction   : fraction extention
 *          x   rA3        rA2:rA1:rA0: rAE
 *          y   rB3        rB2:rB1:rB0: rBE
 * signs are lost !
 *
 * if defined FPLIB_CHECK_FOR_NAN
 * does not return to calling function in case of NaN !
 * -> call fp_split before pushing locals to stack!!!
 *
 * split 2 incoming operands , x and y, y first
 */

#include "gasava.inc"
#include "fplib.inc"

          TEXT_SEG(fplib, __fp_split)
          FUNCTION(__fp_split3)

GLOBAL(__fp_split3)
    MOV     rT0,rB3           ;
    EOR     rT0,rA3           ;
    BST     rT0,7             ; different signs : T = 1
GLOBAL(__fp_split2)
    ADD     rB2,rB2           ; MSB of exponent to carry
    adc     rB3,rB3           ; whole exponent in rB3, sign in C
    CPI     rB3,0xFF          ; check for NAN
    BREQ    fp_split_nan      ; if no jump then C as hidden one is set
    CLR     rBE            ; clear fraction extension
    cp      rBE,rB3        ; set C if nonzero exponent.  -MM 2000-11-25
    brcs    1f
    ldi     rB3,1          ; zero exponent really means 1 with hidden bit = 0
1:
    ROR     rB2            ; sets hidden bit
GLOBAL(__fp_split1)
    ADD     rA2,rA2        ; MSB of exponent to carry
    adc     rA3,rA3        ; whole exponent in rA3, sign in C
    CPI     rA3,0xFF       ; if no jump then C as hidden one is set
    BREQ    fp_split_nan
    CLR     rAE            ; clear fraction extension
    cp      rAE,rA3        ; set C if nonzero exponent.  -MM 2000-11-25
    brcs    1f
    ldi     rA3,1          ; zero exponent really means 1 with hidden bit = 0
1:
    ROR     rA2            ; sets hidden bit
    RET
 fp_split_nan:
    POP     rA3
    POP     rA3            ; pop return adress
 #ifdef __ERRNO__
    LDI     rA3,EDOM       ; NaN is argument domain error !
 #endif
    RJMP    _U(__fp_nan)

          ENDFUNC


