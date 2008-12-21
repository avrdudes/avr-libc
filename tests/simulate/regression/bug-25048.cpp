/* Avr-libc bug #25048: eeprom.h will not compile as c++ code.
   This is compile-time bug. It is actual for chips with small amount
   EEPROM memory, for example AT90S2313.
   $Id$	*/

#ifndef	__AVR__
int main ()	{ return 0; }
#else

#include <avr/eeprom.h>

EEMEM unsigned char c;

int main ()
{
    eeprom_write_byte (&c, 0);
    return eeprom_read_byte (&c);
}
#endif
