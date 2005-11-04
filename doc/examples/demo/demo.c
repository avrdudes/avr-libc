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

#if defined(__AVR_AT90S2313__)
#  define OC1 PB3
#  define OCR OCR1
#  define DDROC DDRB
#elif defined(__AVR_AT90S2333__) || defined(__AVR_AT90S4433__)
#  define OC1 PB1
#  define DDROC DDRB
#  define OCR OCR1
#elif defined(__AVR_AT90S4414__) || defined(__AVR_AT90S8515__) || \
      defined(__AVR_AT90S4434__) || defined(__AVR_AT90S8535__) || \
      defined(__AVR_ATmega163__)
#  define OC1 PD5
#  define DDROC DDRD
#  define OCR OCR1A
#elif defined(__AVR_ATmega8__)
#  define OC1 PB1
#  define DDROC DDRB
#  define OCR OCR1A
#  define PWM10 WGM10
#  define PWM11 WGM11
#elif defined(__AVR_ATmega32__) || defined(__AVR_ATmega16__)
#  define OC1 PD5
#  define DDROC DDRD
#  define OCR OCR1A
#  define PWM10 WGM10
#  define PWM11 WGM11
#elif defined(__AVR_ATmega64__) || defined(__AVR_ATmega128__)
#  define OC1 PB5
#  define DDROC DDRB
#  define OCR OCR1A
#  define PWM10 WGM10
#  define PWM11 WGM11
#else
#  error "Don't know what kind of MCU you are compiling for"
#endif

#if defined(COM11)
#  define XCOM11 COM11
#elif defined(COM1A1)
#  define XCOM11 COM1A1
#else
#  error "need either COM1A1 or COM11"
#endif

enum { UP, DOWN };

volatile uint16_t pwm; /* Note [1] */
volatile uint8_t direction;

ISR (TIMER1_OVF_vect) /* Note [2] */
{
    switch (direction) /* Note [3] */
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

    OCR = pwm; /* Note [4] */
}

void
ioinit (void) /* Note [5] */
{
    /* tmr1 is 10-bit PWM */
    TCCR1A = _BV (PWM10) | _BV (PWM11) | _BV (XCOM11);

    /* tmr1 running on full MCU clock */
    TCCR1B = _BV (CS10);

    /* set PWM value to 0 */
    OCR = 0;

    /* enable OC1 and PB2 as output */
    DDROC = _BV (OC1);

    /* enable interrupts */
    TIMSK = _BV (TOIE1);
    sei ();
}

int
main (void)
{
    ioinit ();

    /* loop forever, the interrupts are doing the rest */

    for (;;) /* Note [6] */
        ;

    return (0);
}
