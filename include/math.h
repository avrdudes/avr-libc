/* Copyright (c) 2002, Michael Stumpf
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.
   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.

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
   math.h - mathematical functions

   Author : Michael Stumpf
            Michael.Stumpf@t-online.de

   __ATTR_CONST__ added by marekm@linux.org.pl for functions
   that "do not examine any values except their arguments, and have
   no effects except the return value", for better optimization by gcc.
 */

#ifndef __MATH_H
#define __MATH_H

#define M_PI 3.141592653589793238462643
#define M_SQRT2 1.4142135623730950488016887

#ifndef __ATTR_CONST__
#define __ATTR_CONST__ __attribute__((__const__))
#endif

#ifdef __cplusplus
extern "C" {
#endif
	
extern double cos(double) __ATTR_CONST__;
extern double fabs(double) __ATTR_CONST__;
#if 0
/* fabs seems to be built in already */
extern inline double fabs( double __x )
  { double __res;
    __asm__ __volatile__ ("andi %D0,0x7F \n\t"
		: "=d" (__res) : "0" (__x) );
    return __res;
  }
#endif
extern double fmod(double, double) __ATTR_CONST__;
extern double modf(double, double *);
extern double sin(double) __ATTR_CONST__;
extern double sqrt(double) __ATTR_CONST__;
extern double tan(double) __ATTR_CONST__;
extern double floor(double) __ATTR_CONST__;
extern double ceil(double) __ATTR_CONST__;
extern double frexp(double, int *);
extern double ldexp(double,int) __ATTR_CONST__;
extern double exp(double) __ATTR_CONST__;
extern double cosh(double) __ATTR_CONST__;
extern double sinh(double) __ATTR_CONST__;
extern double tanh(double) __ATTR_CONST__;
extern double acos(double) __ATTR_CONST__;
extern double asin(double) __ATTR_CONST__;
extern double atan(double) __ATTR_CONST__;
extern double atan2(double, double) __ATTR_CONST__;
extern double log(double) __ATTR_CONST__;
extern double log10(double) __ATTR_CONST__;
extern double pow(double, double) __ATTR_CONST__;
extern double strtod(const char *s, char **endptr);

/* non-standard functions */
extern double square(double) __ATTR_CONST__;
extern double inverse(double) __ATTR_CONST__;

#ifdef __cplusplus
}
#endif

#endif /* _MATH_H */

