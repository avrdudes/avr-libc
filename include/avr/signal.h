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

#ifndef _AVR_SIGNAL_H_
#define _AVR_SIGNAL_H_

/** \name Macros for writing interrupt handler functions */

/*@{*/

/** \def SIGNAL(signame)
    \ingroup avr_interrupts

    \code#include <avr/signal.h>\endcode

    Introduces an interrupt handler function that runs with global interrupts
    initially disabled.  */

#ifdef __cplusplus
#define SIGNAL(signame)					\
extern "C" void signame(void);				\
void signame (void) __attribute__ ((signal));		\
void signame (void)
#else
#define SIGNAL(signame)					\
void signame (void) __attribute__ ((signal));		\
void signame (void)
#endif

/** \def INTERRUPT(signame) 
    \ingroup avr_interrupts

    \code#include <avr/signal.h>\endcode

    Introduces an interrupt handler function that runs with global interrupts
    initially enabled. This allows interrupt handlers to be interrupted. */

#ifdef __cplusplus
#define INTERRUPT(signame)				\
extern "C" void signame(void);				\
void signame (void) __attribute__ ((interrupt));	\
void signame (void)
#else
#define INTERRUPT(signame)				\
void signame (void) __attribute__ ((interrupt));	\
void signame (void)
#endif

/*@}*/

#endif /* _AVR_SIGNAL_H_ */
