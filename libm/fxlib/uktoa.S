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

#ifndef __AVR_TINY__

#include "asmdef.h"

;; The argument registers as of avr-gcc ABI.
#define A0      22
#define A1      A0+1
#define A2      A0+2
#define A3      A0+3
#define pBufArg 20
#define Mode    18      /* const */

;; Passed from the signed routines: 0 or '-'.
#define Sign    r27

;; Locals

#define pBuf    r30
#define NonZero r19
#define Digs    r17
#define Count   r16

;; Register(s) that don't need to survive __mulsi_const_10.
#define Digit   r21

#define E4 (10000 << 16)
#define E3  (1000 << 16)

;; Number of integral positions.
#define IDIGS 5

;; Addends for respective rounding points: approx 0.5 * 10^{-RP}.
#define RP0 32768
#define RP1 3277
#define RP2 328
#define RP3 33
#define RP4 3

;; Addend used during rounding, holds one of RPx.
#define D0  r26
#define D1  r27

#define FXTOA_ALL 0x1f
#define BIT_NO_ROUNDING     7
#define BIT_NO_TRAILING_0S  6
#define BIT_COMMA           5

;;; char* R24 = uktoa (unsigned accum R20, char *R20, uint8_t R18)
;;; char* R24 = uktoa (unsigned accum A[], char *,    uint8_t Mode)
;;; where Mode is a 2:2:2:32 mixed-radix value where:
;;; bool Mode.7 specifies whether to truncate instead of round.
;;; bool Mode.6 specifies whether no trailing zeros is in effect.
;;; bool Mode.5 specifies a comma as decimal point instead of a dot.
;;; uint8_t Mode.4..0 == 31:  Print ALL digits.
;;;         Mode.4..0 != 31:  Specifies the rounding point resp. the
;;;                           number of fractional digits.
ENTRY uktoa
    clr     Sign
ENTRY uktoa.sign
    push    r16
    push    r17
    push    pBufArg + 0
    push    pBufArg + 1

    X_movw  pBuf, pBufArg
    mov     Digs, Mode
    cbr     Digs, 0b11100000

    ;; Output potential sign for the signed fixed-point routines.
    cpse    Sign, __zero_reg__
    st      Z+, Sign

    ;; T = FXTOA_ALL (output all).
    set
    cpi     Digs, FXTOA_ALL
    breq .LdoneRounding
    clt

    ;; Mode.7 = Truncate instead of Round.
    sbrc    Mode, BIT_NO_ROUNDING
    rjmp .LdoneRounding

    ;; Load rounder addend for the specified rounding point to D[].
    clr     D0
    clr     D1
    cpi     Digs, 1
    breq .Lrp1
    brlo .Lrp0
    cpi     Digs, 3
    breq .Lrp3
    brlo .Lrp2
    cpi     Digs, 5
    brsh .LdoneRounding

.Lrp4:  sbiw D0,     -RP4+RP3                               ; D[] = RP4
.Lrp3:  subi D0, lo8(-RP3+RP2)  $  sbci D1, hi8(-RP3+RP2)   ; D[] = RP3
.Lrp2:  subi D0, lo8(-RP2+RP1)  $  sbci D1, hi8(-RP2+RP1)   ; D[] = RP2
.Lrp1:  subi D0, lo8(-RP1+RP0)  $  sbci D1, hi8(-RP1+RP0)   ; D[] = RP1
.Lrp0:  /* lo8(-RP0) is 0 */    $  subi D1, hi8(-RP0)       ; D[] = RP0
    ;; A[] += zero-extend D[].
    add     A0, D0
    adc     A1, D1
    adc     A2, __zero_reg__
    adc     A3, __zero_reg__
    brcc .LdoneRounding

    ;; Rounding gave 65536.0
    ldi     Digit, '6'
    st      Z+, Digit
    ldi     A0,  lo8(5536 << 16)
    ldi     A1,  hi8(5536 << 16)
    ldi     A2, hlo8(5536 << 16)
    ldi     A3, hhi8(5536 << 16)

