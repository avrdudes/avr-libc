#include <avr/pgmspace.h>
#include <stdio.h>

/*
  You can put data in program memory,
  but reading this data allowed only through macro `pgm_read_byte'
*/



prog_char b[500] = {1,2,3,4,5}; /* This 8bit array in program memory. */

prog_int i[10] = {1,2,3,4,5}; /* This 16bit array in program memory. */

prog_long l[] = {1,2,3,4,5}; /* This 32bit array in program memory. */

prog_long_long ll[] = {1,2,3,4,5}; /* This 64bit array in program memory. */

char a[] PROGMEM = "This string in program memory too";

void
foo(void)
{
  char *p = PSTR ("This string in program memory");
  
  printf_P (PSTR ("This string in program memory"));
  
  char c = pgm_read_byte (p+5);	/* c = 's' */
  char aa = pgm_read_byte (&a[10]);	/* aa = 'g' */
  char bb = pgm_read_byte (&b[3]);	/* bb = 4 */
  
}
