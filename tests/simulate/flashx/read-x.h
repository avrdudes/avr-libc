#ifndef __FLASHX
int main (void)
{
  return 0;
}
#else
#include <avr/flash.h>
#include <stdlib.h>

const __flashx T data[] = { -VAL, -2 * VAL, -7 * VAL };

T get_val (uint8_t i)
{
  T v = -VAL;
  if (i == 1) v *= 2;
  if (i == 2) v *= 7;
  __asm ("" : "+r" (v));
  return v;
}

__attribute__((noinline,noclone))
void test (uint8_t i)
{
  if (READ (data[0]) != get_val (0))
    exit (__LINE__);

  if (READ (data[i]) != get_val (i))
    exit (__LINE__);
}

int main (void)
{
  test (1);
  test (2);
  return 0;
}
#endif
