/* bug #22593: vfscanf improperly scans string parameters with a width
   option by 1 character
   $Id$	*/

/* Seems, this is duplication of bug #19079: sscanf %s eats 1 char too much
 */

#include <stdio.h>
#include <string.h>

#ifndef	__AVR__
# define sscanf_P	sscanf
# define PSTR(s)	(s)
#else
# include <avr/pgmspace.h>
#endif

int main ()
{
    char s1[5], s2[5];
    int result;
    
    s1[0] = 0;
    s2[0] = 0;

    result = sscanf_P (",ABCD,EFGH,", PSTR (",%4s,%4s,"), s1, s2);
    if (result != 2)
	return __LINE__;
    if (strcmp (s1, "ABCD") || strcmp (s2, "EFGH"))
	return __LINE__;

    s1[0] = 0;
    s2[0] = 0;
    result = sscanf_P (",ABCD,EFGH,", PSTR (",%3s,%3s,"), s1, s2);
    if (result != 1)
	return __LINE__;
    if (strcmp (s1, "ABC"))
	return __LINE__;

    return 0;
}
