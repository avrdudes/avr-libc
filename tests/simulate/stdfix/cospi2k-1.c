#if defined (USE_AVRTEST) && !defined (__AVR_TINY__)

#include <stdfix.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h> // M_PI_2

#include "avrtest.h"

#define T accum

// The target function: return cos (x * pi/2)
__attribute__((noipa))
float func (float x)
{
  x = avrtest_mulf (x, M_PI_2);
  return avrtest_cosf (x);
}

void test_cospi2k (void)
{
  float d_mi = +1000;
  float d_ma = -1000;
  uint32_t cyc = 0;

  // Test cospi2k() for all x in [-2, +2] to have an absolute error
  // as mentioned in stdfix.h.

  for (T x = -2.0k; x <= 2.0k; x += kbits (1))
    {
      avrtest_reset_cycles ();
      T yk = cospi2k (x);
      uint32_t c = avrtest_cycles ();
      if (c > cyc) cyc = c;

      float y2 = avrtest_ktof (yk);
      float y1 = func (avrtest_ktof (x));
      float d = avrtest_subf (y2, y1);

      d_ma = avrtest_fmaxf (d, d_ma);
      d_mi = avrtest_fminf (d, d_mi);
      if (avrtest_cmpf (d_ma, +5e-5f) > 0) exit (__LINE__);
      if (avrtest_cmpf (d_mi, -5e-5f) < 0) exit (__LINE__);
    }

  LOG_FMT_FLOAT ("d_min = % f\n", d_mi);
  LOG_FMT_FLOAT ("d_max = % f\n", d_ma);
  LOG_FMT_U32 ("Cycles = %u\n", cyc);
}


int main (void)
{
  test_cospi2k ();
  return 0;
}

#else
int main (void)
{
  return 0;
}
#endif
