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

/* Without MUL we could use the same algorithm, but the guess is that it would
   be worse than log2f -- at least as far as the runtime is concerned.  */

#ifndef __AVR_TINY__

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

    ;; Yes: Is fractional part == 0 ?
    cp      Arg0, __zero_reg__
    cpc     Arg1, __zero_reg__
    brne .Loop_lt1
    ;; Yes: Return log2(0) = -32768.
    ldi     Arg3, 0x80
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
;;; ufract R24 = log_2 (1 + ufract R24)

    push    Int
    X_movw  R24, Arg0
    XCALL   _U(log21pur)
    X_movw  Arg0, R24

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; Final roundup: Combine log2 with the integral part to accum Arg[].
    ;; Sign-extend integral part to Arg2/3.
    pop     Arg2
    clr     Arg3
    sbrc    Arg2, 7
    dec     Arg3
    ;; Convert to signed accum:  Q-format 16.16 -> s16.15
    asr     Arg3
    ror     Arg2
    ror     Arg1
    ror     Arg0
    ret

ENDFUNC

#endif /* AVR_TINY */
