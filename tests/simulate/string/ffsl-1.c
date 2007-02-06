/* $Id$	*/

#ifndef	__AVR__
# define _GNU_SOURCE
#endif
#include <stdlib.h>
#include <string.h>

int main ()
{
    static struct t_s {
	long val;
	unsigned char pattern;
    } t[] = {
	{ 0, 0 },
	{ 1, 1 },
	{ 0xffffffff, 1 },
	{ 0x00000002, 2 },
	{ 0x80000002, 2 },
	{ 0xfffffff2, 2 },
	{ 0x00000040, 7 },
	{ 0xffffff40, 7 },
	{ 0x00000080, 8 },
	{ 0xffffff80, 8 },

	{ 0x00000100, 9 },
	{ 0xffffff00, 9 },
	{ 0x00008000, 16 },
	{ 0xffff8000, 16 },
	
	{ 0x00010000, 17 },
	{ 0xffff0000, 17 },
	{ 0x00800000, 24 },
	{ 0xff800000, 24 },
	
	{ 0x01000000, 25 },
	{ 0xff000000, 25 },
	{ 0x80000000, 32 },
    };
    int i;
    
    for (i = 0; i != (int)(sizeof(t)/sizeof(t[0])); i++) {
	if (ffsl (t[i].val) != t[i].pattern)
	    exit (1 + i);
    }
    return 0;
}
