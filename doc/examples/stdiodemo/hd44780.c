/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <joerg@FreeBSD.ORG> wrote this file.  As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return.        Joerg Wunsch
 * ----------------------------------------------------------------------------
 *
 * HD44780 LCD display driver
 *
 * The LCD controller is used in 4-bit mode with a full bi-directional
 * interface (i.e. R/~W is connected) so the busy flag can be read.
 *
 * $Id$
 */

#include "defines.h"

#include <stdint.h>

#include <avr/io.h>
#include <util/delay.h>

#include "hd44780.h"

#define GLUE(a, b)     a##b
#define PORT(x)        GLUE(PORT, x)
#define PIN(x)         GLUE(PIN, x)
#define DDR(x)         GLUE(DDR, x)

#define HD44780_PORTOUT    PORT(HD44780_PORT)
#define HD44780_PORTIN     PIN(HD44780_PORT)
#define HD44780_DDR        DDR(HD44780_PORT)

#define HD44780_DATABITS \
(_BV(HD44780_D4)|_BV(HD44780_D5)|_BV(HD44780_D6)|_BV(HD44780_D7))

#define HD44780_BUSYFLAG 0x80

/*
 * Send one pulse to the E signal (enable).  Mind the timing
 * constraints.
 */
static inline void
hd44780_pulse_e(void)
{

  HD44780_PORTOUT |= _BV(HD44780_E);
#if F_CPU > 4000000UL
  _delay_us(0.5);		/* guarantee 500 ns high */
#elif F_CPU > 2000000UL
  __asm__ volatile("nop");
#endif
  HD44780_PORTOUT &= ~_BV(HD44780_E);
}

/*
 * Send one nibble out to the LCD controller.
 */
static void
hd44780_outnibble(uint8_t n, uint8_t rs)
{
  uint8_t x;

  HD44780_PORTOUT &= ~_BV(HD44780_RW);
  if (rs)
    HD44780_PORTOUT |= _BV(HD44780_RS);
  else
    HD44780_PORTOUT &= ~_BV(HD44780_RS);
  x = (HD44780_PORTOUT & ~HD44780_DATABITS) | (n & HD44780_DATABITS);
  HD44780_PORTOUT = x;
  hd44780_pulse_e();
}

/*
 * Send one byte to the LCD controller.  As we are in 4-bit mode, we
 * have to send two nibbles.
 */
void
hd44780_outbyte(uint8_t b, uint8_t rs)
{
  hd44780_outnibble(b >> 4, rs);
  hd44780_outnibble(b & 0xf, rs);
}

/*
 * Read one nibble from the LCD controller.
 */
static uint8_t
hd44780_innibble(uint8_t rs)
{
  uint8_t x;

  HD44780_PORTOUT |= _BV(HD44780_RW);
  HD44780_DDR &= ~HD44780_DATABITS;
  if (rs)
    HD44780_PORTOUT |= _BV(HD44780_RS);
  else
    HD44780_PORTOUT &= ~_BV(HD44780_RS);
  hd44780_pulse_e();
  x = HD44780_PORTIN & HD44780_DATABITS;
  HD44780_DDR |= HD44780_DATABITS;
  HD44780_PORTOUT &= ~_BV(HD44780_RW);

  return x & HD44780_DATABITS;
}

/*
 * Read one byte (i.e. two nibbles) from the LCD controller.
 */
uint8_t
hd44780_inbyte(uint8_t rs)
{
  uint8_t x;

  x = hd44780_innibble(rs) << 4;
  x |= hd44780_innibble(rs);

  return x;
}

/*
 * Wait until the busy flag is cleared.
 */
void
hd44780_wait_ready(void)
{
  while (hd44780_incmd() & HD44780_BUSYFLAG) ;
}

/*
 * Initialize the LCD controller.
 *
 * The initialization sequence has a mandatory timing so the
 * controller can safely recognize the type of interface desired.
 * This is the only area where timed waits are really needed as
 * the busy flag cannot be probed initially.
 */
void
hd44780_init(void)
{

  HD44780_DDR = _BV(HD44780_RS) | _BV(HD44780_RW) | _BV(HD44780_E)
    | HD44780_DATABITS;

  _delay_ms(15);		/* 40 ms needed for Vcc = 2.7 V */
  hd44780_outnibble(HD44780_FNSET(1, 0, 0) >> 4, 0);
  _delay_ms(4.1);
  hd44780_outnibble(HD44780_FNSET(1, 0, 0) >> 4, 0);
  _delay_ms(0.1);
  hd44780_outnibble(HD44780_FNSET(1, 0, 0) >> 4, 0);

  hd44780_outnibble(HD44780_FNSET(0, 1, 0) >> 4, 0);
  hd44780_wait_ready();
  hd44780_outcmd(HD44780_FNSET(0, 1, 0));
  hd44780_wait_ready();
  hd44780_outcmd(HD44780_DISPCTL(0, 0, 0));
  hd44780_wait_ready();
}

