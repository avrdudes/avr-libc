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

/* avr/iotn15.h - definitions for ATtiny15 */

#ifndef _AVR_IOTN15_H_
#define _AVR_IOTN15_H_ 1

#ifndef __ASSEMBLER__
#  warning "MCU not supported by the C compiler"
#endif

/* I/O registers */

/* 0x00..0x03 reserved */

#define ADCW	_SFR_IO16(0x04)
#define ADCL	_SFR_IO8(0x04)
#define ADCH	_SFR_IO8(0x05)
#define ADCSR	_SFR_IO8(0x06)
#define ADMUX	_SFR_IO8(0x07)

/* Analog Comparator Control and Status Register */
#define ACSR	_SFR_IO8(0x08)

/* 0x09..0x15 reserved */

/* Input Pins, Port B */
#define PINB	_SFR_IO8(0x16)

/* Data Direction Register, Port B */
#define DDRB	_SFR_IO8(0x17)

/* Data Register, Port B */
#define PORTB	_SFR_IO8(0x18)

/* 0x19..0x1B reserved */

/* EEPROM Control Register */
#define EECR	_SFR_IO8(0x1C)

/* EEPROM Data Register */
#define EEDR	_SFR_IO8(0x1D)

/* EEPROM Address Register */
#define EEAR	_SFR_IO8(0x1E)
#define EEARL	_SFR_IO8(0x1E)

/* 0x1F..0x20 reserved */

/* Watchdog Timer Control Register */
#define WDTCR	_SFR_IO8(0x21)

/* 0x22..0x2B reserved */
#define SFIOR	_SFR_IO8(0x2C)

#define OCR1B	_SFR_IO8(0x2D)
#define OCR1A	_SFR_IO8(0x2E)
#define TCNT1	_SFR_IO8(0x2F)
#define TCCR1	_SFR_IO8(0x30)

/* Oscillator Calibration Register */
#define OSCCAL	_SFR_IO8(0x31)

/* Timer/Counter0 (8-bit) */
#define TCNT0	_SFR_IO8(0x32)

/* Timer/Counter0 Control Register */
#define TCCR0	_SFR_IO8(0x33)

/* MCU general Status Register */
#define MCUSR	_SFR_IO8(0x34)

/* MCU general Control Register */
#define MCUCR	_SFR_IO8(0x35)

/* 0x36..0x37 reserved */

/* Timer/Counter Interrupt Flag Register */
#define TIFR	_SFR_IO8(0x38)

/* Timer/Counter Interrupt MaSK Register */
#define TIMSK	_SFR_IO8(0x39)

/* General Interrupt Flag Register */
#define GIFR	_SFR_IO8(0x3A)

/* General Interrupt MaSK register */
#define GIMSK	_SFR_IO8(0x3B)

/* 0x3C..0x3E reserved */

/* Status REGister */
#define SREG	_SFR_IO8(0x3F)

/* Interrupt vectors */

#define SIG_INTERRUPT0		_VECTOR(1)
#define SIG_PIN			_VECTOR(2)
#define SIG_OUTPUT_COMPARE1A	_VECTOR(3)
#define SIG_OVERFLOW1		_VECTOR(4)
#define SIG_OVERFLOW0		_VECTOR(5)
#define SIG_EEPROM_READY	_VECTOR(6)
#define SIG_COMPARATOR		_VECTOR(7)
#define SIG_ADC			_VECTOR(8)

#define _VECTORS_SIZE 18

/* Bit numbers */

/* GIMSK */
#define INT0	6
#define PCIE	5

/* GIFR */
#define INTF0	6
#define PCIF	5

/* TIMSK */
#define OCIE1	6
#define TOIE1	2
#define TOIE0	1

/* TIFR */
#define OCF1	6
#define TOV1	2
#define TOV0	1

/* MCUCR */
#define PUD	6
#define SE	5
#define SM1	4
#define SM0	3
#define ISC01	1
#define ISC00	0

/* MCUSR */
#define WDRF	3
#define BORF	2
#define EXTRF	1
#define PORF	0

/* TCCR0 */
#define CS02	2
#define CS01	1
#define CS00	0

/* TCCR1 */
#define CTC1	7
#define PWM1	6
#define COM1A1	5
#define COM1A0	4
#define CS13	3
#define CS12	2
#define CS11	1
#define CS10	0

/* SFIOR */
#define FOC1A	2
#define PSR1	1
#define PSR0	0

/* WDTCR */
#define WDTOE	4
#define WDE	3
#define WDP2	2
#define WDP1	1
#define WDP0	0

/* EECR */
#define EERIE	3
#define EEMWE	2
#define EEWE	1
#define EERE	0

/*
   PB5 = RESET# / ADC0
   PB4 = ADC3
   PB3 = ADC2
   PB2 = SCK / ADC1 / T0 / INT0
   PB1 = MISO / AIN1 / OCP
   PB0 = MOSI / AIN0 / AREF
 */

/* PORTB */
#define PORTB4	4
#define PORTB3	3
#define PORTB2	2
#define PORTB1	1
#define PORTB0	0

/* DDRB */
#define DDB4	4
#define DDB3	3
#define DDB2	2
#define DDB1	1
#define DDB0	0

/* PINB */
#define PINB5	5
#define PINB4	4
#define PINB3	3
#define PINB2	2
#define PINB1	1
#define PINB0	0

/* ACSR */
#define ACD	7
#define GREF	6
#define ACO	5
#define ACI	4
#define ACIE	3
#define ACIS1	1
#define ACIS0	0

/* ADMUX */
#define REFS1	7
#define REFS0	6
#define ADLAR	5
#define MUX2	2
#define MUX1	1
#define MUX0	0

/* ADCSR */
#define ADEN	7
#define ADSC	6
#define ADFR	5
#define ADIF	4
#define ADIE	3
#define ADPS2	2
#define ADPS1	1
#define ADPS0	0

#define ZL r30
#define ZH r31

/* Last memory addresses */
#define RAMEND		0x1F
#define XRAMEND		0x0
#define E2END		0x3F
#define FLASHEND	0x3FF

#endif /* _AVR_IOTN15_H_ */
