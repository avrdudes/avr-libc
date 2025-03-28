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

/* $Id$ */

/* Without MUL we could use the same algorithm, but the guess is that it would
   be worse than log2f -- at least as far as the runtime is concerned.  */

#ifdef __AVR_HAVE_MUL__

#include "asmdef.h"

;;; accum R22 = log2 (unsigned accum R22)

#define     Arg0    r22
#define     Arg1    r23
#define     Arg2    r24
#define     Arg3    r25

;; Integral part of log2, determined by counting leading zeros of Arg[].
#define     Int     r27

ENTRY log2uk
    clr     Int
    ;; Arg[] < 1.0 ?
    sbiw    Arg2, 0
    brne .Lge1

    ;; No: Is fractional part == 0 ?
    cp      Arg0, __zero_reg__
    cpc     Arg1, __zero_reg__
    brne .Loop_lt1
    ldi     Arg3, 0x80          ; log2(0) = -32878.
    ret
.Loop_lt1:
    ;; No: Shift left until >= 1.0, i.e. until in [1, 2).
    dec     Int
    lsl     Arg0
    rol     Arg1
    brcc .Loop_lt1
    rjmp .Log2_1p_ur

;; Arg[] >= 1: Shift right until < 2.0, i.e. until in [1, 2).
.Loop_ge1:
    inc     Int
    lsr     Arg3
    ror     Arg2
    ror     Arg1
    ror     Arg0
.Lge1:
    cpi     Arg2, 2
    cpc     Arg3, __zero_reg__
    brsh .Loop_ge1

.Log2_1p_ur:

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; Calculate    log_2 (1 + A) with A in [0, 1).
;;; ufract R22 = log_2 (1 + ufract R22)

#define     A0      r22
#define     A1      r23

#define     P0      r21
#define     P1      r18
#define     P2      r19
#define     P3      r20

#define     Zero    r24

#define     Mask0   r25
#define     Mask1   r26
#define     Res0    r30
#define     Res1    r31

    clr     Res0
    clr     Res1
    X_movw  Zero, Res0          ; Clear Zero and Mask0
    ldi     Mask1, hi8(1 << 15) ; 0.5
.Loop:
    ;; (1 + A)^2 = 1 + 2A + A^2
    ldi     P3, 1
    mul     A1, A1
    X_movw  P1, r0
    mov     P0, A0              ; Proxy for A0^2

    fmul    A0, A1
    adc     P2, Zero
    adc     P3, Zero
    add     P0, r0
    adc     P1, r1
    adc     P2, Zero
    adc     P3, Zero

    add     P1, A0
    adc     P2, A1
    adc     P3, Zero
    add     P1, A0
    adc     P2, A1
    adc     P3, Zero

    cpi     P3, 2               ; P[] >= 2 ?  i.e.  P[] in [2, 4) ?
    brlo 1f
    lsr     P3                  ; Yes =>  P[] >> 1 in [1, 2) again.
    ror     P2
    ror     P1
    adc     P1, Zero
    adc     P2, Zero
    or      Res0, Mask0
    or      Res1, Mask1
1:
    X_movw  A0, P1
    lsr     Mask1
    ror     Mask0
    brcc .Loop

    clr     __zero_reg__
    X_movw  A0, Res0

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; Final roundup: Combine log2 with the integral part to accum Arg[].
    ;; Sign-extend integral part to Arg2/3.
    mov     Arg2, Int
    clr     Arg3
    sbrc    Arg2, 7
    dec     Arg3
    ;; Convert to signed accum:  Q-format 16.16 -> s16.15
    asr     Arg3
    ror     Arg2
    ror     Arg1
    ror     Arg0
    ;; Round.
    adc     Arg0, __zero_reg__
    adc     Arg1, __zero_reg__
    adc     Arg2, __zero_reg__
    adc     Arg3, __zero_reg__
    ret

ENDFUNC

#endif /* Have MUL */
