/* Copyright (c) 2002, Reiner Patommel
   Copyright (c) 2006  Dmitry Xmelkov
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
  POSSIBILITY OF SUCH DAMAGE. */

#ifndef __AVR_TINY__

#include "fp32def.h"
#include "asmdef.h"

/* This is an asin/acos internal function. Arg must be  0 <= x <= 1  */

#define One         0x3f800000          /* 1.0 */
#define Half        0x3f000000          /* 0.5 */
#define PI_2        0x3fc90fda          /* pi/2 */

#define rC0     r16
#define rC1     r17
#define rC2     YL
#define rC3     YH

ENTRY __fp_asinf_acosf
        ;; A := |A|
        cbr     rA3, 0x80
        cpi     rA3, hhi8(Half)
        ;; R0 = A < 0.5 ? -1 : 0
        sbc     r0, r0
        eor     r0, XL
        ;; R0 == 0: Finally reverse-subtract pi/2.
        push    r0
        ;; 0   <= x <  1/2: Compute x * asinq(x^2)
        ;; 1/2 <= x <= 1:   Compute sqrt(1-x) * acosq1m(1-x)
        brlo .L_asinf
        push    rC0
        push    rC1
        push    rC2
        push    rC3
        ;; C := 1 - A
        ldi     rB0,  lo8(One)
        ldi     rB1,  hi8(One)
        ldi     rB2, hlo8(One)
        ldi     rB3, hhi8(One)
        rcall   __rsubsf3.arccos
        X_movw  rC0, rA0
        X_movw  rC2, rA2
        ;; sqrt (1 - A)
        XCALL   _U(sqrtf)
        push    rA0
        push    rA1
        push    rA2
        push    rA3
        X_movw  rA0, rC0
        X_movw  rA2, rC2
        ldi     ZL, lo8(.L_acosq1m)
        ldi     ZH, hi8(.L_acosq1m)
        LDI_XH_hh8     (.L_acosq1m)
        XCALL   _U(__fp_powser)
        ;; B = sqrt (1 - A)
        pop     rB3
        pop     rB2
        pop     rB1
        pop     rB0
        ;; Restore C
        pop     rC3
        pop     rC2
        pop     rC1
        pop     rC0
        ;; acosq1m (1 - A) * sqrt (1 - A) = acos(A)
        XCALL   _U(__mulsf3)

.L_maybe_rsub_PI2:
        pop     r0
        cpse    r0, __zero_reg__
        ret
        ;; Reverse-subtract pi/2.
        ldi     rB0,  lo8(PI_2)
        ldi     rB1,  hi8(PI_2)
        ldi     rB2, hlo8(PI_2)
        ldi     rB3, hhi8(PI_2)

;;; Reverse-subtract: Returns B - A.
ENTRY __rsubsf3.arccos
        subi    rA3, 0x80
        XJMP    _U(__addsf3)

.L_asinf:
        ;; asin(A) = A * asinq (A^2)
        ldi     ZL, lo8(.L_asinq)
        ldi     ZH, hi8(.L_asinq)
        LDI_XH_hh8     (.L_asinq)
        XCALL   _U(__fp_powsodd)
        rjmp .L_maybe_rsub_PI2
ENDFUNC

PGMX_SECTION(fplib.arccos)
;;; acosq1m(x) = acos(1-x) / sqrt(x) for 0 <= x <= 1/2.
.type .L_acosq1m, "object"
.L_acosq1m:
        .byte   5                               ;  [5/0] MiniMax
        .byte        0xd6,0xf8,0xf6,0x3a        ;  0.0018842470
        .byte   0xec,0x86,0x33,0x0a,0x3b        ;  0.0021087841
        .byte   0xfe,0x6b,0xed,0x03,0x3c        ;  0.0080522113
        .byte   0x52,0xe0,0x0f,0xd9,0x3c        ;  0.0264968282
        .byte   0x18,0x64,0x5c,0xf1,0x3d        ;  0.1178520031
        .byte   0x26,0xf3,0x04,0xb5,0x3f        ;  1.4142135561
.size .L_acosq1m, . - .L_acosq1m

;;; asinq(x) = asin(sqrt(x)) / sqrt(x) for 0 <= x <= (1/2)^2.
.type .L_asinq, "object"
.L_asinq:
        .byte   5                               ;  [5/0] MiniMax
        .byte        0xb6,0xa2,0x2e,0x3d        ;  0.0426356426
        .byte   0xfa,0x34,0x72,0xc3,0x3c        ;  0.0238581691
        .byte   0xcc,0xd4,0x92,0x3a,0x3d        ;  0.0455501854
        .byte   0x10,0x6c,0x7c,0x99,0x3d        ;  0.0749443476
        .byte   0x82,0xfd,0xaa,0x2a,0x3e        ;  0.1666679011
        .byte   0xee,0xff,0xff,0x7f,0x3f        ;  0.9999999956
.size .L_asinq, . - .L_asinq
        .end
#endif /* __AVR_TINY__ */
