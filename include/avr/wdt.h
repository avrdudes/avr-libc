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

/*
   avr/wdt.h - macros for AVR watchdog timer
 */

#ifndef _AVR_WDT_H_
#define _AVR_WDT_H_

#include <avr/io.h>

#define wdt_reset() __asm__ __volatile__ ("wdr")

#define _wdt_write(value)				\
	__asm__ __volatile__ (				\
		"in __tmp_reg__,__SREG__" "\n\t"	\
		"cli" "\n\t"				\
		"wdr" "\n\t"				\
		"out %0,%1" "\n\t"			\
		"out __SREG__,__tmp_reg__" "\n\t"	\
		"out %0,%2"				\
		: /* no outputs */			\
		: "I" (_SFR_IO_ADDR(WDTCR)),		\
		  "r" (0x18),/* _BV(WDCE) | _BV(WDE) */	\
		  "r" ((unsigned char)(value))		\
		: "r0"					\
	)

#define wdt_enable(timeout) _wdt_write((timeout) | _BV(WDE))

#define wdt_disable() _wdt_write(0)

#endif /* _AVR_WDT_H_ */
