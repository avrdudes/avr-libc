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
   strcasecmp.S
   Case insensitive compare

   Contributors:
     Created by Reiner Patommel
*/
#include "macros.inc"

#define s1_hi r25
#define s1_lo r24
#define s2_hi r23
#define s2_lo r22

#define ret_hi r25
#define ret_lo r24

#define tmp r22
#define cht r21

/** \ingroup avr_string
    \fn int strcasecmp(const char *s1, const char *s2)
    \brief Compare two strings ignoring case.

    The strcasecmp() function compares the two strings s1 and s2, ignoring the
    case of the characters.  It returns an integer less than, equal to, or
    greater than zero if s1 is found, respectively, to be less than, to match,
    or be greater than s2.

    \returns The strcasecmp() function returns an integer less than, equal to,
    or greater than zero if s1 is found, respectively, to be less than, to
    match, or be greater than s2.  */

    .text
    .global _U(strcasecmp)
    .type   _U(strcasecmp), @function
_U(strcasecmp):
    LOAD_Z(s2_lo, s2_hi)
    LOAD_X(s1_lo, s1_hi)
.strcasecmp_loop:
    LD    ret_lo, X+          ; load *s1
    LD    tmp, Z+             ; load *s2
    MOV   cht, tmp            ; copy of *s2 to tmp
    ORI   cht, 0x20           ; make tmp lower case
    CPI   cht, 'a'            ; test on [a .. z]
	BRLT  .strcasecmp_tst
    CPI   cht, 'z'+1
	BRGE  .strcasecmp_tst
    ORI   tmp, 0x20           ; we got an aplpha in s2
    ORI   ret_lo, 0x20
.strcasecmp_tst:                 ; compare
    SUB   ret_lo, tmp
    BRNE  .strcasecmp_done
    TST   tmp                 ; end of s2?
    BRNE  .strcasecmp_loop
.strcasecmp_done:
; ret_hi = SREG.C ? 0xFF : 0
    SBC   ret_hi, ret_hi
    RET
.strcasecmp_end:
    .size   _U(strcasecmp), .strcasecmp_end - _U(strcasecmp)

