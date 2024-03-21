#include <stdlib.h>
#include <avr/pgmspace.h>

#if __SIZEOF_LONG__ == 4
#define VAL 0x01050711
#else
#define VAL 0x0107
#endif

const unsigned long data[] PROGMEM = { VAL, 2 * VAL, 7 * VAL };

unsigned long get_val (uint8_t i)
{
  unsigned long v = VAL;
  if (i == 1) v *= 2;
  if (i == 2) v *= 7;
  return v;
}

__attribute__((noinline,noclone))
void test (uint8_t i)
{
  if (pgm_read_unsigned_long (&data[0]) != get_val (0))
    exit (__LINE__);

  if (pgm_read_unsigned_long (&data[i]) != get_val (i))
    exit (__LINE__);
}

int main (void)
{
  test (1);
  test (2);
  return 0;
}
