/*
 * Copyright (C) 2022, Microchip Technology Inc. and its subsidiaries ("Microchip")
 * All rights reserved.
 *
 * This software is developed by Microchip Technology Inc. and its subsidiaries ("Microchip").
 *
 * Redistribution and use in source and binary forms, with or without modification, are
 * permitted provided that the following conditions are met:
 *
 *     1. Redistributions of source code must retain the above copyright notice, this list of
 *        conditions and the following disclaimer.
 *
 *     2. Redistributions in binary form must reproduce the above copyright notice, this list
 *        of conditions and the following disclaimer in the documentation and/or other
 *        materials provided with the distribution. Publication is not required when
 *        this file is used in an embedded application.
 *
 *     3. Microchip's name may not be used to endorse or promote products derived from this
 *        software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY MICROCHIP "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL MICROCHIP BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING BUT NOT LIMITED TO
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWSOEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _AVR_ATA5795_H_INCLUDED
#define _AVR_ATA5795_H_INCLUDED


#ifndef _AVR_IO_H_
#  error "Include <avr/io.h> instead of this file."
#endif

#ifndef _AVR_IOXXX_H_
#  define _AVR_IOXXX_H_ "ioa5795.h"
#else
#  error "Attempt to include more than one <avr/ioXXX.h> file."
#endif

/* Registers and associated bit numbers */

#define PINB    _SFR_IO8(0x03)
#define PINB7   7
#define PINB6   6
#define PINB5   5
#define PINB4   4
#define PINB3   3
#define PINB2   2
#define PINB1   1
#define PINB0   0

#define DDRB    _SFR_IO8(0x04)
#define DDRB7   7
// Inserted "DDB7" from "DDRB7" due to compatibility
#define DDB7    7
#define DDRB6   6
// Inserted "DDB6" from "DDRB6" due to compatibility
#define DDB6    6
#define DDRB5   5
// Inserted "DDB5" from "DDRB5" due to compatibility
#define DDB5    5
#define DDRB4   4
// Inserted "DDB4" from "DDRB4" due to compatibility
#define DDB4    4
#define DDRB3   3
// Inserted "DDB3" from "DDRB3" due to compatibility
#define DDB3    3
#define DDRB2   2
// Inserted "DDB2" from "DDRB2" due to compatibility
#define DDB2    2
#define DDRB1   1
// Inserted "DDB1" from "DDRB1" due to compatibility
#define DDB1    1
#define DDRB0   0
// Inserted "DDB0" from "DDRB0" due to compatibility
#define DDB0    0

#define PORTB   _SFR_IO8(0x05)
#define PORTB7  7
#define PORTB6  6
#define PORTB5  5
#define PORTB4  4
#define PORTB3  3
#define PORTB2  2
#define PORTB1  1
#define PORTB0  0

#define PINC    _SFR_IO8(0x06)
#define PINC4   4
#define PINC3   3
#define PINC2   2
#define PINC1   1
#define PINC0   0

#define DDRC    _SFR_IO8(0x07)
#define DDRC4   4
// Inserted "DDC4" from "DDRC4" due to compatibility
#define DDC4    4
#define DDRC3   3
// Inserted "DDC3" from "DDRC3" due to compatibility
#define DDC3    3
#define DDRC2   2
// Inserted "DDC2" from "DDRC2" due to compatibility
#define DDC2    2
#define DDRC1   1
// Inserted "DDC1" from "DDRC1" due to compatibility
#define DDC1    1
#define DDRC0   0
// Inserted "DDC0" from "DDRC0" due to compatibility
#define DDC0    0

#define PORTC   _SFR_IO8(0x08)
#define PORTC4  4
#define PORTC3  3
#define PORTC2  2
#define PORTC1  1
#define PORTC0  0

#define PIND    _SFR_IO8(0x09)
#define PIND7   7
#define PIND6   6
#define PIND5   5
#define PIND4   4
#define PIND3   3
#define PIND2   2
#define PIND1   1
#define PIND0   0

