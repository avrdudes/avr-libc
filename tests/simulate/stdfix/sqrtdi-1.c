#include <stdint.h>
#include <stdlib.h>

#define U24BIT 16777215ULL

#define FUN(x) sqrtu64_floor (x);

int main (void)
{
    uint32_t r;
    uint64_t sqr;
    if (UINT64_MAX != 18446744073709551615ULL) exit (__LINE__);

    /* Test limiting values first. */
    r = FUN (0ULL);
    if (r != 0UL) exit (__LINE__);
    r = FUN (1ULL);
    if (r != 1UL) exit (__LINE__);
    r = FUN (UINT64_MAX);
    if (r != UINT32_MAX) exit (__LINE__);

    /* Test squares of all 8-bit numbers */
    for (uint16_t i = 1UL; i < UINT8_MAX; i++)
    {
        sqr = (uint64_t) i * i;
        r = FUN (sqr);
        if (r != i) exit (__LINE__);
        uint32_t r2 = FUN (sqr - 1);
        if (r2 != r - 1) exit (__LINE__);
    }

    /* Test different ranges where high-order bits are set */
    for (uint32_t i = 1UL; i < 100UL; i++)
    {
        uint64_t tmp = UINT16_MAX + 173ULL * (uint64_t) i;
        sqr = tmp * tmp;
        r = FUN (sqr);
        if (r != tmp) exit (__LINE__);
        uint32_t r2 = FUN (sqr - 1);
        if (r2 != r - 1) exit (__LINE__);
    }
    for (uint32_t i = 1UL; i < 100UL; i++)
    {
        uint64_t tmp = U24BIT + 1234ULL * i;
        sqr = tmp * tmp;
        r = FUN (sqr);
        if (r != tmp) exit (__LINE__);
        uint32_t r2 = FUN (sqr - 1);
        if (r2 != r - 1) exit (__LINE__);
    }
    return 0;
}
