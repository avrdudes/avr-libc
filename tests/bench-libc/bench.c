#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "avrtest.h"

#define sprintf_min sprintf
#define sprintf_flt sprintf

#define sscanf_min sscanf
#define sscanf_flt sscanf

#if __SIZEOF_DOUBLE__ == 4
#define ftostre dtostre
#define ftostrf dtostrf
#define strtof strtod
#endif

int cmp (const void *a, const void *b)
{
    const char *pa = (const char*) a;
    const char *pb = (const char*) b;
    return *pa - *pb;
}

int i;
long l;
long long ll;
float x;
char s[100];
void *pv;
char *end;

void __attribute__((constructor))
init_for_qsort (void)
{
    for (uint8_t i = 0; i < sizeof (s); ++i)
        s[i] = avrtest_prand ();
}

int main (void)
{
    PERF_START_CALL (1);

#include "code.out"

    PERF_DUMP (1);

    return 0;
}
