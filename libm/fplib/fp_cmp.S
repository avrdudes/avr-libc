/*  -*- Mode: Asm -*-  */

/* Copyright (c) 2002  Michael Stumpf  <mistumpf@de.pepperl-fuchs.com>
   All rights reserved.


   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.
   
   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.
     
   * Neither the name of the copyright holders nor the names of
     contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
   ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
   POSSIBILITY OF SUCH DAMAGE. 
*/

/* $Id$ */

/*
    fp_cmp.S is part of     FPlib V 0.3.0       ported to avr-as
    for details see readme.fplib

 *----------------------------------------------------------------------------------------
 */

#include "gasava.inc"
#include "fplib.inc"

/* GCC expects all these functions to return -1/0/1 as for __cmpsf2 -
   compare with gcc/config/fp-bit.c (the only difference is with NaNs
   where we should always return nonzero for EQ/NE, -1 for GT/GE,
   1 for LT/LE).  -MM 2000-11-18 */

          TEXT_SEG(fplib, __fp_cmp)

          FUNCTION(__eqsf2)

GLOBAL(__eqsf2)                  ; equal : true, if Z set (and T clear)
GLOBAL(__nesf2)
GLOBAL(__ltsf2)
GLOBAL(__lesf2)
    rcall   .fp_cmp
    brts    .Lfp_cmp_gt  ; return 1 (not equal / false) if we got a NaN
    rjmp    .Lfp_cmp_ret

          ENDFUNC

          FUNCTION(__gtsf2)

GLOBAL(__gtsf2)                  ; greater than : true, if Z clear and C clear
GLOBAL(__gesf2)
    rcall   .fp_cmp
    brts    .Lfp_cmp_lt
    rjmp    .Lfp_cmp_ret

          ENDFUNC

          FUNCTION(__cmpsf2)

GLOBAL(__cmpsf2)  ; returns 1 for A > B ; 0 for A == B ; -1 for A < B ; NaN ?
    rcall   .fp_cmp
.Lfp_cmp_ret:
    breq    .Lfp_cmp_eq
    brcc    .Lfp_cmp_gt
.Lfp_cmp_lt:
    ldi     retByte,0xFF
    ret
.Lfp_cmp_eq:
    ldi     retByte,0x00
    ret
.Lfp_cmp_gt:
    ldi     retByte,0x01
    ret

          ENDFUNC

/*------------------------------------------------------------------------
 * compare  A == B
 *                                   { C = 1 Z = 0 T = 0 A < B
 * compares x to y and sets flags :  { C = 0 Z = 1 T = 0 A == B
 *                                   { C = 0 Z = 0 T = 0 A > B,
 *                                   {             T = 1 NAN
 */

          .func .fp_cmp

.fp_cmp:
    BST    rA3,7
    MOV    rT0,rA3
    EOR    rT0,rB3
    BLD    rT0,0		; rT0.7 = sign(A) EOR sign(B), rT0.0 = sign(A)
    SET
    RCALL  _U(__fp_split2)	; does not return on NaN (T set then)
    CLT
    SBRC   rT0,7
    RJMP   1f			; different signs

    ; same signs : compare
    CP     rA0,rB0
    CPC    rA1,rB1
    CPC    rA2,rB2
    CPC    rA3,rB3		; A - B ; set Z if equal, sets C if A < B (unsigned)
    BREQ   2f
    BRCC   1f		; A > B (unsigned)
    COM    rT0		; A < B (unsigned)
1:			; different signs (-0 < +0!)
		;  sign(A) == 0 (positive) -> A > B, C = 0 , Z = 0
		;  sign(A) == 1 (negative) -> A < B, C = 1 , Z = 0
    ROR    rT0		; C = sign(A)
    CLZ			; Z = 0
2:
    ret

          ENDFUNC

