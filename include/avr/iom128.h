/* Copyright (c) 2002, Peter Jansen
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

/* avr/iom128.h - defines for ATmega128 */

#ifndef _AVR_IOM128_H_
#define _AVR_IOM128_H_ 1

#include <avr/sfr_defs.h>

/* I/O registers */

/* Input Pins, Port F */
#define PINF      _SFR_IO8(0x00)

/* Input Pins, Port E */
#define PINE      _SFR_IO8(0x01)

/* Data Direction Register, Port E */
#define DDRE      _SFR_IO8(0x02)

/* Data Register, Port E */
#define PORTE     _SFR_IO8(0x03)

/* ADC Data Register */
#define ADCW	_SFR_IO16(0x04)
#define ADCL	_SFR_IO8(0x04)
#define ADCH	_SFR_IO8(0x05)

/* ADC Control and status register */
#define ADCSR     _SFR_IO8(0x06)

/* ADC Multiplexer select */
#define ADMUX     _SFR_IO8(0x07)

/* Analog Comparator Control and Status Register */
#define ACSR      _SFR_IO8(0x08)

/* USART0 Baud Rate Register Low */
#define UBRR0L    _SFR_IO8(0x09)

/* USART0 Control and Status Register B */
#define UCSR0B    _SFR_IO8(0x0A)

/* USART0 Control and Status Register A */
#define UCSR0A    _SFR_IO8(0x0B)

/* USART I/O Data Register */
#define UDR0      _SFR_IO8(0x0C)

/* SPI Control Register */
#define SPCR      _SFR_IO8(0x0D)

/* SPI Status Register */
#define SPSR      _SFR_IO8(0x0E)

/* SPI I/O Data Register */
#define SPDR      _SFR_IO8(0x0F)

/* Input Pins, Port D */
#define PIND      _SFR_IO8(0x10)

/* Data Direction Register, Port D */
#define DDRD      _SFR_IO8(0x11)

/* Data Register, Port D */
#define PORTD     _SFR_IO8(0x12)

/* Input Pins, Port C */
#define PINC	  _SFR_IO8(0x13)

/* Data Direction Register, Port C */
#define DDRC	  _SFR_IO8(0x14)

/* Data Register, Port C */
#define PORTC     _SFR_IO8(0x15)

/* Input Pins, Port B */
#define PINB      _SFR_IO8(0x16)

/* Data Direction Register, Port B */
#define DDRB      _SFR_IO8(0x17)

/* Data Register, Port B */
#define PORTB     _SFR_IO8(0x18)

/* Input Pins, Port A */
#define PINA      _SFR_IO8(0x19)

/* Data Direction Register, Port A */
#define DDRA      _SFR_IO8(0x1A)

/* Data Register, Port A */
#define PORTA     _SFR_IO8(0x1B)

/* EEPROM Control Register */
#define EECR      _SFR_IO8(0x1C)

/* EEPROM Data Register */
#define EEDR      _SFR_IO8(0x1D)

/* EEPROM Address Register */
#define EEAR	_SFR_IO16(0x1E)
#define EEARL     _SFR_IO8(0x1E)
#define EEARH     _SFR_IO8(0x1F)

/* Special Function I/O Register */
#define SFIOR     _SFR_IO8(0x20)

/* Watchdog Timer Control Register */
#define WDTCR     _SFR_IO8(0x21)

/* On-chip Debug Register */
#define OCDR	  _SFR_IO8(0x22)

/* Timer2 Output Compare Register */
#define OCR2      _SFR_IO8(0x23)

/* Timer/Counter 2 */
#define TCNT2     _SFR_IO8(0x24)

/* Timer/Counter 2 Control register */
#define TCCR2     _SFR_IO8(0x25)

/* T/C 1 Input Capture Register */
#define ICR1	_SFR_IO16(0x26)
#define ICR1L     _SFR_IO8(0x26)
#define ICR1H     _SFR_IO8(0x27)

/* Timer/Counter1 Output Compare Register B */
#define OCR1B	_SFR_IO16(0x28)
#define OCR1BL    _SFR_IO8(0x28)
#define OCR1BH    _SFR_IO8(0x29)

/* Timer/Counter1 Output Compare Register A */
#define OCR1A	_SFR_IO16(0x2A)
#define OCR1AL    _SFR_IO8(0x2A)
#define OCR1AH    _SFR_IO8(0x2B)

