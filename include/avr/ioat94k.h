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

/* $Id$ */

/* avr/ioat94k.h - definitions for AT94K series FPSLIC(tm) */

#ifndef _AVR_IOAT94K_H_
#define _AVR_IOAT94K_H_ 1

/* This file should only be included from <avr/io.h>, never directly. */

#ifndef _AVR_IO_H_
#  error "Include <avr/io.h> instead of this file."
#endif

#ifndef _AVR_IOXXX_H_
#  define _AVR_IOXXX_H_ "ioat94k.h"
#else
#  error "Attempt to include more than one <avr/ioXXX.h> file."
#endif 

#include <avr/sfr_defs.h>

/* I/O registers */

/* UART1 Baud Rate Register */
#define UBRR1	_SFR_IO8(0x00)

/* UART1 Control and Status Registers */
#define UCSR1B	_SFR_IO8(0x01)
#define UCSR1A	_SFR_IO8(0x02)

/* UART1 I/O Data Register */
#define UDR1	_SFR_IO8(0x03)

/* 0x04 reserved */

/* Input Pins, Port E */
#define PINE	_SFR_IO8(0x05)

/* Data Direction Register, Port E */
#define DDRE	_SFR_IO8(0x06)

/* Data Register, Port E */
#define PORTE	_SFR_IO8(0x07)

/* 0x08 reserved */

/* UART0 Baud Rate Register */
#define UBRR0	_SFR_IO8(0x09)

/* UART0 Control and Status Registers */
#define UCSR0B	_SFR_IO8(0x0A)
#define UCSR0A	_SFR_IO8(0x0B)

/* UART0 I/O Data Register */
#define UDR0	_SFR_IO8(0x0C)

/* 0x0D..0x0F reserved */

/* Input Pins, Port D */
#define PIND	_SFR_IO8(0x10)

/* Data Direction Register, Port D */
#define DDRD	_SFR_IO8(0x11)

/* Data Register, Port D */
#define PORTD	_SFR_IO8(0x12)

/* FPGA I/O Select Control Register */
#define FISCR	_SFR_IO8(0x13)

/* FPGA I/O Select Registers A, B, C, D */
#define FISUA	_SFR_IO8(0x14)
#define FISUB	_SFR_IO8(0x15)
#define FISUC	_SFR_IO8(0x16)
#define FISUD	_SFR_IO8(0x17)

/* FPGA Cache Logic(R) registers (top secret, under NDA) */
#define FPGAX	_SFR_IO8(0x18)
#define FPGAY	_SFR_IO8(0x19)
#define FPGAZ	_SFR_IO8(0x1A)
#define FPGAD	_SFR_IO8(0x1B)

/* TWI stands for "Two Wire Interface" or "TWI Was I2C(tm)" */

/* 2-wire Serial Bit Rate Register */
#define TWBR	_SFR_IO8(0x1C)

/* 2-wire Serial Status Register */
#define TWSR	_SFR_IO8(0x1D)

/* 2-wire Serial (Slave) Address Register */
#define TWAR	_SFR_IO8(0x1E)

/* 2-wire Serial Data Register */
#define TWDR	_SFR_IO8(0x1F)

/* UART Baud Register High */
#define UBRRH	_SFR_IO8(0x20)

/* Watchdog Timer Control Register */
#define WDTCR	_SFR_IO8(0x21)

/* Timer/Counter2 Output Compare Register */
#define OCR2	_SFR_IO8(0x22)

/* Timer/Counter2 (8-bit) */
#define TCNT2	_SFR_IO8(0x23)

/* Timer/Counter1 Input Capture Register */
#define ICR1	_SFR_IO16(0x24)
#define ICR1L	_SFR_IO8(0x24)
#define ICR1H	_SFR_IO8(0x25)

/* Asynchronous mode StatuS Register */
#define ASSR	_SFR_IO8(0x26)

/* Timer/Counter2 Control Register */
#define TCCR2	_SFR_IO8(0x27)

/* Timer/Counter1 Output Compare RegisterB */
#define OCR1B	_SFR_IO16(0x28)
#define OCR1BL	_SFR_IO8(0x28)
#define OCR1BH	_SFR_IO8(0x29)

/* Timer/Counter1 Output Compare RegisterA */
#define OCR1A	_SFR_IO16(0x2A)
#define OCR1AL	_SFR_IO8(0x2A)
#define OCR1AH	_SFR_IO8(0x2B)

/* Timer/Counter1 */
#define TCNT1	_SFR_IO16(0x2C)
#define TCNT1L	_SFR_IO8(0x2C)
#define TCNT1H	_SFR_IO8(0x2D)

