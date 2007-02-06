/* $Id$ */

#include <stdlib.h>
#include <string.h>
#include "progmem.h"
#include "dtostre.h"

PROGMEM static const struct dtostre_s t[] = {

    { { 0x7f800000 }, 0, 0,			"inf" },
    { { 0x7f800000 }, 0, DTOSTR_ALWAYS_SIGN,	" inf" },
    { { 0x7f800000 }, 0, DTOSTR_PLUS_SIGN,	"+inf" },
    { { 0x7f800000 }, 0, DTOSTR_UPPERCASE,	"INF" },
    { { 0xff800000 }, 0, 0,			"-inf" },
    { { 0xff800000 }, 0, DTOSTR_ALWAYS_SIGN,	"-inf" },
    { { 0xff800000 }, 0, DTOSTR_PLUS_SIGN,	"-inf" },
    { { 0xff800000 }, 0, DTOSTR_UPPERCASE,	"-INF" },

    { { 0x7f800001 }, 0, 0,			"nan" },
    { { 0x7f800001 }, 0, DTOSTR_ALWAYS_SIGN,	" nan" },
    { { 0x7f800001 }, 0, DTOSTR_PLUS_SIGN,	"+nan" },
    { { 0x7f800001 }, 0, DTOSTR_UPPERCASE,	"NAN" },
    { { 0xff800001 }, 0, 0,			"nan" },    /* no '-NaN' */
    { { 0xff800001 }, 0, DTOSTR_ALWAYS_SIGN,	" nan" },
    { { 0xff800001 }, 0, DTOSTR_PLUS_SIGN,	"+nan" },
    { { 0xff800001 }, 0, DTOSTR_UPPERCASE,	"NAN" },

    { { 0x7fffffff }, 0, 0,			"nan" },
    { { 0xffffffff }, 0, 0,			"nan" },
    { { 0x7fc00000 }, 0, 0,			"nan" },
    { { 0xffc00000 }, 0, 0,			"nan" },
};

int main ()
{
    int i;
    for (i= 0; (size_t)i != sizeof(t)/sizeof(t[0]); i++)
	run_dtostre (t+i, i+1);
    return 0;
}
