#if defined (USE_AVRTEST) && (!defined (__AVR_TINY__) || __GNUC__ >= 15)

#include <stdfix.h>
#include <stdlib.h>
#include <stdint.h>

#include "avrtest.h"

// The target function: return asin (x)
static float func (float x)
{
  return avrtest_asinf (x);
}

#define T accum

void test_asink (void)
{
  float d_mi = +1000;
  float d_ma = -1000;
  uint32_t cyc = 0;

  // Test asink() for all x in [-1, +1] to have an absolute error
  // as mentioned in stdfix.h.

  for (T x = -1k; x <= 1k; x += kbits (1))
    {
      avrtest_cycles_call ();
      T y = asink (x);
      uint32_t c = avrtest_cycles ();
      if (c > cyc) cyc = c;

      float y2 = avrtest_ktof (y);
      float y1 = func (avrtest_ktof (x));
      float d = avrtest_subf (y2, y1);

      d_ma = avrtest_fmaxf (d, d_ma);
      d_mi = avrtest_fminf (d, d_mi);
      if (avrtest_cmpf (d_ma, +5.1e-5f) > 0) exit (__LINE__);
      if (avrtest_cmpf (d_mi, -5.1e-5f) < 0) exit (__LINE__);
    }

  LOG_FMT_FLOAT ("d_min = % f\n", d_mi);
  LOG_FMT_FLOAT ("d_max = % f\n", d_ma);
  LOG_FMT_U32 ("Cycles = %u\n", cyc);
}

int main (void)
{
  test_asink ();
  return 0;
}

#else
int main (void)
{
  return 0;
}
#endif
