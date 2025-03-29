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

#ifdef __AVR_HAVE_MUL__

/* The implementation is basically the same like can be found at
      https://www.mikrocontroller.net/articles/AVR_Arithmetik/Sinus_und_Cosinus_(Lineare_Interpolation)
   of which I am the author, including the provided derivation and analysis.
   As it turned out, the used linear interpolation runs much faster and more
   exact than CORDIC, and the code size is about the same.  */

#include <stdfix.h>
#include <stdint.h>

// Due to ICE GCC PR119532 we avoid fixed-point for now.

extern int16_t my_sinuhk_deg (uint16_t) __asm("sinuhk_deg");

// Cosine of deg in [0°, 256°).
fract cosuhk_deg (unsigned short accum deg)
{
  uint16_t _90_deg = bitsuhk (90uhk);
  uint16_t udeg = bitsuhk (deg);
  // Force the constant into a register.
  __asm ("" : "+r" (_90_deg));

  int16_t res = udeg <= _90_deg
    // cos(x) = sin(pi/2 - x)
    ? my_sinuhk_deg (_90_deg - udeg)
    // cos(x) = -sin (x - pi/2)
    : -my_sinuhk_deg (udeg - _90_deg);

  return rbits (res);
}
#endif /* Have MUL */

