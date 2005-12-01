/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <joerg@FreeBSD.ORG> wrote this file.  As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return.        Joerg Wunsch
 * ----------------------------------------------------------------------------
 *
 * IO feature compatibility definitions for various AVRs.
 *
 * $Id$
 */

#if !defined(IOCOMPAT_H)
#define IOCOMPAT_H 1

#if defined(__AVR_AT90S2313__)
#  define OC1 PB3
#  define OCR OCR1
#  define DDROC DDRB
#  define TIMER1_OVF_vect TIMER1_OVF1_vect
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
#elif defined(__AVR_ATmega8__) || defined(__AVR_ATmega48__) || \
      defined(__AVR_ATmega88__) || defined(__AVR_ATmega168__)
#  define OC1 PB1
#  define DDROC DDRB
#  define OCR OCR1A
#  if !defined(TIMSK)		/* ATmega48/88/168 */
#    define TIMSK TIMSK1
#  endif /* !defined(TIMSK) */
#elif defined(__AVR_ATmega32__) || defined(__AVR_ATmega16__)
#  define OC1 PD5
#  define DDROC DDRD
#  define OCR OCR1A
#elif defined(__AVR_ATmega64__) || defined(__AVR_ATmega128__)
#  define OC1 PB5
#  define DDROC DDRB
#  define OCR OCR1A
#else
#  error "Don't know what kind of MCU you are compiling for"
#endif

#if !defined(COM1A1)
#  define COM1A1 COM11
#endif

#if !defined(WGM10)
#  define WGM10 PWM10
#  define WGM11 PWM11
#endif

#endif /* !defined(IOCOMPAT_H) */
