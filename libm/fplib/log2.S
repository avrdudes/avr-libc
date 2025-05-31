/* Copyright (c) 2002  Michael Stumpf  <mistumpf@de.pepperl-fuchs.com>
   Copyright (c) 2006  Dmitry Xmelkov
   Copyright (c) 2025  Georg-Johann Lay
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

;; float log2f (float A);
;; The log2f() function returns the base 2 logarithm of A.

#define FL_M1   0xbf800000  /* -1.0 */

#define rC3 YH
#define rC2 YL      /* adiw, sbiw can be used   */
#define rC1 r17
#define rC0 r16

FUNCTION log2f

.L_nf:  brts    .L_nan          ; Branch, if -Inf.
        XJMP    _U(__fp_mpack)  ; Pass as is: NaN -> NaN, +Inf -> +Inf.
.L_nan: XJMP    _U(__fp_nan)
.L_min: set
        XJMP    _U(__fp_inf)

ENTRY_FLOAT log2f log2 log2l
    XCALL   _U(__fp_splitA)
    brcs .L_nf          ; !isfinite(A)
    tst     rA3
    breq .L_min         ; 0 -> -Inf
    brts .L_nan         ; log(negative)

    push    rC3
    push    rC2

    ;; Normalize (if Subnormal)
    mov     rC2, rA3    ; Move exponent to rC3.rC2
    clr     rC3
    tst     rA2
    brmi 2f
1:  sbiw    rC2, 1
    lsl     rA0
    rol     rA1
    rol     rA2
    brpl 1b
2:
    ;; Calculate log2(1+x) for x in [-0.25, 0.5).
    ;; Different tables are used:
    ;; .L_tlow  for values in [0, 0.5)
    ;; .L_thigh for values in [-0.25, 0).
    ldi     rB0,  lo8(FL_M1)
    ldi     rB1,  hi8(FL_M1)
    ldi     rB2, hlo8(FL_M1)
    ldi     rB3, hhi8(FL_M1)
    ;; 1.x is 0x3f8...
    ldi     rA3, 0x3f
    cpi     rA2, 0xc0
    brsh 4f
    ;; A is in [1.0, 1.5): The implicit "1." provides
    ;; the LSB of the exponent in IEEE form.
3:  XCALL   _U(__addsf3)
    ;; Now A is in [0, 0.5).
    ldi     ZL, lo8(.L_tlow)
    ldi     ZH, hi8(.L_tlow)
    LDI_XH_hh8     (.L_tlow)
    rjmp 5f
4:  ;; A is in [1.5, 2): Unset the LSB of the exponent which
    ;; divides A by 2 and maps it to [0.75, 1).  Adjust exponent in C3.C2.
    cbr     rA2, 0x80
    adiw    rC2, 1
    XCALL   _U(__addsf3)
    ;; Now A is in [-0.25, 0).
    ldi     ZL, lo8(.L_thigh)
    ldi     ZH, hi8(.L_thigh)
    LDI_XH_hh8     (.L_thigh)
5:  XCALL   _U(__fp_powser)

    push    rAE
    push    rA1
    push    rA0
    X_movw  rA0, rC2        ; rA1.rA0 = exponent (possibly negative)
    X_movw  rC2, rA2

    ;; Calculating log2() of the exponent is just a conversion to int.
    subi    rA0, lo8(127)   ; Subtract 127, the exponent bias.
    sbci    rA1, hi8(127)
    ;; Sign-extend
    rol     rA1             ; C = rA1 sign bit
    sbc     rA2, rA2
    sbc     rA3, rA3
    ror     rA1             ; Restore rA1: undo the rol from above.
    XCALL   _U(__floatsisf)

    pop     rB0
    pop     rB1
    pop     rBE
    X_movw  rB2, rC2

    pop     rC2
    pop     rC3
    clr     rAE
    ;; log2(Mant * 2^expo) = log2(Mant) + expo.
    XCALL   _U(__addsf3x)
    XJMP    _U(__fp_round)
ENDFUNC

    PGMX_SECTION(fplib.log2)

;; A [7/0] MiniMax for log2(1+x)/x over [0, 0.5]
;; with an appended 0.0 coefficient to yield log2(1+x).
OBJECT .L_tlow
    .byte   8
    .byte        0x9c,0x1a,0x22,0xbd    ; -0.0395761585
    .byte   0xa0,0x92,0x20,0x00,0x3e    ;  0.1251242551
    .byte   0xbe,0xcc,0xd5,0x58,0xbe    ; -0.2117530814
    .byte   0x94,0xde,0xa0,0x90,0x3e    ;  0.2824773365
    .byte   0xa0,0xa5,0x4b,0xb8,0xbe    ; -0.3599521405
    .byte   0x20,0xa9,0x32,0xf6,0x3e    ;  0.4808552601
    .byte   0x80,0x2a,0xaa,0x38,0xbf    ; -0.7213465273
    .byte   0x22,0x3b,0xaa,0xb8,0x3f    ;  1.4426950371
    .byte   0x00,0x00,0x00,0x00,0x00    ;  0.0000000000
ENDOBJ .L_tlow

;; A [7/0] MiniMax for log2(1+x)/x over [-0.25, 0]
;; with an appended 0.0 coefficient to yield log2(1+x).
OBJECT .L_thigh
    .byte   8
    .byte        0x3c,0x5b,0xf7,0xbe    ; -0.4831179295
    .byte   0xda,0xd7,0xaa,0x71,0x3d    ;  0.0590008194
    .byte   0x8c,0x77,0x86,0x8c,0xbe    ; -0.2744634015
    .byte   0x2e,0xee,0x93,0x91,0x3e    ;  0.2843317444
    .byte   0x7a,0x9f,0xce,0xb8,0xbe    ; -0.3609514081
    .byte   0x10,0x24,0x37,0xf6,0x3e    ;  0.4808894414
    .byte   0xfa,0x3c,0xaa,0x38,0xbf    ; -0.7213476285
    .byte   0x28,0x3b,0xaa,0xb8,0x3f    ;  1.4426950407
    .byte   0x00,0x00,0x00,0x00,0x00    ;  0.0000000000
ENDOBJ .L_thigh

#endif /* AVR_TINY */
