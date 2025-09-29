#include <stdlib.h>
#include <avr/eeprom.h>

#define ADDR ((void*) 10)

#define UVAL 0x11223344
#define IVAL -11223344

void utest (void)
{
    eeprom_write_u32 (ADDR, UVAL);
    if (eeprom_read_u32 (ADDR) != UVAL)
        exit (__LINE__);

    eeprom_update_u32 (ADDR, ~UVAL);
    if (eeprom_read_u32 (ADDR) != (uint32_t) ~UVAL)
        exit (__LINE__);
}

void itest (void)
{
    eeprom_write_i32 (ADDR, IVAL);
    if (eeprom_read_i32 (ADDR) != IVAL)
        exit (__LINE__);

    eeprom_update_i32 (ADDR, -IVAL);
    if (eeprom_read_i32 (ADDR) != -IVAL)
        exit (__LINE__);
}

int main (void)
{
  utest();
  itest();
  return 0;
}
