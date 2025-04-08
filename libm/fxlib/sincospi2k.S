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

;;; cos(x * pi/2)
;;; sin(x * pi/2)

#define A0  r22
#define A1  r23
#define A2  r24
#define A3  r25

ENTRY cospi2k
    ;; cos(x) = sin(x + pi/2)
    subi    A1, hi8(-(1<<15))
    sbci    A2, hh8(-(1<<15))
ENTRY sinpi2k
    push    A2
    ;; Convert from Q-format s16.15 to 0.16.
    lsl     A0
    rol     A1
    ;; sin(x) = sin(pi - x)
    sbc     r24, r24
    sbc     r25, r25
    eor     r24, A0
    eor     r25, A1
    XCALL   _U(sinpi2ur)
    X_movw  A0, r24
    ;; Cast unsigned fract A[] to accum A[]
    clr     A3
    clr     A2
    lsr     A1
    ror     A0
    ;; Round
    adc     A0, __zero_reg__
    adc     A1, __zero_reg__
    ;; sin(x) = -sin(x +- pi)
    pop     __tmp_reg__
    sbrs    __tmp_reg__, 0
    ret
    XJMP    _U(__negsi2)
ENDFUNC
