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

/* $Id$ */

/*
   avr/delay.h - loops for small accurate delays
 */

#ifndef _AVR_DELAY_H_
#define _AVR_DELAY_H_ 1

#include <inttypes.h>

/** \defgroup avr_delay Busy-wait delay loops
    \code
    #include <avr/delay.h>
    \endcode

    The macros in this header file implement simple delay loops
    that perform a busy-waiting.  They are typically used to
    facilitate short delays in the program execution.  They are
    implemented as count-down loops with a well-known CPU cycle
    count per loop iteration.  As such, no other processing can
    occur simultaneously.  It should be kept in mind that the
    functions described here do not disable interrupts.

    In general, for long delays, the use of hardware timers is
    much preferrable, as they free the CPU, and allow for
    concurrent processing of other events while the timer is
    running.  However, in particular for very short delays, the
    overhead of setting up a hardware timer is too much compared
    to the overall delay time.

    Two inline functions are provided for the actual delay
    algorithms.  Two wrapper macros allow the specification of
    microsecond, and millisecond delays directly, using the
    application-supplied macro F_CPU as the CPU clock frequency
    (in Hertz).

    \note While these macros perform all calculation at compile-time
    using the C preprocessor, so no run-time overhead results, care
    should be taken to not overflow the argument domain range, as the
    macros cannot detect such an overflow but would rather truncate
    the loop count, yielding unintented delay values.
*/

/** \ingroup avr_delay

    Delay loop using an 8-bit counter \c __count, so up to 256
    iterations are possible.  (The value 256 would have to be passed
    as 0.)  The loop executes three CPU cycles per iteration, not
    including the overhead the compiler needs to setup the counter
    register.

    Thus, at a CPU speed of 1 MHz, delays of up to 768 microseconds
    can be achieved.
*/
static __inline__ void
_delay_loop_1(uint8_t __count)
{
	asm volatile (
		"1: dec %0" "\n\t"
		"brne 1b"
		: "=r" (__count)
		: "0" (__count)
	);
}

/** \ingroup avr_delay

    Delay loop using a 16-bit counter \c __count, so up to 65536
    iterations are possible.  (The value 65536 would have to be
    passed as 0.)  The loop executes four CPU cycles per iteration,
    not including the overhead the compiler requires to setup the
    counter register pair.

    Thus, at a CPU speed of 1 MHz, delays of up to about 262.1
    milliseconds can be achieved.
 */
static __inline__ void
_delay_loop_2(uint16_t __count)
{
	asm volatile (
		"1: sbiw %0,1" "\n\t"
		"brne 1b"
		: "=w" (__count)
		: "0" (__count)
	);
}


/**
   \ingroup avr_delay
   \def _delay_us

   Perform a delay of \c count microseconds, using _delay_loop_1().

   The macro F_CPU is supposed to be defined to an unsigned long
   integer constant defining the CPU clock frequency (in Hertz).

   The maximal possible delay is 768 us / F_CPU in MHz.
 */
#define _delay_us(count) \
_delay_loop_1((uint8_t)(((unsigned long)(F_CPU) * (count)) / 3000000UL))

/**
   \ingroup avr_delay
   \def _delay_ms

   Perform a delay of \c count milliseconds, using _delay_loop_2().

   The macro F_CPU is supposed to be defined to an unsigned long
   integer constant defining the CPU clock frequency (in Hertz).

   The maximal possible delay is 262.14 ms / F_CPU in MHz.
 */
#define _delay_ms(count) \
_delay_loop_2((uint16_t)(((unsigned long)(F_CPU) * (count)) / 4000UL))

#endif /* _AVR_DELAY_H_ */
