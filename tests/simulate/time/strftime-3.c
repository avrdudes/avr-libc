#ifdef __AVR_TINY__
int main (void) { return 0; }
#else
#include <stdio.h>
#include <time.h>
#include <avr/flash.h>

typedef struct
{
    const char *fmt;
    const __flash char *res;
} res_t;

// 'E' and 'O' prefix are ignored.

const __flash res_t Res[] =
{
    { "A%x%%%X--%a", FLIT("A02/07/36%06:28:15--Tue") },

    { NULL, FLIT("") }
};


int main (void)
{
	time_t t = -1ul;
	struct tm tm, *tmp = &tm;

	localtime_r (&t, tmp);

    for (const __flash res_t *r = Res; r->fmt; ++r)
    {
        char tstr[40];

        strftime (tstr, sizeof (tstr), r->fmt, tmp);

        if (strcmp_F (tstr, r->res))
        {
            printf_FSTR ("==============\n");
            printf_FSTR ("%s: soll=\"%S\"\n", r->fmt, r->res);
            printf_FSTR ("%s: ist= \"%s\"\n", r->fmt, tstr);

            exit (__LINE__);
        }
    }

    return 0;
}
#endif