/* Timer/Counter 1 */
#define TCNT1	_SFR_IO16(0x2C)
#define TCNT1L    _SFR_IO8(0x2C)
#define TCNT1H    _SFR_IO8(0x2D)

/* Timer/Counter 1 Control and Status Register */
#define TCCR1B    _SFR_IO8(0x2E)

/* Timer/Counter 1 Control Register */
#define TCCR1A    _SFR_IO8(0x2F)

/* Timer/Counter 0 Asynchronous Control & Status Register */
#define ASSR      _SFR_IO8(0x30)

/* Output Compare Register 0 */
#define OCR0      _SFR_IO8(0x31)

/* Timer/Counter 0 */
#define TCNT0     _SFR_IO8(0x32)

/* Timer/Counter 0 Control Register */
#define TCCR0     _SFR_IO8(0x33)

/* MCU Status Register */
#define MCUSR     _SFR_IO8(0x34)

/* MCU general Control Register */
#define MCUCR     _SFR_IO8(0x35)

/* Timer/Counter Interrupt Flag Register */
#define TIFR      _SFR_IO8(0x36)

/* Timer/Counter Interrupt MaSK register */
#define TIMSK     _SFR_IO8(0x37)

/* External Interrupt Flag Register */
#define EIFR      _SFR_IO8(0x38)

/* External Interrupt MaSK register */
#define EIMSK     _SFR_IO8(0x39)

/* External Interrupt Control Register B */
#define EICRB     _SFR_IO8(0x3A)

/* RAM Page Z select register */
#define RAMPZ     _SFR_IO8(0x3B)

/* XDIV Divide control register */
#define XDIV      _SFR_IO8(0x3C)

/* Stack Pointer */
#define SP	_SFR_IO16(0x3D)
#define SPL	_SFR_IO8(0x3D)
#define SPH	_SFR_IO8(0x3E)

/* Status REGister */
#define SREG      _SFR_IO8(0x3F)

/* Extended I/O registers */

/* Data Direction Register, Port F */
#define DDRF      _SFR_MEM8(0x61)

/* Data Register, Port F */
#define PORTF	  _SFR_MEM8(0x62)

/* Input Pins, Port G */
#define PING      _SFR_MEM8(0x63)

/* Data Direction Register, Port G */
#define DDRG      _SFR_MEM8(0x64)

/* Data Register, Port G */
#define PORTG	  _SFR_MEM8(0x65)

/* Store Program Memory Control Register */
#define SPMCR	  _SFR_MEM8(0x68)

/* External Interrupt Control Register A */
#define EICRA	  _SFR_MEM8(0x6A)

/* External Memory Control Register B */
#define XMCRB	  _SFR_MEM8(0x6C)

/* External Memory Control Register A */
#define XMCRA	  _SFR_MEM8(0x6D)

/* Oscillator Calibration Register */
#define OSCCAL	  _SFR_MEM8(0x6F)

/* 2-wire Serial Interface Bit Rate Register */
#define TWBR	  _SFR_MEM8(0x70)

/* 2-wire Serial Interface Status Register */
#define TWSR	  _SFR_MEM8(0x71)

/* 2-wire Serial Interface Address Register */
#define TWAR	  _SFR_MEM8(0x72)

/* 2-wire Serial Interface Data Register */
#define TWDR	  _SFR_MEM8(0x73)

/* 2-wire Serial Interface Control Register */
#define TWCR	  _SFR_MEM8(0x74)

/* Time Counter 1 Output Compare Register C */
#define OCR1C	_SFR_MEM16(0x78)
#define OCR1CL	  _SFR_MEM8(0x78)
#define OCR1CH	  _SFR_MEM8(0x79)

/* Timer/Counter 1 Control Register C */
#define TCCR1C	  _SFR_MEM8(0x7A)

/* Extended Timer Interrupt Flag Register */
#define ETIFR	  _SFR_MEM8(0x7C)

/* Extended Timer Interrupt Mask Register */
#define ETIMSK	  _SFR_MEM8(0x7D)

/* Timer/Counter 3 Input Capture Register */
#define ICR3	_SFR_MEM16(0x80)
#define ICR3L	  _SFR_MEM8(0x80)
#define ICR3H	  _SFR_MEM8(0x81)

