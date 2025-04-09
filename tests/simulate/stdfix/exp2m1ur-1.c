// exp2m1ur is available on AVRrc, but __muluhq3 is not.

#if defined (USE_AVRTEST) && (!defined (__AVR_TINY__) || __GNUC__ >= 15)

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

      avrtest_cycles_call ();
      unsigned fract ur = exp2m1ur (x);
      uint32_t c = avrtest_cycles ();
      if (c > cyc) cyc = c;

      float y2 = avrtest_urtof (ur);
      float y1 = func (avrtest_urtof (x));
      float d = avrtest_subf (y2, y1);

      d_ma = avrtest_fmaxf (d, d_ma);
      d_mi = avrtest_fminf (d, d_mi);
      if (avrtest_cmpf (d_ma, +0.000022f) > 0) exit (__LINE__);
      if (avrtest_cmpf (d_mi, -0.000022f) < 0) exit (__LINE__);
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
