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

#if !defined(__AVR_TINY__)

#include "fp32def.h"
#include "asmdef.h"

;;; void sincosf (float A, float *psin, float *pcos);

ENTRY_FLOAT sincosf sincos sincosl
    push    YH
    push    YL
    push    r19                 ; pcos
    push    r18
    X_movw  YL, r20             ; psin
    push    rA3
    XCALL   _U(__fp_rempio2)
    pop     r0
    ;; Push rempio2 result for later.
    push    rA3
    push    rA2
    push    rA1
    push    rA0
    push    rAE
    push    ZL
    ;; Proceed with sin computation.
    sbrc    r0, 7
    subi    ZL, -2
    XCALL   _U(__fp_sinus)
    ;; *psin = sin (x)
    std     Y+0, rA0
    std     Y+1, rA1
    std     Y+2, rA2
    std     Y+3, rA3
    ;; Restore rempio result for cos.
    pop     ZL
    pop     rAE
    pop     rA0
    pop     rA1
    pop     rA2
    pop     rA3
    ;; Y = pcos
    pop     YL
    pop     YH
    ;; Vanilla cos computation.
    inc ZL
    XCALL   _U(__fp_sinus)
    ;; *pcos = cos (x)
    std     Y+0, rA0
    std     Y+1, rA1
    std     Y+2, rA2
    std     Y+3, rA3
    ;; Epilogue
    pop     YL
    pop     YH
    ret
ENDFUNC

#endif /* !defined(__AVR_TINY__) */
