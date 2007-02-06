/* Base test.
   $Id$
 */
#include <stdlib.h>
#include <string.h>
#include "progmem.h"
#include "strtol.h"

PROGMEM static const struct t_s {
    char s[14];		/* string to convert	*/
    int base;
    long ret;		/* result must	*/
    int err;		/* errno must	*/
    unsigned char len;	/* endptr displacement must	*/
} t[] = {
    { "", 0,	    0, 0, 0 },
    { "-", 0,	    0, 0, 0 },
    { "+", 0,	    0, 0, 0 },
    { "    ", 0,    0, 0, 0 },

#ifdef	__AVR__		/* AVR: errno is't set in case of invalid base	*/
    { "", -1,	    0, 0, 0 },
    { "0", 1,	    0, 0, 0 },
    { "123", 37,    0, 0, 0 },
#else
    { "", -1,	    0, EINVAL, 0 },
    { "0", 1,	    0, EINVAL, 0 },
    { "123", 37,    0, EINVAL, 0 },
#endif
	
    { "0", 0,	    0, 0, 1 },
    { "0 ", 0,	    0, 0, 1 },
    { " 0", 0,	    0, 0, 2 },
    { "\t0", 0,	    0, 0, 2 },
    { " \t 0", 0,   0, 0, 4 },
    { "0x0", 0,	    0, 0, 3 },
    { "0000", 0,    0, 0, 4 },
    { "+0", 0,	    0, 0, 2 },
    { "-0", 0,	    0, 0, 2 },
	
    { "0x", 0,	    0, 0, 1 },
    { "0x", 16,	    0, 0, 1 },
    { "0X", 0,	    0, 0, 1 },
    { " 0x", 0,	    0, 0, 2 },
    { "0xx", 0,	    0, 0, 1 },
    { "-0x", 0,	    0, 0, 2 },
    { "-0x", 16,    0, 0, 2 },
    { "+0x", 0,	    0, 0, 2 },
	
    { "1", 0,	    1, 0, 1 },
    { "-1", 0,	    -1, 0, 2 },

    { "210", 3,	    2*9 + 1*3 + 0,		0, 3 },
    { "a98", 11,    10*11*11L + 9*11 + 8,	0, 3 },
    { "xyz", 36,    33*36*36L + 34*36 + 35,	0, 3 },
	
    { "12345", 8,    012345, 0, 5 },
    { "12345", 10,    12345, 0, 5 },
    { "12345", 16,    0x12345, 0, 5 },
};

int main ()
{
    struct t_s tt;
    int i;
    
    for (i = 0; i != (int)(sizeof(t)/sizeof(t[0])); i++) {
	memcpy_P (&tt, t+i, sizeof(tt));
	if (t_strtol (tt.s, tt.base, tt.ret, tt.err, tt.len))
	    exit (i+1);
    }
    return 0;
}
