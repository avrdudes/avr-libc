/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <joerg@FreeBSD.ORG> wrote this file.  As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return.        Joerg Wunsch
 * ----------------------------------------------------------------------------
 *
 * Simple AVR demonstration.  Controls a LED that can be directly
 * connected from OC1/OC1A to GND.  The brightness of the LED is
 * controlled with the PWM.  After each period of the PWM, the PWM
 * value is either incremented or decremented, that's all.
 *
 * $Id$
 */

#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>

#include "iocompat.h"		/* Note [1] */

enum { UP, DOWN };

volatile uint16_t pwm;		/* Note [2] */
volatile uint8_t direction;

ISR (TIMER1_OVF_vect)		/* Note [3] */
{
    switch (direction)		/* Note [4] */
    {
        case UP:
            if (++pwm == 1023)
                direction = DOWN;
            break;

        case DOWN:
            if (--pwm == 0)
                direction = UP;
            break;
    }

    OCR = pwm;			/* Note [5] */
}

void
ioinit (void)			/* Note [6] */
{
    /* tmr1 is 10-bit PWM */
    TCCR1A = _BV (WGM10) | _BV (WGM11) | _BV (COM1A1);

    /* tmr1 running on full MCU clock */
    TCCR1B = _BV (CS10);

    /* set PWM value to 0 */
    OCR = 0;

    /* enable OC1 as output */
    DDROC = _BV (OC1);

    /* enable timer 1 overflow interrupt */
    TIMSK = _BV (TOIE1);
    sei ();
}

int
main (void)
{

    ioinit ();

    /* loop forever, the interrupts are doing the rest */

    for (;;)			/* Note [7] */
        sleep_mode();

    return (0);
}
