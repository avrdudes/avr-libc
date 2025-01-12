/* Copyright (c) 2013 Joerg Wunsch
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

#ifndef _STDFIX_AVRLIBC_H
#define _STDFIX_AVRLIBC_H

/*
 * AVR-LibC addendum file for Embedded C Fixed-Point support
 *
 * See: ISO/IEC TR 18037
 * http://www.open-std.org/jtc1/sc22/wg14/www/docs/n1169.pdf
 */

#ifndef _AVRGCC_STDFIX_H  /* Defined in stdfix.h from avr-gcc */
#warning please include <stdfix.h> directly rather than <stdfix-avrlibc.h>
#endif /* _AVRGCC_STDFIX_H */

#ifndef __ATTR_CONST__
#define __ATTR_CONST__ __attribute__((__const__))
#endif

/* Room for AVR-LibC specific extensions */

/* 7.18a.6.1 The fixed-point arithmetic operation support functions */

/*
 * The functions below compute the result of the multiplication or division
 * operation on the operands with the indicated types, and return a value with
 * the indicated type.  The return value is rounded towards zero, and is
 * saturated on overflow.  If the second operand of one of the divide
 * functions is zero, the behavior is undefined.
 */

#ifdef __cplusplus
extern "C" {
#endif

/*
 * The rdivi() function computes the value \c num/denom and returns the
 * result of the \c fract type.
 */
__ATTR_CONST__
extern fract rdivi (int num, int denom);

/*
 * The lrdivi() function computes the value of \c num/denom and returns the
 * result of the long fract type.
 */
__ATTR_CONST__
extern long fract lrdivi (long int num, long int denom);

/*
 * The urdivi() function computes the value \c num/denom and returns the
 * result of the \c unsigned \c fract type.
 */
__ATTR_CONST__
extern unsigned fract urdivi (unsigned int num, unsigned int denom);

/*
 * The ulrdivi() function computes the value of \c num/denom and returns the
 * result of the unsigned long fract type.
 */
__ATTR_CONST__
extern unsigned long fract
ulrdivi (unsigned long int num, unsigned long int denom);

#ifdef __cplusplus
}
#endif

#endif /* _STDFIX_AVRLIBC_H */
