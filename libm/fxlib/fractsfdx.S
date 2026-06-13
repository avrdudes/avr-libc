/* Copyright (c) 2026  Georg-Johann Lay
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

#ifdef __DA_FBIT__

#if (__TA_FBIT__ & __DA_FBIT__ & __DQ_FBIT__) % 2 != 1
#error
#endif

;; Subtract FBIT from the float exponent right away.
;; In the case of 0.0f we will get a subnormal that maps to 0.

#define exp_lo(N)  hlo8 ((N) << 23)
#define exp_hi(N)  hhi8 ((N) << 23)

ENTRY __fractsfdq
    subi    r25, exp_hi (__TA_FBIT__ - __DQ_FBIT__)

ENTRY __fractsfta
    subi    r25, exp_hi (__DA_FBIT__ - __TA_FBIT__)

ENTRY __fractsfda
    subi    r24, exp_lo (-__DA_FBIT__)
    sbci    r25, exp_hi (-__DA_FBIT__)

    XJMP    _U(__fixsfdi)
ENDFUNC

#endif /* __DA_FBIT__ */
