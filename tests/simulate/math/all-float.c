/* Copyright (c) 2009  Dmitry Xmelkov
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

/* Test of math function float aliases. */
#include <math.h>
#include <stdlib.h>

#define CMP(fun) if ((void*) fun != (void*) fun##f) exit (__LINE__)

int main (void)
{
#if defined(__AVR__) && __SIZEOF_DOUBLE__ == __SIZEOF_FLOAT__
    volatile float x = 0.25, y, z;
    volatile int i;

    CMP (cos);
    CMP (sin);
    CMP (tan);

    y = fabs (x);
    z = fabsf (x);
    if (y != z) exit (__LINE__);

    CMP (fmod);
    CMP (modf);

    CMP (sqrt);
    CMP (cbrt);
    CMP (hypot);
    CMP (square);

    CMP (floor);
    CMP (ceil);

    CMP (frexp);
    CMP (ldexp);

    CMP (exp);
    CMP (cosh);
    CMP (sinh);
    CMP (tanh);

    CMP (acos);
    CMP (asin);
    CMP (atan);
    CMP (atan2);

    CMP (log);
    CMP (log10);
    CMP (pow);

    i = isnan (x);
    if (isnanf (x) != i) exit (__LINE__);

    i = isinf (x);
    if (isinff (x) != i) exit (__LINE__);

    i = isfinite (x);
    if (isfinitef (x) != i) exit (__LINE__);

    y = copysign (x, -1.0f);
    if (copysignf (x, -1.0f) != y) exit (__LINE__);

    i = signbit (x);
    if (signbitf (x) != i) exit (__LINE__);

    CMP (fdim);
    CMP (fma);
    CMP (fmax);
    CMP (fmin);

    CMP (trunc);
    CMP (round);
    CMP (lround);
    CMP (lrint);
#endif

    return 0;
}
