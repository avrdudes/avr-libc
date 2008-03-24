/* Copyright (c) 2007, 2008 Atmel Corporation
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.

   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.

   * Neither the name of the copyright holders nor the names of
     contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.

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

#ifndef _AVR_ATxmega128A1_H_
#define _AVR_ATxmega128A1_H_ 1


/* This file should only be included from <avr/io.h>, never directly. */

#ifndef _AVR_IO_H_
#  error "Include <avr/io.h> instead of this file."
#endif

#ifndef _AVR_IOXXX_H_
#  define _AVR_IOXXX_H_ "iox128a1.h"
#else
#  error "Attempt to include more than one <avr/ioXXX.h> file."
#endif 


/* Ungrouped common registers */
#define GPIO0   _SFR_MEM8(0x00)     // General Purpose IO Register 0
#define GPIO1   _SFR_MEM8(0x01)     // General Purpose IO Register 1
#define GPIO2   _SFR_MEM8(0x02)     // General Purpose IO Register 2
#define GPIO3   _SFR_MEM8(0x03)     // General Purpose IO Register 3
#define GPIO4   _SFR_MEM8(0x04)     // General Purpose IO Register 4
#define GPIO5   _SFR_MEM8(0x05)     // General Purpose IO Register 5
#define GPIO6   _SFR_MEM8(0x06)     // General Purpose IO Register 6
#define GPIO7   _SFR_MEM8(0x07)     // General Purpose IO Register 7
#define GPIO8   _SFR_MEM8(0x08)     // General Purpose IO Register 8
#define GPIO9   _SFR_MEM8(0x09)     // General Purpose IO Register 9
#define GPIOA   _SFR_MEM8(0x0A)     // General Purpose IO Register 10
#define GPIOB   _SFR_MEM8(0x0B)     // General Purpose IO Register 11
#define GPIOC   _SFR_MEM8(0x0C)     // General Purpose IO Register 12
#define GPIOD   _SFR_MEM8(0x0D)     // General Purpose IO Register 13
#define GPIOE   _SFR_MEM8(0x0E)     // General Purpose IO Register 14
#define GPIOF   _SFR_MEM8(0x0F)     // General Purpose IO Register 15

#define CCP     _SFR_MEM8(0x34)      // Configuration Change Protection
#define RAMPD   _SFR_MEM8(0x38)      // Ramp D
#define RAMPX   _SFR_MEM8(0x39)      // Ramp X
#define RAMPY   _SFR_MEM8(0x3A)      // Ramp Y
#define RAMPZ   _SFR_MEM8(0x3B)      // Ramp Z
#define EIND    _SFR_MEM8(0x3C)      // Extended Indirect Jump
#define SPL     _SFR_MEM8(0x3D)      // Stack Pointer Low
#define SPH     _SFR_MEM8(0x3E)      // Stack Pointer High
#define SP      _SFR_MEM16(0x3D)     // 16-bit Stack Pointer
#define SREG    _SFR_MEM8(0x3F)      // Status Register



/* C Language Only */
#if !defined (__ASSEMBLER__)


#include <stdint.h>

typedef volatile uint8_t register8_t;
typedef volatile uint16_t register16_t;
typedef volatile uint32_t register32_t;


#ifdef _WORDREGISTER
#undef _WORDREGISTER
#endif
#define _WORDREGISTER(regname)   \
    union \
    { \
        register16_t regname; \
        struct \
        { \
            register8_t regname ## L; \
            register8_t regname ## H; \
        }; \
    }

#ifdef _DWORDREGISTER
#undef _DWORDREGISTER
#endif
#define _DWORDREGISTER(regname)  \
    union \
    { \
        register32_t regname; \
        struct \
        { \
            register8_t regname ## 0; \
            register8_t regname ## 1; \
            register8_t regname ## 2; \
            register8_t regname ## 3; \
        }; \
    }



/*
==========================================================================
IO Module Structures
==========================================================================
*/


/*
--------------------------------------------------------------------------
XOCD - On-Chip Debug System
--------------------------------------------------------------------------
*/

/* On-Chip Debug System */
typedef struct OCD_struct
{
    register8_t OCDR0; /* OCD Register 0 */
    register8_t OCDR1; /* OCD Register 1 */
} OCD_t;

/*
--------------------------------------------------------------------------
CLK - Clock System
--------------------------------------------------------------------------
*/

/* Clock System */
typedef struct CLK_struct
{
    register8_t CTRL; /* Control Register */
    register8_t PSCTRL; /* Prescaler Control Register */
    register8_t LOCK; /* Lock register */
    register8_t RTCCTRL; /* RTC Control Register */
} CLK_t;

/* Power Reduction */
typedef struct PR_struct
{
    register8_t PR; /* General Power Reduction */
    register8_t PRPA; /* Power Reduction Port A */
    register8_t PRPB; /* Power Reduction Port B */
    register8_t PRPC; /* Power Reduction Port C */
    register8_t PRPD; /* Power Reduction Port D */
    register8_t PRPE; /* Power Reduction Port E */
    register8_t PRPF; /* Power Reduction Port F */
} PR_t;

/*
--------------------------------------------------------------------------
SLEEP - Sleep Controller
--------------------------------------------------------------------------
*/

/* Sleep Controller */
typedef struct SLEEP_struct
{
    register8_t CTRL; /* Control Register */
} SLEEP_t;

/*
--------------------------------------------------------------------------
OSC - Oscillator
--------------------------------------------------------------------------
*/

/* Oscillator */
typedef struct OSC_struct
{
    register8_t CTRL; /* Control Register */
    register8_t STATUS; /* Status Register */
    register8_t XOSCCTRL; /* External Oscillator Control Register */
    register8_t XOSCFAIL; /* External Oscillator Failure Detection Register */
    register8_t RC32KCAL; /* 32kHz Internal Oscillator Calibration Register */
    register8_t PLLCTRL; /* PLL Control REgister */
    register8_t DFLLCTRL; /* DFLL Control Register */
} OSC_t;

/*
--------------------------------------------------------------------------
DFLL - DFLL
--------------------------------------------------------------------------
*/

/* DFLL */
typedef struct DFLL_struct
{
    register8_t OSCCNT0; /* Oscillator Counter Register 0 */
    register8_t OSCCNT1; /* Oscillator Counter Register 1 */
    register8_t OSCCNT2; /* Oscillator Counter Register 2 */
    register8_t CALA; /* Calibration Register A */
    register8_t CALB; /* Calibration Register B */
} DFLL_t;

/*
--------------------------------------------------------------------------
RST - Reset
--------------------------------------------------------------------------
*/

/* Reset */
typedef struct RST_struct
{
    register8_t STATUS; /* Status Register */
    register8_t CTRL; /* Control Register */
} RST_t;

/*
--------------------------------------------------------------------------
WDT - Watch-Dog Timer
--------------------------------------------------------------------------
*/

/* Watch-Dog Timer */
typedef struct WDT_struct
{
    register8_t CTRL; /* Control */
    register8_t WINCTRL; /* Windowed Mode Control */
    register8_t STATUS; /* Status */
} WDT_t;

/*
--------------------------------------------------------------------------
MCU - MCU
--------------------------------------------------------------------------
*/

/* MCU */
typedef struct MCU_struct
{
    register8_t DEVID0; /* Device ID byte 0 */
    register8_t DEVID1; /* Device ID byte 1 */
    register8_t DEVID2; /* Device ID byte 2 */
    register8_t REVID; /* Revision ID */
    register8_t JTAGUID; /* JTAG User ID */
    register8_t reserved_0x05;
    register8_t MCUCR; /* MCU Control */
    register8_t reserved_0x07;
    register8_t EVSYSLOCK; /* Event System Lock */
    register8_t AWEXLOCK; /* AWeX Lock */
    register8_t reserved_0x0A;
    register8_t reserved_0x0B;
} MCU_t;

/*
--------------------------------------------------------------------------
PMIC - Programmable Multi-level Interrupt Controller
--------------------------------------------------------------------------
*/

/* Programmable Multi-level Interrupt Controller */
typedef struct PMIC_struct
{
    register8_t STATUS; /* Status Register */
    register8_t INTPRI; /* Interrupt Priority */
    register8_t CTRL; /* Control Register */
} PMIC_t;

/*
--------------------------------------------------------------------------
DMA - DMA Controller
--------------------------------------------------------------------------
*/

/* DMA Channel */
typedef struct DMA_CH_struct
{
    register8_t CTRLA; /* Channel Control */
    register8_t CTRLB; /* Channel Control */
    register8_t ADDRCTRL; /* Address Control */
    register8_t TRIGSRC; /* Channel Trigger Source */
    register8_t reserved_0x03;
    _WORDREGISTER(TRFCNT); /* Channel Block Transfer Count */
    register8_t REPCNT; /* Channel Repeat Count */
    register8_t reserved_0x07;
    register8_t SRCADDR0; /* Channel Source Address 0 */
    register8_t SRCADDR1; /* Channel Source Address 1 */
    register8_t SRCADDR2; /* Channel Source Address 2 */
    register8_t reserved_0x0B;
    register8_t DESTADDR0; /* Channel Destination Address 0 */
    register8_t DESTADDR1; /* Channel Destination Address 1 */
    register8_t DESTADDR2; /* Channel Destination Address 2 */
    register8_t reserved_0x0F;
} DMA_CH_t;

/* DMA Controller */
typedef struct DMA_struct
{
    register8_t CTRL; /* Control */
    register8_t INTFLAGS; /* Transfer Interrupt Status */
    register8_t STATUS; /* Status */
    register8_t reserved_0x05;
    register8_t reserved_0x06;
    register8_t reserved_0x07;
    register8_t reserved_0x08;
    register8_t reserved_0x09;
    register8_t reserved_0x0A;
    register8_t reserved_0x0B;
    register8_t reserved_0x0C;
    register8_t reserved_0x0D;
    register8_t reserved_0x0E;
    register8_t reserved_0x0F;
    DMA_CH_t CH0; /* DMA Channel 0 */
    DMA_CH_t CH1; /* DMA Channel 1 */
    DMA_CH_t CH2; /* DMA Channel 2 */
    DMA_CH_t CH3; /* DMA Channel 3 */
} DMA_t;

/*
--------------------------------------------------------------------------
EVSYS - Event System
--------------------------------------------------------------------------
*/

/* Event System */
typedef struct EVSYS_struct
{
    register8_t CH0MUX; /* Event Channel 0 Multiplexer */
    register8_t CH1MUX; /* Event Channel 1 Multiplexer */
    register8_t CH2MUX; /* Event Channel 2 Multiplexer */
    register8_t CH3MUX; /* Event Channel 3 Multiplexer */
    register8_t CH4MUX; /* Event Channel 4 Multiplexer */
    register8_t CH5MUX; /* Event Channel 5 Multiplexer */
    register8_t CH6MUX; /* Event Channel 6 Multiplexer */
    register8_t CH7MUX; /* Event Channel 7 Multiplexer */
    register8_t CH0CTRL; /* Channel 0 Control Register */
    register8_t CH1CTRL; /* Channel 1 Control Register */
    register8_t CH2CTRL; /* Channel 2 Control Register */
    register8_t CH3CTRL; /* Channel 3 Control Register */
    register8_t CH4CTRL; /* Channel 4 Control Register */
    register8_t CH5CTRL; /* Channel 5 Control Register */
    register8_t CH6CTRL; /* Channel 6 Control Register */
    register8_t CH7CTRL; /* Channel 7 Control Register */
    register8_t STROBE; /* Event Strobe */
    register8_t DATA; /* Event Data */
} EVSYS_t;

/*
--------------------------------------------------------------------------
NVM - Non Volatile Memory
--------------------------------------------------------------------------
*/

/* Non-volatile Memory */
typedef struct NVM_struct
{
    register8_t ADDR0; /* Address Register 0 */
    register8_t ADDR1; /* Address Register 1 */
    register8_t ADDR2; /* Address Register 2 */
    register8_t reserved_0x03;
    register8_t DATA0; /* Data Register 0 */
    register8_t DATA1; /* Data Register 1 */
    register8_t DATA2; /* Data Register 2 */
    register8_t reserved_0x07;
    register8_t reserved_0x08;
    register8_t reserved_0x09;
    register8_t CMD; /* Command */
    register8_t CTRLA; /* Control Register A */
    register8_t CTRLB; /* Control Register B */
    register8_t INTCTRL; /* Interrupt Control */
    register8_t reserved_0x0E;
    register8_t STATUS; /* Status */
    register8_t LOCKBITS; /* Lock Bits */
} NVM_t;

/* Lock Bits */
typedef struct NVM_LOCKBITS_struct
{
    register8_t LOCKBITS; /* Lock Bits */
} NVM_LOCKBITS_t;

/* Fuses */
typedef struct NVM_FUSES_struct
{
    register8_t FUSEBYTE0; /* JTAG User ID */
    register8_t FUSEBYTE1; /* Watchdog Configuration */
    register8_t FUSEBYTE2; /* Reset Configuration */
    register8_t reserved_0x03;
    register8_t FUSEBYTE4; /* Start-up Configuration */
    register8_t FUSEBYTE5; /* EESAVE and BOD Level */
} NVM_FUSES_t;

/* Production Signatures */
typedef struct NVM_PROD_SIGNATURES_struct
{
    register8_t RCOSC2M; /* RCOSC 2MHz Calibration Value */
    register8_t RCOSC32K; /* RCOSC 32kHz Calibration Value */
    register8_t RCOSC32M; /* RCOSC 32MHz Calibration Value */
    register8_t LOTNUM0; /* Lot Number, Byte 0, ASCII */
    register8_t LOTNUM1; /* Lot Number, Byte 1, ASCII */
    register8_t LOTNUM2; /* Lot Number, Byte 2, ASCII */
    register8_t LOTNUM3; /* Lot Number, Byte 3, ASCII */
    register8_t LOTNUM4; /* Lot Number, Byte 4, ASCII */
    register8_t LOTNUM5; /* Lot Number, Byte 5, ASCII */
    register8_t WAFNUM; /* Wafer Number */
    _WORDREGISTER(COORDX); /* Wafer Coordinate X */
    _WORDREGISTER(COORDY); /* Wafer Coordinate Y */
    register8_t ADCACAL0; /* ADCA Calibration Byte 0 */
    register8_t ADCACAL1; /* ADCA Calibration Byte 1 */
    register8_t ADCACAL2; /* ADCA Calibration Byte 2 */
    register8_t ADCACAL3; /* ADCA Calibration Byte 3 */
    register8_t ADCBCAL0; /* ADCB Calibration Byte 0 */
    register8_t ADCBCAL1; /* ADCB Calibration Byte 1 */
    register8_t ADCBCAL2; /* ADCB Calibration Byte 2 */
    register8_t ADCBCAL3; /* ADCB Calibration Byte 3 */
    register8_t DACACAL0; /* DACA Calibration Byte 0 */
    register8_t DACACAL1; /* DACA Calibration Byte 1 */
    register8_t DACBCAL0; /* DACB Calibration Byte 0 */
    register8_t DACBCAL1; /* DACB Calibration Byte 1 */
} NVM_PROD_SIGNATURES_t;

/*
--------------------------------------------------------------------------
AC - Analog Comparator
--------------------------------------------------------------------------
*/

/* Analog Comparator */
typedef struct AC_struct
{
    register8_t AC0CTRL; /* Comparator 0 Control */
    register8_t AC1CTRL; /* Comparator 1 Control */
    register8_t AC0MUXCTRL; /* Comparator 0 MUX Control */
    register8_t AC1MUXCTRL; /* Comparator 1 MUX Control */
    register8_t CTRLA; /* Control Register A */
    register8_t CTRLB; /* Control Register B */
    register8_t WINCTRL; /* Window Mode Control */
    register8_t STATUS; /* Status */
} AC_t;

/*
--------------------------------------------------------------------------
ADC - Analog/Digital Converter
--------------------------------------------------------------------------
*/

/* ADC Channel */
typedef struct ADC_CH_struct
{
    register8_t CTRL; /* Control Register */
    register8_t MUXCTRL; /* MUX Control */
    register8_t INTCTRL; /* Channel Interrupt Control */
    register8_t INTFLAGS; /* Interrupt Flags */
    _WORDREGISTER(RES); /* Channel Result */
    register8_t reserved_0x6;
    register8_t reserved_0x7;
} ADC_CH_t;

/* Analog-to-Digital Converter */
typedef struct ADC_struct
{
    register8_t CTRLA; /* Control Register A */
    register8_t CTRLB; /* Control Register B */
    register8_t REFCTRL; /* Reference Control */
    register8_t EVCTRL; /* Event Control */
    register8_t PRESCALER; /* Clock Prescaler */
    register8_t CALCTRL; /* Calibration Control Register */
    register8_t INTFLAGS; /* Interrupt Flags */
    register8_t reserved_0x07;
    register8_t reserved_0x08;
    register8_t reserved_0x09;
    register8_t reserved_0x10;
    register8_t reserved_0x11;
    register8_t CALIB; /* Calibration Value */
    register8_t reserved_0x0D;
    register8_t reserved_0x0E;
    register8_t reserved_0x0F;
    _WORDREGISTER(CH0RES); /* Channel 0 Result */
    _WORDREGISTER(CH1RES); /* Channel 1 Result */
    _WORDREGISTER(CH2RES); /* Channel 2 Result */
    _WORDREGISTER(CH3RES); /* Channel 3 Result */
    _WORDREGISTER(CMP); /* Compare Value */
    register8_t reserved_0x1A;
    register8_t reserved_0x1B;
    register8_t reserved_0x1C;
    register8_t reserved_0x1D;
    register8_t reserved_0x1E;
    register8_t reserved_0x1F;
    ADC_CH_t CH0; /* ADC Channel 0 */
    ADC_CH_t CH1; /* ADC Channel 1 */
    ADC_CH_t CH2; /* ADC Channel 2 */
    ADC_CH_t CH3; /* ADC Channel 3 */
} ADC_t;

/*
--------------------------------------------------------------------------
DAC - Digital/Analog Converter
--------------------------------------------------------------------------
*/

/* Digital-to-Analog Converter */
typedef struct DAC_struct
{
    register8_t CTRLA; /* Control Register A */
    register8_t CTRLB; /* Control Register B */
    register8_t CTRLC; /* Control Register C */
    register8_t EVCTRL; /* Event Input Control */
    register8_t TIMCTRL; /* Timing Control */
    register8_t STATUS; /* Status */
    register8_t reserved_0x06;
    register8_t reserved_0x07;
    register8_t GAINCAL; /* Gain Calibration */
    register8_t OFFSETCAL; /* Offset Calibration */
    register8_t reserved_0x0A;
    register8_t reserved_0x0B;
    register8_t reserved_0x0C;
    register8_t reserved_0x0D;
    register8_t reserved_0x0E;
    register8_t reserved_0x0F;
    register8_t reserved_0x10;
    register8_t reserved_0x11;
    register8_t reserved_0x12;
    register8_t reserved_0x13;
    register8_t reserved_0x14;
    register8_t reserved_0x15;
    register8_t reserved_0x16;
    register8_t reserved_0x17;
    _WORDREGISTER(CH0DATA); /* Channel 0 Data */
    _WORDREGISTER(CH1DATA); /* Channel 1 Data */
} DAC_t;

/*
--------------------------------------------------------------------------
RTC - Real-Time Clock
--------------------------------------------------------------------------
*/

/* Real-Time Clock */
typedef struct RTC_struct
{
    register8_t CTRL; /* Control Register */
    register8_t STATUS; /* Status Register */
    register8_t INTCTRL; /* Interrupt Control Register */
    register8_t INTFLAGS; /* Interrupt Flags */
    register8_t TEMP; /* Temporary register */
    register8_t reserved_0x05;
    register8_t reserved_0x06;
    register8_t reserved_0x07;
    _WORDREGISTER(CNT); /* Count Register */
    _WORDREGISTER(PER); /* Period Register */
    _WORDREGISTER(COMP); /* Compare Register */
} RTC_t;

/*
--------------------------------------------------------------------------
EBI - External Bus Interface
--------------------------------------------------------------------------
*/

/* EBI Chip Select Module */
typedef struct EBI_CS_struct
{
    register8_t CTRLA; /* Chip Select Control Register A */
    register8_t CTRLB; /* Chip Select Control Register B */
    _WORDREGISTER(BASEADDR); /* Chip Select Base Address */
} EBI_CS_t;

/* External Bus Interface */
typedef struct EBI_struct
{
    register8_t CTRL; /* Control */
    register8_t SDRAMCTRLA; /* SDRAM Control Register A */
    register8_t reserved_0x02;
    register8_t reserved_0x03;
    _WORDREGISTER(REFRESH); /* SDRAM Refresh Period */
    _WORDREGISTER(INITDLY); /* SDRAM Initialization Delay */
    register8_t SDRAMCTRLB; /* SDRAM Control Register B */
    register8_t SDRAMCTRLC; /* SDRAM Control Register C */
    register8_t reserved_0x0A;
    register8_t reserved_0x0B;
    register8_t reserved_0x0C;
    register8_t reserved_0x0D;
    register8_t reserved_0x0E;
    register8_t reserved_0x0F;
    EBI_CS_t CS0; /* Chip Select 0 */
    EBI_CS_t CS1; /* Chip Select 1 */
    EBI_CS_t CS2; /* Chip Select 2 */
    EBI_CS_t CS3; /* Chip Select 3 */
} EBI_t;

/*
--------------------------------------------------------------------------
TWI - Two-Wire Interface
--------------------------------------------------------------------------
*/

/*  */
typedef struct TWI_MASTER_struct
{
    register8_t CTRLA; /* Control Register A */
    register8_t CTRLB; /* Control Register B */
    register8_t CTRLC; /* Control Register C */
    register8_t STATUS; /* Status Register */
    register8_t BAUD; /* Baurd Rate Control Register */
    register8_t ADDR; /* Address Register */
    register8_t DATA; /* Data Register */
} TWI_MASTER_t;

/*  */
typedef struct TWI_SLAVE_struct
{
    register8_t CTRLA; /* Control Register A */
    register8_t CTRLB; /* Control Register B */
    register8_t STATUS; /* Status Register */
    register8_t ADDR; /* Address Register */
    register8_t DATA; /* Data Register */
} TWI_SLAVE_t;

/* Two-Wire Interface */
typedef struct TWI_struct
{
    register8_t CTRL; /* TWI Common Control Register */
    TWI_MASTER_t MASTER; /* TWI master module */
    TWI_SLAVE_t SLAVE; /* TWI slave module */
} TWI_t;

/*
--------------------------------------------------------------------------
PORT - Port Configuration
--------------------------------------------------------------------------
*/

/* I/O port Configuration */
typedef struct PORTCFG_struct
{
    register8_t MPCMASK; /* Multi-pin Configuration Mask */
    register8_t reserved_0x01;
    register8_t VPCTRLA; /* Virtual Port Control Register A */
    register8_t VPCTRLB; /* Virtual Port Control Register B */
    register8_t CLKEVOUT; /* Clock and Event Out Register */
} PORTCFG_t;

/* Virtual Port */
typedef struct VPORT_struct
{
    register8_t DIR; /* I/O Port Data Direction */
    register8_t OUT; /* I/O Port Output */
    register8_t IN; /* I/O Port Input */
    register8_t INTFLAGS; /* Interrupt Flag Register */
} VPORT_t;

/* I/O Ports */
typedef struct PORT_struct
{
    register8_t DIR; /* I/O Port Data Direction */
    register8_t DIRSET; /* I/O Port Data Direction Set */
    register8_t DIRCLR; /* I/O Port Data Direction Clear */
    register8_t DIRTGL; /* I/O Port Data Direction Toggle */
    register8_t OUT; /* I/O Port Output */
    register8_t OUTSET; /* I/O Port Output Set */
    register8_t OUTCLR; /* I/O Port Output Clear */
    register8_t OUTTGL; /* I/O Port Output Toggle */
    register8_t IN; /* I/O port Input */
    register8_t INTCTRL; /* Interrupt Control Register */
    register8_t INT0MASK; /* Port Interrupt 0 Mask */
    register8_t INT1MASK; /* Port Interrupt 1 Mask */
    register8_t INTFLAGS; /* Interrupt Flag Register */
    register8_t reserved_0x0D;
    register8_t reserved_0x0E;
    register8_t reserved_0x0F;
    register8_t PIN0CTRL; /* Pin 0 Control Register */
    register8_t PIN1CTRL; /* Pin 1 Control Register */
    register8_t PIN2CTRL; /* Pin 2 Control Register */
    register8_t PIN3CTRL; /* Pin 3 Control Register */
    register8_t PIN4CTRL; /* Pin 4 Control Register */
    register8_t PIN5CTRL; /* Pin 5 Control Register */
    register8_t PIN6CTRL; /* Pin 6 Control Register */
    register8_t PIN7CTRL; /* Pin 7 Control Register */
} PORT_t;

/*
--------------------------------------------------------------------------
TC - 16-bit Timer/Counter With PWM
--------------------------------------------------------------------------
*/

/* 16-bit Timer/Counter 0 */
typedef struct TC0_struct
{
    register8_t CTRLA; /* Control  Register A */
    register8_t CTRLB; /* Control Register B */
    register8_t CTRLC; /* Control register C */
    register8_t CTRLD; /* Control Register D */
    register8_t CTRLE; /* Control Register E */
    register8_t reserved_0x05;
    register8_t INTCTRLA; /* Interrupt Control Register A */
    register8_t INTCTRLB; /* Interrupt Control Register B */
    register8_t CTRLFCLR; /* Control Register F Clear */
    register8_t CTRLFSET; /* Control Register F Set */
    register8_t CTRLGCLR; /* Control Register G Clear */
    register8_t CTRLGSET; /* Control Register G Set */
    register8_t INTFLAGS; /* Interrupt Flag Register */
    register8_t reserved_0x0D;
    register8_t reserved_0x0E;
    register8_t TEMP; /* Temporary Register For 16-bit Access */
    register8_t reserved_0x10;
    register8_t reserved_0x11;
    register8_t reserved_0x12;
    register8_t reserved_0x13;
    register8_t reserved_0x14;
    register8_t reserved_0x15;
    register8_t reserved_0x16;
    register8_t reserved_0x17;
    register8_t reserved_0x18;
    register8_t reserved_0x19;
    register8_t reserved_0x1A;
    register8_t reserved_0x1B;
    register8_t reserved_0x1C;
    register8_t reserved_0x1D;
    register8_t reserved_0x1E;
    register8_t reserved_0x1F;
    _WORDREGISTER(CNT); /* Count */
    register8_t reserved_0x22;
    register8_t reserved_0x23;
    register8_t reserved_0x24;
    register8_t reserved_0x25;
    _WORDREGISTER(PER); /* Period */
    _WORDREGISTER(CCA); /* Compare or Capture A */
    _WORDREGISTER(CCB); /* Compare or Capture B */
    _WORDREGISTER(CCC); /* Compare or Capture C */
    _WORDREGISTER(CCD); /* Compare or Capture D */
    register8_t reserved_0x30;
    register8_t reserved_0x31;
    register8_t reserved_0x32;
    register8_t reserved_0x33;
    register8_t reserved_0x34;
    register8_t reserved_0x35;
    _WORDREGISTER(PERBUF); /* Period Buffer */
    _WORDREGISTER(CCABUF); /* Compare Or Capture A Buffer */
    _WORDREGISTER(CCBBUF); /* Compare Or Capture B Buffer */
    _WORDREGISTER(CCCBUF); /* Compare Or Capture C Buffer */
    _WORDREGISTER(CCDBUF); /* Compare Or Capture D Buffer */
} TC0_t;

/* 16-bit Timer/Counter 1 */
typedef struct TC1_struct
{
    register8_t CTRLA; /* Control  Register A */
    register8_t CTRLB; /* Control Register B */
    register8_t CTRLC; /* Control register C */
    register8_t CTRLD; /* Control Register D */
    register8_t CTRLE; /* Control Register E */
    register8_t reserved_0x05;
    register8_t INTCTRLA; /* Interrupt Control Register A */
    register8_t INTCTRLB; /* Interrupt Control Register B */
    register8_t CTRLFCLR; /* Control Register F Clear */
    register8_t CTRLFSET; /* Control Register F Set */
    register8_t CTRLGCLR; /* Control Register G Clear */
    register8_t CTRLGSET; /* Control Register G Set */
    register8_t INTFLAGS; /* Interrupt Flag Register */
    register8_t reserved_0x0D;
    register8_t reserved_0x0E;
    register8_t TEMP; /* Temporary Register For 16-bit Access */
    register8_t reserved_0x10;
    register8_t reserved_0x11;
    register8_t reserved_0x12;
    register8_t reserved_0x13;
    register8_t reserved_0x14;
    register8_t reserved_0x15;
    register8_t reserved_0x16;
    register8_t reserved_0x17;
    register8_t reserved_0x18;
    register8_t reserved_0x19;
    register8_t reserved_0x1A;
    register8_t reserved_0x1B;
    register8_t reserved_0x1C;
    register8_t reserved_0x1D;
    register8_t reserved_0x1E;
    register8_t reserved_0x1F;
    _WORDREGISTER(CNT); /* Count */
    register8_t reserved_0x22;
    register8_t reserved_0x23;
    register8_t reserved_0x24;
    register8_t reserved_0x25;
    _WORDREGISTER(PER); /* Period */
    _WORDREGISTER(CCA); /* Compare or Capture A */
    _WORDREGISTER(CCB); /* Compare or Capture B */
    register8_t reserved_0x2C;
    register8_t reserved_0x2D;
    register8_t reserved_0x2E;
    register8_t reserved_0x2F;
    register8_t reserved_0x30;
    register8_t reserved_0x31;
    register8_t reserved_0x32;
    register8_t reserved_0x33;
    register8_t reserved_0x34;
    register8_t reserved_0x35;
    _WORDREGISTER(PERBUF); /* Period Buffer */
    _WORDREGISTER(CCABUF); /* Compare Or Capture A Buffer */
    _WORDREGISTER(CCBBUF); /* Compare Or Capture B Buffer */
} TC1_t;

/* Advanced Waveform Extension */
typedef struct AWEX_struct
{
    register8_t CTRL; /* Control Register */
    register8_t reserved_0x01;
    register8_t FDEVMASK; /* Fault Detection Event Mask */
    register8_t DFCTRL; /* Fault Detection Control Register */
    register8_t STATUS; /* Status Register */
    register8_t reserved_0x05;
    register8_t DTBOTH; /* Dead Time Both Sides */
    register8_t DTBOTHBUF; /* Dead Time Both Sides Buffer */
    register8_t DTLS; /* Dead Time Low Side */
    register8_t DTHS; /* Dead Time High Side */
    register8_t DTLSBUF; /* Dead Time Low Side Buffer */
    register8_t DTHSBUF; /* Dead Time High Side Buffer */
    register8_t OUTOVEN; /* Output Override Enable */
} AWEX_t;

/* High-Resolution Extension */
typedef struct HIRES_struct
{
    register8_t CTRL; /* Control Register */
} HIRES_t;

/*
--------------------------------------------------------------------------
USART - Universal Asynchronous Receiver-Transmitter
--------------------------------------------------------------------------
*/

/* Universal Synchronous/Asynchronous Receiver/Transmitter */
typedef struct USART_struct
{
    register8_t DATA; /* Data Register */
    register8_t STATUS; /* Status Register */
    register8_t reserved_0x02;
    register8_t CTRLA; /* Control Register A */
    register8_t CTRLB; /* Control Register B */
    register8_t CTRLC; /* Control Register C */
    register8_t BAUDCTRLA; /* Baud Rate Control Register A */
    register8_t BAUDCTRLB; /* Baud Rate Control Register B */
} USART_t;

/*
--------------------------------------------------------------------------
SPI - Serial Peripheral Interface
--------------------------------------------------------------------------
*/

/* Serial Peripheral Interface */
typedef struct SPI_struct
{
    register8_t CTRL; /* Control Register */
    register8_t INTCTRL; /* Interrupt Control Register */
    register8_t STATUS; /* Status Register */
    register8_t DATA; /* Data Register */
} SPI_t;

/*
--------------------------------------------------------------------------
IRCOM - IR Communication Module
--------------------------------------------------------------------------
*/

/* IR Communication Module */
typedef struct IRCOM_struct
{
    register8_t TXPLCTRL; /* IrDA Transmitter Pulse Length Control Register */
    register8_t RXPLCTRL; /* IrDA Receiver Pulse Length Control Register */
    register8_t CTRL; /* Control Register */
} IRCOM_t;

/*
--------------------------------------------------------------------------
AES - AES Module
--------------------------------------------------------------------------
*/

/* AES MOdule */
typedef struct AES_struct
{
    register8_t CTRL; /* AES Control Register */
    register8_t STATUS; /* AES Status Register */
    register8_t STATE; /* AES State Register */
    register8_t KEY; /* AES Key Register */
    register8_t INTCTRL; /* AES Interrupt Control Register */
} AES_t;



/*
==========================================================================
 IO Module Instances. Mapped to memory.
==========================================================================
*/


#define OCD      (*(OCD_t *) 0x002E)      /* On-Chip Debug System */
#define CLK      (*(CLK_t *) 0x0040)      /* Clock System */
#define SLEEP      (*(SLEEP_t *) 0x0048)      /* Sleep Controller */
#define OSC      (*(OSC_t *) 0x0050)      /* Oscillator */
#define DFLLRC32M      (*(DFLL_t *) 0x0060)      /* DFLL for 32MHz Clock */
#define DFLLRC2M      (*(DFLL_t *) 0x0068)      /* DFLL for 2MHz Internal RC */
#define PR      (*(PR_t *) 0x0070)      /* Power Reduction */
#define RST      (*(RST_t *) 0x0078)      /* Reset Controller */
#define WDT      (*(WDT_t *) 0x0080)      /* Watch-Dog Timer */
#define MCU      (*(MCU_t *) 0x0090)      /* MCU Revision */
#define PMIC      (*(PMIC_t *) 0x00A0)      /* Programmable Interrupt Controller */
#define DMA      (*(DMA_t *) 0x0100)      /* DMA Controller */
#define EVSYS      (*(EVSYS_t *) 0x0180)      /* Event System */
#define NVM      (*(NVM_t *) 0x01C0)      /* Non Volatile Memory */
#define ACA      (*(AC_t *) 0x0380)      /* Analog Comparator A */
#define ACB      (*(AC_t *) 0x0390)      /* Analog Comparator B */
#define ADCA      (*(ADC_t *) 0x0200)      /* Analog/Digital Converter A */
#define ADCB      (*(ADC_t *) 0x0240)      /* Analog/Digital Converter B */
#define DACA      (*(DAC_t *) 0x0300)      /* Digital/Analog Converter A */
#define DACB      (*(DAC_t *) 0x0320)      /* Digital/Analog Converter B */
#define RTC      (*(RTC_t *) 0x0400)      /* Real-Time Clock */
#define EBI      (*(EBI_t *) 0x0440)      /* External Bus Interface */
#define TWIC      (*(TWI_t *) 0x480)      /* Two-Wire Interface C */
#define TWID      (*(TWI_t *) 0x490)      /* Two-Wire Interface D */
#define TWIE      (*(TWI_t *) 0x4A0)      /* Two-Wire Interface E */
#define TWIF      (*(TWI_t *) 0x4B0)      /* Two-Wire Interface F */
#define PORTCFG      (*(PORTCFG_t *) 0x00B0)      /* Port Configuration */
#define VPORT0      (*(VPORT_t *) 0x0010)      /* Virtual Port 0 */
#define VPORT1      (*(VPORT_t *) 0x0014)      /* Virtual Port 1 */
#define VPORT2      (*(VPORT_t *) 0x0018)      /* Virtual Port 2 */
#define VPORT3      (*(VPORT_t *) 0x001C)      /* Virtual Port 3 */
#define PORTA      (*(PORT_t *) 0x0600)      /* Port A */
#define PORTB      (*(PORT_t *) 0x0620)      /* Port B */
#define PORTC      (*(PORT_t *) 0x0640)      /* Port C */
#define PORTD      (*(PORT_t *) 0x0660)      /* Port D */
#define PORTE      (*(PORT_t *) 0x0680)      /* Port E */
#define PORTF      (*(PORT_t *) 0x06A0)      /* Port F */
#define PORTH      (*(PORT_t *) 0x06E0)      /* Port H */
#define PORTJ      (*(PORT_t *) 0x0700)      /* Port J */
#define PORTK      (*(PORT_t *) 0x0720)      /* Port K */
#define PORTQ      (*(PORT_t *) 0x07C0)      /* Port Q */
#define PORTR      (*(PORT_t *) 0x07E0)      /* Port R */
#define TCC0      (*(TC0_t *) 0x800)      /* 16-bit Timer/Counter With PWM C0 */
#define TCC1      (*(TC1_t *) 0x840)      /* 16-bit Timer/Counter With PWM C1 */
#define AWEXC      (*(AWEX_t *) 0x880)      /* Advanced Waveform Extension C */
#define HIRESC      (*(HIRES_t *) 0x890)      /* High-Resolution PWM C */
#define USARTC0      (*(USART_t *) 0x8A0)      /* Universal Asynchronous Receiver-Transmitter C0 */
#define USARTC1      (*(USART_t *) 0x8B0)      /* Universal Asynchronous Receiver-Transmitter C1 */
#define SPIC      (*(SPI_t *) 0x8C0)      /* Serial Peripheral Interface C */
#define TCD0      (*(TC0_t *) 0x900)      /* 16-bit Timer/Counter With PWM D0 */
#define TCD1      (*(TC1_t *) 0x940)      /* 16-bit Timer/Counter With PWM D1 */
#define HIRESD      (*(HIRES_t *) 0x990)      /* High-Resolution PWM D */
#define USARTD0      (*(USART_t *) 0x9A0)      /* Universal Asynchronous Receiver-Transmitter D0 */
#define USARTD1      (*(USART_t *) 0x9B0)      /* Universal Asynchronous Receiver-Transmitter D1 */
#define SPID      (*(SPI_t *) 0x9C0)      /* Serial Peripheral Interface D */
#define TCE0      (*(TC0_t *) 0xA00)      /* 16-bit Timer/Counter With PWM E0 */
#define TCE1      (*(TC1_t *) 0xA40)      /* 16-bit Timer/Counter With PWM E1 */
#define AWEXE      (*(AWEX_t *) 0xA80)      /* Advanced Waveform Extension E */
#define HIRESE      (*(HIRES_t *) 0xA90)      /* High-Resolution PWM E */
#define USARTE0      (*(USART_t *) 0xAA0)      /* Universal Asynchronous Receiver-Transmitter E0 */
#define USARTE1      (*(USART_t *) 0xAB0)      /* Universal Asynchronous Receiver-Transmitter E1 */
#define SPIE      (*(SPI_t *) 0xAC0)      /* Serial Peripheral Interface E */
#define TCF0      (*(TC0_t *) 0xB00)      /* 16-bit Timer/Counter With PWM F0 */
#define TCF1      (*(TC1_t *) 0xB40)      /* 16-bit Timer/Counter With PWM F1 */
#define HIRESF      (*(HIRES_t *) 0xB90)      /* High-Resolution PWM F */
#define USARTF0      (*(USART_t *) 0xBA0)      /* Universal Asynchronous Receiver-Transmitter F0 */
#define USARTF1      (*(USART_t *) 0xBB0)      /* Universal Asynchronous Receiver-Transmitter F1 */
#define SPIF      (*(SPI_t *) 0xBC0)      /* Serial Peripheral Interface F */
#define IRCOM      (*(IRCOM_t *) 0x8F0)      /* IR Communication Module */
#define AES      (*(AES_t *) 0x0C0)      /* AES Crypto Module */


/* ========== IO register and sub-module fully qualified names ========== */


// OCD - On-Chip Debug System
#define OCD_OCDR0 OCD.OCDR0
#define OCD_OCDR1 OCD.OCDR1

// CLK - Clock System
#define CLK_CTRL CLK.CTRL
#define CLK_PSCTRL CLK.PSCTRL
#define CLK_LOCK CLK.LOCK
#define CLK_RTCCTRL CLK.RTCCTRL

// SLEEP - Sleep Controller
#define SLEEP_CTRL SLEEP.CTRL

// OSC - Oscillator
#define OSC_CTRL OSC.CTRL
#define OSC_STATUS OSC.STATUS
#define OSC_XOSCCTRL OSC.XOSCCTRL
#define OSC_XOSCFAIL OSC.XOSCFAIL
#define OSC_RC32KCAL OSC.RC32KCAL
#define OSC_PLLCTRL OSC.PLLCTRL
#define OSC_DFLLCTRL OSC.DFLLCTRL

// DFLLRC32M - DFLL for 32MHz Clock
#define DFLLRC32M_OSCCNT0 DFLLRC32M.OSCCNT0
#define DFLLRC32M_OSCCNT1 DFLLRC32M.OSCCNT1
#define DFLLRC32M_OSCCNT2 DFLLRC32M.OSCCNT2
#define DFLLRC32M_CALA DFLLRC32M.CALA
#define DFLLRC32M_CALB DFLLRC32M.CALB

// DFLLRC2M - DFLL for 2MHz Internal RC
#define DFLLRC2M_OSCCNT0 DFLLRC2M.OSCCNT0
#define DFLLRC2M_OSCCNT1 DFLLRC2M.OSCCNT1
#define DFLLRC2M_OSCCNT2 DFLLRC2M.OSCCNT2
#define DFLLRC2M_CALA DFLLRC2M.CALA
#define DFLLRC2M_CALB DFLLRC2M.CALB

// PR - Power Reduction
#define PR_PR PR.PR
#define PR_PRPA PR.PRPA
#define PR_PRPB PR.PRPB
#define PR_PRPC PR.PRPC
#define PR_PRPD PR.PRPD
#define PR_PRPE PR.PRPE
#define PR_PRPF PR.PRPF

// RST - Reset Controller
#define RST_STATUS RST.STATUS
#define RST_CTRL RST.CTRL

// WDT - Watch-Dog Timer
#define WDT_CTRL WDT.CTRL
#define WDT_WINCTRL WDT.WINCTRL
#define WDT_STATUS WDT.STATUS

// MCU - MCU Revision
#define MCU_DEVID0 MCU.DEVID0
#define MCU_DEVID1 MCU.DEVID1
#define MCU_DEVID2 MCU.DEVID2
#define MCU_REVID MCU.REVID
#define MCU_JTAGUID MCU.JTAGUID
#define MCU_MCUCR MCU.MCUCR
#define MCU_EVSYSLOCK MCU.EVSYSLOCK
#define MCU_AWEXLOCK MCU.AWEXLOCK

// PMIC - Programmable Interrupt Controller
#define PMIC_STATUS PMIC.STATUS
#define PMIC_INTPRI PMIC.INTPRI
#define PMIC_CTRL PMIC.CTRL

// DMA - DMA Controller
#define DMA_CTRL DMA.CTRL
#define DMA_INTFLAGS DMA.INTFLAGS
#define DMA_STATUS DMA.STATUS

// EVSYS - Event System
#define EVSYS_CH0MUX EVSYS.CH0MUX
#define EVSYS_CH1MUX EVSYS.CH1MUX
#define EVSYS_CH2MUX EVSYS.CH2MUX
#define EVSYS_CH3MUX EVSYS.CH3MUX
#define EVSYS_CH4MUX EVSYS.CH4MUX
#define EVSYS_CH5MUX EVSYS.CH5MUX
#define EVSYS_CH6MUX EVSYS.CH6MUX
#define EVSYS_CH7MUX EVSYS.CH7MUX
#define EVSYS_CH0CTRL EVSYS.CH0CTRL
#define EVSYS_CH1CTRL EVSYS.CH1CTRL
#define EVSYS_CH2CTRL EVSYS.CH2CTRL
#define EVSYS_CH3CTRL EVSYS.CH3CTRL
#define EVSYS_CH4CTRL EVSYS.CH4CTRL
#define EVSYS_CH5CTRL EVSYS.CH5CTRL
#define EVSYS_CH6CTRL EVSYS.CH6CTRL
#define EVSYS_CH7CTRL EVSYS.CH7CTRL
#define EVSYS_STROBE EVSYS.STROBE
#define EVSYS_DATA EVSYS.DATA

// NVM - Non Volatile Memory
#define NVM_ADDR0 NVM.ADDR0
#define NVM_ADDR1 NVM.ADDR1
#define NVM_ADDR2 NVM.ADDR2
#define NVM_DATA0 NVM.DATA0
#define NVM_DATA1 NVM.DATA1
#define NVM_DATA2 NVM.DATA2
#define NVM_CMD NVM.CMD
#define NVM_CTRLA NVM.CTRLA
#define NVM_CTRLB NVM.CTRLB
#define NVM_INTCTRL NVM.INTCTRL
#define NVM_STATUS NVM.STATUS
#define NVM_LOCKBITS NVM.LOCKBITS

// ACA - Analog Comparator A
#define ACA_AC0CTRL ACA.AC0CTRL
#define ACA_AC1CTRL ACA.AC1CTRL
#define ACA_AC0MUXCTRL ACA.AC0MUXCTRL
#define ACA_AC1MUXCTRL ACA.AC1MUXCTRL
#define ACA_CTRLA ACA.CTRLA
#define ACA_CTRLB ACA.CTRLB
#define ACA_WINCTRL ACA.WINCTRL
#define ACA_STATUS ACA.STATUS

// ACB - Analog Comparator B
#define ACB_AC0CTRL ACB.AC0CTRL
#define ACB_AC1CTRL ACB.AC1CTRL
#define ACB_AC0MUXCTRL ACB.AC0MUXCTRL
#define ACB_AC1MUXCTRL ACB.AC1MUXCTRL
#define ACB_CTRLA ACB.CTRLA
#define ACB_CTRLB ACB.CTRLB
#define ACB_WINCTRL ACB.WINCTRL
#define ACB_STATUS ACB.STATUS

// ADCA - Analog/Digital Converter A
#define ADCA_CTRLA ADCA.CTRLA
#define ADCA_CTRLB ADCA.CTRLB
#define ADCA_REFCTRL ADCA.REFCTRL
#define ADCA_EVCTRL ADCA.EVCTRL
#define ADCA_PRESCALER ADCA.PRESCALER
#define ADCA_CALCTRL ADCA.CALCTRL
#define ADCA_INTFLAGS ADCA.INTFLAGS
#define ADCA_CALIB ADCA.CALIB
#define ADCA_CH0RES ADCA.CH0RES
#define ADCA_CH1RES ADCA.CH1RES
#define ADCA_CH2RES ADCA.CH2RES
#define ADCA_CH3RES ADCA.CH3RES
#define ADCA_CMP ADCA.CMP

// ADCB - Analog/Digital Converter B
#define ADCB_CTRLA ADCB.CTRLA
#define ADCB_CTRLB ADCB.CTRLB
#define ADCB_REFCTRL ADCB.REFCTRL
#define ADCB_EVCTRL ADCB.EVCTRL
#define ADCB_PRESCALER ADCB.PRESCALER
#define ADCB_CALCTRL ADCB.CALCTRL
#define ADCB_INTFLAGS ADCB.INTFLAGS
#define ADCB_CALIB ADCB.CALIB
#define ADCB_CH0RES ADCB.CH0RES
#define ADCB_CH1RES ADCB.CH1RES
#define ADCB_CH2RES ADCB.CH2RES
#define ADCB_CH3RES ADCB.CH3RES
#define ADCB_CMP ADCB.CMP

// DACA - Digital/Analog Converter A
#define DACA_CTRLA DACA.CTRLA
#define DACA_CTRLB DACA.CTRLB
#define DACA_CTRLC DACA.CTRLC
#define DACA_EVCTRL DACA.EVCTRL
#define DACA_TIMCTRL DACA.TIMCTRL
#define DACA_STATUS DACA.STATUS
#define DACA_GAINCAL DACA.GAINCAL
#define DACA_OFFSETCAL DACA.OFFSETCAL
#define DACA_CH0DATA DACA.CH0DATA
#define DACA_CH1DATA DACA.CH1DATA

// DACB - Digital/Analog Converter B
#define DACB_CTRLA DACB.CTRLA
#define DACB_CTRLB DACB.CTRLB
#define DACB_CTRLC DACB.CTRLC
#define DACB_EVCTRL DACB.EVCTRL
#define DACB_TIMCTRL DACB.TIMCTRL
#define DACB_STATUS DACB.STATUS
#define DACB_GAINCAL DACB.GAINCAL
#define DACB_OFFSETCAL DACB.OFFSETCAL
#define DACB_CH0DATA DACB.CH0DATA
#define DACB_CH1DATA DACB.CH1DATA

// RTC - Real-Time Clock
#define RTC_CTRL RTC.CTRL
#define RTC_STATUS RTC.STATUS
#define RTC_INTCTRL RTC.INTCTRL
#define RTC_INTFLAGS RTC.INTFLAGS
#define RTC_TEMP RTC.TEMP
#define RTC_CNT RTC.CNT
#define RTC_PER RTC.PER
#define RTC_COMP RTC.COMP

// EBI - External Bus Interface
#define EBI_CTRL EBI.CTRL
#define EBI_SDRAMCTRLA EBI.SDRAMCTRLA
#define EBI_REFRESH EBI.REFRESH
#define EBI_INITDLY EBI.INITDLY
#define EBI_SDRAMCTRLB EBI.SDRAMCTRLB
#define EBI_SDRAMCTRLC EBI.SDRAMCTRLC

// TWIC - Two-Wire Interface C
#define TWIC_CTRL TWIC.CTRL

// TWID - Two-Wire Interface D
#define TWID_CTRL TWID.CTRL

// TWIE - Two-Wire Interface E
#define TWIE_CTRL TWIE.CTRL

// TWIF - Two-Wire Interface F
#define TWIF_CTRL TWIF.CTRL

// PORTCFG - Port Configuration
#define PORTCFG_MPCMASK PORTCFG.MPCMASK
#define PORTCFG_VPCTRLA PORTCFG.VPCTRLA
#define PORTCFG_VPCTRLB PORTCFG.VPCTRLB
#define PORTCFG_CLKEVOUT PORTCFG.CLKEVOUT

// VPORT0 - Virtual Port 0
#define VPORT0_DIR VPORT0.DIR
#define VPORT0_OUT VPORT0.OUT
#define VPORT0_IN VPORT0.IN
#define VPORT0_INTFLAGS VPORT0.INTFLAGS

// VPORT1 - Virtual Port 1
#define VPORT1_DIR VPORT1.DIR
#define VPORT1_OUT VPORT1.OUT
#define VPORT1_IN VPORT1.IN
#define VPORT1_INTFLAGS VPORT1.INTFLAGS

// VPORT2 - Virtual Port 2
#define VPORT2_DIR VPORT2.DIR
#define VPORT2_OUT VPORT2.OUT
#define VPORT2_IN VPORT2.IN
#define VPORT2_INTFLAGS VPORT2.INTFLAGS

// VPORT3 - Virtual Port 3
#define VPORT3_DIR VPORT3.DIR
#define VPORT3_OUT VPORT3.OUT
#define VPORT3_IN VPORT3.IN
#define VPORT3_INTFLAGS VPORT3.INTFLAGS

// PORTA - Port A
#define PORTA_DIR PORTA.DIR
#define PORTA_DIRSET PORTA.DIRSET
#define PORTA_DIRCLR PORTA.DIRCLR
#define PORTA_DIRTGL PORTA.DIRTGL
#define PORTA_OUT PORTA.OUT
#define PORTA_OUTSET PORTA.OUTSET
#define PORTA_OUTCLR PORTA.OUTCLR
#define PORTA_OUTTGL PORTA.OUTTGL
#define PORTA_IN PORTA.IN
#define PORTA_INTCTRL PORTA.INTCTRL
#define PORTA_INT0MASK PORTA.INT0MASK
#define PORTA_INT1MASK PORTA.INT1MASK
#define PORTA_INTFLAGS PORTA.INTFLAGS
#define PORTA_PIN0CTRL PORTA.PIN0CTRL
#define PORTA_PIN1CTRL PORTA.PIN1CTRL
#define PORTA_PIN2CTRL PORTA.PIN2CTRL
#define PORTA_PIN3CTRL PORTA.PIN3CTRL
#define PORTA_PIN4CTRL PORTA.PIN4CTRL
#define PORTA_PIN5CTRL PORTA.PIN5CTRL
#define PORTA_PIN6CTRL PORTA.PIN6CTRL
#define PORTA_PIN7CTRL PORTA.PIN7CTRL

// PORTB - Port B
#define PORTB_DIR PORTB.DIR
#define PORTB_DIRSET PORTB.DIRSET
#define PORTB_DIRCLR PORTB.DIRCLR
#define PORTB_DIRTGL PORTB.DIRTGL
#define PORTB_OUT PORTB.OUT
#define PORTB_OUTSET PORTB.OUTSET
#define PORTB_OUTCLR PORTB.OUTCLR
#define PORTB_OUTTGL PORTB.OUTTGL
#define PORTB_IN PORTB.IN
#define PORTB_INTCTRL PORTB.INTCTRL
#define PORTB_INT0MASK PORTB.INT0MASK
#define PORTB_INT1MASK PORTB.INT1MASK
#define PORTB_INTFLAGS PORTB.INTFLAGS
#define PORTB_PIN0CTRL PORTB.PIN0CTRL
#define PORTB_PIN1CTRL PORTB.PIN1CTRL
#define PORTB_PIN2CTRL PORTB.PIN2CTRL
#define PORTB_PIN3CTRL PORTB.PIN3CTRL
#define PORTB_PIN4CTRL PORTB.PIN4CTRL
#define PORTB_PIN5CTRL PORTB.PIN5CTRL
#define PORTB_PIN6CTRL PORTB.PIN6CTRL
#define PORTB_PIN7CTRL PORTB.PIN7CTRL

// PORTC - Port C
#define PORTC_DIR PORTC.DIR
#define PORTC_DIRSET PORTC.DIRSET
#define PORTC_DIRCLR PORTC.DIRCLR
#define PORTC_DIRTGL PORTC.DIRTGL
#define PORTC_OUT PORTC.OUT
#define PORTC_OUTSET PORTC.OUTSET
#define PORTC_OUTCLR PORTC.OUTCLR
#define PORTC_OUTTGL PORTC.OUTTGL
#define PORTC_IN PORTC.IN
#define PORTC_INTCTRL PORTC.INTCTRL
#define PORTC_INT0MASK PORTC.INT0MASK
#define PORTC_INT1MASK PORTC.INT1MASK
#define PORTC_INTFLAGS PORTC.INTFLAGS
#define PORTC_PIN0CTRL PORTC.PIN0CTRL
#define PORTC_PIN1CTRL PORTC.PIN1CTRL
#define PORTC_PIN2CTRL PORTC.PIN2CTRL
#define PORTC_PIN3CTRL PORTC.PIN3CTRL
#define PORTC_PIN4CTRL PORTC.PIN4CTRL
#define PORTC_PIN5CTRL PORTC.PIN5CTRL
#define PORTC_PIN6CTRL PORTC.PIN6CTRL
#define PORTC_PIN7CTRL PORTC.PIN7CTRL

// PORTD - Port D
#define PORTD_DIR PORTD.DIR
#define PORTD_DIRSET PORTD.DIRSET
#define PORTD_DIRCLR PORTD.DIRCLR
#define PORTD_DIRTGL PORTD.DIRTGL
#define PORTD_OUT PORTD.OUT
#define PORTD_OUTSET PORTD.OUTSET
#define PORTD_OUTCLR PORTD.OUTCLR
#define PORTD_OUTTGL PORTD.OUTTGL
#define PORTD_IN PORTD.IN
#define PORTD_INTCTRL PORTD.INTCTRL
#define PORTD_INT0MASK PORTD.INT0MASK
#define PORTD_INT1MASK PORTD.INT1MASK
#define PORTD_INTFLAGS PORTD.INTFLAGS
#define PORTD_PIN0CTRL PORTD.PIN0CTRL
#define PORTD_PIN1CTRL PORTD.PIN1CTRL
#define PORTD_PIN2CTRL PORTD.PIN2CTRL
#define PORTD_PIN3CTRL PORTD.PIN3CTRL
#define PORTD_PIN4CTRL PORTD.PIN4CTRL
#define PORTD_PIN5CTRL PORTD.PIN5CTRL
#define PORTD_PIN6CTRL PORTD.PIN6CTRL
#define PORTD_PIN7CTRL PORTD.PIN7CTRL

// PORTE - Port E
#define PORTE_DIR PORTE.DIR
#define PORTE_DIRSET PORTE.DIRSET
#define PORTE_DIRCLR PORTE.DIRCLR
#define PORTE_DIRTGL PORTE.DIRTGL
#define PORTE_OUT PORTE.OUT
#define PORTE_OUTSET PORTE.OUTSET
#define PORTE_OUTCLR PORTE.OUTCLR
#define PORTE_OUTTGL PORTE.OUTTGL
#define PORTE_IN PORTE.IN
#define PORTE_INTCTRL PORTE.INTCTRL
#define PORTE_INT0MASK PORTE.INT0MASK
#define PORTE_INT1MASK PORTE.INT1MASK
#define PORTE_INTFLAGS PORTE.INTFLAGS
#define PORTE_PIN0CTRL PORTE.PIN0CTRL
#define PORTE_PIN1CTRL PORTE.PIN1CTRL
#define PORTE_PIN2CTRL PORTE.PIN2CTRL
#define PORTE_PIN3CTRL PORTE.PIN3CTRL
#define PORTE_PIN4CTRL PORTE.PIN4CTRL
#define PORTE_PIN5CTRL PORTE.PIN5CTRL
#define PORTE_PIN6CTRL PORTE.PIN6CTRL
#define PORTE_PIN7CTRL PORTE.PIN7CTRL

// PORTF - Port F
#define PORTF_DIR PORTF.DIR
#define PORTF_DIRSET PORTF.DIRSET
#define PORTF_DIRCLR PORTF.DIRCLR
#define PORTF_DIRTGL PORTF.DIRTGL
#define PORTF_OUT PORTF.OUT
#define PORTF_OUTSET PORTF.OUTSET
#define PORTF_OUTCLR PORTF.OUTCLR
#define PORTF_OUTTGL PORTF.OUTTGL
#define PORTF_IN PORTF.IN
#define PORTF_INTCTRL PORTF.INTCTRL
#define PORTF_INT0MASK PORTF.INT0MASK
#define PORTF_INT1MASK PORTF.INT1MASK
#define PORTF_INTFLAGS PORTF.INTFLAGS
#define PORTF_PIN0CTRL PORTF.PIN0CTRL
#define PORTF_PIN1CTRL PORTF.PIN1CTRL
#define PORTF_PIN2CTRL PORTF.PIN2CTRL
#define PORTF_PIN3CTRL PORTF.PIN3CTRL
#define PORTF_PIN4CTRL PORTF.PIN4CTRL
#define PORTF_PIN5CTRL PORTF.PIN5CTRL
#define PORTF_PIN6CTRL PORTF.PIN6CTRL
#define PORTF_PIN7CTRL PORTF.PIN7CTRL

// PORTH - Port H
#define PORTH_DIR PORTH.DIR
#define PORTH_DIRSET PORTH.DIRSET
#define PORTH_DIRCLR PORTH.DIRCLR
#define PORTH_DIRTGL PORTH.DIRTGL
#define PORTH_OUT PORTH.OUT
#define PORTH_OUTSET PORTH.OUTSET
#define PORTH_OUTCLR PORTH.OUTCLR
#define PORTH_OUTTGL PORTH.OUTTGL
#define PORTH_IN PORTH.IN
#define PORTH_INTCTRL PORTH.INTCTRL
#define PORTH_INT0MASK PORTH.INT0MASK
#define PORTH_INT1MASK PORTH.INT1MASK
#define PORTH_INTFLAGS PORTH.INTFLAGS
#define PORTH_PIN0CTRL PORTH.PIN0CTRL
#define PORTH_PIN1CTRL PORTH.PIN1CTRL
#define PORTH_PIN2CTRL PORTH.PIN2CTRL
#define PORTH_PIN3CTRL PORTH.PIN3CTRL
#define PORTH_PIN4CTRL PORTH.PIN4CTRL
#define PORTH_PIN5CTRL PORTH.PIN5CTRL
#define PORTH_PIN6CTRL PORTH.PIN6CTRL
#define PORTH_PIN7CTRL PORTH.PIN7CTRL

// PORTJ - Port J
#define PORTJ_DIR PORTJ.DIR
#define PORTJ_DIRSET PORTJ.DIRSET
#define PORTJ_DIRCLR PORTJ.DIRCLR
#define PORTJ_DIRTGL PORTJ.DIRTGL
#define PORTJ_OUT PORTJ.OUT
#define PORTJ_OUTSET PORTJ.OUTSET
#define PORTJ_OUTCLR PORTJ.OUTCLR
#define PORTJ_OUTTGL PORTJ.OUTTGL
#define PORTJ_IN PORTJ.IN
#define PORTJ_INTCTRL PORTJ.INTCTRL
#define PORTJ_INT0MASK PORTJ.INT0MASK
#define PORTJ_INT1MASK PORTJ.INT1MASK
#define PORTJ_INTFLAGS PORTJ.INTFLAGS
#define PORTJ_PIN0CTRL PORTJ.PIN0CTRL
#define PORTJ_PIN1CTRL PORTJ.PIN1CTRL
#define PORTJ_PIN2CTRL PORTJ.PIN2CTRL
#define PORTJ_PIN3CTRL PORTJ.PIN3CTRL
#define PORTJ_PIN4CTRL PORTJ.PIN4CTRL
#define PORTJ_PIN5CTRL PORTJ.PIN5CTRL
#define PORTJ_PIN6CTRL PORTJ.PIN6CTRL
#define PORTJ_PIN7CTRL PORTJ.PIN7CTRL

// PORTK - Port K
#define PORTK_DIR PORTK.DIR
#define PORTK_DIRSET PORTK.DIRSET
#define PORTK_DIRCLR PORTK.DIRCLR
#define PORTK_DIRTGL PORTK.DIRTGL
#define PORTK_OUT PORTK.OUT
#define PORTK_OUTSET PORTK.OUTSET
#define PORTK_OUTCLR PORTK.OUTCLR
#define PORTK_OUTTGL PORTK.OUTTGL
#define PORTK_IN PORTK.IN
#define PORTK_INTCTRL PORTK.INTCTRL
#define PORTK_INT0MASK PORTK.INT0MASK
#define PORTK_INT1MASK PORTK.INT1MASK
#define PORTK_INTFLAGS PORTK.INTFLAGS
#define PORTK_PIN0CTRL PORTK.PIN0CTRL
#define PORTK_PIN1CTRL PORTK.PIN1CTRL
#define PORTK_PIN2CTRL PORTK.PIN2CTRL
#define PORTK_PIN3CTRL PORTK.PIN3CTRL
#define PORTK_PIN4CTRL PORTK.PIN4CTRL
#define PORTK_PIN5CTRL PORTK.PIN5CTRL
#define PORTK_PIN6CTRL PORTK.PIN6CTRL
#define PORTK_PIN7CTRL PORTK.PIN7CTRL

// PORTQ - Port Q
#define PORTQ_DIR PORTQ.DIR
#define PORTQ_DIRSET PORTQ.DIRSET
#define PORTQ_DIRCLR PORTQ.DIRCLR
#define PORTQ_DIRTGL PORTQ.DIRTGL
#define PORTQ_OUT PORTQ.OUT
#define PORTQ_OUTSET PORTQ.OUTSET
#define PORTQ_OUTCLR PORTQ.OUTCLR
#define PORTQ_OUTTGL PORTQ.OUTTGL
#define PORTQ_IN PORTQ.IN
#define PORTQ_INTCTRL PORTQ.INTCTRL
#define PORTQ_INT0MASK PORTQ.INT0MASK
#define PORTQ_INT1MASK PORTQ.INT1MASK
#define PORTQ_INTFLAGS PORTQ.INTFLAGS
#define PORTQ_PIN0CTRL PORTQ.PIN0CTRL
#define PORTQ_PIN1CTRL PORTQ.PIN1CTRL
#define PORTQ_PIN2CTRL PORTQ.PIN2CTRL
#define PORTQ_PIN3CTRL PORTQ.PIN3CTRL
#define PORTQ_PIN4CTRL PORTQ.PIN4CTRL
#define PORTQ_PIN5CTRL PORTQ.PIN5CTRL
#define PORTQ_PIN6CTRL PORTQ.PIN6CTRL
#define PORTQ_PIN7CTRL PORTQ.PIN7CTRL

// PORTR - Port R
#define PORTR_DIR PORTR.DIR
#define PORTR_DIRSET PORTR.DIRSET
#define PORTR_DIRCLR PORTR.DIRCLR
#define PORTR_DIRTGL PORTR.DIRTGL
#define PORTR_OUT PORTR.OUT
#define PORTR_OUTSET PORTR.OUTSET
#define PORTR_OUTCLR PORTR.OUTCLR
#define PORTR_OUTTGL PORTR.OUTTGL
#define PORTR_IN PORTR.IN
#define PORTR_INTCTRL PORTR.INTCTRL
#define PORTR_INT0MASK PORTR.INT0MASK
#define PORTR_INT1MASK PORTR.INT1MASK
#define PORTR_INTFLAGS PORTR.INTFLAGS
#define PORTR_PIN0CTRL PORTR.PIN0CTRL
#define PORTR_PIN1CTRL PORTR.PIN1CTRL
#define PORTR_PIN2CTRL PORTR.PIN2CTRL
#define PORTR_PIN3CTRL PORTR.PIN3CTRL
#define PORTR_PIN4CTRL PORTR.PIN4CTRL
#define PORTR_PIN5CTRL PORTR.PIN5CTRL
#define PORTR_PIN6CTRL PORTR.PIN6CTRL
#define PORTR_PIN7CTRL PORTR.PIN7CTRL

// TCC0 - 16-bit Timer/Counter With PWM C0
#define TCC0_CTRLA TCC0.CTRLA
#define TCC0_CTRLB TCC0.CTRLB
#define TCC0_CTRLC TCC0.CTRLC
#define TCC0_CTRLD TCC0.CTRLD
#define TCC0_CTRLE TCC0.CTRLE
#define TCC0_INTCTRLA TCC0.INTCTRLA
#define TCC0_INTCTRLB TCC0.INTCTRLB
#define TCC0_CTRLFCLR TCC0.CTRLFCLR
#define TCC0_CTRLFSET TCC0.CTRLFSET
#define TCC0_CTRLGCLR TCC0.CTRLGCLR
#define TCC0_CTRLGSET TCC0.CTRLGSET
#define TCC0_INTFLAGS TCC0.INTFLAGS
#define TCC0_TEMP TCC0.TEMP
#define TCC0_CNT TCC0.CNT
#define TCC0_PER TCC0.PER
#define TCC0_CCA TCC0.CCA
#define TCC0_CCB TCC0.CCB
#define TCC0_CCC TCC0.CCC
#define TCC0_CCD TCC0.CCD
#define TCC0_PERBUF TCC0.PERBUF
#define TCC0_CCABUF TCC0.CCABUF
#define TCC0_CCBBUF TCC0.CCBBUF
#define TCC0_CCCBUF TCC0.CCCBUF
#define TCC0_CCDBUF TCC0.CCDBUF

// TCC1 - 16-bit Timer/Counter With PWM C1
#define TCC1_CTRLA TCC1.CTRLA
#define TCC1_CTRLB TCC1.CTRLB
#define TCC1_CTRLC TCC1.CTRLC
#define TCC1_CTRLD TCC1.CTRLD
#define TCC1_CTRLE TCC1.CTRLE
#define TCC1_INTCTRLA TCC1.INTCTRLA
#define TCC1_INTCTRLB TCC1.INTCTRLB
#define TCC1_CTRLFCLR TCC1.CTRLFCLR
#define TCC1_CTRLFSET TCC1.CTRLFSET
#define TCC1_CTRLGCLR TCC1.CTRLGCLR
#define TCC1_CTRLGSET TCC1.CTRLGSET
#define TCC1_INTFLAGS TCC1.INTFLAGS
#define TCC1_TEMP TCC1.TEMP
#define TCC1_CNT TCC1.CNT
#define TCC1_PER TCC1.PER
#define TCC1_CCA TCC1.CCA
#define TCC1_CCB TCC1.CCB
#define TCC1_PERBUF TCC1.PERBUF
#define TCC1_CCABUF TCC1.CCABUF
#define TCC1_CCBBUF TCC1.CCBBUF

// AWEXC - Advanced Waveform Extension C
#define AWEXC_CTRL AWEXC.CTRL
#define AWEXC_FDEVMASK AWEXC.FDEVMASK
#define AWEXC_DFCTRL AWEXC.DFCTRL
#define AWEXC_STATUS AWEXC.STATUS
#define AWEXC_DTBOTH AWEXC.DTBOTH
#define AWEXC_DTBOTHBUF AWEXC.DTBOTHBUF
#define AWEXC_DTLS AWEXC.DTLS
#define AWEXC_DTHS AWEXC.DTHS
#define AWEXC_DTLSBUF AWEXC.DTLSBUF
#define AWEXC_DTHSBUF AWEXC.DTHSBUF
#define AWEXC_OUTOVEN AWEXC.OUTOVEN

// HIRESC - High-Resolution PWM C
#define HIRESC_CTRL HIRESC.CTRL

// USARTC0 - Universal Asynchronous Receiver-Transmitter C0
#define USARTC0_DATA USARTC0.DATA
#define USARTC0_STATUS USARTC0.STATUS
#define USARTC0_CTRLA USARTC0.CTRLA
#define USARTC0_CTRLB USARTC0.CTRLB
#define USARTC0_CTRLC USARTC0.CTRLC
#define USARTC0_BAUDCTRLA USARTC0.BAUDCTRLA
#define USARTC0_BAUDCTRLB USARTC0.BAUDCTRLB

// USARTC1 - Universal Asynchronous Receiver-Transmitter C1
#define USARTC1_DATA USARTC1.DATA
#define USARTC1_STATUS USARTC1.STATUS
#define USARTC1_CTRLA USARTC1.CTRLA
#define USARTC1_CTRLB USARTC1.CTRLB
#define USARTC1_CTRLC USARTC1.CTRLC
#define USARTC1_BAUDCTRLA USARTC1.BAUDCTRLA
#define USARTC1_BAUDCTRLB USARTC1.BAUDCTRLB

// SPIC - Serial Peripheral Interface C
#define SPIC_CTRL SPIC.CTRL
#define SPIC_INTCTRL SPIC.INTCTRL
#define SPIC_STATUS SPIC.STATUS
#define SPIC_DATA SPIC.DATA

// TCD0 - 16-bit Timer/Counter With PWM D0
#define TCD0_CTRLA TCD0.CTRLA
#define TCD0_CTRLB TCD0.CTRLB
#define TCD0_CTRLC TCD0.CTRLC
#define TCD0_CTRLD TCD0.CTRLD
#define TCD0_CTRLE TCD0.CTRLE
#define TCD0_INTCTRLA TCD0.INTCTRLA
#define TCD0_INTCTRLB TCD0.INTCTRLB
#define TCD0_CTRLFCLR TCD0.CTRLFCLR
#define TCD0_CTRLFSET TCD0.CTRLFSET
#define TCD0_CTRLGCLR TCD0.CTRLGCLR
#define TCD0_CTRLGSET TCD0.CTRLGSET
#define TCD0_INTFLAGS TCD0.INTFLAGS
#define TCD0_TEMP TCD0.TEMP
#define TCD0_CNT TCD0.CNT
#define TCD0_PER TCD0.PER
#define TCD0_CCA TCD0.CCA
#define TCD0_CCB TCD0.CCB
#define TCD0_CCC TCD0.CCC
#define TCD0_CCD TCD0.CCD
#define TCD0_PERBUF TCD0.PERBUF
#define TCD0_CCABUF TCD0.CCABUF
#define TCD0_CCBBUF TCD0.CCBBUF
#define TCD0_CCCBUF TCD0.CCCBUF
#define TCD0_CCDBUF TCD0.CCDBUF

// TCD1 - 16-bit Timer/Counter With PWM D1
#define TCD1_CTRLA TCD1.CTRLA
#define TCD1_CTRLB TCD1.CTRLB
#define TCD1_CTRLC TCD1.CTRLC
#define TCD1_CTRLD TCD1.CTRLD
#define TCD1_CTRLE TCD1.CTRLE
#define TCD1_INTCTRLA TCD1.INTCTRLA
#define TCD1_INTCTRLB TCD1.INTCTRLB
#define TCD1_CTRLFCLR TCD1.CTRLFCLR
#define TCD1_CTRLFSET TCD1.CTRLFSET
#define TCD1_CTRLGCLR TCD1.CTRLGCLR
#define TCD1_CTRLGSET TCD1.CTRLGSET
#define TCD1_INTFLAGS TCD1.INTFLAGS
#define TCD1_TEMP TCD1.TEMP
#define TCD1_CNT TCD1.CNT
#define TCD1_PER TCD1.PER
#define TCD1_CCA TCD1.CCA
#define TCD1_CCB TCD1.CCB
#define TCD1_PERBUF TCD1.PERBUF
#define TCD1_CCABUF TCD1.CCABUF
#define TCD1_CCBBUF TCD1.CCBBUF

// HIRESD - High-Resolution PWM D
#define HIRESD_CTRL HIRESD.CTRL

// USARTD0 - Universal Asynchronous Receiver-Transmitter D0
#define USARTD0_DATA USARTD0.DATA
#define USARTD0_STATUS USARTD0.STATUS
#define USARTD0_CTRLA USARTD0.CTRLA
#define USARTD0_CTRLB USARTD0.CTRLB
#define USARTD0_CTRLC USARTD0.CTRLC
#define USARTD0_BAUDCTRLA USARTD0.BAUDCTRLA
#define USARTD0_BAUDCTRLB USARTD0.BAUDCTRLB

// USARTD1 - Universal Asynchronous Receiver-Transmitter D1
#define USARTD1_DATA USARTD1.DATA
#define USARTD1_STATUS USARTD1.STATUS
#define USARTD1_CTRLA USARTD1.CTRLA
#define USARTD1_CTRLB USARTD1.CTRLB
#define USARTD1_CTRLC USARTD1.CTRLC
#define USARTD1_BAUDCTRLA USARTD1.BAUDCTRLA
#define USARTD1_BAUDCTRLB USARTD1.BAUDCTRLB

// SPID - Serial Peripheral Interface D
#define SPID_CTRL SPID.CTRL
#define SPID_INTCTRL SPID.INTCTRL
#define SPID_STATUS SPID.STATUS
#define SPID_DATA SPID.DATA

// TCE0 - 16-bit Timer/Counter With PWM E0
#define TCE0_CTRLA TCE0.CTRLA
#define TCE0_CTRLB TCE0.CTRLB
#define TCE0_CTRLC TCE0.CTRLC
#define TCE0_CTRLD TCE0.CTRLD
#define TCE0_CTRLE TCE0.CTRLE
#define TCE0_INTCTRLA TCE0.INTCTRLA
#define TCE0_INTCTRLB TCE0.INTCTRLB
#define TCE0_CTRLFCLR TCE0.CTRLFCLR
#define TCE0_CTRLFSET TCE0.CTRLFSET
#define TCE0_CTRLGCLR TCE0.CTRLGCLR
#define TCE0_CTRLGSET TCE0.CTRLGSET
#define TCE0_INTFLAGS TCE0.INTFLAGS
#define TCE0_TEMP TCE0.TEMP
#define TCE0_CNT TCE0.CNT
#define TCE0_PER TCE0.PER
#define TCE0_CCA TCE0.CCA
#define TCE0_CCB TCE0.CCB
#define TCE0_CCC TCE0.CCC
#define TCE0_CCD TCE0.CCD
#define TCE0_PERBUF TCE0.PERBUF
#define TCE0_CCABUF TCE0.CCABUF
#define TCE0_CCBBUF TCE0.CCBBUF
#define TCE0_CCCBUF TCE0.CCCBUF
#define TCE0_CCDBUF TCE0.CCDBUF

// TCE1 - 16-bit Timer/Counter With PWM E1
#define TCE1_CTRLA TCE1.CTRLA
#define TCE1_CTRLB TCE1.CTRLB
#define TCE1_CTRLC TCE1.CTRLC
#define TCE1_CTRLD TCE1.CTRLD
#define TCE1_CTRLE TCE1.CTRLE
#define TCE1_INTCTRLA TCE1.INTCTRLA
#define TCE1_INTCTRLB TCE1.INTCTRLB
#define TCE1_CTRLFCLR TCE1.CTRLFCLR
#define TCE1_CTRLFSET TCE1.CTRLFSET
#define TCE1_CTRLGCLR TCE1.CTRLGCLR
#define TCE1_CTRLGSET TCE1.CTRLGSET
#define TCE1_INTFLAGS TCE1.INTFLAGS
#define TCE1_TEMP TCE1.TEMP
#define TCE1_CNT TCE1.CNT
#define TCE1_PER TCE1.PER
#define TCE1_CCA TCE1.CCA
#define TCE1_CCB TCE1.CCB
#define TCE1_PERBUF TCE1.PERBUF
#define TCE1_CCABUF TCE1.CCABUF
#define TCE1_CCBBUF TCE1.CCBBUF

// AWEXE - Advanced Waveform Extension E
#define AWEXE_CTRL AWEXE.CTRL
#define AWEXE_FDEVMASK AWEXE.FDEVMASK
#define AWEXE_DFCTRL AWEXE.DFCTRL
#define AWEXE_STATUS AWEXE.STATUS
#define AWEXE_DTBOTH AWEXE.DTBOTH
#define AWEXE_DTBOTHBUF AWEXE.DTBOTHBUF
#define AWEXE_DTLS AWEXE.DTLS
#define AWEXE_DTHS AWEXE.DTHS
#define AWEXE_DTLSBUF AWEXE.DTLSBUF
#define AWEXE_DTHSBUF AWEXE.DTHSBUF
#define AWEXE_OUTOVEN AWEXE.OUTOVEN

// HIRESE - High-Resolution PWM E
#define HIRESE_CTRL HIRESE.CTRL

// USARTE0 - Universal Asynchronous Receiver-Transmitter E0
#define USARTE0_DATA USARTE0.DATA
#define USARTE0_STATUS USARTE0.STATUS
#define USARTE0_CTRLA USARTE0.CTRLA
#define USARTE0_CTRLB USARTE0.CTRLB
#define USARTE0_CTRLC USARTE0.CTRLC
#define USARTE0_BAUDCTRLA USARTE0.BAUDCTRLA
#define USARTE0_BAUDCTRLB USARTE0.BAUDCTRLB

// USARTE1 - Universal Asynchronous Receiver-Transmitter E1
#define USARTE1_DATA USARTE1.DATA
#define USARTE1_STATUS USARTE1.STATUS
#define USARTE1_CTRLA USARTE1.CTRLA
#define USARTE1_CTRLB USARTE1.CTRLB
#define USARTE1_CTRLC USARTE1.CTRLC
#define USARTE1_BAUDCTRLA USARTE1.BAUDCTRLA
#define USARTE1_BAUDCTRLB USARTE1.BAUDCTRLB

// SPIE - Serial Peripheral Interface E
#define SPIE_CTRL SPIE.CTRL
#define SPIE_INTCTRL SPIE.INTCTRL
#define SPIE_STATUS SPIE.STATUS
#define SPIE_DATA SPIE.DATA

// TCF0 - 16-bit Timer/Counter With PWM F0
#define TCF0_CTRLA TCF0.CTRLA
#define TCF0_CTRLB TCF0.CTRLB
#define TCF0_CTRLC TCF0.CTRLC
#define TCF0_CTRLD TCF0.CTRLD
#define TCF0_CTRLE TCF0.CTRLE
#define TCF0_INTCTRLA TCF0.INTCTRLA
#define TCF0_INTCTRLB TCF0.INTCTRLB
#define TCF0_CTRLFCLR TCF0.CTRLFCLR
#define TCF0_CTRLFSET TCF0.CTRLFSET
#define TCF0_CTRLGCLR TCF0.CTRLGCLR
#define TCF0_CTRLGSET TCF0.CTRLGSET
#define TCF0_INTFLAGS TCF0.INTFLAGS
#define TCF0_TEMP TCF0.TEMP
#define TCF0_CNT TCF0.CNT
#define TCF0_PER TCF0.PER
#define TCF0_CCA TCF0.CCA
#define TCF0_CCB TCF0.CCB
#define TCF0_CCC TCF0.CCC
#define TCF0_CCD TCF0.CCD
#define TCF0_PERBUF TCF0.PERBUF
#define TCF0_CCABUF TCF0.CCABUF
#define TCF0_CCBBUF TCF0.CCBBUF
#define TCF0_CCCBUF TCF0.CCCBUF
#define TCF0_CCDBUF TCF0.CCDBUF

// TCF1 - 16-bit Timer/Counter With PWM F1
#define TCF1_CTRLA TCF1.CTRLA
#define TCF1_CTRLB TCF1.CTRLB
#define TCF1_CTRLC TCF1.CTRLC
#define TCF1_CTRLD TCF1.CTRLD
#define TCF1_CTRLE TCF1.CTRLE
#define TCF1_INTCTRLA TCF1.INTCTRLA
#define TCF1_INTCTRLB TCF1.INTCTRLB
#define TCF1_CTRLFCLR TCF1.CTRLFCLR
#define TCF1_CTRLFSET TCF1.CTRLFSET
#define TCF1_CTRLGCLR TCF1.CTRLGCLR
#define TCF1_CTRLGSET TCF1.CTRLGSET
#define TCF1_INTFLAGS TCF1.INTFLAGS
#define TCF1_TEMP TCF1.TEMP
#define TCF1_CNT TCF1.CNT
#define TCF1_PER TCF1.PER
#define TCF1_CCA TCF1.CCA
#define TCF1_CCB TCF1.CCB
#define TCF1_PERBUF TCF1.PERBUF
#define TCF1_CCABUF TCF1.CCABUF
#define TCF1_CCBBUF TCF1.CCBBUF

// HIRESF - High-Resolution PWM F
#define HIRESF_CTRL HIRESF.CTRL

// USARTF0 - Universal Asynchronous Receiver-Transmitter F0
#define USARTF0_DATA USARTF0.DATA
#define USARTF0_STATUS USARTF0.STATUS
#define USARTF0_CTRLA USARTF0.CTRLA
#define USARTF0_CTRLB USARTF0.CTRLB
#define USARTF0_CTRLC USARTF0.CTRLC
#define USARTF0_BAUDCTRLA USARTF0.BAUDCTRLA
#define USARTF0_BAUDCTRLB USARTF0.BAUDCTRLB

// USARTF1 - Universal Asynchronous Receiver-Transmitter F1
#define USARTF1_DATA USARTF1.DATA
#define USARTF1_STATUS USARTF1.STATUS
#define USARTF1_CTRLA USARTF1.CTRLA
#define USARTF1_CTRLB USARTF1.CTRLB
#define USARTF1_CTRLC USARTF1.CTRLC
#define USARTF1_BAUDCTRLA USARTF1.BAUDCTRLA
#define USARTF1_BAUDCTRLB USARTF1.BAUDCTRLB

// SPIF - Serial Peripheral Interface F
#define SPIF_CTRL SPIF.CTRL
#define SPIF_INTCTRL SPIF.INTCTRL
#define SPIF_STATUS SPIF.STATUS
#define SPIF_DATA SPIF.DATA

// IRCOM - IR Communication Module
#define IRCOM_TXPLCTRL IRCOM.TXPLCTRL
#define IRCOM_RXPLCTRL IRCOM.RXPLCTRL
#define IRCOM_CTRL IRCOM.CTRL

// AES - AES Crypto Module
#define AES_CTRL AES.CTRL
#define AES_STATUS AES.STATUS
#define AES_STATE AES.STATE
#define AES_KEY AES.KEY
#define AES_INTCTRL AES.INTCTRL

#endif /* !defined (__ASSEMBLER__) */


/* ========== Flattened fully qualified IO register names ========== */

/* GPIO - General Purpose IO Registers */
#define GPIO_GPIO0 _SFR_MEM8(0)
#define GPIO_GPIO1 _SFR_MEM8(1)
#define GPIO_GPIO2 _SFR_MEM8(2)
#define GPIO_GPIO3 _SFR_MEM8(3)
#define GPIO_GPIO4 _SFR_MEM8(4)
#define GPIO_GPIO5 _SFR_MEM8(5)
#define GPIO_GPIO6 _SFR_MEM8(6)
#define GPIO_GPIO7 _SFR_MEM8(7)
#define GPIO_GPIO8 _SFR_MEM8(8)
#define GPIO_GPIO9 _SFR_MEM8(9)
#define GPIO_GPIOA _SFR_MEM8(10)
#define GPIO_GPIOB _SFR_MEM8(11)
#define GPIO_GPIOC _SFR_MEM8(12)
#define GPIO_GPIOD _SFR_MEM8(13)
#define GPIO_GPIOE _SFR_MEM8(14)
#define GPIO_GPIOF _SFR_MEM8(15)

/* OCD - On-Chip Debug System */
#define OCD_OCDR0 _SFR_MEM8(46)
#define OCD_OCDR1 _SFR_MEM8(47)

/* CPU - CPU Registers */
#define CPU_CCP _SFR_MEM8(52)
#define CPU_RAMPD _SFR_MEM8(56)
#define CPU_RAMPX _SFR_MEM8(57)
#define CPU_RAMPY _SFR_MEM8(58)
#define CPU_RAMPZ _SFR_MEM8(59)
#define CPU_EIND _SFR_MEM8(60)
#define CPU_SPL _SFR_MEM8(61)
#define CPU_SPH _SFR_MEM8(62)
#define CPU_SREG _SFR_MEM8(63)

/* CLK - Clock System */
#define CLK_CTRL _SFR_MEM8(64)
#define CLK_PSCTRL _SFR_MEM8(65)
#define CLK_LOCK _SFR_MEM8(66)
#define CLK_RTCCTRL _SFR_MEM8(67)

/* SLEEP - Sleep Controller */
#define SLEEP_CTRL _SFR_MEM8(72)

/* OSC - Oscillator */
#define OSC_CTRL _SFR_MEM8(80)
#define OSC_STATUS _SFR_MEM8(81)
#define OSC_XOSCCTRL _SFR_MEM8(82)
#define OSC_XOSCFAIL _SFR_MEM8(83)
#define OSC_RC32KCAL _SFR_MEM8(84)
#define OSC_PLLCTRL _SFR_MEM8(85)
#define OSC_DFLLCTRL _SFR_MEM8(86)

/* DFLLRC32M - DFLL for 32MHz Clock */
#define DFLLRC32M_OSCCNT0 _SFR_MEM8(96)
#define DFLLRC32M_OSCCNT1 _SFR_MEM8(97)
#define DFLLRC32M_OSCCNT2 _SFR_MEM8(98)
#define DFLLRC32M_CALA _SFR_MEM8(99)
#define DFLLRC32M_CALB _SFR_MEM8(100)

/* DFLLRC2M - DFLL for 2MHz Internal RC */
#define DFLLRC2M_OSCCNT0 _SFR_MEM8(104)
#define DFLLRC2M_OSCCNT1 _SFR_MEM8(105)
#define DFLLRC2M_OSCCNT2 _SFR_MEM8(106)
#define DFLLRC2M_CALA _SFR_MEM8(107)
#define DFLLRC2M_CALB _SFR_MEM8(108)

/* PR - Power Reduction */
#define PR_PR _SFR_MEM8(112)
#define PR_PRPA _SFR_MEM8(113)
#define PR_PRPB _SFR_MEM8(114)
#define PR_PRPC _SFR_MEM8(115)
#define PR_PRPD _SFR_MEM8(116)
#define PR_PRPE _SFR_MEM8(117)
#define PR_PRPF _SFR_MEM8(118)

/* RST - Reset Controller */
#define RST_STATUS _SFR_MEM8(120)
#define RST_CTRL _SFR_MEM8(121)

/* WDT - Watch-Dog Timer */
#define WDT_CTRL _SFR_MEM8(128)
#define WDT_WINCTRL _SFR_MEM8(129)
#define WDT_STATUS _SFR_MEM8(130)

/* MCU - MCU Revision */
#define MCU_DEVID0 _SFR_MEM8(144)
#define MCU_DEVID1 _SFR_MEM8(145)
#define MCU_DEVID2 _SFR_MEM8(146)
#define MCU_REVID _SFR_MEM8(147)
#define MCU_JTAGUID _SFR_MEM8(148)
#define MCU_MCUCR _SFR_MEM8(150)
#define MCU_EVSYSLOCK _SFR_MEM8(152)
#define MCU_AWEXLOCK _SFR_MEM8(153)

/* PMIC - Programmable Interrupt Controller */
#define PMIC_STATUS _SFR_MEM8(160)
#define PMIC_INTPRI _SFR_MEM8(161)
#define PMIC_CTRL _SFR_MEM8(162)

/* DMA - DMA Controller */
#define DMA_CTRL _SFR_MEM8(256)
#define DMA_INTFLAGS _SFR_MEM8(259)
#define DMA_STATUS _SFR_MEM8(260)

/* EVSYS - Event System */
#define EVSYS_CH0MUX _SFR_MEM8(384)
#define EVSYS_CH1MUX _SFR_MEM8(385)
#define EVSYS_CH2MUX _SFR_MEM8(386)
#define EVSYS_CH3MUX _SFR_MEM8(387)
#define EVSYS_CH4MUX _SFR_MEM8(388)
#define EVSYS_CH5MUX _SFR_MEM8(389)
#define EVSYS_CH6MUX _SFR_MEM8(390)
#define EVSYS_CH7MUX _SFR_MEM8(391)
#define EVSYS_CH0CTRL _SFR_MEM8(392)
#define EVSYS_CH1CTRL _SFR_MEM8(393)
#define EVSYS_CH2CTRL _SFR_MEM8(394)
#define EVSYS_CH3CTRL _SFR_MEM8(395)
#define EVSYS_CH4CTRL _SFR_MEM8(396)
#define EVSYS_CH5CTRL _SFR_MEM8(397)
#define EVSYS_CH6CTRL _SFR_MEM8(398)
#define EVSYS_CH7CTRL _SFR_MEM8(399)
#define EVSYS_STROBE _SFR_MEM8(400)
#define EVSYS_DATA _SFR_MEM8(401)

/* NVM - Non Volatile Memory */
#define NVM_ADDR0 _SFR_MEM8(448)
#define NVM_ADDR1 _SFR_MEM8(449)
#define NVM_ADDR2 _SFR_MEM8(450)
#define NVM_DATA0 _SFR_MEM8(452)
#define NVM_DATA1 _SFR_MEM8(453)
#define NVM_DATA2 _SFR_MEM8(454)
#define NVM_CMD _SFR_MEM8(458)
#define NVM_CTRLA _SFR_MEM8(459)
#define NVM_CTRLB _SFR_MEM8(460)
#define NVM_INTCTRL _SFR_MEM8(461)
#define NVM_STATUS _SFR_MEM8(463)
#define NVM_LOCKBITS _SFR_MEM8(464)

/* ACA - Analog Comparator A */
#define ACA_AC0CTRL _SFR_MEM8(896)
#define ACA_AC1CTRL _SFR_MEM8(897)
#define ACA_AC0MUXCTRL _SFR_MEM8(898)
#define ACA_AC1MUXCTRL _SFR_MEM8(899)
#define ACA_CTRLA _SFR_MEM8(900)
#define ACA_CTRLB _SFR_MEM8(901)
#define ACA_WINCTRL _SFR_MEM8(902)
#define ACA_STATUS _SFR_MEM8(903)

/* ACB - Analog Comparator B */
#define ACB_AC0CTRL _SFR_MEM8(912)
#define ACB_AC1CTRL _SFR_MEM8(913)
#define ACB_AC0MUXCTRL _SFR_MEM8(914)
#define ACB_AC1MUXCTRL _SFR_MEM8(915)
#define ACB_CTRLA _SFR_MEM8(916)
#define ACB_CTRLB _SFR_MEM8(917)
#define ACB_WINCTRL _SFR_MEM8(918)
#define ACB_STATUS _SFR_MEM8(919)

/* ADCA - Analog/Digital Converter A */
#define ADCA_CTRLA _SFR_MEM8(512)
#define ADCA_CTRLB _SFR_MEM8(513)
#define ADCA_REFCTRL _SFR_MEM8(514)
#define ADCA_EVCTRL _SFR_MEM8(515)
#define ADCA_PRESCALER _SFR_MEM8(516)
#define ADCA_CALCTRL _SFR_MEM8(517)
#define ADCA_INTFLAGS _SFR_MEM8(518)
#define ADCA_CALIB _SFR_MEM8(524)
#define ADCA_CH0RES _SFR_MEM16(528)
#define ADCA_CH1RES _SFR_MEM16(530)
#define ADCA_CH2RES _SFR_MEM16(532)
#define ADCA_CH3RES _SFR_MEM16(534)
#define ADCA_CMP _SFR_MEM16(536)

/* ADCB - Analog/Digital Converter B */
#define ADCB_CTRLA _SFR_MEM8(576)
#define ADCB_CTRLB _SFR_MEM8(577)
#define ADCB_REFCTRL _SFR_MEM8(578)
#define ADCB_EVCTRL _SFR_MEM8(579)
#define ADCB_PRESCALER _SFR_MEM8(580)
#define ADCB_CALCTRL _SFR_MEM8(581)
#define ADCB_INTFLAGS _SFR_MEM8(582)
#define ADCB_CALIB _SFR_MEM8(588)
#define ADCB_CH0RES _SFR_MEM16(592)
#define ADCB_CH1RES _SFR_MEM16(594)
#define ADCB_CH2RES _SFR_MEM16(596)
#define ADCB_CH3RES _SFR_MEM16(598)
#define ADCB_CMP _SFR_MEM16(600)

/* DACA - Digital/Analog Converter A */
#define DACA_CTRLA _SFR_MEM8(768)
#define DACA_CTRLB _SFR_MEM8(769)
#define DACA_CTRLC _SFR_MEM8(770)
#define DACA_EVCTRL _SFR_MEM8(771)
#define DACA_TIMCTRL _SFR_MEM8(772)
#define DACA_STATUS _SFR_MEM8(773)
#define DACA_GAINCAL _SFR_MEM8(776)
#define DACA_OFFSETCAL _SFR_MEM8(777)
#define DACA_CH0DATA _SFR_MEM16(792)
#define DACA_CH1DATA _SFR_MEM16(794)

/* DACB - Digital/Analog Converter B */
#define DACB_CTRLA _SFR_MEM8(800)
#define DACB_CTRLB _SFR_MEM8(801)
#define DACB_CTRLC _SFR_MEM8(802)
#define DACB_EVCTRL _SFR_MEM8(803)
#define DACB_TIMCTRL _SFR_MEM8(804)
#define DACB_STATUS _SFR_MEM8(805)
#define DACB_GAINCAL _SFR_MEM8(808)
#define DACB_OFFSETCAL _SFR_MEM8(809)
#define DACB_CH0DATA _SFR_MEM16(824)
#define DACB_CH1DATA _SFR_MEM16(826)

/* RTC - Real-Time Clock */
#define RTC_CTRL _SFR_MEM8(1024)
#define RTC_STATUS _SFR_MEM8(1025)
#define RTC_INTCTRL _SFR_MEM8(1026)
#define RTC_INTFLAGS _SFR_MEM8(1027)
#define RTC_TEMP _SFR_MEM8(1028)
#define RTC_CNT _SFR_MEM16(1032)
#define RTC_PER _SFR_MEM16(1034)
#define RTC_COMP _SFR_MEM16(1036)

/* EBI - External Bus Interface */
#define EBI_CTRL _SFR_MEM8(1088)
#define EBI_SDRAMCTRLA _SFR_MEM8(1089)
#define EBI_REFRESH _SFR_MEM16(1092)
#define EBI_INITDLY _SFR_MEM16(1094)
#define EBI_SDRAMCTRLB _SFR_MEM8(1096)
#define EBI_SDRAMCTRLC _SFR_MEM8(1097)

/* TWIC - Two-Wire Interface C */
#define TWIC_CTRL _SFR_MEM8(1152)

/* TWID - Two-Wire Interface D */
#define TWID_CTRL _SFR_MEM8(1168)

/* TWIE - Two-Wire Interface E */
#define TWIE_CTRL _SFR_MEM8(1184)

/* TWIF - Two-Wire Interface F */
#define TWIF_CTRL _SFR_MEM8(1200)

/* PORTCFG - Port Configuration */
#define PORTCFG_MPCMASK _SFR_MEM8(176)
#define PORTCFG_VPCTRLA _SFR_MEM8(178)
#define PORTCFG_VPCTRLB _SFR_MEM8(179)
#define PORTCFG_CLKEVOUT _SFR_MEM8(180)

/* VPORT0 - Virtual Port 0 */
#define VPORT0_DIR _SFR_MEM8(16)
#define VPORT0_OUT _SFR_MEM8(17)
#define VPORT0_IN _SFR_MEM8(18)
#define VPORT0_INTFLAGS _SFR_MEM8(19)

/* VPORT1 - Virtual Port 1 */
#define VPORT1_DIR _SFR_MEM8(20)
#define VPORT1_OUT _SFR_MEM8(21)
#define VPORT1_IN _SFR_MEM8(22)
#define VPORT1_INTFLAGS _SFR_MEM8(23)

/* VPORT2 - Virtual Port 2 */
#define VPORT2_DIR _SFR_MEM8(24)
#define VPORT2_OUT _SFR_MEM8(25)
#define VPORT2_IN _SFR_MEM8(26)
#define VPORT2_INTFLAGS _SFR_MEM8(27)

/* VPORT3 - Virtual Port 3 */
#define VPORT3_DIR _SFR_MEM8(28)
#define VPORT3_OUT _SFR_MEM8(29)
#define VPORT3_IN _SFR_MEM8(30)
#define VPORT3_INTFLAGS _SFR_MEM8(31)

/* PORTA - Port A */
#define PORTA_DIR _SFR_MEM8(1536)
#define PORTA_DIRSET _SFR_MEM8(1537)
#define PORTA_DIRCLR _SFR_MEM8(1538)
#define PORTA_DIRTGL _SFR_MEM8(1539)
#define PORTA_OUT _SFR_MEM8(1540)
#define PORTA_OUTSET _SFR_MEM8(1541)
#define PORTA_OUTCLR _SFR_MEM8(1542)
#define PORTA_OUTTGL _SFR_MEM8(1543)
#define PORTA_IN _SFR_MEM8(1544)
#define PORTA_INTCTRL _SFR_MEM8(1545)
#define PORTA_INT0MASK _SFR_MEM8(1546)
#define PORTA_INT1MASK _SFR_MEM8(1547)
#define PORTA_INTFLAGS _SFR_MEM8(1548)
#define PORTA_PIN0CTRL _SFR_MEM8(1552)
#define PORTA_PIN1CTRL _SFR_MEM8(1553)
#define PORTA_PIN2CTRL _SFR_MEM8(1554)
#define PORTA_PIN3CTRL _SFR_MEM8(1555)
#define PORTA_PIN4CTRL _SFR_MEM8(1556)
#define PORTA_PIN5CTRL _SFR_MEM8(1557)
#define PORTA_PIN6CTRL _SFR_MEM8(1558)
#define PORTA_PIN7CTRL _SFR_MEM8(1559)

/* PORTB - Port B */
#define PORTB_DIR _SFR_MEM8(1568)
#define PORTB_DIRSET _SFR_MEM8(1569)
#define PORTB_DIRCLR _SFR_MEM8(1570)
#define PORTB_DIRTGL _SFR_MEM8(1571)
#define PORTB_OUT _SFR_MEM8(1572)
#define PORTB_OUTSET _SFR_MEM8(1573)
#define PORTB_OUTCLR _SFR_MEM8(1574)
#define PORTB_OUTTGL _SFR_MEM8(1575)
#define PORTB_IN _SFR_MEM8(1576)
#define PORTB_INTCTRL _SFR_MEM8(1577)
#define PORTB_INT0MASK _SFR_MEM8(1578)
#define PORTB_INT1MASK _SFR_MEM8(1579)
#define PORTB_INTFLAGS _SFR_MEM8(1580)
#define PORTB_PIN0CTRL _SFR_MEM8(1584)
#define PORTB_PIN1CTRL _SFR_MEM8(1585)
#define PORTB_PIN2CTRL _SFR_MEM8(1586)
#define PORTB_PIN3CTRL _SFR_MEM8(1587)
#define PORTB_PIN4CTRL _SFR_MEM8(1588)
#define PORTB_PIN5CTRL _SFR_MEM8(1589)
#define PORTB_PIN6CTRL _SFR_MEM8(1590)
#define PORTB_PIN7CTRL _SFR_MEM8(1591)

/* PORTC - Port C */
#define PORTC_DIR _SFR_MEM8(1600)
#define PORTC_DIRSET _SFR_MEM8(1601)
#define PORTC_DIRCLR _SFR_MEM8(1602)
#define PORTC_DIRTGL _SFR_MEM8(1603)
#define PORTC_OUT _SFR_MEM8(1604)
#define PORTC_OUTSET _SFR_MEM8(1605)
#define PORTC_OUTCLR _SFR_MEM8(1606)
#define PORTC_OUTTGL _SFR_MEM8(1607)
#define PORTC_IN _SFR_MEM8(1608)
#define PORTC_INTCTRL _SFR_MEM8(1609)
#define PORTC_INT0MASK _SFR_MEM8(1610)
#define PORTC_INT1MASK _SFR_MEM8(1611)
#define PORTC_INTFLAGS _SFR_MEM8(1612)
#define PORTC_PIN0CTRL _SFR_MEM8(1616)
#define PORTC_PIN1CTRL _SFR_MEM8(1617)
#define PORTC_PIN2CTRL _SFR_MEM8(1618)
#define PORTC_PIN3CTRL _SFR_MEM8(1619)
#define PORTC_PIN4CTRL _SFR_MEM8(1620)
#define PORTC_PIN5CTRL _SFR_MEM8(1621)
#define PORTC_PIN6CTRL _SFR_MEM8(1622)
#define PORTC_PIN7CTRL _SFR_MEM8(1623)

/* PORTD - Port D */
#define PORTD_DIR _SFR_MEM8(1632)
#define PORTD_DIRSET _SFR_MEM8(1633)
#define PORTD_DIRCLR _SFR_MEM8(1634)
#define PORTD_DIRTGL _SFR_MEM8(1635)
#define PORTD_OUT _SFR_MEM8(1636)
#define PORTD_OUTSET _SFR_MEM8(1637)
#define PORTD_OUTCLR _SFR_MEM8(1638)
#define PORTD_OUTTGL _SFR_MEM8(1639)
#define PORTD_IN _SFR_MEM8(1640)
#define PORTD_INTCTRL _SFR_MEM8(1641)
#define PORTD_INT0MASK _SFR_MEM8(1642)
#define PORTD_INT1MASK _SFR_MEM8(1643)
#define PORTD_INTFLAGS _SFR_MEM8(1644)
#define PORTD_PIN0CTRL _SFR_MEM8(1648)
#define PORTD_PIN1CTRL _SFR_MEM8(1649)
#define PORTD_PIN2CTRL _SFR_MEM8(1650)
#define PORTD_PIN3CTRL _SFR_MEM8(1651)
#define PORTD_PIN4CTRL _SFR_MEM8(1652)
#define PORTD_PIN5CTRL _SFR_MEM8(1653)
#define PORTD_PIN6CTRL _SFR_MEM8(1654)
#define PORTD_PIN7CTRL _SFR_MEM8(1655)

/* PORTE - Port E */
#define PORTE_DIR _SFR_MEM8(1664)
#define PORTE_DIRSET _SFR_MEM8(1665)
#define PORTE_DIRCLR _SFR_MEM8(1666)
#define PORTE_DIRTGL _SFR_MEM8(1667)
#define PORTE_OUT _SFR_MEM8(1668)
#define PORTE_OUTSET _SFR_MEM8(1669)
#define PORTE_OUTCLR _SFR_MEM8(1670)
#define PORTE_OUTTGL _SFR_MEM8(1671)
#define PORTE_IN _SFR_MEM8(1672)
#define PORTE_INTCTRL _SFR_MEM8(1673)
#define PORTE_INT0MASK _SFR_MEM8(1674)
#define PORTE_INT1MASK _SFR_MEM8(1675)
#define PORTE_INTFLAGS _SFR_MEM8(1676)
#define PORTE_PIN0CTRL _SFR_MEM8(1680)
#define PORTE_PIN1CTRL _SFR_MEM8(1681)
#define PORTE_PIN2CTRL _SFR_MEM8(1682)
#define PORTE_PIN3CTRL _SFR_MEM8(1683)
#define PORTE_PIN4CTRL _SFR_MEM8(1684)
#define PORTE_PIN5CTRL _SFR_MEM8(1685)
#define PORTE_PIN6CTRL _SFR_MEM8(1686)
#define PORTE_PIN7CTRL _SFR_MEM8(1687)

/* PORTF - Port F */
#define PORTF_DIR _SFR_MEM8(1696)
#define PORTF_DIRSET _SFR_MEM8(1697)
#define PORTF_DIRCLR _SFR_MEM8(1698)
#define PORTF_DIRTGL _SFR_MEM8(1699)
#define PORTF_OUT _SFR_MEM8(1700)
#define PORTF_OUTSET _SFR_MEM8(1701)
#define PORTF_OUTCLR _SFR_MEM8(1702)
#define PORTF_OUTTGL _SFR_MEM8(1703)
#define PORTF_IN _SFR_MEM8(1704)
#define PORTF_INTCTRL _SFR_MEM8(1705)
#define PORTF_INT0MASK _SFR_MEM8(1706)
#define PORTF_INT1MASK _SFR_MEM8(1707)
#define PORTF_INTFLAGS _SFR_MEM8(1708)
#define PORTF_PIN0CTRL _SFR_MEM8(1712)
#define PORTF_PIN1CTRL _SFR_MEM8(1713)
#define PORTF_PIN2CTRL _SFR_MEM8(1714)
#define PORTF_PIN3CTRL _SFR_MEM8(1715)
#define PORTF_PIN4CTRL _SFR_MEM8(1716)
#define PORTF_PIN5CTRL _SFR_MEM8(1717)
#define PORTF_PIN6CTRL _SFR_MEM8(1718)
#define PORTF_PIN7CTRL _SFR_MEM8(1719)

/* PORTH - Port H */
#define PORTH_DIR _SFR_MEM8(1760)
#define PORTH_DIRSET _SFR_MEM8(1761)
#define PORTH_DIRCLR _SFR_MEM8(1762)
#define PORTH_DIRTGL _SFR_MEM8(1763)
#define PORTH_OUT _SFR_MEM8(1764)
#define PORTH_OUTSET _SFR_MEM8(1765)
#define PORTH_OUTCLR _SFR_MEM8(1766)
#define PORTH_OUTTGL _SFR_MEM8(1767)
#define PORTH_IN _SFR_MEM8(1768)
#define PORTH_INTCTRL _SFR_MEM8(1769)
#define PORTH_INT0MASK _SFR_MEM8(1770)
#define PORTH_INT1MASK _SFR_MEM8(1771)
#define PORTH_INTFLAGS _SFR_MEM8(1772)
#define PORTH_PIN0CTRL _SFR_MEM8(1776)
#define PORTH_PIN1CTRL _SFR_MEM8(1777)
#define PORTH_PIN2CTRL _SFR_MEM8(1778)
#define PORTH_PIN3CTRL _SFR_MEM8(1779)
#define PORTH_PIN4CTRL _SFR_MEM8(1780)
#define PORTH_PIN5CTRL _SFR_MEM8(1781)
#define PORTH_PIN6CTRL _SFR_MEM8(1782)
#define PORTH_PIN7CTRL _SFR_MEM8(1783)

/* PORTJ - Port J */
#define PORTJ_DIR _SFR_MEM8(1792)
#define PORTJ_DIRSET _SFR_MEM8(1793)
#define PORTJ_DIRCLR _SFR_MEM8(1794)
#define PORTJ_DIRTGL _SFR_MEM8(1795)
#define PORTJ_OUT _SFR_MEM8(1796)
#define PORTJ_OUTSET _SFR_MEM8(1797)
#define PORTJ_OUTCLR _SFR_MEM8(1798)
#define PORTJ_OUTTGL _SFR_MEM8(1799)
#define PORTJ_IN _SFR_MEM8(1800)
#define PORTJ_INTCTRL _SFR_MEM8(1801)
#define PORTJ_INT0MASK _SFR_MEM8(1802)
#define PORTJ_INT1MASK _SFR_MEM8(1803)
#define PORTJ_INTFLAGS _SFR_MEM8(1804)
#define PORTJ_PIN0CTRL _SFR_MEM8(1808)
#define PORTJ_PIN1CTRL _SFR_MEM8(1809)
#define PORTJ_PIN2CTRL _SFR_MEM8(1810)
#define PORTJ_PIN3CTRL _SFR_MEM8(1811)
#define PORTJ_PIN4CTRL _SFR_MEM8(1812)
#define PORTJ_PIN5CTRL _SFR_MEM8(1813)
#define PORTJ_PIN6CTRL _SFR_MEM8(1814)
#define PORTJ_PIN7CTRL _SFR_MEM8(1815)

/* PORTK - Port K */
#define PORTK_DIR _SFR_MEM8(1824)
#define PORTK_DIRSET _SFR_MEM8(1825)
#define PORTK_DIRCLR _SFR_MEM8(1826)
#define PORTK_DIRTGL _SFR_MEM8(1827)
#define PORTK_OUT _SFR_MEM8(1828)
#define PORTK_OUTSET _SFR_MEM8(1829)
#define PORTK_OUTCLR _SFR_MEM8(1830)
#define PORTK_OUTTGL _SFR_MEM8(1831)
#define PORTK_IN _SFR_MEM8(1832)
#define PORTK_INTCTRL _SFR_MEM8(1833)
#define PORTK_INT0MASK _SFR_MEM8(1834)
#define PORTK_INT1MASK _SFR_MEM8(1835)
#define PORTK_INTFLAGS _SFR_MEM8(1836)
#define PORTK_PIN0CTRL _SFR_MEM8(1840)
#define PORTK_PIN1CTRL _SFR_MEM8(1841)
#define PORTK_PIN2CTRL _SFR_MEM8(1842)
#define PORTK_PIN3CTRL _SFR_MEM8(1843)
#define PORTK_PIN4CTRL _SFR_MEM8(1844)
#define PORTK_PIN5CTRL _SFR_MEM8(1845)
#define PORTK_PIN6CTRL _SFR_MEM8(1846)
#define PORTK_PIN7CTRL _SFR_MEM8(1847)

/* PORTQ - Port Q */
#define PORTQ_DIR _SFR_MEM8(1984)
#define PORTQ_DIRSET _SFR_MEM8(1985)
#define PORTQ_DIRCLR _SFR_MEM8(1986)
#define PORTQ_DIRTGL _SFR_MEM8(1987)
#define PORTQ_OUT _SFR_MEM8(1988)
#define PORTQ_OUTSET _SFR_MEM8(1989)
#define PORTQ_OUTCLR _SFR_MEM8(1990)
#define PORTQ_OUTTGL _SFR_MEM8(1991)
#define PORTQ_IN _SFR_MEM8(1992)
#define PORTQ_INTCTRL _SFR_MEM8(1993)
#define PORTQ_INT0MASK _SFR_MEM8(1994)
#define PORTQ_INT1MASK _SFR_MEM8(1995)
#define PORTQ_INTFLAGS _SFR_MEM8(1996)
#define PORTQ_PIN0CTRL _SFR_MEM8(2000)
#define PORTQ_PIN1CTRL _SFR_MEM8(2001)
#define PORTQ_PIN2CTRL _SFR_MEM8(2002)
#define PORTQ_PIN3CTRL _SFR_MEM8(2003)
#define PORTQ_PIN4CTRL _SFR_MEM8(2004)
#define PORTQ_PIN5CTRL _SFR_MEM8(2005)
#define PORTQ_PIN6CTRL _SFR_MEM8(2006)
#define PORTQ_PIN7CTRL _SFR_MEM8(2007)

/* PORTR - Port R */
#define PORTR_DIR _SFR_MEM8(2016)
#define PORTR_DIRSET _SFR_MEM8(2017)
#define PORTR_DIRCLR _SFR_MEM8(2018)
#define PORTR_DIRTGL _SFR_MEM8(2019)
#define PORTR_OUT _SFR_MEM8(2020)
#define PORTR_OUTSET _SFR_MEM8(2021)
#define PORTR_OUTCLR _SFR_MEM8(2022)
#define PORTR_OUTTGL _SFR_MEM8(2023)
#define PORTR_IN _SFR_MEM8(2024)
#define PORTR_INTCTRL _SFR_MEM8(2025)
#define PORTR_INT0MASK _SFR_MEM8(2026)
#define PORTR_INT1MASK _SFR_MEM8(2027)
#define PORTR_INTFLAGS _SFR_MEM8(2028)
#define PORTR_PIN0CTRL _SFR_MEM8(2032)
#define PORTR_PIN1CTRL _SFR_MEM8(2033)
#define PORTR_PIN2CTRL _SFR_MEM8(2034)
#define PORTR_PIN3CTRL _SFR_MEM8(2035)
#define PORTR_PIN4CTRL _SFR_MEM8(2036)
#define PORTR_PIN5CTRL _SFR_MEM8(2037)
#define PORTR_PIN6CTRL _SFR_MEM8(2038)
#define PORTR_PIN7CTRL _SFR_MEM8(2039)

/* TCC0 - 16-bit Timer/Counter With PWM C0 */
#define TCC0_CTRLA _SFR_MEM8(2048)
#define TCC0_CTRLB _SFR_MEM8(2049)
#define TCC0_CTRLC _SFR_MEM8(2050)
#define TCC0_CTRLD _SFR_MEM8(2051)
#define TCC0_CTRLE _SFR_MEM8(2052)
#define TCC0_INTCTRLA _SFR_MEM8(2054)
#define TCC0_INTCTRLB _SFR_MEM8(2055)
#define TCC0_CTRLFCLR _SFR_MEM8(2056)
#define TCC0_CTRLFSET _SFR_MEM8(2057)
#define TCC0_CTRLGCLR _SFR_MEM8(2058)
#define TCC0_CTRLGSET _SFR_MEM8(2059)
#define TCC0_INTFLAGS _SFR_MEM8(2060)
#define TCC0_TEMP _SFR_MEM8(2063)
#define TCC0_CNT _SFR_MEM16(2080)
#define TCC0_PER _SFR_MEM16(2086)
#define TCC0_CCA _SFR_MEM16(2088)
#define TCC0_CCB _SFR_MEM16(2090)
#define TCC0_CCC _SFR_MEM16(2092)
#define TCC0_CCD _SFR_MEM16(2094)
#define TCC0_PERBUF _SFR_MEM16(2102)
#define TCC0_CCABUF _SFR_MEM16(2104)
#define TCC0_CCBBUF _SFR_MEM16(2106)
#define TCC0_CCCBUF _SFR_MEM16(2108)
#define TCC0_CCDBUF _SFR_MEM16(2110)

/* TCC1 - 16-bit Timer/Counter With PWM C1 */
#define TCC1_CTRLA _SFR_MEM8(2112)
#define TCC1_CTRLB _SFR_MEM8(2113)
#define TCC1_CTRLC _SFR_MEM8(2114)
#define TCC1_CTRLD _SFR_MEM8(2115)
#define TCC1_CTRLE _SFR_MEM8(2116)
#define TCC1_INTCTRLA _SFR_MEM8(2118)
#define TCC1_INTCTRLB _SFR_MEM8(2119)
#define TCC1_CTRLFCLR _SFR_MEM8(2120)
#define TCC1_CTRLFSET _SFR_MEM8(2121)
#define TCC1_CTRLGCLR _SFR_MEM8(2122)
#define TCC1_CTRLGSET _SFR_MEM8(2123)
#define TCC1_INTFLAGS _SFR_MEM8(2124)
#define TCC1_TEMP _SFR_MEM8(2127)
#define TCC1_CNT _SFR_MEM16(2144)
#define TCC1_PER _SFR_MEM16(2150)
#define TCC1_CCA _SFR_MEM16(2152)
#define TCC1_CCB _SFR_MEM16(2154)
#define TCC1_PERBUF _SFR_MEM16(2166)
#define TCC1_CCABUF _SFR_MEM16(2168)
#define TCC1_CCBBUF _SFR_MEM16(2170)

/* AWEXC - Advanced Waveform Extension C */
#define AWEXC_CTRL _SFR_MEM8(2176)
#define AWEXC_FDEVMASK _SFR_MEM8(2178)
#define AWEXC_DFCTRL _SFR_MEM8(2179)
#define AWEXC_STATUS _SFR_MEM8(2180)
#define AWEXC_DTBOTH _SFR_MEM8(2182)
#define AWEXC_DTBOTHBUF _SFR_MEM8(2183)
#define AWEXC_DTLS _SFR_MEM8(2184)
#define AWEXC_DTHS _SFR_MEM8(2185)
#define AWEXC_DTLSBUF _SFR_MEM8(2186)
#define AWEXC_DTHSBUF _SFR_MEM8(2187)
#define AWEXC_OUTOVEN _SFR_MEM8(2188)

/* HIRESC - High-Resolution PWM C */
#define HIRESC_CTRL _SFR_MEM8(2192)

/* USARTC0 - Universal Asynchronous Receiver-Transmitter C0 */
#define USARTC0_DATA _SFR_MEM8(2208)
#define USARTC0_STATUS _SFR_MEM8(2209)
#define USARTC0_CTRLA _SFR_MEM8(2211)
#define USARTC0_CTRLB _SFR_MEM8(2212)
#define USARTC0_CTRLC _SFR_MEM8(2213)
#define USARTC0_BAUDCTRLA _SFR_MEM8(2214)
#define USARTC0_BAUDCTRLB _SFR_MEM8(2215)

/* USARTC1 - Universal Asynchronous Receiver-Transmitter C1 */
#define USARTC1_DATA _SFR_MEM8(2224)
#define USARTC1_STATUS _SFR_MEM8(2225)
#define USARTC1_CTRLA _SFR_MEM8(2227)
#define USARTC1_CTRLB _SFR_MEM8(2228)
#define USARTC1_CTRLC _SFR_MEM8(2229)
#define USARTC1_BAUDCTRLA _SFR_MEM8(2230)
#define USARTC1_BAUDCTRLB _SFR_MEM8(2231)

/* SPIC - Serial Peripheral Interface C */
#define SPIC_CTRL _SFR_MEM8(2240)
#define SPIC_INTCTRL _SFR_MEM8(2241)
#define SPIC_STATUS _SFR_MEM8(2242)
#define SPIC_DATA _SFR_MEM8(2243)

/* TCD0 - 16-bit Timer/Counter With PWM D0 */
#define TCD0_CTRLA _SFR_MEM8(2304)
#define TCD0_CTRLB _SFR_MEM8(2305)
#define TCD0_CTRLC _SFR_MEM8(2306)
#define TCD0_CTRLD _SFR_MEM8(2307)
#define TCD0_CTRLE _SFR_MEM8(2308)
#define TCD0_INTCTRLA _SFR_MEM8(2310)
#define TCD0_INTCTRLB _SFR_MEM8(2311)
#define TCD0_CTRLFCLR _SFR_MEM8(2312)
#define TCD0_CTRLFSET _SFR_MEM8(2313)
#define TCD0_CTRLGCLR _SFR_MEM8(2314)
#define TCD0_CTRLGSET _SFR_MEM8(2315)
#define TCD0_INTFLAGS _SFR_MEM8(2316)
#define TCD0_TEMP _SFR_MEM8(2319)
#define TCD0_CNT _SFR_MEM8(2336)
#define TCD0_PER _SFR_MEM8(2342)
#define TCD0_CCA _SFR_MEM8(2344)
#define TCD0_CCB _SFR_MEM8(2346)
#define TCD0_CCC _SFR_MEM8(2348)
#define TCD0_CCD _SFR_MEM8(2350)
#define TCD0_PERBUF _SFR_MEM8(2358)
#define TCD0_CCABUF _SFR_MEM8(2360)
#define TCD0_CCBBUF _SFR_MEM8(2362)
#define TCD0_CCCBUF _SFR_MEM8(2364)
#define TCD0_CCDBUF _SFR_MEM8(2366)

/* TCD1 - 16-bit Timer/Counter With PWM D1 */
#define TCD1_CTRLA _SFR_MEM8(2368)
#define TCD1_CTRLB _SFR_MEM8(2369)
#define TCD1_CTRLC _SFR_MEM8(2370)
#define TCD1_CTRLD _SFR_MEM8(2371)
#define TCD1_CTRLE _SFR_MEM8(2372)
#define TCD1_INTCTRLA _SFR_MEM8(2374)
#define TCD1_INTCTRLB _SFR_MEM8(2375)
#define TCD1_CTRLFCLR _SFR_MEM8(2376)
#define TCD1_CTRLFSET _SFR_MEM8(2377)
#define TCD1_CTRLGCLR _SFR_MEM8(2378)
#define TCD1_CTRLGSET _SFR_MEM8(2379)
#define TCD1_INTFLAGS _SFR_MEM8(2380)
#define TCD1_TEMP _SFR_MEM8(2383)
#define TCD1_CNT _SFR_MEM8(2400)
#define TCD1_PER _SFR_MEM8(2406)
#define TCD1_CCA _SFR_MEM8(2408)
#define TCD1_CCB _SFR_MEM8(2410)
#define TCD1_PERBUF _SFR_MEM8(2422)
#define TCD1_CCABUF _SFR_MEM8(2424)
#define TCD1_CCBBUF _SFR_MEM8(2426)

/* HIRESD - High-Resolution PWM D */
#define HIRESD_CTRL _SFR_MEM8(2448)

/* USARTD0 - Universal Asynchronous Receiver-Transmitter D0 */
#define USARTD0_DATA _SFR_MEM8(2464)
#define USARTD0_STATUS _SFR_MEM8(2465)
#define USARTD0_CTRLA _SFR_MEM8(2467)
#define USARTD0_CTRLB _SFR_MEM8(2468)
#define USARTD0_CTRLC _SFR_MEM8(2469)
#define USARTD0_BAUDCTRLA _SFR_MEM8(2470)
#define USARTD0_BAUDCTRLB _SFR_MEM8(2471)

/* USARTD1 - Universal Asynchronous Receiver-Transmitter D1 */
#define USARTD1_DATA _SFR_MEM8(2480)
#define USARTD1_STATUS _SFR_MEM8(2481)
#define USARTD1_CTRLA _SFR_MEM8(2483)
#define USARTD1_CTRLB _SFR_MEM8(2484)
#define USARTD1_CTRLC _SFR_MEM8(2485)
#define USARTD1_BAUDCTRLA _SFR_MEM8(2486)
#define USARTD1_BAUDCTRLB _SFR_MEM8(2487)

/* SPID - Serial Peripheral Interface D */
#define SPID_CTRL _SFR_MEM8(2496)
#define SPID_INTCTRL _SFR_MEM8(2497)
#define SPID_STATUS _SFR_MEM8(2498)
#define SPID_DATA _SFR_MEM8(2499)

/* TCE0 - 16-bit Timer/Counter With PWM E0 */
#define TCE0_CTRLA _SFR_MEM8(2560)
#define TCE0_CTRLB _SFR_MEM8(2561)
#define TCE0_CTRLC _SFR_MEM8(2562)
#define TCE0_CTRLD _SFR_MEM8(2563)
#define TCE0_CTRLE _SFR_MEM8(2564)
#define TCE0_INTCTRLA _SFR_MEM8(2566)
#define TCE0_INTCTRLB _SFR_MEM8(2567)
#define TCE0_CTRLFCLR _SFR_MEM8(2568)
#define TCE0_CTRLFSET _SFR_MEM8(2569)
#define TCE0_CTRLGCLR _SFR_MEM8(2570)
#define TCE0_CTRLGSET _SFR_MEM8(2571)
#define TCE0_INTFLAGS _SFR_MEM8(2572)
#define TCE0_TEMP _SFR_MEM8(2575)
#define TCE0_CNT _SFR_MEM8(2592)
#define TCE0_PER _SFR_MEM8(2598)
#define TCE0_CCA _SFR_MEM8(2600)
#define TCE0_CCB _SFR_MEM8(2602)
#define TCE0_CCC _SFR_MEM8(2604)
#define TCE0_CCD _SFR_MEM8(2606)
#define TCE0_PERBUF _SFR_MEM8(2614)
#define TCE0_CCABUF _SFR_MEM8(2616)
#define TCE0_CCBBUF _SFR_MEM8(2618)
#define TCE0_CCCBUF _SFR_MEM8(2620)
#define TCE0_CCDBUF _SFR_MEM8(2622)

/* TCE1 - 16-bit Timer/Counter With PWM E1 */
#define TCE1_CTRLA _SFR_MEM8(2624)
#define TCE1_CTRLB _SFR_MEM8(2625)
#define TCE1_CTRLC _SFR_MEM8(2626)
#define TCE1_CTRLD _SFR_MEM8(2627)
#define TCE1_CTRLE _SFR_MEM8(2628)
#define TCE1_INTCTRLA _SFR_MEM8(2630)
#define TCE1_INTCTRLB _SFR_MEM8(2631)
#define TCE1_CTRLFCLR _SFR_MEM8(2632)
#define TCE1_CTRLFSET _SFR_MEM8(2633)
#define TCE1_CTRLGCLR _SFR_MEM8(2634)
#define TCE1_CTRLGSET _SFR_MEM8(2635)
#define TCE1_INTFLAGS _SFR_MEM8(2636)
#define TCE1_TEMP _SFR_MEM8(2639)
#define TCE1_CNT _SFR_MEM8(2656)
#define TCE1_PER _SFR_MEM8(2662)
#define TCE1_CCA _SFR_MEM8(2664)
#define TCE1_CCB _SFR_MEM8(2666)
#define TCE1_PERBUF _SFR_MEM8(2678)
#define TCE1_CCABUF _SFR_MEM8(2680)
#define TCE1_CCBBUF _SFR_MEM8(2682)

/* AWEXE - Advanced Waveform Extension E */
#define AWEXE_CTRL _SFR_MEM8(2688)
#define AWEXE_FDEVMASK _SFR_MEM8(2690)
#define AWEXE_DFCTRL _SFR_MEM8(2691)
#define AWEXE_STATUS _SFR_MEM8(2692)
#define AWEXE_DTBOTH _SFR_MEM8(2694)
#define AWEXE_DTBOTHBUF _SFR_MEM8(2695)
#define AWEXE_DTLS _SFR_MEM8(2696)
#define AWEXE_DTHS _SFR_MEM8(2697)
#define AWEXE_DTLSBUF _SFR_MEM8(2698)
#define AWEXE_DTHSBUF _SFR_MEM8(2699)
#define AWEXE_OUTOVEN _SFR_MEM8(2700)

/* HIRESE - High-Resolution PWM E */
#define HIRESE_CTRL _SFR_MEM8(2704)

/* USARTE0 - Universal Asynchronous Receiver-Transmitter E0 */
#define USARTE0_DATA _SFR_MEM8(2720)
#define USARTE0_STATUS _SFR_MEM8(2721)
#define USARTE0_CTRLA _SFR_MEM8(2723)
#define USARTE0_CTRLB _SFR_MEM8(2724)
#define USARTE0_CTRLC _SFR_MEM8(2725)
#define USARTE0_BAUDCTRLA _SFR_MEM8(2726)
#define USARTE0_BAUDCTRLB _SFR_MEM8(2727)

/* USARTE1 - Universal Asynchronous Receiver-Transmitter E1 */
#define USARTE1_DATA _SFR_MEM8(2736)
#define USARTE1_STATUS _SFR_MEM8(2737)
#define USARTE1_CTRLA _SFR_MEM8(2739)
#define USARTE1_CTRLB _SFR_MEM8(2740)
#define USARTE1_CTRLC _SFR_MEM8(2741)
#define USARTE1_BAUDCTRLA _SFR_MEM8(2742)
#define USARTE1_BAUDCTRLB _SFR_MEM8(2743)

/* SPIE - Serial Peripheral Interface E */
#define SPIE_CTRL _SFR_MEM8(2752)
#define SPIE_INTCTRL _SFR_MEM8(2753)
#define SPIE_STATUS _SFR_MEM8(2754)
#define SPIE_DATA _SFR_MEM8(2755)

/* TCF0 - 16-bit Timer/Counter With PWM F0 */
#define TCF0_CTRLA _SFR_MEM8(2816)
#define TCF0_CTRLB _SFR_MEM8(2817)
#define TCF0_CTRLC _SFR_MEM8(2818)
#define TCF0_CTRLD _SFR_MEM8(2819)
#define TCF0_CTRLE _SFR_MEM8(2820)
#define TCF0_INTCTRLA _SFR_MEM8(2822)
#define TCF0_INTCTRLB _SFR_MEM8(2823)
#define TCF0_CTRLFCLR _SFR_MEM8(2824)
#define TCF0_CTRLFSET _SFR_MEM8(2825)
#define TCF0_CTRLGCLR _SFR_MEM8(2826)
#define TCF0_CTRLGSET _SFR_MEM8(2827)
#define TCF0_INTFLAGS _SFR_MEM8(2828)
#define TCF0_TEMP _SFR_MEM8(2831)
#define TCF0_CNT _SFR_MEM8(2848)
#define TCF0_PER _SFR_MEM8(2854)
#define TCF0_CCA _SFR_MEM8(2856)
#define TCF0_CCB _SFR_MEM8(2858)
#define TCF0_CCC _SFR_MEM8(2860)
#define TCF0_CCD _SFR_MEM8(2862)
#define TCF0_PERBUF _SFR_MEM8(2870)
#define TCF0_CCABUF _SFR_MEM8(2872)
#define TCF0_CCBBUF _SFR_MEM8(2874)
#define TCF0_CCCBUF _SFR_MEM8(2876)
#define TCF0_CCDBUF _SFR_MEM8(2878)

/* TCF1 - 16-bit Timer/Counter With PWM F1 */
#define TCF1_CTRLA _SFR_MEM8(2880)
#define TCF1_CTRLB _SFR_MEM8(2881)
#define TCF1_CTRLC _SFR_MEM8(2882)
#define TCF1_CTRLD _SFR_MEM8(2883)
#define TCF1_CTRLE _SFR_MEM8(2884)
#define TCF1_INTCTRLA _SFR_MEM8(2886)
#define TCF1_INTCTRLB _SFR_MEM8(2887)
#define TCF1_CTRLFCLR _SFR_MEM8(2888)
#define TCF1_CTRLFSET _SFR_MEM8(2889)
#define TCF1_CTRLGCLR _SFR_MEM8(2890)
#define TCF1_CTRLGSET _SFR_MEM8(2891)
#define TCF1_INTFLAGS _SFR_MEM8(2892)
#define TCF1_TEMP _SFR_MEM8(2895)
#define TCF1_CNT _SFR_MEM8(2912)
#define TCF1_PER _SFR_MEM8(2918)
#define TCF1_CCA _SFR_MEM8(2920)
#define TCF1_CCB _SFR_MEM8(2922)
#define TCF1_PERBUF _SFR_MEM8(2934)
#define TCF1_CCABUF _SFR_MEM8(2936)
#define TCF1_CCBBUF _SFR_MEM8(2938)

/* HIRESF - High-Resolution PWM F */
#define HIRESF_CTRL _SFR_MEM8(2960)

/* USARTF0 - Universal Asynchronous Receiver-Transmitter F0 */
#define USARTF0_DATA _SFR_MEM8(2976)
#define USARTF0_STATUS _SFR_MEM8(2977)
#define USARTF0_CTRLA _SFR_MEM8(2979)
#define USARTF0_CTRLB _SFR_MEM8(2980)
#define USARTF0_CTRLC _SFR_MEM8(2981)
#define USARTF0_BAUDCTRLA _SFR_MEM8(2982)
#define USARTF0_BAUDCTRLB _SFR_MEM8(2983)

/* USARTF1 - Universal Asynchronous Receiver-Transmitter F1 */
#define USARTF1_DATA _SFR_MEM8(2992)
#define USARTF1_STATUS _SFR_MEM8(2993)
#define USARTF1_CTRLA _SFR_MEM8(2995)
#define USARTF1_CTRLB _SFR_MEM8(2996)
#define USARTF1_CTRLC _SFR_MEM8(2997)
#define USARTF1_BAUDCTRLA _SFR_MEM8(2998)
#define USARTF1_BAUDCTRLB _SFR_MEM8(2999)

/* SPIF - Serial Peripheral Interface F */
#define SPIF_CTRL _SFR_MEM8(3008)
#define SPIF_INTCTRL _SFR_MEM8(3009)
#define SPIF_STATUS _SFR_MEM8(3010)
#define SPIF_DATA _SFR_MEM8(3011)

/* IRCOM - IR Communication Module */
#define IRCOM_TXPLCTRL _SFR_MEM8(2288)
#define IRCOM_RXPLCTRL _SFR_MEM8(2289)
#define IRCOM_CTRL _SFR_MEM8(2290)

/* AES - AES Crypto Module */
#define AES_CTRL _SFR_MEM8(192)
#define AES_STATUS _SFR_MEM8(193)
#define AES_STATE _SFR_MEM8(194)
#define AES_KEY _SFR_MEM8(195)
#define AES_INTCTRL _SFR_MEM8(196)


/*================== Bitfield Definitions ================== */

// CCP bit masks and bit positions
#define IO_bm 0x01 // TODO: Find documentation on this bit mask
#define IO_bp 0 // TODO: Find documentation on this bit position
#define PM_bm 0x02 // TODO: Find documentation on this bit mask
#define PM_bp 1 // TODO: Find documentation on this bit position

// SREG bit masks and bit positions
#define I_bm 0x80 // Global Interrupt Enable Flag bit mask
#define I_bp 7 // Global Interrupt Enable Flag bit position
#define T_bm 0x40 // Transfer Bit bit mask
#define T_bp 6 // Transfer Bit bit position
#define H_bm 0x20 // Half Carry Flag bit mask
#define H_bp 5 // Half Carry Flag bit position
#define S_bm 0x10 // N Exclusive Or V Flag bit mask
#define S_bp 4 // N Exclusive Or V Flag bit position
#define V_bm 0x08 // Two's Complement Overflow Flag bit mask
#define V_bp 3 // Two's Complement Overflow Flag bit position
#define N_bm 0x04 // Negative Flag bit mask
#define N_bp 2 // Negative Flag bit position
#define Z_bm 0x02 // Zero Flag bit mask
#define Z_bp 1 // Zero Flag bit position
#define C_bm 0x01 // Carry Flag bit mask
#define C_bp 0 // Carry Flag bit position




/*
--------------------------------------------------------------------------
 XOCD - On-Chip Debug System
--------------------------------------------------------------------------
*/

/* OCD.OCDR1 bit masks and bit positions */

        
#define OCD_OCDRD_bm 0x01 // OCDR Dirty bit mask
#define OCD_OCDRD_bp 0 // OCDR Dirty bit position


#if !defined (__ASSEMBLER__)
/* CCP signatures */
typedef enum CCP_enum
{
  CCP_SPM_gc = (0x9D<<0),   /* SPM Instruction Protection */
  CCP_IOREG_gc = (0xD8<<0),   /* IO Register Protection */
} CCP_t;
#endif /* !defined (__ASSEMBLER__) */


/*
--------------------------------------------------------------------------
 CLK - Clock System
--------------------------------------------------------------------------
*/

/* CLK.CTRL bit masks and bit positions */

        
#define CLK_SCLKSEL_gm 0x07 // System Clock Selection group mask
#define CLK_SCLKSEL_bp 0 // System Clock Selection group position

#define CLK_SCLKSEL0_bm (1<<0) // System Clock Selection bit 0 mask
#define CLK_SCLKSEL0_bp 0 // System Clock Selection bit 0 position
#define CLK_SCLKSEL1_bm (1<<1) // System Clock Selection bit 1 mask
#define CLK_SCLKSEL1_bp 1 // System Clock Selection bit 1 position
#define CLK_SCLKSEL2_bm (1<<2) // System Clock Selection bit 2 mask
#define CLK_SCLKSEL2_bp 2 // System Clock Selection bit 2 position

/* CLK.PSCTRL bit masks and bit positions */

        
#define CLK_PSADIV_gm 0x7C // Prescaler A Division Factor group mask
#define CLK_PSADIV_bp 2 // Prescaler A Division Factor group position

#define CLK_PSADIV0_bm (1<<2) // Prescaler A Division Factor bit 0 mask
#define CLK_PSADIV0_bp 2 // Prescaler A Division Factor bit 0 position
#define CLK_PSADIV1_bm (1<<3) // Prescaler A Division Factor bit 1 mask
#define CLK_PSADIV1_bp 3 // Prescaler A Division Factor bit 1 position
#define CLK_PSADIV2_bm (1<<4) // Prescaler A Division Factor bit 2 mask
#define CLK_PSADIV2_bp 4 // Prescaler A Division Factor bit 2 position
#define CLK_PSADIV3_bm (1<<5) // Prescaler A Division Factor bit 3 mask
#define CLK_PSADIV3_bp 5 // Prescaler A Division Factor bit 3 position
#define CLK_PSADIV4_bm (1<<6) // Prescaler A Division Factor bit 4 mask
#define CLK_PSADIV4_bp 6 // Prescaler A Division Factor bit 4 position
#define CLK_PSBCDIV_gm 0x03 // Prescaler B and D Division factor group mask
#define CLK_PSBCDIV_bp 0 // Prescaler B and D Division factor group position

#define CLK_PSBCDIV0_bm (1<<0) // Prescaler B and D Division factor bit 0 mask
#define CLK_PSBCDIV0_bp 0 // Prescaler B and D Division factor bit 0 position
#define CLK_PSBCDIV1_bm (1<<1) // Prescaler B and D Division factor bit 1 mask
#define CLK_PSBCDIV1_bp 1 // Prescaler B and D Division factor bit 1 position

/* CLK.LOCK bit masks and bit positions */

        
#define CLK_LOCK_bm 0x01 // Clock System Lock bit mask
#define CLK_LOCK_bp 0 // Clock System Lock bit position

/* CLK.RTCCTRL bit masks and bit positions */

        
#define CLK_RTCSRC_gm 0x0E // Clock Source group mask
#define CLK_RTCSRC_bp 1 // Clock Source group position

#define CLK_RTCSRC0_bm (1<<1) // Clock Source bit 0 mask
#define CLK_RTCSRC0_bp 1 // Clock Source bit 0 position
#define CLK_RTCSRC1_bm (1<<2) // Clock Source bit 1 mask
#define CLK_RTCSRC1_bp 2 // Clock Source bit 1 position
#define CLK_RTCSRC2_bm (1<<3) // Clock Source bit 2 mask
#define CLK_RTCSRC2_bp 3 // Clock Source bit 2 position
#define CLK_RTCEN_bm 0x01 // RTC Clock Source Enable bit mask
#define CLK_RTCEN_bp 0 // RTC Clock Source Enable bit position

/* PR.PR bit masks and bit positions */

        
#define PR_EBI_bm 0x08 // External Bus Interface bit mask
#define PR_EBI_bp 3 // External Bus Interface bit position
#define PR_RTC_bm 0x04 // Real-time Counter bit mask
#define PR_RTC_bp 2 // Real-time Counter bit position
#define PR_EVSYS_bm 0x02 // Event System bit mask
#define PR_EVSYS_bp 1 // Event System bit position
#define PR_DMA_bm 0x01 // DMA-Controller bit mask
#define PR_DMA_bp 0 // DMA-Controller bit position

/* PR.PRPA bit masks and bit positions */

        
#define PR_DAC_bm 0x04 // Port A DAC bit mask
#define PR_DAC_bp 2 // Port A DAC bit position
#define PR_ADC_bm 0x02 // Port A ADC bit mask
#define PR_ADC_bp 1 // Port A ADC bit position
#define PR_AC_bm 0x01 // Port A Analog Comparator bit mask
#define PR_AC_bp 0 // Port A Analog Comparator bit position

/* PR.PRPB bit masks and bit positions */

        
/* Masks for DAC aready defined */
            
/* Masks for ADC aready defined */
            
/* Masks for AC aready defined */
            

/* PR.PRPC bit masks and bit positions */

        
#define PR_TWI_bm 0x40 // Port C Two-wire Interface bit mask
#define PR_TWI_bp 6 // Port C Two-wire Interface bit position
#define PR_USART1_bm 0x20 // Port C USART1 bit mask
#define PR_USART1_bp 5 // Port C USART1 bit position
#define PR_USART0_bm 0x10 // Port C USART0 bit mask
#define PR_USART0_bp 4 // Port C USART0 bit position
#define PR_SPI_bm 0x08 // Port C SPI bit mask
#define PR_SPI_bp 3 // Port C SPI bit position
#define PR_HIRES_bm 0x04 // Port C AWEX bit mask
#define PR_HIRES_bp 2 // Port C AWEX bit position
#define PR_TC1_bm 0x02 // Port C Timer/Counter1 bit mask
#define PR_TC1_bp 1 // Port C Timer/Counter1 bit position
#define PR_TC0_bm 0x01 // Port C Timer/Counter0 bit mask
#define PR_TC0_bp 0 // Port C Timer/Counter0 bit position

/* PR.PRPD bit masks and bit positions */

        
/* Masks for TWI aready defined */
            
/* Masks for USART1 aready defined */
            
/* Masks for USART0 aready defined */
            
/* Masks for SPI aready defined */
            
/* Masks for HIRES aready defined */
            
/* Masks for TC1 aready defined */
            
/* Masks for TC0 aready defined */
            

/* PR.PRPE bit masks and bit positions */

        
/* Masks for TWI aready defined */
            
/* Masks for USART1 aready defined */
            
/* Masks for USART0 aready defined */
            
/* Masks for SPI aready defined */
            
/* Masks for HIRES aready defined */
            
/* Masks for TC1 aready defined */
            
/* Masks for TC0 aready defined */
            

/* PR.PRPF bit masks and bit positions */

        
/* Masks for TWI aready defined */
            
/* Masks for USART1 aready defined */
            
/* Masks for USART0 aready defined */
            
/* Masks for SPI aready defined */
            
/* Masks for HIRES aready defined */
            
/* Masks for TC1 aready defined */
            
/* Masks for TC0 aready defined */
            

#if !defined (__ASSEMBLER__)
/* System Clock Selection */
typedef enum CLK_SCLKSEL_enum
{
  CLK_SCLKSEL_RC2M_gc = (0x00<<0),   /* Internal 2MHz RC Oscillator */
  CLK_SCLKSEL_RC32M_gc = (0x01<<0),   /* Internal 32MHz RC Oscillator */
  CLK_SCLKSEL_RC32K_gc = (0x02<<0),   /* Internal 32kHz RC Oscillator */
  CLK_SCLKSEL_XOSC_gc = (0x03<<0),   /* External Crystal Oscillator or Clock */
  CLK_SCLKSEL_PLL_gc = (0x04<<0),   /* Phase Locked Loop */
} CLK_SCLKSEL_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/* Prescaler A Division Factor */
typedef enum CLK_PSADIV_enum
{
  CLK_PSADIV_1_gc = (0x00<<2),   /* Divide by 1 */
  CLK_PSADIV_2_gc = (0x01<<2),   /* Divide by 2 */
  CLK_PSADIV_4_gc = (0x03<<2),   /* Divide by 4 */
  CLK_PSADIV_8_gc = (0x05<<2),   /* Divide by 8 */
  CLK_PSADIV_16_gc = (0x07<<2),   /* Divide by 16 */
  CLK_PSADIV_32_gc = (0x09<<2),   /* Divide by 32 */
  CLK_PSADIV_64_gc = (0x0B<<2),   /* Divide by 64 */
  CLK_PSADIV_128_gc = (0x0D<<2),   /* Divide by 128 */
  CLK_PSADIV_256_gc = (0x0F<<2),   /* Divide by 256 */
  CLK_PSADIV_512_gc = (0x11<<2),   /* Divide by 512 */
} CLK_PSADIV_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/* Prescaler B and C Division Factor */
typedef enum CLK_PSBCDIV_enum
{
  CLK_PSBCDIV_1_1_gc = (0x00<<0),   /* Divide B by 1 and C by 1 */
  CLK_PSBCDIV_1_2_gc = (0x01<<0),   /* Divide B by 1 and C by 2 */
  CLK_PSBCDIV_4_1_gc = (0x02<<0),   /* Divide B by 4 and C by 1 */
  CLK_PSBCDIV_2_2_gc = (0x03<<0),   /* Divide B by 2 and C by 2 */
} CLK_PSBCDIV_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/* RTC Clock Source */
typedef enum CLK_RTCSRC_enum
{
  CLK_RTCSRC_ULP_gc = (0x00<<1),   /* 1kHz from internal 32kHz ULP */
  CLK_RTCSRC_TOSC_gc = (0x01<<1),   /* 1kHz from 32kHz crystal oscillator on TOSC */
  CLK_RTCSRC_RCOSC_gc = (0x02<<1),   /* 1kHz from internal 32kHz RC oscillator */
  CLK_RTCSRC_TOSC32_gc = (0x05<<1),   /* 32kHz from 32kHz crystal oscillator on TOSC */
} CLK_RTCSRC_t;
#endif /* !defined (__ASSEMBLER__) */


/*
--------------------------------------------------------------------------
 SLEEP - Sleep Controller
--------------------------------------------------------------------------
*/

/* SLEEP.CTRL bit masks and bit positions */

        
#define SLEEP_SMODE_gm 0x0E // Sleep Mode group mask
#define SLEEP_SMODE_bp 1 // Sleep Mode group position

#define SLEEP_SMODE0_bm (1<<1) // Sleep Mode bit 0 mask
#define SLEEP_SMODE0_bp 1 // Sleep Mode bit 0 position
#define SLEEP_SMODE1_bm (1<<2) // Sleep Mode bit 1 mask
#define SLEEP_SMODE1_bp 2 // Sleep Mode bit 1 position
#define SLEEP_SMODE2_bm (1<<3) // Sleep Mode bit 2 mask
#define SLEEP_SMODE2_bp 3 // Sleep Mode bit 2 position
#define SLEEP_SEN_bm 0x01 // Sleep Enable bit mask
#define SLEEP_SEN_bp 0 // Sleep Enable bit position

#if !defined (__ASSEMBLER__)
/* Sleep Mode */
typedef enum SLEEP_SMODE_enum
{
  SLEEP_SMODE_IDLE_gc = (0x00<<1),   /* Idle mode */
  SLEEP_SMODE_PDOWN_gc = (0x02<<1),   /* Power-down Mode */
  SLEEP_SMODE_PSAVE_gc = (0x03<<1),   /* Power-save Mode */
  SLEEP_SMODE_STDBY_gc = (0x06<<1),   /* Standby Mode */
  SLEEP_SMODE_ESTDBY_gc = (0x07<<1),   /* Extended Standby Mode */
} SLEEP_SMODE_t;
#endif /* !defined (__ASSEMBLER__) */


/*
--------------------------------------------------------------------------
 OSC - Oscillator
--------------------------------------------------------------------------
*/

/* OSC.CTRL bit masks and bit positions */

        
#define OSC_PLLEN_bm 0x10 // PLL Enable bit mask
#define OSC_PLLEN_bp 4 // PLL Enable bit position
#define OSC_XOSCEN_bm 0x08 // External Oscillator Enable bit mask
#define OSC_XOSCEN_bp 3 // External Oscillator Enable bit position
#define OSC_RC32KEN_bm 0x04 // Internal 32kHz RC Oscillator Enable bit mask
#define OSC_RC32KEN_bp 2 // Internal 32kHz RC Oscillator Enable bit position
#define OSC_RC32MEN_bm 0x02 // Internal 32MHz RC Oscillator Enable bit mask
#define OSC_RC32MEN_bp 1 // Internal 32MHz RC Oscillator Enable bit position
#define OSC_RC2MEN_bm 0x01 // Internal 2MHz RC Oscillator Enable bit mask
#define OSC_RC2MEN_bp 0 // Internal 2MHz RC Oscillator Enable bit position

/* OSC.STATUS bit masks and bit positions */

        
#define OSC_PLLRDY_bm 0x10 // PLL Ready bit mask
#define OSC_PLLRDY_bp 4 // PLL Ready bit position
#define OSC_XOSCRDY_bm 0x08 // External Oscillator Ready bit mask
#define OSC_XOSCRDY_bp 3 // External Oscillator Ready bit position
#define OSC_RC32KRDY_bm 0x04 // Internal 32kHz RC Oscillator Ready bit mask
#define OSC_RC32KRDY_bp 2 // Internal 32kHz RC Oscillator Ready bit position
#define OSC_RC32MRDY_bm 0x02 // Internal 32MHz RC Oscillator Ready bit mask
#define OSC_RC32MRDY_bp 1 // Internal 32MHz RC Oscillator Ready bit position
#define OSC_RC2MRDY_bm 0x01 // Internal 2MHz RC Oscillator Ready bit mask
#define OSC_RC2MRDY_bp 0 // Internal 2MHz RC Oscillator Ready bit position

/* OSC.XOSCCTRL bit masks and bit positions */

        
#define OSC_FRQRANGE_gm 0xC0 // Frequency Range group mask
#define OSC_FRQRANGE_bp 6 // Frequency Range group position

#define OSC_FRQRANGE0_bm (1<<6) // Frequency Range bit 0 mask
#define OSC_FRQRANGE0_bp 6 // Frequency Range bit 0 position
#define OSC_FRQRANGE1_bm (1<<7) // Frequency Range bit 1 mask
#define OSC_FRQRANGE1_bp 7 // Frequency Range bit 1 position
#define OSC_X32KLPM_bm 0x20 // 32kHz XTAL OSC Low-power Mode bit mask
#define OSC_X32KLPM_bp 5 // 32kHz XTAL OSC Low-power Mode bit position
#define OSC_XOSCSEL_gm 0x0F // External Oscillator Selection and Startup Time group mask
#define OSC_XOSCSEL_bp 0 // External Oscillator Selection and Startup Time group position

#define OSC_XOSCSEL0_bm (1<<0) // External Oscillator Selection and Startup Time bit 0 mask
#define OSC_XOSCSEL0_bp 0 // External Oscillator Selection and Startup Time bit 0 position
#define OSC_XOSCSEL1_bm (1<<1) // External Oscillator Selection and Startup Time bit 1 mask
#define OSC_XOSCSEL1_bp 1 // External Oscillator Selection and Startup Time bit 1 position
#define OSC_XOSCSEL2_bm (1<<2) // External Oscillator Selection and Startup Time bit 2 mask
#define OSC_XOSCSEL2_bp 2 // External Oscillator Selection and Startup Time bit 2 position
#define OSC_XOSCSEL3_bm (1<<3) // External Oscillator Selection and Startup Time bit 3 mask
#define OSC_XOSCSEL3_bp 3 // External Oscillator Selection and Startup Time bit 3 position

/* OSC.XOSCFAIL bit masks and bit positions */

        
#define OSC_XOSCFDIF_bm 0x02 // Failure Detection Interrupt Flag bit mask
#define OSC_XOSCFDIF_bp 1 // Failure Detection Interrupt Flag bit position
#define OSC_XOSCFDEN_bm 0x01 // Failure Detection Enable bit mask
#define OSC_XOSCFDEN_bp 0 // Failure Detection Enable bit position

/* OSC.PLLCTRL bit masks and bit positions */

        
#define OSC_PLLSRC_gm 0xC0 // Clock Source group mask
#define OSC_PLLSRC_bp 6 // Clock Source group position

#define OSC_PLLSRC0_bm (1<<6) // Clock Source bit 0 mask
#define OSC_PLLSRC0_bp 6 // Clock Source bit 0 position
#define OSC_PLLSRC1_bm (1<<7) // Clock Source bit 1 mask
#define OSC_PLLSRC1_bp 7 // Clock Source bit 1 position
#define OSC_PLLFAC_gm 0x1F // Multiplication Factor group mask
#define OSC_PLLFAC_bp 0 // Multiplication Factor group position

#define OSC_PLLFAC0_bm (1<<0) // Multiplication Factor bit 0 mask
#define OSC_PLLFAC0_bp 0 // Multiplication Factor bit 0 position
#define OSC_PLLFAC1_bm (1<<1) // Multiplication Factor bit 1 mask
#define OSC_PLLFAC1_bp 1 // Multiplication Factor bit 1 position
#define OSC_PLLFAC2_bm (1<<2) // Multiplication Factor bit 2 mask
#define OSC_PLLFAC2_bp 2 // Multiplication Factor bit 2 position
#define OSC_PLLFAC3_bm (1<<3) // Multiplication Factor bit 3 mask
#define OSC_PLLFAC3_bp 3 // Multiplication Factor bit 3 position
#define OSC_PLLFAC4_bm (1<<4) // Multiplication Factor bit 4 mask
#define OSC_PLLFAC4_bp 4 // Multiplication Factor bit 4 position

/* OSC.DFLLCTRL bit masks and bit positions */

        
#define OSC_RC32MCREF_bm 0x02 // 32MHz Calibration Reference bit mask
#define OSC_RC32MCREF_bp 1 // 32MHz Calibration Reference bit position
#define OSC_RC2MCREF_bm 0x01 // 2MHz Calibration Reference bit mask
#define OSC_RC2MCREF_bp 0 // 2MHz Calibration Reference bit position

#if !defined (__ASSEMBLER__)
/* Frequency Range */
typedef enum OSC_FRQRANGE_enum
{
  OSC_FRQRANGE_04TO2_gc = (0x00<<6),   /* 0.4 - 2 MHz */
  OSC_FRQRANGE_2TO9_gc = (0x01<<6),   /* 2 - 9 MHz */
  OSC_FRQRANGE_9TO12_gc = (0x02<<6),   /* 9 - 12 MHz */
  OSC_FRQRANGE_12TO16_gc = (0x03<<6),   /* 12 - 16 MHz */
} OSC_FRQRANGE_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/* External Oscillator Selection and Startup Time */
typedef enum OSC_XOSCSEL_enum
{
  OSC_XOSCSEL_EXTCLK_gc = (0x00<<0),   /* External Clock - 6 CLK */
  OSC_XOSCSEL_32KHz_gc = (0x02<<0),   /* 32kHz TOSC - 32K CLK */
  OSC_XOSCSEL_XTAL_256CLK_gc = (0x03<<0),   /* 0.4-16MHz XTAL - 256 CLK */
  OSC_XOSCSEL_XTAL_1KCLK_gc = (0x07<<0),   /* 0.4-16MHz XTAL - 1K CLK */
  OSC_XOSCSEL_XTAL_16KCLK_gc = (0x0B<<0),   /* 0.4-16MHz XTAL - 16K CLK */
} OSC_XOSCSEL_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/* PLL Clock Source */
typedef enum OSC_PLLSRC_enum
{
  OSC_PLLSRC_RC2M_gc = (0x00<<6),   /* Internal 2MHz RC Oscillator */
  OSC_PLLSRC_RC32M_gc = (0x02<<6),   /* Internal 32MHz RC Oscillator */
  OSC_PLLSRC_XOSC_gc = (0x03<<6),   /* External Oscillator */
} OSC_PLLSRC_t;
#endif /* !defined (__ASSEMBLER__) */


/*
--------------------------------------------------------------------------
 DFLL - DFLL
--------------------------------------------------------------------------
*/

/* DFLL.CALA bit masks and bit positions */

        
#define DFLL_CALL_gm 0xFE // DFLL Calibration bits [6:0] group mask
#define DFLL_CALL_bp 1 // DFLL Calibration bits [6:0] group position

#define DFLL_CALL0_bm (1<<1) // DFLL Calibration bits [6:0] bit 0 mask
#define DFLL_CALL0_bp 1 // DFLL Calibration bits [6:0] bit 0 position
#define DFLL_CALL1_bm (1<<2) // DFLL Calibration bits [6:0] bit 1 mask
#define DFLL_CALL1_bp 2 // DFLL Calibration bits [6:0] bit 1 position
#define DFLL_CALL2_bm (1<<3) // DFLL Calibration bits [6:0] bit 2 mask
#define DFLL_CALL2_bp 3 // DFLL Calibration bits [6:0] bit 2 position
#define DFLL_CALL3_bm (1<<4) // DFLL Calibration bits [6:0] bit 3 mask
#define DFLL_CALL3_bp 4 // DFLL Calibration bits [6:0] bit 3 position
#define DFLL_CALL4_bm (1<<5) // DFLL Calibration bits [6:0] bit 4 mask
#define DFLL_CALL4_bp 5 // DFLL Calibration bits [6:0] bit 4 position
#define DFLL_CALL5_bm (1<<6) // DFLL Calibration bits [6:0] bit 5 mask
#define DFLL_CALL5_bp 6 // DFLL Calibration bits [6:0] bit 5 position
#define DFLL_CALL6_bm (1<<7) // DFLL Calibration bits [6:0] bit 6 mask
#define DFLL_CALL6_bp 7 // DFLL Calibration bits [6:0] bit 6 position
#define DFLL_ENABLE_bm 0x01 // DFLL Enable bit mask
#define DFLL_ENABLE_bp 0 // DFLL Enable bit position

/* DFLL.CALB bit masks and bit positions */

        
#define DFLL_CALH_gm 0x1F // DFLL Calibration bits [11:7] group mask
#define DFLL_CALH_bp 0 // DFLL Calibration bits [11:7] group position

#define DFLL_CALH0_bm (1<<0) // DFLL Calibration bits [11:7] bit 0 mask
#define DFLL_CALH0_bp 0 // DFLL Calibration bits [11:7] bit 0 position
#define DFLL_CALH1_bm (1<<1) // DFLL Calibration bits [11:7] bit 1 mask
#define DFLL_CALH1_bp 1 // DFLL Calibration bits [11:7] bit 1 position
#define DFLL_CALH2_bm (1<<2) // DFLL Calibration bits [11:7] bit 2 mask
#define DFLL_CALH2_bp 2 // DFLL Calibration bits [11:7] bit 2 position
#define DFLL_CALH3_bm (1<<3) // DFLL Calibration bits [11:7] bit 3 mask
#define DFLL_CALH3_bp 3 // DFLL Calibration bits [11:7] bit 3 position
#define DFLL_CALH4_bm (1<<4) // DFLL Calibration bits [11:7] bit 4 mask
#define DFLL_CALH4_bp 4 // DFLL Calibration bits [11:7] bit 4 position


/*
--------------------------------------------------------------------------
 RST - Reset
--------------------------------------------------------------------------
*/

/* RST.STATUS bit masks and bit positions */

        
#define RST_SDRF_bm 0x40 // Spike Detection Reset Flag bit mask
#define RST_SDRF_bp 6 // Spike Detection Reset Flag bit position
#define RST_SRF_bm 0x20 // Software Reset Flag bit mask
#define RST_SRF_bp 5 // Software Reset Flag bit position
#define RST_PDIRF_bm 0x10 // Programming and Debug Interface Interface Reset Flag bit mask
#define RST_PDIRF_bp 4 // Programming and Debug Interface Interface Reset Flag bit position
#define RST_WDRF_bm 0x08 // Watchdog Reset Flag bit mask
#define RST_WDRF_bp 3 // Watchdog Reset Flag bit position
#define RST_BORF_bm 0x04 // Brown-out Reset Flag bit mask
#define RST_BORF_bp 2 // Brown-out Reset Flag bit position
#define RST_EXTRF_bm 0x02 // External Reset Flag bit mask
#define RST_EXTRF_bp 1 // External Reset Flag bit position
#define RST_PORF_bm 0x01 // Power-on Reset Flag bit mask
#define RST_PORF_bp 0 // Power-on Reset Flag bit position

/* RST.CTRL bit masks and bit positions */

        
#define RST_SWRST_bm 0x01 // Software Reset bit mask
#define RST_SWRST_bp 0 // Software Reset bit position


/*
--------------------------------------------------------------------------
 WDT - Watch-Dog Timer
--------------------------------------------------------------------------
*/

/* WDT.CTRL bit masks and bit positions */

        
#define WDT_PER_gm 0x3C // Period group mask
#define WDT_PER_bp 2 // Period group position

#define WDT_PER0_bm (1<<2) // Period bit 0 mask
#define WDT_PER0_bp 2 // Period bit 0 position
#define WDT_PER1_bm (1<<3) // Period bit 1 mask
#define WDT_PER1_bp 3 // Period bit 1 position
#define WDT_PER2_bm (1<<4) // Period bit 2 mask
#define WDT_PER2_bp 4 // Period bit 2 position
#define WDT_PER3_bm (1<<5) // Period bit 3 mask
#define WDT_PER3_bp 5 // Period bit 3 position
#define WDT_ENABLE_bm 0x02 // Enable bit mask
#define WDT_ENABLE_bp 1 // Enable bit position
#define WDT_CEN_bm 0x01 // Change Enable bit mask
#define WDT_CEN_bp 0 // Change Enable bit position

/* WDT.WINCTRL bit masks and bit positions */

        
#define WDT_WPER_gm 0x3C // Windowed Mode Period group mask
#define WDT_WPER_bp 2 // Windowed Mode Period group position

#define WDT_WPER0_bm (1<<2) // Windowed Mode Period bit 0 mask
#define WDT_WPER0_bp 2 // Windowed Mode Period bit 0 position
#define WDT_WPER1_bm (1<<3) // Windowed Mode Period bit 1 mask
#define WDT_WPER1_bp 3 // Windowed Mode Period bit 1 position
#define WDT_WPER2_bm (1<<4) // Windowed Mode Period bit 2 mask
#define WDT_WPER2_bp 4 // Windowed Mode Period bit 2 position
#define WDT_WPER3_bm (1<<5) // Windowed Mode Period bit 3 mask
#define WDT_WPER3_bp 5 // Windowed Mode Period bit 3 position
#define WDT_WEN_bm 0x02 // Windowed Mode Enable bit mask
#define WDT_WEN_bp 1 // Windowed Mode Enable bit position
#define WDT_WCEN_bm 0x01 // Windowed Mode Change Enable bit mask
#define WDT_WCEN_bp 0 // Windowed Mode Change Enable bit position

/* WDT.STATUS bit masks and bit positions */

        
#define WDT_SYNCBUSY_bm 0x01 // Syncronization busy bit mask
#define WDT_SYNCBUSY_bp 0 // Syncronization busy bit position

#if !defined (__ASSEMBLER__)
/*  */
typedef enum WDT_PER_enum
{
  WDT_PER_8CLK_gc = (0x00<<2),   /* 8 cycles (8ms @ 3.3V) */
  WDT_PER_16CLK_gc = (0x01<<2),   /* 16 cycles (16ms @ 3.3V) */
  WDT_PER_32CLK_gc = (0x02<<2),   /* 32 cycles (32ms @ 3.3V) */
  WDT_PER_64CLK_gc = (0x03<<2),   /* 64 cycles (64ms @ 3.3V) */
  WDT_PER_128CLK_gc = (0x04<<2),   /* 128 cycles (0.125s @ 3.3V) */
  WDT_PER_256CLK_gc = (0x05<<2),   /* 256 cycles (0.25s @ 3.3V) */
  WDT_PER_512CLK_gc = (0x06<<2),   /* 512 cycles (0.5s @ 3.3V) */
  WDT_PER_1KCLK_gc = (0x07<<2),   /* 1K cycles (1s @ 3.3V) */
  WDT_PER_2KCLK_gc = (0x08<<2),   /* 2K cycles (2s @ 3.3V) */
  WDT_PER_4KCLK_gc = (0x09<<2),   /* 4K cycles (4s @ 3.3V) */
  WDT_PER_8KCLK_gc = (0x0A<<2),   /* 8K cycles (8s @ 3.3V) */
} WDT_PER_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/*  */
typedef enum WDT_WPER_enum
{
  WDT_WPER_8CLK_gc = (0x00<<2),   /* 8 cycles (8ms @ 3.3V) */
  WDT_WPER_16CLK_gc = (0x01<<2),   /* 16 cycles (16ms @ 3.3V) */
  WDT_WPER_32CLK_gc = (0x02<<2),   /* 32 cycles (32ms @ 3.3V) */
  WDT_WPER_64CLK_gc = (0x03<<2),   /* 64 cycles (64ms @ 3.3V) */
  WDT_WPER_128CLK_gc = (0x04<<2),   /* 128 cycles (0.125s @ 3.3V) */
  WDT_WPER_256CLK_gc = (0x05<<2),   /* 256 cycles (0.25s @ 3.3V) */
  WDT_WPER_512CLK_gc = (0x06<<2),   /* 512 cycles (0.5s @ 3.3V) */
  WDT_WPER_1KCLK_gc = (0x07<<2),   /* 1K cycles (1s @ 3.3V) */
  WDT_WPER_2KCLK_gc = (0x08<<2),   /* 2K cycles (2s @ 3.3V) */
  WDT_WPER_4KCLK_gc = (0x09<<2),   /* 4K cycles (4s @ 3.3V) */
  WDT_WPER_8KCLK_gc = (0x0A<<2),   /* 8K cycles (8s @ 3.3V) */
} WDT_WPER_t;
#endif /* !defined (__ASSEMBLER__) */


/*
--------------------------------------------------------------------------
 MCU - MCU
--------------------------------------------------------------------------
*/

/* MCU.MCUCR bit masks and bit positions */

        
#define MCU_JTAGD_bm 0x01 // JTAG Disable bit mask
#define MCU_JTAGD_bp 0 // JTAG Disable bit position

/* MCU.EVSYSLOCK bit masks and bit positions */

        
#define MCU_EVSYS1LOCK_bm 0x10 // Event Channel 4-7 Lock bit mask
#define MCU_EVSYS1LOCK_bp 4 // Event Channel 4-7 Lock bit position
#define MCU_EVSYS0LOCK_bm 0x01 // Event Channel 0-3 Lock bit mask
#define MCU_EVSYS0LOCK_bp 0 // Event Channel 0-3 Lock bit position

/* MCU.AWEXLOCK bit masks and bit positions */

        
#define MCU_AWEXELOCK_bm 0x04 // AWeX on T/C E0 Lock bit mask
#define MCU_AWEXELOCK_bp 2 // AWeX on T/C E0 Lock bit position
#define MCU_AWEXCLOCK_bm 0x01 // AWeX on T/C C0 Lock bit mask
#define MCU_AWEXCLOCK_bp 0 // AWeX on T/C C0 Lock bit position


/*
--------------------------------------------------------------------------
 PMIC - Programmable Multi-level Interrupt Controller
--------------------------------------------------------------------------
*/

/* PMIC.STATUS bit masks and bit positions */

        
#define PMIC_NMIEX_bm 0x80 // Non-maskable Interrupt Executing bit mask
#define PMIC_NMIEX_bp 7 // Non-maskable Interrupt Executing bit position
#define PMIC_HILVLEX_bm 0x04 // High Level Interrupt Executing bit mask
#define PMIC_HILVLEX_bp 2 // High Level Interrupt Executing bit position
#define PMIC_MEDLVLEX_bm 0x02 // Medium Level Interrupt Executing bit mask
#define PMIC_MEDLVLEX_bp 1 // Medium Level Interrupt Executing bit position
#define PMIC_LOLVLEX_bm 0x01 // Low Level Interrupt Executing bit mask
#define PMIC_LOLVLEX_bp 0 // Low Level Interrupt Executing bit position

/* PMIC.CTRL bit masks and bit positions */

        
#define PMIC_RREN_bm 0x80 // Round-Robin Priority Enable bit mask
#define PMIC_RREN_bp 7 // Round-Robin Priority Enable bit position
#define PMIC_IVSEL_bm 0x40 // Interrupt Vector Select bit mask
#define PMIC_IVSEL_bp 6 // Interrupt Vector Select bit position
#define PMIC_HILVLEN_bm 0x04 // High Level Enable bit mask
#define PMIC_HILVLEN_bp 2 // High Level Enable bit position
#define PMIC_MEDLVLEN_bm 0x02 // Medium Level Enable bit mask
#define PMIC_MEDLVLEN_bp 1 // Medium Level Enable bit position
#define PMIC_LOLVLEN_bm 0x01 // Low Level Enable bit mask
#define PMIC_LOLVLEN_bp 0 // Low Level Enable bit position


/*
--------------------------------------------------------------------------
 DMA - DMA Controller
--------------------------------------------------------------------------
*/

/* DMA_CH.CTRLA bit masks and bit positions */

        
#define DMA_CH_ENABLE_bm 0x80 // Channel Enable bit mask
#define DMA_CH_ENABLE_bp 7 // Channel Enable bit position
#define DMA_CH_RESET_bm 0x40 // Channel Software Reset bit mask
#define DMA_CH_RESET_bp 6 // Channel Software Reset bit position
#define DMA_CH_REPEAT_bm 0x20 // Channel Repeat Mode bit mask
#define DMA_CH_REPEAT_bp 5 // Channel Repeat Mode bit position
#define DMA_CH_TRFREQ_bm 0x10 // Channel Transfer Request bit mask
#define DMA_CH_TRFREQ_bp 4 // Channel Transfer Request bit position
#define DMA_CH_SINGLE_bm 0x04 // Channel Single Shot Data Transfer bit mask
#define DMA_CH_SINGLE_bp 2 // Channel Single Shot Data Transfer bit position
#define DMA_CH_BURSTLEN_gm 0x03 // Channel Transfer Mode group mask
#define DMA_CH_BURSTLEN_bp 0 // Channel Transfer Mode group position

#define DMA_CH_BURSTLEN0_bm (1<<0) // Channel Transfer Mode bit 0 mask
#define DMA_CH_BURSTLEN0_bp 0 // Channel Transfer Mode bit 0 position
#define DMA_CH_BURSTLEN1_bm (1<<1) // Channel Transfer Mode bit 1 mask
#define DMA_CH_BURSTLEN1_bp 1 // Channel Transfer Mode bit 1 position

/* DMA_CH.CTRLB bit masks and bit positions */

        
#define DMA_CH_CHBUSY_bm 0x80 // Block Transfer Busy bit mask
#define DMA_CH_CHBUSY_bp 7 // Block Transfer Busy bit position
#define DMA_CH_CHPEND_bm 0x40 // Block Transfer Pending bit mask
#define DMA_CH_CHPEND_bp 6 // Block Transfer Pending bit position
#define DMA_CH_ERRIF_bm 0x20 // Block Transfer Error Interrupt Flag bit mask
#define DMA_CH_ERRIF_bp 5 // Block Transfer Error Interrupt Flag bit position
#define DMA_CH_TRNIF_bm 0x10 // Transaction Complete Interrup Flag bit mask
#define DMA_CH_TRNIF_bp 4 // Transaction Complete Interrup Flag bit position
#define DMA_CH_ERRINTLVL_gm 0x0C // Transfer Error Interrupt Level group mask
#define DMA_CH_ERRINTLVL_bp 2 // Transfer Error Interrupt Level group position

#define DMA_CH_ERRINTLVL0_bm (1<<2) // Transfer Error Interrupt Level bit 0 mask
#define DMA_CH_ERRINTLVL0_bp 2 // Transfer Error Interrupt Level bit 0 position
#define DMA_CH_ERRINTLVL1_bm (1<<3) // Transfer Error Interrupt Level bit 1 mask
#define DMA_CH_ERRINTLVL1_bp 3 // Transfer Error Interrupt Level bit 1 position
#define DMA_CH_TRNINTLVL_gm 0x03 // Transaction Complete Interrupt Level group mask
#define DMA_CH_TRNINTLVL_bp 0 // Transaction Complete Interrupt Level group position

#define DMA_CH_TRNINTLVL0_bm (1<<0) // Transaction Complete Interrupt Level bit 0 mask
#define DMA_CH_TRNINTLVL0_bp 0 // Transaction Complete Interrupt Level bit 0 position
#define DMA_CH_TRNINTLVL1_bm (1<<1) // Transaction Complete Interrupt Level bit 1 mask
#define DMA_CH_TRNINTLVL1_bp 1 // Transaction Complete Interrupt Level bit 1 position

/* DMA_CH.ADDRCTRL bit masks and bit positions */

        
#define DMA_CH_SRCRELOAD_gm 0xC0 // Channel Source Address Reload group mask
#define DMA_CH_SRCRELOAD_bp 6 // Channel Source Address Reload group position

#define DMA_CH_SRCRELOAD0_bm (1<<6) // Channel Source Address Reload bit 0 mask
#define DMA_CH_SRCRELOAD0_bp 6 // Channel Source Address Reload bit 0 position
#define DMA_CH_SRCRELOAD1_bm (1<<7) // Channel Source Address Reload bit 1 mask
#define DMA_CH_SRCRELOAD1_bp 7 // Channel Source Address Reload bit 1 position
#define DMA_CH_SRCDIR_gm 0x30 // Channel Source Address Mode group mask
#define DMA_CH_SRCDIR_bp 4 // Channel Source Address Mode group position

#define DMA_CH_SRCDIR0_bm (1<<4) // Channel Source Address Mode bit 0 mask
#define DMA_CH_SRCDIR0_bp 4 // Channel Source Address Mode bit 0 position
#define DMA_CH_SRCDIR1_bm (1<<5) // Channel Source Address Mode bit 1 mask
#define DMA_CH_SRCDIR1_bp 5 // Channel Source Address Mode bit 1 position
#define DMA_CH_DESTRELOAD_gm 0x0C // Channel Destination Address Reload group mask
#define DMA_CH_DESTRELOAD_bp 2 // Channel Destination Address Reload group position

#define DMA_CH_DESTRELOAD0_bm (1<<2) // Channel Destination Address Reload bit 0 mask
#define DMA_CH_DESTRELOAD0_bp 2 // Channel Destination Address Reload bit 0 position
#define DMA_CH_DESTRELOAD1_bm (1<<3) // Channel Destination Address Reload bit 1 mask
#define DMA_CH_DESTRELOAD1_bp 3 // Channel Destination Address Reload bit 1 position
#define DMA_CH_DESTDIR_gm 0x03 // Channel Destination Address Mode group mask
#define DMA_CH_DESTDIR_bp 0 // Channel Destination Address Mode group position

#define DMA_CH_DESTDIR0_bm (1<<0) // Channel Destination Address Mode bit 0 mask
#define DMA_CH_DESTDIR0_bp 0 // Channel Destination Address Mode bit 0 position
#define DMA_CH_DESTDIR1_bm (1<<1) // Channel Destination Address Mode bit 1 mask
#define DMA_CH_DESTDIR1_bp 1 // Channel Destination Address Mode bit 1 position

/* DMA.CTRL bit masks and bit positions */

        
#define DMA_ENABLE_bm 0x80 // Enable bit mask
#define DMA_ENABLE_bp 7 // Enable bit position
#define DMA_RESET_bm 0x40 // Software Reset bit mask
#define DMA_RESET_bp 6 // Software Reset bit position
#define DMA_DBUFMODE_gm 0x0C // Double Buffering Mode group mask
#define DMA_DBUFMODE_bp 2 // Double Buffering Mode group position

#define DMA_DBUFMODE0_bm (1<<2) // Double Buffering Mode bit 0 mask
#define DMA_DBUFMODE0_bp 2 // Double Buffering Mode bit 0 position
#define DMA_DBUFMODE1_bm (1<<3) // Double Buffering Mode bit 1 mask
#define DMA_DBUFMODE1_bp 3 // Double Buffering Mode bit 1 position
#define DMA_PRIMODE_gm 0x03 // Channel Priority Mode group mask
#define DMA_PRIMODE_bp 0 // Channel Priority Mode group position

#define DMA_PRIMODE0_bm (1<<0) // Channel Priority Mode bit 0 mask
#define DMA_PRIMODE0_bp 0 // Channel Priority Mode bit 0 position
#define DMA_PRIMODE1_bm (1<<1) // Channel Priority Mode bit 1 mask
#define DMA_PRIMODE1_bp 1 // Channel Priority Mode bit 1 position

/* DMA.INTFLAGS bit masks and bit positions */

        
#define DMA_CH3ERRIF_bm 0x80 // Channel 3 Block Transfer Error Interrupt Flag bit mask
#define DMA_CH3ERRIF_bp 7 // Channel 3 Block Transfer Error Interrupt Flag bit position
#define DMA_CH2ERRIF_bm 0x40 // Channel 2 Block Transfer Error Interrupt Flag bit mask
#define DMA_CH2ERRIF_bp 6 // Channel 2 Block Transfer Error Interrupt Flag bit position
#define DMA_CH1ERRIF_bm 0x20 // Channel 1 Block Transfer Error Interrupt Flag bit mask
#define DMA_CH1ERRIF_bp 5 // Channel 1 Block Transfer Error Interrupt Flag bit position
#define DMA_CH0ERRIF_bm 0x10 // Channel 0 Block Transfer Error Interrupt Flag bit mask
#define DMA_CH0ERRIF_bp 4 // Channel 0 Block Transfer Error Interrupt Flag bit position
#define DMA_CH3TRNIF_bm 0x08 // Channel 3 Transaction Complete Interrupt Flag bit mask
#define DMA_CH3TRNIF_bp 3 // Channel 3 Transaction Complete Interrupt Flag bit position
#define DMA_CH2TRNIF_bm 0x04 // Channel 2 Transaction Complete Interrupt Flag bit mask
#define DMA_CH2TRNIF_bp 2 // Channel 2 Transaction Complete Interrupt Flag bit position
#define DMA_CH1TRNIF_bm 0x02 // Channel 1 Transaction Complete Interrupt Flag bit mask
#define DMA_CH1TRNIF_bp 1 // Channel 1 Transaction Complete Interrupt Flag bit position
#define DMA_CH0TRNIF_bm 0x01 // Channel 0 Transaction Complete Interrupt Flag bit mask
#define DMA_CH0TRNIF_bp 0 // Channel 0 Transaction Complete Interrupt Flag bit position

/* DMA.STATUS bit masks and bit positions */

        
#define DMA_CH3BUSY_bm 0x80 // Channel 3 Block Transfer Busy bit mask
#define DMA_CH3BUSY_bp 7 // Channel 3 Block Transfer Busy bit position
#define DMA_CH2BUSY_bm 0x40 // Channel 2 Block Transfer Busy bit mask
#define DMA_CH2BUSY_bp 6 // Channel 2 Block Transfer Busy bit position
#define DMA_CH1BUSY_bm 0x20 // Channel 1 Block Transfer Busy bit mask
#define DMA_CH1BUSY_bp 5 // Channel 1 Block Transfer Busy bit position
#define DMA_CH0BUSY_bm 0x10 // Channel 0 Block Transfer Busy bit mask
#define DMA_CH0BUSY_bp 4 // Channel 0 Block Transfer Busy bit position
#define DMA_CH3PEND_bm 0x08 // Channel 3 Block Transfer Pending bit mask
#define DMA_CH3PEND_bp 3 // Channel 3 Block Transfer Pending bit position
#define DMA_CH2PEND_bm 0x04 // Channel 2 Block Transfer Pending bit mask
#define DMA_CH2PEND_bp 2 // Channel 2 Block Transfer Pending bit position
#define DMA_CH1PEND_bm 0x02 // Channel 1 Block Transfer Pending bit mask
#define DMA_CH1PEND_bp 1 // Channel 1 Block Transfer Pending bit position
#define DMA_CH0PEND_bm 0x01 // Channel 0 Block Transfer Pending bit mask
#define DMA_CH0PEND_bp 0 // Channel 0 Block Transfer Pending bit position

#if !defined (__ASSEMBLER__)
/*  */
typedef enum DMA_CH_BURSTLEN_enum
{
  DMA_CH_BURSTLEN_1BYTE_gc = (0x00<<0),   /* 1-byte burst mode */
  DMA_CH_BURSTLEN_2BYTE_gc = (0x01<<0),   /* 2-byte burst mode */
  DMA_CH_BURSTLEN_4BYTE_gc = (0x02<<0),   /* 4-byte burst mode */
  DMA_CH_BURSTLEN_8BYTE_gc = (0x03<<0),   /* 8-byte burst mode */
} DMA_CH_BURSTLEN_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/*  */
typedef enum DMA_CH_SRCRELOAD_enum
{
  DMA_CH_SRCRELOAD_NONE_gc = (0x00<<6),   /* No reload */
  DMA_CH_SRCRELOAD_BLOCK_gc = (0x01<<6),   /* Reload at end of block */
  DMA_CH_SRCRELOAD_BURST_gc = (0x02<<6),   /* Reload at end of burst */
  DMA_CH_SRCRELOAD_TRANSACTION_gc = (0x03<<6),   /* Reload at end of transaction */
} DMA_CH_SRCRELOAD_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/*  */
typedef enum DMA_CH_SRCDIR_enum
{
  DMA_CH_SRCDIR_FIXED_gc = (0x00<<4),   /* Fixed */
  DMA_CH_SRCDIR_INC_gc = (0x01<<4),   /* Increment */
  DMA_CH_SRCDIR_DEC_gc = (0x02<<4),   /* Decrement */
} DMA_CH_SRCDIR_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/*  */
typedef enum DMA_CH_DESTRELOAD_enum
{
  DMA_CH_DESTRELOAD_NONE_gc = (0x00<<2),   /* No reload */
  DMA_CH_DESTRELOAD_BLOCK_gc = (0x01<<2),   /* Reload at end of block */
  DMA_CH_DESTRELOAD_BURST_gc = (0x02<<2),   /* Reload at end of burst */
  DMA_CH_DESTRELOAD_TRANSACTION_gc = (0x03<<2),   /* Reload at end of transaction */
} DMA_CH_DESTRELOAD_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/*  */
typedef enum DMA_CH_DESTDIR_enum
{
  DMA_CH_DESTDIR_FIXED_gc = (0x00<<0),   /* Fixed */
  DMA_CH_DESTDIR_INC_gc = (0x01<<0),   /* Increment */
  DMA_CH_DESTDIR_DEC_gc = (0x02<<0),   /* Decrement */
} DMA_CH_DESTDIR_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/*  */
typedef enum DMA_CH_TRIGSRC_enum
{
  DMA_CH_TRIGSRC_OFF_gc = (0x00<<0),   /* Off software triggers only */
  DMA_CH_TRIGSRC_EVSYS_CH0_gc = (0x01<<0),   /* Event System Channel 0 */
  DMA_CH_TRIGSRC_EVSYS_CH1_gc = (0x02<<0),   /* Event System Channel 1 */
  DMA_CH_TRIGSRC_EVSYS_CH2_gc = (0x03<<0),   /* Event System Channel 2 */
  DMA_CH_TRIGSRC_ADCA_CH0_gc = (0x10<<0),   /* ADCA Channel 0 */
  DMA_CH_TRIGSRC_ADCA_CH1_gc = (0x11<<0),   /* ADCA Channel 1 */
  DMA_CH_TRIGSRC_ADCA_CH2_gc = (0x12<<0),   /* ADCA Channel 2 */
  DMA_CH_TRIGSRC_ADCA_CH3_gc = (0x13<<0),   /* ADCA Channel 3 */
  DMA_CH_TRIGSRC_ADCA_CH4_gc = (0x14<<0),   /* ADCA Channel 0,1,2,3 combined */
  DMA_CH_TRIGSRC_DACA_CH0_gc = (0x15<<0),   /* DACA Channel 0 */
  DMA_CH_TRIGSRC_DACA_CH1_gc = (0x16<<0),   /* DACA Channel 1 */
  DMA_CH_TRIGSRC_ADCB_CH0_gc = (0x20<<0),   /* ADCB Channel 0 */
  DMA_CH_TRIGSRC_ADCB_CH1_gc = (0x21<<0),   /* ADCB Channel 1 */
  DMA_CH_TRIGSRC_ADCB_CH2_gc = (0x22<<0),   /* ADCB Channel 2 */
  DMA_CH_TRIGSRC_ADCB_CH3_gc = (0x23<<0),   /* ADCB Channel 3 */
  DMA_CH_TRIGSRC_ADCB_CH4_gc = (0x24<<0),   /* ADCB Channel 4 */
  DMA_CH_TRIGSRC_DACB_CH0_gc = (0x25<<0),   /* DACB Channel 0 */
  DMA_CH_TRIGSRC_DACB_CH1_gc = (0x26<<0),   /* DACB Channel 1 */
  DMA_CH_TRIGSRC_TCC0_OVF_gc = (0x40<<0),   /* Timer/Counter C0 Overflow */
  DMA_CH_TRIGSRC_TCC0_ERR_gc = (0x41<<0),   /* Timer/Counter C0 Error */
  DMA_CH_TRIGSRC_TCC0_CCA_gc = (0x42<<0),   /* Timer/Counter C0 Compare or Capture A */
  DMA_CH_TRIGSRC_TCC0_CCB_gc = (0x43<<0),   /* Timer/Counter C0 Compare or Capture B */
  DMA_CH_TRIGSRC_TCC0_CCC_gc = (0x44<<0),   /* Timer/Counter C0 Compare or Capture C */
  DMA_CH_TRIGSRC_TCC0_CCD_gc = (0x45<<0),   /* Timer/Counter C0 Compare or Capture D */
  DMA_CH_TRIGSRC_TCC1_OVF_gc = (0x46<<0),   /* Timer/Counter C1 Overflow */
  DMA_CH_TRIGSRC_TCC1_ERR_gc = (0x47<<0),   /* Timer/Counter C1 Error */
  DMA_CH_TRIGSRC_TCC1_CCA_gc = (0x48<<0),   /* Timer/Counter C1 Compare or Capture A */
  DMA_CH_TRIGSRC_TCC1_CCB_gc = (0x49<<0),   /* Timer/Counter C1 Compare or Capture B */
  DMA_CH_TRIGSRC_SPIC_gc = (0x4A<<0),   /* SPI C Transfer Complete */
  DMA_CH_TRIGSRC_USARTC0_RXC_gc = (0x4B<<0),   /* USART C0 Receive Complete */
  DMA_CH_TRIGSRC_USARTC0_DRE_gc = (0x4C<<0),   /* USART C0 Data Register Empty */
  DMA_CH_TRIGSRC_USARTC1_RXC_gc = (0x4E<<0),   /* USART C1 Receive Complete */
  DMA_CH_TRIGSRC_USARTC1_DRE_gc = (0x4F<<0),   /* USART C1 Data Register Empty */
  DMA_CH_TRIGSRC_TCD0_OVF_gc = (0x60<<0),   /* Timer/Counter D0 Overflow */
  DMA_CH_TRIGSRC_TCD0_ERR_gc = (0x61<<0),   /* Timer/Counter D0 Error */
  DMA_CH_TRIGSRC_TCD0_CCA_gc = (0x62<<0),   /* Timer/Counter D0 Compare or Capture A */
  DMA_CH_TRIGSRC_TCD0_CCB_gc = (0x63<<0),   /* Timer/Counter D0 Compare or Capture B */
  DMA_CH_TRIGSRC_TCD0_CCC_gc = (0x64<<0),   /* Timer/Counter D0 Compare or Capture C */
  DMA_CH_TRIGSRC_TCD0_CCD_gc = (0x65<<0),   /* Timer/Counter D0 Compare or Capture D */
  DMA_CH_TRIGSRC_TCD1_OVF_gc = (0x66<<0),   /* Timer/Counter D1 Overflow */
  DMA_CH_TRIGSRC_TCD1_ERR_gc = (0x67<<0),   /* Timer/Counter D1 Error */
  DMA_CH_TRIGSRC_TCD1_CCA_gc = (0x68<<0),   /* Timer/Counter D1 Compare or Capture A */
  DMA_CH_TRIGSRC_TCD1_CCB_gc = (0x69<<0),   /* Timer/Counter D1 Compare or Capture B */
  DMA_CH_TRIGSRC_SPID_gc = (0x6A<<0),   /* SPI D Transfer Complete */
  DMA_CH_TRIGSRC_USARTD0_RXC_gc = (0x6B<<0),   /* USART D0 Receive Complete */
  DMA_CH_TRIGSRC_USARTD0_DRE_gc = (0x6C<<0),   /* USART D0 Data Register Empty */
  DMA_CH_TRIGSRC_USARTD1_RXC_gc = (0x6E<<0),   /* USART D1 Receive Complete */
  DMA_CH_TRIGSRC_USARTD1_DRE_gc = (0x6F<<0),   /* USART D1 Data Register Empty */
  DMA_CH_TRIGSRC_TCE0_OVF_gc = (0x80<<0),   /* Timer/Counter E0 Overflow */
  DMA_CH_TRIGSRC_TCE0_ERR_gc = (0x81<<0),   /* Timer/Counter E0 Error */
  DMA_CH_TRIGSRC_TCE0_CCA_gc = (0x82<<0),   /* Timer/Counter E0 Compare or Capture A */
  DMA_CH_TRIGSRC_TCE0_CCB_gc = (0x83<<0),   /* Timer/Counter E0 Compare or Capture B */
  DMA_CH_TRIGSRC_TCE0_CCC_gc = (0x84<<0),   /* Timer/Counter E0 Compare or Capture C */
  DMA_CH_TRIGSRC_TCE0_CCD_gc = (0x85<<0),   /* Timer/Counter E0 Compare or Capture D */
  DMA_CH_TRIGSRC_TCE1_OVF_gc = (0x86<<0),   /* Timer/Counter E1 Overflow */
  DMA_CH_TRIGSRC_TCE1_ERR_gc = (0x87<<0),   /* Timer/Counter E1 Error */
  DMA_CH_TRIGSRC_TCE1_CCA_gc = (0x88<<0),   /* Timer/Counter E1 Compare or Capture A */
  DMA_CH_TRIGSRC_TCE1_CCB_gc = (0x89<<0),   /* Timer/Counter E1 Compare or Capture B */
  DMA_CH_TRIGSRC_SPIE_gc = (0x8A<<0),   /* SPI E Transfer Complete */
  DMA_CH_TRIGSRC_USARTE0_RXC_gc = (0x8B<<0),   /* USART E0 Receive Complete */
  DMA_CH_TRIGSRC_USARTE0_DRE_gc = (0x8C<<0),   /* USART E0 Data Register Empty */
  DMA_CH_TRIGSRC_USARTE1_RXC_gc = (0x8E<<0),   /* USART E1 Receive Complete */
  DMA_CH_TRIGSRC_USARTE1_DRE_gc = (0x8F<<0),   /* USART E1 Data Register Empty */
  DMA_CH_TRIGSRC_TCF0_OVF_gc = (0xA0<<0),   /* Timer/Counter F0 Overflow */
  DMA_CH_TRIGSRC_TCF0_ERR_gc = (0xA1<<0),   /* Timer/Counter F0 Error */
  DMA_CH_TRIGSRC_TCF0_CCA_gc = (0xA2<<0),   /* Timer/Counter F0 Compare or Capture A */
  DMA_CH_TRIGSRC_TCF0_CCB_gc = (0xA3<<0),   /* Timer/Counter F0 Compare or Capture B */
  DMA_CH_TRIGSRC_TCF0_CCC_gc = (0xA4<<0),   /* Timer/Counter F0 Compare or Capture C */
  DMA_CH_TRIGSRC_TCF0_CCD_gc = (0xA5<<0),   /* Timer/Counter F0 Compare or Capture D */
  DMA_CH_TRIGSRC_TCF1_OVF_gc = (0xA6<<0),   /* Timer/Counter F1 Overflow */
  DMA_CH_TRIGSRC_TCF1_ERR_gc = (0xA7<<0),   /* Timer/Counter F1 Error */
  DMA_CH_TRIGSRC_TCF1_CCA_gc = (0xA8<<0),   /* Timer/Counter F1 Compare or Capture A */
  DMA_CH_TRIGSRC_TCF1_CCB_gc = (0xA9<<0),   /* Timer/Counter F1 Compare or Capture B */
  DMA_CH_TRIGSRC_SPIF_gc = (0xAA<<0),   /* SPI F Transfer Complete */
  DMA_CH_TRIGSRC_USARTF0_RXC_gc = (0xAB<<0),   /* USART F0 Receive Complete */
  DMA_CH_TRIGSRC_USARTF0_DRE_gc = (0xAC<<0),   /* USART F0 Data Register Empty */
  DMA_CH_TRIGSRC_USARTF1_RXC_gc = (0xAE<<0),   /* USART F1 Receive Complete */
  DMA_CH_TRIGSRC_USARTF1_DRE_gc = (0xAF<<0),   /* USART F1 Data Register Empty */
} DMA_CH_TRIGSRC_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/*  */
typedef enum DMA_DBUFMODE_enum
{
  DMA_DBUFMODE_DISABLED_gc = (0x00<<2),   /* Double buffering disabled */
  DMA_DBUFMODE_CH01_gc = (0x01<<2),   /* Double buffering enabled on channel 0/1 */
  DMA_DBUFMODE_CH23_gc = (0x02<<2),   /* Double buffering enabled on channel 2/3 */
  DMA_DBUFMODE_CH01CH23_gc = (0x03<<2),   /* Double buffering enabled on ch. 0/1 and ch. 2/3 */
} DMA_DBUFMODE_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/*  */
typedef enum DMA_PRIMODE_enum
{
  DMA_PRIMODE_RR0123_gc = (0x00<<0),   /* Round Robin */
  DMA_PRIMODE_CH0RR123_gc = (0x01<<0),   /* Channel 0 > Round Robin on channel 1/2/3 */
  DMA_PRIMODE_CH01RR23_gc = (0x02<<0),   /* Channel 0 > channel 1 > Round Robin on channel 2/3 */
  DMA_PRIMODE_CH0123_gc = (0x03<<0),   /* Channel 0 > channel 1 > channel 2 > channel 3 */
} DMA_PRIMODE_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/*  */
typedef enum DMA_CH_INTLVL_enum
{
  DMA_CH_INTLVL_OFF_gc = (0x00<<2),   /* Interrupt disabled */
  DMA_CH_INTLVL_LO_gc = (0x01<<2),   /* Low level */
  DMA_CH_INTLVL_MED_gc = (0x02<<2),   /* Medium level */
  DMA_CH_INTLVL_HI_gc = (0x03<<2),   /* High level */
} DMA_CH_INTLVL_t;
#endif /* !defined (__ASSEMBLER__) */


/*
--------------------------------------------------------------------------
 EVSYS - Event System
--------------------------------------------------------------------------
*/

/* EVSYS.CH0MUX bit masks and bit positions */

        
#define EVSYS_CHMUX_gm 0xFF // Event Channel 0 Multiplexer group mask
#define EVSYS_CHMUX_bp 0 // Event Channel 0 Multiplexer group position

#define EVSYS_CHMUX0_bm (1<<0) // Event Channel 0 Multiplexer bit 0 mask
#define EVSYS_CHMUX0_bp 0 // Event Channel 0 Multiplexer bit 0 position
#define EVSYS_CHMUX1_bm (1<<1) // Event Channel 0 Multiplexer bit 1 mask
#define EVSYS_CHMUX1_bp 1 // Event Channel 0 Multiplexer bit 1 position
#define EVSYS_CHMUX2_bm (1<<2) // Event Channel 0 Multiplexer bit 2 mask
#define EVSYS_CHMUX2_bp 2 // Event Channel 0 Multiplexer bit 2 position
#define EVSYS_CHMUX3_bm (1<<3) // Event Channel 0 Multiplexer bit 3 mask
#define EVSYS_CHMUX3_bp 3 // Event Channel 0 Multiplexer bit 3 position
#define EVSYS_CHMUX4_bm (1<<4) // Event Channel 0 Multiplexer bit 4 mask
#define EVSYS_CHMUX4_bp 4 // Event Channel 0 Multiplexer bit 4 position
#define EVSYS_CHMUX5_bm (1<<5) // Event Channel 0 Multiplexer bit 5 mask
#define EVSYS_CHMUX5_bp 5 // Event Channel 0 Multiplexer bit 5 position
#define EVSYS_CHMUX6_bm (1<<6) // Event Channel 0 Multiplexer bit 6 mask
#define EVSYS_CHMUX6_bp 6 // Event Channel 0 Multiplexer bit 6 position
#define EVSYS_CHMUX7_bm (1<<7) // Event Channel 0 Multiplexer bit 7 mask
#define EVSYS_CHMUX7_bp 7 // Event Channel 0 Multiplexer bit 7 position

/* EVSYS.CH1MUX bit masks and bit positions */

        
/* Masks for CHMUX aready defined */
            

/* EVSYS.CH2MUX bit masks and bit positions */

        
/* Masks for CHMUX aready defined */
            

/* EVSYS.CH3MUX bit masks and bit positions */

        
/* Masks for CHMUX aready defined */
            

/* EVSYS.CH4MUX bit masks and bit positions */

        
/* Masks for CHMUX aready defined */
            

/* EVSYS.CH5MUX bit masks and bit positions */

        
/* Masks for CHMUX aready defined */
            

/* EVSYS.CH6MUX bit masks and bit positions */

        
/* Masks for CHMUX aready defined */
            

/* EVSYS.CH7MUX bit masks and bit positions */

        
/* Masks for CHMUX aready defined */
            

/* EVSYS.CH0CTRL bit masks and bit positions */

        
#define EVSYS_QDIRM_gm 0x60 // Quadrature Decoder Index Recognition Mode group mask
#define EVSYS_QDIRM_bp 5 // Quadrature Decoder Index Recognition Mode group position

#define EVSYS_QDIRM0_bm (1<<5) // Quadrature Decoder Index Recognition Mode bit 0 mask
#define EVSYS_QDIRM0_bp 5 // Quadrature Decoder Index Recognition Mode bit 0 position
#define EVSYS_QDIRM1_bm (1<<6) // Quadrature Decoder Index Recognition Mode bit 1 mask
#define EVSYS_QDIRM1_bp 6 // Quadrature Decoder Index Recognition Mode bit 1 position
#define EVSYS_QDIEN_bm 0x10 // Quadrature Decoder Index Enable bit mask
#define EVSYS_QDIEN_bp 4 // Quadrature Decoder Index Enable bit position
#define EVSYS_QDEN_bm 0x08 // Quadrature Decoder Enable bit mask
#define EVSYS_QDEN_bp 3 // Quadrature Decoder Enable bit position
#define EVSYS_DIGFILT_gm 0x07 // Digital Filter group mask
#define EVSYS_DIGFILT_bp 0 // Digital Filter group position

#define EVSYS_DIGFILT0_bm (1<<0) // Digital Filter bit 0 mask
#define EVSYS_DIGFILT0_bp 0 // Digital Filter bit 0 position
#define EVSYS_DIGFILT1_bm (1<<1) // Digital Filter bit 1 mask
#define EVSYS_DIGFILT1_bp 1 // Digital Filter bit 1 position
#define EVSYS_DIGFILT2_bm (1<<2) // Digital Filter bit 2 mask
#define EVSYS_DIGFILT2_bp 2 // Digital Filter bit 2 position

/* EVSYS.CH1CTRL bit masks and bit positions */

        
/* Masks for DIGFILT aready defined */
            

/* EVSYS.CH2CTRL bit masks and bit positions */

        
/* Masks for QDIRM aready defined */
            
/* Masks for QDIEN aready defined */
            
/* Masks for QDEN aready defined */
            
/* Masks for DIGFILT aready defined */
            

/* EVSYS.CH3CTRL bit masks and bit positions */

        
/* Masks for DIGFILT aready defined */
            

/* EVSYS.CH4CTRL bit masks and bit positions */

        
/* Masks for QDIRM aready defined */
            
/* Masks for QDIEN aready defined */
            
/* Masks for QDEN aready defined */
            
/* Masks for DIGFILT aready defined */
            

/* EVSYS.CH5CTRL bit masks and bit positions */

        
/* Masks for DIGFILT aready defined */
            

/* EVSYS.CH6CTRL bit masks and bit positions */

        
/* Masks for DIGFILT aready defined */
            

/* EVSYS.CH7CTRL bit masks and bit positions */

        
/* Masks for DIGFILT aready defined */
            

#if !defined (__ASSEMBLER__)
/*  */
typedef enum EVSYS_QDIRM_enum
{
  EVSYS_QDIRM_00_gc = (0x00<<5),   /* QDPH0 = 0, QDPH90 = 0 */
  EVSYS_QDIRM_01_gc = (0x01<<5),   /* QDPH0 = 0, QDPH90 = 1 */
  EVSYS_QDIRM_10_gc = (0x02<<5),   /* QDPH0 = 1, QDPH90 = 0 */
  EVSYS_QDIRM_11_gc = (0x03<<5),   /* QDPH0 = 1, QDPH90 = 1 */
} EVSYS_QDIRM_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/*  */
typedef enum EVSYS_DIGFILT_enum
{
  EVSYS_DIGFILT_1SAMPLE_gc = (0x00<<0),   /* 1 SAMPLE */
  EVSYS_DIGFILT_2SAMPLES_gc = (0x01<<0),   /* 2 SAMPLES */
  EVSYS_DIGFILT_3SAMPLES_gc = (0x02<<0),   /* 3 SAMPLES */
  EVSYS_DIGFILT_4SAMPLES_gc = (0x03<<0),   /* 4 SAMPLES */
  EVSYS_DIGFILT_5SAMPLES_gc = (0x04<<0),   /* 5 SAMPLES */
  EVSYS_DIGFILT_6SAMPLES_gc = (0x05<<0),   /* 6 SAMPLES */
  EVSYS_DIGFILT_7SAMPLES_gc = (0x06<<0),   /* 7 SAMPLES */
  EVSYS_DIGFILT_8SAMPLES_gc = (0x07<<0),   /* 8 SAMPLES */
} EVSYS_DIGFILT_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/*  */
typedef enum EVSYS_CHMUX_enum
{
  EVSYS_CHMUX_OFF_gc = (0x00<<0),   /* Off */
  EVSYS_CHMUX_RTC_OVF_gc = (0x08<<0),   /* RTC Overflow */
  EVSYS_CHMUX_RTC_CMP_gc = (0x09<<0),   /* RTC Compare Match */
  EVSYS_CHMUX_ACA_CH0_gc = (0x10<<0),   /* Analog Comparator A Channel 0 */
  EVSYS_CHMUX_ACA_CH1_gc = (0x11<<0),   /* Analog Comparator A Channel 1 */
  EVSYS_CHMUX_ACA_WIN_gc = (0x12<<0),   /* Analog Comparator A Window */
  EVSYS_CHMUX_ACB_CH0_gc = (0x13<<0),   /* Analog Comparator B Channel 0 */
  EVSYS_CHMUX_ACB_CH1_gc = (0x14<<0),   /* Analog Comparator B Channel 1 */
  EVSYS_CHMUX_ACB_WIN_gc = (0x15<<0),   /* Analog Comparator B Window */
  EVSYS_CHMUX_ADCA_CH0_gc = (0x20<<0),   /* ADC A Channel 0 */
  EVSYS_CHMUX_ADCA_CH1_gc = (0x21<<0),   /* ADC A Channel 1 */
  EVSYS_CHMUX_ADCA_CH2_gc = (0x22<<0),   /* ADC A Channel 2 */
  EVSYS_CHMUX_ADCA_CH3_gc = (0x23<<0),   /* ADC A Channel 3 */
  EVSYS_CHMUX_ADCB_CH0_gc = (0x24<<0),   /* ADC B Channel 0 */
  EVSYS_CHMUX_ADCB_CH1_gc = (0x25<<0),   /* ADC B Channel 1 */
  EVSYS_CHMUX_ADCB_CH2_gc = (0x26<<0),   /* ADC B Channel 2 */
  EVSYS_CHMUX_ADCB_CH3_gc = (0x27<<0),   /* ADC B Channel 3 */
  EVSYS_CHMUX_PORTA_PIN0_gc = (0x50<<0),   /* Port A, Pin0 */
  EVSYS_CHMUX_PORTA_PIN1_gc = (0x51<<0),   /* Port A, Pin1 */
  EVSYS_CHMUX_PORTA_PIN2_gc = (0x52<<0),   /* Port A, Pin2 */
  EVSYS_CHMUX_PORTA_PIN3_gc = (0x53<<0),   /* Port A, Pin3 */
  EVSYS_CHMUX_PORTA_PIN4_gc = (0x54<<0),   /* Port A, Pin4 */
  EVSYS_CHMUX_PORTA_PIN5_gc = (0x55<<0),   /* Port A, Pin5 */
  EVSYS_CHMUX_PORTA_PIN6_gc = (0x56<<0),   /* Port A, Pin6 */
  EVSYS_CHMUX_PORTA_PIN7_gc = (0x57<<0),   /* Port A, Pin7 */
  EVSYS_CHMUX_PORTB_PIN0_gc = (0x58<<0),   /* Port B, Pin0 */
  EVSYS_CHMUX_PORTB_PIN1_gc = (0x59<<0),   /* Port B, Pin1 */
  EVSYS_CHMUX_PORTB_PIN2_gc = (0x5A<<0),   /* Port B, Pin2 */
  EVSYS_CHMUX_PORTB_PIN3_gc = (0x5B<<0),   /* Port B, Pin3 */
  EVSYS_CHMUX_PORTB_PIN4_gc = (0x5C<<0),   /* Port B, Pin4 */
  EVSYS_CHMUX_PORTB_PIN5_gc = (0x5D<<0),   /* Port B, Pin5 */
  EVSYS_CHMUX_PORTB_PIN6_gc = (0x5E<<0),   /* Port B, Pin6 */
  EVSYS_CHMUX_PORTB_PIN7_gc = (0x5F<<0),   /* Port B, Pin7 */
  EVSYS_CHMUX_PORTC_PIN0_gc = (0x60<<0),   /* Port C, Pin0 */
  EVSYS_CHMUX_PORTC_PIN1_gc = (0x61<<0),   /* Port C, Pin1 */
  EVSYS_CHMUX_PORTC_PIN2_gc = (0x62<<0),   /* Port C, Pin2 */
  EVSYS_CHMUX_PORTC_PIN3_gc = (0x63<<0),   /* Port C, Pin3 */
  EVSYS_CHMUX_PORTC_PIN4_gc = (0x64<<0),   /* Port C, Pin4 */
  EVSYS_CHMUX_PORTC_PIN5_gc = (0x65<<0),   /* Port C, Pin5 */
  EVSYS_CHMUX_PORTC_PIN6_gc = (0x66<<0),   /* Port C, Pin6 */
  EVSYS_CHMUX_PORTC_PIN7_gc = (0x67<<0),   /* Port C, Pin7 */
  EVSYS_CHMUX_PORTD_PIN0_gc = (0x68<<0),   /* Port D, Pin0 */
  EVSYS_CHMUX_PORTD_PIN1_gc = (0x69<<0),   /* Port D, Pin1 */
  EVSYS_CHMUX_PORTD_PIN2_gc = (0x6A<<0),   /* Port D, Pin2 */
  EVSYS_CHMUX_PORTD_PIN3_gc = (0x6B<<0),   /* Port D, Pin3 */
  EVSYS_CHMUX_PORTD_PIN4_gc = (0x6C<<0),   /* Port D, Pin4 */
  EVSYS_CHMUX_PORTD_PIN5_gc = (0x6D<<0),   /* Port D, Pin5 */
  EVSYS_CHMUX_PORTD_PIN6_gc = (0x6E<<0),   /* Port D, Pin6 */
  EVSYS_CHMUX_PORTD_PIN7_gc = (0x6F<<0),   /* Port D, Pin7 */
  EVSYS_CHMUX_PORTE_PIN0_gc = (0x70<<0),   /* Port E, Pin0 */
  EVSYS_CHMUX_PORTE_PIN1_gc = (0x71<<0),   /* Port E, Pin1 */
  EVSYS_CHMUX_PORTE_PIN2_gc = (0x72<<0),   /* Port E, Pin2 */
  EVSYS_CHMUX_PORTE_PIN3_gc = (0x73<<0),   /* Port E, Pin3 */
  EVSYS_CHMUX_PORTE_PIN4_gc = (0x74<<0),   /* Port E, Pin4 */
  EVSYS_CHMUX_PORTE_PIN5_gc = (0x75<<0),   /* Port E, Pin5 */
  EVSYS_CHMUX_PORTE_PIN6_gc = (0x76<<0),   /* Port E, Pin6 */
  EVSYS_CHMUX_PORTE_PIN7_gc = (0x77<<0),   /* Port E, Pin7 */
  EVSYS_CHMUX_PORTF_PIN0_gc = (0x78<<0),   /* Port F, Pin0 */
  EVSYS_CHMUX_PORTF_PIN1_gc = (0x79<<0),   /* Port F, Pin1 */
  EVSYS_CHMUX_PORTF_PIN2_gc = (0x7A<<0),   /* Port F, Pin2 */
  EVSYS_CHMUX_PORTF_PIN3_gc = (0x7B<<0),   /* Port F, Pin3 */
  EVSYS_CHMUX_PORTF_PIN4_gc = (0x7C<<0),   /* Port F, Pin4 */
  EVSYS_CHMUX_PORTF_PIN5_gc = (0x7D<<0),   /* Port F, Pin5 */
  EVSYS_CHMUX_PORTF_PIN6_gc = (0x7E<<0),   /* Port F, Pin6 */
  EVSYS_CHMUX_PORTF_PIN7_gc = (0x7F<<0),   /* Port F, Pin7 */
  EVSYS_CHMUX_PRESCALER_1_gc = (0x80<<0),   /* Prescaler, divide by 1 */
  EVSYS_CHMUX_PRESCALER_2_gc = (0x81<<0),   /* Prescaler, divide by 2 */
  EVSYS_CHMUX_PRESCALER_4_gc = (0x82<<0),   /* Prescaler, divide by 4 */
  EVSYS_CHMUX_PRESCALER_8_gc = (0x83<<0),   /* Prescaler, divide by 8 */
  EVSYS_CHMUX_PRESCALER_16_gc = (0x84<<0),   /* Prescaler, divide by 16 */
  EVSYS_CHMUX_PRESCALER_32_gc = (0x85<<0),   /* Prescaler, divide by 32 */
  EVSYS_CHMUX_PRESCALER_64_gc = (0x86<<0),   /* Prescaler, divide by 64 */
  EVSYS_CHMUX_PRESCALER_128_gc = (0x87<<0),   /* Prescaler, divide by 128 */
  EVSYS_CHMUX_PRESCALER_256_gc = (0x88<<0),   /* Prescaler, divide by 256 */
  EVSYS_CHMUX_PRESCALER_512_gc = (0x89<<0),   /* Prescaler, divide by 512 */
  EVSYS_CHMUX_PRESCALER_1024_gc = (0x8A<<0),   /* Prescaler, divide by 1024 */
  EVSYS_CHMUX_PRESCALER_2048_gc = (0x8B<<0),   /* Prescaler, divide by 2048 */
  EVSYS_CHMUX_PRESCALER_4096_gc = (0x8C<<0),   /* Prescaler, divide by 4096 */
  EVSYS_CHMUX_PRESCALER_8192_gc = (0x8D<<0),   /* Prescaler, divide by 8192 */
  EVSYS_CHMUX_PRESCALER_16384_gc = (0x8E<<0),   /* Prescaler, divide by 16384 */
  EVSYS_CHMUX_PRESCALER_32768_gc = (0x8F<<0),   /* Prescaler, divide by 32768 */
  EVSYS_CHMUX_TCC0_OVF_gc = (0xC0<<0),   /* Timer/Counter C0 Overflow */
  EVSYS_CHMUX_TCC0_ERR_gc = (0xC1<<0),   /* Timer/Counter C0 Error */
  EVSYS_CHMUX_TCC0_CCA_gc = (0xC4<<0),   /* Timer/Counter C0 Compare or Capture A */
  EVSYS_CHMUX_TCC0_CCB_gc = (0xC5<<0),   /* Timer/Counter C0 Compare or Capture B */
  EVSYS_CHMUX_TCC0_CCC_gc = (0xC6<<0),   /* Timer/Counter C0 Compare or Capture C */
  EVSYS_CHMUX_TCC0_CCD_gc = (0xC7<<0),   /* Timer/Counter C0 Compare or Capture D */
  EVSYS_CHMUX_TCC1_OVF_gc = (0xC8<<0),   /* Timer/Counter C1 Overflow */
  EVSYS_CHMUX_TCC1_ERR_gc = (0xC9<<0),   /* Timer/Counter C1 Error */
  EVSYS_CHMUX_TCC1_CCA_gc = (0xCC<<0),   /* Timer/Counter C1 Compare or Capture A */
  EVSYS_CHMUX_TCC1_CCB_gc = (0xCD<<0),   /* Timer/Counter C1 Compare or Capture B */
  EVSYS_CHMUX_TCD0_OVF_gc = (0xD0<<0),   /* Timer/Counter D0 Overflow */
  EVSYS_CHMUX_TCD0_ERR_gc = (0xD1<<0),   /* Timer/Counter D0 Error */
  EVSYS_CHMUX_TCD0_CCA_gc = (0xD4<<0),   /* Timer/Counter D0 Compare or Capture A */
  EVSYS_CHMUX_TCD0_CCB_gc = (0xD5<<0),   /* Timer/Counter D0 Compare or Capture B */
  EVSYS_CHMUX_TCD0_CCC_gc = (0xD6<<0),   /* Timer/Counter D0 Compare or Capture C */
  EVSYS_CHMUX_TCD0_CCD_gc = (0xD7<<0),   /* Timer/Counter D0 Compare or Capture D */
  EVSYS_CHMUX_TCD1_OVF_gc = (0xD8<<0),   /* Timer/Counter D1 Overflow */
  EVSYS_CHMUX_TCD1_ERR_gc = (0xD9<<0),   /* Timer/Counter D1 Error */
  EVSYS_CHMUX_TCD1_CCA_gc = (0xDC<<0),   /* Timer/Counter D1 Compare or Capture A */
  EVSYS_CHMUX_TCD1_CCB_gc = (0xDD<<0),   /* Timer/Counter D1 Compare or Capture B */
  EVSYS_CHMUX_TCE0_OVF_gc = (0xE0<<0),   /* Timer/Counter E0 Overflow */
  EVSYS_CHMUX_TCE0_ERR_gc = (0xE1<<0),   /* Timer/Counter E0 Error */
  EVSYS_CHMUX_TCE0_CCA_gc = (0xE4<<0),   /* Timer/Counter E0 Compare or Capture A */
  EVSYS_CHMUX_TCE0_CCB_gc = (0xE5<<0),   /* Timer/Counter E0 Compare or Capture B */
  EVSYS_CHMUX_TCE0_CCC_gc = (0xE6<<0),   /* Timer/Counter E0 Compare or Capture C */
  EVSYS_CHMUX_TCE0_CCD_gc = (0xE7<<0),   /* Timer/Counter E0 Compare or Capture D */
  EVSYS_CHMUX_TCE1_OVF_gc = (0xE8<<0),   /* Timer/Counter E1 Overflow */
  EVSYS_CHMUX_TCE1_ERR_gc = (0xE9<<0),   /* Timer/Counter E1 Error */
  EVSYS_CHMUX_TCE1_CCA_gc = (0xEC<<0),   /* Timer/Counter E1 Compare or Capture A */
  EVSYS_CHMUX_TCE1_CCB_gc = (0xED<<0),   /* Timer/Counter E1 Compare or Capture B */
  EVSYS_CHMUX_TCF0_OVF_gc = (0xF0<<0),   /* Timer/Counter F0 Overflow */
  EVSYS_CHMUX_TCF0_ERR_gc = (0xF1<<0),   /* Timer/Counter F0 Error */
  EVSYS_CHMUX_TCF0_CCA_gc = (0xF4<<0),   /* Timer/Counter F0 Compare or Capture A */
  EVSYS_CHMUX_TCF0_CCB_gc = (0xF5<<0),   /* Timer/Counter F0 Compare or Capture B */
  EVSYS_CHMUX_TCF0_CCC_gc = (0xF6<<0),   /* Timer/Counter F0 Compare or Capture C */
  EVSYS_CHMUX_TCF0_CCD_gc = (0xF7<<0),   /* Timer/Counter F0 Compare or Capture D */
  EVSYS_CHMUX_TCF1_OVF_gc = (0xF8<<0),   /* Timer/Counter F1 Overflow */
  EVSYS_CHMUX_TCF1_ERR_gc = (0xF9<<0),   /* Timer/Counter F1 Error */
  EVSYS_CHMUX_TCF1_CCA_gc = (0xFC<<0),   /* Timer/Counter F1 Compare or Capture A */
  EVSYS_CHMUX_TCF1_CCB_gc = (0xFD<<0),   /* Timer/Counter F1 Compare or Capture B */
} EVSYS_CHMUX_t;
#endif /* !defined (__ASSEMBLER__) */


/*
--------------------------------------------------------------------------
 NVM - Non Volatile Memory
--------------------------------------------------------------------------
*/

/* NVM.CMD bit masks and bit positions */

        
#define NVM_CMD_gm 0xFF // Command group mask
#define NVM_CMD_bp 0 // Command group position

#define NVM_CMD0_bm (1<<0) // Command bit 0 mask
#define NVM_CMD0_bp 0 // Command bit 0 position
#define NVM_CMD1_bm (1<<1) // Command bit 1 mask
#define NVM_CMD1_bp 1 // Command bit 1 position
#define NVM_CMD2_bm (1<<2) // Command bit 2 mask
#define NVM_CMD2_bp 2 // Command bit 2 position
#define NVM_CMD3_bm (1<<3) // Command bit 3 mask
#define NVM_CMD3_bp 3 // Command bit 3 position
#define NVM_CMD4_bm (1<<4) // Command bit 4 mask
#define NVM_CMD4_bp 4 // Command bit 4 position
#define NVM_CMD5_bm (1<<5) // Command bit 5 mask
#define NVM_CMD5_bp 5 // Command bit 5 position
#define NVM_CMD6_bm (1<<6) // Command bit 6 mask
#define NVM_CMD6_bp 6 // Command bit 6 position
#define NVM_CMD7_bm (1<<7) // Command bit 7 mask
#define NVM_CMD7_bp 7 // Command bit 7 position

/* NVM.CTRLA bit masks and bit positions */

        
#define NVM_CMDEX_bm 0x01 // Command Execute bit mask
#define NVM_CMDEX_bp 0 // Command Execute bit position

/* NVM.CTRLB bit masks and bit positions */

        
#define NVM_EEMAPEN_bm 0x08 // EEPROM Mapping Enable bit mask
#define NVM_EEMAPEN_bp 3 // EEPROM Mapping Enable bit position
#define NVM_FPRM_bm 0x04 // Flash Power Reduction Enable bit mask
#define NVM_FPRM_bp 2 // Flash Power Reduction Enable bit position
#define NVM_EPRM_bm 0x02 // EEPROM Power Reduction Enable bit mask
#define NVM_EPRM_bp 1 // EEPROM Power Reduction Enable bit position
#define NVM_SPMLOCK_bm 0x01 // SPM Lock bit mask
#define NVM_SPMLOCK_bp 0 // SPM Lock bit position

/* NVM.INTCTRL bit masks and bit positions */

        
#define NVM_SPMLVL_gm 0x0C // SPM Interrupt Level group mask
#define NVM_SPMLVL_bp 2 // SPM Interrupt Level group position

#define NVM_SPMLVL0_bm (1<<2) // SPM Interrupt Level bit 0 mask
#define NVM_SPMLVL0_bp 2 // SPM Interrupt Level bit 0 position
#define NVM_SPMLVL1_bm (1<<3) // SPM Interrupt Level bit 1 mask
#define NVM_SPMLVL1_bp 3 // SPM Interrupt Level bit 1 position
#define NVM_EELVL_gm 0x03 // EEPROM Interrupt Level group mask
#define NVM_EELVL_bp 0 // EEPROM Interrupt Level group position

#define NVM_EELVL0_bm (1<<0) // EEPROM Interrupt Level bit 0 mask
#define NVM_EELVL0_bp 0 // EEPROM Interrupt Level bit 0 position
#define NVM_EELVL1_bm (1<<1) // EEPROM Interrupt Level bit 1 mask
#define NVM_EELVL1_bp 1 // EEPROM Interrupt Level bit 1 position

/* NVM.STATUS bit masks and bit positions */

        
#define NVM_NVMBUSY_bm 0x80 // Non-volatile Memory Busy bit mask
#define NVM_NVMBUSY_bp 7 // Non-volatile Memory Busy bit position
#define NVM_FBUSY_bm 0x40 // Flash Memory Busy bit mask
#define NVM_FBUSY_bp 6 // Flash Memory Busy bit position
#define NVM_EELOAD_bm 0x02 // EEPROM Page Buffer Active Loading bit mask
#define NVM_EELOAD_bp 1 // EEPROM Page Buffer Active Loading bit position
#define NVM_FLOAD_bm 0x01 // Flash Page Buffer Active Loading bit mask
#define NVM_FLOAD_bp 0 // Flash Page Buffer Active Loading bit position

/* NVM.LOCKBITS bit masks and bit positions */

        
#define NVM_BLBB_gm 0xC0 // Boot Lock Bits - Boot Section group mask
#define NVM_BLBB_bp 6 // Boot Lock Bits - Boot Section group position

#define NVM_BLBB0_bm (1<<6) // Boot Lock Bits - Boot Section bit 0 mask
#define NVM_BLBB0_bp 6 // Boot Lock Bits - Boot Section bit 0 position
#define NVM_BLBB1_bm (1<<7) // Boot Lock Bits - Boot Section bit 1 mask
#define NVM_BLBB1_bp 7 // Boot Lock Bits - Boot Section bit 1 position
#define NVM_BLBA_gm 0x30 // Boot Lock Bits - Application Section group mask
#define NVM_BLBA_bp 4 // Boot Lock Bits - Application Section group position

#define NVM_BLBA0_bm (1<<4) // Boot Lock Bits - Application Section bit 0 mask
#define NVM_BLBA0_bp 4 // Boot Lock Bits - Application Section bit 0 position
#define NVM_BLBA1_bm (1<<5) // Boot Lock Bits - Application Section bit 1 mask
#define NVM_BLBA1_bp 5 // Boot Lock Bits - Application Section bit 1 position
#define NVM_BLBAT_gm 0x0C // Boot Lock Bits - Application Table group mask
#define NVM_BLBAT_bp 2 // Boot Lock Bits - Application Table group position

#define NVM_BLBAT0_bm (1<<2) // Boot Lock Bits - Application Table bit 0 mask
#define NVM_BLBAT0_bp 2 // Boot Lock Bits - Application Table bit 0 position
#define NVM_BLBAT1_bm (1<<3) // Boot Lock Bits - Application Table bit 1 mask
#define NVM_BLBAT1_bp 3 // Boot Lock Bits - Application Table bit 1 position
#define NVM_LB_gm 0x03 // Lock Bits group mask
#define NVM_LB_bp 0 // Lock Bits group position

#define NVM_LB0_bm (1<<0) // Lock Bits bit 0 mask
#define NVM_LB0_bp 0 // Lock Bits bit 0 position
#define NVM_LB1_bm (1<<1) // Lock Bits bit 1 mask
#define NVM_LB1_bp 1 // Lock Bits bit 1 position

/* NVM_LOCKBITS.LOCKBITS bit masks and bit positions */

        
#define NVM_LOCKBITS_BLBB_gm 0xC0 // Boot Lock Bits - Boot Section group mask
#define NVM_LOCKBITS_BLBB_bp 6 // Boot Lock Bits - Boot Section group position

#define NVM_LOCKBITS_BLBB0_bm (1<<6) // Boot Lock Bits - Boot Section bit 0 mask
#define NVM_LOCKBITS_BLBB0_bp 6 // Boot Lock Bits - Boot Section bit 0 position
#define NVM_LOCKBITS_BLBB1_bm (1<<7) // Boot Lock Bits - Boot Section bit 1 mask
#define NVM_LOCKBITS_BLBB1_bp 7 // Boot Lock Bits - Boot Section bit 1 position
#define NVM_LOCKBITS_BLBA_gm 0x30 // Boot Lock Bits - Application Section group mask
#define NVM_LOCKBITS_BLBA_bp 4 // Boot Lock Bits - Application Section group position

#define NVM_LOCKBITS_BLBA0_bm (1<<4) // Boot Lock Bits - Application Section bit 0 mask
#define NVM_LOCKBITS_BLBA0_bp 4 // Boot Lock Bits - Application Section bit 0 position
#define NVM_LOCKBITS_BLBA1_bm (1<<5) // Boot Lock Bits - Application Section bit 1 mask
#define NVM_LOCKBITS_BLBA1_bp 5 // Boot Lock Bits - Application Section bit 1 position
#define NVM_LOCKBITS_BLBAT_gm 0x0C // Boot Lock Bits - Application Table group mask
#define NVM_LOCKBITS_BLBAT_bp 2 // Boot Lock Bits - Application Table group position

#define NVM_LOCKBITS_BLBAT0_bm (1<<2) // Boot Lock Bits - Application Table bit 0 mask
#define NVM_LOCKBITS_BLBAT0_bp 2 // Boot Lock Bits - Application Table bit 0 position
#define NVM_LOCKBITS_BLBAT1_bm (1<<3) // Boot Lock Bits - Application Table bit 1 mask
#define NVM_LOCKBITS_BLBAT1_bp 3 // Boot Lock Bits - Application Table bit 1 position
#define NVM_LOCKBITS_LB_gm 0x03 // Lock Bits group mask
#define NVM_LOCKBITS_LB_bp 0 // Lock Bits group position

#define NVM_LOCKBITS_LB0_bm (1<<0) // Lock Bits bit 0 mask
#define NVM_LOCKBITS_LB0_bp 0 // Lock Bits bit 0 position
#define NVM_LOCKBITS_LB1_bm (1<<1) // Lock Bits bit 1 mask
#define NVM_LOCKBITS_LB1_bp 1 // Lock Bits bit 1 position

/* NVM_FUSES.FUSEBYTE0 bit masks and bit positions */

        
#define NVM_FUSES_JTAGUSERID_gm 0xFF // JTAG User ID group mask
#define NVM_FUSES_JTAGUSERID_bp 0 // JTAG User ID group position

#define NVM_FUSES_JTAGUSERID0_bm (1<<0) // JTAG User ID bit 0 mask
#define NVM_FUSES_JTAGUSERID0_bp 0 // JTAG User ID bit 0 position
#define NVM_FUSES_JTAGUSERID1_bm (1<<1) // JTAG User ID bit 1 mask
#define NVM_FUSES_JTAGUSERID1_bp 1 // JTAG User ID bit 1 position
#define NVM_FUSES_JTAGUSERID2_bm (1<<2) // JTAG User ID bit 2 mask
#define NVM_FUSES_JTAGUSERID2_bp 2 // JTAG User ID bit 2 position
#define NVM_FUSES_JTAGUSERID3_bm (1<<3) // JTAG User ID bit 3 mask
#define NVM_FUSES_JTAGUSERID3_bp 3 // JTAG User ID bit 3 position
#define NVM_FUSES_JTAGUSERID4_bm (1<<4) // JTAG User ID bit 4 mask
#define NVM_FUSES_JTAGUSERID4_bp 4 // JTAG User ID bit 4 position
#define NVM_FUSES_JTAGUSERID5_bm (1<<5) // JTAG User ID bit 5 mask
#define NVM_FUSES_JTAGUSERID5_bp 5 // JTAG User ID bit 5 position
#define NVM_FUSES_JTAGUSERID6_bm (1<<6) // JTAG User ID bit 6 mask
#define NVM_FUSES_JTAGUSERID6_bp 6 // JTAG User ID bit 6 position
#define NVM_FUSES_JTAGUSERID7_bm (1<<7) // JTAG User ID bit 7 mask
#define NVM_FUSES_JTAGUSERID7_bp 7 // JTAG User ID bit 7 position

/* NVM_FUSES.FUSEBYTE1 bit masks and bit positions */

        
#define NVM_FUSES_WDWP_gm 0xF0 // Watchdog Window Timeout Period group mask
#define NVM_FUSES_WDWP_bp 4 // Watchdog Window Timeout Period group position

#define NVM_FUSES_WDWP0_bm (1<<4) // Watchdog Window Timeout Period bit 0 mask
#define NVM_FUSES_WDWP0_bp 4 // Watchdog Window Timeout Period bit 0 position
#define NVM_FUSES_WDWP1_bm (1<<5) // Watchdog Window Timeout Period bit 1 mask
#define NVM_FUSES_WDWP1_bp 5 // Watchdog Window Timeout Period bit 1 position
#define NVM_FUSES_WDWP2_bm (1<<6) // Watchdog Window Timeout Period bit 2 mask
#define NVM_FUSES_WDWP2_bp 6 // Watchdog Window Timeout Period bit 2 position
#define NVM_FUSES_WDWP3_bm (1<<7) // Watchdog Window Timeout Period bit 3 mask
#define NVM_FUSES_WDWP3_bp 7 // Watchdog Window Timeout Period bit 3 position
#define NVM_FUSES_WDP_gm 0x0F // Watchdog Timeout Period group mask
#define NVM_FUSES_WDP_bp 0 // Watchdog Timeout Period group position

#define NVM_FUSES_WDP0_bm (1<<0) // Watchdog Timeout Period bit 0 mask
#define NVM_FUSES_WDP0_bp 0 // Watchdog Timeout Period bit 0 position
#define NVM_FUSES_WDP1_bm (1<<1) // Watchdog Timeout Period bit 1 mask
#define NVM_FUSES_WDP1_bp 1 // Watchdog Timeout Period bit 1 position
#define NVM_FUSES_WDP2_bm (1<<2) // Watchdog Timeout Period bit 2 mask
#define NVM_FUSES_WDP2_bp 2 // Watchdog Timeout Period bit 2 position
#define NVM_FUSES_WDP3_bm (1<<3) // Watchdog Timeout Period bit 3 mask
#define NVM_FUSES_WDP3_bp 3 // Watchdog Timeout Period bit 3 position

/* NVM_FUSES.FUSEBYTE2 bit masks and bit positions */

        
#define NVM_FUSES_DVSDON_bm 0x80 // Spike Detector Enable bit mask
#define NVM_FUSES_DVSDON_bp 7 // Spike Detector Enable bit position
#define NVM_FUSES_BOOTRST_bm 0x40 // Boot Loader Section Reset Vector bit mask
#define NVM_FUSES_BOOTRST_bp 6 // Boot Loader Section Reset Vector bit position
#define NVM_FUSES_BODACT_gm 0x0C // BOD Operation in Active Mode group mask
#define NVM_FUSES_BODACT_bp 2 // BOD Operation in Active Mode group position

#define NVM_FUSES_BODACT0_bm (1<<2) // BOD Operation in Active Mode bit 0 mask
#define NVM_FUSES_BODACT0_bp 2 // BOD Operation in Active Mode bit 0 position
#define NVM_FUSES_BODACT1_bm (1<<3) // BOD Operation in Active Mode bit 1 mask
#define NVM_FUSES_BODACT1_bp 3 // BOD Operation in Active Mode bit 1 position
#define NVM_FUSES_BODPD_gm 0x03 // BOD Operation in Power-Down Mode group mask
#define NVM_FUSES_BODPD_bp 0 // BOD Operation in Power-Down Mode group position

#define NVM_FUSES_BODPD0_bm (1<<0) // BOD Operation in Power-Down Mode bit 0 mask
#define NVM_FUSES_BODPD0_bp 0 // BOD Operation in Power-Down Mode bit 0 position
#define NVM_FUSES_BODPD1_bm (1<<1) // BOD Operation in Power-Down Mode bit 1 mask
#define NVM_FUSES_BODPD1_bp 1 // BOD Operation in Power-Down Mode bit 1 position

/* NVM_FUSES.FUSEBYTE4 bit masks and bit positions */

        
#define NVM_FUSES_SUT_gm 0x0C // Start-up Time group mask
#define NVM_FUSES_SUT_bp 2 // Start-up Time group position

#define NVM_FUSES_SUT0_bm (1<<2) // Start-up Time bit 0 mask
#define NVM_FUSES_SUT0_bp 2 // Start-up Time bit 0 position
#define NVM_FUSES_SUT1_bm (1<<3) // Start-up Time bit 1 mask
#define NVM_FUSES_SUT1_bp 3 // Start-up Time bit 1 position
#define NVM_FUSES_WDLOCK_bm 0x02 // Watchdog Timer Lock bit mask
#define NVM_FUSES_WDLOCK_bp 1 // Watchdog Timer Lock bit position
#define NVM_FUSES_JTAGEN_bm 0x01 // JTAG Interface Enable bit mask
#define NVM_FUSES_JTAGEN_bp 0 // JTAG Interface Enable bit position

/* NVM_FUSES.FUSEBYTE5 bit masks and bit positions */

        
#define NVM_FUSES_EESAVE_bm 0x08 // Preserve EEPROM Through Chip Erase bit mask
#define NVM_FUSES_EESAVE_bp 3 // Preserve EEPROM Through Chip Erase bit position
#define NVM_FUSES_BODLVL_gm 0x07 // Brown Out Detection Voltage Level group mask
#define NVM_FUSES_BODLVL_bp 0 // Brown Out Detection Voltage Level group position

#define NVM_FUSES_BODLVL0_bm (1<<0) // Brown Out Detection Voltage Level bit 0 mask
#define NVM_FUSES_BODLVL0_bp 0 // Brown Out Detection Voltage Level bit 0 position
#define NVM_FUSES_BODLVL1_bm (1<<1) // Brown Out Detection Voltage Level bit 1 mask
#define NVM_FUSES_BODLVL1_bp 1 // Brown Out Detection Voltage Level bit 1 position
#define NVM_FUSES_BODLVL2_bm (1<<2) // Brown Out Detection Voltage Level bit 2 mask
#define NVM_FUSES_BODLVL2_bp 2 // Brown Out Detection Voltage Level bit 2 position

#if !defined (__ASSEMBLER__)
/*  */
typedef enum NVM_CMD_enum
{
  NVM_CMD_NO_OPERATION_gc = (0x00<<0),   /* Noop/Ordinary LPM */
  NVM_CMD_READ_CALIB_ROW_gc = (0x02<<0),   /* Read calibration row */
  NVM_CMD_READ_USER_SIG_ROW_gc = (0x03<<0),   /* Read user signature row */
  NVM_CMD_READ_EEPROM_gc = (0x06<<0),   /* Read EEPROM */
  NVM_CMD_READ_FUSES_gc = (0x07<<0),   /* Read fuse byte */
  NVM_CMD_WRITE_LOCK_BITS_gc = (0x08<<0),   /* Write lock bits */
  NVM_CMD_ERASE_USER_SIG_ROW_gc = (0x18<<0),   /* Erase user signature row */
  NVM_CMD_WRITE_USER_SIG_ROW_gc = (0x1A<<0),   /* Write user signature row */
  NVM_CMD_ERASE_APP_gc = (0x20<<0),   /* Erase Application Section */
  NVM_CMD_ERASE_APP_PAGE_gc = (0x22<<0),   /* Erase Application Section page */
  NVM_CMD_LOAD_FLASH_BUFFER_gc = (0x23<<0),   /* Load Flash page buffer */
  NVM_CMD_WRITE_APP_PAGE_gc = (0x24<<0),   /* Write Application Section page */
  NVM_CMD_ERASE_WRITE_APP_PAGE_gc = (0x25<<0),   /* Erase-and-write Application Section page */
  NVM_CMD_ERASE_FLASH_BUFFER_gc = (0x26<<0),   /* Erase/flush Flash page buffer */
  NVM_CMD_ERASE_BOOT_PAGE_gc = (0x2A<<0),   /* Erase Boot Section page */
  NVM_CMD_WRITE_BOOT_PAGE_gc = (0x2C<<0),   /* Write Boot Section page */
  NVM_CMD_ERASE_WRITE_BOOT_PAGE_gc = (0x2D<<0),   /* Erase-and-write Boot Section page */
  NVM_CMD_ERASE_EEPROM_gc = (0x30<<0),   /* Erase EEPROM */
  NVM_CMD_ERASE_EEPROM_PAGE_gc = (0x32<<0),   /* Erase EEPROM page */
  NVM_CMD_LOAD_EEPROM_BUFFER_gc = (0x33<<0),   /* Load EEPROM page buffer */
  NVM_CMD_WRITE_EEPROM_PAGE_gc = (0x34<<0),   /* Write EEPROM page */
  NVM_CMD_ERASE_WRITE_EEPROM_PAGE_gc = (0x35<<0),   /* Erase-and-write EEPROM page */
  NVM_CMD_ERASE_EEPROM_BUFFER_gc = (0x36<<0),   /* Erase/flush EEPROM page buffer */
  NVM_CMD_APP_CRC_gc = (0x38<<0),   /* Generate Application section CRC */
  NVM_CMD_BOOT_CRC_gc = (0x39<<0),   /* Generate Boot Section CRC */
} NVM_CMD_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/*  */
typedef enum NVM_SPMLVL_enum
{
  NVM_SPMLVL_OFF_gc = (0x00<<2),   /* Interrupt disabled */
  NVM_SPMLVL_LO_gc = (0x01<<2),   /* Low level */
  NVM_SPMLVL_MED_gc = (0x02<<2),   /* Medium level */
  NVM_SPMLVL_HI_gc = (0x03<<2),   /* High level */
} NVM_SPMLVL_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/*  */
typedef enum NVM_EELVL_enum
{
  NVM_EELVL_OFF_gc = (0x00<<0),   /* Interrupt disabled */
  NVM_EELVL_LO_gc = (0x01<<0),   /* Low level */
  NVM_EELVL_MED_gc = (0x02<<0),   /* Medium level */
  NVM_EELVL_HI_gc = (0x03<<0),   /* High level */
} NVM_EELVL_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/*  */
typedef enum NVM_BLBB_enum
{
  NVM_BLBB_NOLOCK_gc = (0x03<<6),   /* No locks */
  NVM_BLBB_WLOCK_gc = (0x02<<6),   /* Write not allowed */
  NVM_BLBB_RLOCK_gc = (0x01<<6),   /* Read not allowed */
  NVM_BLBB_RWLOCK_gc = (0x00<<6),   /* Read and write not allowed */
} NVM_BLBB_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/*  */
typedef enum NVM_BLBA_enum
{
  NVM_BLBA_NOLOCK_gc = (0x03<<4),   /* No locks */
  NVM_BLBA_WLOCK_gc = (0x02<<4),   /* Write not allowed */
  NVM_BLBA_RLOCK_gc = (0x01<<4),   /* Read not allowed */
  NVM_BLBA_RWLOCK_gc = (0x00<<4),   /* Read and write not allowed */
} NVM_BLBA_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/*  */
typedef enum NVM_BLBAT_enum
{
  NVM_BLBAT_NOLOCK_gc = (0x03<<2),   /* No locks */
  NVM_BLBAT_WLOCK_gc = (0x02<<2),   /* Write not allowed */
  NVM_BLBAT_RLOCK_gc = (0x01<<2),   /* Read not allowed */
  NVM_BLBAT_RWLOCK_gc = (0x00<<2),   /* Read and write not allowed */
} NVM_BLBAT_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/*  */
typedef enum NVM_LB_enum
{
  NVM_LB_NOLOCK_gc = (0x03<<0),   /* No locks */
  NVM_LB_WLOCK_gc = (0x02<<0),   /* Write not allowed */
  NVM_LB_RWLOCK_gc = (0x00<<0),   /* Read and write not allowed */
} NVM_LB_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/* Boot Loader Section Reset Vector */
typedef enum BOOTRST_enum
{
  BOOTRST_BOOTLDR_gc = (0x00<<6),   /* Boot Loader Reset */
  BOOTRST_APPLICATION_gc = (0x01<<6),   /* Application Reset */
} BOOTRST_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/* BOD operation */
typedef enum BOD_enum
{
  BOD_INSAMPLEDMODE_gc = (0x01<<2),   /* BOD enabled in sampled mode */
  BOD_CONTINOUSLY_gc = (0x02<<2),   /* BOD enabled continuously */
  BOD_DISABLED_gc = (0x03<<2),   /* BOD Disabled */
} BOD_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/* Watchdog (Window) Timeout Period */
typedef enum WD_enum
{
  WD_8CLK_gc = (0x00<<4),   /* 8 cycles (8ms @ 3.3V) */
  WD_16CLK_gc = (0x01<<4),   /* 16 cycles (16ms @ 3.3V) */
  WD_32CLK_gc = (0x02<<4),   /* 32 cycles (32ms @ 3.3V) */
  WD_64CLK_gc = (0x03<<4),   /* 64 cycles (64ms @ 3.3V) */
  WD_128CLK_gc = (0x04<<4),   /* 128 cycles (0.125s @ 3.3V) */
  WD_256CLK_gc = (0x05<<4),   /* 256 cycles (0.25s @ 3.3V) */
  WD_512CLK_gc = (0x06<<4),   /* 512 cycles (0.5s @ 3.3V) */
  WD_1KCLK_gc = (0x07<<4),   /* 1K cycles (1s @ 3.3V) */
  WD_2KCLK_gc = (0x08<<4),   /* 2K cycles (2s @ 3.3V) */
  WD_4KCLK_gc = (0x09<<4),   /* 4K cycles (4s @ 3.3V) */
  WD_8KCLK_gc = (0x0A<<4),   /* 8K cycles (8s @ 3.3V) */
} WD_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/* Start-up Time */
typedef enum SUT_enum
{
  SUT_0MS_gc = (0x03<<2),   /* 0 ms */
  SUT_4MS_gc = (0x01<<2),   /* 4 ms */
  SUT_64MS_gc = (0x00<<2),   /* 64 ms */
} SUT_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/* Brown Out Detection Voltage Level */
typedef enum BODLVL_enum
{
  BODLVL_1V6_gc = (0x07<<0),   /* 1.6 V */
  BODLVL_1V8_gc = (0x06<<0),   /* 1.8 V */
  BODLVL_2V0_gc = (0x05<<0),   /* 2.0 V */
  BODLVL_2V2_gc = (0x04<<0),   /* 2.2 V */
  BODLVL_2V4_gc = (0x03<<0),   /* 2.4 V */
  BODLVL_2V7_gc = (0x02<<0),   /* 2.7 V */
  BODLVL_2V9_gc = (0x01<<0),   /* 2.9 V */
  BODLVL_3V2_gc = (0x00<<0),   /* 3.2 V */
} BODLVL_t;
#endif /* !defined (__ASSEMBLER__) */


/*
--------------------------------------------------------------------------
 AC - Analog Comparator
--------------------------------------------------------------------------
*/

/* AC.AC0CTRL bit masks and bit positions */

        
#define AC_INTMODE_gm 0xC0 // Interrupt Mode group mask
#define AC_INTMODE_bp 6 // Interrupt Mode group position

#define AC_INTMODE0_bm (1<<6) // Interrupt Mode bit 0 mask
#define AC_INTMODE0_bp 6 // Interrupt Mode bit 0 position
#define AC_INTMODE1_bm (1<<7) // Interrupt Mode bit 1 mask
#define AC_INTMODE1_bp 7 // Interrupt Mode bit 1 position
#define AC_INTLVL_gm 0x30 // Interrupt Level group mask
#define AC_INTLVL_bp 4 // Interrupt Level group position

#define AC_INTLVL0_bm (1<<4) // Interrupt Level bit 0 mask
#define AC_INTLVL0_bp 4 // Interrupt Level bit 0 position
#define AC_INTLVL1_bm (1<<5) // Interrupt Level bit 1 mask
#define AC_INTLVL1_bp 5 // Interrupt Level bit 1 position
#define AC_HSMODE_bm 0x08 // High-speed Mode bit mask
#define AC_HSMODE_bp 3 // High-speed Mode bit position
#define AC_HYSMODE_gm 0x06 // Hysteresis Mode group mask
#define AC_HYSMODE_bp 1 // Hysteresis Mode group position

#define AC_HYSMODE0_bm (1<<1) // Hysteresis Mode bit 0 mask
#define AC_HYSMODE0_bp 1 // Hysteresis Mode bit 0 position
#define AC_HYSMODE1_bm (1<<2) // Hysteresis Mode bit 1 mask
#define AC_HYSMODE1_bp 2 // Hysteresis Mode bit 1 position
#define AC_ENABLE_bm 0x01 // Enable bit mask
#define AC_ENABLE_bp 0 // Enable bit position

/* AC.AC1CTRL bit masks and bit positions */

        
/* Masks for INTMODE aready defined */
            
/* Masks for INTLVL aready defined */
            
/* Masks for HSMODE aready defined */
            
/* Masks for HYSMODE aready defined */
            
/* Masks for ENABLE aready defined */
            

/* AC.AC0MUXCTRL bit masks and bit positions */

        
#define AC_MUXPOS_gm 0x38 // MUX Positive Input group mask
#define AC_MUXPOS_bp 3 // MUX Positive Input group position

#define AC_MUXPOS0_bm (1<<3) // MUX Positive Input bit 0 mask
#define AC_MUXPOS0_bp 3 // MUX Positive Input bit 0 position
#define AC_MUXPOS1_bm (1<<4) // MUX Positive Input bit 1 mask
#define AC_MUXPOS1_bp 4 // MUX Positive Input bit 1 position
#define AC_MUXPOS2_bm (1<<5) // MUX Positive Input bit 2 mask
#define AC_MUXPOS2_bp 5 // MUX Positive Input bit 2 position
#define AC_MUXNEG_gm 0x07 // MUX Negative Input group mask
#define AC_MUXNEG_bp 0 // MUX Negative Input group position

#define AC_MUXNEG0_bm (1<<0) // MUX Negative Input bit 0 mask
#define AC_MUXNEG0_bp 0 // MUX Negative Input bit 0 position
#define AC_MUXNEG1_bm (1<<1) // MUX Negative Input bit 1 mask
#define AC_MUXNEG1_bp 1 // MUX Negative Input bit 1 position
#define AC_MUXNEG2_bm (1<<2) // MUX Negative Input bit 2 mask
#define AC_MUXNEG2_bp 2 // MUX Negative Input bit 2 position

/* AC.AC1MUXCTRL bit masks and bit positions */

        
/* Masks for MUXPOS aready defined */
            
/* Masks for MUXNEG aready defined */
            

/* AC.CTRLA bit masks and bit positions */

        
#define AC_AC0OUT_bm 0x01 // Comparator 0 Output Enable bit mask
#define AC_AC0OUT_bp 0 // Comparator 0 Output Enable bit position

/* AC.CTRLB bit masks and bit positions */

        
#define AC_SCALEFAC_gm 0x3F // VCC Voltage Scaler Factor group mask
#define AC_SCALEFAC_bp 0 // VCC Voltage Scaler Factor group position

#define AC_SCALEFAC0_bm (1<<0) // VCC Voltage Scaler Factor bit 0 mask
#define AC_SCALEFAC0_bp 0 // VCC Voltage Scaler Factor bit 0 position
#define AC_SCALEFAC1_bm (1<<1) // VCC Voltage Scaler Factor bit 1 mask
#define AC_SCALEFAC1_bp 1 // VCC Voltage Scaler Factor bit 1 position
#define AC_SCALEFAC2_bm (1<<2) // VCC Voltage Scaler Factor bit 2 mask
#define AC_SCALEFAC2_bp 2 // VCC Voltage Scaler Factor bit 2 position
#define AC_SCALEFAC3_bm (1<<3) // VCC Voltage Scaler Factor bit 3 mask
#define AC_SCALEFAC3_bp 3 // VCC Voltage Scaler Factor bit 3 position
#define AC_SCALEFAC4_bm (1<<4) // VCC Voltage Scaler Factor bit 4 mask
#define AC_SCALEFAC4_bp 4 // VCC Voltage Scaler Factor bit 4 position
#define AC_SCALEFAC5_bm (1<<5) // VCC Voltage Scaler Factor bit 5 mask
#define AC_SCALEFAC5_bp 5 // VCC Voltage Scaler Factor bit 5 position

/* AC.WINCTRL bit masks and bit positions */

        
#define AC_WEN_bm 0x10 // Window Mode Enable bit mask
#define AC_WEN_bp 4 // Window Mode Enable bit position
#define AC_WINTMODE_gm 0x0C // Window Interrupt Mode group mask
#define AC_WINTMODE_bp 2 // Window Interrupt Mode group position

#define AC_WINTMODE0_bm (1<<2) // Window Interrupt Mode bit 0 mask
#define AC_WINTMODE0_bp 2 // Window Interrupt Mode bit 0 position
#define AC_WINTMODE1_bm (1<<3) // Window Interrupt Mode bit 1 mask
#define AC_WINTMODE1_bp 3 // Window Interrupt Mode bit 1 position
#define AC_WINTLVL_gm 0x03 // Window Interrupt Level group mask
#define AC_WINTLVL_bp 0 // Window Interrupt Level group position

#define AC_WINTLVL0_bm (1<<0) // Window Interrupt Level bit 0 mask
#define AC_WINTLVL0_bp 0 // Window Interrupt Level bit 0 position
#define AC_WINTLVL1_bm (1<<1) // Window Interrupt Level bit 1 mask
#define AC_WINTLVL1_bp 1 // Window Interrupt Level bit 1 position

/* AC.STATUS bit masks and bit positions */

        
#define AC_WSTATE_gm 0xC0 // Window Mode State group mask
#define AC_WSTATE_bp 6 // Window Mode State group position

#define AC_WSTATE0_bm (1<<6) // Window Mode State bit 0 mask
#define AC_WSTATE0_bp 6 // Window Mode State bit 0 position
#define AC_WSTATE1_bm (1<<7) // Window Mode State bit 1 mask
#define AC_WSTATE1_bp 7 // Window Mode State bit 1 position
#define AC_AC1STATE_bm 0x20 // Comparator 1 State bit mask
#define AC_AC1STATE_bp 5 // Comparator 1 State bit position
#define AC_AC0STATE_bm 0x10 // Comparator 0 State bit mask
#define AC_AC0STATE_bp 4 // Comparator 0 State bit position
#define AC_WIF_bm 0x04 // Window Mode Interrupt Flag bit mask
#define AC_WIF_bp 2 // Window Mode Interrupt Flag bit position
#define AC_AC1IF_bm 0x02 // Comparator 1 Interrupt Flag bit mask
#define AC_AC1IF_bp 1 // Comparator 1 Interrupt Flag bit position
#define AC_AC0IF_bm 0x01 // Comparator 0 Interrupt Flag bit mask
#define AC_AC0IF_bp 0 // Comparator 0 Interrupt Flag bit position

#if !defined (__ASSEMBLER__)
/*  */
typedef enum AC_INTMODE_enum
{
  AC_INTMODE_BOTHEDGES_gc = (0x00<<6),   /* Interrupt on both edges */
  AC_INTMODE_FALLING_gc = (0x02<<6),   /* Interrupt on falling edge */
  AC_INTMODE_RISING_gc = (0x03<<6),   /* Interrupt on rising edge */
} AC_INTMODE_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/*  */
typedef enum AC_INTLVL_enum
{
  AC_INTLVL_OFF_gc = (0x00<<4),   /* Interrupt disabled */
  AC_INTLVL_LO_gc = (0x01<<4),   /* Low level */
  AC_INTLVL_MED_gc = (0x02<<4),   /* Medium level */
  AC_INTLVL_HI_gc = (0x03<<4),   /* High level */
} AC_INTLVL_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/*  */
typedef enum AC_HYSMODE_enum
{
  AC_HYSMODE_NO_gc = (0x00<<1),   /* No hysteresis */
  AC_HYSMODE_SMALL_gc = (0x01<<1),   /* Small hysteresis */
  AC_HYSMODE_LARGE_gc = (0x02<<1),   /* Large hysteresis */
} AC_HYSMODE_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/*  */
typedef enum AC_MUXPOS_enum
{
  AC_MUXPOS_PIN0_gc = (0x00<<3),   /* Pin 0 */
  AC_MUXPOS_PIN1_gc = (0x01<<3),   /* Pin 1 */
  AC_MUXPOS_PIN2_gc = (0x02<<3),   /* Pin 2 */
  AC_MUXPOS_PIN3_gc = (0x02<<3),   /* Pin 3 */
  AC_MUXPOS_PIN4_gc = (0x03<<3),   /* Pin 4 */
  AC_MUXPOS_PIN5_gc = (0x04<<3),   /* Pin 5 */
  AC_MUXPOS_PIN6_gc = (0x05<<3),   /* Pin 6 */
  AC_MUXPOS_DAC_gc = (0x07<<3),   /* DAC output */
} AC_MUXPOS_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/*  */
typedef enum AC_MUXNEG_enum
{
  AC_MUXNEG_PIN0_gc = (0x00<<0),   /* Pin 0 */
  AC_MUXNEG_PIN1_gc = (0x01<<0),   /* Pin 1 */
  AC_MUXNEG_PIN3_gc = (0x02<<0),   /* Pin 3 */
  AC_MUXNEG_PIN5_gc = (0x03<<0),   /* Pin 5 */
  AC_MUXNEG_PIN7_gc = (0x04<<0),   /* Pin 7 */
  AC_MUXNEG_DAC_gc = (0x05<<0),   /* DAC output */
  AC_MUXNEG_BANDGAP_gc = (0x06<<0),   /* Bandgap Reference */
  AC_MUXNEG_SCALER_gc = (0x07<<0),   /* Internal voltage scaler */
} AC_MUXNEG_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/*  */
typedef enum AC_WINTMODE_enum
{
  AC_WINTMODE_ABOVE_gc = (0x00<<2),   /* Interrupt on above window */
  AC_WINTMODE_INSIDE_gc = (0x01<<2),   /* Interrupt on inside window */
  AC_WINTMODE_BELOW_gc = (0x02<<2),   /* Interrupt on below window */
  AC_WINTMODE_OUTSIDE_gc = (0x03<<2),   /* Interrupt on outside window */
} AC_WINTMODE_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/*  */
typedef enum AC_WINTLVL_enum
{
  AC_WINTLVL_OFF_gc = (0x00<<0),   /* Interrupt disabled */
  AC_WINTLVL_LO_gc = (0x01<<0),   /* Low priority */
  AC_WINTLVL_MED_gc = (0x02<<0),   /* Medium priority */
  AC_WINTLVL_HI_gc = (0x03<<0),   /* High priority */
} AC_WINTLVL_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/*  */
typedef enum AC_WSTATE_enum
{
  AC_WSTATE_ABOVE_gc = (0x00<<6),   /* Signal above window */
  AC_WSTATE_INSIDE_gc = (0x01<<6),   /* Signal inside window */
  AC_WSTATE_BELOW_gc = (0x02<<6),   /* Signal below window */
} AC_WSTATE_t;
#endif /* !defined (__ASSEMBLER__) */


/*
--------------------------------------------------------------------------
 ADC - Analog/Digital Converter
--------------------------------------------------------------------------
*/

/* ADC_CH.CTRL bit masks and bit positions */

        
#define ADC_CH_START_bm 0x80 // Channel Start Conversion bit mask
#define ADC_CH_START_bp 7 // Channel Start Conversion bit position
#define ADC_CH_GAINFAC_gm 0x1C // Gain Factor group mask
#define ADC_CH_GAINFAC_bp 2 // Gain Factor group position

#define ADC_CH_GAINFAC0_bm (1<<2) // Gain Factor bit 0 mask
#define ADC_CH_GAINFAC0_bp 2 // Gain Factor bit 0 position
#define ADC_CH_GAINFAC1_bm (1<<3) // Gain Factor bit 1 mask
#define ADC_CH_GAINFAC1_bp 3 // Gain Factor bit 1 position
#define ADC_CH_GAINFAC2_bm (1<<4) // Gain Factor bit 2 mask
#define ADC_CH_GAINFAC2_bp 4 // Gain Factor bit 2 position
#define ADC_CH_INPUTMODE_gm 0x03 // Negative Input Select group mask
#define ADC_CH_INPUTMODE_bp 0 // Negative Input Select group position

#define ADC_CH_INPUTMODE0_bm (1<<0) // Negative Input Select bit 0 mask
#define ADC_CH_INPUTMODE0_bp 0 // Negative Input Select bit 0 position
#define ADC_CH_INPUTMODE1_bm (1<<1) // Negative Input Select bit 1 mask
#define ADC_CH_INPUTMODE1_bp 1 // Negative Input Select bit 1 position

/* ADC_CH.MUXCTRL bit masks and bit positions */

        
#define ADC_CH_MUXPOS_gm 0xF0 // Positive Input Select group mask
#define ADC_CH_MUXPOS_bp 4 // Positive Input Select group position

#define ADC_CH_MUXPOS0_bm (1<<4) // Positive Input Select bit 0 mask
#define ADC_CH_MUXPOS0_bp 4 // Positive Input Select bit 0 position
#define ADC_CH_MUXPOS1_bm (1<<5) // Positive Input Select bit 1 mask
#define ADC_CH_MUXPOS1_bp 5 // Positive Input Select bit 1 position
#define ADC_CH_MUXPOS2_bm (1<<6) // Positive Input Select bit 2 mask
#define ADC_CH_MUXPOS2_bp 6 // Positive Input Select bit 2 position
#define ADC_CH_MUXPOS3_bm (1<<7) // Positive Input Select bit 3 mask
#define ADC_CH_MUXPOS3_bp 7 // Positive Input Select bit 3 position
#define ADC_CH_MUXINT_gm 0xF0 // Internal Input Select group mask
#define ADC_CH_MUXINT_bp 4 // Internal Input Select group position

#define ADC_CH_MUXINT0_bm (1<<4) // Internal Input Select bit 0 mask
#define ADC_CH_MUXINT0_bp 4 // Internal Input Select bit 0 position
#define ADC_CH_MUXINT1_bm (1<<5) // Internal Input Select bit 1 mask
#define ADC_CH_MUXINT1_bp 5 // Internal Input Select bit 1 position
#define ADC_CH_MUXINT2_bm (1<<6) // Internal Input Select bit 2 mask
#define ADC_CH_MUXINT2_bp 6 // Internal Input Select bit 2 position
#define ADC_CH_MUXINT3_bm (1<<7) // Internal Input Select bit 3 mask
#define ADC_CH_MUXINT3_bp 7 // Internal Input Select bit 3 position
#define ADC_CH_MUXNEG_gm 0x03 // Negative Input Select group mask
#define ADC_CH_MUXNEG_bp 0 // Negative Input Select group position

#define ADC_CH_MUXNEG0_bm (1<<0) // Negative Input Select bit 0 mask
#define ADC_CH_MUXNEG0_bp 0 // Negative Input Select bit 0 position
#define ADC_CH_MUXNEG1_bm (1<<1) // Negative Input Select bit 1 mask
#define ADC_CH_MUXNEG1_bp 1 // Negative Input Select bit 1 position

/* ADC_CH.INTCTRL bit masks and bit positions */

        
#define ADC_CH_INTMODE_gm 0x0C // Interrupt Mode group mask
#define ADC_CH_INTMODE_bp 2 // Interrupt Mode group position

#define ADC_CH_INTMODE0_bm (1<<2) // Interrupt Mode bit 0 mask
#define ADC_CH_INTMODE0_bp 2 // Interrupt Mode bit 0 position
#define ADC_CH_INTMODE1_bm (1<<3) // Interrupt Mode bit 1 mask
#define ADC_CH_INTMODE1_bp 3 // Interrupt Mode bit 1 position
#define ADC_CH_INTLVL_gm 0x03 // Interrupt Level group mask
#define ADC_CH_INTLVL_bp 0 // Interrupt Level group position

#define ADC_CH_INTLVL0_bm (1<<0) // Interrupt Level bit 0 mask
#define ADC_CH_INTLVL0_bp 0 // Interrupt Level bit 0 position
#define ADC_CH_INTLVL1_bm (1<<1) // Interrupt Level bit 1 mask
#define ADC_CH_INTLVL1_bp 1 // Interrupt Level bit 1 position

/* ADC_CH.INTFLAGS bit masks and bit positions */

        
#define ADC_CH_CHIF_bm 0x01 // Channel Interrupt Flag bit mask
#define ADC_CH_CHIF_bp 0 // Channel Interrupt Flag bit position

/* ADC.CTRLA bit masks and bit positions */

        
#define ADC_DMASEL_gm 0xE0 // DMA Selection group mask
#define ADC_DMASEL_bp 5 // DMA Selection group position

#define ADC_DMASEL0_bm (1<<5) // DMA Selection bit 0 mask
#define ADC_DMASEL0_bp 5 // DMA Selection bit 0 position
#define ADC_DMASEL1_bm (1<<6) // DMA Selection bit 1 mask
#define ADC_DMASEL1_bp 6 // DMA Selection bit 1 position
#define ADC_DMASEL2_bm (1<<7) // DMA Selection bit 2 mask
#define ADC_DMASEL2_bp 7 // DMA Selection bit 2 position
#define ADC_CH3START_bm 0x20 // Channel 3 Start Conversion bit mask
#define ADC_CH3START_bp 5 // Channel 3 Start Conversion bit position
#define ADC_CH2START_bm 0x10 // Channel 2 Start Conversion bit mask
#define ADC_CH2START_bp 4 // Channel 2 Start Conversion bit position
#define ADC_CH1START_bm 0x08 // Channel 1 Start Conversion bit mask
#define ADC_CH1START_bp 3 // Channel 1 Start Conversion bit position
#define ADC_CH0START_bm 0x04 // Channel 0 Start Conversion bit mask
#define ADC_CH0START_bp 2 // Channel 0 Start Conversion bit position
#define ADC_FLUSH_bm 0x02 // Flush Pipeline bit mask
#define ADC_FLUSH_bp 1 // Flush Pipeline bit position
#define ADC_ENABLE_bm 0x01 // Enable ADC bit mask
#define ADC_ENABLE_bp 0 // Enable ADC bit position

/* ADC.CTRLB bit masks and bit positions */

        
#define ADC_CONMODE_bm 0x10 // Conversion Mode bit mask
#define ADC_CONMODE_bp 4 // Conversion Mode bit position
#define ADC_FREERUN_bm 0x08 // Free Running Mode Enable bit mask
#define ADC_FREERUN_bp 3 // Free Running Mode Enable bit position
#define ADC_RESOLUTION_gm 0x06 // Result Resolution group mask
#define ADC_RESOLUTION_bp 1 // Result Resolution group position

#define ADC_RESOLUTION0_bm (1<<1) // Result Resolution bit 0 mask
#define ADC_RESOLUTION0_bp 1 // Result Resolution bit 0 position
#define ADC_RESOLUTION1_bm (1<<2) // Result Resolution bit 1 mask
#define ADC_RESOLUTION1_bp 2 // Result Resolution bit 1 position

/* ADC.REFCTRL bit masks and bit positions */

        
#define ADC_REFSEL_gm 0x30 // Reference Selection group mask
#define ADC_REFSEL_bp 4 // Reference Selection group position

#define ADC_REFSEL0_bm (1<<4) // Reference Selection bit 0 mask
#define ADC_REFSEL0_bp 4 // Reference Selection bit 0 position
#define ADC_REFSEL1_bm (1<<5) // Reference Selection bit 1 mask
#define ADC_REFSEL1_bp 5 // Reference Selection bit 1 position
#define ADC_BANDGAP_bm 0x02 // Bandgap enable bit mask
#define ADC_BANDGAP_bp 1 // Bandgap enable bit position
#define ADC_TEMPREF_bm 0x01 // Temperature Reference Enable bit mask
#define ADC_TEMPREF_bp 0 // Temperature Reference Enable bit position

/* ADC.EVCTRL bit masks and bit positions */

        
#define ADC_SWEEP_gm 0xC0 // Channel Sweep Selection group mask
#define ADC_SWEEP_bp 6 // Channel Sweep Selection group position

#define ADC_SWEEP0_bm (1<<6) // Channel Sweep Selection bit 0 mask
#define ADC_SWEEP0_bp 6 // Channel Sweep Selection bit 0 position
#define ADC_SWEEP1_bm (1<<7) // Channel Sweep Selection bit 1 mask
#define ADC_SWEEP1_bp 7 // Channel Sweep Selection bit 1 position
#define ADC_EVSEL_gm 0x38 // Event Input Select group mask
#define ADC_EVSEL_bp 3 // Event Input Select group position

#define ADC_EVSEL0_bm (1<<3) // Event Input Select bit 0 mask
#define ADC_EVSEL0_bp 3 // Event Input Select bit 0 position
#define ADC_EVSEL1_bm (1<<4) // Event Input Select bit 1 mask
#define ADC_EVSEL1_bp 4 // Event Input Select bit 1 position
#define ADC_EVSEL2_bm (1<<5) // Event Input Select bit 2 mask
#define ADC_EVSEL2_bp 5 // Event Input Select bit 2 position
#define ADC_EVACT_gm 0x07 // Event Action Select group mask
#define ADC_EVACT_bp 0 // Event Action Select group position

#define ADC_EVACT0_bm (1<<0) // Event Action Select bit 0 mask
#define ADC_EVACT0_bp 0 // Event Action Select bit 0 position
#define ADC_EVACT1_bm (1<<1) // Event Action Select bit 1 mask
#define ADC_EVACT1_bp 1 // Event Action Select bit 1 position
#define ADC_EVACT2_bm (1<<2) // Event Action Select bit 2 mask
#define ADC_EVACT2_bp 2 // Event Action Select bit 2 position

/* ADC.PRESCALER bit masks and bit positions */

        
#define ADC_PRESCALER_gm 0x07 // Clock Prescaler Selection group mask
#define ADC_PRESCALER_bp 0 // Clock Prescaler Selection group position

#define ADC_PRESCALER0_bm (1<<0) // Clock Prescaler Selection bit 0 mask
#define ADC_PRESCALER0_bp 0 // Clock Prescaler Selection bit 0 position
#define ADC_PRESCALER1_bm (1<<1) // Clock Prescaler Selection bit 1 mask
#define ADC_PRESCALER1_bp 1 // Clock Prescaler Selection bit 1 position
#define ADC_PRESCALER2_bm (1<<2) // Clock Prescaler Selection bit 2 mask
#define ADC_PRESCALER2_bp 2 // Clock Prescaler Selection bit 2 position

/* ADC.CALCTRL bit masks and bit positions */

        
#define ADC_CAL_bm 0x01 // ADC Calibration Start bit mask
#define ADC_CAL_bp 0 // ADC Calibration Start bit position

/* ADC.INTFLAGS bit masks and bit positions */

        
#define ADC_CH3IF_bm 0x08 // Channel 3 Interrupt Flag bit mask
#define ADC_CH3IF_bp 3 // Channel 3 Interrupt Flag bit position
#define ADC_CH2IF_bm 0x04 // Channel 2 Interrupt Flag bit mask
#define ADC_CH2IF_bp 2 // Channel 2 Interrupt Flag bit position
#define ADC_CH1IF_bm 0x02 // Channel 1 Interrupt Flag bit mask
#define ADC_CH1IF_bp 1 // Channel 1 Interrupt Flag bit position
#define ADC_CH0IF_bm 0x01 // Channel 0 Interrupt Flag bit mask
#define ADC_CH0IF_bp 0 // Channel 0 Interrupt Flag bit position

#if !defined (__ASSEMBLER__)
/*  */
typedef enum ADC_CH_MUXPOS_enum
{
  ADC_CH_MUXPOS_PIN0_gc = (0x00<<4),   /* Input pin 0 */
  ADC_CH_MUXPOS_PIN1_gc = (0x01<<4),   /* Input pin 1 */
  ADC_CH_MUXPOS_PIN2_gc = (0x02<<4),   /* Input pin 2 */
  ADC_CH_MUXPOS_PIN3_gc = (0x03<<4),   /* Input pin 3 */
  ADC_CH_MUXPOS_PIN4_gc = (0x04<<4),   /* Input pin 4 */
  ADC_CH_MUXPOS_PIN5_gc = (0x05<<4),   /* Input pin 5 */
  ADC_CH_MUXPOS_PIN6_gc = (0x06<<4),   /* Input pin 6 */
  ADC_CH_MUXPOS_PIN7_gc = (0x07<<4),   /* Input pin 7 */
} ADC_CH_MUXPOS_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/*  */
typedef enum ADC_CH_MUXINT_enum
{
  ADC_CH_MUXINT_TEMP_gc = (0x00<<0),   /* Temperature Reference */
  ADC_CH_MUXINT_BANDGAP_gc = (0x01<<0),   /* Bandgap Reference */
  ADC_CH_MUXINT_SCALEDVCC_gc = (0x02<<0),   /* 1/10 scaled VCC */
  ADC_CH_MUXINT_DAC_gc = (0x03<<0),   /* DAC output */
} ADC_CH_MUXINT_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/*  */
typedef enum ADC_CH_MUXNEG_enum
{
  ADC_CH_MUXNEG_PIN0_gc = (0x00<<0),   /* Input pin 0 */
  ADC_CH_MUXNEG_PIN1_gc = (0x01<<0),   /* Input pin 1 */
  ADC_CH_MUXNEG_PIN2_gc = (0x02<<0),   /* Input pin 2 */
  ADC_CH_MUXNEG_PIN3_gc = (0x03<<0),   /* Input pin 3 */
  ADC_CH_MUXNEG_PIN4_gc = (0x04<<0),   /* Input pin 4 */
  ADC_CH_MUXNEG_PIN5_gc = (0x05<<0),   /* Input pin 5 */
  ADC_CH_MUXNEG_PIN6_gc = (0x06<<0),   /* Input pin 6 */
  ADC_CH_MUXNEG_PIN7_gc = (0x07<<0),   /* Input pin 7 */
} ADC_CH_MUXNEG_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/*  */
typedef enum ADC_CH_INPUTMODE_enum
{
  ADC_CH_INPUTMODE_INTERNAL_gc = (0x00<<0),   /* Internal inputs, no gain */
  ADC_CH_INPUTMODE_SINGLEENDED_gc = (0x01<<0),   /* Single-ended input, no gain */
  ADC_CH_INPUTMODE_DIFF_gc = (0x02<<0),   /* Differential input, no gain */
  ADC_CH_INPUTMODE_DIFFWGAIN_gc = (0x03<<0),   /* Differential input, with gain */
} ADC_CH_INPUTMODE_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/*  */
typedef enum ADC_CH_GAINFAC_enum
{
  ADC_CH_GAINFAC_1X_gc = (0x00<<0),   /* 1x gain */
  ADC_CH_GAINFAC_2X_gc = (0x01<<0),   /* 2x gain */
  ADC_CH_GAINFAC_4X_gc = (0x02<<0),   /* 4x gain */
  ADC_CH_GAINFAC_8X_gc = (0x03<<0),   /* 8x gain */
  ADC_CH_GAINFAC_16X_gc = (0x04<<0),   /* 16x gain */
  ADC_CH_GAINFAC_32X_gc = (0x05<<0),   /* 32x gain */
  ADC_CH_GAINFAC_64X_gc = (0x06<<0),   /* 64x gain */
} ADC_CH_GAINFAC_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/*  */
typedef enum ADC_RESOLUTION_enum
{
  ADC_RESOLUTION_12BIT_gc = (0x00<<1),   /* 12-bit right-adjusted result */
  ADC_RESOLUTION_8BIT_gc = (0x02<<1),   /* 8-bit right-adjusted result */
  ADC_RESOLUTION_LEFT12BIT_gc = (0x03<<1),   /* 12-bit left-adjusted result */
} ADC_RESOLUTION_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/*  */
typedef enum ADC_REFSEL_enum
{
  ADC_REFSEL_INT1V_gc = (0x00<<4),   /* Internal 1V */
  ADC_REFSEL_VCC_gc = (0x01<<4),   /* Internal VCC-0.6V */
  ADC_REFSEL_AREFA_gc = (0x02<<4),   /* External reference on PORT A */
  ADC_REFSEL_AREFB_gc = (0x03<<4),   /* External reference on PORT B */
} ADC_REFSEL_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/*  */
typedef enum ADC_SWEEP_enum
{
  ADC_SWEEP_0_gc = (0x00<<6),   /* ADC Channel 0 */
  ADC_SWEEP_01_gc = (0x01<<6),   /* ADC Channel 0,1 */
  ADC_SWEEP_012_gc = (0x02<<6),   /* ADC Channel 0,1,2 */
  ADC_SWEEP_0123_gc = (0x03<<6),   /* ADC Channel 0,1,2,3 */
} ADC_SWEEP_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/*  */
typedef enum ADC_EVSEL_enum
{
  ADC_EVSEL_0123_gc = (0x00<<3),   /* Event Channel 0,1,2,3 */
  ADC_EVSEL_1234_gc = (0x01<<3),   /* Event Channel 1,2,3,4 */
  ADC_EVSEL_2345_gc = (0x02<<3),   /* Event Channel 2,3,4,5 */
  ADC_EVSEL_3456_gc = (0x03<<3),   /* Event Channel 3,4,5,6 */
  ADC_EVSEL_4567_gc = (0x04<<3),   /* Event Channel 4,5,6,7 */
  ADC_EVSEL_567_gc = (0x05<<3),   /* Event Channel 5,6,7 */
  ADC_EVSEL_67_gc = (0x06<<3),   /* Event Channel 6,7 */
  ADC_EVSEL_7_gc = (0x07<<3),   /* Event Channel 7 */
} ADC_EVSEL_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/*  */
typedef enum ADC_EVACT_enum
{
  ADC_EVACT_NONE_gc = (0x00<<0),   /* No event action */
  ADC_EVACT_CH0_gc = (0x01<<0),   /* First event triggers channel 0 */
  ADC_EVACT_CH01_gc = (0x02<<0),   /* First two events trigger channel 0,1 */
  ADC_EVACT_CH012_gc = (0x03<<0),   /* First three events trigger channel 0,1,2 */
  ADC_EVACT_CH0123_gc = (0x04<<0),   /* Events trigger channel 0,1,2,3 */
  ADC_EVACT_SWEEP_gc = (0x05<<0),   /* First event triggers sweep */
  ADC_EVACT_SYNCHSWEEP_gc = (0x06<<0),   /* First event triggers synchronized sweep */
} ADC_EVACT_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/*  */
typedef enum ADC_CH_INTMODE_enum
{
  ADC_CH_INTMODE_COMPLETE_gc = (0x00<<2),   /* Interrupt on conversion complete */
  ADC_CH_INTMODE_BELOW_gc = (0x01<<2),   /* Interrupt on result below compare value */
  ADC_CH_INTMODE_ABOVE_gc = (0x03<<2),   /* Interrupt on result above compare value */
} ADC_CH_INTMODE_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/*  */
typedef enum ADC_CH_INTLVL_enum
{
  ADC_CH_INTLVL_OFF_gc = (0x00<<0),   /* Interrupt disabled */
  ADC_CH_INTLVL_LO_gc = (0x01<<0),   /* Low level */
  ADC_CH_INTLVL_MED_gc = (0x02<<0),   /* Medium level */
  ADC_CH_INTLVL_HI_gc = (0x03<<0),   /* High level */
} ADC_CH_INTLVL_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/*  */
typedef enum ADC_DMASEL_enum
{
  ADC_DMASEL_OFF_gc = (0x00<<5),   /* Combined DMA request OFF */
  ADC_DMASEL_CH01_gc = (0x01<<5),   /* ADC Channel 0 or 1 */
  ADC_DMASEL_CH012_gc = (0x02<<5),   /* ADC Channel 0 or 1 or 2 */
  ADC_DMASEL_CH0123_gc = (0x03<<5),   /* ADC Channel 0 or 1 or 2 or 3 */
} ADC_DMASEL_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/*  */
typedef enum ADC_PRESCALER_enum
{
  ADC_PRESCALER_DIV4_gc = (0x00<<0),   /* Divide clock by 4 */
  ADC_PRESCALER_DIV8_gc = (0x01<<0),   /* Divide clock by 8 */
  ADC_PRESCALER_DIV16_gc = (0x02<<0),   /* Divide clock by 16 */
  ADC_PRESCALER_DIV32_gc = (0x03<<0),   /* Divide clock by 32 */
  ADC_PRESCALER_DIV64_gc = (0x04<<0),   /* Divide clock by 64 */
  ADC_PRESCALER_DIV128_gc = (0x05<<0),   /* Divide clock by 128 */
  ADC_PRESCALER_DIV256_gc = (0x06<<0),   /* Divide clock by 256 */
  ADC_PRESCALER_DIV512_gc = (0x07<<0),   /* Divide clock by 512 */
} ADC_PRESCALER_t;
#endif /* !defined (__ASSEMBLER__) */


/*
--------------------------------------------------------------------------
 DAC - Digital/Analog Converter
--------------------------------------------------------------------------
*/

/* DAC.CTRLA bit masks and bit positions */

        
#define DAC_IDOEN_bm 0x10 // Internal Output Enable bit mask
#define DAC_IDOEN_bp 4 // Internal Output Enable bit position
#define DAC_CH1EN_bm 0x08 // Channel 1 Output Enable bit mask
#define DAC_CH1EN_bp 3 // Channel 1 Output Enable bit position
#define DAC_CH0EN_bm 0x04 // Channel 0 Output Enable bit mask
#define DAC_CH0EN_bp 2 // Channel 0 Output Enable bit position
#define DAC_LPMODE_bm 0x02 // Low Power Mode bit mask
#define DAC_LPMODE_bp 1 // Low Power Mode bit position
#define DAC_ENABLE_bm 0x01 // Enable bit mask
#define DAC_ENABLE_bp 0 // Enable bit position

/* DAC.CTRLB bit masks and bit positions */

        
#define DAC_CHSEL_gm 0x60 // Channel Select group mask
#define DAC_CHSEL_bp 5 // Channel Select group position

#define DAC_CHSEL0_bm (1<<5) // Channel Select bit 0 mask
#define DAC_CHSEL0_bp 5 // Channel Select bit 0 position
#define DAC_CHSEL1_bm (1<<6) // Channel Select bit 1 mask
#define DAC_CHSEL1_bp 6 // Channel Select bit 1 position
#define DAC_CH1TRIG_bm 0x02 // Channel 1 Event Trig Enable bit mask
#define DAC_CH1TRIG_bp 1 // Channel 1 Event Trig Enable bit position
#define DAC_CH0TRIG_bm 0x01 // Channel 0 Event Trig Enable bit mask
#define DAC_CH0TRIG_bp 0 // Channel 0 Event Trig Enable bit position

/* DAC.CTRLC bit masks and bit positions */

        
#define DAC_REFSEL_gm 0x18 // Reference Select group mask
#define DAC_REFSEL_bp 3 // Reference Select group position

#define DAC_REFSEL0_bm (1<<3) // Reference Select bit 0 mask
#define DAC_REFSEL0_bp 3 // Reference Select bit 0 position
#define DAC_REFSEL1_bm (1<<4) // Reference Select bit 1 mask
#define DAC_REFSEL1_bp 4 // Reference Select bit 1 position
#define DAC_LEFTADJ_bm 0x01 // Left-adjust Result bit mask
#define DAC_LEFTADJ_bp 0 // Left-adjust Result bit position

/* DAC.EVCTRL bit masks and bit positions */

        
#define DAC_EVSEL_gm 0x07 // Event Input Selection group mask
#define DAC_EVSEL_bp 0 // Event Input Selection group position

#define DAC_EVSEL0_bm (1<<0) // Event Input Selection bit 0 mask
#define DAC_EVSEL0_bp 0 // Event Input Selection bit 0 position
#define DAC_EVSEL1_bm (1<<1) // Event Input Selection bit 1 mask
#define DAC_EVSEL1_bp 1 // Event Input Selection bit 1 position
#define DAC_EVSEL2_bm (1<<2) // Event Input Selection bit 2 mask
#define DAC_EVSEL2_bp 2 // Event Input Selection bit 2 position

/* DAC.TIMCTRL bit masks and bit positions */

        
#define DAC_CONINTVAL_gm 0x70 // Conversion Intercal group mask
#define DAC_CONINTVAL_bp 4 // Conversion Intercal group position

#define DAC_CONINTVAL0_bm (1<<4) // Conversion Intercal bit 0 mask
#define DAC_CONINTVAL0_bp 4 // Conversion Intercal bit 0 position
#define DAC_CONINTVAL1_bm (1<<5) // Conversion Intercal bit 1 mask
#define DAC_CONINTVAL1_bp 5 // Conversion Intercal bit 1 position
#define DAC_CONINTVAL2_bm (1<<6) // Conversion Intercal bit 2 mask
#define DAC_CONINTVAL2_bp 6 // Conversion Intercal bit 2 position
#define DAC_REFRESH_gm 0x0F // Refresh Timing Control group mask
#define DAC_REFRESH_bp 0 // Refresh Timing Control group position

#define DAC_REFRESH0_bm (1<<0) // Refresh Timing Control bit 0 mask
#define DAC_REFRESH0_bp 0 // Refresh Timing Control bit 0 position
#define DAC_REFRESH1_bm (1<<1) // Refresh Timing Control bit 1 mask
#define DAC_REFRESH1_bp 1 // Refresh Timing Control bit 1 position
#define DAC_REFRESH2_bm (1<<2) // Refresh Timing Control bit 2 mask
#define DAC_REFRESH2_bp 2 // Refresh Timing Control bit 2 position
#define DAC_REFRESH3_bm (1<<3) // Refresh Timing Control bit 3 mask
#define DAC_REFRESH3_bp 3 // Refresh Timing Control bit 3 position

/* DAC.STATUS bit masks and bit positions */

        
#define DAC_CH1DRE_bm 0x02 // Channel 1 Data Register Empty bit mask
#define DAC_CH1DRE_bp 1 // Channel 1 Data Register Empty bit position
#define DAC_CH0DRE_bm 0x01 // Channel 0 Data Register Empty bit mask
#define DAC_CH0DRE_bp 0 // Channel 0 Data Register Empty bit position

#if !defined (__ASSEMBLER__)
/*  */
typedef enum DAC_CHSEL_enum
{
  DAC_CHSEL_SINGLE_gc = (0x00<<5),   /* Single channel operation (Channel A only) */
  DAC_CHSEL_DUAL_gc = (0x02<<5),   /* Dual channel operation (S/H on both channels) */
} DAC_CHSEL_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/*  */
typedef enum DAC_REFSEL_enum
{
  DAC_REFSEL_INT1V_gc = (0x00<<3),   /* Internal 1V  */
  DAC_REFSEL_AVCC_gc = (0x01<<3),   /* Analog supply voltage */
  DAC_REFSEL_AREFA_gc = (0x02<<3),   /* External reference on AREF on PORTA */
  DAC_REFSEL_AREFB_gc = (0x02<<3),   /* External reference on AREF on PORTB */
} DAC_REFSEL_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/*  */
typedef enum DAC_EVSEL_enum
{
  DAC_EVSEL_EV0_gc = (0x00<<0),   /* Event Channel 0 */
  DAC_EVSEL_EV1_gc = (0x01<<0),   /* Event Channel 1 */
  DAC_EVSEL_EV2_gc = (0x02<<0),   /* Event Channel 2 */
  DAC_EVSEL_EV3_gc = (0x03<<0),   /* Event Channele 3 */
  DAC_EVSEL_EV4_gc = (0x04<<0),   /* Event Channel 4 */
  DAC_EVSEL_EV5_gc = (0x05<<0),   /* Event Channel 5 */
  DAC_EVSEL_EV6_gc = (0x06<<0),   /* Event Channel 6 */
  DAC_EVSEL_EV7_gc = (0x07<<0),   /* Event Channel 7 */
} DAC_EVSEL_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/*  */
typedef enum DAC_CONINTVAL_enum
{
  DAC_CONINTVAL_1CLK_gc = (0x00<<4),   /* 1 CLK / 2 CLK in S/H mode */
  DAC_CONINTVAL_2CLK_gc = (0x01<<4),   /* 2 CLK / 3 CLK in S/H mode */
  DAC_CONINTVAL_4CLK_gc = (0x02<<4),   /* 4 CLK / 6 CLK in S/H mode */
  DAC_CONINTVAL_8CLK_gc = (0x03<<4),   /* 8 CLK / 12 CLK in S/H mode */
  DAC_CONINTVAL_16CLK_gc = (0x04<<4),   /* 16 CLK / 24 CLK in S/H mode */
  DAC_CONINTVAL_32CLK_gc = (0x05<<4),   /* 32 CLK / 48 CLK in S/H mode */
  DAC_CONINTVAL_64CLK_gc = (0x06<<4),   /* 64 CLK / 96 CLK in S/H mode */
  DAC_CONINTVAL_128CLK_gc = (0x07<<4),   /* 128 CLK / 192 CLK in S/H mode */
} DAC_CONINTVAL_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/*  */
typedef enum DAC_REFRESH_enum
{
  DAC_REFRESH_16CLK_gc = (0x00<<0),   /* 16 CLK */
  DAC_REFRESH_32CLK_gc = (0x01<<0),   /* 32 CLK */
  DAC_REFRESH_64CLK_gc = (0x02<<0),   /* 64 CLK */
  DAC_REFRESH_128CLK_gc = (0x03<<0),   /* 128 CLK */
  DAC_REFRESH_256CLK_gc = (0x04<<0),   /* 256 CLK */
  DAC_REFRESH_512CLK_gc = (0x05<<0),   /* 512 CLK */
  DAC_REFRESH_1024CLK_gc = (0x06<<0),   /* 1024 CLK */
  DAC_REFRESH_2048CLK_gc = (0x07<<0),   /* 2048 CLK */
  DAC_REFRESH_4086CLK_gc = (0x08<<0),   /* 4096 CLK */
  DAC_REFRESH_8192CLK_gc = (0x09<<0),   /* 8192 CLK */
  DAC_REFRESH_16384CLK_gc = (0x0A<<0),   /* 16384 CLK */
  DAC_REFRESH_32768CLK_gc = (0x0B<<0),   /* 32768 CLK */
  DAC_REFRESH_65536CLK_gc = (0x0C<<0),   /* 65536 CLK */
  DAC_REFRESH_OFF_gc = (0x0F<<0),   /* Auto refresh OFF */
} DAC_REFRESH_t;
#endif /* !defined (__ASSEMBLER__) */


/*
--------------------------------------------------------------------------
 RTC - Real-Time Clock
--------------------------------------------------------------------------
*/

/* RTC.CTRL bit masks and bit positions */

        
#define RTC_PRESCALER_gm 0x07 // Prescaling Factor group mask
#define RTC_PRESCALER_bp 0 // Prescaling Factor group position

#define RTC_PRESCALER0_bm (1<<0) // Prescaling Factor bit 0 mask
#define RTC_PRESCALER0_bp 0 // Prescaling Factor bit 0 position
#define RTC_PRESCALER1_bm (1<<1) // Prescaling Factor bit 1 mask
#define RTC_PRESCALER1_bp 1 // Prescaling Factor bit 1 position
#define RTC_PRESCALER2_bm (1<<2) // Prescaling Factor bit 2 mask
#define RTC_PRESCALER2_bp 2 // Prescaling Factor bit 2 position

/* RTC.STATUS bit masks and bit positions */

        
#define RTC_SYNCBUSY_bm 0x01 // Synchronization Busy Flag bit mask
#define RTC_SYNCBUSY_bp 0 // Synchronization Busy Flag bit position

/* RTC.INTCTRL bit masks and bit positions */

        
#define RTC_COMPINTLVL_gm 0x0C // Compare Match Interrupt Level group mask
#define RTC_COMPINTLVL_bp 2 // Compare Match Interrupt Level group position

#define RTC_COMPINTLVL0_bm (1<<2) // Compare Match Interrupt Level bit 0 mask
#define RTC_COMPINTLVL0_bp 2 // Compare Match Interrupt Level bit 0 position
#define RTC_COMPINTLVL1_bm (1<<3) // Compare Match Interrupt Level bit 1 mask
#define RTC_COMPINTLVL1_bp 3 // Compare Match Interrupt Level bit 1 position
#define RTC_OVFINTLVL_gm 0x03 // Overflow Interrupt Level group mask
#define RTC_OVFINTLVL_bp 0 // Overflow Interrupt Level group position

#define RTC_OVFINTLVL0_bm (1<<0) // Overflow Interrupt Level bit 0 mask
#define RTC_OVFINTLVL0_bp 0 // Overflow Interrupt Level bit 0 position
#define RTC_OVFINTLVL1_bm (1<<1) // Overflow Interrupt Level bit 1 mask
#define RTC_OVFINTLVL1_bp 1 // Overflow Interrupt Level bit 1 position

/* RTC.INTFLAGS bit masks and bit positions */

        
#define RTC_COMPIF_bm 0x02 // Compare Match Interrupt Flag bit mask
#define RTC_COMPIF_bp 1 // Compare Match Interrupt Flag bit position
#define RTC_OVFIF_bm 0x01 // Overflow Interrupt Flag bit mask
#define RTC_OVFIF_bp 0 // Overflow Interrupt Flag bit position

#if !defined (__ASSEMBLER__)
/* Prescaler Factor */
typedef enum RTC_PRESCALER_enum
{
  RTC_PRESCALER_OFF_gc = (0x00<<0),   /* RTC Off */
  RTC_PRESCALER_DIV1_gc = (0x01<<0),   /* RTC Clock */
  RTC_PRESCALER_DIV2_gc = (0x02<<0),   /* RTC Clock / 2 */
  RTC_PRESCALER_DIV8_gc = (0x03<<0),   /* RTC Clock / 8 */
  RTC_PRESCALER_DIV16_gc = (0x04<<0),   /* RTC Clock / 16 */
  RTC_PRESCALER_DIV64_gc = (0x05<<0),   /* RTC Clock / 64 */
  RTC_PRESCALER_DIV256_gc = (0x06<<0),   /* RTC Clock / 256 */
  RTC_PRESCALER_DIV1024_gc = (0x07<<0),   /* RTC Clock / 1024 */
} RTC_PRESCALER_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/* Compare Interrupt level */
typedef enum RTC_COMPINTLVL_enum
{
  RTC_COMPINTLVL_OFF_gc = (0x00<<2),   /* Interrupt Disabled */
  RTC_COMPINTLVL_LO_gc = (0x01<<2),   /* Low Level */
  RTC_COMPINTLVL_MED_gc = (0x02<<2),   /* Medium Level */
  RTC_COMPINTLVL_HI_gc = (0x03<<2),   /* High Level */
} RTC_COMPINTLVL_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/* Overflow Interrupt level */
typedef enum RTC_OVFINTLVL_enum
{
  RTC_OVFINTLVL_OFF_gc = (0x00<<0),   /* Interrupt Disabled */
  RTC_OVFINTLVL_LO_gc = (0x01<<0),   /* Low Level */
  RTC_OVFINTLVL_MED_gc = (0x02<<0),   /* Medium Level */
  RTC_OVFINTLVL_HI_gc = (0x03<<0),   /* High Level */
} RTC_OVFINTLVL_t;
#endif /* !defined (__ASSEMBLER__) */


/*
--------------------------------------------------------------------------
 EBI - External Bus Interface
--------------------------------------------------------------------------
*/

/* EBI_CS.CTRLA bit masks and bit positions */

        
#define EBI_CS_ASPACE_gm 0x7C // Address Space group mask
#define EBI_CS_ASPACE_bp 2 // Address Space group position

#define EBI_CS_ASPACE0_bm (1<<2) // Address Space bit 0 mask
#define EBI_CS_ASPACE0_bp 2 // Address Space bit 0 position
#define EBI_CS_ASPACE1_bm (1<<3) // Address Space bit 1 mask
#define EBI_CS_ASPACE1_bp 3 // Address Space bit 1 position
#define EBI_CS_ASPACE2_bm (1<<4) // Address Space bit 2 mask
#define EBI_CS_ASPACE2_bp 4 // Address Space bit 2 position
#define EBI_CS_ASPACE3_bm (1<<5) // Address Space bit 3 mask
#define EBI_CS_ASPACE3_bp 5 // Address Space bit 3 position
#define EBI_CS_ASPACE4_bm (1<<6) // Address Space bit 4 mask
#define EBI_CS_ASPACE4_bp 6 // Address Space bit 4 position
#define EBI_CS_MODE_gm 0x03 // Memory Mode group mask
#define EBI_CS_MODE_bp 0 // Memory Mode group position

#define EBI_CS_MODE0_bm (1<<0) // Memory Mode bit 0 mask
#define EBI_CS_MODE0_bp 0 // Memory Mode bit 0 position
#define EBI_CS_MODE1_bm (1<<1) // Memory Mode bit 1 mask
#define EBI_CS_MODE1_bp 1 // Memory Mode bit 1 position

/* EBI_CS.CTRLB bit masks and bit positions */

        
#define EBI_CS_SRWS_gm 0x07 // SRAM Wait State Cycles group mask
#define EBI_CS_SRWS_bp 0 // SRAM Wait State Cycles group position

#define EBI_CS_SRWS0_bm (1<<0) // SRAM Wait State Cycles bit 0 mask
#define EBI_CS_SRWS0_bp 0 // SRAM Wait State Cycles bit 0 position
#define EBI_CS_SRWS1_bm (1<<1) // SRAM Wait State Cycles bit 1 mask
#define EBI_CS_SRWS1_bp 1 // SRAM Wait State Cycles bit 1 position
#define EBI_CS_SRWS2_bm (1<<2) // SRAM Wait State Cycles bit 2 mask
#define EBI_CS_SRWS2_bp 2 // SRAM Wait State Cycles bit 2 position
#define EBI_CS_SDINITDONE_bm 0x80 // SDRAM Initialization Done bit mask
#define EBI_CS_SDINITDONE_bp 7 // SDRAM Initialization Done bit position
#define EBI_CS_SDSREN_bm 0x04 // SDRAM Self-refresh Enable bit mask
#define EBI_CS_SDSREN_bp 2 // SDRAM Self-refresh Enable bit position
#define EBI_CS_SDMODE_gm 0x03 // SDRAM Mode group mask
#define EBI_CS_SDMODE_bp 0 // SDRAM Mode group position

#define EBI_CS_SDMODE0_bm (1<<0) // SDRAM Mode bit 0 mask
#define EBI_CS_SDMODE0_bp 0 // SDRAM Mode bit 0 position
#define EBI_CS_SDMODE1_bm (1<<1) // SDRAM Mode bit 1 mask
#define EBI_CS_SDMODE1_bp 1 // SDRAM Mode bit 1 position

/* EBI.CTRL bit masks and bit positions */

        
#define EBI_SDDATAW_gm 0xC0 // SDRAM Data Width Setting group mask
#define EBI_SDDATAW_bp 6 // SDRAM Data Width Setting group position

#define EBI_SDDATAW0_bm (1<<6) // SDRAM Data Width Setting bit 0 mask
#define EBI_SDDATAW0_bp 6 // SDRAM Data Width Setting bit 0 position
#define EBI_SDDATAW1_bm (1<<7) // SDRAM Data Width Setting bit 1 mask
#define EBI_SDDATAW1_bp 7 // SDRAM Data Width Setting bit 1 position
#define EBI_LPCMODE_gm 0x30 // SRAM LPC Mode group mask
#define EBI_LPCMODE_bp 4 // SRAM LPC Mode group position

#define EBI_LPCMODE0_bm (1<<4) // SRAM LPC Mode bit 0 mask
#define EBI_LPCMODE0_bp 4 // SRAM LPC Mode bit 0 position
#define EBI_LPCMODE1_bm (1<<5) // SRAM LPC Mode bit 1 mask
#define EBI_LPCMODE1_bp 5 // SRAM LPC Mode bit 1 position
#define EBI_SRMODE_gm 0x0C // SRAM Mode group mask
#define EBI_SRMODE_bp 2 // SRAM Mode group position

#define EBI_SRMODE0_bm (1<<2) // SRAM Mode bit 0 mask
#define EBI_SRMODE0_bp 2 // SRAM Mode bit 0 position
#define EBI_SRMODE1_bm (1<<3) // SRAM Mode bit 1 mask
#define EBI_SRMODE1_bp 3 // SRAM Mode bit 1 position
#define EBI_IFMODE_gm 0x03 // Interface Mode group mask
#define EBI_IFMODE_bp 0 // Interface Mode group position

#define EBI_IFMODE0_bm (1<<0) // Interface Mode bit 0 mask
#define EBI_IFMODE0_bp 0 // Interface Mode bit 0 position
#define EBI_IFMODE1_bm (1<<1) // Interface Mode bit 1 mask
#define EBI_IFMODE1_bp 1 // Interface Mode bit 1 position

/* EBI.SDRAMCTRLA bit masks and bit positions */

        
#define EBI_SDCAS_bm 0x08 // SDRAM CAS Latency Setting bit mask
#define EBI_SDCAS_bp 3 // SDRAM CAS Latency Setting bit position
#define EBI_SDROW_bm 0x04 // SDRAM ROW Bits Setting bit mask
#define EBI_SDROW_bp 2 // SDRAM ROW Bits Setting bit position
#define EBI_SDCOL_gm 0x03 // SDRAM Column Bits Setting group mask
#define EBI_SDCOL_bp 0 // SDRAM Column Bits Setting group position

#define EBI_SDCOL0_bm (1<<0) // SDRAM Column Bits Setting bit 0 mask
#define EBI_SDCOL0_bp 0 // SDRAM Column Bits Setting bit 0 position
#define EBI_SDCOL1_bm (1<<1) // SDRAM Column Bits Setting bit 1 mask
#define EBI_SDCOL1_bp 1 // SDRAM Column Bits Setting bit 1 position

/* EBI.SDRAMCTRLB bit masks and bit positions */

        
#define EBI_MRDLY_gm 0xC0 // SDRAM Mode Register Delay group mask
#define EBI_MRDLY_bp 6 // SDRAM Mode Register Delay group position

#define EBI_MRDLY0_bm (1<<6) // SDRAM Mode Register Delay bit 0 mask
#define EBI_MRDLY0_bp 6 // SDRAM Mode Register Delay bit 0 position
#define EBI_MRDLY1_bm (1<<7) // SDRAM Mode Register Delay bit 1 mask
#define EBI_MRDLY1_bp 7 // SDRAM Mode Register Delay bit 1 position
#define EBI_ROWCYCDLY_gm 0x38 // SDRAM Row Cycle Delay group mask
#define EBI_ROWCYCDLY_bp 3 // SDRAM Row Cycle Delay group position

#define EBI_ROWCYCDLY0_bm (1<<3) // SDRAM Row Cycle Delay bit 0 mask
#define EBI_ROWCYCDLY0_bp 3 // SDRAM Row Cycle Delay bit 0 position
#define EBI_ROWCYCDLY1_bm (1<<4) // SDRAM Row Cycle Delay bit 1 mask
#define EBI_ROWCYCDLY1_bp 4 // SDRAM Row Cycle Delay bit 1 position
#define EBI_ROWCYCDLY2_bm (1<<5) // SDRAM Row Cycle Delay bit 2 mask
#define EBI_ROWCYCDLY2_bp 5 // SDRAM Row Cycle Delay bit 2 position
#define EBI_RPDLY_gm 0x07 // SDRAM Row-to-Precharge Delay group mask
#define EBI_RPDLY_bp 0 // SDRAM Row-to-Precharge Delay group position

#define EBI_RPDLY0_bm (1<<0) // SDRAM Row-to-Precharge Delay bit 0 mask
#define EBI_RPDLY0_bp 0 // SDRAM Row-to-Precharge Delay bit 0 position
#define EBI_RPDLY1_bm (1<<1) // SDRAM Row-to-Precharge Delay bit 1 mask
#define EBI_RPDLY1_bp 1 // SDRAM Row-to-Precharge Delay bit 1 position
#define EBI_RPDLY2_bm (1<<2) // SDRAM Row-to-Precharge Delay bit 2 mask
#define EBI_RPDLY2_bp 2 // SDRAM Row-to-Precharge Delay bit 2 position

/* EBI.SDRAMCTRLC bit masks and bit positions */

        
#define EBI_WRDLY_gm 0xC0 // SDRAM Write Recovery Delay group mask
#define EBI_WRDLY_bp 6 // SDRAM Write Recovery Delay group position

#define EBI_WRDLY0_bm (1<<6) // SDRAM Write Recovery Delay bit 0 mask
#define EBI_WRDLY0_bp 6 // SDRAM Write Recovery Delay bit 0 position
#define EBI_WRDLY1_bm (1<<7) // SDRAM Write Recovery Delay bit 1 mask
#define EBI_WRDLY1_bp 7 // SDRAM Write Recovery Delay bit 1 position
#define EBI_ESRDLY_gm 0x38 // SDRAM Exit-Self-refresh-to-Active Delay group mask
#define EBI_ESRDLY_bp 3 // SDRAM Exit-Self-refresh-to-Active Delay group position

#define EBI_ESRDLY0_bm (1<<3) // SDRAM Exit-Self-refresh-to-Active Delay bit 0 mask
#define EBI_ESRDLY0_bp 3 // SDRAM Exit-Self-refresh-to-Active Delay bit 0 position
#define EBI_ESRDLY1_bm (1<<4) // SDRAM Exit-Self-refresh-to-Active Delay bit 1 mask
#define EBI_ESRDLY1_bp 4 // SDRAM Exit-Self-refresh-to-Active Delay bit 1 position
#define EBI_ESRDLY2_bm (1<<5) // SDRAM Exit-Self-refresh-to-Active Delay bit 2 mask
#define EBI_ESRDLY2_bp 5 // SDRAM Exit-Self-refresh-to-Active Delay bit 2 position
#define EBI_ROWCOLDLY_gm 0x07 // SDRAM Row-to-Column Delay group mask
#define EBI_ROWCOLDLY_bp 0 // SDRAM Row-to-Column Delay group position

#define EBI_ROWCOLDLY0_bm (1<<0) // SDRAM Row-to-Column Delay bit 0 mask
#define EBI_ROWCOLDLY0_bp 0 // SDRAM Row-to-Column Delay bit 0 position
#define EBI_ROWCOLDLY1_bm (1<<1) // SDRAM Row-to-Column Delay bit 1 mask
#define EBI_ROWCOLDLY1_bp 1 // SDRAM Row-to-Column Delay bit 1 position
#define EBI_ROWCOLDLY2_bm (1<<2) // SDRAM Row-to-Column Delay bit 2 mask
#define EBI_ROWCOLDLY2_bp 2 // SDRAM Row-to-Column Delay bit 2 position

#if !defined (__ASSEMBLER__)
/*  */
typedef enum EBI_CS_ASPACE_enum
{
  EBI_CS_ASPACE_256B_gc = (0x00<<2),   /* 256 bytes */
  EBI_CS_ASPACE_512B_gc = (0x01<<2),   /* 512 bytes */
  EBI_CS_ASPACE_1KB_gc = (0x02<<2),   /* 1K bytes */
  EBI_CS_ASPACE_2KB_gc = (0x03<<2),   /* 2K bytes */
  EBI_CS_ASPACE_4KB_gc = (0x04<<2),   /* 4K bytes */
  EBI_CS_ASPACE_8KB_gc = (0x05<<2),   /* 8K bytes */
  EBI_CS_ASPACE_16KB_gc = (0x06<<2),   /* 16K bytes */
  EBI_CS_ASPACE_32KB_gc = (0x07<<2),   /* 32K bytes */
  EBI_CS_ASPACE_64KB_gc = (0x08<<2),   /* 64K bytes */
  EBI_CS_ASPACE_128KB_gc = (0x09<<2),   /* 128K bytes */
  EBI_CS_ASPACE_256KB_gc = (0x0A<<2),   /* 256K bytes */
  EBI_CS_ASPACE_512KB_gc = (0x0B<<2),   /* 512K bytes */
  EBI_CS_ASPACE_1MB_gc = (0x0C<<2),   /* 1M bytes */
  EBI_CS_ASPACE_2MB_gc = (0x0D<<2),   /* 2M bytes */
  EBI_CS_ASPACE_4MB_gc = (0x0E<<2),   /* 4M bytes */
  EBI_CS_ASPACE_8MB_gc = (0x0F<<2),   /* 8M bytes */
  EBI_CS_ASPACE_16M_gc = (0x10<<2),   /* 16M bytes */
} EBI_CS_ASPACE_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/*  */
typedef enum EBI_CS_MODE_enum
{
  EBI_CS_MODE_DISABLED_gc = (0x00<<0),   /* Chip Select Disabled */
  EBI_CS_MODE_SRAM_gc = (0x01<<0),   /* Chip Select in SRAM mode */
  EBI_CS_MODE_LPC_gc = (0x02<<0),   /* Chip Select in SRAM LPC mode */
  EBI_CS_MODE_SDRAM_gc = (0x03<<0),   /* Chip Select in SDRAM mode */
} EBI_CS_MODE_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/*  */
typedef enum EBI_CS_SDMODE_enum
{
  EBI_CS_SDMODE_NORMAL_gc = (0x00<<0),   /* Normal mode */
  EBI_CS_SDMODE_LOAD_gc = (0x01<<0),   /* Load Mode Register command mode */
} EBI_CS_SDMODE_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/*  */
typedef enum EBI_SDDATAW_enum
{
  EBI_SDDATAW_4BIT_gc = (0x00<<6),   /* 4-bit data bus */
  EBI_SDDATAW_8BIT_gc = (0x01<<6),   /* 8-bit data bus */
} EBI_SDDATAW_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/*  */
typedef enum EBI_LPCMODE_enum
{
  EBI_LPCMODE_ALE1_gc = (0x00<<4),   /* Data muxed with addr byte 0 */
  EBI_LPCMODE_ALE12_gc = (0x02<<4),   /* Data muxed with addr byte 0 and 1 */
} EBI_LPCMODE_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/*  */
typedef enum EBI_SRMODE_enum
{
  EBI_SRMODE_ALE1_gc = (0x00<<2),   /* Addr byte 0 muxed with 1 */
  EBI_SRMODE_ALE2_gc = (0x01<<2),   /* Addr byte 0 muxed with 2 */
  EBI_SRMODE_ALE12_gc = (0x02<<2),   /* Addr byte 0 muxed with 1 and 2 */
  EBI_SRMODE_NOALE_gc = (0x03<<2),   /* No addr muxing */
} EBI_SRMODE_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/*  */
typedef enum EBI_IFMODE_enum
{
  EBI_IFMODE_DISABLED_gc = (0x00<<0),   /* EBI Disabled */
  EBI_IFMODE_3PORT_gc = (0x01<<0),   /* 3-port mode */
  EBI_IFMODE_4PORT_gc = (0x02<<0),   /* 4-port mode */
  EBI_IFMODE_2PORT_gc = (0x03<<0),   /* 2-port mode */
} EBI_IFMODE_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/*  */
typedef enum EBI_SDCOL_enum
{
  EBI_SDCOL_8BIT_gc = (0x00<<0),   /* 8 column bits */
  EBI_SDCOL_9BIT_gc = (0x01<<0),   /* 9 column bits */
  EBI_SDCOL_10BIT_gc = (0x02<<0),   /* 10 column bits */
  EBI_SDCOL_11BIT_gc = (0x03<<0),   /* 11 column bits */
} EBI_SDCOL_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/*  */
typedef enum EBI_MRDLY_enum
{
  EBI_MRDLY_0CLK_gc = (0x00<<6),   /* 0 cycles */
  EBI_MRDLY_1CLK_gc = (0x01<<6),   /* 1 cycle */
  EBI_MRDLY_2CLK_gc = (0x02<<6),   /* 2 cycles */
  EBI_MRDLY_3CLK_gc = (0x03<<6),   /* 3 cycles */
} EBI_MRDLY_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/*  */
typedef enum EBI_ROWCYCDLY_enum
{
  EBI_ROWCYCDLY_0CLK_gc = (0x00<<3),   /* 0 cycles */
  EBI_ROWCYCDLY_1CLK_gc = (0x01<<3),   /* 1 cycle */
  EBI_ROWCYCDLY_2CLK_gc = (0x02<<3),   /* 2 cycles */
  EBI_ROWCYCDLY_3CLK_gc = (0x03<<3),   /* 3 cycles */
  EBI_ROWCYCDLY_4CLK_gc = (0x04<<3),   /* 4 cycles */
  EBI_ROWCYCDLY_5CLK_gc = (0x05<<3),   /* 5 cycle */
  EBI_ROWCYCDLY_6CLK_gc = (0x06<<3),   /* 6 cycles */
  EBI_ROWCYCDLY_7CLK_gc = (0x07<<3),   /* 7 cycles */
} EBI_ROWCYCDLY_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/*  */
typedef enum EBI_RPDLY_enum
{
  EBI_RPDLY_0CLK_gc = (0x00<<0),   /* 0 cycles */
  EBI_RPDLY_1CLK_gc = (0x01<<0),   /* 1 cycle */
  EBI_RPDLY_2CLK_gc = (0x02<<0),   /* 2 cycles */
  EBI_RPDLY_3CLK_gc = (0x03<<0),   /* 3 cycles */
  EBI_RPDLY_4CLK_gc = (0x04<<0),   /* 4 cycles */
  EBI_RPDLY_5CLK_gc = (0x05<<0),   /* 5 cycle */
  EBI_RPDLY_6CLK_gc = (0x06<<0),   /* 6 cycles */
  EBI_RPDLY_7CLK_gc = (0x07<<0),   /* 7 cycles */
} EBI_RPDLY_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/*  */
typedef enum EBI_WRDLY_enum
{
  EBI_WRDLY_0CLK_gc = (0x00<<6),   /* 0 cycles */
  EBI_WRDLY_1CLK_gc = (0x01<<6),   /* 1 cycle */
  EBI_WRDLY_2CLK_gc = (0x02<<6),   /* 2 cycles */
  EBI_WRDLY_3CLK_gc = (0x03<<6),   /* 3 cycles */
} EBI_WRDLY_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/*  */
typedef enum EBI_ESRDLY_enum
{
  EBI_ESRDLY_0CLK_gc = (0x00<<3),   /* 0 cycles */
  EBI_ESRDLY_1CLK_gc = (0x01<<3),   /* 1 cycle */
  EBI_ESRDLY_2CLK_gc = (0x02<<3),   /* 2 cycles */
  EBI_ESRDLY_3CLK_gc = (0x03<<3),   /* 3 cycles */
  EBI_ESRDLY_4CLK_gc = (0x04<<3),   /* 4 cycles */
  EBI_ESRDLY_5CLK_gc = (0x05<<3),   /* 5 cycle */
  EBI_ESRDLY_6CLK_gc = (0x06<<3),   /* 6 cycles */
  EBI_ESRDLY_7CLK_gc = (0x07<<3),   /* 7 cycles */
} EBI_ESRDLY_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/*  */
typedef enum EBI_ROWCOLDLY_enum
{
  EBI_ROWCOLDLY_0CLK_gc = (0x00<<0),   /* 0 cycles */
  EBI_ROWCOLDLY_1CLK_gc = (0x01<<0),   /* 1 cycle */
  EBI_ROWCOLDLY_2CLK_gc = (0x02<<0),   /* 2 cycles */
  EBI_ROWCOLDLY_3CLK_gc = (0x03<<0),   /* 3 cycles */
  EBI_ROWCOLDLY_4CLK_gc = (0x04<<0),   /* 4 cycles */
  EBI_ROWCOLDLY_5CLK_gc = (0x05<<0),   /* 5 cycle */
  EBI_ROWCOLDLY_6CLK_gc = (0x06<<0),   /* 6 cycles */
  EBI_ROWCOLDLY_7CLK_gc = (0x07<<0),   /* 7 cycles */
} EBI_ROWCOLDLY_t;
#endif /* !defined (__ASSEMBLER__) */


/*
--------------------------------------------------------------------------
 TWI - Two-Wire Interface
--------------------------------------------------------------------------
*/

/* TWI_MASTER.CTRLA bit masks and bit positions */

        
#define TWI_MASTER_INTLVL_gm 0xC0 // Interrupt Level group mask
#define TWI_MASTER_INTLVL_bp 6 // Interrupt Level group position

#define TWI_MASTER_INTLVL0_bm (1<<6) // Interrupt Level bit 0 mask
#define TWI_MASTER_INTLVL0_bp 6 // Interrupt Level bit 0 position
#define TWI_MASTER_INTLVL1_bm (1<<7) // Interrupt Level bit 1 mask
#define TWI_MASTER_INTLVL1_bp 7 // Interrupt Level bit 1 position
#define TWI_MASTER_RIEN_bm 0x20 // Read Interrupt Enable bit mask
#define TWI_MASTER_RIEN_bp 5 // Read Interrupt Enable bit position
#define TWI_MASTER_WIEN_bm 0x10 // Write Interrupt Enable bit mask
#define TWI_MASTER_WIEN_bp 4 // Write Interrupt Enable bit position
#define TWI_MASTER_ENABLE_bm 0x08 // Enable TWI Master bit mask
#define TWI_MASTER_ENABLE_bp 3 // Enable TWI Master bit position

/* TWI_MASTER.CTRLB bit masks and bit positions */

        
#define TWI_MASTER_TIMEOUT_gm 0x0C // Inactive Bus Timeout group mask
#define TWI_MASTER_TIMEOUT_bp 2 // Inactive Bus Timeout group position

#define TWI_MASTER_TIMEOUT0_bm (1<<2) // Inactive Bus Timeout bit 0 mask
#define TWI_MASTER_TIMEOUT0_bp 2 // Inactive Bus Timeout bit 0 position
#define TWI_MASTER_TIMEOUT1_bm (1<<3) // Inactive Bus Timeout bit 1 mask
#define TWI_MASTER_TIMEOUT1_bp 3 // Inactive Bus Timeout bit 1 position
#define TWI_MASTER_QCEN_bm 0x02 // Quick Command Enable bit mask
#define TWI_MASTER_QCEN_bp 1 // Quick Command Enable bit position
#define TWI_MASTER_SMEN_bm 0x01 // Smart Mode Enable bit mask
#define TWI_MASTER_SMEN_bp 0 // Smart Mode Enable bit position

/* TWI_MASTER.CTRLC bit masks and bit positions */

        
#define TWI_MASTER_ACKACT_bm 0x04 // Acknowledge Action bit mask
#define TWI_MASTER_ACKACT_bp 2 // Acknowledge Action bit position
#define TWI_MASTER_CMD_gm 0x03 // Command group mask
#define TWI_MASTER_CMD_bp 0 // Command group position

#define TWI_MASTER_CMD0_bm (1<<0) // Command bit 0 mask
#define TWI_MASTER_CMD0_bp 0 // Command bit 0 position
#define TWI_MASTER_CMD1_bm (1<<1) // Command bit 1 mask
#define TWI_MASTER_CMD1_bp 1 // Command bit 1 position

/* TWI_MASTER.STATUS bit masks and bit positions */

        
#define TWI_MASTER_RIF_bm 0x80 // Read Interrupt Flag bit mask
#define TWI_MASTER_RIF_bp 7 // Read Interrupt Flag bit position
#define TWI_MASTER_WIF_bm 0x40 // Write Interrupt Flag bit mask
#define TWI_MASTER_WIF_bp 6 // Write Interrupt Flag bit position
#define TWI_MASTER_CLKHOLD_bm 0x20 // Clock Hold bit mask
#define TWI_MASTER_CLKHOLD_bp 5 // Clock Hold bit position
#define TWI_MASTER_RXACK_bm 0x10 // Received Acknowledge bit mask
#define TWI_MASTER_RXACK_bp 4 // Received Acknowledge bit position
#define TWI_MASTER_ARBLOST_bm 0x08 // Arbitration Lost bit mask
#define TWI_MASTER_ARBLOST_bp 3 // Arbitration Lost bit position
#define TWI_MASTER_BUSERR_bm 0x04 // Bus Error bit mask
#define TWI_MASTER_BUSERR_bp 2 // Bus Error bit position
#define TWI_MASTER_BUSSTATE_gm 0x03 // Bus State group mask
#define TWI_MASTER_BUSSTATE_bp 0 // Bus State group position

#define TWI_MASTER_BUSSTATE0_bm (1<<0) // Bus State bit 0 mask
#define TWI_MASTER_BUSSTATE0_bp 0 // Bus State bit 0 position
#define TWI_MASTER_BUSSTATE1_bm (1<<1) // Bus State bit 1 mask
#define TWI_MASTER_BUSSTATE1_bp 1 // Bus State bit 1 position

/* TWI_SLAVE.CTRLA bit masks and bit positions */

        
#define TWI_SLAVE_INTLVL_gm 0xC0 // Interrupt Level group mask
#define TWI_SLAVE_INTLVL_bp 6 // Interrupt Level group position

#define TWI_SLAVE_INTLVL0_bm (1<<6) // Interrupt Level bit 0 mask
#define TWI_SLAVE_INTLVL0_bp 6 // Interrupt Level bit 0 position
#define TWI_SLAVE_INTLVL1_bm (1<<7) // Interrupt Level bit 1 mask
#define TWI_SLAVE_INTLVL1_bp 7 // Interrupt Level bit 1 position
#define TWI_SLAVE_DIEN_bm 0x20 // Data Interrupt Enable bit mask
#define TWI_SLAVE_DIEN_bp 5 // Data Interrupt Enable bit position
#define TWI_SLAVE_APIEN_bm 0x10 // Address/Stop Interrupt Enable bit mask
#define TWI_SLAVE_APIEN_bp 4 // Address/Stop Interrupt Enable bit position
#define TWI_SLAVE_ENABLE_bm 0x08 // Enable TWI Slave bit mask
#define TWI_SLAVE_ENABLE_bp 3 // Enable TWI Slave bit position
#define TWI_SLAVE_PIEN_bm 0x04 // Stop Interrupt Enable bit mask
#define TWI_SLAVE_PIEN_bp 2 // Stop Interrupt Enable bit position
#define TWI_SLAVE_PMEN_bm 0x02 // Promiscuous Mode Enable bit mask
#define TWI_SLAVE_PMEN_bp 1 // Promiscuous Mode Enable bit position
#define TWI_SLAVE_SMEN_bm 0x01 // Smart Mode Enable bit mask
#define TWI_SLAVE_SMEN_bp 0 // Smart Mode Enable bit position

/* TWI_SLAVE.CTRLB bit masks and bit positions */

        
#define TWI_SLAVE_ACKACT_bm 0x04 // Acknowledge Action bit mask
#define TWI_SLAVE_ACKACT_bp 2 // Acknowledge Action bit position
#define TWI_SLAVE_CMD_gm 0x03 // Command group mask
#define TWI_SLAVE_CMD_bp 0 // Command group position

#define TWI_SLAVE_CMD0_bm (1<<0) // Command bit 0 mask
#define TWI_SLAVE_CMD0_bp 0 // Command bit 0 position
#define TWI_SLAVE_CMD1_bm (1<<1) // Command bit 1 mask
#define TWI_SLAVE_CMD1_bp 1 // Command bit 1 position

/* TWI_SLAVE.STATUS bit masks and bit positions */

        
#define TWI_SLAVE_DIF_bm 0x80 // Data Interrupt Flag bit mask
#define TWI_SLAVE_DIF_bp 7 // Data Interrupt Flag bit position
#define TWI_SLAVE_APIF_bm 0x40 // Address/Stop Interrupt Flag bit mask
#define TWI_SLAVE_APIF_bp 6 // Address/Stop Interrupt Flag bit position
#define TWI_SLAVE_CLKHOLD_bm 0x20 // Clock Hold bit mask
#define TWI_SLAVE_CLKHOLD_bp 5 // Clock Hold bit position
#define TWI_SLAVE_RXACK_bm 0x10 // Received Acknowledge bit mask
#define TWI_SLAVE_RXACK_bp 4 // Received Acknowledge bit position
#define TWI_SLAVE_COLL_bm 0x08 // Collision bit mask
#define TWI_SLAVE_COLL_bp 3 // Collision bit position
#define TWI_SLAVE_BUSERR_bm 0x04 // Bus Error bit mask
#define TWI_SLAVE_BUSERR_bp 2 // Bus Error bit position
#define TWI_SLAVE_DIR_bm 0x02 // Read/Write Direction bit mask
#define TWI_SLAVE_DIR_bp 1 // Read/Write Direction bit position
#define TWI_SLAVE_AP_bm 0x01 // Slave Address or Stop bit mask
#define TWI_SLAVE_AP_bp 0 // Slave Address or Stop bit position

/* TWI.CTRL bit masks and bit positions */

        
#define TWI_SDAHOLD_bm 0x02 // SDA Hold Time Enable bit mask
#define TWI_SDAHOLD_bp 1 // SDA Hold Time Enable bit position
#define TWI_EDIEN_bm 0x01 // External Driver Interface Enable bit mask
#define TWI_EDIEN_bp 0 // External Driver Interface Enable bit position

#if !defined (__ASSEMBLER__)
/* Master Interrupt Level */
typedef enum TWI_MASTER_INTLVL_enum
{
  TWI_MASTER_INTLVL_OFF_gc = (0x00<<6),   /* Interrupt Disabled */
  TWI_MASTER_INTLVL_LO_gc = (0x01<<6),   /* Low Level */
  TWI_MASTER_INTLVL_MED_gc = (0x02<<6),   /* Medium Level */
  TWI_MASTER_INTLVL_HI_gc = (0x03<<6),   /* High Level */
} TWI_MASTER_INTLVL_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/* Inactive Timeout */
typedef enum TWI_MASTER_TIMEOUT_enum
{
  TWI_MASTER_TIMEOUT_DISABLED_gc = (0x00<<2),   /* Bus Timeout Disabled */
  TWI_MASTER_TIMEOUT_50US_gc = (0x01<<2),   /* 50 Microseconds */
  TWI_MASTER_TIMEOUT_100US_gc = (0x02<<2),   /* 100 Microseconds */
  TWI_MASTER_TIMEOUT_200US_gc = (0x03<<2),   /* 200 Microseconds */
} TWI_MASTER_TIMEOUT_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/* Master Command */
typedef enum TWI_MASTER_CMD_enum
{
  TWI_MASTER_CMD_NOACT_gc = (0x00<<0),   /* No Action */
  TWI_MASTER_CMD_REPSTART_gc = (0x01<<0),   /* Issue Repeated Start Condition */
  TWI_MASTER_CMD_RECVTRANS_gc = (0x02<<0),   /* Receive or Transmit Data */
  TWI_MASTER_CMD_STOP_gc = (0x03<<0),   /* Issue Stop Condition */
} TWI_MASTER_CMD_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/* Master Bus State */
typedef enum TWI_MASTER_BUSSTATE_enum
{
  TWI_MASTER_BUSSTATE_UNKNOWN_gc = (0x00<<0),   /* Unknown Bus State */
  TWI_MASTER_BUSSTATE_IDLE_gc = (0x01<<0),   /* Bus is Idle */
  TWI_MASTER_BUSSTATE_OWNER_gc = (0x02<<0),   /* This Module Controls The Bus */
  TWI_MASTER_BUSSTATE_BUSY_gc = (0x03<<0),   /* The Bus is Busy */
} TWI_MASTER_BUSSTATE_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/* Slave Interrupt Level */
typedef enum TWI_SLAVE_INTLVL_enum
{
  TWI_SLAVE_INTLVL_OFF_gc = (0x00<<6),   /* Interrupt Disabled */
  TWI_SLAVE_INTLVL_LO_gc = (0x01<<6),   /* Low Level */
  TWI_SLAVE_INTLVL_MED_gc = (0x02<<6),   /* Medium Level */
  TWI_SLAVE_INTLVL_HI_gc = (0x03<<6),   /* High Level */
} TWI_SLAVE_INTLVL_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/* Slave Command */
typedef enum TWI_SLAVE_CMD_enum
{
  TWI_SLAVE_CMD_NOACT_gc = (0x00<<0),   /* No Action */
  TWI_SLAVE_CMD_COMPTRANS_gc = (0x02<<0),   /* Used To Complete a Transaction */
  TWI_SLAVE_CMD_RESPONSE_gc = (0x03<<0),   /* Used in Response to Address/Data Interrupt */
} TWI_SLAVE_CMD_t;
#endif /* !defined (__ASSEMBLER__) */


/*
--------------------------------------------------------------------------
 PORT - Port Configuration
--------------------------------------------------------------------------
*/

/* PORTCFG.VPCTRLA bit masks and bit positions */

        
#define PORTCFG_VP1MAP_gm 0xF0 // Virtual Port 1 Mapping group mask
#define PORTCFG_VP1MAP_bp 4 // Virtual Port 1 Mapping group position

#define PORTCFG_VP1MAP0_bm (1<<4) // Virtual Port 1 Mapping bit 0 mask
#define PORTCFG_VP1MAP0_bp 4 // Virtual Port 1 Mapping bit 0 position
#define PORTCFG_VP1MAP1_bm (1<<5) // Virtual Port 1 Mapping bit 1 mask
#define PORTCFG_VP1MAP1_bp 5 // Virtual Port 1 Mapping bit 1 position
#define PORTCFG_VP1MAP2_bm (1<<6) // Virtual Port 1 Mapping bit 2 mask
#define PORTCFG_VP1MAP2_bp 6 // Virtual Port 1 Mapping bit 2 position
#define PORTCFG_VP1MAP3_bm (1<<7) // Virtual Port 1 Mapping bit 3 mask
#define PORTCFG_VP1MAP3_bp 7 // Virtual Port 1 Mapping bit 3 position
#define PORTCFG_VP0MAP_gm 0x0F // Virtual Port 0 Mapping group mask
#define PORTCFG_VP0MAP_bp 0 // Virtual Port 0 Mapping group position

#define PORTCFG_VP0MAP0_bm (1<<0) // Virtual Port 0 Mapping bit 0 mask
#define PORTCFG_VP0MAP0_bp 0 // Virtual Port 0 Mapping bit 0 position
#define PORTCFG_VP0MAP1_bm (1<<1) // Virtual Port 0 Mapping bit 1 mask
#define PORTCFG_VP0MAP1_bp 1 // Virtual Port 0 Mapping bit 1 position
#define PORTCFG_VP0MAP2_bm (1<<2) // Virtual Port 0 Mapping bit 2 mask
#define PORTCFG_VP0MAP2_bp 2 // Virtual Port 0 Mapping bit 2 position
#define PORTCFG_VP0MAP3_bm (1<<3) // Virtual Port 0 Mapping bit 3 mask
#define PORTCFG_VP0MAP3_bp 3 // Virtual Port 0 Mapping bit 3 position

/* PORTCFG.VPCTRLB bit masks and bit positions */

        
#define PORTCFG_VP3MAP_gm 0xF0 // Virtual Port 3 Mapping group mask
#define PORTCFG_VP3MAP_bp 4 // Virtual Port 3 Mapping group position

#define PORTCFG_VP3MAP0_bm (1<<4) // Virtual Port 3 Mapping bit 0 mask
#define PORTCFG_VP3MAP0_bp 4 // Virtual Port 3 Mapping bit 0 position
#define PORTCFG_VP3MAP1_bm (1<<5) // Virtual Port 3 Mapping bit 1 mask
#define PORTCFG_VP3MAP1_bp 5 // Virtual Port 3 Mapping bit 1 position
#define PORTCFG_VP3MAP2_bm (1<<6) // Virtual Port 3 Mapping bit 2 mask
#define PORTCFG_VP3MAP2_bp 6 // Virtual Port 3 Mapping bit 2 position
#define PORTCFG_VP3MAP3_bm (1<<7) // Virtual Port 3 Mapping bit 3 mask
#define PORTCFG_VP3MAP3_bp 7 // Virtual Port 3 Mapping bit 3 position
#define PORTCFG_VP2MAP_gm 0x0F // Virtual Port 2 Mapping group mask
#define PORTCFG_VP2MAP_bp 0 // Virtual Port 2 Mapping group position

#define PORTCFG_VP2MAP0_bm (1<<0) // Virtual Port 2 Mapping bit 0 mask
#define PORTCFG_VP2MAP0_bp 0 // Virtual Port 2 Mapping bit 0 position
#define PORTCFG_VP2MAP1_bm (1<<1) // Virtual Port 2 Mapping bit 1 mask
#define PORTCFG_VP2MAP1_bp 1 // Virtual Port 2 Mapping bit 1 position
#define PORTCFG_VP2MAP2_bm (1<<2) // Virtual Port 2 Mapping bit 2 mask
#define PORTCFG_VP2MAP2_bp 2 // Virtual Port 2 Mapping bit 2 position
#define PORTCFG_VP2MAP3_bm (1<<3) // Virtual Port 2 Mapping bit 3 mask
#define PORTCFG_VP2MAP3_bp 3 // Virtual Port 2 Mapping bit 3 position

/* PORTCFG.CLKEVOUT bit masks and bit positions */

        
#define PORTCFG_CLKOUT_gm 0x30 // Clock Output Port group mask
#define PORTCFG_CLKOUT_bp 4 // Clock Output Port group position

#define PORTCFG_CLKOUT0_bm (1<<4) // Clock Output Port bit 0 mask
#define PORTCFG_CLKOUT0_bp 4 // Clock Output Port bit 0 position
#define PORTCFG_CLKOUT1_bm (1<<5) // Clock Output Port bit 1 mask
#define PORTCFG_CLKOUT1_bp 5 // Clock Output Port bit 1 position
#define PORTCFG_EVOUT_gm 0x03 // Event Output Port group mask
#define PORTCFG_EVOUT_bp 0 // Event Output Port group position

#define PORTCFG_EVOUT0_bm (1<<0) // Event Output Port bit 0 mask
#define PORTCFG_EVOUT0_bp 0 // Event Output Port bit 0 position
#define PORTCFG_EVOUT1_bm (1<<1) // Event Output Port bit 1 mask
#define PORTCFG_EVOUT1_bp 1 // Event Output Port bit 1 position

/* VPORT.INTFLAGS bit masks and bit positions */

        
#define VPORT_INT1IF_bm 0x02 // Port Interrupt 1 Flag bit mask
#define VPORT_INT1IF_bp 1 // Port Interrupt 1 Flag bit position
#define VPORT_INT0IF_bm 0x01 // Port Interrupt 0 Flag bit mask
#define VPORT_INT0IF_bp 0 // Port Interrupt 0 Flag bit position

/* PORT.INTCTRL bit masks and bit positions */

        
#define PORT_INT1LVL_gm 0x0C // Port Interrupt 1 Level group mask
#define PORT_INT1LVL_bp 2 // Port Interrupt 1 Level group position

#define PORT_INT1LVL0_bm (1<<2) // Port Interrupt 1 Level bit 0 mask
#define PORT_INT1LVL0_bp 2 // Port Interrupt 1 Level bit 0 position
#define PORT_INT1LVL1_bm (1<<3) // Port Interrupt 1 Level bit 1 mask
#define PORT_INT1LVL1_bp 3 // Port Interrupt 1 Level bit 1 position
#define PORT_INT0LVL_gm 0x03 // Port Interrupt 0 Level group mask
#define PORT_INT0LVL_bp 0 // Port Interrupt 0 Level group position

#define PORT_INT0LVL0_bm (1<<0) // Port Interrupt 0 Level bit 0 mask
#define PORT_INT0LVL0_bp 0 // Port Interrupt 0 Level bit 0 position
#define PORT_INT0LVL1_bm (1<<1) // Port Interrupt 0 Level bit 1 mask
#define PORT_INT0LVL1_bp 1 // Port Interrupt 0 Level bit 1 position

/* PORT.INTFLAGS bit masks and bit positions */

        
#define PORT_INT1IF_bm 0x02 // Port Interrupt 1 Flag bit mask
#define PORT_INT1IF_bp 1 // Port Interrupt 1 Flag bit position
#define PORT_INT0IF_bm 0x01 // Port Interrupt 0 Flag bit mask
#define PORT_INT0IF_bp 0 // Port Interrupt 0 Flag bit position

/* PORT.PIN0CTRL bit masks and bit positions */

        
#define PORT_SRLEN_bm 0x80 // Slew Rate Enable bit mask
#define PORT_SRLEN_bp 7 // Slew Rate Enable bit position
#define PORT_INVEN_bm 0x40 // Inverted I/O Enable bit mask
#define PORT_INVEN_bp 6 // Inverted I/O Enable bit position
#define PORT_OPC_gm 0x38 // Output/Pull Configuration group mask
#define PORT_OPC_bp 3 // Output/Pull Configuration group position

#define PORT_OPC0_bm (1<<3) // Output/Pull Configuration bit 0 mask
#define PORT_OPC0_bp 3 // Output/Pull Configuration bit 0 position
#define PORT_OPC1_bm (1<<4) // Output/Pull Configuration bit 1 mask
#define PORT_OPC1_bp 4 // Output/Pull Configuration bit 1 position
#define PORT_OPC2_bm (1<<5) // Output/Pull Configuration bit 2 mask
#define PORT_OPC2_bp 5 // Output/Pull Configuration bit 2 position
#define PORT_ISC_gm 0x07 // Input/Sense Configuration group mask
#define PORT_ISC_bp 0 // Input/Sense Configuration group position

#define PORT_ISC0_bm (1<<0) // Input/Sense Configuration bit 0 mask
#define PORT_ISC0_bp 0 // Input/Sense Configuration bit 0 position
#define PORT_ISC1_bm (1<<1) // Input/Sense Configuration bit 1 mask
#define PORT_ISC1_bp 1 // Input/Sense Configuration bit 1 position
#define PORT_ISC2_bm (1<<2) // Input/Sense Configuration bit 2 mask
#define PORT_ISC2_bp 2 // Input/Sense Configuration bit 2 position

/* PORT.PIN1CTRL bit masks and bit positions */

        
/* Masks for SRLEN aready defined */
            
/* Masks for INVEN aready defined */
            
/* Masks for OPC aready defined */
            
/* Masks for ISC aready defined */
            

/* PORT.PIN2CTRL bit masks and bit positions */

        
/* Masks for SRLEN aready defined */
            
/* Masks for INVEN aready defined */
            
/* Masks for OPC aready defined */
            
/* Masks for ISC aready defined */
            

/* PORT.PIN3CTRL bit masks and bit positions */

        
/* Masks for SRLEN aready defined */
            
/* Masks for INVEN aready defined */
            
/* Masks for OPC aready defined */
            
/* Masks for ISC aready defined */
            

/* PORT.PIN4CTRL bit masks and bit positions */

        
/* Masks for SRLEN aready defined */
            
/* Masks for INVEN aready defined */
            
/* Masks for OPC aready defined */
            
/* Masks for ISC aready defined */
            

/* PORT.PIN5CTRL bit masks and bit positions */

        
/* Masks for SRLEN aready defined */
            
/* Masks for INVEN aready defined */
            
/* Masks for OPC aready defined */
            
/* Masks for ISC aready defined */
            

/* PORT.PIN6CTRL bit masks and bit positions */

        
/* Masks for SRLEN aready defined */
            
/* Masks for INVEN aready defined */
            
/* Masks for OPC aready defined */
            
/* Masks for ISC aready defined */
            

/* PORT.PIN7CTRL bit masks and bit positions */

        
/* Masks for SRLEN aready defined */
            
/* Masks for INVEN aready defined */
            
/* Masks for OPC aready defined */
            
/* Masks for ISC aready defined */
            

#if !defined (__ASSEMBLER__)
/* Virtual Port 0 Mapping */
typedef enum PORTCFG_VP0MAP_enum
{
  PORTCFG_VP0MAP_PORTA_gc = (0x00<<0),   /* Mapped To PORTA */
  PORTCFG_VP0MAP_PORTB_gc = (0x01<<0),   /* Mapped To PORTB */
  PORTCFG_VP0MAP_PORTC_gc = (0x02<<0),   /* Mapped To PORTC */
  PORTCFG_VP0MAP_PORTD_gc = (0x03<<0),   /* Mapped To PORTD */
  PORTCFG_VP0MAP_PORTE_gc = (0x04<<0),   /* Mapped To PORTE */
  PORTCFG_VP0MAP_PORTF_gc = (0x05<<0),   /* Mapped To PORTF */
  PORTCFG_VP0MAP_PORTG_gc = (0x06<<0),   /* Mapped To PORTG */
  PORTCFG_VP0MAP_PORTH_gc = (0x07<<0),   /* Mapped To PORTH */
  PORTCFG_VP0MAP_PORTJ_gc = (0x08<<0),   /* Mapped To PORTJ */
  PORTCFG_VP0MAP_PORTK_gc = (0x09<<0),   /* Mapped To PORTK */
  PORTCFG_VP0MAP_PORTL_gc = (0x0A<<0),   /* Mapped To PORTL */
  PORTCFG_VP0MAP_PORTM_gc = (0x0B<<0),   /* Mapped To PORTM */
  PORTCFG_VP0MAP_PORTN_gc = (0x0C<<0),   /* Mapped To PORTN */
  PORTCFG_VP0MAP_PORTP_gc = (0x0D<<0),   /* Mapped To PORTP */
  PORTCFG_VP0MAP_PORTQ_gc = (0x0E<<0),   /* Mapped To PORTQ */
  PORTCFG_VP0MAP_PORTR_gc = (0x0F<<0),   /* Mapped To PORTR */
} PORTCFG_VP0MAP_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/* Virtual Port 1 Mapping */
typedef enum PORTCFG_VP1MAP_enum
{
  PORTCFG_VP1MAP_PORTA_gc = (0x00<<4),   /* Mapped To PORTA */
  PORTCFG_VP1MAP_PORTB_gc = (0x01<<4),   /* Mapped To PORTB */
  PORTCFG_VP1MAP_PORTC_gc = (0x02<<4),   /* Mapped To PORTC */
  PORTCFG_VP1MAP_PORTD_gc = (0x03<<4),   /* Mapped To PORTD */
  PORTCFG_VP1MAP_PORTE_gc = (0x04<<4),   /* Mapped To PORTE */
  PORTCFG_VP1MAP_PORTF_gc = (0x05<<4),   /* Mapped To PORTF */
  PORTCFG_VP1MAP_PORTG_gc = (0x06<<4),   /* Mapped To PORTG */
  PORTCFG_VP1MAP_PORTH_gc = (0x07<<4),   /* Mapped To PORTH */
  PORTCFG_VP1MAP_PORTJ_gc = (0x08<<4),   /* Mapped To PORTJ */
  PORTCFG_VP1MAP_PORTK_gc = (0x09<<4),   /* Mapped To PORTK */
  PORTCFG_VP1MAP_PORTL_gc = (0x0A<<4),   /* Mapped To PORTL */
  PORTCFG_VP1MAP_PORTM_gc = (0x0B<<4),   /* Mapped To PORTM */
  PORTCFG_VP1MAP_PORTN_gc = (0x0C<<4),   /* Mapped To PORTN */
  PORTCFG_VP1MAP_PORTP_gc = (0x0D<<4),   /* Mapped To PORTP */
  PORTCFG_VP1MAP_PORTQ_gc = (0x0E<<4),   /* Mapped To PORTQ */
  PORTCFG_VP1MAP_PORTR_gc = (0x0F<<4),   /* Mapped To PORTR */
} PORTCFG_VP1MAP_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/* Virtual Port 2 Mapping */
typedef enum PORTCFG_VP2MAP_enum
{
  PORTCFG_VP2MAP_PORTA_gc = (0x00<<0),   /* Mapped To PORTA */
  PORTCFG_VP2MAP_PORTB_gc = (0x01<<0),   /* Mapped To PORTB */
  PORTCFG_VP2MAP_PORTC_gc = (0x02<<0),   /* Mapped To PORTC */
  PORTCFG_VP2MAP_PORTD_gc = (0x03<<0),   /* Mapped To PORTD */
  PORTCFG_VP2MAP_PORTE_gc = (0x04<<0),   /* Mapped To PORTE */
  PORTCFG_VP2MAP_PORTF_gc = (0x05<<0),   /* Mapped To PORTF */
  PORTCFG_VP2MAP_PORTG_gc = (0x06<<0),   /* Mapped To PORTG */
  PORTCFG_VP2MAP_PORTH_gc = (0x07<<0),   /* Mapped To PORTH */
  PORTCFG_VP2MAP_PORTJ_gc = (0x08<<0),   /* Mapped To PORTJ */
  PORTCFG_VP2MAP_PORTK_gc = (0x09<<0),   /* Mapped To PORTK */
  PORTCFG_VP2MAP_PORTL_gc = (0x0A<<0),   /* Mapped To PORTL */
  PORTCFG_VP2MAP_PORTM_gc = (0x0B<<0),   /* Mapped To PORTM */
  PORTCFG_VP2MAP_PORTN_gc = (0x0C<<0),   /* Mapped To PORTN */
  PORTCFG_VP2MAP_PORTP_gc = (0x0D<<0),   /* Mapped To PORTP */
  PORTCFG_VP2MAP_PORTQ_gc = (0x0E<<0),   /* Mapped To PORTQ */
  PORTCFG_VP2MAP_PORTR_gc = (0x0F<<0),   /* Mapped To PORTR */
} PORTCFG_VP2MAP_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/* Virtual Port 3 Mapping */
typedef enum PORTCFG_VP3MAP_enum
{
  PORTCFG_VP3MAP_PORTA_gc = (0x00<<4),   /* Mapped To PORTA */
  PORTCFG_VP3MAP_PORTB_gc = (0x01<<4),   /* Mapped To PORTB */
  PORTCFG_VP3MAP_PORTC_gc = (0x02<<4),   /* Mapped To PORTC */
  PORTCFG_VP3MAP_PORTD_gc = (0x03<<4),   /* Mapped To PORTD */
  PORTCFG_VP3MAP_PORTE_gc = (0x04<<4),   /* Mapped To PORTE */
  PORTCFG_VP3MAP_PORTF_gc = (0x05<<4),   /* Mapped To PORTF */
  PORTCFG_VP3MAP_PORTG_gc = (0x06<<4),   /* Mapped To PORTG */
  PORTCFG_VP3MAP_PORTH_gc = (0x07<<4),   /* Mapped To PORTH */
  PORTCFG_VP3MAP_PORTJ_gc = (0x08<<4),   /* Mapped To PORTJ */
  PORTCFG_VP3MAP_PORTK_gc = (0x09<<4),   /* Mapped To PORTK */
  PORTCFG_VP3MAP_PORTL_gc = (0x0A<<4),   /* Mapped To PORTL */
  PORTCFG_VP3MAP_PORTM_gc = (0x0B<<4),   /* Mapped To PORTM */
  PORTCFG_VP3MAP_PORTN_gc = (0x0C<<4),   /* Mapped To PORTN */
  PORTCFG_VP3MAP_PORTP_gc = (0x0D<<4),   /* Mapped To PORTP */
  PORTCFG_VP3MAP_PORTQ_gc = (0x0E<<4),   /* Mapped To PORTQ */
  PORTCFG_VP3MAP_PORTR_gc = (0x0F<<4),   /* Mapped To PORTR */
} PORTCFG_VP3MAP_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/* Clock Output Port */
typedef enum PORTCFG_CLKOUT_enum
{
  PORTCFG_CLKOUT_OFF_gc = (0x00<<4),   /* Clock Output Disabled */
  PORTCFG_CLKOUT_PC7_gc = (0x01<<4),   /* Clock Output on Port C pin 7 */
  PORTCFG_CLKOUT_PD7_gc = (0x02<<4),   /* Clock Output on Port D pin 7 */
  PORTCFG_CLKOUT_PE7_gc = (0x03<<4),   /* Clock Output on Port E pin 7 */
} PORTCFG_CLKOUT_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/* Event Output Port */
typedef enum PORTCFG_EVOUT_enum
{
  PORTCFG_EVOUT_OFF_gc = (0x00<<0),   /* Event Output Disabled */
  PORTCFG_EVOUT_PC7_gc = (0x01<<0),   /* Event Channel 7 Output on Port C pin 7 */
  PORTCFG_EVOUT_PD7_gc = (0x02<<0),   /* Event Channel 7 Output on Port D pin 7 */
  PORTCFG_EVOUT_PE7_gc = (0x03<<0),   /* Event Channel 7 Output on Port E pin 7 */
} PORTCFG_EVOUT_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/* Port Interrupt 0 Level */
typedef enum PORT_INT0LVL_enum
{
  PORT_INT0LVL_OFF_gc = (0x00<<0),   /* Interrupt Disabled */
  PORT_INT0LVL_LO_gc = (0x01<<0),   /* Low Level */
  PORT_INT0LVL_MED_gc = (0x02<<0),   /* Medium Level */
  PORT_INT0LVL_HI_gc = (0x03<<0),   /* High Level */
} PORT_INT0LVL_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/* Port Interrupt 1 Level */
typedef enum PORT_INT1LVL_enum
{
  PORT_INT1LVL_OFF_gc = (0x00<<2),   /* Interrupt Disabled */
  PORT_INT1LVL_LO_gc = (0x01<<2),   /* Low Level */
  PORT_INT1LVL_MED_gc = (0x02<<2),   /* Medium Level */
  PORT_INT1LVL_HI_gc = (0x03<<2),   /* High Level */
} PORT_INT1LVL_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/* Output/Pull Configuration */
typedef enum PORT_OPC_enum
{
  PORT_OPC_TOTEM_gc = (0x00<<3),   /* Totempole */
  PORT_OPC_BUSKEEPER_gc = (0x01<<3),   /* Totempole w/ Bus keeper on Input and Output */
  PORT_OPC_PULLDOWN_gc = (0x02<<3),   /* Totempole w/ Pull-down on Input */
  PORT_OPC_PULLUP_gc = (0x03<<3),   /* Totempole w/ Pull-up on Input */
  PORT_OPC_WIREDOR_gc = (0x04<<3),   /* Wired OR */
  PORT_OPC_WIREDAND_gc = (0x05<<3),   /* Wired AND */
  PORT_OPC_WIREDORPULL_gc = (0x06<<3),   /* Wired OR w/ Pull-down */
  PORT_OPC_WIREDANDPULL_gc = (0x07<<3),   /* Wired AND w/ Pull-up */
} PORT_OPC_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/* Input/Sense Configuration */
typedef enum PORT_ISC_enum
{
  PORT_ISC_BOTHEDGES_gc = (0x00<<0),   /* Sense Both Edges */
  PORT_ISC_RISING_gc = (0x01<<0),   /* Sense Rising Edge */
  PORT_ISC_FALLING_gc = (0x02<<0),   /* Sense Falling Edge */
  PORT_ISC_LEVEL_gc = (0x03<<0),   /* Sense Level (Transparent For Events) */
  PORT_ISC_INPUT_DISABLE_gc = (0x07<<0),   /* Disable Digital Input Buffer */
} PORT_ISC_t;
#endif /* !defined (__ASSEMBLER__) */


/*
--------------------------------------------------------------------------
 TC - 16-bit Timer/Counter With PWM
--------------------------------------------------------------------------
*/

/* TC0.CTRLA bit masks and bit positions */

        
#define TC0_CLKSEL_gm 0x0F // Clock Selection group mask
#define TC0_CLKSEL_bp 0 // Clock Selection group position

#define TC0_CLKSEL0_bm (1<<0) // Clock Selection bit 0 mask
#define TC0_CLKSEL0_bp 0 // Clock Selection bit 0 position
#define TC0_CLKSEL1_bm (1<<1) // Clock Selection bit 1 mask
#define TC0_CLKSEL1_bp 1 // Clock Selection bit 1 position
#define TC0_CLKSEL2_bm (1<<2) // Clock Selection bit 2 mask
#define TC0_CLKSEL2_bp 2 // Clock Selection bit 2 position
#define TC0_CLKSEL3_bm (1<<3) // Clock Selection bit 3 mask
#define TC0_CLKSEL3_bp 3 // Clock Selection bit 3 position

/* TC0.CTRLB bit masks and bit positions */

        
#define TC0_CCDEN_bm 0x80 // Compare or Capture D Enable bit mask
#define TC0_CCDEN_bp 7 // Compare or Capture D Enable bit position
#define TC0_CCCEN_bm 0x40 // Compare or Capture C Enable bit mask
#define TC0_CCCEN_bp 6 // Compare or Capture C Enable bit position
#define TC0_CCBEN_bm 0x20 // Compare or Capture B Enable bit mask
#define TC0_CCBEN_bp 5 // Compare or Capture B Enable bit position
#define TC0_CCAEN_bm 0x10 // Compare or Capture A Enable bit mask
#define TC0_CCAEN_bp 4 // Compare or Capture A Enable bit position
#define TC0_WGMODE_gm 0x07 // Waveform generation mode group mask
#define TC0_WGMODE_bp 0 // Waveform generation mode group position

#define TC0_WGMODE0_bm (1<<0) // Waveform generation mode bit 0 mask
#define TC0_WGMODE0_bp 0 // Waveform generation mode bit 0 position
#define TC0_WGMODE1_bm (1<<1) // Waveform generation mode bit 1 mask
#define TC0_WGMODE1_bp 1 // Waveform generation mode bit 1 position
#define TC0_WGMODE2_bm (1<<2) // Waveform generation mode bit 2 mask
#define TC0_WGMODE2_bp 2 // Waveform generation mode bit 2 position

/* TC0.CTRLC bit masks and bit positions */

        
#define TC0_CMPD_bm 0x08 // Compare D Output Value bit mask
#define TC0_CMPD_bp 3 // Compare D Output Value bit position
#define TC0_CMPC_bm 0x04 // Compare C Output Value bit mask
#define TC0_CMPC_bp 2 // Compare C Output Value bit position
#define TC0_CMPB_bm 0x02 // Compare B Output Value bit mask
#define TC0_CMPB_bp 1 // Compare B Output Value bit position
#define TC0_CMPA_bm 0x01 // Compare A Output Value bit mask
#define TC0_CMPA_bp 0 // Compare A Output Value bit position

/* TC0.CTRLD bit masks and bit positions */

        
#define TC0_EVACT_gm 0xE0 // Event Action group mask
#define TC0_EVACT_bp 5 // Event Action group position

#define TC0_EVACT0_bm (1<<5) // Event Action bit 0 mask
#define TC0_EVACT0_bp 5 // Event Action bit 0 position
#define TC0_EVACT1_bm (1<<6) // Event Action bit 1 mask
#define TC0_EVACT1_bp 6 // Event Action bit 1 position
#define TC0_EVACT2_bm (1<<7) // Event Action bit 2 mask
#define TC0_EVACT2_bp 7 // Event Action bit 2 position
#define TC0_EVDLY_bm 0x10 // Event Delay bit mask
#define TC0_EVDLY_bp 4 // Event Delay bit position
#define TC0_EVSEL_gm 0x0F // Event Source Select group mask
#define TC0_EVSEL_bp 0 // Event Source Select group position

#define TC0_EVSEL0_bm (1<<0) // Event Source Select bit 0 mask
#define TC0_EVSEL0_bp 0 // Event Source Select bit 0 position
#define TC0_EVSEL1_bm (1<<1) // Event Source Select bit 1 mask
#define TC0_EVSEL1_bp 1 // Event Source Select bit 1 position
#define TC0_EVSEL2_bm (1<<2) // Event Source Select bit 2 mask
#define TC0_EVSEL2_bp 2 // Event Source Select bit 2 position
#define TC0_EVSEL3_bm (1<<3) // Event Source Select bit 3 mask
#define TC0_EVSEL3_bp 3 // Event Source Select bit 3 position

/* TC0.CTRLE bit masks and bit positions */

        
#define TC0_DTHM_bm 0x02 // Dead Time Hold Mode bit mask
#define TC0_DTHM_bp 1 // Dead Time Hold Mode bit position
#define TC0_BYTEM_bm 0x01 // Byte Mode bit mask
#define TC0_BYTEM_bp 0 // Byte Mode bit position

/* TC0.INTCTRLA bit masks and bit positions */

        
#define TC0_ERRINTLVL_gm 0x0C // Error Interrupt Level group mask
#define TC0_ERRINTLVL_bp 2 // Error Interrupt Level group position

#define TC0_ERRINTLVL0_bm (1<<2) // Error Interrupt Level bit 0 mask
#define TC0_ERRINTLVL0_bp 2 // Error Interrupt Level bit 0 position
#define TC0_ERRINTLVL1_bm (1<<3) // Error Interrupt Level bit 1 mask
#define TC0_ERRINTLVL1_bp 3 // Error Interrupt Level bit 1 position
#define TC0_OVFINTLVL_gm 0x03 // Overflow interrupt level group mask
#define TC0_OVFINTLVL_bp 0 // Overflow interrupt level group position

#define TC0_OVFINTLVL0_bm (1<<0) // Overflow interrupt level bit 0 mask
#define TC0_OVFINTLVL0_bp 0 // Overflow interrupt level bit 0 position
#define TC0_OVFINTLVL1_bm (1<<1) // Overflow interrupt level bit 1 mask
#define TC0_OVFINTLVL1_bp 1 // Overflow interrupt level bit 1 position

/* TC0.INTCTRLB bit masks and bit positions */

        
#define TC0_CCDINTLVL_gm 0xC0 // Compare or Capture D Interrupt Level group mask
#define TC0_CCDINTLVL_bp 6 // Compare or Capture D Interrupt Level group position

#define TC0_CCDINTLVL0_bm (1<<6) // Compare or Capture D Interrupt Level bit 0 mask
#define TC0_CCDINTLVL0_bp 6 // Compare or Capture D Interrupt Level bit 0 position
#define TC0_CCDINTLVL1_bm (1<<7) // Compare or Capture D Interrupt Level bit 1 mask
#define TC0_CCDINTLVL1_bp 7 // Compare or Capture D Interrupt Level bit 1 position
#define TC0_CCCINTLVL_gm 0x30 // Compare or Capture C Interrupt Level group mask
#define TC0_CCCINTLVL_bp 4 // Compare or Capture C Interrupt Level group position

#define TC0_CCCINTLVL0_bm (1<<4) // Compare or Capture C Interrupt Level bit 0 mask
#define TC0_CCCINTLVL0_bp 4 // Compare or Capture C Interrupt Level bit 0 position
#define TC0_CCCINTLVL1_bm (1<<5) // Compare or Capture C Interrupt Level bit 1 mask
#define TC0_CCCINTLVL1_bp 5 // Compare or Capture C Interrupt Level bit 1 position
#define TC0_CCBINTLVL_gm 0x0C // Compare or Capture B Interrupt Level group mask
#define TC0_CCBINTLVL_bp 2 // Compare or Capture B Interrupt Level group position

#define TC0_CCBINTLVL0_bm (1<<2) // Compare or Capture B Interrupt Level bit 0 mask
#define TC0_CCBINTLVL0_bp 2 // Compare or Capture B Interrupt Level bit 0 position
#define TC0_CCBINTLVL1_bm (1<<3) // Compare or Capture B Interrupt Level bit 1 mask
#define TC0_CCBINTLVL1_bp 3 // Compare or Capture B Interrupt Level bit 1 position
#define TC0_CCAINTLVL_gm 0x03 // Compare or Capture A Interrupt Level group mask
#define TC0_CCAINTLVL_bp 0 // Compare or Capture A Interrupt Level group position

#define TC0_CCAINTLVL0_bm (1<<0) // Compare or Capture A Interrupt Level bit 0 mask
#define TC0_CCAINTLVL0_bp 0 // Compare or Capture A Interrupt Level bit 0 position
#define TC0_CCAINTLVL1_bm (1<<1) // Compare or Capture A Interrupt Level bit 1 mask
#define TC0_CCAINTLVL1_bp 1 // Compare or Capture A Interrupt Level bit 1 position

/* TC0.CTRLFCLR bit masks and bit positions */

        
#define TC0_CMD_gm 0x0C // Command group mask
#define TC0_CMD_bp 2 // Command group position

#define TC0_CMD0_bm (1<<2) // Command bit 0 mask
#define TC0_CMD0_bp 2 // Command bit 0 position
#define TC0_CMD1_bm (1<<3) // Command bit 1 mask
#define TC0_CMD1_bp 3 // Command bit 1 position
#define TC0_LUPD_bm 0x02 // Lock Update bit mask
#define TC0_LUPD_bp 1 // Lock Update bit position
#define TC0_DIR_bm 0x01 // Direction bit mask
#define TC0_DIR_bp 0 // Direction bit position

/* TC0.CTRLFSET bit masks and bit positions */

        
/* Masks for CMD aready defined */
            
/* Masks for LUPD aready defined */
            
/* Masks for DIR aready defined */
            

/* TC0.CTRLGCLR bit masks and bit positions */

        
#define TC0_CCDBV_bm 0x10 // Compare or Capture D Buffer Valid bit mask
#define TC0_CCDBV_bp 4 // Compare or Capture D Buffer Valid bit position
#define TC0_CCCBV_bm 0x08 // Compare or Capture C Buffer Valid bit mask
#define TC0_CCCBV_bp 3 // Compare or Capture C Buffer Valid bit position
#define TC0_CCBBV_bm 0x04 // Compare or Capture B Buffer Valid bit mask
#define TC0_CCBBV_bp 2 // Compare or Capture B Buffer Valid bit position
#define TC0_CCABV_bm 0x02 // Compare or Capture A Buffer Valid bit mask
#define TC0_CCABV_bp 1 // Compare or Capture A Buffer Valid bit position
#define TC0_PERBV_bm 0x01 // Period Buffer Valid bit mask
#define TC0_PERBV_bp 0 // Period Buffer Valid bit position

/* TC0.CTRLGSET bit masks and bit positions */

        
/* Masks for CCDBV aready defined */
            
/* Masks for CCCBV aready defined */
            
/* Masks for CCBBV aready defined */
            
/* Masks for CCABV aready defined */
            
/* Masks for PERBV aready defined */
            

/* TC0.INTFLAGS bit masks and bit positions */

        
#define TC0_CCDIF_bm 0x80 // Compare or Capture D Interrupt Flag bit mask
#define TC0_CCDIF_bp 7 // Compare or Capture D Interrupt Flag bit position
#define TC0_CCCIF_bm 0x40 // Compare or Capture C Interrupt Flag bit mask
#define TC0_CCCIF_bp 6 // Compare or Capture C Interrupt Flag bit position
#define TC0_CCBIF_bm 0x20 // Compare or Capture B Interrupt Flag bit mask
#define TC0_CCBIF_bp 5 // Compare or Capture B Interrupt Flag bit position
#define TC0_CCAIF_bm 0x10 // Compare or Capture A Interrupt Flag bit mask
#define TC0_CCAIF_bp 4 // Compare or Capture A Interrupt Flag bit position
#define TC0_ERRIF_bm 0x02 // Error Interrupt Flag bit mask
#define TC0_ERRIF_bp 1 // Error Interrupt Flag bit position
#define TC0_OVFIF_bm 0x01 // Overflow Interrupt Flag bit mask
#define TC0_OVFIF_bp 0 // Overflow Interrupt Flag bit position

/* TC1.CTRLA bit masks and bit positions */

        
#define TC1_CLKSEL_gm 0x0F // Clock Selection group mask
#define TC1_CLKSEL_bp 0 // Clock Selection group position

#define TC1_CLKSEL0_bm (1<<0) // Clock Selection bit 0 mask
#define TC1_CLKSEL0_bp 0 // Clock Selection bit 0 position
#define TC1_CLKSEL1_bm (1<<1) // Clock Selection bit 1 mask
#define TC1_CLKSEL1_bp 1 // Clock Selection bit 1 position
#define TC1_CLKSEL2_bm (1<<2) // Clock Selection bit 2 mask
#define TC1_CLKSEL2_bp 2 // Clock Selection bit 2 position
#define TC1_CLKSEL3_bm (1<<3) // Clock Selection bit 3 mask
#define TC1_CLKSEL3_bp 3 // Clock Selection bit 3 position

/* TC1.CTRLB bit masks and bit positions */

        
#define TC1_CCBEN_bm 0x20 // Compare or Capture B Enable bit mask
#define TC1_CCBEN_bp 5 // Compare or Capture B Enable bit position
#define TC1_CCAEN_bm 0x10 // Compare or Capture A Enable bit mask
#define TC1_CCAEN_bp 4 // Compare or Capture A Enable bit position
#define TC1_WGMODE_gm 0x07 // Waveform generation mode group mask
#define TC1_WGMODE_bp 0 // Waveform generation mode group position

#define TC1_WGMODE0_bm (1<<0) // Waveform generation mode bit 0 mask
#define TC1_WGMODE0_bp 0 // Waveform generation mode bit 0 position
#define TC1_WGMODE1_bm (1<<1) // Waveform generation mode bit 1 mask
#define TC1_WGMODE1_bp 1 // Waveform generation mode bit 1 position
#define TC1_WGMODE2_bm (1<<2) // Waveform generation mode bit 2 mask
#define TC1_WGMODE2_bp 2 // Waveform generation mode bit 2 position

/* TC1.CTRLC bit masks and bit positions */

        
#define TC1_CMPB_bm 0x02 // Compare B Output Value bit mask
#define TC1_CMPB_bp 1 // Compare B Output Value bit position
#define TC1_CMPA_bm 0x01 // Compare A Output Value bit mask
#define TC1_CMPA_bp 0 // Compare A Output Value bit position

/* TC1.CTRLD bit masks and bit positions */

        
#define TC1_EVACT_gm 0xE0 // Event Action group mask
#define TC1_EVACT_bp 5 // Event Action group position

#define TC1_EVACT0_bm (1<<5) // Event Action bit 0 mask
#define TC1_EVACT0_bp 5 // Event Action bit 0 position
#define TC1_EVACT1_bm (1<<6) // Event Action bit 1 mask
#define TC1_EVACT1_bp 6 // Event Action bit 1 position
#define TC1_EVACT2_bm (1<<7) // Event Action bit 2 mask
#define TC1_EVACT2_bp 7 // Event Action bit 2 position
#define TC1_EVDLY_bm 0x10 // Event Delay bit mask
#define TC1_EVDLY_bp 4 // Event Delay bit position
#define TC1_EVSEL_gm 0x0F // Event Source Select group mask
#define TC1_EVSEL_bp 0 // Event Source Select group position

#define TC1_EVSEL0_bm (1<<0) // Event Source Select bit 0 mask
#define TC1_EVSEL0_bp 0 // Event Source Select bit 0 position
#define TC1_EVSEL1_bm (1<<1) // Event Source Select bit 1 mask
#define TC1_EVSEL1_bp 1 // Event Source Select bit 1 position
#define TC1_EVSEL2_bm (1<<2) // Event Source Select bit 2 mask
#define TC1_EVSEL2_bp 2 // Event Source Select bit 2 position
#define TC1_EVSEL3_bm (1<<3) // Event Source Select bit 3 mask
#define TC1_EVSEL3_bp 3 // Event Source Select bit 3 position

/* TC1.CTRLE bit masks and bit positions */

        
#define TC1_DTHM_bm 0x02 // Dead Time Hold Mode bit mask
#define TC1_DTHM_bp 1 // Dead Time Hold Mode bit position
#define TC1_BYTEM_bm 0x01 // Byte Mode bit mask
#define TC1_BYTEM_bp 0 // Byte Mode bit position

/* TC1.INTCTRLA bit masks and bit positions */

        
#define TC1_ERRINTLVL_gm 0x0C // Error Interrupt Level group mask
#define TC1_ERRINTLVL_bp 2 // Error Interrupt Level group position

#define TC1_ERRINTLVL0_bm (1<<2) // Error Interrupt Level bit 0 mask
#define TC1_ERRINTLVL0_bp 2 // Error Interrupt Level bit 0 position
#define TC1_ERRINTLVL1_bm (1<<3) // Error Interrupt Level bit 1 mask
#define TC1_ERRINTLVL1_bp 3 // Error Interrupt Level bit 1 position
#define TC1_OVFINTLVL_gm 0x03 // Overflow interrupt level group mask
#define TC1_OVFINTLVL_bp 0 // Overflow interrupt level group position

#define TC1_OVFINTLVL0_bm (1<<0) // Overflow interrupt level bit 0 mask
#define TC1_OVFINTLVL0_bp 0 // Overflow interrupt level bit 0 position
#define TC1_OVFINTLVL1_bm (1<<1) // Overflow interrupt level bit 1 mask
#define TC1_OVFINTLVL1_bp 1 // Overflow interrupt level bit 1 position

/* TC1.INTCTRLB bit masks and bit positions */

        
#define TC1_CCBINTLVL_gm 0x0C // Compare or Capture B Interrupt Level group mask
#define TC1_CCBINTLVL_bp 2 // Compare or Capture B Interrupt Level group position

#define TC1_CCBINTLVL0_bm (1<<2) // Compare or Capture B Interrupt Level bit 0 mask
#define TC1_CCBINTLVL0_bp 2 // Compare or Capture B Interrupt Level bit 0 position
#define TC1_CCBINTLVL1_bm (1<<3) // Compare or Capture B Interrupt Level bit 1 mask
#define TC1_CCBINTLVL1_bp 3 // Compare or Capture B Interrupt Level bit 1 position
#define TC1_CCAINTLVL_gm 0x03 // Compare or Capture A Interrupt Level group mask
#define TC1_CCAINTLVL_bp 0 // Compare or Capture A Interrupt Level group position

#define TC1_CCAINTLVL0_bm (1<<0) // Compare or Capture A Interrupt Level bit 0 mask
#define TC1_CCAINTLVL0_bp 0 // Compare or Capture A Interrupt Level bit 0 position
#define TC1_CCAINTLVL1_bm (1<<1) // Compare or Capture A Interrupt Level bit 1 mask
#define TC1_CCAINTLVL1_bp 1 // Compare or Capture A Interrupt Level bit 1 position

/* TC1.CTRLFCLR bit masks and bit positions */

        
#define TC1_CMD_gm 0x0C // Command group mask
#define TC1_CMD_bp 2 // Command group position

#define TC1_CMD0_bm (1<<2) // Command bit 0 mask
#define TC1_CMD0_bp 2 // Command bit 0 position
#define TC1_CMD1_bm (1<<3) // Command bit 1 mask
#define TC1_CMD1_bp 3 // Command bit 1 position
#define TC1_LUPD_bm 0x02 // Lock Update bit mask
#define TC1_LUPD_bp 1 // Lock Update bit position
#define TC1_DIR_bm 0x01 // Direction bit mask
#define TC1_DIR_bp 0 // Direction bit position

/* TC1.CTRLFSET bit masks and bit positions */

        
/* Masks for CMD aready defined */
            
/* Masks for LUPD aready defined */
            
/* Masks for DIR aready defined */
            

/* TC1.CTRLGCLR bit masks and bit positions */

        
#define TC1_CCBBV_bm 0x04 // Compare or Capture B Buffer Valid bit mask
#define TC1_CCBBV_bp 2 // Compare or Capture B Buffer Valid bit position
#define TC1_CCABV_bm 0x02 // Compare or Capture A Buffer Valid bit mask
#define TC1_CCABV_bp 1 // Compare or Capture A Buffer Valid bit position
#define TC1_PERBV_bm 0x01 // Period Buffer Valid bit mask
#define TC1_PERBV_bp 0 // Period Buffer Valid bit position

/* TC1.CTRLGSET bit masks and bit positions */

        
/* Masks for CCBBV aready defined */
            
/* Masks for CCABV aready defined */
            
/* Masks for PERBV aready defined */
            

/* TC1.INTFLAGS bit masks and bit positions */

        
#define TC1_CCBIF_bm 0x20 // Compare or Capture B Interrupt Flag bit mask
#define TC1_CCBIF_bp 5 // Compare or Capture B Interrupt Flag bit position
#define TC1_CCAIF_bm 0x10 // Compare or Capture A Interrupt Flag bit mask
#define TC1_CCAIF_bp 4 // Compare or Capture A Interrupt Flag bit position
#define TC1_ERRIF_bm 0x02 // Error Interrupt Flag bit mask
#define TC1_ERRIF_bp 1 // Error Interrupt Flag bit position
#define TC1_OVFIF_bm 0x01 // Overflow Interrupt Flag bit mask
#define TC1_OVFIF_bp 0 // Overflow Interrupt Flag bit position

/* AWEX.CTRL bit masks and bit positions */

        
#define AWEX_PGM_bm 0x20 // Pattern Generation Mode bit mask
#define AWEX_PGM_bp 5 // Pattern Generation Mode bit position
#define AWEX_CWCM_bm 0x10 // Common Waveform Channel Mode bit mask
#define AWEX_CWCM_bp 4 // Common Waveform Channel Mode bit position
#define AWEX_DTICCDEN_bm 0x08 // Dead Time Insertion Compare Channel D Enable bit mask
#define AWEX_DTICCDEN_bp 3 // Dead Time Insertion Compare Channel D Enable bit position
#define AWEX_DTICCCEN_bm 0x04 // Dead Time Insertion Compare Channel C Enable bit mask
#define AWEX_DTICCCEN_bp 2 // Dead Time Insertion Compare Channel C Enable bit position
#define AWEX_DTICCBEN_bm 0x02 // Dead Time Insertion Compare Channel B Enable bit mask
#define AWEX_DTICCBEN_bp 1 // Dead Time Insertion Compare Channel B Enable bit position
#define AWEX_DTICCAEN_bm 0x01 // Dead Time Insertion Compare Channel A Enable bit mask
#define AWEX_DTICCAEN_bp 0 // Dead Time Insertion Compare Channel A Enable bit position

/* AWEX.DFCTRL bit masks and bit positions */

        
#define AWEX_FDDBD_bm 0x10 // Fault Detect on Disable Break Disable bit mask
#define AWEX_FDDBD_bp 4 // Fault Detect on Disable Break Disable bit position
#define AWEX_FDMODE_bm 0x04 // Fault Detect Mode bit mask
#define AWEX_FDMODE_bp 2 // Fault Detect Mode bit position
#define AWEX_FDACT_gm 0x03 // Fault Detect Action group mask
#define AWEX_FDACT_bp 0 // Fault Detect Action group position

#define AWEX_FDACT0_bm (1<<0) // Fault Detect Action bit 0 mask
#define AWEX_FDACT0_bp 0 // Fault Detect Action bit 0 position
#define AWEX_FDACT1_bm (1<<1) // Fault Detect Action bit 1 mask
#define AWEX_FDACT1_bp 1 // Fault Detect Action bit 1 position

/* AWEX.STATUS bit masks and bit positions */

        
#define AWEX_FDF_bm 0x04 // Fault Detect Flag bit mask
#define AWEX_FDF_bp 2 // Fault Detect Flag bit position
#define AWEX_DTHSBUFV_bm 0x02 // Dead Time High Side Buffer Valid bit mask
#define AWEX_DTHSBUFV_bp 1 // Dead Time High Side Buffer Valid bit position
#define AWEX_DTLSBUFV_bm 0x01 // Dead Time Low Side Buffer Valid bit mask
#define AWEX_DTLSBUFV_bp 0 // Dead Time Low Side Buffer Valid bit position

/* HIRES.CTRL bit masks and bit positions */

        
#define HIRES_HREN_gm 0x03 // High Resolution Enable group mask
#define HIRES_HREN_bp 0 // High Resolution Enable group position

#define HIRES_HREN0_bm (1<<0) // High Resolution Enable bit 0 mask
#define HIRES_HREN0_bp 0 // High Resolution Enable bit 0 position
#define HIRES_HREN1_bm (1<<1) // High Resolution Enable bit 1 mask
#define HIRES_HREN1_bp 1 // High Resolution Enable bit 1 position

#if !defined (__ASSEMBLER__)
/* Clock Selection */
typedef enum TC_CLKSEL_enum
{
  TC_CLKSEL_OFF_gc = (0x00<<0),   /* Timer Off */
  TC_CLKSEL_DIV1_gc = (0x01<<0),   /* System Clock */
  TC_CLKSEL_DIV2_gc = (0x02<<0),   /* System Clock / 2 */
  TC_CLKSEL_DIV4_gc = (0x03<<0),   /* System Clock / 4 */
  TC_CLKSEL_DIV8_gc = (0x04<<0),   /* System Clock / 8 */
  TC_CLKSEL_DIV64_gc = (0x05<<0),   /* System Clock / 64 */
  TC_CLKSEL_DIV256_gc = (0x06<<0),   /* System Clock / 256 */
  TC_CLKSEL_DIV1024_gc = (0x07<<0),   /* System Clock / 1024 */
  TC_CLKSEL_EVCH0_gc = (0x08<<0),   /* Event Channel 0 */
  TC_CLKSEL_EVCH1_gc = (0x09<<0),   /* Event Channel 1 */
  TC_CLKSEL_EVCH2_gc = (0x0A<<0),   /* Event Channel 2 */
  TC_CLKSEL_EVCH3_gc = (0x0B<<0),   /* Event Channel 3 */
  TC_CLKSEL_EVCH4_gc = (0x0C<<0),   /* Event Channel 4 */
  TC_CLKSEL_EVCH5_gc = (0x0D<<0),   /* Event Channel 5 */
  TC_CLKSEL_EVCH6_gc = (0x0E<<0),   /* Event Channel 6 */
  TC_CLKSEL_EVCH7_gc = (0x0F<<0),   /* Event Channel 7 */
} TC_CLKSEL_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/* Waveform Generation Mode */
typedef enum TC_WGMODE_enum
{
  TC_WGMODE_NORMAL_gc = (0x00<<0),   /* Normal Mode */
  TC_WGMODE_FRQ_gc = (0x01<<0),   /* Frequency Generation Mode */
  TC_WGMODE_SS_gc = (0x03<<0),   /* Single Slope */
  TC_WGMODE_DS_T_gc = (0x05<<0),   /* Dual Slope, Update on TOP */
  TC_WGMODE_DS_TB_gc = (0x06<<0),   /* Dual Slope, Update on TOP and BOTTOM */
  TC_WGMODE_DS_B_gc = (0x07<<0),   /* Dual Slope, Update on BOTTOM */
} TC_WGMODE_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/* Event Action */
typedef enum TC_EVACT_enum
{
  TC_EVACT_OFF_gc = (0x00<<5),   /* No Event Action */
  TC_EVACT_CAPT_gc = (0x01<<5),   /* Input Capture */
  TC_EVACT_UPDOWN_gc = (0x02<<5),   /* Externally Controlled Up/Down Count */
  TC_EVACT_QDEC_gc = (0x03<<5),   /* Quadrature Decode */
  TC_EVACT_RESTART_gc = (0x04<<5),   /* Restart */
  TC_EVACT_FRW_gc = (0x05<<5),   /* Frequency Capture */
  TC_EVACT_PW_gc = (0x06<<5),   /* Pulse-width Capture */
} TC_EVACT_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/* Event Selection */
typedef enum TC_EVSEL_enum
{
  TC_EVSEL_OFF_gc = (0x00<<0),   /* No Event Source */
  TC_EVSEL_CH0_gc = (0x08<<0),   /* Event Channel 0 */
  TC_EVSEL_CH1_gc = (0x09<<0),   /* Event Channel 1 */
  TC_EVSEL_CH2_gc = (0x0A<<0),   /* Event Channel 2 */
  TC_EVSEL_CH3_gc = (0x0B<<0),   /* Event Channel 3 */
  TC_EVSEL_CH4_gc = (0x0C<<0),   /* Event Channel 4 */
  TC_EVSEL_CH5_gc = (0x0D<<0),   /* Event Channel 5 */
  TC_EVSEL_CH6_gc = (0x0E<<0),   /* Event Channel 6 */
  TC_EVSEL_CH7_gc = (0x0F<<0),   /* Event Channel 7 */
} TC_EVSEL_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/* Error Interrupt Level */
typedef enum TC_ERRINTLVL_enum
{
  TC_ERRINTLVL_OFF_gc = (0x00<<2),   /* Interrupt Disabled */
  TC_ERRINTLVL_LO_gc = (0x01<<2),   /* Low Level */
  TC_ERRINTLVL_MED_gc = (0x02<<2),   /* Medium Level */
  TC_ERRINTLVL_HI_gc = (0x03<<2),   /* High Level */
} TC_ERRINTLVL_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/* Overflow Interrupt Level */
typedef enum TC_OVFINTLVL_enum
{
  TC_OVFINTLVL_OFF_gc = (0x00<<0),   /* Interrupt Disabled */
  TC_OVFINTLVL_LO_gc = (0x01<<0),   /* Low Level */
  TC_OVFINTLVL_MED_gc = (0x02<<0),   /* Medium Level */
  TC_OVFINTLVL_HI_gc = (0x03<<0),   /* High Level */
} TC_OVFINTLVL_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/* Compare or Capture D Interrupt Level */
typedef enum TC_CCDINTLVL_enum
{
  TC_CCDINTLVL_OFF_gc = (0x00<<6),   /* Interrupt Disabled */
  TC_CCDINTLVL_LO_gc = (0x01<<6),   /* Low Level */
  TC_CCDINTLVL_MED_gc = (0x02<<6),   /* Medium Level */
  TC_CCDINTLVL_HI_gc = (0x03<<6),   /* High Level */
} TC_CCDINTLVL_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/* Compare or Capture C Interrupt Level */
typedef enum TC_CCCINTLVL_enum
{
  TC_CCCINTLVL_OFF_gc = (0x00<<4),   /* Interrupt Disabled */
  TC_CCCINTLVL_LO_gc = (0x01<<4),   /* Low Level */
  TC_CCCINTLVL_MED_gc = (0x02<<4),   /* Medium Level */
  TC_CCCINTLVL_HI_gc = (0x03<<4),   /* High Level */
} TC_CCCINTLVL_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/* Compare or Capture B Interrupt Level */
typedef enum TC_CCBINTLVL_enum
{
  TC_CCBINTLVL_OFF_gc = (0x00<<2),   /* Interrupt Disabled */
  TC_CCBINTLVL_LO_gc = (0x01<<2),   /* Low Level */
  TC_CCBINTLVL_MED_gc = (0x02<<2),   /* Medium Level */
  TC_CCBINTLVL_HI_gc = (0x03<<2),   /* High Level */
} TC_CCBINTLVL_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/* Compare or Capture A Interrupt Level */
typedef enum TC_CCAINTLVL_enum
{
  TC_CCAINTLVL_OFF_gc = (0x00<<0),   /* Interrupt Disabled */
  TC_CCAINTLVL_LO_gc = (0x01<<0),   /* Low Level */
  TC_CCAINTLVL_MED_gc = (0x02<<0),   /* Medium Level */
  TC_CCAINTLVL_HI_gc = (0x03<<0),   /* High Level */
} TC_CCAINTLVL_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/* Timer/Counter Command */
typedef enum TC_CMD_enum
{
  TC_CMD_NONE_gc = (0x00<<2),   /* No Command */
  TC_CMD_UPDATE_gc = (0x01<<2),   /* Force Update */
  TC_CMD_RESTART_gc = (0x02<<2),   /* Force Restart */
  TC_CMD_RESET_gc = (0x03<<2),   /* Force Hard Reset */
} TC_CMD_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/* Fault Detect Action */
typedef enum AWEX_FDACT_enum
{
  AWEX_FDACT_NONE_gc = (0x00<<0),   /* No Fault Protection */
  AWEX_FDACT_CLEAROE_gc = (0x01<<0),   /* Clear Output Enable Bits */
  AWEX_FDACT_CLEARDIR_gc = (0x03<<0),   /* Clear I/O Port Direction Bits */
} AWEX_FDACT_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/* High Resolution Enable */
typedef enum HIRES_HREN_enum
{
  HIRES_HREN_NONE_gc = (0x00<<0),   /* No Fault Protection */
  HIRES_HREN_TC0_gc = (0x01<<0),   /* Enable High Resolution on Timer/Counter 0 */
  HIRES_HREN_TC1_gc = (0x02<<0),   /* Enable High Resolution on Timer/Counter 1 */
  HIRES_HREN_BOTH_gc = (0x03<<0),   /* Enable High Resolution both Timer/Counters */
} HIRES_HREN_t;
#endif /* !defined (__ASSEMBLER__) */


/*
--------------------------------------------------------------------------
 USART - Universal Asynchronous Receiver-Transmitter
--------------------------------------------------------------------------
*/

/* USART.STATUS bit masks and bit positions */

        
#define USART_RXCIF_bm 0x80 // Receive Interrupt Flag bit mask
#define USART_RXCIF_bp 7 // Receive Interrupt Flag bit position
#define USART_TXCIF_bm 0x40 // Transmit Interrupt Flag bit mask
#define USART_TXCIF_bp 6 // Transmit Interrupt Flag bit position
#define USART_DREIF_bm 0x20 // Data Register Empty Flag bit mask
#define USART_DREIF_bp 5 // Data Register Empty Flag bit position
#define USART_FERR_bm 0x10 // Frame Error bit mask
#define USART_FERR_bp 4 // Frame Error bit position
#define USART_BUFOVF_bm 0x08 // Buffer Overflow bit mask
#define USART_BUFOVF_bp 3 // Buffer Overflow bit position
#define USART_PERR_bm 0x04 // Parity Error bit mask
#define USART_PERR_bp 2 // Parity Error bit position
#define USART_RXB8_bm 0x01 // Receive Bit 8 bit mask
#define USART_RXB8_bp 0 // Receive Bit 8 bit position

/* USART.CTRLA bit masks and bit positions */

        
#define USART_RXCINTLVL_gm 0x30 // Receive Interrupt Level group mask
#define USART_RXCINTLVL_bp 4 // Receive Interrupt Level group position

#define USART_RXCINTLVL0_bm (1<<4) // Receive Interrupt Level bit 0 mask
#define USART_RXCINTLVL0_bp 4 // Receive Interrupt Level bit 0 position
#define USART_RXCINTLVL1_bm (1<<5) // Receive Interrupt Level bit 1 mask
#define USART_RXCINTLVL1_bp 5 // Receive Interrupt Level bit 1 position
#define USART_TXCINTLVL_gm 0x0C // Transmit Interrupt Level group mask
#define USART_TXCINTLVL_bp 2 // Transmit Interrupt Level group position

#define USART_TXCINTLVL0_bm (1<<2) // Transmit Interrupt Level bit 0 mask
#define USART_TXCINTLVL0_bp 2 // Transmit Interrupt Level bit 0 position
#define USART_TXCINTLVL1_bm (1<<3) // Transmit Interrupt Level bit 1 mask
#define USART_TXCINTLVL1_bp 3 // Transmit Interrupt Level bit 1 position
#define USART_DREINTLVL_gm 0x03 // Data Register Empty Interrupt Level group mask
#define USART_DREINTLVL_bp 0 // Data Register Empty Interrupt Level group position

#define USART_DREINTLVL0_bm (1<<0) // Data Register Empty Interrupt Level bit 0 mask
#define USART_DREINTLVL0_bp 0 // Data Register Empty Interrupt Level bit 0 position
#define USART_DREINTLVL1_bm (1<<1) // Data Register Empty Interrupt Level bit 1 mask
#define USART_DREINTLVL1_bp 1 // Data Register Empty Interrupt Level bit 1 position

/* USART.CTRLB bit masks and bit positions */

        
#define USART_RXEN_bm 0x10 // Receiver Enable bit mask
#define USART_RXEN_bp 4 // Receiver Enable bit position
#define USART_TXEN_bm 0x08 // Transmitter Enable bit mask
#define USART_TXEN_bp 3 // Transmitter Enable bit position
#define USART_CLK2X_bm 0x04 // Double transmission speed bit mask
#define USART_CLK2X_bp 2 // Double transmission speed bit position
#define USART_MPCM_bm 0x02 // Multi-processor Communication Mode bit mask
#define USART_MPCM_bp 1 // Multi-processor Communication Mode bit position
#define USART_TXB8_bm 0x01 // Transmit bit 8 bit mask
#define USART_TXB8_bp 0 // Transmit bit 8 bit position

/* USART.CTRLC bit masks and bit positions */

        
#define USART_CMODE_gm 0xC0 // Communication Mode group mask
#define USART_CMODE_bp 6 // Communication Mode group position

#define USART_CMODE0_bm (1<<6) // Communication Mode bit 0 mask
#define USART_CMODE0_bp 6 // Communication Mode bit 0 position
#define USART_CMODE1_bm (1<<7) // Communication Mode bit 1 mask
#define USART_CMODE1_bp 7 // Communication Mode bit 1 position
#define USART_PMODE_gm 0x30 // Parity Mode group mask
#define USART_PMODE_bp 4 // Parity Mode group position

#define USART_PMODE0_bm (1<<4) // Parity Mode bit 0 mask
#define USART_PMODE0_bp 4 // Parity Mode bit 0 position
#define USART_PMODE1_bm (1<<5) // Parity Mode bit 1 mask
#define USART_PMODE1_bp 5 // Parity Mode bit 1 position
#define USART_SBMODE_bm 0x08 // Stop Bit Mode bit mask
#define USART_SBMODE_bp 3 // Stop Bit Mode bit position
#define USART_CHSIZE_gm 0x07 // Character Size group mask
#define USART_CHSIZE_bp 0 // Character Size group position

#define USART_CHSIZE0_bm (1<<0) // Character Size bit 0 mask
#define USART_CHSIZE0_bp 0 // Character Size bit 0 position
#define USART_CHSIZE1_bm (1<<1) // Character Size bit 1 mask
#define USART_CHSIZE1_bp 1 // Character Size bit 1 position
#define USART_CHSIZE2_bm (1<<2) // Character Size bit 2 mask
#define USART_CHSIZE2_bp 2 // Character Size bit 2 position

/* USART.BAUDCTRLA bit masks and bit positions */

        
#define USART_BSEL_gm 0xFF // Baud Rate Selection Bits [7:0] group mask
#define USART_BSEL_bp 0 // Baud Rate Selection Bits [7:0] group position

#define USART_BSEL0_bm (1<<0) // Baud Rate Selection Bits [7:0] bit 0 mask
#define USART_BSEL0_bp 0 // Baud Rate Selection Bits [7:0] bit 0 position
#define USART_BSEL1_bm (1<<1) // Baud Rate Selection Bits [7:0] bit 1 mask
#define USART_BSEL1_bp 1 // Baud Rate Selection Bits [7:0] bit 1 position
#define USART_BSEL2_bm (1<<2) // Baud Rate Selection Bits [7:0] bit 2 mask
#define USART_BSEL2_bp 2 // Baud Rate Selection Bits [7:0] bit 2 position
#define USART_BSEL3_bm (1<<3) // Baud Rate Selection Bits [7:0] bit 3 mask
#define USART_BSEL3_bp 3 // Baud Rate Selection Bits [7:0] bit 3 position
#define USART_BSEL4_bm (1<<4) // Baud Rate Selection Bits [7:0] bit 4 mask
#define USART_BSEL4_bp 4 // Baud Rate Selection Bits [7:0] bit 4 position
#define USART_BSEL5_bm (1<<5) // Baud Rate Selection Bits [7:0] bit 5 mask
#define USART_BSEL5_bp 5 // Baud Rate Selection Bits [7:0] bit 5 position
#define USART_BSEL6_bm (1<<6) // Baud Rate Selection Bits [7:0] bit 6 mask
#define USART_BSEL6_bp 6 // Baud Rate Selection Bits [7:0] bit 6 position
#define USART_BSEL7_bm (1<<7) // Baud Rate Selection Bits [7:0] bit 7 mask
#define USART_BSEL7_bp 7 // Baud Rate Selection Bits [7:0] bit 7 position

/* USART.BAUDCTRLB bit masks and bit positions */

        
#define USART_BSCALE_gm 0xF0 // Baud Rate Scale group mask
#define USART_BSCALE_bp 4 // Baud Rate Scale group position

#define USART_BSCALE0_bm (1<<4) // Baud Rate Scale bit 0 mask
#define USART_BSCALE0_bp 4 // Baud Rate Scale bit 0 position
#define USART_BSCALE1_bm (1<<5) // Baud Rate Scale bit 1 mask
#define USART_BSCALE1_bp 5 // Baud Rate Scale bit 1 position
#define USART_BSCALE2_bm (1<<6) // Baud Rate Scale bit 2 mask
#define USART_BSCALE2_bp 6 // Baud Rate Scale bit 2 position
#define USART_BSCALE3_bm (1<<7) // Baud Rate Scale bit 3 mask
#define USART_BSCALE3_bp 7 // Baud Rate Scale bit 3 position
/* Masks for BSEL aready defined */
            

#if !defined (__ASSEMBLER__)
/* Receive Complete Interrupt level */
typedef enum USART_RXCINTLVL_enum
{
  USART_RXCINTLVL_OFF_gc = (0x00<<4),   /* Interrupt Disabled */
  USART_RXCINTLVL_LO_gc = (0x01<<4),   /* Low Level */
  USART_RXCINTLVL_MED_gc = (0x02<<4),   /* Medium Level */
  USART_RXCINTLVL_HI_gc = (0x03<<4),   /* High Level */
} USART_RXCINTLVL_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/* Transmit Complete Interrupt level */
typedef enum USART_TXCINTLVL_enum
{
  USART_TXCINTLVL_OFF_gc = (0x00<<2),   /* Interrupt Disabled */
  USART_TXCINTLVL_LO_gc = (0x01<<2),   /* Low Level */
  USART_TXCINTLVL_MED_gc = (0x02<<2),   /* Medium Level */
  USART_TXCINTLVL_HI_gc = (0x03<<2),   /* High Level */
} USART_TXCINTLVL_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/* Data Register Empty Interrupt level */
typedef enum USART_DREINTLVL_enum
{
  USART_DREINTLVL_OFF_gc = (0x00<<0),   /* Interrupt Disabled */
  USART_DREINTLVL_LO_gc = (0x01<<0),   /* Low Level */
  USART_DREINTLVL_MED_gc = (0x02<<0),   /* Medium Level */
  USART_DREINTLVL_HI_gc = (0x03<<0),   /* High Level */
} USART_DREINTLVL_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/* Character Size */
typedef enum USART_CHSIZE_enum
{
  USART_CHSIZE_5BIT_gc = (0x00<<0),   /* Character size: 5 bit */
  USART_CHSIZE_6BIT_gc = (0x01<<0),   /* Character size: 6 bit */
  USART_CHSIZE_7BIT_gc = (0x02<<0),   /* Character size: 7 bit */
  USART_CHSIZE_8BIT_gc = (0x03<<0),   /* Character size: 8 bit */
  USART_CHSIZE_9BIT_gc = (0x07<<0),   /* Character size: 9 bit */
} USART_CHSIZE_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/* Communication Mode */
typedef enum USART_CMODE_enum
{
  USART_CMODE_ASYNCHRONOUS_gc = (0x00<<6),   /* Asynchronous Mode */
  USART_CMODE_SYNCHRONOUS_gc = (0x01<<6),   /* Synchronous Mode */
  USART_CMODE_IRDA_gc = (0x02<<6),   /* IrDA Mode */
  USART_CMODE_MSPI_gc = (0x03<<6),   /* Master SPI Mode */
} USART_CMODE_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/* Parity Mode */
typedef enum USART_PMODE_enum
{
  USART_PMODE_DISABLED_gc = (0x00<<0),   /* No Parity */
  USART_PMODE_EVEN_gc = (0x02<<0),   /* Even Parity */
  USART_PMODE_ODD_gc = (0x03<<0),   /* Odd Parity */
} USART_PMODE_t;
#endif /* !defined (__ASSEMBLER__) */


/*
--------------------------------------------------------------------------
 SPI - Serial Peripheral Interface
--------------------------------------------------------------------------
*/

/* SPI.CTRL bit masks and bit positions */

        
#define SPI_CLK2X_bm 0x80 // TODO: Find documentation on this bit bit mask
#define SPI_CLK2X_bp 7 // TODO: Find documentation on this bit bit position
#define SPI_ENABLE_bm 0x40 // Enable Module bit mask
#define SPI_ENABLE_bp 6 // Enable Module bit position
#define SPI_DORD_bm 0x20 // Data Order Setting bit mask
#define SPI_DORD_bp 5 // Data Order Setting bit position
#define SPI_MASTER_bm 0x10 // Master Operation Enable bit mask
#define SPI_MASTER_bp 4 // Master Operation Enable bit position
#define SPI_MODE_gm 0x0C // SPI Mode group mask
#define SPI_MODE_bp 2 // SPI Mode group position

#define SPI_MODE0_bm (1<<2) // SPI Mode bit 0 mask
#define SPI_MODE0_bp 2 // SPI Mode bit 0 position
#define SPI_MODE1_bm (1<<3) // SPI Mode bit 1 mask
#define SPI_MODE1_bp 3 // SPI Mode bit 1 position
#define SPI_PRESCALER_gm 0x03 // Prescaler group mask
#define SPI_PRESCALER_bp 0 // Prescaler group position

#define SPI_PRESCALER0_bm (1<<0) // Prescaler bit 0 mask
#define SPI_PRESCALER0_bp 0 // Prescaler bit 0 position
#define SPI_PRESCALER1_bm (1<<1) // Prescaler bit 1 mask
#define SPI_PRESCALER1_bp 1 // Prescaler bit 1 position

/* SPI.INTCTRL bit masks and bit positions */

        
#define SPI_INTLVL_gm 0x03 // Interrupt level group mask
#define SPI_INTLVL_bp 0 // Interrupt level group position

#define SPI_INTLVL0_bm (1<<0) // Interrupt level bit 0 mask
#define SPI_INTLVL0_bp 0 // Interrupt level bit 0 position
#define SPI_INTLVL1_bm (1<<1) // Interrupt level bit 1 mask
#define SPI_INTLVL1_bp 1 // Interrupt level bit 1 position

/* SPI.STATUS bit masks and bit positions */

        
#define SPI_IF_bm 0x80 // Interrupt Flag bit mask
#define SPI_IF_bp 7 // Interrupt Flag bit position
#define SPI_WRCOL_bm 0x40 // Write Collision bit mask
#define SPI_WRCOL_bp 6 // Write Collision bit position

#if !defined (__ASSEMBLER__)
/* SPI Mode */
typedef enum SPI_MODE_enum
{
  SPI_MODE_0_gc = (0x00<<2),   /* SPI Mode 0 */
  SPI_MODE_1_gc = (0x01<<2),   /* SPI Mode 1 */
  SPI_MODE_2_gc = (0x02<<2),   /* SPI Mode 2 */
  SPI_MODE_3_gc = (0x03<<2),   /* SPI Mode 3 */
} SPI_MODE_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/* Prescaler setting */
typedef enum SPI_PRESCALER_enum
{
  SPI_PRESCALER_DIV4_gc = (0x00<<0),   /* System Clock / 4 */
  SPI_PRESCALER_DIV16_gc = (0x01<<0),   /* System Clock / 16 */
  SPI_PRESCALER_DIV64_gc = (0x02<<0),   /* System Clock / 64 */
  SPI_PRESCALER_DIV128_gc = (0x03<<0),   /* System Clock / 128 */
} SPI_PRESCALER_t;
#endif /* !defined (__ASSEMBLER__) */

#if !defined (__ASSEMBLER__)
/* Interrupt level */
typedef enum SPI_INTLVL_enum
{
  SPI_INTLVL_OFF_gc = (0x00<<0),   /* Interrupt Disabled */
  SPI_INTLVL_LO_gc = (0x01<<0),   /* Low Level */
  SPI_INTLVL_MED_gc = (0x02<<0),   /* Medium Level */
  SPI_INTLVL_HI_gc = (0x03<<0),   /* High Level */
} SPI_INTLVL_t;
#endif /* !defined (__ASSEMBLER__) */


/*
--------------------------------------------------------------------------
 IRCOM - IR Communication Module
--------------------------------------------------------------------------
*/

/* IRCOM.CTRL bit masks and bit positions */

        
#define IRCOM_EVSEL_gm 0x0F // Event Channel Select group mask
#define IRCOM_EVSEL_bp 0 // Event Channel Select group position

#define IRCOM_EVSEL0_bm (1<<0) // Event Channel Select bit 0 mask
#define IRCOM_EVSEL0_bp 0 // Event Channel Select bit 0 position
#define IRCOM_EVSEL1_bm (1<<1) // Event Channel Select bit 1 mask
#define IRCOM_EVSEL1_bp 1 // Event Channel Select bit 1 position
#define IRCOM_EVSEL2_bm (1<<2) // Event Channel Select bit 2 mask
#define IRCOM_EVSEL2_bp 2 // Event Channel Select bit 2 position
#define IRCOM_EVSEL3_bm (1<<3) // Event Channel Select bit 3 mask
#define IRCOM_EVSEL3_bp 3 // Event Channel Select bit 3 position

#if !defined (__ASSEMBLER__)
/* Event Selection */
typedef enum IRDA_EVSEL_enum
{
  IRDA_EVSEL_OFF_gc = (0x00<<0),   /* No Event Source */
  IRDA_EVSEL_0_gc = (0x08<<0),   /* Event Channel 0 */
  IRDA_EVSEL_1_gc = (0x09<<0),   /* Event Channel 1 */
  IRDA_EVSEL_2_gc = (0x0A<<0),   /* Event Channel 2 */
  IRDA_EVSEL_3_gc = (0x0B<<0),   /* Event Channel 3 */
  IRDA_EVSEL_4_gc = (0x0C<<0),   /* Event Channel 4 */
  IRDA_EVSEL_5_gc = (0x0D<<0),   /* Event Channel 5 */
  IRDA_EVSEL_6_gc = (0x0E<<0),   /* Event Channel 6 */
  IRDA_EVSEL_7_gc = (0x0F<<0),   /* Event Channel 7 */
} IRDA_EVSEL_t;
#endif /* !defined (__ASSEMBLER__) */


/*
--------------------------------------------------------------------------
 AES - AES Module
--------------------------------------------------------------------------
*/

/* AES.CTRL bit masks and bit positions */

        
#define AES_START_bm 0x80 // Start/Run bit mask
#define AES_START_bp 7 // Start/Run bit position
#define AES_AUTO_bm 0x40 // Auto Start Trigger bit mask
#define AES_AUTO_bp 6 // Auto Start Trigger bit position
#define AES_RESET_bm 0x20 // AES Software Reset bit mask
#define AES_RESET_bp 5 // AES Software Reset bit position
#define AES_DECRYPT_bm 0x10 // Decryption / Direction bit mask
#define AES_DECRYPT_bp 4 // Decryption / Direction bit position
#define AES_XOR_bm 0x04 // State XOR Load Enable bit mask
#define AES_XOR_bp 2 // State XOR Load Enable bit position

/* AES.STATUS bit masks and bit positions */

        
#define AES_ERROR_bm 0x80 // AES Error bit mask
#define AES_ERROR_bp 7 // AES Error bit position
#define AES_SRIF_bm 0x01 // State Ready Interrupt Flag bit mask
#define AES_SRIF_bp 0 // State Ready Interrupt Flag bit position

/* AES.INTCTRL bit masks and bit positions */

        
#define AES_INTLVL_gm 0x03 // Interrupt level group mask
#define AES_INTLVL_bp 0 // Interrupt level group position

#define AES_INTLVL0_bm (1<<0) // Interrupt level bit 0 mask
#define AES_INTLVL0_bp 0 // Interrupt level bit 0 position
#define AES_INTLVL1_bm (1<<1) // Interrupt level bit 1 mask
#define AES_INTLVL1_bp 1 // Interrupt level bit 1 position

#if !defined (__ASSEMBLER__)
/* Interrupt level */
typedef enum AES_INTLVL_enum
{
  AES_INTLVL_OFF_gc = (0x00<<0),   /* Interrupt Disabled */
  AES_INTLVL_LO_gc = (0x01<<0),   /* Low Level */
  AES_INTLVL_MED_gc = (0x02<<0),   /* Medium Level */
  AES_INTLVL_HI_gc = (0x03<<0),   /* High Level */
} AES_INTLVL_t;
#endif /* !defined (__ASSEMBLER__) */


// Port pins

#define PIN0_bm 0x01 
#define PIN0_bp 0
#define PIN1_bm 0x02
#define PIN1_bp 1
#define PIN2_bm 0x04 
#define PIN2_bp 2
#define PIN3_bm 0x08 
#define PIN3_bp 3
#define PIN4_bm 0x10 
#define PIN4_bp 4
#define PIN5_bm 0x20 
#define PIN5_bp 5
#define PIN6_bm 0x40 
#define PIN6_bp 6
#define PIN7_bm 0x80 
#define PIN7_bp 7


/* ========== Interrupt Vector Definitions ========== */

/* OSC interrupt vectors */
#define OSC_XOSCF_vect _VECTOR(1) // External Oscillator Failure Interrupt (NMI)

/* PORTC interrupt vectors */
#define PORTC_INT0_vect _VECTOR(2) // External Interrupt 0
#define PORTC_INT1_vect _VECTOR(3) // External Interrupt 1

/* PORTR interrupt vectors */
#define PORTR_INT0_vect _VECTOR(4) // External Interrupt 0
#define PORTR_INT1_vect _VECTOR(5) // External Interrupt 1

/* DMA interrupt vectors */
#define DMA_CH0_vect _VECTOR(6) // Channel 0 Interrupt
#define DMA_CH1_vect _VECTOR(7) // Channel 1 Interrupt
#define DMA_CH2_vect _VECTOR(8) // Channel 2 Interrupt
#define DMA_CH3_vect _VECTOR(9) // Channel 3 Interrupt

/* RTC interrupt vectors */
#define RTC_OVF_vect _VECTOR(10) // Overflow Interrupt
#define RTC_COMP_vect _VECTOR(11) // Compare Interrupt

/* TWIC interrupt vectors */
#define TWIC_TWIS_vect _VECTOR(12) // TWI Slave Interrupt
#define TWIC_TWIM_vect _VECTOR(13) // TWI Master Interrupt

/* TCC0 interrupt vectors */
#define TCC0_OVF_vect _VECTOR(14) // Overflow Interrupt
#define TCC0_ERR_vect _VECTOR(15) // Error Interrupt
#define TCC0_CCA_vect _VECTOR(16) // Compare or Capture A Interrupt
#define TCC0_CCB_vect _VECTOR(17) // Compare or Capture B Interrupt
#define TCC0_CCC_vect _VECTOR(18) // Compare or Capture C Interrupt
#define TCC0_CCD_vect _VECTOR(19) // Compare or Capture D Interrupt

/* TCC1 interrupt vectors */
#define TCC1_OVF_vect _VECTOR(20) // Overflow Interrupt
#define TCC1_ERR_vect _VECTOR(21) // Error Interrupt
#define TCC1_CCA_vect _VECTOR(22) // Compare or Capture A Interrupt
#define TCC1_CCB_vect _VECTOR(23) // Compare or Capture B Interrupt

/* SPIC interrupt vectors */
#define SPIC_INT_vect _VECTOR(24) // SPI Interrupt

/* USARTC0 interrupt vectors */
#define USARTC0_RXC_vect _VECTOR(25) // Reception Complete Interrupt
#define USARTC0_DRE_vect _VECTOR(26) // Data Register Empty Interrupt
#define USARTC0_TXC_vect _VECTOR(27) // Transmission Complete Interrupt

/* USARTC1 interrupt vectors */
#define USARTC1_RXC_vect _VECTOR(28) // Reception Complete Interrupt
#define USARTC1_DRE_vect _VECTOR(29) // Data Register Empty Interrupt
#define USARTC1_TXC_vect _VECTOR(30) // Transmission Complete Interrupt

/* AES interrupt vectors */
#define AES_INT_vect _VECTOR(31) // AES Interrupt

/* NVM interrupt vectors */
#define NVM_EE_vect _VECTOR(32) // EE Interrupt
#define NVM_SPM_vect _VECTOR(33) // SPM Interrupt

/* PORTB interrupt vectors */
#define PORTB_INT0_vect _VECTOR(34) // External Interrupt 0
#define PORTB_INT1_vect _VECTOR(35) // External Interrupt 1

/* ACB interrupt vectors */
#define ACB_ACW_vect _VECTOR(38) // ACW Window Mode Interrupt
#define ACB_AC1_vect _VECTOR(37) // AC1 Interrupt
#define ACB_AC0_vect _VECTOR(36) // AC0 Interrupt

/* ADCB interrupt vectors */
#define ADCB_CH0_vect _VECTOR(39) // Interrupt 0
#define ADCB_CH1_vect _VECTOR(40) // Interrupt 1
#define ADCB_CH2_vect _VECTOR(41) // Interrupt 2
#define ADCB_CH3_vect _VECTOR(42) // Interrupt 3

/* PORTE interrupt vectors */
#define PORTE_INT0_vect _VECTOR(43) // External Interrupt 0
#define PORTE_INT1_vect _VECTOR(44) // External Interrupt 1

/* TWIE interrupt vectors */
#define TWIE_TWIS_vect _VECTOR(45) // TWI Slave Interrupt
#define TWIE_TWIM_vect _VECTOR(46) // TWI Master Interrupt

/* TCE0 interrupt vectors */
#define TCE0_OVF_vect _VECTOR(47) // Overflow Interrupt
#define TCE0_ERR_vect _VECTOR(48) // Error Interrupt
#define TCE0_CCA_vect _VECTOR(49) // Compare or Capture A Interrupt
#define TCE0_CCB_vect _VECTOR(50) // Compare or Capture B Interrupt
#define TCE0_CCC_vect _VECTOR(51) // Compare or Capture C Interrupt
#define TCE0_CCD_vect _VECTOR(52) // Compare or Capture D Interrupt

/* TCE1 interrupt vectors */
#define TCE1_OVF_vect _VECTOR(53) // Overflow Interrupt
#define TCE1_ERR_vect _VECTOR(54) // Error Interrupt
#define TCE1_CCA_vect _VECTOR(55) // Compare or Capture A Interrupt
#define TCE1_CCB_vect _VECTOR(56) // Compare or Capture B Interrupt

/* SPIE interrupt vectors */
#define SPIE_INT_vect _VECTOR(57) // SPI Interrupt

/* USARTE0 interrupt vectors */
#define USARTE0_RXC_vect _VECTOR(58) // Reception Complete Interrupt
#define USARTE0_DRE_vect _VECTOR(59) // Data Register Empty Interrupt
#define USARTE0_TXC_vect _VECTOR(60) // Transmission Complete Interrupt

/* USARTE1 interrupt vectors */
#define USARTE1_RXC_vect _VECTOR(61) // Reception Complete Interrupt
#define USARTE1_DRE_vect _VECTOR(62) // Data Register Empty Interrupt
#define USARTE1_TXC_vect _VECTOR(63) // Transmission Complete Interrupt

/* PORTD interrupt vectors */
#define PORTD_INT0_vect _VECTOR(64) // External Interrupt 0
#define PORTD_INT1_vect _VECTOR(65) // External Interrupt 1

/* PORTA interrupt vectors */
#define PORTA_INT0_vect _VECTOR(66) // External Interrupt 0
#define PORTA_INT1_vect _VECTOR(67) // External Interrupt 1

/* ACA interrupt vectors */
#define ACA_ACW_vect _VECTOR(70) // ACW Window Mode Interrupt
#define ACA_AC1_vect _VECTOR(69) // AC1 Interrupt
#define ACA_AC0_vect _VECTOR(68) // AC0 Interrupt

/* ADCA interrupt vectors */
#define ADCA_CH0_vect _VECTOR(71) // Interrupt 0
#define ADCA_CH1_vect _VECTOR(72) // Interrupt 1
#define ADCA_CH2_vect _VECTOR(73) // Interrupt 2
#define ADCA_CH3_vect _VECTOR(74) // Interrupt 3

/* TWID interrupt vectors */
#define TWID_TWIS_vect _VECTOR(75) // TWI Slave Interrupt
#define TWID_TWIM_vect _VECTOR(76) // TWI Master Interrupt

/* TCD0 interrupt vectors */
#define TCD0_OVF_vect _VECTOR(77) // Overflow Interrupt
#define TCD0_ERR_vect _VECTOR(78) // Error Interrupt
#define TCD0_CCA_vect _VECTOR(79) // Compare or Capture A Interrupt
#define TCD0_CCB_vect _VECTOR(80) // Compare or Capture B Interrupt
#define TCD0_CCC_vect _VECTOR(81) // Compare or Capture C Interrupt
#define TCD0_CCD_vect _VECTOR(82) // Compare or Capture D Interrupt

/* TCD1 interrupt vectors */
#define TCD1_OVF_vect _VECTOR(83) // Overflow Interrupt
#define TCD1_ERR_vect _VECTOR(84) // Error Interrupt
#define TCD1_CCA_vect _VECTOR(85) // Compare or Capture A Interrupt
#define TCD1_CCB_vect _VECTOR(86) // Compare or Capture B Interrupt

/* SPID interrupt vectors */
#define SPID_INT_vect _VECTOR(87) // SPI Interrupt

/* USARTD0 interrupt vectors */
#define USARTD0_RXC_vect _VECTOR(88) // Reception Complete Interrupt
#define USARTD0_DRE_vect _VECTOR(89) // Data Register Empty Interrupt
#define USARTD0_TXC_vect _VECTOR(90) // Transmission Complete Interrupt

/* USARTD1 interrupt vectors */
#define USARTD1_RXC_vect _VECTOR(91) // Reception Complete Interrupt
#define USARTD1_DRE_vect _VECTOR(92) // Data Register Empty Interrupt
#define USARTD1_TXC_vect _VECTOR(93) // Transmission Complete Interrupt

/* PORTQ interrupt vectors */
#define PORTQ_INT0_vect _VECTOR(94) // External Interrupt 0
#define PORTQ_INT1_vect _VECTOR(95) // External Interrupt 1

/* PORTH interrupt vectors */
#define PORTH_INT0_vect _VECTOR(96) // External Interrupt 0
#define PORTH_INT1_vect _VECTOR(97) // External Interrupt 1

/* PORTJ interrupt vectors */
#define PORTJ_INT0_vect _VECTOR(98) // External Interrupt 0
#define PORTJ_INT1_vect _VECTOR(99) // External Interrupt 1

/* PORTK interrupt vectors */
#define PORTK_INT0_vect _VECTOR(100) // External Interrupt 0
#define PORTK_INT1_vect _VECTOR(101) // External Interrupt 1

/* PORTF interrupt vectors */
#define PORTF_INT0_vect _VECTOR(104) // External Interrupt 0
#define PORTF_INT1_vect _VECTOR(105) // External Interrupt 1

/* TWIF interrupt vectors */
#define TWIF_TWIS_vect _VECTOR(106) // TWI Slave Interrupt
#define TWIF_TWIM_vect _VECTOR(107) // TWI Master Interrupt

/* TCF0 interrupt vectors */
#define TCF0_OVF_vect _VECTOR(108) // Overflow Interrupt
#define TCF0_ERR_vect _VECTOR(109) // Error Interrupt
#define TCF0_CCA_vect _VECTOR(110) // Compare or Capture A Interrupt
#define TCF0_CCB_vect _VECTOR(111) // Compare or Capture B Interrupt
#define TCF0_CCC_vect _VECTOR(112) // Compare or Capture C Interrupt
#define TCF0_CCD_vect _VECTOR(113) // Compare or Capture D Interrupt

/* TCF1 interrupt vectors */
#define TCF1_OVF_vect _VECTOR(114) // Overflow Interrupt
#define TCF1_ERR_vect _VECTOR(115) // Error Interrupt
#define TCF1_CCA_vect _VECTOR(116) // Compare or Capture A Interrupt
#define TCF1_CCB_vect _VECTOR(117) // Compare or Capture B Interrupt

/* SPIF interrupt vectors */
#define SPIF_INT_vect _VECTOR(118) // SPI Interrupt

/* USARTF0 interrupt vectors */
#define USARTF0_RXC_vect _VECTOR(119) // Reception Complete Interrupt
#define USARTF0_DRE_vect _VECTOR(120) // Data Register Empty Interrupt
#define USARTF0_TXC_vect _VECTOR(121) // Transmission Complete Interrupt

/* USARTF1 interrupt vectors */
#define USARTF1_RXC_vect _VECTOR(122) // Reception Complete Interrupt
#define USARTF1_DRE_vect _VECTOR(123) // Data Register Empty Interrupt
#define USARTF1_TXC_vect _VECTOR(124) // Transmission Complete Interrupt


// todo: calculate size from XML data
#define _VECTORS_SIZE (125 * 4)



/* todo: calculate from XML file */
/* Constants */
#define SPM_PAGESIZE 256
#define RAMSTART 0x2000
#define RAMSIZE  0x2000
#define RAMEND   (RAMSTART + RAMSIZE - 1)  /* Last On-Chip SRAM Location. */
#define XRAMEND  0xFFFFFF
#define E2END    0x7FF
#define FLASHEND 0x1FFFF


/* todo: Fuses */


/* todo: Lockbits */


#endif /* _AVR_ATxmega128A1_H_ */
