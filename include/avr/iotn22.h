/* Copyright (c) 2002, Marek Michalkiewicz
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.
   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE. */

/* avr/iotn22.h - definitions for ATtiny22 */

#ifndef _AVR_IOTN22_H_
#define _AVR_IOTN22_H_ 1

#include <avr/sfr_defs.h>

/* I/O registers */

/* Input Pins, Port B */
#define PINB	_SFR_IO8(0x16)

/* Data Direction Register, Port B */
#define DDRB	_SFR_IO8(0x17)

/* Data Register, Port B */
#define PORTB	_SFR_IO8(0x18)

/* EEPROM Control Register */
#define EECR	_SFR_IO8(0x1C)

/* EEPROM Data Register */
#define EEDR	_SFR_IO8(0x1D)

/* EEPROM Address Register Low */
#define EEAR	_SFR_IO8(0x1E)
#define EEARL	_SFR_IO8(0x1E)

/* Watchdog Timer Control Register */
#define WDTCR	_SFR_IO8(0x21)

/* Timer/Counter 0 */
#define TCNT0	_SFR_IO8(0x32)

/* Timer/Counter 0 Control Register */
#define TCCR0	_SFR_IO8(0x33)

/* MCU Status Register */
#define MCUSR	_SFR_IO8(0x34)

/* MCU general Control Register */
#define MCUCR	_SFR_IO8(0x35)

/* Timer/Counter Interrupt Flag register */
#define TIFR	_SFR_IO8(0x38)

/* Timer/Counter Interrupt MaSK register */
#define TIMSK	_SFR_IO8(0x39)

/* General Interrupt Flag register */
#define GIFR	_SFR_IO8(0x3A)

/* General Interrupt MaSK register */
#define GIMSK	_SFR_IO8(0x3B)

/* Stack Pointer */
#define SP	_SFR_IO8(0x3D)
#define SPL	_SFR_IO8(0x3D)

/* Status REGister */
#define SREG	_SFR_IO8(0x3F)

/* Interrupt vectors */

#define SIG_INTERRUPT0		_VECTOR(1)
#define SIG_OVERFLOW0		_VECTOR(2)

#define _VECTORS_SIZE 6

/*
   The Register Bit names are represented by their bit number (0-7).
 */

/* General Interrupt MaSK register */
#define    INT0    6
#define    INTF0   6

/* General Interrupt Flag Register */
#define    TOIE0   1
#define    TOV0    1

/* MCU general Control Register */
#define    SE      5
#define    SM      4
#define    ISC01   1
#define    ISC00   0

/* Timer/Counter 0 Control Register */
#define    CS02    2
#define    CS01    1
#define    CS00    0

/* Watchdog Timer Control Register */
#define    WDTOE   4
#define    WDE     3
#define    WDP2    2
#define    WDP1    1
#define    WDP0    0

/* EEPROM Control Register */
#define    EEMWE   2
#define    EEWE    1
#define    EERE    0

/*
   PB2 = SCK/T0
   PB1 = MISO/INT0
   PB0 = MOSI
 */

/* Data Register, Port B */
#define    PB4     4
#define    PB3     3
#define    PB2     2
#define    PB1     1
#define    PB0     0

/* Data Direction Register, Port B */
#define    DDB4    4
#define    DDB3    3
#define    DDB2    2
#define    DDB1    1
#define    DDB0    0

/* Input Pins, Port B */
#define    PINB4   4
#define    PINB3   3
#define    PINB2   2
#define    PINB1   1
#define    PINB0   0

/* Pointer definition   */
#define    XL     r26
#define    XH     r27
#define    YL     r28
#define    YH     r29
#define    ZL     r30
#define    ZH     r31

/* Constants */
#define    RAMEND    0xDF
#define    XRAMEND   0xDF
#define    E2END     0x7F
#define    FLASHEND  0x07FF

#endif /* _AVR_IOTN22_H_ */
