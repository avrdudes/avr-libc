#include <stdlib.h>
#include <avr/pgmspace.h>

#define VAL 0x11

#ifdef __AVR_HAVE_ELPM__
__attribute__((__section__(".mydata")))
#else
PROGMEM
#endif
const signed char data[] = { -VAL, -2 * VAL, -7 * VAL };

signed char get_val (uint8_t i)
{
  signed char v = -VAL;
  if (i == 1) v *= 2;
  if (i == 2) v *= 7;
  return v;
}

__attribute__((noinline,noclone))
void test (uint8_t i)
{
  if (pgm_read_signed_char_far (pgm_get_far_address (data[0])) != get_val (0))
    exit (__LINE__);

  uint_farptr_t pf = pgm_get_far_address (data[0]) + i * sizeof (signed char);
  if (pgm_read_signed_char_far (pf) != get_val (i))
    exit (__LINE__);
}

int main (void)
{
  test (1);
  test (2);
  return 0;
}
