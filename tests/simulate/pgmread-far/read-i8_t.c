#include <stdlib.h>
#include <avr/pgmspace.h>

#define VAL 0x11

PROGMEM_FAR
const int8_t data[] = { -VAL, -2 * VAL, -7 * VAL };

int8_t get_val (uint8_t i)
{
  int8_t v = -VAL;
  if (i == 1) v *= 2;
  if (i == 2) v *= 7;
  return v;
}

__attribute__((noinline,noclone))
void test (uint8_t i)
{
  if (pgm_read_i8_far (pgm_get_far_address (data[0])) != get_val (0))
    exit (__LINE__);

  uint_farptr_t pf = pgm_get_far_address (data[0]) + i * sizeof (int8_t);
  if (pgm_read_i8_far (pf) != get_val (i))
    exit (__LINE__);
}

int main (void)
{
  test (1);
  test (2);
  return 0;
}