/* Timer/Counter 3 Output Compare Register C */
#define OCR3C	_SFR_MEM16(0x82)
#define OCR3CL	  _SFR_MEM8(0x82)
#define OCR3CH	  _SFR_MEM8(0x83)

/* Timer/Counter 3 Output Compare Register B */
#define OCR3B	_SFR_MEM16(0x84)
#define OCR3BL	  _SFR_MEM8(0x84)
#define OCR3BH	  _SFR_MEM8(0x85)

/* Timer/Counter 3 Output Compare Register A */
#define OCR3A	_SFR_MEM16(0x86)
#define OCR3AL	  _SFR_MEM8(0x86)
#define OCR3AH	  _SFR_MEM8(0x87)

/* Timer/Counter 3 Counter Register */
#define TCNT3	_SFR_MEM16(0x88)
#define TCNT3L	  _SFR_MEM8(0x88)
#define TCNT3H	  _SFR_MEM8(0x89)

/* Timer/Counter 3 Control Register B */
#define TCCR3B	  _SFR_MEM8(0x8A)

/* Timer/Counter 3 Control Register A */
#define TCCR3A	  _SFR_MEM8(0x8B)

/* Timer/Counter 3 Control Register C */
#define TCCR3C	  _SFR_MEM8(0x8C)

/* USART0 Baud Rate Register High */
#define UBRR0H    _SFR_MEM8(0x90)

/* USART0 Control and Status Register C */
#define UCSR0C	  _SFR_MEM8(0x95)

/* USART1 Baud Rate Register High */
#define UBRR1H	  _SFR_MEM8(0x98)

/* USART1 Baud Rate Register Low*/
#define UBRR1L	  _SFR_MEM8(0x99)

/* USART1 Control and Status Register B */
#define UCSR1B	  _SFR_MEM8(0x9A)

/* USART1 Control and Status Register A */
#define UCSR1A	  _SFR_MEM8(0x9B)

/* USART1 I/O Data Register */
#define UDR1	  _SFR_MEM8(0x9C)

/* USART1 Control and Status Register C */
#define UCSR1C	  _SFR_MEM8(0x9D)


/* Interrupt vectors */

#define SIG_INTERRUPT0		_VECTOR(1)
#define SIG_INTERRUPT1		_VECTOR(2)
#define SIG_INTERRUPT2		_VECTOR(3)
#define SIG_INTERRUPT3		_VECTOR(4)
#define SIG_INTERRUPT4		_VECTOR(5)
#define SIG_INTERRUPT5		_VECTOR(6)
#define SIG_INTERRUPT6		_VECTOR(7)
#define SIG_INTERRUPT7		_VECTOR(8)
#define SIG_OUTPUT_COMPARE2	_VECTOR(9)
#define SIG_OVERFLOW2		_VECTOR(10)
#define SIG_INPUT_CAPTURE1	_VECTOR(11)
#define SIG_OUTPUT_COMPARE1A	_VECTOR(12)
#define SIG_OUTPUT_COMPARE1B	_VECTOR(13)
#define SIG_OVERFLOW1		_VECTOR(14)
#define SIG_OUTPUT_COMPARE0	_VECTOR(15)
#define SIG_OVERFLOW0		_VECTOR(16)
#define SIG_SPI			_VECTOR(17)
#define SIG_UART0_RECV		_VECTOR(18)
#define SIG_UART0_DATA		_VECTOR(19)
#define SIG_UART0_TRANS		_VECTOR(20)
#define SIG_ADC			_VECTOR(21)
#define SIG_EEPROM_READY	_VECTOR(22)
#define SIG_COMPARATOR		_VECTOR(23)
#define SIG_OUTPUT_COMPARE1C	_VECTOR(24)
#define SIG_INPUT_CAPTURE3	_VECTOR(25)
#define SIG_OUTPUT_COMPARE3A	_VECTOR(26)
#define SIG_OUTPUT_COMPARE3B	_VECTOR(27)
#define SIG_OUTPUT_COMPARE3C	_VECTOR(28)
#define SIG_OVERFLOW3		_VECTOR(29)
#define SIG_UART1_RECV		_VECTOR(30)
#define SIG_UART1_DATA		_VECTOR(31)
#define SIG_UART1_TRANS		_VECTOR(32)
#define SIG_2WIRE_SERIAL	_VECTOR(33)
#define SIG_SPM_READY		_VECTOR(34)

