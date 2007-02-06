/* Binary conversion.
   $Id$
 */
#include <stdlib.h>
#include <string.h>
#include "progmem.h"
#include "strtol.h"

int main ()
{
    PROGMEM static struct t_s {
	char s[34];		/* string to convert	*/
	int base;
	long ret;		/* result must	*/
	int err;		/* errno must	*/
	unsigned char len;	/* endptr displacement must	*/
    } t[] = {
	
	{ "0", 2,	0, 0, 1 },
	{ "1", 2,	1, 0, 1 },
	{ "-1", 2,	-1, 0, 2 },
	{ "10101010", 2,	0xaa, 0, 8 },
	{ "1111111111111111111111111111110", 2,	  0x7ffffffe, 0, 31 },
	{ "1111111111111111111111111111111", 2,	  0x7fffffff, 0, 31 },
	{ "10000000000000000000000000000000", 2,  0x7fffffff, ERANGE, 32 },
	{ "10000000000000000000000000000001", 2,  0x7fffffff, ERANGE, 32 },
	{ "-1111111111111111111111111111111", 2,  0x80000001, 0, 32 },
	{ "-10000000000000000000000000000000", 2, 0x80000000, 0, 33 },
	{ "-10000000000000000000000000000001", 2, 0x80000000, ERANGE, 33 },
	{ "-10000000000000000000000000000010", 2, 0x80000000, ERANGE, 33 },
	
    };
    struct t_s tt;
    int i;
    
    for (i = 0; i != (int)(sizeof(t)/sizeof(t[0])); i++) {
	struct t_s *p;
	memcpy_P (&tt, t + i, sizeof(tt));
	p = &tt;
	if (t_strtol (p->s, p->base, p->ret, p->err, p->len))
	    exit (i+1);
    }
    return 0;
}