.LdoneRounding:
    subi    Digs, -IDIGS

    ldi     NonZero, '0'

    ;; A[] -= 10000  as often as possible.
    ;; Digit will hold the net number of subtractions (plus '0').
    ldi     Digit, '0' - 1
.Loop_sub_E4:
    inc     Digit
    ;; 10000  = 2710 0000, i.e. the 2 low bytes are 0.
    subi    A2, hlo8(E4)
    sbci    A3, hhi8(E4)
    brcc .Loop_sub_E4

    ;; Once Digit is unequal '0', NonZero will be non-'0' in the
    ;; remainder.  This is used to skip leading zeros.
    or      NonZero, Digit

    ;; Store Digit, skipping leading zeros.
    cpi     NonZero, '0'
    breq 0f
    st      Z+, Digit

0:  ;; Undo the underflow from the subtraction above by adding 1E4.
    subi    A2, hlo8(-E4)
    sbci    A3, hhi8(-E4)

    ;; Count finished figures, including the skipped ones.
    ldi     Count, 1

.Loop_digits:
    ;; A[] -= 1000  as often as possible.
    ;; Digit will hold the net number of subtractions (plus '0').
    ldi     Digit, '0' - 1
.Loop_sub_E3:
    inc     Digit
    ;; 1000 = 03E8 0000, i.e. the low 2 bytes are 0.
    subi    A2, hlo8(E3)
    sbci    A3, hhi8(E3)
    brcc .Loop_sub_E3

    ;; Already done the integral figures.  When we are still in this
    ;; loop, then we are after '.' and have to emit the decimal point.
    cpi     Count, IDIGS
    brne 0f
    ;; Set Nonzero to true (!= '0')
    ldi     NonZero, '.'
    sbrc    Mode, BIT_COMMA
    ldi     NonZero, ','
    st      Z+, NonZero

0:  cpi     Count, IDIGS - 1
    brne 1f
    ;; Integral part is 0: Set NonZero to true (!= '0') in order to
    ;; print '0' for the integral part.
    ldi     NonZero, '.'

1:  ;; Store Digit, skipping leading zeros.
    inc     Count
    or      NonZero, Digit
    cpi     NonZero, '0'
    breq .+2
    st      Z+, Digit

    ;; Undo the underflow from the subtraction above by adding 1E3.
    subi    A0,  lo8(-E3) ; Just needed for the Z-flag
    sbci    A1,  hi8(-E3) ; Just needed for the Z-flag
    sbci    A2, hlo8(-E3)
    sbci    A3, hhi8(-E3)

    brtc 2f
    ;; FXTOA_ALL: Done all figures?
    brne 2f
    ;; Yes, but don't skip integral '0's.
    cpi     Count, IDIGS
    brsh .Lend

2:  ;; Shift a decimal 0 into A[] from the low end: A[] *= 10.
    ;; Clobbers: R26, R27, R20, R21.
    XCALL   _U(__mulsi_const_10)

    ;; Continue until the expected number of digits has been output.
    ;; Notice that we never drop out of this loop here for FXTOA_ALL.
    cp      Count, Digs
    brlo .Loop_digits

    sbrs    Mode, BIT_NO_TRAILING_0S
    rjmp .Lend

    ;; Remove trailing 0s.  Unfortunately, we don't know a priori
    ;; whether trailing 0s will be present, so kill them now.
    cpi     Count, IDIGS
    ;; Only eat 0s when they are fractional.
    breq .Lend

3:  ld      Digit, -Z
    cpi     Digit, '0'
    breq 3b
    ;; Also ditch a trailing '.' or ',' (actually the range ',' ... '.').
    subi    Digit, ','
    cpi     Digit, 1 + '.' - ','
    brlo .Lend
    ;; Undo -Z from above.
    adiw    ZL, 1

.Lend:
    ;; The terminating '\0'.
    st      Z, __zero_reg__

    ;; Return buf[].
    pop     r25
    pop     r24
    ;; Epilogue
    pop     r17
    pop     r16
    ret
ENDFUNC

#endif /* !AVR_TINY */
