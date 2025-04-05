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

// atan(x) over [0, 1)  ->  [0, pi/4].

T atanur (T x)
{
  T a0 = 0x0.0001p0ur; // 0.0000153
  T a1 = 0x0.ff8dp0ur; // 0.9982452
  T a2 = 0x0.8610p0ur; // 0.5236816
  T a3 = 0x0.737ep0ur; // 0.4511414
  T a4 = 0x0.439fp0ur; // 0.2641449
  T a5 = 0x0.0caep0ur; // 0.0495300

  // Reformulate the MiniMax polynomial such that the coefficients
  // and intermediate values are all in [0, 1).

  T y = a5;
  y = a4 - x * y;
  y = a3 - x * y;
  y = a2 - x * y;
  y = a1 + x * y - (x >> 1);
  y = a0 + x * y;

  return y;
}
