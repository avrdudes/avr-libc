#ifndef FX
#error define FX
#endif

#include "fx-defs.h"
#include "avrtest.h"
#include <stdint.h>

#define NI __attribute((noipa))
#define AI static __inline__ __attribute((always_inline))

#ifdef SIZE_ONLY
#define NAK __attribute__((naked))
#else
#define NAK // empty
#endif

#define avrtest_mulfx GLUE2 (avrtest_mul, FX)
#define avrtest_divfx GLUE2 (avrtest_div, FX)

#if MUL
NAK NI fx_t do_mul (fx_t a, fx_t b)
{
  return a * b;
}
#endif // MUL

#if DIV
NAK NI fx_t do_div (fx_t a, fx_t b)
{
  return a / b;
}
#endif // DIV

#ifndef SIZE_ONLY

// 64-bit pseudo-random uint64_t.
AI uint64_t u64rand (void)
{
  uint64_t r = avrtest_prand ();
  return (r << 32) | avrtest_prand ();
}

// Pseudo-random FX.
fx_t fxrand (void)
{
  return sizeof (fx_t) <= 4
    ? fxbits ((int_t) avrtest_prand ())
    : fxbits (u64rand ());
}

// Shift the random value right by a random value in 0..IBIT-1
// so as to get a more realistic value distribution for mul.
NI __attribute__((flatten)) fx_t fxrandB (void)
{
  uint8_t sh = IBIT ? avrtest_prand () % IBIT : 0;
  int_t r = bitsfx (fxrand ()) >> sh;
  return fxbits (r);
}

// Absolut value of difference.
NI uint_t absdiff (fx_t a, fx_t b)
{
  return a > b
    ? (uint_t) bitsfx (a) - (uint_t) bitsfx (b)
    : (uint_t) bitsfx (b) - (uint_t) bitsfx (a);
}

static inline void logfx (const char *s, fx_t x, const char *t)
{
  LOG_STR (s);
  switch (sizeof (fx_t))
    {
    case 1: LOG_FMT_U8  ("%" FMT, bitsfx (x)); break;
    case 2: LOG_FMT_U16 ("%" FMT, bitsfx (x)); break;
    case 4: LOG_FMT_U32 ("%" FMT, bitsfx (x)); break;
    case 8: LOG_FMT_U64 ("%" FMT, bitsfx (x)); break;
    }
  LOG_FMT_FLOAT (" = %f", (float) x);
  LOG_STR (t);
}


int main (void)
{
  uint32_t cyc_max = 0;
  uint32_t cyc = 0;
  uint_t max_ulp = 0;

  uint32_t count;
  for (count = 0; count < TIMES; )
    {
#if MUL
      fx_t a = fxrandB ();
      fx_t b = fxrandB ();
      avrtest_cycles_callee ();
      fx_t c1 = do_mul (a, b);
      uint32_t c = avrtest_cycles ();
      fx_t c2 = avrtest_mulfx (a, b);
#endif // MUL
#if DIV
      fx_t a = fxrand ();
      fx_t b = fxrand ();
      if (b == fx(0))
        continue;
      avrtest_cycles_callee ();
      fx_t c1 = do_div (a, b);
      uint32_t c = avrtest_cycles ();
      fx_t c2 = avrtest_divfx (a, b);
#endif // DIV

      // Assume MIN / MAX comes from saturation, which the AVR routines
      // don't always do for the non-saturating ops.
      if (c2 == MAXfx || (SBIT && c2 == MINfx))
        continue;

      cyc += c;
      if (c > cyc_max)
        cyc_max = c;

      ++count;

      uint_t ad = absdiff (c1, c2);
      if (ad > max_ulp)
        max_ulp = ad;

      if (max_ulp > 10)
        {
          logfx ("a  = ", a, "\n");
          logfx ("b  = ", b, "\n");
          logfx ("c1 = ", c1, "\n");
          logfx ("c2 = ", c2, "\n");
          break;
        }
    }

  LOG_FMT_U32 ("cyc_max=%u\n", cyc_max);
  LOG_FMT_U32 ("cyc_avr=%u\n", cyc / count);
  LOG_FMT_U64 ("d_max=%llu\n", (uint64_t) max_ulp);

  return 0;
}

#endif // SIZE_ONLY
