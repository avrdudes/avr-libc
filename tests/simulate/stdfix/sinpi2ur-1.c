#if defined (USE_AVRTEST) && (!defined (__AVR_TINY__) || __GNUC__ >= 15)

#include <stdfix.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h> // M_PI_2

#include "avrtest.h"

#define T unsigned fract

// The target function: return sin (x * pi/2)
__attribute__((noipa))
float func (float x)
{
  x = avrtest_mulf (x, M_PI_2);
  return avrtest_sinf (x);
}

void test_sinpi2ur (void)
{
  float d_mi = +1000;
  float d_ma = -1000;
  uint32_t cyc = 0;

  // Test sinpi2ur() for all x in [0, 1) to have an absolute error
  // as mentioned in stdfix.h.

  uint16_t i = 0;
  do
    {
      unsigned fract x = urbits (i);

      avrtest_reset_cycles ();
      unsigned fract ur = sinpi2ur (x);
      uint32_t c = avrtest_cycles ();
      if (c > cyc) cyc = c;

      float y2 = avrtest_urtof (ur);
      float y1 = func (avrtest_urtof (x));
      float d = avrtest_subf (y2, y1);

      d_ma = avrtest_fmaxf (d, d_ma);
      d_mi = avrtest_fminf (d, d_mi);
      if (avrtest_cmpf (d_ma, +3.9e-5f) > 0) exit (__LINE__);
      if (avrtest_cmpf (d_mi, -3.9e-5f) < 0) exit (__LINE__);
    }
  while (++i);

  LOG_FMT_FLOAT ("d_min = % f\n", d_mi);
  LOG_FMT_FLOAT ("d_max = % f\n", d_ma);
  LOG_FMT_U32 ("Cycles = %u\n", cyc);
}


int main (void)
{
  test_sinpi2ur ();
  return 0;
}

#else
int main (void)
{
  return 0;
}
#endif
