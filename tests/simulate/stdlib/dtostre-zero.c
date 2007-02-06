/* $Id$ */

#include <stdlib.h>
#include <string.h>
#include "progmem.h"
#include "dtostre.h"

PROGMEM static const struct dtostre_s t[] = {
    
    { { 0 }, 0, 0,		"0e+00" },
    { { 0x80000000 }, 0, 0,	"-0e+00" },	/* 'minus 0'	*/
    { { 0 }, 0, DTOSTR_PLUS_SIGN,	"+0e+00" },
    { { 0 }, 0, DTOSTR_ALWAYS_SIGN,	" 0e+00" },
    { { 0 }, 0, DTOSTR_ALWAYS_SIGN | DTOSTR_PLUS_SIGN,	"+0e+00" },
    { { 0 }, 0, DTOSTR_UPPERCASE,	"0E+00" },
    { { 0 }, 1, 0,		"0.0e+00" },
    { { 0 }, 2, 0,		"0.00e+00" },
    { { 0 }, 3, 0,		"0.000e+00" },
    { { 0 }, 4, 0,		"0.0000e+00" },
    { { 0 }, 5, 0,		"0.00000e+00" },
    { { 0 }, 6, 0,		"0.000000e+00" },
    { { 0 }, 7, 0,		"0.0000000e+00" },
    { { 0 }, 8, 0,		"0.0000000e+00" },
    { { 0 }, 255, 0,		"0.0000000e+00" },

};

int main ()
{
    int i;
    for (i= 0; (size_t)i != sizeof(t)/sizeof(t[0]); i++)
	run_dtostre (t+i, i+1);
    return 0;
}