#define DDRD    _SFR_IO8(0x0A)
#define DDRD7   7
// Inserted "DDD7" from "DDRD7" due to compatibility
#define DDD7    7
#define DDRD6   6
// Inserted "DDD6" from "DDRD6" due to compatibility
#define DDD6    6
#define DDRD5   5
// Inserted "DDD5" from "DDRD5" due to compatibility
#define DDD5    5
#define DDRD4   4
// Inserted "DDD4" from "DDRD4" due to compatibility
#define DDD4    4
#define DDRD3   3
// Inserted "DDD3" from "DDRD3" due to compatibility
#define DDD3    3
#define DDRD2   2
// Inserted "DDD2" from "DDRD2" due to compatibility
#define DDD2    2
#define DDRD1   1
// Inserted "DDD1" from "DDRD1" due to compatibility
#define DDD1    1
#define DDRD0   0
// Inserted "DDD0" from "DDRD0" due to compatibility
#define DDD0    0

#define PORTD   _SFR_IO8(0x0B)
#define PORTD7  7
#define PORTD6  6
#define PORTD5  5
#define PORTD4  4
#define PORTD3  3
#define PORTD2  2
#define PORTD1  1
#define PORTD0  0

/* Reserved [0x0C] */

#define TPCR    _SFR_IO8(0x0D)
#define TPMA    0
#define TPMOD   1
#define TPMS0   2
#define TPMS1   3
#define TPMD0   4
#define TPMD1   5
#define TPPSD   6
#define TPD     7

#define TPFR    _SFR_IO8(0x0E)
#define TPF     0
#define TPA     1
#define TPGAP   2
#define TPPSW   3

#define CMCR    _SFR_IO8(0x0F)
#define CMM0    0
#define CMM1    1
#define SRCD    2
#define CO32D   3
#define CCS     4
#define ECINS   5
#define CMONEN  6
#define CMCCE   7

#define CMSR    _SFR_IO8(0x10)
#define ECF     0
#define SXF     1
#define RTCF    2

#define T2CR    _SFR_IO8(0x11)
#define T2OTM   0
#define T2CTM   1
#define T2CRM   2
#define T2GRM   3
#define T2TOP   4
#define T2RES   5
#define T2TS    6
#define T2E     7

#define T3CR    _SFR_IO8(0x12)
#define T3OTM   0
#define T3CTM   1
#define T3CRM   2
#define T3CPRM  3
#define T3TOP   4
#define T3RES   5
#define T3CPTM  6
#define T3E     7

#define AESCR   _SFR_IO8(0x13)
#define AESWK   0
#define AESWD   1
#define AESIM   2
#define AESD    3
#define AESXOR  4
#define AESRES  5
#define AESE    7

#define AESSR   _SFR_IO8(0x14)
#define AESRF   0
#define AESERF  7

#define TMIFR   _SFR_IO8(0x15)
#define TMRXF   0
#define TMTXF   1
#define TMTCF   2
#define TMRXS   3
#define TMTXS   4

#define VMSR    _SFR_IO8(0x16)
#define VMF     0

#define PCIFR   _SFR_IO8(0x17)
#define PCIF0   0
#define PCIF1   1

/* Reserved [0x18] */

#define T0IFR   _SFR_IO8(0x19)
#define T0F     0

#define T1IFR   _SFR_IO8(0x1A)
#define T1F     0

#define T2IFR   _SFR_IO8(0x1B)
#define T2OFF   0
#define T2COF   1

#define T3IFR   _SFR_IO8(0x1C)
#define T3OFF   0
#define T3COF   1
#define T3ICF   2

#define EIFR    _SFR_IO8(0x1D)
#define INTF0   0

#define GPIOR0  _SFR_IO8(0x1E)

#define EECR    _SFR_IO8(0x1F)
#define EERE    0
#define EEWE    1
#define EEMWE   2
#define EERIE   3
#define EEPM0   4
#define EEPM1   5
#define EELP    6

#define EEDR    _SFR_IO8(0x20)

/* Combine EEARL and EEARH */
#define EEAR    _SFR_IO16(0x21)

#define EEARL   _SFR_IO8(0x21)
#define EEARH   _SFR_IO8(0x22)

#define EEPR    _SFR_IO8(0x23)
#define EEAP0   0
#define EEAP1   1
#define EEAP2   2
#define EEAP3   3

#define EECCR   _SFR_IO8(0x24)
#define EEL0    0
#define EEL1    1
#define EEL2    2
#define EEL3    3

/* Reserved [0x25] */

#define PCICR   _SFR_IO8(0x26)
#define PCIE0   0
#define PCIE1   1

#define EIMSK   _SFR_IO8(0x27)
#define INT0    0

#define TMDR    _SFR_IO8(0x28)

#define AESDR   _SFR_IO8(0x29)

