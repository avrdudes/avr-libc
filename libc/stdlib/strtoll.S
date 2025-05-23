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

#include <errno.h>
#include "asmdef.h"
#include "strtoxx.h"
#include "strto64.h"

#if B_SIGN != 0
#error
#endif

;;; long long strtoll (const char *nptr, char **endptr, int ibase);
;;;     R18 = strtoll (const char *R24,  char **R22,    int R20);

ENTRY strtoll
    ;; Push Y, R17...R8
    do_prologue_saves 12

    X_movw      Nptr, r24
    X_movw      ENDptr, r22
    ldi         r24, lo8(gs(__strto64.madd))
    ldi         r25, hi8(gs(__strto64.madd))

    ;; A[] := 0
#ifdef __AVR_HAVE_MUL__
    clr         A0
    clr         A1
    X_movw      A2, A0
    X_movw      A4, A0
    X_movw      A6, A0
#else
    XCALL       _U(__strto64.clr_result)
#endif /* Have MUL */

    ;; A[] = strtoxx.worker (const char *Y, char **Z, R20 ibase, R24 & madd())
    ;; Sets Flags.B_SIGN.
    XCALL       _U(__strtoxx.worker)
    brts .Large                     ; Overflowed
    X_movw      RET6, A6
    X_movw      RET4, A4
    X_movw      RET2, A2
    ;X_movw     RET0, A0  ; RET0 === A0

    ;; T only handles the cases where |A| >= 2^64, hence check for s64 bounds.
    ;; Compare against 0x8000000000000000 (Sign = 0).
    ;; Compare against 0x8000000000000001 (Sign = 1).
    andi        Flags, 1 << B_SIGN  ; B_SIGN is bit 0.
    ldi         r27, 0x80
    cp          RET0, Flags
    cpc         RET1, __zero_reg__
    cpc         RET2, __zero_reg__
    cpc         RET3, __zero_reg__
    cpc         RET4, __zero_reg__
    cpc         RET5, __zero_reg__
    cpc         RET6, __zero_reg__
    cpc         RET7, r27
    brsh .Large

    ;; Apply sign.
#ifdef __AVR_ERRATA_SKIP_JMP_CALL__
    sbrs        Flags, B_SIGN
    rjmp .Lret
#else
    sbrc        Flags, B_SIGN
#endif
    XCALL       _U(__negdi2)

.Lret:
    do_epilogue_restores 12

.Large:
    ;; Handle overflow
    ;; C := Sign == 1 ? 0 : 1
    inc         Flags
    lsr         Flags
    ;; RET[] := Sign ? INT64_MIN : INT64_MAX
    XCALL       _U(__sbc_8)
    subi        RET7, 0x80
    ldi         XL, lo8(ERANGE)
    ldi         XH, hi8(ERANGE)
    XCALL       _U(__strtoxx.set_errno)
    rjmp .Lret
ENDFUNC

#endif /* !AVR_TINY */