#define _VECTORS_SIZE 140

/*
   The Register Bit names are represented by their bit number (0-7).
*/

/* 2-wire Control Register */
#define    TWINT        7
#define    TWEA         6
#define    TWSTA        5
#define    TWSTO        4
#define    TWWC         3
#define    TWEN         2
#define    TWIE         0

/* 2-wire Address Register */
#define    TWA6         7
#define    TWA5         6
#define    TWA4         5
#define    TWA3         4
#define    TWA2         3
#define    TWA1         2
#define    TWA0         1
#define    TWGCE        0

/* 2-wire Status Register */
#define    TWS7         7
#define    TWS6         6
#define    TWS5         5
#define    TWS4         4
#define    TWS3         3
#define    TWPS1        1
#define    TWPS0        0

/* External Memory Control Register A */
#define    SRL2         6
#define    SRL1         5
#define    SRL0         4
#define    SRW01        3
#define    SRW00        2
#define    SRW11        1

/* External Memory Control Register B */
#define    XMBK         7
#define    XMM2         2
#define    XMM1         1
#define    XMM0         0

/* XDIV Divide control register*/
#define    XDIVEN       7
#define    XDIV6        6
#define    XDIV5        5
#define    XDIV4        4
#define    XDIV3        3
#define    XDIV2        2
#define    XDIV1        1
#define    XDIV0        0

/* RAM Page Z select register */
#define     RAMPZ0      0

/* External Interrupt Control Register A */
#define    ISC31        7
#define    ISC30        6
#define    ISC21        5
#define    ISC20        4
#define    ISC11        3
#define    ISC10        2
#define    ISC01        1
#define    ISC00        0

/* External Interrupt Control Register B */
#define    ISC71        7
#define    ISC70        6
#define    ISC61        5
#define    ISC60        4
#define    ISC51        3
#define    ISC50        2
#define    ISC41        1
#define    ISC40        0

/* Store Program Memory Control Register */
#define    SPMIE        7
#define    RWWSB        6
#define    RWWSRE       4
#define    BLBSET       3
#define    PGWRT        2
#define    PGERS        1
#define    SPMEN        0

/* External Interrupt MaSK register */
#define    INT7         7
#define    INT6         6
#define    INT5         5
#define    INT4         4
#define    INT3         3
#define    INT2         2
#define    INT1         1
#define    INT0         0

/* External Interrupt Flag Register */
#define    INTF7        7
#define    INTF6        6
#define    INTF5        5
#define    INTF4        4

/* Timer/Counter Interrupt MaSK register */
#define    OCIE2        7
#define    TOIE2        6
#define    TICIE1       5
#define    OCIE1A       4
#define    OCIE1B       3
#define    TOIE1        2
#define    OCIE0        1
#define    TOIE0        0

/* Timer/Counter Interrupt Flag Register */
#define    OCF2         7
#define    TOV2         6
#define    ICF1         5
#define    OCF1A        4
#define    OCF1B        3
#define    TOV1         2
#define    OCF0         1
#define    TOV0         0

/* Extended Timer Interrupt MaSK register */
#define    TICIE3       5
#define    OCIE3A       4
#define    OCIE3B       3
#define    TOIE3        2
#define    OCIE3C       1
#define    OCIE1C       0

/* Extended Timer Interrupt Flag Register */
#define    ICF3         5
#define    OCF3A        4
#define    OCF3B        3
#define    TOV3         2
#define    OCF3C        1
#define    OCF1C        0

/* MCU general Control Register */
#define    SRE          7
#define    SRW          6
#define    SE           5
#define    SM1          4
#define    SM0          3
#define    SM2          2
#define    IVSEL        1
#define    IVCE         0

/* MCU Status Register */
#define    JTD          7
#define    JTRF         4
#define    WDRF         3
#define    BORF         2
#define    EXTRF        1
#define    PORF         0

/* Timer/Counter Control Register */
#define    FOC          7
#define    WGM0         6
#define    COM1         5
#define    COM0         4
#define    WGM1         3
#define    CS2          2
#define    CS1          1
#define    CS0          0

/* Timer/Counter 0 Asynchronous Control & Status Register */
#define    AS0          3
#define    TCN0UB       2
#define    OCR0UB       1
#define    TCR0UB       0

