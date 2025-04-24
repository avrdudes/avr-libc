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

;; atan(x) over [0, oo)  ->  [0, pi/2)

;; unsigned accum R22 = atanuk (unsigned accum R22);

#ifndef __AVR_TINY__

#include "asmdef.h"

#define X0   r22
#define X1   r23
#define X2   r24
#define X3   r25
#define X4   r26
#define X5   r27

#define Y0   r18
#define Y1   r19
#define Y2   r20
#define Y3   r21

#define One  (1 << 16)          /*  1.0uk  */
#define Pi2  (One + 37407)      /*  pi/2   */

ENTRY atanuk
    X_sbiw      X2, 0
    brne 1f
    ;; 0 <= X < 1: X fits in UHQmode.
    X_movw      r24, X0
    XCALL       _U(atanur)
    ;; R24:UHQ  ->  R22:USA
    X_movw      X0, r24
    clr         X2
    clr         X3
    ret

1:  cpi         X2, 1
    cpc         X3, __zero_reg__
    cpc         X0, __zero_reg__
    cpc         X1, __zero_reg__
    brne 2f
    ;; atan(1) = pi/4
    ldi         X0, lo8(Pi2 >> 1)
    ldi         X1, hi8(Pi2 >> 1)
    ldi         X2, hlo8(Pi2 >> 1)
    ldi         X3, hhi8(Pi2 >> 1)
    ret

2:  ;; X > 1: atan(X) = pi/2 - atan(1/X)
    X_movw      Y0, X0
    X_movw      Y2, X2
    ;; This arg gets passed already in place.
    ldi         X2, lo8(One)
    ldi         X3, hi8(One)
    ldi         X4, hlo8(One)
    ldi         X5, hhi8(One)
    ;; X[3..0] = X[5..2] / Y[3..0]
    XCALL       _U(__udivusa3)
    ;; 1/X fits in UHQmode.
    X_movw      r24, X0
    XCALL       _U(atanur)
    ;; X:USA = X:USA - R24:UHQ
    ldi         X0, lo8(Pi2)    $  sub   X0, r24
    ldi         X1, hi8(Pi2)    $  sbc   X1, r25
    ldi         X2, hlo8(Pi2)   $  sbci  X2, 0
    ldi         X3, hhi8(Pi2)   $  sbci  X3, 0
    ret
ENDFUNC

#endif /* AVRrc */
