/* Copyright (c) 2002, 2004 Marek Michalkiewicz
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

/*
   avr/wdt.h - macros for AVR watchdog timer
 */

#ifndef _AVR_WDT_H_
#define _AVR_WDT_H_

#include <avr/io.h>

/** \defgroup avr_watchdog Watchdog timer handling
    \code #include <avr/wdt.h> \endcode

    This header file declares the interface to some inline macros
    handling the watchdog timer present in many AVR devices.  In order
    to prevent the watchdog timer configuration from being
    accidentally altered by a crashing application, a special timed
    sequence is required in order to change it.  The macros within
    this header file handle the required sequence automatically
    before changing any value.  Interrupts will be disabled during
    the manipulation.

    \note Depending on the fuse configuration of the particular
    device, further restrictions might apply, in particular it might
    be disallowed to turn off the watchdog timer. */

/**
   \ingroup avr_watchdog
   Reset the watchdog timer.  When the watchdog timer is enabled,
   a call to this instruction is required before the timer expires,
   otherwise a watchdog-initiated device reset will occur. */

#define wdt_reset() __asm__ __volatile__ ("wdr")

#if defined (__AVR_ATmega169__)
#define _wdt_write(value)				\
	__asm__ __volatile__ (				\
		"in __tmp_reg__,__SREG__" "\n\t"	\
		"cli" "\n\t"				\
		"wdr" "\n\t"				\
		"sts %0,%1" "\n\t"			\
		"out __SREG__,__tmp_reg__" "\n\t"	\
		"sts %0,%2"				\
		: /* no outputs */			\
		: "M" (_SFR_MEM_ADDR(WDTCR)),		\
		  "r" (0x18),/* _BV(WDCE) | _BV(WDE) */	\
		  "r" ((unsigned char)(value))		\
		: "r0"					\
	)
#else
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
#endif

/**
   \ingroup avr_watchdog
   Enable the watchdog timer, configuring it for expiry after
   \c timeout (which is a combination of the \c WDP0 through
   \c WDP2 to write into the \c WDTCR register).

   See also the symbolic constants \c WDTO_15MS et al.
*/
#define wdt_enable(timeout) _wdt_write((timeout) | _BV(WDE))

/**
   \ingroup avr_watchdog
   Disable the watchdog timer, if possible.  This attempts to
   turn off the \c WDE bit in the \c WDTCR register. */
#define wdt_disable() _wdt_write(0)

/**
   \ingroup avr_watchdog
   Symbolic constants for the watchdog timeout.  Since the watchdog
   timer is based on a free-running RC oscillator, the times are
   approximate only and apply to a supply voltage of 5 V.  At lower
   supply voltages, the times will increase.  For older devices, the
   times will be as large as three times when operating at Vcc = 3 V,
   while the newer devices (e. g. ATmega128, ATmega8) only experience
   a negligible change.

   Possible timeout values are: 15 ms, 30 ms, 60 ms, 120 ms, 250 ms,
   500 ms, 1 s, 2 s.  Symbolic constants are formed by the prefix
   \c WDTO_, followed by the time.

   Example that would select a watchdog timer expiry of approximately
   500 ms:
   \code
   wdt_enable(WDTO_500MS);
   \endcode
*/
#define WDTO_15MS	0

/** \ingroup avr_watchdog
    See \c WDT0_15MS */
#define WDTO_30MS	1

/** \ingroup avr_watchdog See
    \c WDT0_15MS */
#define WDTO_60MS	2

/** \ingroup avr_watchdog
    See \c WDT0_15MS */
#define WDTO_120MS	3

/** \ingroup avr_watchdog
    See \c WDT0_15MS */
#define WDTO_250MS	4

/** \ingroup avr_watchdog
    See \c WDT0_15MS */
#define WDTO_500MS	5

/** \ingroup avr_watchdog
    See \c WDT0_15MS */
#define WDTO_1S		6

/** \ingroup avr_watchdog
    See \c WDT0_15MS */
#define WDTO_2S		7

#endif /* _AVR_WDT_H_ */