#define AESKR   _SFR_IO8(0x2A)
#define AESKR0  0
#define AESKR1  1
#define AESKR2  2
#define AESKR3  3
#define AESKR4  4
#define AESKR5  5
#define AESKR6  6
#define AESKR7  7

#define VMCR    _SFR_IO8(0x2B)
#define VMLS0   0
#define VMLS1   1
#define VMLS2   2
#define VMLS3   3
#define VMIM    4
#define VMPS    5
#define BODPD   6
#define BODLS   7

#define SPCR    _SFR_IO8(0x2C)
#define SPR0    0
#define SPR1    1
#define CPHA    2
#define CPOL    3
#define MSTR    4
#define DORD    5
#define SPE     6
#define SPIE    7

#define SPSR    _SFR_IO8(0x2D)
#define SPI2X   0
#define WCOL    6
#define SPIF    7

#define SPDR    _SFR_IO8(0x2E)

/* Reserved [0x2F..0x32] */

#define SMCR    _SFR_IO8(0x33)
#define SE      0
#define SM0     1
#define SM1     2
#define SM2     3

#define MCUSR   _SFR_IO8(0x34)
#define PORF    0
#define EXTRF   1
#define BORF    2
#define WDRF    3
#define TPRF    5

#define MCUCR   _SFR_IO8(0x35)
#define IVCE    0
#define IVSEL   1
#define PUD     4

/* Reserved [0x36] */

#define SPMCSR  _SFR_IO8(0x37)
#define SPMEN   0
#define PGERS   1
#define PGWRT   2
#define BLBSET  3
#define RWWSRE  4
#define SIGRD   5
#define RWWSB   6
#define SPMIE   7

#define T1CR    _SFR_IO8(0x38)
#define T1PS0   0
#define T1PS1   1
#define T1IE    2
#define T1CS0   3
#define T1CS1   4
#define T1E     7

#define T0CR    _SFR_IO8(0x39)
#define T0PS0   0
#define T0PS1   1
#define T0PS2   2
#define T0IE    3
#define T0PR    4

/* Reserved [0x3A] */

#define CMIMR   _SFR_IO8(0x3B)
#define ECIE    0
#define SXIE    1
#define RTCIE   2

#define CLKPR   _SFR_IO8(0x3C)
#define CLKPS0  0
#define CLKPS1  1
#define CLKPS2  2
#define CLTPS0  3
#define CLTPS1  4
#define CLTPS2  5
#define CLKPCE  7

/* SP [0x3D..0x3E] */

/* SREG [0x3F] */

#define WDTCR   _SFR_MEM8(0x60)
#define WDPS0   0
#define WDPS1   1
#define WDPS2   2
#define WDE     3
#define WDCE    4

/* Reserved [0x61..0x62] */

#define PRR0    _SFR_MEM8(0x63)
#define PRT1    1
#define PRT2    2
#define PRT3    3
#define PRTM    4
#define PRCU    5
#define PRDS    6
#define PRVM    7

#define __AVR_HAVE_PRR0	((1<<PRT1)|(1<<PRT2)|(1<<PRT3)|(1<<PRTM)|(1<<PRCU)|(1<<PRDS)|(1<<PRVM))
#define __AVR_HAVE_PRR0_PRT1
#define __AVR_HAVE_PRR0_PRT2
#define __AVR_HAVE_PRR0_PRT3
#define __AVR_HAVE_PRR0_PRTM
#define __AVR_HAVE_PRR0_PRCU
#define __AVR_HAVE_PRR0_PRDS
#define __AVR_HAVE_PRR0_PRVM

#define PRR1    _SFR_MEM8(0x64)
#define PRCI    0
#define PRSPI   1

#define __AVR_HAVE_PRR1	((1<<PRCI)|(1<<PRSPI))
#define __AVR_HAVE_PRR1_PRCI
#define __AVR_HAVE_PRR1_PRSPI

#define SRCCAL  _SFR_MEM8(0x65)

#define FRCCAL  _SFR_MEM8(0x66)

/* Reserved [0x67..0x68] */

#define EICRA   _SFR_MEM8(0x69)
#define ISC00   0
#define ISC01   1

#define PCMSK0  _SFR_MEM8(0x6A)
#define PCINT0  0
#define PCINT1  1
#define PCINT2  2
#define PCINT3  3
#define PCINT4  4
#define PCINT5  5
#define PCINT6  6
#define PCINT7  7

