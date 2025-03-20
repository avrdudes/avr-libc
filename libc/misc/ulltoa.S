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

/* $Id$	*/

#ifndef __AVR_TINY__

#include "asmdef.h"

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
#define Radix   r14

/*  The algorithm works for all radices and also doesn't require divmod
    (not even the 64/8 divmod like used in the previous implementation).
    It works as follows:  The value is shifted to the left, and as the
    bits are appearing at the high end, the expansion is also shifted
    to the left, but taking care that the expanded digits remain in the
    range [ 0, Radix-1 ].  Larger digits will produce a carry to the
    next higher digit.  For example, converting 20 = 0x14 to decimal will
    expand the digits like:
    ...                ...
    0                  * 2 + bit6=0  no bits yet
    0                  * 2 + bit5=0  no bits yet
    1                  * 2 + bit4=1
    2                  * 2 + bit3=0
    5                  * 2 + bit2=1
    01                 * 2 + bit1=0  digit0 overflowed: append one more digit
    02  = strrev(20)   * 2 + bit0=0

    The code consumes 4 instructions more than the old 64/8 divmod method.  */

#define Sign        r27           /* Passed down from lltoa. */
#define Len         r27           /* Length of the expansion so far.  */
#define Digit       r26
#define Zero        __zero_reg__
#define n_Digits    Zero          /* Loop counter Len ... 0   */
#define n_Bits      __tmp_reg__   /* Loop counter 64+1 ... 0  */

#define RADIX_MAX 36
#define RADIX_MIN  2

/*
    * Overall invocation costs ca 35 cycles.
    * The 64-bit loop runs 64 times for all values. One costs 13 cycles.
    * The digit loop is invoked B times where B is the number of bits.
      Invoking (without running) the digit loop costs 6 cycles.
    * One digit loop costs 11.5 cycles.  It runs
      D*(D+1)/2 * ln(Radix)/ln(2)  times where D is the number of digits.
    * Increasing the length costs 5 and is invoked D times.
    * One ASCII loop costs 11 cycles and runs D times.
    * Reverting the string costs 6 * D + 12 * D/2 cycles.

    D = 1 + floor (ln(X) / ln(Radix))

    = 13 * 64 + 35 + 11.5 * D^2 * ln(Radix) / (2*ln2) + 22 * D
    = 870 + 8.3 * D^2 * ln(Radix) + 34 * D.  */

ENTRY _U(__ulltoa)
    clr     Sign
ENTRY _U(__ulltoa.sign)
    ;; Radix in [2, 36] ?
    X_movw  ZL, Radix
    sbiw    ZL, RADIX_MIN
    sbiw    ZL, RADIX_MAX + 1 - RADIX_MIN
    X_movw  ZL, pBufArg
    brlo 1f
    ;;  No
    ldi     Sign, '?'
    rjmp .Lsign
1:
    ;; Yes
    push    Sign
    ;; Work with Radix-1 so that Carry = compare (Radix-1, Digit).
    dec     Radix
    ldi     Len, 64 + 1
    mov     n_Bits, Len

    ldi     Len, 1
    clt                         ; Non-zero ?

.Lnext_bit_stZero:
    st      Z, Zero             ; Store 1 when we come from below.
.Lnext_bit:
    mov     n_Digits, Len
    X_movw  ZL, pBufArg
.Loop_bits:
    dec     n_Bits
    breq .Loop_to_ascii
    lsl     A0
    rol     A1
    rol     A2
    rol     A3
    rol     A4
    rol     A5
    rol     A6
    rol     A7
    brts .Loop_digits
    brcc .Loop_bits
    ;; C = 1: Value is non-0.
    set

    ;; A loop to compute 2 * buf[] + C.
.Loop_digits:
    ld      Digit, Z
    ;; Carry survived from the previous CP below.
    rol     Digit
    ;; C = Radix - 1 < Digit  <=>  Digit >= Radix
    cp      Radix, Digit
    brcc 1f
    sbc     Digit, Radix        ; Digit -= (Radix - 1) + 1
    sec
1:  st      Z+, Digit
    dec     n_Digits
    brne .Loop_digits
    ;; Zero == 0 again.
    brcc .Lnext_bit
    ;; C = 1 drops out of LSL'ing the digits: One more digit, which is 1.
    inc     Len
    inc     Zero                ; Zero = 1
    rjmp .Lnext_bit_stZero

    ;; Convert the digits to ASCII.
