#include <stdlib.h>
#include <avr/eeprom.h>

#define ADDR ((void*) 10)

#define UVAL 0x1122
#define IVAL -1122

void utest (void)
{
    eeprom_write_u16 (ADDR, UVAL);
    if (eeprom_read_u16 (ADDR) != UVAL)
        exit (__LINE__);

    eeprom_update_u16 (ADDR, ~UVAL);
    if (eeprom_read_u16 (ADDR) != (uint16_t) ~UVAL)
        exit (__LINE__);
}

void itest (void)
{
    eeprom_write_i16 (ADDR, IVAL);
    if (eeprom_read_i16 (ADDR) != IVAL)
        exit (__LINE__);

    eeprom_update_i16 (ADDR, -IVAL);
    if (eeprom_read_i16 (ADDR) != -IVAL)
        exit (__LINE__);
}

int main (void)
{
  utest();
  itest();
  return 0;
}
