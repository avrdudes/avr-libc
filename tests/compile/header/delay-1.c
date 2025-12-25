/* ARGS: -Os */

#define F_CPU 1000000

#include <util/delay.h>

int main (void)
{
    _delay_ms (100);
    _delay_us (100);

    return 0;
}
