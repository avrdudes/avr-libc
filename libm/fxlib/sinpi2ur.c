/* Copyright (c) 2025  Georg-Johann Lay
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
   POSSIBILITY OF SUCH DAMAGE.  */

#include <stdfix.h>

#define T unsigned fract

static inline __attribute__((always_inline))
T rsub1 (T x)
{
  __asm ("com %A0 $ com %B0" : "+r" (x));
  return x;
}


T sinpi2ur (T x)
{
  // sinpi2(x) - x has 2 zeros instead of just one.  Factor them out and
  // mulitply them back in below.  Just like MiniMax for sinpi2 this
  // costs 5 MULs, but the zeros are taming the errors at both ends.
  T a0 = 0.5706834793;
  T a1 = 0.5741653442;
  T a2 = 0.0906479359;
  T a3 = 0.0543137789;

  // Reformulate the MiniMax polynomial such that the coefficients
  // and intermediate values are all in [0, 1).

  T y = a3;
  y = a2 + x * y;
  y = a1 - x * y;
  y = a0 + x * y;

  // y = y * x * (1 - x) + x
  y *= x;   x = rsub1 (x);
  y *= x;   x = rsub1 (x);
  y += x;

  // Finally, nudge the absolute error for some inputs.

  unsigned char hi = bitsur (x) >> 8;
  if (hi >= 0x5e && hi <= 0xab)
    y += urbits (2);

  return y;
}
