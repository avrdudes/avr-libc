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

/* I/O registers */

/* ADC */
#define ADCW    _SFR_IO16(0x04)
#ifndef __ASSEMBLER__
#define ADC     _SFR_IO16(0x04)
#endif
#define ADCL    _SFR_IO8(0x04)
#define ADCH    _SFR_IO8(0x05)
#define ADCSR   _SFR_IO8(0x06)
#define ADMUX   _SFR_IO8(0x07)

/* Analog Comparator Control and Status Register */
#define ACSR    _SFR_IO8(0x08)

/* USI Control Register */
#define USICR  _SFR_IO8(0x0D)

/* USI Status Register */
#define USISR  _SFR_IO8(0x0E)

/* USI Data Register */
#define USIDR  _SFR_IO8(0x0F)

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

/* 0x1C..0x1E EEPROM */

/* Watchdog Timer Control Register */
#define WDTCR	_SFR_IO8(0x21)

/* PLL Control and Status Register */
#define PLLCSR  _SFR_IO8(0x29)

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

/* Oscillator Calibration Register */
#define OSCCAL  _SFR_IO8(0x31)

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

/* 0x3D SP */

/* 0x3F SREG */

/* Interrupt vectors */

#define SIG_INTERRUPT0		    _VECTOR(1)
#define SIG_PIN_CHANGE		    _VECTOR(2)
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
#define    PCIE1   5
#define    PCIE0   4

/* General Interrupt Flag Register */
#define    INTF0   6
#define    PCIF    5

/* Timer/Counter Interrupt MaSK register */
#define    OCIE1A  6
#define    OCIE1B  5
#define    TOIE1   2
#define    TOIE0   1

/* Timer/Counter Interrupt Flag register */
#define    OCF1A   6
#define    OCF1B   5
#define    TOV1    2
#define    TOV0    1

/* PLL Control and Status Register */
#define    PCKE    2
#define    PLLE    1
#define    PLOCK   0

/* MCU Status Register */
#define    WDRF    3
#define    BORF    2
#define    EXTRF   1
#define    PORF    0

/* MCU general Control Register */
#define    PUD     6
#define    SE      5
#define    SM1     4
#define    SM0     3
#define    ISC01   1
#define    ISC00   0

/* Timer/Counter 0 Control Register TCCR0 */
#define    PSR0    3
#define    CS02    2
#define    CS01    1
#define    CS00    0

/* Timer/Counter 1 Control Register TCCR1A */
#define    COM1A1  7
#define    COM1A0  6
#define    COM1B1  5
#define    COM1B0  4
#define    FOC1A   3
#define    FOC1B   2
#define    PWM1A   1
#define    PWM1B   0

/* Timer/Counter 1 Control Register TCCR1B */
#define    CTC1    7
#define    PSR1    6
#define    CS13    3
#define    CS12    2
#define    CS11    1
#define    CS10    0

/* USI Status Register USISR */
#define    USISIF  7
#define    USIOIF  6
#define    USIPF   5
#define    USIDC   4
#define    USICNT3 3
#define    USICNT2 2
#define    USICNT1 1
#define    USICNT0 0

/* USI Control Register USICR */
#define    USISIE  7
#define    USIOIE  6
#define    USIWM1  5
#define    USIWM0  4
#define    USICS1  3
#define    USICS0  2
#define    USICLK  1
#define    USITC   0

/* Watchdog Timer Control Register */
#define    WDTOE   4
#define    WDE     3
#define    WDP2    2
#define    WDP1    1
#define    WDP0    0

/* Analog Comparator control and Status Register */
#define ACD     7
#define ACBG    6
#define ACO     5
#define ACI     4
#define ACIE    3
#define ACME    2
#define ACIS1   1
#define ACIS0   0

/* ADMUX */
#define REFS1   7
#define REFS0   6
#define ADLAR   5
#define MUX4    4
#define MUX3    3
#define MUX2    2
#define MUX1    1
#define MUX0    0

/* ADCSR */
#define ADEN    7
#define ADSC    6
#define ADFR    5
#define ADIF    4
#define ADIE    3
#define ADPS2   2
#define ADPS1   1
#define ADPS0   0

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

/* Constants */
#define    RAMEND    0xDF
#define    XRAMEND   0xDF
#define    E2END     0x7F
#define    FLASHEND  0x07FF

#endif  /* _AVR_IOTN26_H_ */
