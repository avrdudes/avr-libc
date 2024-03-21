#include <stdlib.h>
#include <avr/pgmspace.h>

#define VAL 0x0105

#ifdef __AVR_HAVE_ELPM__
__attribute__((__section__(".mydata")))
#else
PROGMEM
#endif
const uint16_t data[] = { VAL, 2 * VAL, 7 * VAL };

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
  if (pgm_read_u16_far (pgm_get_far_address (data[0])) != get_val (0))
    exit (__LINE__);

  uint_farptr_t pf = pgm_get_far_address (data[0]) + i * sizeof (uint16_t);
  if (pgm_read_u16_far (pf) != get_val (i))
    exit (__LINE__);
}

int main (void)
{
  test (1);
  test (2);
  return 0;
}
