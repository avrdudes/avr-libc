#include <stdlib.h>

#define __pgm_read_template__
#include <avr/pgmspace.h>

#ifdef __AVR_TINY__
int main (void) { return 0; }
#else

#define VAL (-1.125f)

const float data[] PROGMEM = { VAL, -3 * VAL, 77 * VAL };

float get_val (uint8_t i)
{
  float v = VAL;
  if (i == 1) v *= -3;
  if (i == 2) v *= 77;
  return v;
}

__attribute__((noinline,noclone))
void test (uint8_t i)
{
  if (pgm_read<float> (&data[0]) != get_val (0))
    exit (__LINE__);

  if (pgm_read<float> (&data[i]) != get_val (i))
    exit (__LINE__);
}

int main (void)
{
  test (1);
  test (2);
  return 0;
}
#endif
