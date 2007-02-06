/* Nonregular cases.
   $Id$
 */
#include <stdlib.h>
#include <string.h>
#include "progmem.h"
#include "dtostre.h"

PROGMEM static const struct dtostre_s t[] = {

    { { .fl = 1e-15 }, 3, 0,		"1.000e-15" },
    { { .fl = -1e-15 }, 3, 0,		"-1.000e-15" },

    { { .fl = 1.234567 }, 6, 0,		"1.234567e+00" },
    { { .fl = -1.234567 }, 6, 0,	"-1.234567e+00" },
    
    { { .fl = 9.876543 }, 6, 0,		"9.876543e+00" },

};

int main ()
{
    int i;
    for (i= 0; (size_t)i != sizeof(t)/sizeof(t[0]); i++)
	run_dtostre (t+i, i+1);
    return 0;
}
