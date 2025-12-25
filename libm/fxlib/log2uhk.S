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

;;; short accum R24 = log2 (unsigned short accum R24)

#define     Arg0    r24
#define     Arg1    r25

;; Integral part of log2, determined by counting leading zeros of Arg[].
#define     Int     r27

ENTRY log2uhk
    clr     Int
    ;; Arg[] < 1.0 ?
    tst     Arg1
    brne .Lge1

    ;; Yes: Is fractional part == 0 ?
    tst     Arg0
    brne .Loop_lt1
    ;; Yes: log2(0) = -128.
    ldi     Arg1, 0x80
    ret

.Loop_lt1:
    ;; No: Shift left until >= 1.0, i.e. until in [1, 2).
    dec     Int
    lsl     Arg0
    brcc .Loop_lt1
    rjmp .Log2_1p_uhr

;; Arg[] >= 1: Shift right until < 2.0, i.e. until in [1, 2).
.Loop_ge1:
    inc     Int
    lsr     Arg1
    ror     Arg0
.Lge1:
    cpi     Arg1, 2
    brsh .Loop_ge1

.Log2_1p_uhr:
    push    Int

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; Calculate     log_2 (1 + A) with A in [0, 1).
;;; uhfract R24 = log_2 (1 + uhfract R24)

    XCALL   _U(log21puhr)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; Finally combine log2 with the integral part to short accum Arg[].
    pop     Arg1
    ;; Convert to signed accum:  Q-format 8.8 -> s8.7
    asr     Arg1
    ror     Arg0
    ret

ENDFUNC
