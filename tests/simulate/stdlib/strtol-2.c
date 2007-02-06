/* Overflow.
   $Id$
 */
#include <stdlib.h>
#include "strtol.h"

int main ()
{
    static struct t_s {
	char s[14];		/* string to convert	*/
	int base;
	long ret;		/* result must	*/
	int err;		/* errno must	*/
	unsigned char len;	/* endptr displacement must	*/
    } t[] = {
	
	{ "2147483647", 0,	0x7fffffff, 0, 10 },
	{ "0x7fffffff", 0,	0x7fffffff, 0, 10 },
	{ "017777777777", 0,	0x7fffffff, 0, 12 },
	{ "2147483648", 0,	0x7fffffff, ERANGE, 10 },
	{ "0x80000000", 0,	0x7fffffff, ERANGE, 10 },
	{ "020000000000", 0,	0x7fffffff, ERANGE, 12 },
	
	{ "-2147483647", 0,	0x80000001, 0, 11 },
	{ "-0x7fffffff", 0,	0x80000001, 0, 11 },
	{ "-017777777777", 0,	0x80000001, 0, 13 },
	{ "-2147483648", 0,	0x80000000, 0, 11 },
	{ "-0x80000000", 0,	0x80000000, 0, 11 },
	{ "-020000000000", 0,	0x80000000, 0, 13 },
	{ "-2147483649", 0,	0x80000000, ERANGE, 11 },
	{ "-0x80000001", 0,	0x80000000, ERANGE, 11 },
	{ "-020000000001", 0,	0x80000000, ERANGE, 13 },

    };
    int i;
    
    for (i = 0; i != (int)(sizeof(t)/sizeof(t[0])); i++) {
	struct t_s *p = t+i;
	if (t_strtol (p->s, p->base, p->ret, p->err, p->len))
	    exit (i+1);
    }
    return 0;
}
