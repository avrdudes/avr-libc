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
    asin.S is part of     FPlib V 0.3.0       ported to avr-as
    for details see readme.fplib

 *----------------------------------------------------------------------------------------
 *
 *	A = asin(A)
 */

#include "gasava.inc"
#include "fplib.inc"

             TEXT_SEG(fplib, asin)
             FUNCTION(asin)

GLOBAL(asin)
       BST   rA3,7		; keep sign
       ANDI  rA3,0x7F
       LDI   rB3,0x3F
       LDI   rB2,0x80
       CPI   rA0,0x01
       CPC   rA1,rT1c
       CPC   rA2,rB2
       CPC   rA3,rB3		; A - 1.0000001192092896
       BRCS  _asin_00		; A <= 1.0
       RJMP  _U(__fp_nanEDOM)	; A > 1.0 -> argument range error
 _asin_00:
       BLD   rA3,7		; |A| <= 1.0

       PUSH  rA3
       PUSH  rA2
       PUSH  rA1
       PUSH  rA0
       RCALL   _U(square)	; xý

       LDI     ZL,LOW(table_asin)
       LDI     ZH,HIGH(table_asin)
       RCALL   _U(fp_powerseries)
       POP     rB0
       POP     rB1
       POP     rB2
       POP     rB3
       RJMP    _U(__mulsf3)


          ENDFUNC

/* asin(x) =    x ( 1 + xý(1/2*3 + xý(1*3/2*4*5 + xý(1*3*5/2*4*6*7 + xý(1*3*5*7/2*4*6*8*9+xý... (obsolete!)
 *
 *                  1 - xý(P1 - xý(P2 - xý(P3 - xý(P4 - xýP5))))
 * asin(x) =    x * --------------------------------------------
 *                        1 + xý(Q1 - xý(Q2 - xý(Q3 - xýQ4)
 *
 *
 * P1 : -2.23672826587    [C00F268E]
 * P2 :  1.69537997243    [3FD90236]
 * P3 : -0.48707145452    [BEF9616E]
 * P4 :  0.036982618272   [3D177B16]
 * P5 :  7.9153501429e-4  [3A4F7F04]
 * P6 :  3.4793309169e-5 (not used)
 *
 * Q1 : -2.4033949375     [C019D139]
 * Q2 :  2.0209457874     [4001572D]
 * Q3 : -6.8828397989e-1  [BF303361]
 * Q4 :  7.7038154006e-2  [3D9DC62E]
 */

	PGM_SECTION

 table_asin: DCB 4
             DCB 0x7B, 0x1D, 0xC6, 0x2E     ; Q4
             DCB 0x7E, 0xB0, 0x33, 0x61     ; Q3
             DCB 0x80, 0x01, 0x57, 0x2D     ; Q2
             DCB 0x80, 0x99, 0xD1, 0x39     ; Q1
             DCB 0x7F, 0x00, 0x00, 0x00     ; 1.0
             DCB 0x05
             DCB 0x74, 0x4F, 0x7F, 0x04     ; P5
             DCB 0x7A, 0x17, 0x7B, 0x16     ; P4
/*           DCB 0x7F, 0xF9, 0x61, 0x6E     ; P3 */
/* the above was wrong, thanks to Dean Ferreyra for reporting it */
             DCB 0x7D, 0xF9, 0x61, 0x6E     ; P3
             DCB 0x7F, 0x59, 0x02, 0x36     ; P2
             DCB 0x80, 0x8F, 0x26, 0x8E     ; P1
             DCB 0x7F, 0x00, 0x00, 0x00     ; 1.0


