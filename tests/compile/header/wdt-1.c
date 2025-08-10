#include <avr/wdt.h>

int main (void)
{
    wdt_enable (1);
    wdt_disable ();

    return 0;
}
