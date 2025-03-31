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
#include <stdint.h>

accum exp2k (accum x)
{
  if (x >= 16k)
    return kbits (0x7fffffff);

  if (x < -16k)
    return kbits (0);

  // Split x into ibit and fbit.

  int8_t ibit;
  uint16_t fbit;

  __asm ("lsl %A[f]"       "\n\t"
         "rol %B[f]"       "\n\t"
         "mov %[i],%C[f]"  "\n\t"
         "rol %[i]"
         : [f] "=r" (fbit), [i] "=r" (ibit)
         : "0" (x));

  // 2^{x} - 1
  const unsigned fract e2m1 = exp2m1ur (urbits (fbit));

  // y = 2^{x} in [1, 2) as 16.16.  For some reason, + works better than |.
  uint32_t y = (1ul << 16) + bitsur (e2m1);

  // Convert 16.16 to s16.15.
  --ibit;

  // Shift according to the integral part.

  if (ibit > 0)
    {
      do
        y <<= 1;
      while (--ibit);
    }
  else if (ibit < 0)
    {
      do
        y >>= 1;
      while (++ibit);
    }

  return kbits (y);
}