/* Timer/Counter Control Register A */
#define    COMA1        7
#define    COMA0        6
#define    COMB1        5
#define    COMB0        4
#define    COMC1        3
#define    COMC0        2
#define    WGMA1        1
#define    WGMA0        0

/* Timer/Counter Control and Status Register B */
#define    ICNC         7
#define    ICES         6
#define    WGMB3        4
#define    WGMB2        3
#define    CSB2         2
#define    CSB1         1
#define    CSB0         0

/* Timer/Counter Control Register C */
#define    FOCA         7
#define    FOCB         6
#define    FOCC         5

/* On-chip Debug Register */
#define    OCDR7        7
#define    OCDR6        6
#define    OCDR5        5
#define    OCDR4        4
#define    OCDR3        3
#define    OCDR2        2
#define    OCDR1        1
#define    OCDR0        0

/* Watchdog Timer Control Register */
#define    WDCE         4
#define    WDE          3
#define    WDP2         2
#define    WDP1         1
#define    WDP0         0

/* Special Function I/O Register */
#define    TSM          7
#define    ADHSM        4
#define    ACME         3
#define    PUD          2
#define    PSR0         1
#define    PSR321       0

/* EEPROM Control Register */
#define    EERIE        3
#define    EEMWE        2
#define    EEWE         1
#define    EERE         0

/* Port Data Register */
#define    PORT7        7
#define    PORT6        6
#define    PORT5        5
#define    PORT4        4
#define    PORT3        3
#define    PORT2        2
#define    PORT1        1
#define    PORT0        0

/* Port Data Direction Register */
#define    DD7          7
#define    DD6          6
#define    DD5          5
#define    DD4          4
#define    DD3          3
#define    DD2          2
#define    DD1          1
#define    DD0          0

/* Port Input Pins */
#define    PIN7         7
#define    PIN6         6
#define    PIN5         5
#define    PIN4         4
#define    PIN3         3
#define    PIN2         2
#define    PIN1         1
#define    PIN0         0

/* Status Register */
#define    SREG_I       7
#define    SREG_T       6
#define    SREG_H       5
#define    SREG_S       4
#define    SREG_V       3
#define    SREG_N       2
#define    SREG_Z       1
#define    SREG_C       0

/* SPI Status Register */
#define    SPIF         7
#define    WCOL         6
#define    SPI2X        0

/* SPI Control Register */
#define    SPIE         7
#define    SPE          6
#define    DORD         5
#define    MSTR         4
#define    CPOL         3
#define    CPHA         2
#define    SPR1         1
#define    SPR0         0

/* USART Register C */
#define    UMSEL        6
#define    UPM1         5
#define    UPM0         4
#define    USBS         3
#define    UCSZ1        2
#define    UCSZ0        1
#define    UCPOL        0

/* USART Status Register A */
#define    RXC          7
#define    TXC          6
#define    UDRE         5
#define    FE           4
#define    DOR          3
#define    UPE          2
#define    U2X          1
#define    MPCM         0

/* USART Control Register B */
#define    RXCIE        7
#define    TXCIE        6
#define    UDRIE        5
#define    RXEN         4
#define    TXEN         3
#define    UCSZ         2
#define    RXB8         1
#define    TXB8         0

/* Analog Comparator Control and Status Register */
#define    ACD          7
#define    ACBG         6
#define    ACO          5
#define    ACI          4
#define    ACIE         3
#define    ACIC         2
#define    ACIS1        1
#define    ACIS0        0

/* ADC Control and status register */
#define    ADEN         7
#define    ADSC         6
#define    ADFR         5
#define    ADIF         4
#define    ADIE         3
#define    ADPS2        2
#define    ADPS1        1
#define    ADPS0        0

/* ADC Multiplexer select */
#define    REFS1        7
#define    REFS0        6
#define    ADLAR        5
#define    MUX4         4
#define    MUX3         3
#define    MUX2         2
#define    MUX1         1
#define    MUX0         0

/* Pointer definition */
#define    XL       r26
#define    XH       r27
#define    YL       r28
#define    YH       r29
#define    ZL       r30
#define    ZH       r31

/* Constants */
#define    RAMEND   0x10FF     /* Last On-Chip SRAM Location */
#define    XRAMEND  0xFFFF
#define    E2END    0x0FFF
#define    FLASHEND 0x1FFFF

#endif /* _AVR_IOM128_H_ */
