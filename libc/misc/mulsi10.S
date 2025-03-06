/* Copyright (c) 2002, Reiner Patommel
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

/*
   mulsi10.S - optimized 32-bit multiply by 10

   Contributors:
     Created by Reiner Patommel <rpatop@post4.tele.dk> based on
	 mul10.S by Marek Michalkiewicz <marekm@linux.org.pl>
 */

#if !defined(__DOXYGEN__)

#include "asmdef.h"

#define A0      r22
#define A1      r23
#define A2      r24
#define A3      r25

#define Tmp0    r26
#define Tmp1    r27
#define Tmp2    r20
#define Tmp3    r21

#define Ten     r20

;;; A3:A2:A1:A0 *= 10
;;; Clobbers: R26 (only non-MUL), R27, R20, R21
;;; uint32_t __mulsi_const_10 (uint32_t);
;;; uint32_t __mulsi_u8 (uint32_t, uint8_t);  MUL only

ENTRY _U(__mulsi_const_10)
#ifdef __AVR_HAVE_MUL__
    ldi     Ten, 10
ENTRY _U(__mulsi_u8)
    mov     Tmp1, A1
    mov     Tmp3, A3

    mul     A0, Ten
    movw    A0, r0

    mul     A2, Ten
    movw    A2, r0

    mul     Tmp3, Ten
    add     A3, r0

    mul     Tmp1, Ten
    add     A1, r0
    adc     A2, r1
    clr     __zero_reg__
    adc     A3, __zero_reg__
#else
    X_movw  Tmp2, A2
    X_movw  Tmp0, A0
    LSL A0
    rol A1
    rol A2
    rol A3              ; d *= 2
    LSL A0
    rol A1
    rol A2
    rol A3              ; d *= 4
    ADD A0, Tmp0
    adc A1, Tmp1
    adc A2, Tmp2
    adc A3, Tmp3        ; d *= 5
    LSL A0
    rol A1
    rol A2
    rol A3              ; d *= 10
#endif /* Have MUL */
    ret
ENDFUNC

#endif /* not __DOXYGEN__ */
