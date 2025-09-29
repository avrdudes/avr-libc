#include <stdlib.h>
#include <avr/eeprom.h>

#define ADDR ((void*) 10)

#define UVAL 0x1122334455667788
#define IVAL -1122334455667788

void utest (void)
{
    eeprom_write_u64 (ADDR, UVAL);
    if (eeprom_read_u64 (ADDR) != UVAL)
        exit (__LINE__);

    eeprom_update_u64 (ADDR, ~UVAL);
    if (eeprom_read_u64 (ADDR) != (uint64_t) ~UVAL)
        exit (__LINE__);
}

void itest (void)
{
    eeprom_write_i64 (ADDR, IVAL);
    if (eeprom_read_i64 (ADDR) != IVAL)
        exit (__LINE__);

    eeprom_update_i64 (ADDR, -IVAL);
    if (eeprom_read_i64 (ADDR) != -IVAL)
        exit (__LINE__);
}

int main (void)
{
  utest();
  itest();
  return 0;
}
