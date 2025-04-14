/* Copyright (c) 2025  Georg-Johann Lay
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
   POSSIBILITY OF SUCH DAMAGE.  */

#include "asmdef.h"


/*  Evaluate a polynomial of degree N, where N is in the range 1..7,
    and all coefficients and all intermediate values must be in the
    range [0, 1).  Intermediate values are the results y_i of the
    partial expansions
       y_N     = a_N,
       ...
       y_2     = a_2 ± x * y_3,
       y_1     = a_1 ± x * y_2,
       y_0     = a_0 ± x * y_1,

    The memory layout of a polynmoial of degree N is

    typedef struct
    {
        uint8_t signs;
        unsigned fract a_N, ..., a_2, a_1, a_0;
    } polynomial_t;

    The bits of signs encode the degree N and the signs of the a_i's:
    - Bit 8-N+i stores the sign of a_i for i = 0..N-1.
    - Bit 7-N is always 1 (stop bit).
    - Bits below 7-N are always 0.
*/

#define ArgTab0     r20
#define ArgTab1     r21
#ifdef __AVR_HAVE_ELPM__
#define ArgTab2     r22
#endif

#define ArgX0   r24
#define ArgX1   r25

#ifdef __AVR_HAVE_MUL__  /* __muluhq3 has a lean non-ABI footprint */
;; Y[] lives in one argument of __muluhq3, which is preserved.
#define Y0      r18
#define Y1      r19

;; X[] lives in the other argument of __muluhq3, which is also preserved.
#define X0      r26
#define X1      r27

#define Signs   r20
#define Tab0    r30
#define Tab1    r31
#define Tab2    ArgTab2

#define A0      Y0
#define A1      Y1

#define SAVE_Z      /* empty */
#define RESTORE_Z   /* empty */

#else /* __muluhq3 complies to ABI */

#define Y0      r24
#define Y1      r25

#define X0      r28
#define X1      r29

#define A0      r22
#define A1      __tmp_reg__

#if defined(__AVR_TINY__)

#define Signs   r18
#define Tab0    r30
#define Tab1    r31

#define SAVE_Z      push ZL      $  mov  r19, ZH
#define RESTORE_Z   mov ZH, r19  $  pop  ZL

#else

#define Signs   r17
#define Tab0    r14
#define Tab1    r15
#define Tab2    r16

#define SAVE_Z      X_movw  Tab0, ZL
#define RESTORE_Z   X_movw  ZL, Tab0

#endif /* AVR_TINY */
#endif /* Have MUL? */


;;; unsigned fract R24 = horner (unsigned fract R24, uint_farptr_t R20)
;;; R24 = A0 ± X * (A1 ± X * (A2 ± X * ...))
ENTRY __horner_ur
#ifndef __AVR_HAVE_MUL__
    push        Signs
    push        X0
    push        X1
#ifndef __AVR_TINY__
    push        Tab0
    push        Tab1
#endif
#ifdef __AVR_HAVE_ELPM__
    push        Tab2
#endif
#endif /* ! Have MUL */

    X_movw      X0, ArgX0
    X_movw      ZL, ArgTab0

#if defined(__AVR_HAVE_ELPM__) && !defined(__AVR_HAVE_ELPMX__)
    mov         Tab2, ArgTab2
#endif
    LPM_R0_ZPLUS_INIT Tab2

    LPM_R0_ZPLUS_NEXT Tab2, Signs
    ;; Y[] = a_N[].
    LPM_R0_ZPLUS_NEXT Tab2, Y0
    LPM_R0_ZPLUS_NEXT Tab2, Y1

.Loop:

#ifndef __AVR_HAVE_MUL__
    X_movw  r22, X0
#endif
    SAVE_Z
    ;; no MUL: (R25:R24) *= (R23:R22)            Clobbers: ABI
    ;; MUL:    (R25:R24) = (R19:R18) * (R27:R26) Clobbers: __tmp_reg__, R22, R23
    XCALL   _U(__muluhq3)       ; libgcc
    RESTORE_Z

    ;; Adjust sign of the product.
    lsl     Signs
    brcc 0f
    com     r25
    neg     r24
    sbci    r25, -1

0:  LPM_R0_ZPLUS_NEXT Tab2, A0
    LPM_R0_ZPLUS_NEXT Tab2, A1

    ;; Y[] := A[] ± X[] * Y[]
#ifdef __AVR_HAVE_MUL__
    add     Y0, r24
    adc     Y1, r25
#else
    add     Y0, A0
    adc     Y1, A1
#endif
    cpi     Signs, 0x80
    brne .Loop

    LPM_R0_ZPLUS_FINI
    X_movw  R24, Y0

#ifndef __AVR_HAVE_MUL__
#ifdef __AVR_HAVE_ELPM__
    pop         Tab2
#endif
#ifndef __AVR_TINY__
    pop         Tab1
    pop         Tab0
#endif
    pop         X1
    pop         X0
    pop         Signs
#endif /* ! Have MUL */

    ret
ENDFUNC
