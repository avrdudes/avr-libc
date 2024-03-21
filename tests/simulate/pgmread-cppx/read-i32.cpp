#include <stdlib.h>
#include <avr/pgmspace.h>

#define VAL 0x01050711

const int32_t data[] PROGMEM = { -VAL, -2 * VAL, -7 * VAL };

int32_t get_val (uint8_t i)
{
  int32_t v = -VAL;
  if (i == 1) v *= 2;
  if (i == 2) v *= 7;
  return v;
}

__attribute__((noinline,noclone))
void test (uint8_t i)
{
  if (pgm_read (&data[0]) != get_val (0))
    exit (__LINE__);

  if (pgm_read (&data[i]) != get_val (i))
    exit (__LINE__);
}

int main (void)
{
  test (1);
  test (2);
  return 0;
}
