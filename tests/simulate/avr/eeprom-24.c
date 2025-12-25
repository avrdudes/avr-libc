#include <stdlib.h>
#include <avr/eeprom.h>

#define ADDR ((void*) 10)

#define UVAL 0x112233
#define IVAL -112233

void utest (void)
{
    eeprom_write_u24 (ADDR, UVAL);
    if (eeprom_read_u24 (ADDR) != UVAL)
        exit (__LINE__);

    eeprom_update_u24 (ADDR, ~UVAL);
    if (eeprom_read_u24 (ADDR) != (uint24_t) ~UVAL)
        exit (__LINE__);
}

void itest (void)
{
    eeprom_write_i24 (ADDR, IVAL);
    if (eeprom_read_i24 (ADDR) != IVAL)
        exit (__LINE__);

    eeprom_update_i24 (ADDR, -IVAL);
    if (eeprom_read_i24 (ADDR) != -IVAL)
        exit (__LINE__);
}

int main (void)
{
  utest();
  itest();
  return 0;
}
