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
   POSSIBILITY OF SUCH DAMAGE.
 */

/* Test of math function float aliases.
   $Id$
 */
#include <math.h>
#include <stdlib.h>

int main ()
{
    volatile float x = 0.25, y, z;
    volatile int i;
    volatile long l;
    double z1;
    float z2;
    int k1, k2;

    y = cos (x);
    z = cosf (x);
    if (y != z) exit (__LINE__);

    y = sin (x);
    z = sinf (x);
    if (y != z) exit (__LINE__);

    y = tan (x);
    z = tanf (x);
    if (y != z) exit (__LINE__);

    y = fabs (x);
    z = fabsf (x);
    if (y != z) exit (__LINE__);

    y = fmod (x, 0.75f);
    z = fmodf (x, 0.75f);
    if (y != z) exit (__LINE__);

    y = modf (x, &z1);
    z = modff (x, &z2);
    if (y != z || z1 != z2) exit (__LINE__);

    y = sqrt (x);
    z = sqrtf (x);
    if (y != z) exit (__LINE__);

    y = cbrt (x);
    z = cbrtf (x);
    if (y != z) exit (__LINE__);

    y = hypot (x, 1.0f);
    z = hypotf (x, 1.0f);
    if (y != z) exit (__LINE__);

#ifdef	__AVR__
    y = square (x);
    z = squaref (x);
    if (y != z) exit (__LINE__);
#endif

    y = floor (x);
    z = floorf (x);
    if (y != z) exit (__LINE__);

    y = ceil (x);
    z = ceilf (x);
    if (y != z) exit (__LINE__);

    y = frexp (x, &k1);
    z = frexpf (x, &k2);
    if (y != z || k1 != k2) exit (__LINE__);

    y = ldexp (x, 3);
    z = ldexpf (x, 3);
    if (y != z) exit (__LINE__);

    y = exp (x);
    z = expf (x);
    if (y != z) exit (__LINE__);

    y = cosh (x);
    z = coshf (x);
    if (y != z) exit (__LINE__);

    y = sinh (x);
    z = sinhf (x);
    if (y != z) exit (__LINE__);

    y = tanh (x);
    z = tanhf (x);
    if (y != z) exit (__LINE__);

    y = acos (x);
    z = acosf (x);
    if (y != z) exit (__LINE__);

    y = asin (x);
    z = asinf (x);
    if (y != z) exit (__LINE__);

    y = atan (x);
    z = atanf (x);
    if (y != z) exit (__LINE__);

    y = atan2 (x, 1.0f);
    z = atan2f (x, 1.0f);
    if (y != z) exit (__LINE__);

    y = log (x);
    z = logf (x);
    if (y != z) exit (__LINE__);

    y = log10 (x);
    z = log10f (x);
    if (y != z) exit (__LINE__);

    y = pow (x, 3.0f);
    z = powf (x, 3.0f);
    if (y != z) exit (__LINE__);

    i = isnan (x);
    if (isnanf (x) != i) exit (__LINE__);

    i = isinf (x);
    if (isinff (x) != i) exit (__LINE__);

#ifdef	__AVR__
    i = isfinite (x);
    if (isfinitef (x) != i) exit (__LINE__);
#endif

    y = copysign (x, -1.0f);
    if (copysignf (x, -1.0f) != y) exit (__LINE__);

#ifdef	__AVR__
    i = signbit (x);
    if (signbitf (x) != i) exit (__LINE__);
#endif

    y = fdim (x, -1.0f);
    if (fdimf (x, -1.0f) != y) exit (__LINE__);

    y = fma (x, 2.0f, 3.0f);
    if (fmaf (x, 2.0f, 3.0f) != y) exit (__LINE__);

    y = fmax (x, 0.0f);
    if (fmaxf (x, 0.0f) != y) exit (__LINE__);

    y = fmin (x, 1.0f);
    if (fminf (x, 1.0f) != y) exit (__LINE__);

    y = trunc (x);
    if (truncf (x) != y) exit (__LINE__);

    y = round (x);
    if (roundf (x) != y) exit (__LINE__);

    l = lround (x);
    if (lroundf (x) != l) exit (__LINE__);

    l = lrint (x);
    if (lrintf (x) != l) exit (__LINE__);

    return 0;
}
