// log21pur is available on AVRrc, but __muluhq3 is not.

#if defined (USE_AVRTEST) && !defined (__AVR_TINY__)

#include <stdfix.h>
#include <stdlib.h>
#include <stdint.h>

#include "avrtest.h"

// The target function: return log2 (1 + x)
__attribute__((noipa))
float func (float x)
{
  float x1 = avrtest_addf (1, x);
  return avrtest_log2f (x1);
}

void test_log21pur (void)
{
  float d_mi = +1000;
  float d_ma = -1000;
  uint32_t cyc = 0;

  // Test log21pur() for all x in [0, 1) to have an absolute error
  // as mentioned in stdfix.h.

  uint16_t i = 0;
  do
    {
      unsigned fract x = urbits (i);

      avrtest_reset_cycles ();
      unsigned fract ur = log21pur (x);
      uint32_t c = avrtest_cycles ();
      if (c > cyc) cyc = c;

      float y2 = ur;
      float y1 = func (x);
      float d = avrtest_subf (y2, y1);

      if (d > d_ma) d_ma = d;
      if (d < d_mi) d_mi = d;
      if (d_ma > +4.4e-5f) exit (__LINE__);
      if (d_mi < -4.4e-5f) exit (__LINE__);
    }
  while (++i);

  LOG_FMT_FLOAT ("d_min = % f\n", d_mi);
  LOG_FMT_FLOAT ("d_max = % f\n", d_ma);
  LOG_FMT_U32 ("Cycles = %u\n", cyc);
}

int main (void)
{
  test_log21pur ();
  return 0;
}

#else
int main (void)
{
  return 0;
}
#endif
