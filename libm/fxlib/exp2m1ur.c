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
T not (T x)
{
  __asm ("com %A0 $ com %B0" : "+r" (x));
  return x;
}


// 2^x - 1 over [0, 1).

T exp2m1ur (T x)
{
  // MiniMax polynomial to reconstruct the target function according
  // to  f(x) = x - a(x) * x * (1 - x)
  T a0 = 0.3069119453;
  T a1 = 0.0655977726;
  T a2 = 0.0137250423;

  T y = a2;
  y = a1 + x * y;
  y = a0 + x * y;

  // y := x - y * x * (1 - x)
  y *= x;   x = not (x);
  y *= x;   x = not (x);
  y = x - y;

  // Finally, nudge the residual error.

  unsigned char hi = bitsur (x) >> 8;
  if (hi >= 0x28 && hi <= 0x78)
    y -= urbits (1);

  return y;
}
