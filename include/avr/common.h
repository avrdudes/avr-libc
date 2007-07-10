/* Copyright (c) 2007 Eric B. Weddington
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


#ifndef _AVR_COMMON_H
#define _AVR_COMMON_H

#include <avr/sfr_defs.h>

/* 
This purpose of this header is to define registers that have not been 
previously defined in the individual device IO header files, and to define 
other symbols that are common across AVR device families.

This file is designed to be included in <avr/io.h> after the individual
device IO header files, and after <avr/sfr_defs.h>

*/

/*------------ Registers Not Previously Defined ------------*/

/* 
These are registers that are not previously defined in the individual
IO header files, OR they are defined here because they are used in parts of
avr-libc even if a device is not selected but a general architecture has
been selected.
*/


/* Definitions for non-Xmega devices */
#if __AVR_ARCH__ != 7

/*
Stack pointer register.

AVR architecture 1 has no RAM, thus no stack pointer. 

All other architectures do have a stack pointer.  Some devices have only
less than 256 bytes of possible RAM locations (128 Bytes of SRAM
and no option for external RAM), thus SPH is officially "reserved"
for them.

*/
#  if __AVR_ARCH__ != 1 

#    ifndef SPL
#      define SPL _SFR_IO8(0x3D)
#    endif
#    if XRAMEND < 0x100
#      ifndef SP
#        define SP  _SFR_IO8(0x3D)
#      endif
#    else
#      ifndef SP
#        define SP  _SFR_IO16(0x3D)
#      endif
#      ifndef SPH
#        define SPH _SFR_IO8(0x3E)
#      endif
#    endif /* XRAMEND < 0x100 && !defined(__COMPILING_AVR_LIBC__) */

#  endif /* __AVR_ARCH__ != 1 */


/* Status Register */
#  ifndef SREG
#    define SREG _SFR_IO8(0x3F)
#  endif

/* SREG bit definitions */
#  ifndef SREG_C
#    define SREG_C  (0)
#  endif
#  ifndef SREG_Z
#    define SREG_Z  (1)
#  endif
#  ifndef SREG_N
#    define SREG_N  (2)
#  endif
#  ifndef SREG_V
#    define SREG_V  (3)
#  endif
#  ifndef SREG_S
#    define SREG_S  (4)
#  endif
#  ifndef SREG_H
#    define SREG_H  (5)
#  endif
#  ifndef SREG_T
#    define SREG_T  (6)
#  endif
#  ifndef SREG_I
#    define SREG_I  (7)
#  endif

#endif /* __AVR_ARCH__ != 7 */


/* AVR 6 Architecture */
#if __AVR_ARCH__ == 6
#  ifndef EIND
#    define EIND  _SFR_IO8(0X3C)
#  endif
#endif /* __AVR_ARCH__ == 6 */


/* Xmega Architecture */
#if __AVR_ARCH__ == 7
#  ifndef CPU0_SREG
#    define CPU0_SREG  _SFR_MEM8(63)
#  endif
#  ifndef CPU0_SPL
#    define CPU0_SPL   _SFR_MEM8(61)
#  endif
#  ifndef CPU0_SPH
#    define CPU0_SPH   _SFR_MEM8(62)
#  endif
#  ifndef CPU0_RAMPZ
#    define CPU0_RAMPZ _SFR_MEM8(59)
#  endif
#  ifndef CPU0_EIND
#    define CPU0_EIND  _SFR_MEM8(60)
#  endif
#endif /* __AVR_ARCH__ == 7 */



#if defined(__COMPILING_AVR_LIBC__)

/*
Only few devices come without EEPROM.  In order to assemble the
EEPROM library components without defining a specific device, we
keep the EEPROM-related definitions here.
*/

/* EEPROM Control Register */
#  ifndef EECR
#    define EECR   _SFR_IO8(0x1C)
#  endif

/* EEPROM Data Register */
#  ifndef EEDR
#    define EEDR   _SFR_IO8(0x1D)
#  endif

