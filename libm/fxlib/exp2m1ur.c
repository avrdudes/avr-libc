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
#include <avr/pgmspace.h>

#define LOG2_N_INTERVALS 2

// Q-format 0.16 values that represent f(x) = 2^x - 1 in [0, 1] as
// a cubic Bézier.
#ifdef __AVR_HAVE_ELPMX__
    PROGMEM_FAR
#else
    PROGMEM
#endif
static const uint16_t
exp2_tab[2 * ((1u << LOG2_N_INTERVALS) + 1)] =
  {
    0x0000, 0x0ec9, // x=0.00:  0.000000, 0.057755
    0x306f, 0x1195, // x=0.25:  0.189194, 0.068680
    0x6a09, 0x14e9, // x=0.50:  0.414200, 0.081680
    0xae89, 0x18de, // x=0.75:  0.681778, 0.097137
    0xffff, 0x1d93  // x=1.00:  1.000000, 0.115524
  };

#define T unsigned fract

// Read one word per post-inc from progmem.
// This is better than pgm_read_word (addr++).
#ifdef __AVR_TINY__
#define pgm_read_inc(addr) urbits (*addr++)
#elif defined (__AVR_HAVE_ELPMX__)
#define pgm_read_inc(addr)                              \
  (__extension__({                                      \
      T result;                                         \
      __asm volatile ("elpm %A0, Z+"  "\n\t"            \
                      "elpm %B0, Z+"                    \
                      : "=r" (result), "+z" (addr));    \
      result;                                           \
    }))
#elif defined (__AVR_HAVE_LPMX__)
#define pgm_read_inc(addr)                      \
  (__extension__({                              \
      T result;                                 \
      __asm ("lpm %A0, Z+"   "\n\t"             \
             "lpm %B0, Z+"                      \
             : "=r" (result), "+z" (addr));     \
      result;                                   \
    }))
#else
#define pgm_read_inc(addr) urbits (pgm_read_u16 (addr++))
#endif

// a + t * (b - a);
static inline
T line1 (T t, T a, T b)
{
  return a + t * (b - a);
}

// 2^x - 1 over [0, 1).

T exp2m1ur (T x)
{
  // Split x into sub-interval number and t.

#if LOG2_N_INTERVALS == 2
  uint8_t int_num = 0;
  __asm ("lsl %A0 $ rol %B0 $ rol %1" "\n\t"
         "lsl %A0 $ rol %B0 $ rol %1"
         : "+r" (x), "+r" (int_num));
  const T t = x;
#else
  uint16_t ux = bitsur (x);
  uint8_t int_num = ux >> (16 - LOG2_N_INTERVALS);
  ux <<= LOG2_N_INTERVALS;
  const T t = urbits (ux);
#endif

#ifdef __AVR_HAVE_ELPMX__
  const uint16_t *pi;
  uint8_t i0 = 4 * int_num;
  uint8_t hi8;
  __asm volatile ("clr %B0"               "\n\t"
                  "clr %1"                "\n\t"
                  "subi %A0,lo8(-(%3))"   "\n\t"
                  "sbci %B0,hi8(-(%3))"   "\n\t"
                  "sbci %1, hh8(-(%3))"   "\n\t"
                  "out __RAMPZ__,%1"
                  : "=d" (pi), "=d" (hi8)
                  : "0" (i0), "i" (exp2_tab) : "memory");
#else
  const uint8_t i0 = 2 * int_num;
  const uint16_t *pi = &exp2_tab [i0];
#endif

  const T y0 = pgm_read_inc (pi);
  const T d0 = pgm_read_inc (pi);
  const T y1 = y0 + d0;
  const T y3 = pgm_read_inc (pi);
  const T d3 = pgm_read_inc (pi);
  const T y2 = y3 - d3;

#if defined(__AVR_HAVE_ELPMX__) && defined(__AVR_HAVE_RAMPD__)
  __asm volatile ("out __RAMPZ__,__zero_reg__" ::: "memory");
#endif

  // Linear
  const T w0 = line1 (t, y0, y1);
  const T w1 = line1 (t, y1, y2);
  const T w2 = line1 (t, y2, y3);

  // Quadratic
  const T v0 = line1 (t, w0, w1);
  const T v1 = line1 (t, w1, w2);

  // Cubic
  return line1 (t, v0, v1);
}
