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
#include <avr/pgmspace.h>

// Lookup table for a sin interpolant for x values at 0°...90°.
// The values have been chosen such that each secant minimizes the max error.
// This is the reason why the values in the table are not plain sin() values.
static const int16_t sin_tab[91] PROGMEM =
{
 0x0000, 0x023c, 0x0478, 0x06b3, 0x08ee, 0x0b28, 0x0d61, 0x0f9a, 0x11d1, 0x1406,
 0x163a, 0x186d, 0x1a9d, 0x1ccb, 0x1ef8, 0x2121, 0x2348, 0x256d, 0x278e, 0x29ad,
 0x2bc8, 0x2ddf, 0x2ff4, 0x3204, 0x3410, 0x3619, 0x381d, 0x3a1d, 0x3c18, 0x3e0f,
 0x4001, 0x41ed, 0x43d5, 0x45b7, 0x4794, 0x496c, 0x4b3d, 0x4d09, 0x4ecf, 0x508e,
 0x5248, 0x53fb, 0x55a7, 0x574d, 0x58eb, 0x5a83, 0x5c14, 0x5d9e, 0x5f20, 0x609b,
 0x620f, 0x637a, 0x64df, 0x663b, 0x678f, 0x68db, 0x6a1f, 0x6b5b, 0x6c8e, 0x6db9,
 0x6edb, 0x6ff5, 0x7106, 0x720e, 0x730d, 0x7403, 0x74f0, 0x75d4, 0x76af, 0x7781,
 0x7849, 0x7908, 0x79bd, 0x7a69, 0x7b0c, 0x7ba5, 0x7c34, 0x7cb9, 0x7d35, 0x7da7,
 0x7e0f, 0x7e6e, 0x7ec2, 0x7f0d, 0x7f4e, 0x7f85, 0x7fb1, 0x7fd4, 0x7fed, 0x7ffc,
 0x7fff
};

// Read one word per post-inc from progmem.
// This is better than pgm_read_word (addr++).
#define pgm_read_i16_inc(addr)                  \
  (__extension__({                              \
      int16_t result;                           \
      __asm ("lpm %A0, Z+"   "\n\t"             \
             "lpm %B0, Z+"                      \
             : "=r" (result), "+z" (addr));     \
      result;                                   \
    }))

// Multiply-Accumulate
// return c + a*b
// a and c are Q-format s.15, b is Q-format 0.8.
static inline int16_t
fmac16_8 (int16_t c, int16_t a, uint8_t b)
{
  __asm ("; fmac16_8: %B[c]:%A[c] += %B[a]:%A[a] * %[b]"  "\n\t"
         "mulsu  %B[a], %[b]"       "\n\t"      // (hi8(a) * b) << 1
         "add    %A[c], R0"         "\n\t"
         "adc    %B[c], R1"         "\n\t"
         "mul    %[b], %A[a]"       "\n\t"      // (b * lo8(a)) << 1
         "rol    r0"                "\n\t"      // round
         "adc    %A[c], R1"         "\n\t"
         "clr    __zero_reg__"      "\n\t"
         "adc    %B[c], __zero_reg__"
         : [c] "+r" (c)
         : [a] "a" (a), [b] "a" (b));
    return c;
}

// Sinus of deg in [0°, 256°).
fract sinuhk_deg (unsigned short accum deg)
{
  uint8_t neg = 0;
  unsigned short accum _180_deg = 180uhk;

  // Force the constant into a register.
  __asm ("" : "+r" (_180_deg));

  if (deg >= _180_deg)
    {
      // sin(x) = -sin(x+pi)
      deg -= _180_deg;
      neg = 1;
      // deg in [0°, 180°)
    }

  if (deg > 90uhk)
    {
      // sin(x) = sin(pi - x)
      deg = _180_deg - deg;
      // deg in [0°, 90°]
    }

  // Read a value from the lookup table.
  // "int16_t" stands for "fract" since avr-gcc optimizes the former better.
  const int16_t *p = & sin_tab[bitsuhk (deg) >> 8];
  int16_t data0 = pgm_read_i16_inc (p);
  int16_t data1 = pgm_read_i16 (p);

  // sin = data0 + (data1 - data0) * lo8(deg).
  int16_t si = fmac16_8 (data0, data1 - data0, bitsuhk (deg));

  return rbits (neg ? -si : si);
}
#endif /* Have MUL */
