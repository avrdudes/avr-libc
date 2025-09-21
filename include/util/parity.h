/* Copyright (c) 2002, Marek Michalkiewicz
   Copyright (c) 2004,2005,2007 Joerg Wunsch
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

#ifndef _UTIL_PARITY_H_
#define _UTIL_PARITY_H_

#include <stdint.h>
#include <bits/attribs.h>

/** \file */
/** \defgroup util_parity <util/parity.h>: Parity bit generation
    \code #include <util/parity.h> \endcode

    This header file contains optimized assembler code to calculate
    the parity bit for a byte.
*/
/** \fn uint8_t parity_even_bit (uint8_t val);
    \ingroup util_parity
    \returns 1 if \c val has an odd number of bits set, and 0 otherwise. */

static __ATTR_ALWAYS_INLINE__
uint8_t parity_even_bit (uint8_t __val)
{
  if (__builtin_constant_p (__builtin_parity (__val)))
    return (uint8_t) __builtin_parity (__val);

  __asm (/* parity is in [0..7] */
         "mov  __tmp_reg__, %0"  "\n\t"
         "swap __tmp_reg__"      "\n\t"
         "eor  %0, __tmp_reg__"  "\n\t"
         /* parity is in [0..3] */
         "subi %0, -4"           "\n\t"
         "andi %0, -5"           "\n\t"
         "subi %0, -6"           "\n\t"
         /* parity is in [0,3] */
         "sbrc %0, 3"            "\n\t"
         "inc  %0"
         /* parity is in [0] */
         : "+d" (__val));

  return __val & 1;
}

#endif /* _UTIL_PARITY_H_ */
