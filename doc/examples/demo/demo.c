/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <joerg@FreeBSD.ORG> wrote this file.  As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return.        Joerg Wunsch
 * ----------------------------------------------------------------------------
 *
 * Simple AVR demonstration.  Controls a LED that can be directly
 * connected from a pin to GND.  The brightness of the LED is
 * controlled with the PWM.  After each period of the PWM, the PWM
 * value is either incremented or decremented, that's all.
 *
 * Configured to run on an Arduino Nano compatible device with an
 * ATmega328P.  The board has a LED, which is connected to PB5.  Since
 * PB5 is not a hardware waveform output from a timer on the
 * ATmega328P, the LED is toggled within the timer interrupts.
 */

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>

/* Note [1] */
#define TIMER1_TOP 1023
#define TIMER1_CTRLA (0)
#define TIMER1_CTRLB (_BV(WGM13) | _BV(WGM12) | 2)

#define LED_PORT PORTB
#define LED_DDR  DDRB
#define LED_PIN  _BV(5)

enum { UP, DOWN };

ISR(TIMER1_CAPT_vect)           // Note [2]
{
    // turn on LED
    LED_PORT |= LED_PIN;        // Note [3]

    static uint16_t pwm;        // Note [4]
    static uint8_t direction;

    switch (direction)          // Note [5]
    {
        case UP:
            if (++pwm == TIMER1_TOP)
                direction = DOWN;
            break;

        case DOWN:
            if (--pwm == 0)
                direction = UP;
            break;
    }

    OCR1A = pwm;                // Note [6]
}

ISR(TIMER1_COMPA_vect)
{
    // turn off LED
    LED_PORT &= ~LED_PIN;       // Note [7]
}

static void
ioinit(void)                    // Note [8]
{
    /* Timer 1 in CTC mode with 10 bits, CPU/8 speed */
    ICR1 = TIMER1_TOP;
    TCCR1A = TIMER1_CTRLA;
    TCCR1B = TIMER1_CTRLB;

    /* Set PWM value to 0. */
    OCR1A = 1;

    /* Enable OC1 as output. */
    LED_DDR |= LED_PIN;

    /* Enable timer 1 overflow and compare A interrupt. */
    TIMSK1 = _BV (ICIE1) | _BV(OCIE1A);
    sei ();
}

int
main(void)
{
    ioinit ();

    /* Loop forever, the interrupts are doing the rest.  */

    for (;;)                    // Note [9]
        sleep_mode();

    return 0;
}
