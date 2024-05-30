#include <stdlib.h>
#include <avr/pgmspace.h>

/* Notice this is failing with some gcc-avr v5.4.0 distributions:
   They back-ported PR71948 from v7 (avr-gcc -mmcu=avrtiny adds 0x4000
   to symbols in progmem), and then in pgmspace.h they add an offset
   of 0x4000 *AGAIN*.  */

#define VAL 0x0105

PROGMEM_FAR
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
  if (pgm_read_word_far (pgm_get_far_address (data[0])) != get_val (0))
    exit (__LINE__);

  uint_farptr_t pf = pgm_get_far_address (data[0]) + i * sizeof (uint16_t);
  if (pgm_read_word_far (pf) != get_val (i))
    exit (__LINE__);
}

int main (void)
{
  test (1);
  test (2);
  return 0;
}
