/* Copyright (c) 2002, Stefan Swanepoel
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

/* $Id$ */

/* avr/iotn26.h - definitions for ATtiny26 */

/* This file should only be included from <avr/io.h>, never directly. */

#ifndef _AVR_IO_H_
#  error "Include <avr/io.h> instead of this file."
#endif

#ifndef _AVR_IOXXX_H_
#  define _AVR_IOXXX_H_ "iotn26.h"
#else
#  error "Attempt to include more than one <avr/ioXXX.h> file."
#endif 

#ifndef _AVR_IOTN26_H_
#define _AVR_IOTN26_H_ 1

#include <avr/sfr_defs.h>

/* I/O registers */

/* Input Pins, Port A */
#define PINA	_SFR_IO8(0x19)

/* Data Direction Register, Port A */
#define DDRA	_SFR_IO8(0x1A)

/* Data Register, Port A */
#define PORTA	_SFR_IO8(0x1B)

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

/* Timer/Counter 1 Control Register A */
#define TCCR1A _SFR_IO8(0x30)

/* Timer/Counter 1 Control Register A */
#define TCCR1B _SFR_IO8(0x2F)

/* Timer/Counter 1 */
#define TCNT1 _SFR_IO8(0x2E)

/* Timer/Counter 1 Output Compare Register A */
#define OCR1A	_SFR_IO8(0x2D)

/* Timer/Counter 1 Output Compare Register B */
#define OCR1B	_SFR_IO8(0x2C)

/* Timer/Counter 1 Output Compare Register C */
#define OCR1C	_SFR_IO8(0x2B)

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

#define SIG_INTERRUPT0		    _VECTOR(1)
#define SIG_INTERRUPT1		    _VECTOR(2)
#define SIG_OUTPUT_COMPARE1A  _VECTOR(3)
#define SIG_OUTPUT_COMPARE1B  _VECTOR(4)
#define SIG_OVERFLOW1	        _VECTOR(5)
#define SIG_OVERFLOW0	        _VECTOR(6)
#define SIG_USI_START	        _VECTOR(7)
#define SIG_USI_OVERFLOW      _VECTOR(8)
#define SIG_EPROM_READY	      _VECTOR(9)
#define SIG_ANA_COMP          _VECTOR(10)
#define SIG_ADC     		      _VECTOR(11)

#define _VECTORS_SIZE 24

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

/* Data Register, Port A */
#define    PA7     7
#define    PA6     6
#define    PA5     5
#define    PA4     4
#define    PA3     3
#define    PA2     2
#define    PA1     1
#define    PA0     0

/* Data Direction Register, Port A */
#define    DDA7    7
#define    DDA6    6
#define    DDA5    5
#define    DDA4    4
#define    DDA3    3
#define    DDA2    2
#define    DDA1    1
#define    DDA0    0

/* Input Pins, Port A */
#define    PINA7   7
#define    PINA6   6
#define    PINA5   5
#define    PINA4   4
#define    PINA3   3
#define    PINA2   2
#define    PINA1   1
#define    PINA0   0

/* Data Register, Port B */
#define    PB7     7
#define    PB6     6
#define    PB5     5
#define    PB4     4
#define    PB3     3
#define    PB2     2
#define    PB1     1
#define    PB0     0

/* Data Direction Register, Port B */
#define    DDB7    7
#define    DDB6    6
#define    DDB5    5
#define    DDB4    4
#define    DDB3    3
#define    DDB2    2
#define    DDB1    1
#define    DDB0    0

/* Input Pins, Port B */
#define    PINB7   7
#define    PINB6   6
#define    PINB5   5
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

#endif  /* _AVR_IOTN26_H_ */
