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

#ifndef _AVR_INTERRUPT_H_
#define _AVR_INTERRUPT_H_

#include <avr/io.h>

/** \name Global manipulation of the interrupt flag

    The global interrupt flag is maintained in the I bit of the status
    register (SREG). */

/*@{*/

/** \def sei()
    \ingroup avr_interrupts

    \code#include <avr/interrupt.h>\endcode

    Enables interrupts by clearing the global interrupt mask. This function
    actually compiles into a single line of assembly, so there is no function
    call overhead. */

#define sei()  __asm__ __volatile__ ("sei" ::)

/** \def cli()
    \ingroup avr_interrupts

    \code#include <avr/interrupt.h>\endcode

    Disables all interrupts by clearing the global interrupt mask. This function
    actually compiles into a single line of assembly, so there is no function
    call overhead. */

#define cli()  __asm__ __volatile__ ("cli" ::)

/*@}*/

#ifdef __cplusplus
extern "C" {
#endif

/** \name Allowing specific system-wide interrupts

    In addition to globally enabling interrupts, each device's particular
    interrupt needs to be enabled separately if interrupts for this device are
    desired.  While some devices maintain their interrupt enable bit inside
    the device's register set, external and timer interrupts have system-wide
    configuration registers. 

    Example:

    \code
    // Enable timer 1 overflow interrupts.
    timer_enable_int(_BV(TOIE1));

    // Do some work...

    // Disable all timer interrupts.
    timer_enable_int(0);
    \endcode

    \note Be careful when you use these functions. If you already have a
    different interrupt enabled, you could inadvertantly disable it by
    enabling another intterupt. */

/*@{*/

/** \ingroup avr_interrupts

    \code#include <avr/interrupt.h>\endcode

    This function gives access to the \c gimsk register (or \c eimsk register
    if using an AVR Mega device). Although this function is essentially the
    same as using the outb() function, it does adapt slightly to the type of
    device being used. */

extern inline void enable_external_int (unsigned char ints)
{
#ifdef EIMSK
  outb(EIMSK, ints);
#else
#ifdef GIMSK
  outb(GIMSK, ints);
#endif
#endif
}

/** \ingroup avr_interrupts

    \code#include <avr/interrupt.h>\endcode

	This function modifies the \c timsk register using the outb() function.
	The value you pass via \c ints is device specific. */

extern inline void timer_enable_int (unsigned char ints)
{
#ifdef TIMSK
  outb(TIMSK, ints);
#endif
}

/*@}*/

#ifdef __cplusplus
}
#endif

#endif
