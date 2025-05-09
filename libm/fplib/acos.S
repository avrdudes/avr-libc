/* Copyright (c) 2002  Michael Stumpf  <mistumpf@de.pepperl-fuchs.com>
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

/* float acosf (float x);
     The acosf() function calculates the arc cosine of x; that is the value
     whose cosine is x.
 */


#if !defined(__AVR_TINY__)

#include "fp32def.h"
#include "asmdef.h"

#define PI 0x40490FDA

ENTRY_FLOAT acosf acos acosl
        ;; Save A sign
        push    rA3
        ;; Finally reverse-subtract pi/2 for 0 <= x < 1/2.
        ldi     XL, -1
        ;; A = arccos(|A|)
        XCALL   _U(__fp_asinf_acosf)
        ;; Check sign
        pop     r0
        sbrs    r0, 7
        ret
        ;; x < 0:  arccos(x) = pi - arccos(-x)
        ldi     rB0,  lo8(PI)
        ldi     rB1,  hi8(PI)
        ldi     rB2, hlo8(PI)
        ldi     rB3, hhi8(PI)
        XJMP    _U(__rsubsf3.arccos)
ENDFUNC

#endif /* !defined(__AVR_TINY__) */
