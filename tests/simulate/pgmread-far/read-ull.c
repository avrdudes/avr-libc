#include <stdlib.h>
#include <avr/pgmspace.h>

#if __SIZEOF_LONG_LONG__ != 8
/* With -mint8 we don't have 64-bit int. */
int main (void)
{
  return 0;
}
#else

#define VAL 0x0102030405060708

PROGMEM_FAR
const unsigned long long data[] = { VAL, 2 * VAL, 7 * VAL };

unsigned long long get_val (uint8_t i)
{
  unsigned long long v = VAL;
  if (i == 1) v *= 2;
  if (i == 2) v *= 7;
  return v;
}

__attribute__((noinline,noclone))
void test (uint8_t i)
{
  if (pgm_read_unsigned_long_long_far (pgm_get_far_address (data[0])) != get_val (0))
    exit (__LINE__);

  uint_farptr_t pf = pgm_get_far_address (data[0]) + i * sizeof (unsigned long long);
  if (pgm_read_unsigned_long_long_far (pf) != get_val (i))
    exit (__LINE__);
}

int main (void)
{
  test (1);
  test (2);
  return 0;
}
#endif /* long long = 8 bytes */
