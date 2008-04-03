/* bug #22800: sprintf() expands a 128char string parameter incorrectly
   $Id$
   
   This bug is marked as INVALID.  It is take place with avr-libc 1.4 only,
   which is not supported now.  Avr-libc 1.6 is correct.
 */

#include <stdio.h>
#include <string.h>

#ifndef	__AVR__
# define strcmp_P	strcmp
# define PSTR(s)	(s)
#else
# include <avr/pgmspace.h>
#endif


char buffer[210], string[200];
char tmp[] = "123";

int main ()
{
    int i;

    /* This is the bug report code.	*/
    for (i = 0; i < 129; i++)
	string[i] = 'B';
    sprintf (buffer, "%s%s", string, tmp);
    
    if (strcmp_P (buffer, PSTR ("BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"  /* 32*B */
				"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"  /* 32*B */
				"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"  /* 32*B */
				"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"  /* 32*B */
				"B123")))
    {
	return __LINE__;
    }

#if	!defined(__AVR__) || (RAMEND >= 0x45F)
    /* Check the size > 255.	*/
    {
	char s[260];
	char t[sizeof(s)];

	memset (s, 'A', sizeof(s));
	s[sizeof(s) - 1] = 0;
	memset (t, 'B', sizeof(t));
	sprintf (t, "%s", s);
	
	if (strcmp (s, t)) return __LINE__;
    }
#endif
    
    return 0;
}
