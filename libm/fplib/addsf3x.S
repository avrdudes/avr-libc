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
    addsf3x.S is part of     FPlib V 0.3.0       ported to avr-as
    for details see readme.fplib

 *----------------------------------------------------------------------------------------
 *
 *--- addition kernel : used by other high level functions
 * add two extended numbers RX = AX + BX
 * AX  rA3 : rA2:rA1:rA0:rAE sign stored in rT1c.7, rAE cleared by fp_split1
 * BX  rB3 : rB2:rB1:rB0:rBE sign(A) ^ sign(B) stored in T
 * RX  rA3 : rA2:rA1:rA0:rAE resulting sign stored in rT1c.7 (rT1c.7 complemented, if B > A)
 */

#if !defined(DOXYGEN)

#include "gasava.inc"
#include "fplib.inc"

          TEXT_SEG(fplib, __addsf3x)
          FUNCTION(__addsf3x)

GLOBAL(__addsf3x)
    CP      rAE,rBE         ; some high level functions use ___addsf3x
    CPC     rA0,rB0         ; directely with preset rAE,rBE
    CPC     rA1,rB1         ;
    CPC     rA2,rB2         ;
    CPC     rA3,rB3         ; A - B
    BREQ    ___addsf3x_300
    BRCC    ___addsf3x_100  ; A >= B

    BRTC    ___addsf3x_01   ; if T clear the A & B of same sign
    COM     rT1c            ; else complement sign
 ___addsf3x_01:
    MOV     rT0,rAE
    MOV     rAE,rBE
    MOV     rBE,rT0
    MOV     rT0,rA0
    MOV     rA0,rB0
    MOV     rB0,rT0
    MOV     rT0,rA1
    MOV     rA1,rB1
    MOV     rB1,rT0
    MOV     rT0,rA2
    MOV     rA2,rB2
    MOV     rB2,rT0
    MOV     rT0,rA3
    MOV     rA3,rB3
    MOV     rB3,rT0

 ; now A > B
 ___addsf3x_100:               ; denormalize lower mantissa until exponents are the same
    CLR     rTI0               ; holds mantissa extension beyond rBE
    TST     rB3                ;
    BREQ    ___addsf3x_130     ; A + 0

    SUB     rB3,rA3            ; get difference, rB3 negative
    BREQ    ___addsf3x_120     ; same : no shift
    CPI     rB3,LOW(-25)       ; no significant digits left after shift
    BRCS    ___addsf3x_130     ;
 ___addsf3x_110:                                                     ;
    LSR     rB2                                                      ;
    ROR     rB1                                                      ;
    ROR     rB0                                                      ;
    ROR     rBE                ; fraction >> 1                       ;
    SBCI    rTI0,0             ; mark if any overflow beyond rBE     ;
    INC     rB3                ; exponent ++
    BRNE    ___addsf3x_110     ;

 ___addsf3x_120:
    BRTS    ___addsf3x_200     ; branch if different sign
    ADD     rAE,rBE            ; maybe rAE and rBE are preset
    adc     rA0,rB0            ;
    adc     rA1,rB1            ;
    adc     rA2,rB2            ; add both mantissae
    BRCC    ___addsf3x_130     ; no fraction overflow if C = 0
    ROR     rA2                ; correct overflow
    ROR     rA1
    ROR     rA0
    ROR     rAE               ; fraction >> 1
    SBCI    rTI0,0            ; mark if any overflow beyond rBE
    INC     rA3               ; exponent++
 ___addsf3x_130:
    BST     rT1c,7
    MOV     rT0,rTI0
    RET

 ___addsf3x_200:
    SUB     rAE,rTI0          ; extended mantissa : 0 - lost bits
    CLR     rAE
    SBC     rAE,rBE           ; subtract the lower from the larger
    SBC     rA0,rB0           ; extended mantissa : if rBE == 0x80 -> rAE = 0x80
    SBC     rA1,rB1           ;
    SBC     rA2,rB2           ;
    RJMP    ___addsf3x_130    ;

 ; A == B
 ___addsf3x_300:
    BRTC    ___addsf3x_100    ; same sign, test for zero & add
    RJMP    _U(__fp_zerox)     ; different signs

          ENDFUNC

#endif /* not DOXYGEN */
