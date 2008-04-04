/* bug #22828: eeprom_write_block(): incompatibility in args order
   $Id$	*/

#include <string.h>

#ifdef	__AVR__
# include <avr/eeprom.h>
# define EEPROM_ADDR	(void *)1
#else
# define eeprom_write_block(src, dst, size)	memcpy (dst, src, size)
# define eeprom_read_block(dst, src, size)	memcpy (dst, src, size)
char EEPROM_ADDR[20];
#endif

const char s[] = "Apple";
char t[sizeof(s)];

int main ()
{

    eeprom_write_block (s, EEPROM_ADDR, sizeof(s));
    memset (t, 0, sizeof(t));
    eeprom_read_block (t, EEPROM_ADDR, sizeof(t));
    if (strcmp (t, "Apple")) return __LINE__;

    return 0;
}
