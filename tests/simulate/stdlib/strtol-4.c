/* With printf.
   $Id$
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "strtol.h"

int main ()
{
    char s[16];
    long x;
    
    for (x = 0; x <= 100; x++) {
	sprintf(s, "%ld", x);
	if (t_strtol(s, 0, x, 0, strlen(s)))
	    exit(__LINE__);
	sprintf(s, "%lx", x);
	if (t_strtol(s, 16, x, 0, strlen(s)))
	    exit(__LINE__);
	sprintf(s, "%lo", x);
	if (t_strtol(s, 8, x, 0, strlen(s)))
	    exit(__LINE__);
    }
    
    for (x = 0; x >= -100; x--) {
	sprintf(s, "%ld", x);
	if (t_strtol(s, 0, x, 0, strlen(s)))
	    exit(__LINE__);
	sprintf(s, "-%lx", -x);
	if (t_strtol(s, 16, x, 0, strlen(s)))
	    exit(__LINE__);
	sprintf(s, "-%lo", -x);
	if (t_strtol(s, 8, x, 0, strlen(s)))
	    exit(__LINE__);
    }
    
    for (x = LONG_MAX; x >= LONG_MAX - 100; x--) {
	sprintf(s, "%ld", x);
	if (t_strtol(s, 0, x, 0, strlen(s)))
	    exit(__LINE__);
	sprintf(s, "%lx", x);
	if (t_strtol(s, 16, x, 0, strlen(s)))
	    exit(__LINE__);
	sprintf(s, "%lo", x);
	if (t_strtol(s, 8, x, 0, strlen(s)))
	    exit(__LINE__);
    }
    
    for (x = LONG_MIN; x <= LONG_MIN + 100; x++) {
	sprintf(s, "%ld", x);
	if (t_strtol(s, 0, x, 0, strlen(s)))
	    exit(__LINE__);
	sprintf(s, "-%lx", -x);
	if (t_strtol(s, 16, x, 0, strlen(s)))
	    exit(__LINE__);
	sprintf(s, "-%lo", -x);
	if (t_strtol(s, 8, x, 0, strlen(s)))
	    exit(__LINE__);
    }
    
    for (x = 1; x <= 300; x++) {
	sprintf(s, "8%07lx", x);
	if (t_strtol(s, 16, 0x7fffffff, ERANGE, strlen(s)))
	    exit(__LINE__);
	sprintf(s, "-8%07lx", x);
	if (t_strtol(s, 16, 0x80000000, ERANGE, strlen(s)))
	    exit(__LINE__);
    }

    return 0;
}
