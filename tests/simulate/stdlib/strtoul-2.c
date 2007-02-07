/* Overflow.
   $Id$
 */
#include <stdlib.h>
#include <string.h>
#include "progmem.h"
#include "strtoul.h"

int main ()
{
    PROGMEM static struct t_s {
	char s[14];		/* string to convert	*/
	int base;
	unsigned long ret;	/* result must	*/
	int err;		/* errno must	*/
	unsigned char len;	/* endptr displacement must	*/
    } t[] = {
	
	{ "2147483647", 0,	0x7fffffff, 0, 10 },
	{ "0x7fffffff", 0,	0x7fffffff, 0, 10 },
	{ "017777777777", 0,	0x7fffffff, 0, 12 },
	{ "2147483648", 0,	0x80000000, 0, 10 },
	{ "0x80000000", 0,	0x80000000, 0, 10 },
	{ "020000000000", 0,	0x80000000, 0, 12 },
	
	{ "4294967295", 0,	0xffffffff, 0, 10 },
	{ "4294967296", 0,	0xffffffff, ERANGE, 10 },
	{ "4294967297", 0,	0xffffffff, ERANGE, 10 },
	{ "4294967298", 0,	0xffffffff, ERANGE, 10 },
	{ "4294967299", 0,	0xffffffff, ERANGE, 10 },
	{ "4294967300", 0,	0xffffffff, ERANGE, 10 },
	{ "4294967301", 0,	0xffffffff, ERANGE, 10 },
	{ "4294967302", 0,	0xffffffff, ERANGE, 10 },
	{ "4294967303", 0,	0xffffffff, ERANGE, 10 },
	{ "4294967304", 0,	0xffffffff, ERANGE, 10 },
	{ "4294967305", 0,	0xffffffff, ERANGE, 10 },
	{ "4294967306", 0,	0xffffffff, ERANGE, 10 },
	{ "9999999999999", 0,	0xffffffff, ERANGE, 13 },

	{ "037777777777", 0,	0xffffffff, 0, 12 },
	{ "040000000000", 0,	0xffffffff, ERANGE, 12 },
	{ "040000000001", 0,	0xffffffff, ERANGE, 12 },
	{ "040000000006", 0,	0xffffffff, ERANGE, 12 },
	{ "040000000007", 0,	0xffffffff, ERANGE, 12 },
	{ "040000000010", 0,	0xffffffff, ERANGE, 12 },
	{ "0777777777777", 0,	0xffffffff, ERANGE, 13 },
	
	{ "0xffffffff", 0,	0xffffffff, 0, 10},
	{ "0x100000000", 0,	0xffffffff, ERANGE, 11 },
	{ "0x100000001", 0,	0xffffffff, ERANGE, 11 },
	{ "0x10000000e", 0,	0xffffffff, ERANGE, 11 },
	{ "0x10000000f", 0,	0xffffffff, ERANGE, 11 },
	{ "0x100000010", 0,	0xffffffff, ERANGE, 11 },
	{ "0xfffffffffff", 0,	0xffffffff, ERANGE, 13 },
	
	{ "-2147483647", 0,	0x80000001, 0, 11 },
	{ "-0x7fffffff", 0,	0x80000001, 0, 11 },
	{ "-017777777777", 0,	0x80000001, 0, 13 },
	{ "-2147483648", 0,	0x80000000, 0, 11 },
	{ "-0x80000000", 0,	0x80000000, 0, 11 },
	{ "-020000000000", 0,	0x80000000, 0, 13 },
	{ "-2147483649", 0,	0x7fffffff, 0, 11 },
	{ "-0x80000001", 0,	0x7fffffff, 0, 11 },
	{ "-020000000001", 0,	0x7fffffff, 0, 13 },
	
	{ "-4294967295", 0,	0x00000001, 0, 11 },
	{ "-4294967296", 0,	0xffffffff, ERANGE, 11 },
	{ "-4294967297", 0,	0xffffffff, ERANGE, 11 },

    };
    int i;
    
    for (i = 0; i != (int)(sizeof(t)/sizeof(t[0])); i++) {
	struct t_s tt, *p;
	memcpy_P (&tt, t + i, sizeof(tt));
	p = &tt;
	if (t_strtoul (p->s, p->base, p->ret, p->err, p->len))
	    exit (i+1);
    }
    return 0;
}
