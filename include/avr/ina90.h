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

/*
   ina90.h

   Contributors:
     Created by Marek Michalkiewicz <marekm@linux.org.pl>
 */

/*
   ina90.h - this is an attempt to provide some compatibility with
   header files that come with IAR C, to make porting applications
   between different compilers easier.  No 100% compatibility though.
 */

#ifndef _INA90_H_
#define _INA90_H_ 1

#define _CLI() __asm__ __volatile__ ("cli")
#define _SEI() __asm__ __volatile__ ("sei")
#define _NOP() __asm__ __volatile__ ("nop")
#define _WDR() __asm__ __volatile__ ("wdr")
#define _SLEEP() __asm__ __volatile__ ("sleep")
#define _OPC(op) __asm__ __volatile__ (".word %0" : : "n" (op))

#define __LPM_enhanced__(addr) ({		\
	unsigned short __addr16 = (unsigned short)(addr); \
	unsigned char __result;			\
	__asm__ (				\
		"lpm %0, Z"			\
		: "=r" (__result)		\
		: "z" (__addr16)		\
	);					\
	__result;				\
 })

#define __LPM_classic__(addr) ({		\
	unsigned short __addr16 = (unsigned short)(addr); \
	unsigned char __result;			\
	__asm__ (				\
		"lpm" "\n\t"			\
		"mov %0, r0"			\
		: "=r" (__result)		\
		: "z" (__addr16)		\
		: "r0"				\
	);					\
	__result;				\
 })

/* Only for devices with more than 64K of program memory.
   RAMPZ must be defined (see iom103.h).  */

#define __ELPM_enhanced__(addr) ({		\
	unsigned long __addr32 = (unsigned long)(addr); \
	unsigned char __result;			\
	__asm__ (				\
		"out %2, %C1" "\n\t"		\
		"movw r30, %1" "\n\t"		\
		"elpm %0, Z"			\
		: "=r" (__result)		\
		: "r" (__addr32),		\
		  "I" (_SFR_IO_ADDR(RAMPZ))	\
		: "r30", "r31"			\
	);					\
	__result;				\
 })

#define __ELPM_classic__(addr) ({		\
	unsigned long __addr32 = (unsigned long)(addr); \
	unsigned char __result;			\
	__asm__ (				\
		"out %2, %C1" "\n\t"		\
		"mov r31, %B1" "\n\t"		\
		"mov r30, %A1" "\n\t"		\
		"elpm" "\n\t"			\
		"mov %0, r0"			\
		: "=r" (__result)		\
		: "r" (__addr32),		\
		  "I" (_SFR_IO_ADDR(RAMPZ))	\
		: "r0", "r30", "r31"		\
	);					\
	__result;				\
 })

#if defined (__AVR_ENHANCED__)
#define  _LPM(addr)  __LPM_enhanced__(addr)
#define _ELPM(addr) __ELPM_enhanced__(addr)
#else
#define  _LPM(addr)  __LPM_classic__(addr)
#define _ELPM(addr) __ELPM_classic__(addr)
#endif

/* _EEGET, _EEPUT */
#include <eeprom.h>

#define input(port) inb(port)
#define output(port, val) outb(port, val)

#define __inp_blk__(port, addr, cnt, op) {	\
	unsigned char __i = (cnt);		\
	unsigned char *__addr = (addr);		\
	while (__i) {				\
		*(__addr op) = input(port);	\
		__i--;				\
	}					\
 }

#define input_block_inc(port, addr, cnt) __inp_blk__(port, addr, cnt, ++)
#define input_block_dec(port, addr, cnt) __inp_blk__(port, addr, cnt, --)

#define __out_blk__(port, addr, cnt, op) {	\
	unsigned char __i = (cnt);		\
	const unsigned char *__addr = (addr);	\
	while (__i) {				\
		output(port, *(__addr op));	\
		__i--;				\
	}					\
 }

#define output_block_inc(port, addr, cnt, op) __out_blk__(port, addr, cnt, ++)
#define output_block_dec(port, addr, cnt, op) __out_blk__(port, addr, cnt, --)

#endif

