/* Copyright (c) 2002, Theodore A. Roth
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

#ifndef _AVR_SLEEP_H_
#define _AVR_SLEEP_H_ 1

#include <avr/io.h>

/** \defgroup avr_sleep Power Management and Sleep Modes

    \code #include <avr/sleep.h>\endcode

    Use of the \c SLEEP instruction can allow your application to reduce it's
    power comsumption considerably. AVR devices can be put into different
    sleep modes by changing the \c SMn bits of the \c MCU Control Register (
    \c MCUCR ). Refer to the datasheet for the details relating to the device
    you are using. */

/** \name Sleep Modes

    \note FIXME: TRoth/2002-11-01: These modes were taken from the mega128
    datasheet and might not be applicable or correct for all devices. */

/* @{ */

/** \ingroup avr_sleep
    \def SLEEP_MODE_IDLE
    Idle mode. */
#define SLEEP_MODE_IDLE         0

/** \ingroup avr_sleep
    \def SLEEP_MODE_ADC
    ADC Noise Reduction Mode. */
#define SLEEP_MODE_ADC          SM0

/** \ingroup avr_sleep
    \def SLEEP_MODE_PWR_DOWN
    Power Down Mode. */
#define SLEEP_MODE_PWR_DOWN     SM1

/** \ingroup avr_sleep
    \def SLEEP_MODE_PWR_SAVE
    Power Save Mode. */
#define SLEEP_MODE_PWR_SAVE     (SM0 | SM1)

/** \ingroup avr_sleep
    \def SLEEP_MODE_STANDBY
    Standby Mode. */
#define SLEEP_MODE_STANDBY      (SM1 | SM2)

/** \ingroup avr_sleep
    \def SLEEP_MODE_EXT_STANDBY
    Extended Standby Mode. */
#define SLEEP_MODE_EXT_STANDBY  (SM0 | SM1 | SM2)

/* @} */

/** \name Sleep Functions */

/* @{ */

/** \ingroup avr_sleep 

    Set the bits in the \c MCUCR to select a sleep mode. */

#if defined(DOXYGEN)
extern void set_sleep_mode (uint8_t mode);
#else
#define set_sleep_mode(mode)   (MCUCR |= (mode))
#endif

/** \ingroup avr_sleep 

    Put the device in sleep mode. How the device is brought out of sleep mode
    depends on the specific mode selected with the set_sleep_mode() function.
    See the data sheet for your device for more details. */

#if defined(DOXYGEN)
extern void sleep_mode (void);
#else
#define sleep_mode() \
{                                              \
    MCUCR |= _BV(SE);                          \
    __asm__ __volatile__ ("sleep" "\n\t" :: ); \
    MCUCR &= ~_BV(SE);                         \
}
#endif

/*@}*/

#endif /* _AVR_SLEEP_H_ */
