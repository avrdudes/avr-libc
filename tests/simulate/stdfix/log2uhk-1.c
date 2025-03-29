#if defined (USE_AVRTEST) && defined (__AVR_HAVE_MUL__)

#include <stdlib.h>
#include <stdint.h>
#include <stdfix.h>
#include <math.h>

#include "avrtest.h"

// Make sure that the absolute error is in the expected range for
// all values in [1, 2).

void test_log2 (void)
{
  for (uint16_t i = 0x100; i <= 0x1ff; ++i)
    {
      // Run for all ua in [1, 2).
      unsigned short accum ua = uhkbits (i);
      short accum la = log2uhk (ua);

      float f1 = avrtest_log2f (ldexp (i, -8));
      float f2 = la;

      float d = avrtest_subf (f2, f1);

      if (d > +0.0053) exit (__LINE__);
      if (d < -0.0053) exit (__LINE__);
    }
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
