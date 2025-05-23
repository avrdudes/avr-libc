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
#include "strto32.h"

;;; unsigned long strtoul (const char *nptr, char **endptr, int ibase);
;;;         R18 = strtoul (const char *R24,  char **R22,    int R20);

ENTRY strtoul
    push        r14
    push        r15
    push        r16
    push        r17
    push        r28
    push        r29

    X_movw      Nptr, r24
    X_movw      ENDptr, r22
    ldi         r24, lo8(gs(__strto32.madd))
    ldi         r25, hi8(gs(__strto32.madd))

    ;; A[] := 0
#ifdef __AVR_HAVE_MUL__
    clr         A0
    clr         A1
    X_movw      A2, A0
#else
    XCALL       _U(__strto32.clr_result)
#endif

    ;; A[] = strtoxx.worker (const char *Y, char **Z, R20 ibase, R24 & madd())
    ;; Sets Flags.B_SIGN.
    XCALL       _U(__strtoxx.worker)
    X_movw      RET2, A2
    X_movw      RET0, A0
    pop         r29
    pop         r28
    pop         r17
    pop         r16
    pop         r15
    pop         r14

    brts .Large                     ; Overflowed

    ;; Apply sign.
    sbrs        Flags, B_SIGN
    ret
    XJMP        _U(__negsi2)

.Large:
    ;; RET[] := UINT32_MAX
    ldi         RET0, 0xff
    ldi         RET1, 0xff
    X_movw      RET2, RET0
    ldi         XL, lo8(ERANGE)
    ldi         XH, hi8(ERANGE)
    XJMP        _U(__strtoxx.set_errno)

ENDFUNC

#endif /* !AVR_TINY */
