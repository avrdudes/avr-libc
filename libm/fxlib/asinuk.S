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

#define TABL __asinq2m1_poly

#define Res0    r22
#define Res1    r23
#define Res2    r24
#define Res3    r25

#define Arg0    r22
#define Arg1    r23
#define Arg2    r24
#define Arg3    r25

#define What    r28
#define Tmp     r30

#ifdef __AVR_TINY__
#define PM_OFFSET 0x4000
#define X0      r18
#define X1      r19
#else
#define PM_OFFSET 0
#define X0      r16
#define X1      r17
#endif

#define Pi2 0x1921f

ENTRY __asinuk_acosuk_NaN_or_0
.LNaN_or_0:
    clr     Res0
    clr     Res1
    X_movw  Res2, Res0
    ror     Res3
    ret
.Lone:
    brts .LNaN_or_0                 ; acos(1) = 0
    ;; asin(1) = pi/2
.Load_pi2:
    ldi     Res0, lo8(Pi2)
    ldi     Res1, hi8(Pi2)
    ldi     Res2, hlo8(Pi2)
    ldi     Res3, hhi8(Pi2)
    ret

ENTRY acosuk
    set
    rjmp .+2
ENTRY asinuk
    clt
    ;; Compare Arg against 1.0uk
    cp      Arg0, __zero_reg__
    cpc     Arg1, __zero_reg__
    ldi     Tmp, 1
    cpc     Arg2, Tmp
    cpc     Arg3, __zero_reg__
    breq .Lone
    brsh .LNaN_or_0

    ;; .0: Compute acos or asin
    ;; .1: in [0, 0.5) or in [0.5, 1)
    ;; .7: Tame
    push    What
    subi    Arg1, 0x80
    cpi     Arg1, 7
    ror     What
    subi    Arg1, 0x80
    bld     What, 0
    bst     Arg1, 7
    bld     What, 1
    push    X0
    push    X1

    brtc .Ldo_asin

    ;; In [0.5, 1): Compute acos.
    ;; X -> sqrt(2-2X)
    ;; W -> 1-X
    clr     X0
    clr     X1
    sub     X0, Arg0
    sbc     X1, Arg1
    X_movw  r24, X0
    lsl     r24
    rol     r25
    sbc     r24, __zero_reg__
    sbc     r25, __zero_reg__
    XCALL   _U(sqrtur)
    X_movw  r30, r24
    X_movw  r24, X0
    X_movw  X0, r30

    rjmp .Ldo_asinq2m1

.Ldo_asin:
    ;; In [0, 0.5): Compute asin.
    ;; W -> 2 * X^2
    X_movw  X0, Arg0
#ifdef __AVR_HAVE_MUL__
    X_movw  r18, X0
    X_movw  r26, X0
#else
    X_movw  r24, X0
#endif
    XCALL   _U(__muluhq3)
    lsl     r24
    rol     r25

.Ldo_asinq2m1:
    ;; W -> asinq2m1 (W)
    ldi     r20, lo8(TABL + PM_OFFSET)
    ldi     r21, hi8(TABL + PM_OFFSET)
#ifdef __AVR_HAVE_ELPM__
    ldi     r22, hh8(TABL + PM_OFFSET)
#endif
    XCALL   _U(__horner_ur)

    ;; W *= 1 + X
#ifdef __AVR_HAVE_MUL__
    X_movw  r26, r24
    X_movw  r18, X0
#else
    X_movw  r22, X0
#endif
    XCALL   _U(__muluhq3)
    ;; Tame error
#ifndef __AVR_TINY__
    sbrc    What, 7
#else
    tst     What
    brpl 0f
#endif
    X_adiw  r24, 2

0:  ;; Adding X might bust UHQmode: Go USAmode.
    X_movw  Res0, r24
    add     Res0, X0
    adc     Res1, X1
    clr     Res2
    adc     Res2, __zero_reg__
    clr     Res3

    andi    What, 0b11
    breq .Ldone                 ; 0b00: Want asin and have asin.
    cpi     What, 0b10
    breq .Lfinish
    brsh .Ldone                 ; 0b11: Want acos and have acos.
.Lfinish:
    ;; 0b01: Want acos but have asin.
    ;; 0b10: Want asin but have acos.
    ;; Use asin(x) + acos(x) = pi/2
    X_movw  XL, Res0
    mov     ZL, Res2
    RCALL   .Load_pi2
    sub     Res0, XL
    sbc     Res1, XH
    sbc     Res2, ZL

.Ldone:
    ;; Epilogue
    pop     X1
    pop     X0
    pop     What
    ret
ENDFUNC

#define SIZEOF_POLY(Deg) (1 + 2 * (1 + Deg))

#define PARAB(s, a0, a1, a2)       \
    $ .byte (s << 6) | (1 << 5)    \
    $ .2byte a2, a1, a0

.section .progmemx.data.TABL, "a", "progbits"
.type TABL, "object"
.size TABL, 1 * SIZEOF_POLY(2)
TABL:
    PARAB (0b00, 0x0002, 0x150e, 0x0626)
