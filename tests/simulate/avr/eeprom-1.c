/* $Id$	*/

#include <avr/eeprom.h>
#include <stdlib.h>
#include <string.h>

/* Note: GCC permits arithmetic with 'void *'.	*/

int main ()
{
    void *p;
#define MAXLEN	(RAMEND > 0x15F ? 260 : (RAMEND - 0x60 - 30))
    unsigned char s[E2END > MAXLEN ? MAXLEN : E2END];

    /* Fill all EEPROM.	*/
    for (p = 0; p <= (void *)E2END; p++)
	eeprom_write_byte (p, ~(int)p);

    /* Read bytes.	*/
    for (p = 0; p <= (void *)E2END; p++)
	if (eeprom_read_byte (p) != (~(int)p & 0xFF))
	    exit (__LINE__);

    /* Read words.	*/
    for (p = 0; p <= (void *)E2END - 1; p += 2) {
	if (eeprom_read_word (p)
	    != ((~(unsigned)p & 0xFF) | (~(unsigned)(p+1) & 0xFF) << 8))
	{
	    exit (__LINE__);
	}
    }

    /* Read double words.	*/
    for (p = 0; p <= (void *)E2END - 3; p += 4) {
	if (eeprom_read_dword (p)
	    != ((~(unsigned)p & 0xFF)
		| (~(unsigned)(p+1) & 0xFF) << 8
		| (unsigned long)(~(unsigned)(p+2) & 0xFF) << 16
		| (unsigned long)(~(unsigned)(p+3) & 0xFF) << 24))
	{
	    exit (__LINE__);
	}
    }

    /* Read blocks.	*/
    for (p = 0; p <= (void *)E2END; ) {
	size_t i, n;
	if ( (n = E2END + 1 - (unsigned)p) > sizeof(s))
	    n = sizeof(s);
	eeprom_read_block (s, p, n);
	for (i = 0; i < n; i++) {
	    if (s[i] != (~(int)p & 0xFF))
		exit (__LINE__);
	    p += 1;
	}
    }

    /* Write only 1 byte.	*/
    eeprom_write_byte ((unsigned char *)5, 1);
    for (p = 0; p <= (void *)E2END; p++) {
	if ((unsigned)p != 5
	    && eeprom_read_byte (p) != (~(int)p & 0xFF))
	{
	    exit (__LINE__);
	}
    }
    if (eeprom_read_byte ((unsigned char *)5) != 1)
	exit (__LINE__);

    /* Write only 1 word.	*/
    eeprom_write_word ((unsigned *)5, 0x1234);
    for (p = 0; p <= (void *)E2END; p++) {
	if ((unsigned)p != 5
	    && (unsigned)p != 6
	    && eeprom_read_byte (p) != (~(int)p & 0xFF))
	{
	    exit (__LINE__);
	}
    }
    if (eeprom_read_word ((unsigned *)5) != 0x1234)
	exit (__LINE__);

    /* Write only 1 double word.	*/
    eeprom_write_dword ((unsigned long *)5, 0x12345678);
    for (p = 0; p <= (void *)E2END; p++) {
	if (((unsigned)p < 5 || (unsigned)p > 8)
	    && eeprom_read_byte (p) != (~(int)p & 0xFF))
	{
	    exit (__LINE__);
	}
    }
    if (eeprom_read_dword ((unsigned long *)5) != 0x12345678)
	exit (__LINE__);

    /* Write block.	*/
    eeprom_write_block ((void *)5, "\x90\xAB\xCD\xEF\x01", 5);
    for (p = 0; p <= (void *)E2END; p++) {
	if (((unsigned)p < 5 || (unsigned)p > 9)
	    && eeprom_read_byte (p) != (~(int)p & 0xFF))
	{
	    exit (__LINE__);
	}
    }
    eeprom_read_block (s, (const void *)5, 5);
    if (memcmp (s, "\x90\xAB\xCD\xEF\x01", 3))
	exit (__LINE__);

    return 0;
}
