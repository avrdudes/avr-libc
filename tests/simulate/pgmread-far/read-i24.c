#include <stdlib.h>
#include <avr/pgmspace.h>

#ifndef __INT24_MAX__
int main (void)
{
  return 0;
}
#else

__extension__ typedef __int24 int24_t;

#define VAL 0x010507

PROGMEM_FAR
const int24_t data[] = { -VAL, -2 * VAL, -7 * VAL };

int24_t get_val (uint8_t i)
{
  int24_t v = -VAL;
  if (i == 1) v *= 2;
  if (i == 2) v *= 7;
  return v;
}

__attribute__((noinline,noclone))
void test (uint8_t i)
{
  if (pgm_read_i24_far (pgm_get_far_address (data[0])) != get_val (0))
    exit (__LINE__);

  uint_farptr_t pf = pgm_get_far_address (data[0]) + i * sizeof (int24_t);
  if (pgm_read_i24_far (pf) != get_val (i))
    exit (__LINE__);
}

int main (void)
{
  test (1);
  test (2);
  return 0;
}
#endif
