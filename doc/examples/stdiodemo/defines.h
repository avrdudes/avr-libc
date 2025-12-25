/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <joerg@FreeBSD.ORG> wrote this file.  As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return.        Joerg Wunsch
 * ----------------------------------------------------------------------------
 *
 * General stdiodemo defines
 */

/* CPU frequency */
#define F_CPU 16000000UL

/* UART baud rate */
#define UART_BAUD  9600

/* HD44780 LCD port connections */
#define HD44780_RW B, 0 // D8 on Arduino Nano
#define HD44780_RS D, 7 // D7 on Arduino Nano

#define HD44780_E  D, 6 // D6 on Arduino Nano
/* The data bits D4-D7 have to be not only in ascending order but also
   consecutive. The LCD is operated in 4-bit mode, so D0-D4 remain
   unconnected. */
#define HD44780_D4 D, 2 // D2 through D5 on Arduino Nano

/* Whether to read the busy flag, or fall back to
   worst-time delays. */
#define USE_BUSY_BIT 1

/* Arduino Nano onboard LED */
#define LED_PORT PORTB
#define LED_DDR  DDRB
#define LED_PIN  _BV(5)
