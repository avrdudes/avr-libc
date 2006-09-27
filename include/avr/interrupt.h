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

#if defined(__DOXYGEN__)
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

#if defined(__DOXYGEN__)
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

/** \name Macros for writing interrupt handler functions */

/*@{*/

#if defined(__DOXYGEN__)
/** \def ISR(vector)
    \ingroup avr_interrupts

    \code#include <avr/interrupt.h>\endcode

    Introduces an interrupt handler function (interrupt service
    routine) that runs with global interrupts initially disabled.

    \c vector must be one of the interrupt vector names that are
    valid for the particular MCU type.
*/
#  define ISR(vector)
#else  /* real code */

#if __GNUC__ >= 4 && __GNUC_MINOR__ >= 1
#  define __INTR_ATTRS used, externally_visible
#else /* GCC < 4.1 */
#  define __INTR_ATTRS used
#endif

#ifdef __cplusplus
#define ISR(vector)					\
extern "C" void vector(void) __attribute__ ((signal,__INTR_ATTRS));	\
void vector (void)
#else
#define ISR(vector)					\
void vector (void) __attribute__ ((signal,__INTR_ATTRS));		\
void vector (void)
#endif

#endif /* DOXYGEN */

#if defined(__DOXYGEN__)
/** \def SIGNAL(vector)
    \ingroup avr_interrupts

    \code#include <avr/interrupt.h>\endcode

    Introduces an interrupt handler function that runs with global interrupts
    initially disabled.

    This is the same as the ISR macro.
    \deprecated Do not use anymore in new code.
*/
#  define SIGNAL(vector)
#else  /* real code */

#ifdef __cplusplus
#define SIGNAL(vector)					\
extern "C" void vector(void) __attribute__ ((signal,__INTR_ATTRS));	\
void vector (void)
#else
#define SIGNAL(vector)					\
void vector (void) __attribute__ ((signal,__INTR_ATTRS));		\
void vector (void)
#endif

#endif /* DOXYGEN */

#if defined(__DOXYGEN__)
/** \def EMPTY_INTERRUPT(vector)
    \ingroup avr_interrupts

    \code#include <avr/interrupt.h>\endcode

    Defines an empty interrupt handler function. This will not generate
    any prolog or epilog code and will only return from the ISR. Do not
    define a function body as this will define it for you.
    Example:
    \code EMPTY_INTERRUPT(ADC_vect);\endcode */
#define EMPTY_INTERRUPT(vector)
#else  /* real code */

#ifdef __cplusplus
#define EMPTY_INTERRUPT(vector)                \
extern "C" void vector(void) __attribute__ ((signal,naked,__INTR_ATTRS));    \
void vector (void) {  __asm__ __volatile__ ("reti" ::); }
#else
#define EMPTY_INTERRUPT(vector)                \
void vector (void) __attribute__ ((signal,naked,__INTR_ATTRS));    \
void vector (void) { __asm__ __volatile__ ("reti" ::); }
#endif

#endif /* DOXYGEN */

#if !defined(__DOXYGEN__)
/* Auxiliary macro for ISR_ALIAS(). */
#define __ALIAS(tgt) __attribute__((alias(#tgt)))
#endif /* !defined(__DOXYGEN__) */

#if defined(__DOXYGEN__)
/** \def ISR_ALIAS(vector, target_vector)
    \ingroup avr_interrupts

    \code#include <avr/interrupt.h>\endcode

    Defines \c vector to point to the same interrupt vector as
    \c target_vector.  That way, a single interrupt vector
    implementation can be used to serve several interrupt sources.

    Do not define a function body.

    \note This requires a recent version of AVR-GCC to work
    (GCC 4.2 or patched GCC 4.1.x).

    Example:
    \code
    ISR(INT0_vect)
    {
        PORTB = 42;
    }

    ISR_ALIAS(INT1_vect, INT0_vect);
    \endcode */
#define ISR_ALIAS(vector, target_vector)
#else /* real code */

#ifdef __cplusplus
#define ISR_ALIAS(vector, tgt) extern "C" void vector(void) __ALIAS(tgt)
#else
#define ISR_ALIAS(vector, tgt) void vector(void) __ALIAS(tgt)
#endif

#endif /* DOXYGEN */


/*@}*/

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif
