#include <stdlib.h>
#include <avr/eeprom.h>

#define ADDR ((void*) 10)

#define VAL 0x1122334455667788

void test1 (void)
{
  eeprom_write_qword (ADDR, VAL);

  if (eeprom_read_dword (ADDR) != (uint32_t) VAL)
    exit (__LINE__);
  if (eeprom_read_dword (ADDR + 4) != (uint32_t) (VAL >> 32))
    exit (__LINE__);
}

void test2 (void)
{
  eeprom_update_qword (ADDR, 2 * VAL);

  if (eeprom_read_dword (ADDR) != (uint32_t) (2 * VAL))
    exit (__LINE__);
  if (eeprom_read_dword (ADDR + 4) != (uint32_t) (VAL >> 31))
    exit (__LINE__);
}

void test3 (void)
{
  if (eeprom_read_qword (ADDR) != 2 * VAL)
    exit (__LINE__);
}

int main (void)
{
  test1 ();
  test2 ();
  test3 ();

  return 0;
}
