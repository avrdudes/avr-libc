#include <stdlib.h>
#include <avr/pgmspace.h>

#ifdef __AVR_TINY__
int main (void) { return 0; }
#else

#define VAL (-1.125L)

#ifdef __AVR_HAVE_ELPM__
__attribute__((__section__(".mydata")))
#else
PROGMEM
#endif
const long double data[] = { VAL, -3 * VAL, 77 * VAL };

long double get_val (uint8_t i)
{
  long double v = VAL;
  if (i == 1) v *= -3;
  if (i == 2) v *= 77;
  return v;
}

__attribute__((noinline,noclone))
void test (uint8_t i)
{
  if (pgm_read_long_double_far (pgm_get_far_address (data[0])) != get_val (0))
    exit (__LINE__);

  uint_farptr_t pf = pgm_get_far_address (data[0]) + i * sizeof (long double);
  if (pgm_read_long_double_far (pf) != get_val (i))
    exit (__LINE__);
}

int main (void)
{
  test (1);
  test (2);
  return 0;
}
#endif
