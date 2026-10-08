#include "avrtest.h"
#include <stdint.h>

#define NI __attribute((noipa))
#define AI static __inline__ __attribute((always_inline))

#ifdef SIZE_ONLY
#define NAK __attribute__((naked))
#else
#define NAK // empty
#endif

#if MUL
NAK NI TC do_mul (TA a, TB b)
{
    return (TC) a * (TC) b;
}
#endif // MUL

#if DIV
int _a[-(sizeof(TA) != sizeof(TC))];
int _b[-(sizeof(TB) != sizeof(TC))];
NAK NI TC do_div (TA a, TB b)
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

// Shift the random value right by a random value in 0..BITSIZE/4
// so as to get a more realistic value distribution for mul.
NI __attribute__((flatten)) uint64_t randB (uint16_t size)
{
  uint8_t sh = avrtest_prand () % (size << 1);
  return u64rand () >> sh;
}

static inline void logfx (const char *s, uint64_t x, int size, const char *t)
{
  LOG_STR (s);
  switch (size)
    {
    case 1: LOG_FMT_U8  ("%02x", x); break;
    case 2: LOG_FMT_U16 ("%04x", x); break;
    case 3: LOG_FMT_U24 ("%06x", x); break;
    case 4: LOG_FMT_U32 ("%08x", x); break;
    case 8: LOG_FMT_U64 ("%016llx", x); break;
    }
  LOG_STR (t);
}

unsigned volatile sink;

int main (void)
{
  uint32_t cyc_max = 0;
  uint32_t cyc = 0;

  for (uint32_t count = 0; count < TIMES; ++count)
    {
#if MUL
#if EXT
      TA a = u64rand ();
      TB b = u64rand ();
#else
      TA a = randB (sizeof (TA));
      TB b = randB (sizeof (TB));
#endif // EXT
      avrtest_cycles_callee ();
      TC c = do_mul (a, b);
      uint32_t cy = avrtest_cycles ();
#endif // MUL
#if DIV
      TC a = u64rand ();
      TC b = u64rand ();
      if (b == 0)
        continue;
      avrtest_cycles_callee ();
      TC c = do_div (a, b);
      uint32_t cy = avrtest_cycles ();
#endif // DIV

      sink = c;

      cyc += cy;
      if (cy > cyc_max)
        cyc_max = cy;
    }

  LOG_FMT_U32 ("cyc_max=%u\n", cyc_max);
  LOG_FMT_U32 ("cyc_avr=%u\n", cyc / TIMES);

  return 0;
}

#endif // SIZE_ONLY
