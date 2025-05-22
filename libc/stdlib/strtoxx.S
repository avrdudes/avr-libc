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

;;; This file contains worker and helper functions for strto[u][l]l.
;;; The caller is responsible for saving all GPRs to please the ABI.

#ifndef __AVR_TINY__

#include <errno.h>
#include "asmdef.h"
#include "strtoxx.h"

;; A[] = strtoxx.worker (const char *Z, char **Y, int R20 ibase,
;;                       uint8_t R26 Flags, r24 (*madd)())
FUNCTION __strtoxx.worker
.Leinval:
    ldi         XL, lo8(EINVAL)
    ldi         XH, hi8(EINVAL)

;;; errno = X
ENTRY __strtoxx.set_errno
    sts         errno+0, XL
    sts         errno+1, XH
    ret

ENTRY __strtoxx.worker
    clt                         ; Clear unsigned overflow.
    clr         Flags
    rcall       .Lstore_nptr

    ;; Check ibase.
    tst         r21
    brne .Leinval
    mov         Radix, r20
    cpi         Radix, 37
    brsh .Leinval
    cpi         Radix, 1
    breq .Leinval

    X_movw      PFmadd, r24

    ;; Consume initial white-spaces.
.Loop_space:
    ld          Digit, Z+
    mov         r24, Digit
    XCALL       _U(__isspace.ignore_r25)
    tst         r24             ; true ?
    brne .Loop_space

    ;; Consume optional sign.
    cpi         Digit, '+'
    breq 0f
    cpi         Digit, '-'
    brne 1f
    ori         Flags, 1 << B_SIGN
0:  ld          Digit, Z+
1:
    ;; Consume optional radix determinator.
    cpi         Digit, '0'
    breq 0f
    tst         Radix
    brne .Lno_prefix
    ldi         Radix, 10
    rjmp .Lno_prefix

0:  ;; Payload starts with '0': May be octal, or 0x (hex), 0b (bin), 0o (oct).
    ori         Flags, 1 << B_PAYLOAD
    ld          r24, Z
    cpi         r24, 'a'
    brsh 1f
    subi        r24, 'A' - 'a'
1:  clr         Prefix
    cpi         r24, 'x'
    breq 16f
    cpi         r24, 'o'        ; C26 instroduces 0o as octal prefix.
    breq 8f
    cpi         r24, 'b'
    breq 2f
    ;; '0' indicates octal.
    tst         Radix
    brne .Lnext_digit
    ldi         Radix, 8
    rjmp .Lnext_digit

2:  subi        Prefix, 8  - 2
8:  subi        Prefix, 16 - 8
16: subi        Prefix, 0  - 16
    tst         Radix
    breq 3f
    cp          Prefix, Radix
    brne .Lnext_digit
3:  ;; Set Radix from prefix.
    mov         Radix, Prefix
    ;; Consume
    ori         Flags, 1 << B_PREFIXED
    adiw        ZL, 1

.Lnext_digit:
    ld          Digit, Z+

.Lno_prefix:
    ;; Convert Digit to its value.
    cpi         Digit, '9' + 1
    brlo 5f
    cpi         Digit, 'a'
    brlo 4f
    subi        Digit, 'a' - 'A'
4:  subi        Digit, 'A'
    cpi         Digit, 'Z' + 1 - 'A'
    brsh .Lstop1
    subi        Digit, -10 - '0'
5:  subi        Digit, '0'
    cp          Digit, Radix
    brsh .Lstop1
    cbr         Flags, 1 << B_PREFIXED
    ori         Flags, 1 << B_PAYLOAD
    ;; Overflowed: Just consume remaining valid digits.
    brts .Lnext_digit

    ;; A[] := A[] * Radix + Digit
    push        r30
    push        r31
    X_movw      r30, PFmadd

    XICALL

    pop         r31
    pop         r30
    rjmp .Lnext_digit

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

.Lstop1:                        ; Z points 1 past an unrecognized char.
    sbrs        Flags, B_PAYLOAD
    ret
    sbrc        Flags, B_PREFIXED
    ;; When the 1st digit is not valid, then the 'x' in "0x" is invalid, too.
    sbiw        Nptr, 1
    sbiw        Nptr, 1
.Lstop0:                        ; Z points to an unrecognized char.
.Lstore_nptr:
    sbiw        ENDptr, 0
    breq 9f
    std         Y+0, Nptr+0
    std         Y+1, Nptr+1
9:  ret

ENDFUNC

#endif /* AVR_TINY */
