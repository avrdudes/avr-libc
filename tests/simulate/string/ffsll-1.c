/* $Id$	*/

#ifndef	__AVR__
# define _GNU_SOURCE
#endif
#include <stdlib.h>
#include <string.h>

int main ()
{
    static struct t_s {
	long long val;
	unsigned char pattern;
    } t[] = {
	{ 0LL, 0 },
	{ 1LL, 1 },
	{ 0xffffffffffffffffLL, 1 },
	{ 0x0000000000000002LL, 2 },
	{ 0x8000000000000002LL, 2 },
	{ 0x7ffffffffffffff2LL, 2 },
	{ 0xfffffffffffffff2LL, 2 },
	{ 0x0000000000000040LL, 7 },
	{ 0xffffffffffffff40LL, 7 },
	{ 0x0000000000000080LL, 8 },
	{ 0xffffffffffffff80LL, 8 },

	{ 0x0000000000000100LL, 9 },
	{ 0xffffffffffffff00LL, 9 },
	{ 0x0000000000008000LL, 16 },
	{ 0xffffffffffff8000LL, 16 },
	
	{ 0x0000000000010000LL, 17 },
	{ 0xffffffffffff0000LL, 17 },
	{ 0x0000000000800000LL, 24 },
	{ 0xffffffffff800000LL, 24 },
	
	{ 0x0000000001000000LL, 25 },
	{ 0xffffffffff000000LL, 25 },
	{ 0x0000000080000000LL, 32 },
	{ 0xffffffff80000000LL, 32 },
	
	{ 0x0000000100000000LL, 33 },
	{ 0xffffffff00000000LL, 33 },
	{ 0x0000008000000000LL, 40 },
	{ 0xffffff8000000000LL, 40 },
	
	{ 0x0000010000000000LL, 41 },
	{ 0xffffff0000000000LL, 41 },
	{ 0x0000800000000000LL, 48 },
	{ 0xffff800000000000LL, 48 },
	
	{ 0x0001000000000000LL, 49 },
	{ 0xffff000000000000LL, 49 },
	{ 0x0080000000000000LL, 56 },
	{ 0xff80000000000000LL, 56 },

	{ 0x0100000000000000LL, 57 },
	{ 0xff00000000000000LL, 57 },
	{ 0x8000000000000000LL, 64 },
    };
    int i;
    
    for (i = 0; i != (int)(sizeof(t)/sizeof(t[0])); i++) {
	if (ffsll (t[i].val) != t[i].pattern)
	    exit (1 + i);
    }
    return 0;
}
