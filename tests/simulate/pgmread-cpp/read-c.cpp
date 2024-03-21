#include <stdlib.h>
#include <avr/pgmspace.h>

#define VAL 0x11

const char data[] PROGMEM = { -VAL, -2 * VAL, -7 * VAL };

char get_val (uint8_t i)
{
  char v = -VAL;
  if (i == 1) v *= 2;
  if (i == 2) v *= 7;
  return v;
}

__attribute__((noinline,noclone))
void test (uint8_t i)
{
  if (pgm_read<char> (&data[0]) != get_val (0))
    exit (__LINE__);

  if (pgm_read<char> (&data[i]) != get_val (i))
    exit (__LINE__);
}

int main (void)
{
  test (1);
  test (2);
  return 0;
}
