#include <progmem.h>

/*
  You can put data in program memory,
  but reading this data allowed only through macro `PRG_RDB'
*/



prog_char b[500] = {1,2,3,4,5}; /* This 8bit array in program memory. */

prog_int i[10] = {1,2,3,4,5}; /* This 16bit array in program memory. */

prog_long l[] = {1,2,3,4,5}; /* This 32bit array in program memory. */

prog_long_long ll[] = {1,2,3,4,5}; /* This 64bit array in program memory. */

char a[] __attribute__ ((progmem)) = "This string in program memory too";

void
foo(void)
{
  char *p = PSTR ("This string in program memory");
  
  printf (PSTR ("This string in program memory")); /* special version of
						      printf needed ! */
  
  char c = PRG_RDB (p+5);	/* c = 's' */
  char aa = PRG_RDB (&a[10]);	/* aa = 'g' */
  char bb = PRG_RDB (&b[3]);	/* bb = 4 */
  
}
