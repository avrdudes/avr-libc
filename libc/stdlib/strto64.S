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

;;; This file contains helper functions for strtoll and strtoull.
;;; The caller is responsible for saving all GPRs to please the ABI.

#ifndef __AVR_TINY__

#include "asmdef.h"
#include "strtoxx.h"
#include "strto64.h"

;;; A[] := 0
ENTRY __strto64.clr_result
    clr         A0
    clr         A1
    X_movw      A2, A0
    X_movw      A4, A0
    X_movw      A6, A0
    ret

;;; Shift in Digit R21 from the low end for Radix R27.
;;; A[] := A[] * Radix + Digit  using B[] and Tmp as temporaries.
;;; Set T = 1 on unsigned overflow.
ENTRY __strto64.madd
    X_movw      B0, A0
    X_movw      B2, A2
    X_movw      B4, A4
    X_movw      B6, A6
    rcall       __strto64.clr_result
    mov         Tmp, Radix
.Loop:
    lsr         Tmp
    brcc 1f
    ADD         A0, B0
    adc         A1, B1
    adc         A2, B2
    adc         A3, B3
    adc         A4, B4
    adc         A5, B5
    adc         A6, B6
    adc         A7, B7
    brcs .Loverflow
    tst         Tmp
1:  breq 2f
    ;; B[] <<= 1
    LSL         B0
    rol         B1
    rol         B2
    rol         B3
    rol         B4
    rol         B5
    rol         B6
    rol         B7
    ;; We have Tmp != 0, hence we are going to add a multiple of B[].
    brcs .Loverflow
    rjmp .Loop

2:  ;; A[] += Digit
    clr         __zero_reg__
    ADD         A0, Digit
    adc         A1, __zero_reg__
    adc         A2, __zero_reg__
    adc         A3, __zero_reg__
    adc         A4, __zero_reg__
    adc         A5, __zero_reg__
    adc         A6, __zero_reg__
    adc         A7, __zero_reg__
    brcc 9f

.Loverflow:
    set                         ; T = Overflow
9:  clr         __zero_reg__
    ret

ENDFUNC

#endif /* AVR_TINY */
