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
   strncasecmp_P.S
   Case insensitive compare

   Contributors:
     Created by Reiner Patommel
*/
#include "macros.inc"

#define s1_hi r25
#define s1_lo r24
#define s2_hi r23
#define s2_lo r22
#define len_hi r21
#define len_lo r20
#define cht r19
#define tmp r18

#define ret_hi r25
#define ret_lo r24

; int strncasecmp_P(const char *s1, const char flash *s2, size_t len)

    .text
    .global _U(strncasecmp_P)
    .type   _U(strncasecmp_P), @function
_U(strncasecmp_P):
    LOAD_Z(s2_lo, s2_hi)
    LOAD_X(s1_lo, s1_hi)
.strncasecmp_P_loop:
    SUBI      len_lo, lo8(1)
    SBCI      len_hi, hi8(1)
    BRCS      .strncasecmp_P_equal
    LD        ret_lo, X+               ; load *s1
    LPM_R0_ZP                          ; load *s2
    MOV       tmp, r0                  ; copy of *s2 to tmp
    MOV       cht, r0                  ; copy of *s2 to cht
    ORI       cht, 0x20                ; make it lower case
    CPI       cht, 'a'                 ; test on [a .. z]
    BRLT      .strncasecmp_P_tst
    CPI       cht, 'z'+1
    BRGE      .strncasecmp_P_tst
    ORI       tmp, 0x20                ; we got an alpha in s2
    ORI       ret_lo, 0x20             ; make *s1, *s2 lower case
   .strncasecmp_P_tst:
    SUB       ret_lo, tmp
    BRNE      .strncasecmp_P_done
    TST       r0
    BRNE      .strncasecmp_P_loop
.strncasecmp_P_equal:
    SUB       ret_lo, ret_lo
.strncasecmp_P_done:
; ret_hi = SREG.C ? 0xFF : 0
    SBC       ret_hi, ret_hi
    RET
.strncasecmp_P_end:
    .size   _U(strncasecmp_P), .strncasecmp_P_end - _U(strncasecmp_P)

