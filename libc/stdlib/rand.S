/* Copyright (c) 2025  Georg-Johann Lay
   Copyright (c) 2025  David Sparks
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

/* https://en.wikipedia.org/wiki/Xorshift
   The period of xorshift32 is 2^32 - 1.

   Using the TestU01 suite from https://simul.iro.umontreal.ca/testu01/tu01.html
   the RNG below achieves a rating of 100% in the bbattery_SmallCrush tests.
   (Which expect a 32-bit resolution, so the upper 17 bits have been filled
   with "good" RNG bits.)  The v2.2.1 implementation of rand() achieved
   a score of 100% too, but utilized a multiple of resources.

   For the tests, see ./tests/bench-rand.  */

#include "asmdef.h"

#define C0  r24
#define C1  r25
#define C2  r26
#define C3  r27

#define A0  r20
#define A1  r21
#define A2  r22
#define A3  r23

#ifdef __AVR_TINY__
#define Ax  __tmp_reg__
#else
#define Ax  r18
#endif /* AVR_TINY */


ENTRY rand
    ldi     r24, lo8(__seed)
    ldi     r25, hi8(__seed)

;;; int16_t R24 = rand_r (uint32_t *R24);
ENTRY rand_r
    X_movw  ZL, r24
    ld      C0, Z+
    ld      C1, Z+
    ld      C2, Z+
    ld      C3, Z
    ;; Map __seed = 0 to something harmless (non-0).
    ;; Notice that all non-zero seeds map to non-zero seeds.
    X_sbiw  C0, 0
    sbci    C2, 0
    sbci    C3, 0
    brne 0f
    ldi     C2, 42
0:
    ;; C[] ^= C[] << 13
    X_movw  A0, C0
    mov     A2, C2
    ;; Set upper 5 bits of A2 to 0b00001 for loop control.
    cbr     A2, 0xf8
    ori     A2, 0x08
1:  lsl     A0
    rol     A1
    rol     A2
    brcc 1b
    eor     C1, A0
    eor     C2, A1
    eor     C3, A2
    ;; C[] ^= C[] >> 17
    X_movw  A0, C2
    lsr     A1
    ror     A0
    eor     C0, A0
    eor     C1, A1
    ;; C[] ^= C[] << 5
    X_movw  A0, C0
    X_movw  A2, C2
    ;; Perform << 5 as 40-bit >> 3 with Ax = 0b100 for loop control.
    ldi     Ax, 0b100
2:  lsr     A3
    ror     A2
    ror     A1
    ror     A0
    ror     Ax
    brcc 2b
    eor     C0, Ax
    eor     C1, A0
    eor     C2, A1
    eor     C3, A2
    st      Z, C3
    st      -Z, C2
    st      -Z, C1
    st      -Z, C0
    ;; This addition to xorshift32 was proposed by David Sparks.
    ;; Without it, the TestU01's MatrixRank test is failing.
    ;; The addition has no effect on the period.
    add     C0, C2
    adc     C1, C3
    ;; Result is in [0, 0x7fff].
    andi    C1, hi8(0x7fff)
    ret
ENDFUNC
