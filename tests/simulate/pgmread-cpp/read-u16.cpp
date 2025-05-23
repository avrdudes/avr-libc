#include <stdlib.h>

#define __pgm_read_template__
#include <avr/pgmspace.h>

#define VAL 0x0105

const uint16_t data[] PROGMEM = { VAL, 2 * VAL, 7 * VAL };

uint16_t get_val (uint8_t i)
{
  uint16_t v = VAL;
  if (i == 1) v *= 2;
  if (i == 2) v *= 7;
  return v;
}

__attribute__((noinline,noclone))
void test (uint8_t i)
{
  if (pgm_read<uint16_t> (&data[0]) != get_val (0))
    exit (__LINE__);

  if (pgm_read<uint16_t> (&data[i]) != get_val (i))
    exit (__LINE__);
}

int main (void)
{
  test (1);
  test (2);
  return 0;
}
