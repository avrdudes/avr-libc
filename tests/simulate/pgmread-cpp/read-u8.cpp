#include <stdlib.h>

#define __pgm_read_template__
#include <avr/pgmspace.h>

#define VAL 0x11

const uint8_t data[] PROGMEM = { VAL, 2 * VAL, 7 * VAL };

uint8_t get_val (uint8_t i)
{
  uint8_t v = VAL;
  if (i == 1) v *= 2;
  if (i == 2) v *= 7;
  return v;
}

__attribute__((noinline,noclone))
void test (uint8_t i)
{
  if (pgm_read<uint8_t> (&data[0]) != get_val (0))
    exit (__LINE__);

  if (pgm_read<uint8_t> (&data[i]) != get_val (i))
    exit (__LINE__);
}

int main (void)
{
  test (1);
  test (2);
  return 0;
}
