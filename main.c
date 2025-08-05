#define F_CPU 16000000UL  // Define CPU frequency for delay
#include <avr/io.h>
#include <util/delay.h>

int main(void) {
    // Set pin 13 (PB5) as output
    DDRB |= (1 << PB5);

    while (1) {
        // Toggle pin 13
        PORTB ^= (1 << PB5);
        _delay_ms(500);  // Wait 500 milliseconds
    }
}