#define PCMSK1  _SFR_MEM8(0x6B)
#define PCINT8  0
#define PCINT9  1
#define PCINT10 2
#define PCINT11 3
#define PCINT12 4
#define PCINT13 5
#define PCINT14 6
#define PCINT15 7

/* Reserved [0x6C] */

#define LDCR    _SFR_MEM8(0x6D)
#define LDE     0
#define LDCS0   1
#define LDCS1   2

/* Reserved [0x6E..0x6F] */

#define T2CNT   _SFR_MEM8(0x70)

#define T2COR   _SFR_MEM8(0x71)

/* Reserved [0x72] */

#define T2MR    _SFR_MEM8(0x73)
#define T2CS0   0
#define T2CS1   1
#define T2CS2   2
#define T2PS0   3
#define T2PS1   4
#define T2PS2   5
#define T2D0    6
#define T2D1    7

#define T2IMR   _SFR_MEM8(0x74)
#define T2OIM   0
#define T2CIM   1

/* Reserved [0x75] */

#define T3CNT   _SFR_MEM8(0x76)

#define T3COR   _SFR_MEM8(0x77)

#define T3ICR   _SFR_MEM8(0x78)

#define T3MRA   _SFR_MEM8(0x79)
#define T3CS0   0
#define T3CS1   1
#define T3SCE   2
#define T3CE0   3
#define T3CE1   4
#define T3CNC   5
#define T3ICS0  6
#define T3ICS1  7

#define T3MRB   _SFR_MEM8(0x7A)
#define T3PS0   0
#define T3PS1   1
#define T3PS2   2

#define T3IMR   _SFR_MEM8(0x7B)
#define T3OIM   0
#define T3CIM   1
#define T3CPIM  2

/* Reserved [0x7C] */

#define TMCR    _SFR_MEM8(0x7D)
#define MI1S0   0
#define MI1S1   1
#define MI2S0   2
#define MI2S1   3
#define MI4S0   4
#define MI4S1   5
#define TMCPOL  6
#define TMSSIE  7

#define TMMR    _SFR_MEM8(0x7E)
#define MOS0    0
#define MOS1    1
#define MSCS0   2
#define MSCS1   3
#define MOUTC   4
#define TMMS0   5
#define TMMS1   6
#define TM12S   7

#define TMIMR   _SFR_MEM8(0x7F)
#define TMRXIM  0
#define TMTXIM  1
#define TMTCIM  2

/* Reserved [0x80..0x9B] */

#define TPIMR   _SFR_MEM8(0x9C)
#define TPIM    0

/* Reserved [0x9D] */

#define RTCCR   _SFR_MEM8(0x9E)
#define RTCR    0

#define RTCDR   _SFR_MEM8(0x9F)

/* Reserved [0xA0..0xA7] */

#define TMMDR   _SFR_MEM8(0xA8)

#define TMBDR   _SFR_MEM8(0xA9)

#define TMTDR   _SFR_MEM8(0xAA)

#define TMSR    _SFR_MEM8(0xAB)

/* Reserved [0xAC] */

#define CRCDR   _SFR_MEM8(0xAD)

#define CRCCR   _SFR_MEM8(0xAE)
#define CRCN0   0
#define CRCN1   1
#define CRCN2   2
#define CRCSEL  3
#define REFLI   4
#define REFLO   5
#define CRCRS   7

#define CRCSR   _SFR_MEM8(0xAF)
#define CRCBF   0



/* Values and associated defines */


#define SLEEP_MODE_IDLE (0x00<<1)
#define SLEEP_MODE_EXT_PWR_SAVE (0x01<<1)
#define SLEEP_MODE_PWR_DOWN (0x02<<1)
#define SLEEP_MODE_PWR_SAVE (0x03<<1)

/* Interrupt vectors */
/* Vector 0 is the reset vector */
/* Transponder Mode Interrupt */
#define TPINT_vect            _VECTOR(1)
#define TPINT_vect_num        1

/* External Interrupt Request 0 */
#define INT0_vect            _VECTOR(2)
#define INT0_vect_num        2

/* Pin Change Interrupt Request 0 */
#define PCINT0_vect            _VECTOR(3)
#define PCINT0_vect_num        3

/* Pin Change Interrupt Request 1 */
#define PCINT1_vect            _VECTOR(4)
#define PCINT1_vect_num        4

/* Voltage Monitor Interrupt */
#define VMINT_vect            _VECTOR(5)
#define VMINT_vect_num        5

/* Timer0 Interval Interrupt */
#define T0INT_vect            _VECTOR(6)
#define T0INT_vect_num        6