.Loop_to_ascii:
    ld      Digit, Z
    subi    Digit, -'0'
    cpi     Digit, '9' + 1
    brlo 1f
    ;; Digits after '9' are: 'a', 'b', c', ...
    subi    Digit, '0' + 10 - 'a'
1:  st      Z+, Digit
    dec     n_Digits
    brne .Loop_to_ascii
    ;; Zero == 0 again.

    ;; Restore Radix (R14 is callee-saved).
    inc     Radix

    ;; Output the sign (if any) and the terminating '\0'.
    pop     Sign
    cpse    Sign, Zero
.Lsign:
    st      Z+, Sign
    st      Z, Zero

    ;; Reverse string and return its address.
    X_movw  R24, pBufArg
    XJMP    _U(strrev)
ENDFUNC

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
#if 0

#define Sign    r27
#define pBuf    r30
#define Digit   r27
#define Count   r26
#define Tmp     __tmp_reg__

#define RADIX_MAX 36
#define RADIX_MIN  2

;;; char*  ulltoa (uint64_t val, char* s,   int radix)
;;; r24  = ulltoa (uint64_t R18, char* R16, int R14)
;;;
;;; Execution time is around  696*N - 623 + 3*(-1)^N for an
;;; N-digit result irrespective of Radix.

ENTRY __ulltoa
    clr     Sign
ENTRY __ulltoa.sign
    ;; Radix in [2, 36] ?
    X_movw  ZL, Radix
    sbiw    ZL, RADIX_MIN
    sbiw    ZL, RADIX_MAX + 1 - RADIX_MIN
    X_movw  pBuf, pBufArg
    brlo 1f
    ;;  No
    ldi     Sign, '?'
    rjmp .Lsign
1:  ;; Yes

    ldi     Count, 0xfe
    push    Sign
.Loop_digits:
    ;; If A[] < Radix we can use A[0] as Digit.
    mov     Digit, A0
    cp      A0, Radix
    cpc     A1, __zero_reg__
    cpc     A2, __zero_reg__
    cpc     A3, __zero_reg__
    cpc     A4, __zero_reg__
    cpc     A5, __zero_reg__
    cpc     A6, __zero_reg__
    cpc     A7, __zero_reg__
    ;; Now C is set iff A[] < Radix.
    ;; Set T = C.
    sbc     Tmp, Tmp
    bst     Tmp, 0
    ;; T = 1: This is the last digit.
    brts .Lwrite_digit

    ;; Compute Digit with 64:8 division with remainder.
    clr     Digit

.Loop_bytes:
    mov     Tmp, A7
    mov     A7, A6
    mov     A6, A5
    mov     A5, A4
    mov     A4, A3
    mov     A3, A2
    mov     A2, A1
    mov     A1, A0

.Loop_bits:
    lsl     Tmp
    rol     Digit
    cp      Digit, Radix
    ;; A0.0 = Digit < Radix
    rol     A0
    sbrs    A0, 0
    sub     Digit, Radix

    ;; Low nibble -= 2 until H underflows (8 loops).
    subi    Count, 2
    brhc .Loop_bits

    com     A0
    ;; High nibble -= 1 until C underflows (8 loops).
    ;; Notice that the SUBI above also decrements the
    ;; high nibble by 1 every 8 loops.
    subi    Count, 0x10
    brcc .Loop_bytes
    ;; Now we have Count = 0xfe again.

.Lwrite_digit:
    ;; Convert Digit to ASCII...
    subi    Digit, -'0'
    cpi     Digit, '9' + 1
    brlo 5f
    ;; Digits after '9' are: 'a', 'b', c', ...
    subi    Digit, '0' + 10 - 'a'
5:  ;; ... and store it to the reversed string
    st      Z+, Digit

    ;; Popped all digits?
    brtc .Loop_digits

    ;; Yes:  Store the sign (if any)
    pop     Sign
    cpse    Sign, __zero_reg__
.Lsign:
    st      Z+, Sign

    ;; Terminate the string with '\0'
    st      Z, __zero_reg__

    ;; Reverse the string and return R24.
    X_movw  r24, pBufArg
    XJMP    _U(strrev)
ENDFUNC
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
#endif /* 0 */

#endif /* __AVR_TINY__ */
