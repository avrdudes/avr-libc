#if defined (USE_AVRTEST) && !defined (__AVR_TINY__)

#include <stdlib.h>
#include <stdint.h>
#include <stdfix.h>
#include <math.h>

#include "avrtest.h"

// Make sure that the absolute error is in the expected range for
// all values in [1, 2).

void test_log2 (void)
{
  float d_mi = +1000;
  float d_ma = -1000;
  uint32_t cyc = 0;

  for (uint32_t i = 0x10000; i <= 0x1ffff; ++i)
    {
      // Run for all ua in [1, 2).  
      unsigned accum ua = ukbits (i);

      avrtest_cycles_call ();
      accum la = log2uk (ua);
      uint32_t c = avrtest_cycles ();
      if (c > cyc) cyc = c;

      float f1 = avrtest_log2f (avrtest_uktof (ua));
      float f2 = avrtest_ktof (la);

      float d = avrtest_subf (f2, f1);

      d_ma = avrtest_fmaxf (d, d_ma);
      d_mi = avrtest_fminf (d, d_mi);
      if (avrtest_cmpf (d_ma, +0.000045f) > 0) exit (__LINE__);
      if (avrtest_cmpf (d_mi, -0.000045f) < 0) exit (__LINE__);
    }

  LOG_FMT_FLOAT ("d_min = % f\n", d_mi);
  LOG_FMT_FLOAT ("d_max = % f\n", d_ma);
  LOG_FMT_U32 ("Cycles = %u\n", cyc);
}

int main (void)
{
  test_log2();

  return 0;
}

#else
int main (void)
{
  return 0;
}
#endif