/* Timer/Counter1 Control Register B */
#define TCCR1B	_SFR_IO8(0x2E)

/* Timer/Counter1 Control Register A */
#define TCCR1A	_SFR_IO8(0x2F)

/* Special Function IO Register */
#define SFIOR	_SFR_IO8(0x30)

/* Timer/Counter0 Output Compare Register */
#define OCR0	_SFR_IO8(0x31)

/* Timer/Counter0 (8-bit) */
#define TCNT0	_SFR_IO8(0x32)

/* Timer/Counter0 Control Register */
#define TCCR0	_SFR_IO8(0x33)

/* 0x34 reserved */

/* MCU Control/Status Register */
#define MCUR	_SFR_IO8(0x35)

/* 2-wire Serial Control Register */
#define TWCR	_SFR_IO8(0x36)

/* 0x37 reserved */

/* Timer/Counter Interrupt Flag Register */
#define TIFR	_SFR_IO8(0x38)

/* Timer/Counter Interrupt MaSK Register */
#define TIMSK	_SFR_IO8(0x39)

/* Software Control Register */
#define SFTCR	_SFR_IO8(0x3A)

/* External Interrupt Mask/Flag Register */
#define EIMF	_SFR_IO8(0x3B)

/* 0x3C reserved */

/* Stack Pointer */
#define SPL	_SFR_IO8(0x3D)
#define SPH	_SFR_IO8(0x3E)

/* Status REGister */
#define SREG	_SFR_IO8(0x3F)


/* Interrupt vectors */

#define SIG_INTERRUPT0		_VECTOR(1)
#define SIG_FPGA_INTERRUPT0	_VECTOR(2)
#define SIG_INTERRUPT1		_VECTOR(3)
#define SIG_FPGA_INTERRUPT1	_VECTOR(4)
#define SIG_INTERRUPT2		_VECTOR(5)
#define SIG_FPGA_INTERRUPT2	_VECTOR(6)
#define SIG_INTERRUPT3		_VECTOR(7)
#define SIG_FPGA_INTERRUPT3	_VECTOR(8)
#define SIG_OUTPUT_COMPARE2	_VECTOR(9)
#define SIG_OVERFLOW2		_VECTOR(10)
#define SIG_INPUT_CAPTURE1	_VECTOR(11)
#define SIG_OUTPUT_COMPARE1A	_VECTOR(12)
#define SIG_OUTPUT_COMPARE1B	_VECTOR(13)
#define SIG_OVERFLOW1		_VECTOR(14)
#define SIG_OUTPUT_COMPARE0	_VECTOR(15)
#define SIG_OVERFLOW0		_VECTOR(16)
#define SIG_FPGA_INTERRUPT4	_VECTOR(17)
#define SIG_FPGA_INTERRUPT5	_VECTOR(18)
#define SIG_FPGA_INTERRUPT6	_VECTOR(19)
#define SIG_FPGA_INTERRUPT7	_VECTOR(20)
#define SIG_UART0_RECV		_VECTOR(21)
#define SIG_UART0_DATA		_VECTOR(22)
#define SIG_UART0_TRANS		_VECTOR(23)
#define SIG_FPGA_INTERRUPT8	_VECTOR(24)
#define SIG_FPGA_INTERRUPT9	_VECTOR(25)
#define SIG_FPGA_INTERRUPT10	_VECTOR(26)
#define SIG_FPGA_INTERRUPT11	_VECTOR(27)
#define SIG_UART1_RECV		_VECTOR(28)
#define SIG_UART1_DATA		_VECTOR(29)
#define SIG_UART1_TRANS		_VECTOR(30)
#define SIG_FPGA_INTERRUPT12	_VECTOR(31)
#define SIG_FPGA_INTERRUPT13	_VECTOR(32)
#define SIG_FPGA_INTERRUPT14	_VECTOR(33)
#define SIG_FPGA_INTERRUPT15	_VECTOR(34)
#define SIG_2WIRE_SERIAL	_VECTOR(35)

#define _VECTORS_SIZE 144

/* Bit numbers - XXX not here yet */

/* Pointer registers (same for all AVR devices so far) */
#define XL r26
#define XH r27
#define YL r28
#define YH r29
#define ZL r30
#define ZH r31

/*
   Last memory addresses - depending on configuration, it is possible
   to have 20K-32K of program memory and 4K-16K of data memory
   (all in the same 36K total of SRAM, loaded from external EEPROM).
 */

#ifndef RAMEND
#define RAMEND 0x0FFF
#endif

#define E2END 0

#ifndef FLASHEND
#define FLASHEND 0x7FFF
#endif

#endif /* _AVR_IOAT94K_H_ */
