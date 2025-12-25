#include <stdlib.h>
#include <avr/eeprom.h>

#define ADDR ((void*) 10)

#define UVAL 0x11
#define IVAL -11

void utest (void)
{
    eeprom_write_u8 (ADDR, UVAL);
    if (eeprom_read_u8 (ADDR) != UVAL)
        exit (__LINE__);

    eeprom_update_u8 (ADDR, ~UVAL);
    if (eeprom_read_u8 (ADDR) != (uint8_t) ~UVAL)
        exit (__LINE__);
}

void itest (void)
{
    eeprom_write_i8 (ADDR, IVAL);
    if (eeprom_read_i8 (ADDR) != IVAL)
        exit (__LINE__);

    eeprom_update_i8 (ADDR, -IVAL);
    if (eeprom_read_i8 (ADDR) != -IVAL)
        exit (__LINE__);
}

int main (void)
{
  utest();
  itest();
  return 0;
}
