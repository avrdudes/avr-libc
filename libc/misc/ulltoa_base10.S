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

;;; This module implements conversion from a 64-bit integer
;;; to a decimal ASCII string.  The function complies to the
;;; avr-gcc ABI and can be used from C code by
;;;
;;;     #include <stdint.h>
;;;
;;;     extern char* __ulltoa_base10 (uint64_t value, char *buf);
;;;
;;; or with an extern "C" declaration to be used from C++.  The function
;;; writes at most 21 chars to buf[] and returns buf.
;;;
;;; The function is small (less than 200 bytes) and fast:
;;;     -  Less than 3300 cycles maximum in all variations.
;;;     -  Less than 2800 cycles maximum with MUL.
;;;     -  Less than 2000 cycles on average with MUL.
;;; The disadvantage is that it's not much faster for small inputs.
;;;
;;; During conversion, 1E18 is subtract as often as possible
;;; without causing an underflow.  As pseudo code:
;;;
;;;     Digit = 0
;;;     WHILE  Number >= Value
;;;         Number -= Value
;;;         Digit++
;;;
;;; The algorithm however implements this as
;;;
;;;     Digit = -1
;;;     DO
;;;         Digit++
;;;     WHILE  (Number -= Value) >= 0
;;;     Number += Value
;;;
;;; and performs one subtraction too much.  The underflow is undone after
;;; the loop by adding Value.  This needs  Digit + 2  operations on
;;; Number (with Digit's value after the loop), whereas the original
;;; formulation of the while loop needs  2 * Digit + 1  operations.

;; The argument registers as of avr-gcc ABI.
#define A0      18
#define A1      A0+1
#define A2      A0+2
#define A3      A0+3
#define A4      A0+4
#define A5      A0+5
#define A6      A0+6
#define A7      A0+7
#define pBufArg r16

#define pBuf    r26
#define Ten     r28
#define Count3  Ten
#define Tmp     __tmp_reg__

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; A[] *= 10 as a macro to be used below.
;; Clobbers:  R28, T (non-MUL version only), TMP_REG, R11...R17.

.macro .MUL_10

#ifdef __AVR_HAVE_MUL__

    ;; We have MUL and hence also MOVW.
    mul     A7, Ten     $ mov   R11, R0
    mul     A5, Ten     $ movw  R12, R0
    mul     A3, Ten     $ movw  R14, R0
    mul     A1, Ten     $ movw  R16, R0

    mul     A0, Ten     $ movw  A0, R0
    mul     A2, Ten     $ movw  A2, R0
    mul     A4, Ten     $ movw  A4, R0
    mul     A6, Ten     $ movw  A6, R0

    ADD     A1, R16
    adc     A2, R17
    adc     A3, R14
    adc     A4, R15
    adc     A5, R12
    adc     A6, R13
    adc     A7, R11

#else /* have MUL */

    ;; No MUL:  Compute  10*A[]  as  (A[] << 1) + (A[] << 3).
    ldi     Count3, 3
    ;; T = (Count3 == 3).
    set
.Loop_shift:
    ;; A[] <<= 1
    LSL     A0      $   rol     A1
    rol     A2      $   rol     A3
    rol     A4      $   rol     A5
    rol     A6      $   rol     A7
    brtc 2f
    ;; After the first shift: save 2*A[].
    clt
    X_movw  16, A6
    X_movw  14, A4
    X_movw  12, A2
    mov     R11, A1
    mov     Tmp, A0
2:
    dec     Count3
    brne .Loop_shift

    ;; We shifted A[] 3 times.  Add  2*A[]  to get  10*A[].
    ADD     A0, Tmp
    adc     A1, R11
    adc     A2, R12
    adc     A3, R13
    adc     A4, R14
    adc     A5, R15
    adc     A6, R16
    adc     A7, R17

#endif /* Have MUL? */

.endm  ; .MUL_10
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

#define NonZero r31
#define Count   r29
#define Zero    r30

;; Registers that don't need to survive .MUL10.
#define Digit   r17
#define One     r16

;; extern char* ulltoa_base10 (uint64_t value, char *buf);

;; Returns buf.
;; Writes at most 21 characters to *buf (including the final '\0').
;;
;;                   |   with MUL   | no MUL, no MOVW
;; ------------------+--------------+-----------------
;; Ticks         (*) |  83 -- 2800  |   85 -- 3210
;; Ticks (mean)  (*) |   < 2000     |    < 2400
;; Code size    (**) |      168     |       182
;; Static storage    |        0     |         0
;; Stack usage   (*) |   11 -- 12   |        11
;;
;; (*)  Including CALL + RET.
;; (**) In bytes, including all dependencies.

ENTRY   __ulltoa_base10
    X_movw  pBuf, pBufArg

;; Entry point from __lltoa_base10.
ENTRY __ulltoa_base10.X
    push    r11
    push    r12
    push    r13
    push    r14
    push    r15
    push    r16
    push    r17
    push    r28
    push    r29

    ldi     Count, 19
    ldi     NonZero, '0'
    ldi     Zero, '0'       ; const
#ifdef __AVR_HAVE_MUL__
    ldi     Ten, 10         ; const
#endif

.Loop_digits:
    ;; A[] -= 1.000.000.000.000.000.000  as often as we can.
    ;; Digit will hold the net number of subtractions (plus '0').
    ldi     Digit, '0' - 1

.Loop_sub:
    inc     Digit
    ;;  1.000.000.000.000.000.000 = 0DE0 B6B3 A764 0000 = 1e18
    ;; 18.446.744.073.709.551.615 = FFFF FFFF FFFF FFFF
    subi    A2, 0x64
    sbci    A3, 0xa7
    sbci    A4, 0xb3
    sbci    A5, 0xb6
    sbci    A6, 0xe0
    sbci    A7, 0xd
    brcc .Loop_sub

    ;; Once Digit is unequal '0', NonZero will be non-'0' in the
    ;; remainder.  This is used to skip leading zeros.
    or      NonZero, Digit

    cpi     Digit, '9' + 1
    brlo .Less_than_1E19
    ;; UINT64_MAX >= 1E19, hence in the first iteration we can
    ;; have Digit up to '0' + 18.  Rectify this now.
    subi    Digit, 10
    ldi     One, '1'
    st      X+, One

.Less_than_1E19:
    ;; Store Digit, skipping leading zeros.
    cpse    NonZero, Zero
    st      X+, Digit

    ;; Undo the underflow from the subtraction above by adding 1E18.
    ;; -1.000.000.000.000.000.000 = F21F 494C 589C 0000
    subi    A0, 0       ; Just needed for the Z-flag
    sbci    A1, 0       ; Just needed for the Z-flag
    sbci    A2, 0x9c
    sbci    A3, 0x58
    sbci    A4, 0x4c
    sbci    A5, 0x49
    sbci    A6, 0x1f
    sbci    A7, 0xf2

    ;; As we are removing decimal digits at the high end (by means
    ;; of the subtractions above), and are "shifting" in decimal
    ;; digits 0 at the low end (my means of the multipliction with 10
    ;; below), A[] will finally become 0.
    breq .L_zero

    ;; A[] *= 10.  This shifts the (decimal) digits to the high end.
    ;; The multiplication will never overflow.  The variant with MUL
    ;; clobberes __zero_reg__, but we never need it until the final '\0'.
    .MUL_10

    ;; Continue until the BREQ above quits the loop.
    dec     Count
    rjmp .Loop_digits

.L_zero:

#ifdef __AVR_HAVE_MUL__
    ;; This version of .MUL_10 clobbered __zero_reg__, restore it.
    clr     __zero_reg__
#endif

    ;; A[] is divisible by 10^Count, and we drop out of the digit loop after
    ;; all non-'0' digits are consumed.  We have to handle 19 digits total
    ;; (including the skipped '0's and counting the case A[] >= 1E19 as one).
    ;; Hence append the missing Count '0's to finish the conversion.

    cpi     NonZero, '0'
    brne .L_final_0s
    ;; Special-case "0":  We did not emit anything yet, tweak Count
    ;; so that we emit exactly one '0'.
    ldi     Count, 1

.Loop_final_0s:
    st      X+, Zero
.L_final_0s:
    dec     Count
    brne .Loop_final_0s

    ;; The terminating '\0'.
    st      X, __zero_reg__

    pop     r29
    pop     r28
    pop     r17
    pop     r16
    pop     r15
    pop     r14
    pop     r13
    pop     r12
    pop     r11
    X_movw  r24, pBufArg
    ret
ENDFUNC

#endif /* no AVR_TINY */
