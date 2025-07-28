#ifdef __AVR_TINY__
int main (void) { return 0; }
#else
#include <stdio.h>
#include <time.h>
#include <avr/flash.h>

typedef struct
{
    char c;
    const __flash char *res;
} res_t;

// 'E' and 'O' prefix are ignored.

const __flash res_t Res[] =
{
    { 'a', FLIT("Tue") },         // day name (short)
    { 'A', FLIT("Tuesday") },     // day name
    { 'b', FLIT("Feb") },         // month name (short)
    { 'B', FLIT("February") },    // month name
    // preferred date + time "%a %b %d %H:%M:%S %Y"
    { 'c', FLIT("Tue Feb 07 06:28:15 2136") },
    { 'C', FLIT("21") },          // century in 00..99
    { 'd', FLIT("07") },          // day of month in 01..31
    { 'D', FLIT("02/07/36") },    // %m/%d/%y
    { 'e', FLIT(" 7") },          // day of month in " 1"..."31"
    { 'F', FLIT("2136-02-07") },  // %Y-%m-%d (ISO 8601)
    { 'G', FLIT("2136") },        // Week-based year in 0000..9999
    { 'g', FLIT("36") },          // week-based year in 00..99
    { 'h', FLIT("Feb") },         // = %b
    { 'H', FLIT("06") },          // hour in 00..23
    { 'I', FLIT("06") },          // hour in 01..12
    { 'j', FLIT("038") },         // day of year in 001...366
    // { 'k', FLIT("?") },        // hour in " 0".."23"
    // { 'l', FLIT("?") },        // hour in " 1".."12"
    { 'm', FLIT("02") },          // month in 01..12
    { 'M', FLIT("28") },          // minute in 00..59
    { 'n', FLIT("\n") },          // newline
    { 'p', FLIT("AM") },          // AM or PM
    // { 'P', FLIT("?") },        // am or pm
    { 'r', FLIT("06:28:15 AM") }, // "%I:%M:%S %p"
    { 'R', FLIT("06:28") },       // "%H:%M"
    // { 's', FLIT("?") },        // # seconds in the epoch
    { 'S', FLIT("15") },          // second in 00..60
    { 't', FLIT("\t") },          // TAB
    { 'T', FLIT("06:28:15") },    // "%H:%M:%S"
    { 'u', FLIT("2") },           // weekday in 1..7
    { 'U', FLIT("06") },          // week in 00..53
    { 'V', FLIT("06") },          // ISO 8601 week in 01..53
    { 'w', FLIT("2") },           // weekday in 0..6
    { 'W', FLIT("06") },          // week in 00..53
    { 'x', FLIT("02/07/36") },    // "%m/%d/%y" preferred date
    { 'X', FLIT("06:28:15") },    // "%H:%M:%S" preferred time
    { 'y', FLIT("36") },          // year in 00..99
    { 'Y', FLIT("2136") },        // year "%C%y"
    { 'z', FLIT("+0000") },       // +hhmm or -hhmm numeric timezone 
    // { 'Z', FLIT("?") },        // timezone name
    // { '+', FLIT("?") },        // date + time in date(1) format
    { '%', FLIT("%") },           // %

    { 0, FLIT("") }
};


int main (void)
{
	time_t t = -1ul;
	struct tm tm, *tmp = &tm;
    char tfmt[] = "%?";

	localtime_r (&t, tmp);

    for (const __flash res_t *r = Res; r->c; ++r)
    {
        char tstr[40];

        tfmt[1] = r->c;
        strftime (tstr, sizeof (tstr), tfmt, tmp);

        if (strcmp_F (tstr, r->res))
        {
            printf_FSTR ("==============\n");
            printf_FSTR ("%c: soll=\"%S\"\n", r->c, r->res);
            printf_FSTR ("%c: ist= \"%s\"\n", r->c, tstr);

            exit (r->c);
        }
    }
    
    return 0;
}
#endif
