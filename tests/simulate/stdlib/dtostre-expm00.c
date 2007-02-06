/* Case of negative zero exponent: 'e-00'.
   $Id$
 */
#include <stdlib.h>
#include <string.h>
#include "progmem.h"
#include "dtostre.h"

PROGMEM static const struct dtostre_s t[] = {

    { { 0x3f7fffff }, 0, 0,	"1e-00" },
    { { 0x3f7fffff }, 1, 0,	"1.0e-00" },
    { { 0x3f7fffff }, 2, 0,	"1.00e-00" },
    { { 0x3f7fffff }, 3, 0,	"1.000e-00" },
    { { 0x3f7fffff }, 4, 0,	"1.0000e-00" },
    { { 0x3f7fffff }, 5, 0,	"1.00000e-00" },
    { { 0x3f7fffff }, 6, 0,	"9.999999e-01" },
    { { 0x3f7fffff }, 7, 0,	"9.9999994e-01" },

    { { 0xbf7fffff }, 0, 0,	"-1e-00" },
    
    { { .fl = 0.9500001 }, 0, 0,	"1e-00" },
    { { .fl = 0.9950001 }, 1, 0,	"1.0e-00" },
    { { .fl = 0.9995001 }, 2, 0,	"1.00e-00" },
    { { .fl = 0.9999501 }, 3, 0,	"1.000e-00" },
    { { .fl = 0.9999951 }, 4, 0,	"1.0000e-00" },
    { { .fl = 0.9999996 }, 5, 0,	"1.00000e-00" },
};

int main ()
{
    int i;
    for (i= 0; (size_t)i != sizeof(t)/sizeof(t[0]); i++)
	run_dtostre (t+i, i+1);
    return 0;
}
