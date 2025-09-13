#include <stdlib.h>
#include <avr/eeprom.h>

#define ADDR ((void*) 10)

#define VAL 0x1122334455667788

/* Work around issue #954, which is due to a bug in SimulAVR.
   Clear XL by hand prior to calling the very EEPROM read func. */
#ifdef __AVR_ATtiny2313__
extern uint32_t eer_dword (const uint32_t*);
extern uint64_t eer_qword (const uint64_t*);
#define eeprom_read_dword(x) eer_dword (x)
#define eeprom_read_qword(x) eer_qword (x)
__asm (".pushsection .text\n"
       ".global eer_dword\n"
       ".global eer_qword\n"
       "eer_dword: clr r27 $ rjmp eeprom_read_dword\n"
       "eer_qword: clr r27 $ rjmp eeprom_read_qword\n"
       ".popsection");
#endif

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
