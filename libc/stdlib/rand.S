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

;;; Realize  GF(2^24)  as  GF(2^24) ~ Z2[X] / (Poly24 * Z2[X])
;;; where  Z2 = Z / 2Z  and Poly24 is a polynomial of degree 24
;;; that's irreducible over Z2.
#define Poly24 0x17a96e9 /* 1 + X^3 + X^5 + X^6 + X^7 + X^9 + X^10 + X^12 + X^15 + X^17 + X^19 + X^20 + X^21 + X^22 + X^24 */

;;; A primitive root of unity in GF(2^24)*, i.e.  Root24^N = 1
;;; and  N = 2^24 - 1  is the smallest N with that property.
#define Root24 0x8b /* 1 + X + X^3 + X^7 */

#define C0 r24
#define C1 r25
#define C2 __zero_reg__
#define A0 r26
#define A1 r27
#define A2 __tmp_reg__

#define B0 r20
#define P0 r21
#define P1 r22
#define P2 r23

;;; int R24 = rand_r (uint32_t * seed R24);
;;; *seed *= Root24  where the multiplikation is in GF(2^24)*  except
;;; when   *seed == 0,  in which case we map 0 to something non-0.
;;; Only the lower 24 bits of *seed are involved.
;;; The period of rand / rand_r is 2^24 - 1.
ENTRY rand
    ldi     r24, lo8(__seed)
    ldi     r25, hi8(__seed)
ENTRY rand_r
    X_movw  ZL, r24
    ld      A0, Z+
    ld      A1, Z+
    ld      A2, Z+
    ;; Map seed = 0 to something harmless.
    X_sbiw  A0, 0
    cpc     A2, __zero_reg__
    brne 0f
    ldi     A1, 0xcc
0:
    ldi     B0, Root24    ; Notice that deg(Root24) < 8.
    ;; Clear result C[].
    clr     C0
    clr     C1
    ; clr     C2        ; C2 === zero_reg
    ldi     P0, lo8(Poly24)
    ldi     P1, hi8(Poly24)
    ldi     P2, hlo8(Poly24)

    ;; Calculate C = A * B mod Poly24, i.e. multiplication in GF(2^24).
.Loop24:
    sbrs    B0, 0
    rjmp 1f
    ;; C += A * X^i  but only if bit B.i is set.
    eor     C0, A0
    eor     C1, A1
    eor     C2, A2
1:
    ;; A *= X
    lsl     A0
    rol     A1
    rol     A2
    ;; A = A mod Poly. When the leading term of A is not X^24
    ;; then nothing needs to be done.
    brcc 2f
    eor     A0, P0
    eor     A1, P1
    eor     A2, P2
2:
    ;; B >>= 1 : Move interesting bit i of B to B0.0.
    lsr     B0
    brne .Loop24
    st      -Z, C2
    st      -Z, C1
    st      -Z, C0
    ;; Result is in [0, RAND_MAX = 0x7fff].
    andi    C1, hi8(0x7fff)
    clr     __zero_reg__
    ret
ENDFUNC
