/* Copyright (c) 2002, Jochen Pernsteiner
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
   strstr.S
   Search string contained in a string

   Contributors:
     Created by Jochen Pernsteiner <jochen.pernsteiner@stud.fh-regensburg.de>
*/

#include "macros.inc"

#define s1_hi r25
#define s1_lo r24
#define s2_hi r23
#define s2_lo r22
#define tmp r21
#define ret_hi r25
#define ret_lo r24

;char *strstr(const char *s1, const char *s2)

.text
.global _U(strstr)
.type _U(strstr), @function
_U(strstr):
        LOAD_X(s1_lo, s1_hi)
        LOAD_Z(s2_lo, s2_hi)
        ld tmp, Z+
        tst tmp
        breq .strstr_ret
        clr ret_lo
        clr ret_hi
.strstr_loop:
        ld __tmp_reg__, X+
        tst __tmp_reg__
        breq .strstr_ret0
        cp __tmp_reg__, tmp
        brne .strstr_loop
        adiw ret_lo, 1
        ld tmp, Z+
        tst tmp
        brne .strstr_loop
        sub XL, ret_lo
        sbc XH, ret_hi
        mov ret_lo, XL
        mov ret_hi, XH
        ret
.strstr_ret0:
        clr ret_lo
        clr ret_hi
.strstr_ret:
        ret

.strstr_end:
.size _U(strstr), .strstr_end - _U(strstr)

