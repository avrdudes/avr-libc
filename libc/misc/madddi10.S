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
   POSSIBILITY OF SUCH DAMAGE.	*/

#ifndef __AVR_TINY__

#include "asmdef.h"

#define A0 18
#define A1 19
#define A2 20
#define A3 21
#define A4 22
#define A5 23
#define A6 24
#define A7 25

;;; uint64_t __madddi_const_10 (uint64_t, uint8_t)
;;; uint64_t R18 = 10 * R18 + (uint64_t) R16
ENTRY _U(__madddi_const_10)
#ifndef __AVR_HAVE_ELPM__
    push    r17
#endif
    push    A5
    push    A4
    X_movw  r0, A0
    X_movw  R26, A2
    X_movw  R30, A6
#ifdef __AVR_HAVE_ELPM__
    lsl     A0 $ rol A1 $ rol A2 $ rol A3 $ rol A4 $ rol A5 $ rol A6 $ rol A7
    lsl     A0 $ rol A1 $ rol A2 $ rol A3 $ rol A4 $ rol A5 $ rol A6 $ rol A7
    add     A0, r0
    adc     A1, r1
    adc     A2, r26
    adc     A3, r27
    pop     r0  $ adc    A4, r0
    pop     r0  $ adc    A5, r0
    adc     A6, r30
    adc     A7, r31
    lsl     A0 $ rol A1 $ rol A2 $ rol A3 $ rol A4 $ rol A5 $ rol A6 $ rol A7
#else
    ;; On the "small" devices, roll a loop.
    ldi     r17, 2
    rjmp .Loop
0:  add     A0, r0
    adc     A1, r1
    adc     A2, r26
    adc     A3, r27
    pop     r0  $ adc    A4, r0
    pop     r0  $ adc    A5, r0
    adc     A6, r30
    adc     A7, r31
.Loop:
    lsl     A0 $ rol A1 $ rol A2 $ rol A3 $ rol A4 $ rol A5 $ rol A6 $ rol A7
    dec     r17
    breq 0b
    brpl .Loop
#endif
    clr     __zero_reg__
    add     A0, R16
    adc     A1, __zero_reg__
    adc     A2, __zero_reg__
    adc     A3, __zero_reg__
    adc     A4, __zero_reg__
    adc     A5, __zero_reg__
    adc     A6, __zero_reg__
    adc     A7, __zero_reg__

#ifndef __AVR_HAVE_ELPM__
    pop     r17
#endif
    ret
ENDFUNC

#endif /* AVR_TINY */
