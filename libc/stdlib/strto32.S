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

;;; This file contains helper functions for strtol and strtoul.
;;; The caller is responsible for saving all GPRs to please the ABI.

#ifndef __AVR_TINY__

#include "asmdef.h"
#include "strtoxx.h"
#include "strto32.h"

#ifndef __AVR_HAVE_MUL__
;;; A[] := 0
ENTRY __strto32.clr_result
    clr         A0
    clr         A1
    X_movw      A2, A0
    ret
#endif /* !Have MUL */

;;; Shift in Digit R21 from the low end for Radix R27.
;;; A[] := A[] * Radix + Digit  using B[] and Tmp as temporaries.
;;; Set T = 1 on unsigned overflow.
ENTRY __strto32.madd
    X_movw      B0, A0
    X_movw      B2, A2

#ifdef __AVR_HAVE_MUL__
    mul         B0, Radix
    movw        A0, r0
    mul         B2, Radix
    movw        A2, r0
    mul         B3, Radix
    tst         r1
    brne .Loverflow
    add         A3, r0
    brcs .Loverflow
    mul         B1, Radix
    ADD         A0, Digit
    adc         A1, r0
    adc         A2, r1
    clr         __zero_reg__
    adc         A3, __zero_reg__
    brcc 9f

#else /* no MUL */

    rcall       __strto32.clr_result
    mov         Tmp, Radix
.Loop:
    lsr         Tmp
    brcc 1f
    ADD         A0, B0
    adc         A1, B1
    adc         A2, B2
    adc         A3, B3
    brcs .Loverflow
    tst         Tmp
1:  breq 2f
    ;; B[] <<= 1
    LSL         B0
    rol         B1
    rol         B2
    rol         B3
    ;; We have Tmp != 0, hence we are going to add a multiple of B[].
    brcs .Loverflow
    rjmp .Loop

2:  ;; A[] += Digit
    clr         __zero_reg__
    ADD         A0, Digit
    adc         A1, __zero_reg__
    adc         A2, __zero_reg__
    adc         A3, __zero_reg__
    brcc 9f

#endif /* Have MUL */

.Loverflow:
    set                         ; T = Overflow
9:  clr         __zero_reg__
    ret

ENDFUNC

#endif /* AVR_TINY */
