#include <stdlib.h>
#include <avr/pgmspace.h>

#ifdef __AVR_TINY__
int main (void) { return 0; }
#else

#define VAL (-1.125L)

const long double data[] PROGMEM = { VAL, -3 * VAL, 77 * VAL };

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
  if (pgm_read_long_double (&data[0]) != get_val (0))
    exit (__LINE__);

  if (pgm_read_long_double (&data[i]) != get_val (i))
    exit (__LINE__);
}

int main (void)
{
  test (1);
  test (2);
  return 0;
}
#endif
