/* Copyright (c) 2002,2005 Marek Michalkiewicz
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

#ifndef _AVR_INTERRUPT_H_
#define _AVR_INTERRUPT_H_

#include <avr/io.h>

/** \name Global manipulation of the interrupt flag

    The global interrupt flag is maintained in the I bit of the status
    register (SREG). */

/*@{*/

#if defined(DOXYGEN)
/** \def sei()
    \ingroup avr_interrupts

    \code#include <avr/interrupt.h>\endcode

    Enables interrupts by setting the global interrupt mask. This function
    actually compiles into a single line of assembly, so there is no function
    call overhead. */
extern void sei(void);
#else  /* !DOXYGEN */
# define sei()  __asm__ __volatile__ ("sei" ::)
#endif /* DOXYGEN */

#if defined(DOXYGEN)
/** \def cli()
    \ingroup avr_interrupts

    \code#include <avr/interrupt.h>\endcode

    Disables all interrupts by clearing the global interrupt mask. This function
    actually compiles into a single line of assembly, so there is no function
    call overhead. */
extern void cli(void);
#else  /* !DOXYGEN */
# define cli()  __asm__ __volatile__ ("cli" ::)
#endif /* DOXYGEN */

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
    \def enable_external_int(mask)
    \code#include <avr/interrupt.h>\endcode

    This macro gives access to the \c GIMSK register (or \c EIMSK register
    if using an AVR Mega device or \c GICR register for others). Although this
    macro is essentially the same as assigning to the register, it does
    adapt slightly to the type of device being used. This macro is 
    unavailable if none of the registers listed above are defined. */

/* Define common register definition if available. */
#if defined(EIMSK)
#  define __EICR  EIMSK
#elif defined(GIMSK)
#  define __EICR  GIMSK
#elif defined(GICR)
#  define __EICR  GICR
#endif

/* If common register defined, define macro. */
#if defined(__EICR) || defined(DOXYGEN)
#define enable_external_int(mask)               (__EICR = mask)
#endif



/** \ingroup avr_interrupts

    \code#include <avr/interrupt.h>\endcode

	This function modifies the \c timsk register.
	The value you pass via \c ints is device specific. */

static __inline__ void timer_enable_int (unsigned char ints)
{
#ifdef TIMSK
    TIMSK = ints;
#endif
}

/*@}*/

#ifdef __cplusplus
}
#endif

#endif
