// exp2m1ur is available on AVRrc, but __muluhq3 is not.

#if defined (USE_AVRTEST) && !defined (__AVR_TINY__)

#include <stdfix.h>
#include <stdlib.h>
#include <stdint.h>

#include "avrtest.h"

// The target function: return 2^x - 1
__attribute__((noipa))
float func (float x)
{
  float y = avrtest_powf (2, x);
  return avrtest_subf (y, 1);
}

void test_exp2m1ur (void)
{
  float d_mi = +1000;
  float d_ma = -1000;
  uint32_t cyc = 0;

  // Test exp2m1ur() for all x in [0, 1) to have an absolute error
  // as mentioned in stdfix.h.

  uint16_t i = 0;
  do
    {
      unsigned fract x = urbits (i);

      avrtest_reset_cycles ();
      float y2 = exp2m1ur (x);
      uint32_t c = avrtest_cycles ();
      if (c > cyc) cyc = c;

      float y1 = func (x);
      float d = avrtest_subf (y2, y1);

      if (d > d_ma) d_ma = d;
      if (d < d_mi) d_mi = d;
      if (d_ma > +0.00004f) exit (__LINE__);
      if (d_mi < -0.00004f) exit (__LINE__);
    }
  while (++i);

  LOG_FMT_FLOAT ("d_min = % f\n", d_mi);
  LOG_FMT_FLOAT ("d_max = % f\n", d_ma);
  LOG_FMT_U32 ("Cycles = %u\n", cyc);
}

int main (void)
{
  test_exp2m1ur ();
  return 0;
}

#else
int main (void)
{
  return 0;
}
#endif
