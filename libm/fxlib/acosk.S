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

#define Arg0    r22
#define Arg1    r23
#define Arg2    r24
#define Arg3    r25

#define Pi 0x3243f

ENTRY acosk
    ;; SA -> USA
    lsl     Arg0
    rol     Arg1
    rol     Arg2
    rol     Arg3
    brcs 2f
    XCALL   _U(acosuk)
0:  ;; USA -> SA
    asr     Arg3
    ror     Arg2
    ror     Arg1
    ror     Arg0
    adc     Arg0, __zero_reg__
    adc     Arg1, __zero_reg__
    adc     Arg2, __zero_reg__
    adc     Arg3, __zero_reg__
    ret
2:  ;; x < 0: acos(x) = pi - acos(-x)
    XCALL   _U(__negsi2)
    XCALL   _U(acosuk)
    X_movw  XL, Arg0
    X_movw  ZL, Arg2
    ldi     Arg0, lo8(Pi)    $  sub  Arg0, XL
    ldi     Arg1, hi8(Pi)    $  sbc  Arg1, XH
    ldi     Arg2, hlo8(Pi)   $  sbc  Arg2, ZL
    ldi     Arg3, hhi8(Pi)   $  sbc  Arg3, ZH
    tst     Arg3
    breq 0b
    ;; Return -65536 for invalid inputs.
    sec
    XJMP    _U(__asinuk_acosuk_NaN_or_0)
ENDFUNC