/* Timer3 Capture Interrupt */
#define T3CAPINT_vect            _VECTOR(7)
#define T3CAPINT_vect_num        7

/* Timer3 Compare Match Interrupt */
#define T3COMINT_vect            _VECTOR(8)
#define T3COMINT_vect_num        8

/* Timer3 Overflow Interrupt */
#define T3OVFINT_vect            _VECTOR(9)
#define T3OVFINT_vect_num        9

/* Timer2 Compare Match Interrupt */
#define T2COMINT_vect            _VECTOR(10)
#define T2COMINT_vect_num        10

/* Timer2 Overflow Interrupt */
#define T2OVFINT_vect            _VECTOR(11)
#define T2OVFINT_vect_num        11

/* Timer1 Interval Interrupt */
#define T1INT_vect            _VECTOR(12)
#define T1INT_vect_num        12

/* SPI Serial Transfer Complete */
#define SPISTC_vect            _VECTOR(13)
#define SPISTC_vect_num        13

/* Timer Modulator SSI Receive Buffer Interrupt */
#define TMRXBINT_vect            _VECTOR(14)
#define TMRXBINT_vect_num        14

/* Timer Modulator SSI Transmit Buffer Interrupt */
#define TMTXBINT_vect            _VECTOR(15)
#define TMTXBINT_vect_num        15

/* Timer Modulator Transmit Complete Interrupt */
#define TMTXCINT_vect            _VECTOR(16)
#define TMTXCINT_vect_num        16

/* AES Interrupt */
#define AESINT_vect            _VECTOR(17)
#define AESINT_vect_num        17

/* External Input Clock Monitoring Interrupt */
#define EXCMINT_vect            _VECTOR(18)
#define EXCMINT_vect_num        18

/* External XTAL Oscillator Break Down Interrupt */
#define EXXMINT_vect            _VECTOR(19)
#define EXXMINT_vect_num        19

/* Real Time Clock Interrupt */
#define RTCINT_vect            _VECTOR(20)
#define RTCINT_vect_num        20

/* EEPROM Ready Interrupt */
#define EEREADY_vect            _VECTOR(21)
#define EEREADY_vect_num        21

/* Store Program Memory Ready  */
#define SPMREADY_vect            _VECTOR(22)
#define SPMREADY_vect_num        22

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define _VECTORS_SIZE 46
#else
#  define _VECTORS_SIZE 46U
#endif


/* Constants */

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define SPM_PAGESIZE 64
#  define FLASHSTART   0x0000
#  define FLASHEND     0x1FFF
#else
#  define SPM_PAGESIZE 64U
#  define FLASHSTART   0x0000U
#  define FLASHEND     0x1FFFU
#endif
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define RAMSTART     0x0100
#  define RAMSIZE      512
#  define RAMEND       0x02FF
#else
#  define RAMSTART     0x0100U
#  define RAMSIZE      512U
#  define RAMEND       0x02FFU
#endif
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define E2START     0
#  define E2SIZE      2048
#  define E2PAGESIZE  16
#  define E2END       0x07FF
#else
#  define E2START     0U
#  define E2SIZE      2048U
#  define E2PAGESIZE  16U
#  define E2END       0x07FFU
#endif
#define XRAMEND      RAMEND


/* Fuses */

#define FUSE_MEMORY_SIZE 1

/* Fuse Byte */
#define FUSE__32OEN      (unsigned char)~_BV(1)
#define FUSE_Reserved    (unsigned char)~_BV(2)
#define FUSE_EESAVE      (unsigned char)~_BV(3)
#define FUSE_WDTON       (unsigned char)~_BV(4)
#define FUSE_SPIEN       (unsigned char)~_BV(5)
#define FUSE_DWEN        (unsigned char)~_BV(6)
#define FUSE_CKDIV8      (unsigned char)~_BV(7)
#define LFUSE_DEFAULT    (FUSE__32OEN & FUSE_Reserved & FUSE_WDTON & FUSE_SPIEN & FUSE_CKDIV8)



/* Lock Bits */
#define __LOCK_BITS_EXIST
#define __BOOT_LOCK_BITS_0_EXIST
#define __BOOT_LOCK_BITS_1_EXIST


/* Signature */
#define SIGNATURE_0 0x1E
#define SIGNATURE_1 0x93
#define SIGNATURE_2 0x61




#endif /* #ifdef _AVR_ATA5795_H_INCLUDED */

