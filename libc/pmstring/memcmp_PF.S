/* Copyright (c) 2010  Jan Waclawek

   based on libc/pmstring/memcmp_P.S which is
   Copyright (c) 2002, 2007 Marek Michalkiewicz
   Copyright (c) 2007  Dmitry Xmelkov
   and on exteded program memory routines, which are
   Copyright (c) 2006, Carlos Lamas

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

/* $Id$ */

/** \file */

/** \ingroup avr_pgmspace
    \fn int memcmp_PF(const void *s1, uint_farptr_t s2, size_t len)
    \brief Compare memory areas

    The memcmp_PF() function compares the first \p len bytes of the memory
    areas \p s1 and flash \p s2. The comparision is performed using unsigned
    char operations. It is an equivalent of memcmp_P() function, except
    that it is capable working on all FLASH including the exteded area
    above 64kB.

    \returns The memcmp_PF() function returns an integer less than, equal
    to, or greater than zero if the first \p len bytes of \p s1 is found,
    respectively, to be less than, to match, or be greater than the first
    \p len bytes of \p s2.  */


#if !defined(__AVR_TINY__)

#if !defined(__DOXYGEN__)

#include "macros.inc"

#define s1_b1 r25
#define s1_b0 r24
#define s2_b3 r23
#define s2_b2 r22
#define s2_b1 r21
#define s2_b0 r20
#define len_b1 r19
#define len_b0 r18

#define ret_b1 r25
#define ret_b0 r24

/* the conditional caters for pre-1.6.8 libc and standalone use */
#ifdef ASSEMBLY_CLIB_SECTION
  ASSEMBLY_CLIB_SECTION
#else
  .text
#endif
  .global _U(memcmp_PF)
  .type _U(memcmp_PF), @function
_U(memcmp_PF):
  X_movw  ZL, s2_b0
  LPM_R0_ZPLUS_INIT s2_b2
  X_movw  XL, s1_b0

  rjmp  2f

1:
  ld    ret_b0, X+
  LPM_R0_ZPLUS_NEXT s2_b2
  sub   ret_b0, r0
  brne  3f
2:
  subi  len_b0, lo8(1)
  sbci  len_b1, hi8(1)
  brsh  1b

  sub   ret_b0, ret_b0
3:
  sbc   ret_b1, ret_b1
  ret

  .size _U(memcmp_PF), . - _U(memcmp_PF)

#endif /* not __DOXYGEN__ */

#endif /* !defined(__AVR_TINY__) */
