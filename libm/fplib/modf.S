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
    modf.S is part of     FPlib V 0.3.0       ported to avr-as
    for details see readme.fplib

 *----------------------------------------------------------------------------------------
 *
 * A = modf(A,&B) *B = integral part of A
 *                 A = fractional part of A
 */

#include "gasava.inc"
#include "fplib.inc"

          TEXT_SEG(fplib, modf)
          FUNCTION(modf)

GLOBAL(modf)
        BST     rA3,7
        RCALL   _U(__fp_split1)	; clears rAE

        PUSH    YL
        PUSH    YH
        MOV     YH,rPH
        MOV     YL,rPL		; pointer to double
        CLR     rB3
        CLR     rB2
        CLR     rB1
        CLR     rB0		; preset zero integral part

        TST     rA3		; if zero return zero for *int and mantissa
        BREQ    _modf_200
        CPI     rA3,0x7F	; Exp < 0x7F -> arg < 1.0 -> no integer part
        BRCS    _modf_200	;

 _modf_100:
        MOV     rTI0,rA3	; keep temporarily
        RCALL   _U(__fp_merge)	; rT0 must not be cleared : rAE=0 no rounding anyway
        MOV     rB3,rA3
        MOV     rB2,rA2
        MOV     rB1,rA1
        MOV     rB0,rA0

        CPI     rTI0,0x96	; rA3 >= 0x96 -> no fractional part
        BRCC    _modf_150	;
        RCALL   _U(__fixsfsi)	;
        RCALL   _U(__floatsisf)	;
        CPI     YL,0
        CPC     YL,YH
        BREQ    _modf_130
        ST      Y+,rA0
        ST      Y+,rA1
        ST      Y+,rA2
        ST      Y+,rA3		; A = integer part
 _modf_130:
        SUBI    rA3,0x80	; A = -int(x)
        POP     YH
        POP     YL
        RJMP    _U(__addsf3)
 _modf_150:
        CLR     rA3
        CLR     rA2
        CLR     rA1
        CLR     rA0
 _modf_200:
        CPI     YL,0
        CPC     YL,YH
        BREQ    _modf_250
        ST      Y+,rB0
        ST      Y+,rB1
        ST      Y+,rB2
        ST      Y+,rB3		; no fractional part
 _modf_250:
        POP     YH
        POP     YL
        RJMP    _U(__fp_merge)	; rT0 must not be cleared : rAE=0 no rounding anyway

          ENDFUNC


