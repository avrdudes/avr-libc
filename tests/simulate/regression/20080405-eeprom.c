/* Support of the .eeprom section by 'runtest.sh'.
   $Id$	*/

#ifdef	__AVR__
# include <avr/eeprom.h>
#else
# define EEMEM
#endif

EEMEM char e[10];

int main ()
{
    return 0;
}
