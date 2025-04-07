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
T lsr2 (T x)
{
  __asm ("lsr %B0 $ ror %A0"     "\n\t"
         "lsr %B0 $ ror %A0"     "\n\t"
         "adc %A0,__zero_reg__"  "\n\t"
         "adc %B0,__zero_reg__"
         : "+r" (x));
  return x;
}


T sinpi2ur (T x)
{
  T a0 = 0.0000070685 + urbits(1);
  T a1 = 0.5703086853;
  T a2 = 0.25 - 0.0054127797;
  T a3 = 0.6675605774;
  T a4 = 0.0371212959;
  T a5 = 0.0547174811;

  if (bitsur (x) >= 0xff40)
    return urbits (0xffff);

  // Reformulate the MiniMax polynomial such that the coefficients
  // and intermediate values are all in [0, 1).

  T y = a5;
  y = a4 + x * y;
  y = a3 - x * y;
  y = a2 + x * y;
  y = a1 - x * y + lsr2 (x);
  y = a0 + x * y + x;

  return y;
}
