#if defined (USE_AVRTEST) && defined (__AVR_HAVE_MUL__)

#include <stdlib.h>
#include <stdint.h>
#include <stdfix.h>
#include <math.h>

#include "avrtest.h"

// Make sure that the absolute error is in the expected range for
// all values.

void test_sin (void)
{
  float f_mi = +1000;
  float f_ma = -1000;
  uint16_t cyc = 0;

  uint16_t uu = 0;
  do
    {
      unsigned short accum x = uhkbits (uu);
      avrtest_reset_cycles();
      fract y2 = sinuhk_deg (x);
      uint16_t c = avrtest_cycles();
      if (c > cyc)
        cyc = c;

      // The algorithm promises to never return -1.0 so that we can
      // use -y2 without causing an overflow.  Don't use -1r in tests.
      uint16_t u2;
      // Hide conversion from the compiler.
      __asm ("" : "=r" (u2) : "0" (y2));
      if (u2 == 0x8000) exit (__LINE__);

      float f1 = avrtest_sinf (avrtest_mulf (x, M_PI / 180.0));
      float f2 = y2;

      float d = avrtest_subf (f2, f1);

      if (d > f_ma) { f_ma = d; LOG_FMT_FLOAT ("max = %+f\n", d); }
      if (d < f_mi) { f_mi = d; LOG_FMT_FLOAT ("min = %+f\n", d); }

      if (d > +0.000065f) exit (__LINE__);
      if (d < -0.000065f) exit (__LINE__);
    } while (++uu);

  LOG_FMT_U16 ("WCET = %u\n", cyc);
  LOG_FMT_FLOAT ("Max = %+f\n", f_ma);
  LOG_FMT_FLOAT ("Min = %+f\n", f_mi);
}

int main (void)
{
  test_sin();

  return 0;
}

#else
int main (void)
{
  return 0;
}
#endif
