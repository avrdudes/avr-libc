#ifdef __AVR_TINY__
int main (void) { return 0; }
#else
#include <stdio.h>
#include <time.h>
#include <avr/flash.h>

typedef struct
{
    uint8_t ret;
    const __flash char *fmt;
    uint8_t lim;
} res_t;

// 'E' and 'O' prefix are ignored.

const __flash res_t Res[] =
{
    { 0, FLIT("ABC"), 2 },
    { 0, FLIT("ABC"), 3 },
    { 3, FLIT("ABC"), 4 },
    { 3, FLIT("ABC"), 5 },

    { 0, FLIT("%X"), 7 },
    { 0, FLIT("%X"), 8 },
    { 8, FLIT("%X"), 9 },
    { 8, FLIT("%X"), 10 },

    { 0, FLIT("%X%t"), 7 },
    { 0, FLIT("%X%t"), 8 },
    { 0, FLIT("%X%t"), 9 },
    { 9, FLIT("%X%t"), 10 },

    { 0, FLIT(""), 0 }
};


int main (void)
{
	time_t t = -1ul;
	struct tm tm, *tmp = &tm;

	localtime_r (&t, tmp);

    for (const __flash res_t *r = Res; r->fmt[0]; ++r)
    {
        char tstr[40];
        char fmt[40];

        strcpy_F (fmt, r->fmt);
        uint8_t ret = strftime (tstr, r->lim, fmt, tmp);

        if (ret != r->ret)
        {
            printf_FSTR ("==============\n");
            printf_FSTR ("\"%s\": soll=%d\n", fmt, r->ret);
            printf_FSTR ("\"%s\": ist= %d\n", fmt, ret);

            exit (__LINE__);
        }

        tstr[3] = '*';
        ret = strftime (tstr, 3, "ABC", tmp);
        if (ret != 0)
            exit (__LINE__);
        if (tstr[3] != '*')
            exit (__LINE__);

        tstr[8] = '*';
        ret = strftime (tstr, 8, "%X", tmp);
        if (ret != 0)
            exit (__LINE__);
        if (tstr[8] != '*')
            exit (__LINE__);
    }

    return 0;
}
#endif
