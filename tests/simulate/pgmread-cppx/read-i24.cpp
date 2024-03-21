#include <stdlib.h>
#include <avr/pgmspace.h>

#ifndef __INT24_MAX__
int main (void)
{
  return 0;
}
#else

#define VAL 0x010507

const __int24 data[] PROGMEM = { -VAL, -2 * VAL, -7 * VAL };

__int24 get_val (uint8_t i)
{
  __int24 v = -VAL;
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
#endif