/* EEPROM Address Register */
#  ifndef EEAR
#    define EEAR   _SFR_IO16(0x1E)
#  endif
#  ifndef EEARL
#    define EEARL  _SFR_IO8(0x1E)
#  endif
#  ifndef EEARH
#    define EEARH  _SFR_IO8(0x1F)
#  endif

/* EEPROM Control Register bits */
#  ifndef EERE
#    define EERE   (0)
#  endif
#  ifndef EEWE
#    define EEWE   (1)
#  endif
#  ifndef EEMWE
#    define EEMWE  (2)
#  endif
#  ifndef EERIE
#    define EERIE  (3)
#  endif

#endif /* __COMPILING_AVR_LIBC__ */



/*------------ Common Symbols ------------*/

/* 
Generic definitions for registers that are common across multiple AVR devices
and families.
*/

/* Pointer registers definitions */
#if __AVR_ARCH__ != 1  /* avr1 does not have X and Y pointers */
#  define XL  r26
#  define XH  r27
#  define YL  r28
#  define YH  r29
#endif /* #if __AVR_ARCH__ != 1 */
#define ZL  r30
#define ZH  r31


/* Status Register */
#if defined(SREG)
#  define AVR_STATUS_REG   SREG
#  define AVR_STATUS_ADDR  _SFR_IO_ADDR(SREG)
#endif
#if defined(CPU0_SREG)
#  define AVR_STATUS_REG   CPU0_SREG
#  define AVR_STATUS_ADDR  _SFR_MEM_ADDR(CPU0_SREG)
#endif

/* Stack Pointer (combined) Register */
#if defined(SP)
#  define AVR_STACK_POINTER_REG   SP
#  define AVR_STACK_POINTER_ADDR  _SFR_IO_ADDR(SP)
#endif
#if defined(CPU0_SPL)
#  define AVR_STACK_POINTER_REG   _SFR_MEM16(_SFR_MEM_ADDR(CPU0_SPL))
#  define AVR_STACK_POINTER_ADDR  _SFR_MEM_ADDR(CPU0_SPL)
#endif

/* Stack Pointer High Register */
#if defined(SPH)
#  define _HAVE_AVR_STACK_POINTER_HI 1
#  define AVR_STACK_POINTER_HI_REG   SPH
#  define AVR_STACK_POINTER_HI_ADDR  _SFR_IO_ADDR(SPH)
#endif
#if defined(CPU0_SPH)
#  define _HAVE_AVR_STACK_POINTER_HI 1
#  define AVR_STACK_POINTER_HI_REG   CPU0_SPH
#  define AVR_STACK_POINTER_HI_ADDR  _SFR_MEM_ADDR(CPU0_SPH)
#endif

/* Stack Pointer Low Register */
#if defined(SPL)
#  define AVR_STACK_POINTER_LO_REG   SPL
#  define AVR_STACK_POINTER_LO_ADDR  _SFR_IO_ADDR(SPL)
#endif
#if defined(CPU0_SPL)
#  define AVR_STACK_POINTER_LO_REG   CPU0_SPL
#  define AVR_STACK_POINTER_LO_ADDR  _SFR_MEM_ADDR(CPU0_SPL)
#endif

/* RAMPZ Register */
#if defined(RAMPZ)
#  define AVR_RAMPZ_REG   RAMPZ
#  define AVR_RAMPZ_ADDR  _SFR_IO_ADDR(RAMPZ)
#endif
#if defined(CPU0_RAMPZ)
#  define AVR_RAMPZ_REG   CPU0_RAMPZ
#  define AVR_RAMPZ_ADDR  _SFR_MEM_ADDR(CPU0_RAMPZ)
#endif

/* Extended Indirect Register */
#if defined(EIND)
#  define AVR_EXTENDED_INDIRECT_REG   EIND
#  define AVR_EXTENDED_INDIRECT_ADDR  _SFR_IO_ADDR(EIND)
#endif
#if defined(CPU0_EIND)
#  define AVR_EXTENDED_INDIRECT_REG   CPU0_EIND
#  define AVR_EXTENDED_INDIRECT_ADDR  _SFR_MEM_ADDR(CPU0_EIND)
#endif


#endif /* _AVR_COMMON_H */
