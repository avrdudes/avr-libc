/* Copyright (c) 2006  Eric B. Weddington
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

#ifndef _AVR_POWER_H_
#define _AVR_POWER_H_   1

#include <avr/io.h>
#include <stdint.h>


/** \defgroup avr_power <avr/power.h>: Power Reduction Management

    \code #include <avr/power.h>\endcode

    Many AVRs contain a Power Reduction Register or Registers that allow you
    to reduce power consumption by disabling or enabling various on-board 
    peripherals as needed.
    
    There are several macros in this header file that provide an easy interface
    to enable or disable on-board peripherals to reduce power.
    
    \note Not all AVR devices have a Power Reduction Register (for example
    the ATmega128). On those devices, these macros are not available.

    \note Not all AVR devices contain the same peripherals (for example, the LCD
    interface), or they will be named differently (for example, USART and 
    USART0). Please consult your device's datasheet, or the header file, to 
    find out which macros are applicable to your device.
*/


/* @} */

/** \name Power Reduction Management Macros */

/* @{ */

#if defined(__DOXYGEN__)

/** \ingroup avr_power
    Enable the Analog to Digital Converter module.
*/
extern void power_adc_enable (void);

/** \ingroup avr_power
    Disable the Analog to Digital Converter module.
*/
extern void power_adc_disable (void);


/** \ingroup avr_power
    Enable the LCD module.
*/
extern void power_lcd_enable (void);

/** \ingroup avr_power
    Diable the LCD module.
*/
extern void power_lcd_disable (void);


/** \ingroup avr_power
    Enable the Power Stage Controller 0 module.
*/
extern void power_psc0_enable (void);

/** \ingroup avr_power
    Disable the Power Stage Controller 0 module.
*/
extern void power_psc0_disable (void);


/** \ingroup avr_power
    Enable the Power Stage Controller 1 module.
*/
extern void power_psc1_enable (void);

/** \ingroup avr_power
    Disable the Power Stage Controller 1 module.
*/
extern void power_psc1_disable (void);


/** \ingroup avr_power
    Enable the Power Stage Controller 2 module.
*/
extern void power_psc2_enable (void);

/** \ingroup avr_power
    Disable the Power Stage Controller 2 module.
*/
extern void power_psc2_disable (void);


/** \ingroup avr_power
    Enable the Serial Peripheral Interface module.
*/
extern void power_spi_enable (void);

/** \ingroup avr_power
    Disable the Serial Peripheral Interface module.
*/
extern void power_spi_disable (void);


/** \ingroup avr_power
    Enable the Timer 0 module.
*/
extern void power_timer0_enable (void);

/** \ingroup avr_power
    Disable the Timer 0 module.
*/
extern void power_timer0_disable (void);


/** \ingroup avr_power
    Enable the Timer 1 module.
*/
extern void power_timer1_enable (void);

/** \ingroup avr_power
    Disable the Timer 1 module.
*/
extern void power_timer1_disable (void);


/** \ingroup avr_power
    Enable the Timer 2 module.
*/
extern void power_timer2_enable (void);

/** \ingroup avr_power
    Disable the Timer 2 module.
*/
extern void power_timer2_disable (void);


/** \ingroup avr_power
    Enable the Timer 3 module.
*/
extern void power_timer3_enable (void);

/** \ingroup avr_power
    Disable the Timer 3 module.
*/
extern void power_timer3_disable (void);


/** \ingroup avr_power
    Enable the Timer 4 module.
*/
extern void power_timer4_enable (void);

/** \ingroup avr_power
    Disable the Timer 4 module.
*/
extern void power_timer4_disable (void);


/** \ingroup avr_power
    Enable the Timer 5 module.
*/
extern void power_timer5_enable (void);

/** \ingroup avr_power
    Disable the Timer 5 module.
*/
extern void power_timer5_disable (void);


/** \ingroup avr_power
    Enable the Two Wire Interface module.
*/
extern void power_twi_enable (void);

/** \ingroup avr_power
    Disable the Two Wire Interface module.
*/
extern void power_twi_disable (void);


/** \ingroup avr_power
    Enable the USART module.
*/
extern void power_usart_enable (void);

/** \ingroup avr_power
    Disable the USART module.
*/
extern void power_usart_disable (void);


/** \ingroup avr_power
    Enable the USART 0 module.
*/
extern void power_usart0_enable (void);

/** \ingroup avr_power
    Disable the USART 0 module.
*/
extern void power_usart0_disable (void);


/** \ingroup avr_power
    Enable the USART 1 module.
*/
extern void power_usart1_enable (void);

/** \ingroup avr_power
    Disable the USART 1 module.
*/
extern void power_usart1_disable (void);


/** \ingroup avr_power
    Enable the USART 2 module.
*/
extern void power_usart2_enable (void);

/** \ingroup avr_power
    Disable the USART 2 module.
*/
extern void power_usart2_disable (void);


/** \ingroup avr_power
    Enable the USART 3 module.
*/
extern void power_usart3_enable (void);

/** \ingroup avr_power
    Disable the USART 3 module.
*/
extern void power_usart3_disable (void);


/** \ingroup avr_power
    Enable the USB module.
*/
extern void power_usb_enable (void);

/** \ingroup avr_power
    Disable the USB module.
*/
extern void power_usb_disable (void);


/** \ingroup avr_power
    Enable the Universal Serial Interface module.
*/
extern void power_usi_enable (void);

/** \ingroup avr_power
    Disable the Universal Serial Interface module.
*/
extern void power_usi_disable (void);


/** \ingroup avr_power
    Enable the Voltage ADC module.
*/
extern void power_vadc_enable (void);

/** \ingroup avr_power
    Disable the Voltage ADC module.
*/
extern void power_vadc_disable (void);


/** \ingroup avr_power
    Enable all modules.
*/
extern void power_all_enable (void);

/** \ingroup avr_power
    Disable all modules.
*/
extern void power_all_disable (void);


#elif defined(__AVR_ATmega640__) \
|| defined(__AVR_ATmega1280__) \
|| defined(__AVR_ATmega1281__) \
|| defined(__AVR_ATmega2560__) \
|| defined(__AVR_ATmega2561__) 

#define power_adc_enable()      (PRR0 &= (uint8_t)~(1 << PRADC))
#define power_adc_disable()     (PRR0 |= (uint8_t)(1 << PRADC))

#define power_spi_enable()      (PRR0 &= (uint8_t)~(1 << PRSPI))
#define power_spi_disable()     (PRR0 |= (uint8_t)(1 << PRSPI))

#define power_twi_enable()      (PRR0 &= (uint8_t)~(1 << PRTWI))
#define power_twi_disable()     (PRR0 |= (uint8_t)(1 << PRTWI))

#define power_timer0_enable()   (PRR0 &= (uint8_t)~(1 << PRTIM0))
#define power_timer0_disable()  (PRR0 |= (uint8_t)(1 << PRTIM0))

#define power_timer1_enable()   (PRR0 &= (uint8_t)~(1 << PRTIM1))
#define power_timer1_disable()  (PRR0 |= (uint8_t)(1 << PRTIM1))

#define power_timer2_enable()   (PRR0 &= (uint8_t)~(1 << PRTIM2))
#define power_timer2_disable()  (PRR0 |= (uint8_t)(1 << PRTIM2))

#define power_timer3_enable()   (PRR1 &= (uint8_t)~(1 << PRTIM3))
#define power_timer3_disable()  (PRR1 |= (uint8_t)(1 << PRTIM3))

#define power_timer4_enable()   (PRR1 &= (uint8_t)~(1 << PRTIM4))
#define power_timer4_disable()  (PRR1 |= (uint8_t)(1 << PRTIM4))

#define power_timer5_enable()   (PRR1 &= (uint8_t)~(1 << PRTIM5))
#define power_timer5_disable()  (PRR1 |= (uint8_t)(1 << PRTIM5))

#define power_usart0_enable()   (PRR0 &= (uint8_t)~(1 << PRUSART0))
#define power_usart0_disable()  (PRR0 |= (uint8_t)(1 << PRUSART0))

#define power_usart1_enable()   (PRR1 &= (uint8_t)~(1 << PRUSART1))
#define power_usart1_disable()  (PRR1 |= (uint8_t)(1 << PRUSART1))

#define power_usart2_enable()   (PRR1 &= (uint8_t)~(1 << PRUSART2))
#define power_usart2_disable()  (PRR1 |= (uint8_t)(1 << PRUSART2))

#define power_usart3_enable()   (PRR1 &= (uint8_t)~(1 << PRUSART3))
#define power_usart3_disable()  (PRR1 |= (uint8_t)(1 << PRUSART3))

#define power_all_enable() \
do{ \
    PRR0 &= (uint8_t)~((1<<PRADC)|(1<<PRSPI)|(1<<PRTWI)|(1<<PRTIM0)|(1<<PRTIM1)|(1<<PRTIM2)|(1<<PRUSART0)); \
    PRR1 &= (uint8_t)~((1<<PRTIM3)|(1<<PRTIM4)|(1<<PRTIM5)|(1<<PRTIM5)|(1<<PRUSART1)|(1<<PRUSART2)|(1<<PRUSART3)); \
}while(0)

#define power_all_disable() \
do{ \
    PRR0 |= (uint8_t)((1<<PRADC)|(1<<PRSPI)|(1<<PRTWI)|(1<<PRTIM0)|(1<<PRTIM1)|(1<<PRTIM2)|(1<<PRUSART0)); \
    PRR1 |= (uint8_t)((1<<PRTIM3)|(1<<PRTIM4)|(1<<PRTIM5)|(1<<PRTIM5)|(1<<PRUSART1)|(1<<PRUSART2)|(1<<PRUSART3)); \
}while(0)


#elif defined(__AVR_AT90USB646__) \
|| defined(__AVR_AT90USB647__) \
|| defined(__AVR_AT90USB1286__) \
|| defined(__AVR_AT90USB1287__)

#define power_adc_enable()      (PRR0 &= (uint8_t)~(1 << PRADC))
#define power_adc_disable()     (PRR0 |= (uint8_t)(1 << PRADC))

#define power_spi_enable()      (PRR0 &= (uint8_t)~(1 << PRSPI))
#define power_spi_disable()     (PRR0 |= (uint8_t)(1 << PRSPI))

#define power_twi_enable()      (PRR0 &= (uint8_t)~(1 << PRTWI))
#define power_twi_disable()     (PRR0 |= (uint8_t)(1 << PRTWI))

#define power_timer0_enable()   (PRR0 &= (uint8_t)~(1 << PRTIM0))
#define power_timer0_disable()  (PRR0 |= (uint8_t)(1 << PRTIM0))

#define power_timer1_enable()   (PRR0 &= (uint8_t)~(1 << PRTIM1))
#define power_timer1_disable()  (PRR0 |= (uint8_t)(1 << PRTIM1))

#define power_timer2_enable()   (PRR0 &= (uint8_t)~(1 << PRTIM2))
#define power_timer2_disable()  (PRR0 |= (uint8_t)(1 << PRTIM2))

#define power_timer3_enable()   (PRR1 &= (uint8_t)~(1 << PRTIM3))
#define power_timer3_disable()  (PRR1 |= (uint8_t)(1 << PRTIM3))

#define power_usart1_enable()   (PRR1 &= (uint8_t)~(1 << PRUSART1))
#define power_usart1_disable()  (PRR1 |= (uint8_t)(1 << PRUSART1))

#define power_usb_enable()      (PRR1 &= (uint8_t)~(1 << PRUSB))
#define power_usb_disable()     (PRR1 |= (uint8_t)(1 << PRUSB))

#define power_all_enable() \
do{ \
    PRR0 &= (uint8_t)~((1<<PRADC)|(1<<PRSPI)|(1<<PRTWI)|(1<<PRTIM0)|(1<<PRTIM1)|(1<<PRTIM2)); \
    PRR1 &= (uint8_t)~((1<<PRTIM3)|(1<<PRUSART1)|(1<<PRUSB)); \
}while(0)

#define power_all_disable() \
do{ \
    PRR0 |= (uint8_t)((1<<PRADC)|(1<<PRSPI)|(1<<PRTWI)|(1<<PRTIM0)|(1<<PRTIM1)|(1<<PRTIM2)); \
    PRR1 |= (uint8_t)((1<<PRTIM3)|(1<<PRUSART1)|(1<<PRUSB)); \
}while(0)


#elif defined(__AVR_AT90PWM1__)

#define power_adc_enable()      (PRR &= (uint8_t)~(1 << PRADC))
#define power_adc_disable()     (PRR |= (uint8_t)(1 << PRADC))

#define power_spi_enable()      (PRR &= (uint8_t)~(1 << PRSPI))
#define power_spi_disable()     (PRR |= (uint8_t)(1 << PRSPI))

#define power_timer0_enable()   (PRR &= (uint8_t)~(1 << PRTIM0))
#define power_timer0_disable()  (PRR |= (uint8_t)(1 << PRTIM0))

#define power_timer1_enable()   (PRR &= (uint8_t)~(1 << PRTIM1))
#define power_timer1_disable()  (PRR |= (uint8_t)(1 << PRTIM1))

/* Power Stage Controller 0 */
#define power_psc0_enable()     (PRR &= (uint8_t)~(1 << PRPSC0))
#define power_psc0_disable()    (PRR |= (uint8_t)(1 << PRPSC0))

/* Power Stage Controller 1 */
#define power_psc1_enable()     (PRR &= (uint8_t)~(1 << PRPSC1))
#define power_psc1_disable()    (PRR |= (uint8_t)(1 << PRPSC1))

/* Power Stage Controller 2 */
#define power_psc2_enable()     (PRR &= (uint8_t)~(1 << PRPSC2))
#define power_psc2_disable()    (PRR |= (uint8_t)(1 << PRPSC2))

#define power_all_enable()      (PRR &= (uint8_t)~((1<<PRADC)|(1<<PRSPI)|(1<<PRTIM0)|(1<<PRTIM1)|(1<<PRPSC0)|(1<<PRPSC1)|(1<<PRPSC2)))
#define power_all_disable()     (PRR |= (uint8_t)((1<<PRADC)|(1<<PRSPI)|(1<<PRTIM0)|(1<<PRTIM1)|(1<<PRPSC0)|(1<<PRPSC1)|(1<<PRPSC2)))


#elif defined(__AVR_AT90PWM2__) \
|| defined(__AVR_AT90PWM3__)

#define power_adc_enable()      (PRR &= (uint8_t)~(1 << PRADC))
#define power_adc_disable()     (PRR |= (uint8_t)(1 << PRADC))

#define power_spi_enable()      (PRR &= (uint8_t)~(1 << PRSPI))
#define power_spi_disable()     (PRR |= (uint8_t)(1 << PRSPI))

#define power_usart_enable()    (PRR &= (uint8_t)~(1 << PRUSART))
#define power_usart_disable()   (PRR |= (uint8_t)(1 << PRUSART))

#define power_timer0_enable()   (PRR &= (uint8_t)~(1 << PRTIM0))
#define power_timer0_disable()  (PRR |= (uint8_t)(1 << PRTIM0))

#define power_timer1_enable()   (PRR &= (uint8_t)~(1 << PRTIM1))
#define power_timer1_disable()  (PRR |= (uint8_t)(1 << PRTIM1))

/* Power Stage Controller 0 */
#define power_psc0_enable()     (PRR &= (uint8_t)~(1 << PRPSC0))
#define power_psc0_disable()    (PRR |= (uint8_t)(1 << PRPSC0))

/* Power Stage Controller 1 */
#define power_psc1_enable()     (PRR &= (uint8_t)~(1 << PRPSC1))
#define power_psc1_disable()    (PRR |= (uint8_t)(1 << PRPSC1))

/* Power Stage Controller 2 */
#define power_psc2_enable()     (PRR &= (uint8_t)~(1 << PRPSC2))
#define power_psc2_disable()    (PRR |= (uint8_t)(1 << PRPSC2))

#define power_all_enable()      (PRR &= (uint8_t)~((1<<PRADC)|(1<<PRSPI)|(1<<PRUSART)|(1<<PRTIM0)|(1<<PRTIM1)|(1<<PRPSC0)|(1<<PRPSC1)|(1<<PRPSC2)))
#define power_all_disable()     (PRR |= (uint8_t)((1<<PRADC)|(1<<PRSPI)|(1<<PRUSART)|(1<<PRTIM0)|(1<<PRTIM1)|(1<<PRPSC0)|(1<<PRPSC1)|(1<<PRPSC2)))


#elif defined(__AVR_ATmega165__) \
|| defined(__AVR_ATmega165P__) \
|| defined(__AVR_ATmega325__) \
|| defined(__AVR_ATmega3250__) \
|| defined(__AVR_ATmega645__) \
|| defined(__AVR_ATmega6450__)

#define power_adc_enable()      (PRR &= (uint8_t)~(1 << PRADC))
#define power_adc_disable()     (PRR |= (uint8_t)(1 << PRADC))

#define power_spi_enable()      (PRR &= (uint8_t)~(1 << PRSPI))
#define power_spi_disable()     (PRR |= (uint8_t)(1 << PRSPI))

#define power_usart0_enable()   (PRR &= (uint8_t)~(1 << PRUSART0))
#define power_usart0_disable()  (PRR |= (uint8_t)(1 << PRUSART0))

#define power_timer1_enable()   (PRR &= (uint8_t)~(1 << PRTIM1))
#define power_timer1_disable()  (PRR |= (uint8_t)(1 << PRTIM1))

#define power_all_enable()      (PRR &= (uint8_t)~((1<<PRADC)|(1<<PRSPI)|(1<<PRUSART0)|(1<<PRTIM1)))
#define power_all_disable()     (PRR |= (uint8_t)((1<<PRADC)|(1<<PRSPI)|(1<<PRUSART0)|(1<<PRTIM1)))


#elif defined(__AVR_ATmega169__) \
|| defined(__AVR_ATmega169P__) \
|| defined(__AVR_ATmega329__) \
|| defined(__AVR_ATmega3290__) \
|| defined(__AVR_ATmega649__) \
|| defined(__AVR_ATmega6490__)

#define power_adc_enable()      (PRR &= (uint8_t)~(1 << PRADC))
#define power_adc_disable()     (PRR |= (uint8_t)(1 << PRADC))

#define power_spi_enable()      (PRR &= (uint8_t)~(1 << PRSPI))
#define power_spi_disable()     (PRR |= (uint8_t)(1 << PRSPI))

#define power_usart0_enable()   (PRR &= (uint8_t)~(1 << PRUSART0))
#define power_usart0_disable()  (PRR |= (uint8_t)(1 << PRUSART0))

#define power_timer1_enable()   (PRR &= (uint8_t)~(1 << PRTIM1))
#define power_timer1_disable()  (PRR |= (uint8_t)(1 << PRTIM1))

#define power_lcd_enable()      (PRR &= (uint8_t)~(1 << PRLCD))
#define power_lcd_disable()     (PRR |= (uint8_t)(1 << PRLCD))

#define power_all_enable()      (PRR &= (uint8_t)~((1<<PRADC)|(1<<PRSPI)|(1<<PRUSART0)|(1<<PRTIM1)|(1<<PRLCD)))
#define power_all_disable()     (PRR |= (uint8_t)((1<<PRADC)|(1<<PRSPI)|(1<<PRUSART0)|(1<<PRTIM1)|(1<<PRLCD)))


#elif defined(__AVR_ATmega164P__) \
|| defined(__AVR_ATmega324P__)

#define power_adc_enable()      (PRR0 &= (uint8_t)~(1 << PRADC))
#define power_adc_disable()     (PRR0 |= (uint8_t)(1 << PRADC))

#define power_spi_enable()      (PRR0 &= (uint8_t)~(1 << PRSPI))
#define power_spi_disable()     (PRR0 |= (uint8_t)(1 << PRSPI))

#define power_usart0_enable()   (PRR0 &= (uint8_t)~(1 << PRUSART0))
#define power_usart0_disable()  (PRR0 |= (uint8_t)(1 << PRUSART0))

#define power_usart1_enable()   (PRR0 &= (uint8_t)~(1 << PRUSART1))
#define power_usart1_disable()  (PRR0 |= (uint8_t)(1 << PRUSART1))

#define power_timer0_enable()   (PRR0 &= (uint8_t)~(1 << PRTIM0))
#define power_timer0_disable()  (PRR0 |= (uint8_t)(1 << PRTIM0))

#define power_timer1_enable()   (PRR0 &= (uint8_t)~(1 << PRTIM1))
#define power_timer1_disable()  (PRR0 |= (uint8_t)(1 << PRTIM1))

#define power_timer2_enable()   (PRR0 &= (uint8_t)~(1 << PRTIM2))
#define power_timer2_disable()  (PRR0 |= (uint8_t)(1 << PRTIM2))

#define power_twi_enable()      (PRR0 &= (uint8_t)~(1 << PRTWI))
#define power_twi_disable()     (PRR0 |= (uint8_t)(1 << PRTWI))

#define power_all_enable()      (PRR0 &= (uint8_t)~((1<<PRADC)|(1<<PRSPI)|(1<<PRUSART0)|(1<<PRUSART1)|(1<<PRTIM0)|(1<<PRTIM2)|(1<<PRTWI)))
#define power_all_disable()     (PRR0 |= (uint8_t)((1<<PRADC)|(1<<PRSPI)|(1<<PRUSART0)|(1<<PRUSART1)|(1<<PRTIM0)|(1<<PRTIM2)|(1<<PRTWI)))


#elif defined(__AVR_ATmega644__)

#define power_adc_enable()      (PRR0 &= (uint8_t)~(1 << PRADC))
#define power_adc_disable()     (PRR0 |= (uint8_t)(1 << PRADC))

#define power_spi_enable()      (PRR0 &= (uint8_t)~(1 << PRSPI))
#define power_spi_disable()     (PRR0 |= (uint8_t)(1 << PRSPI))

#define power_usart0_enable()   (PRR0 &= (uint8_t)~(1 << PRUSART0))
#define power_usart0_disable()  (PRR0 |= (uint8_t)(1 << PRUSART0))

#define power_timer0_enable()   (PRR0 &= (uint8_t)~(1 << PRTIM0))
#define power_timer0_disable()  (PRR0 |= (uint8_t)(1 << PRTIM0))

#define power_timer1_enable()   (PRR0 &= (uint8_t)~(1 << PRTIM1))
#define power_timer1_disable()  (PRR0 |= (uint8_t)(1 << PRTIM1))

#define power_timer2_enable()   (PRR0 &= (uint8_t)~(1 << PRTIM2))
#define power_timer2_disable()  (PRR0 |= (uint8_t)(1 << PRTIM2))

#define power_twi_enable()      (PRR0 &= (uint8_t)~(1 << PRTWI))
#define power_twi_disable()     (PRR0 |= (uint8_t)(1 << PRTWI))

#define power_all_enable()      (PRR0 &= (uint8_t)~((1<<PRADC)|(1<<PRSPI)|(1<<PRUSART0)|(1<<PRTIM0)|(1<<PRTIM1)|(1<<PRTIM2)|(1<<PRTWI)))
#define power_all_disable()     (PRR0 |= (uint8_t)((1<<PRADC)|(1<<PRSPI)|(1<<PRUSART0)|(1<<PRTIM0)|(1<<PRTIM1)|(1<<PRTIM2)|(1<<PRTWI)))


#elif defined(__AVR_ATmega406__)

#define power_twi_enable()      (PRR0 &= (uint8_t)~(1 << PRTWI))
#define power_twi_disable()     (PRR0 |= (uint8_t)(1 << PRTWI))

#define power_timer0_enable()   (PRR0 &= (uint8_t)~(1 << PRTIM0))
#define power_timer0_disable()  (PRR0 |= (uint8_t)(1 << PRTIM0))

#define power_timer1_enable()   (PRR0 &= (uint8_t)~(1 << PRTIM1))
#define power_timer1_disable()  (PRR0 |= (uint8_t)(1 << PRTIM1))

/* Voltage ADC */
#define power_vadc_enable()     (PRR0 &= (uint8_t)~(1 << PRVADC))
#define power_vadc_disable()    (PRR0 |= (uint8_t)(1 << PRVADC))

#define power_all_enable()      (PRR0 &= (uint8_t)~((1<<PRTWI)|(1<<PRTIM0)|(1<<PRTIM1)|(1<<PRVADC)))
#define power_all_disable()     (PRR0 |= (uint8_t)((1<<PRTWI)|(1<<PRTIM0)|(1<<PRTIM1)|(1<<PRVADC)))


#elif defined(__AVR_ATmega48__) \
|| defined(__AVR_ATmega88__) \
|| defined(__AVR_ATmega168__)

#define power_adc_enable()      (PRR &= (uint8_t)~(1 << PRADC))
#define power_adc_disable()     (PRR |= (uint8_t)(1 << PRADC))

#define power_spi_enable()      (PRR &= (uint8_t)~(1 << PRSPI))
#define power_spi_disable()     (PRR |= (uint8_t)(1 << PRSPI))

#define power_usart0_enable()   (PRR &= (uint8_t)~(1 << PRUSART0))
#define power_usart0_disable()  (PRR |= (uint8_t)(1 << PRUSART0))

#define power_timer0_enable()   (PRR &= (uint8_t)~(1 << PRTIM0))
#define power_timer0_disable()  (PRR |= (uint8_t)(1 << PRTIM0))

#define power_timer1_enable()   (PRR &= (uint8_t)~(1 << PRTIM1))
#define power_timer1_disable()  (PRR |= (uint8_t)(1 << PRTIM1))

#define power_timer2_enable()   (PRR &= (uint8_t)~(1 << PRTIM2))
#define power_timer2_disable()  (PRR |= (uint8_t)(1 << PRTIM2))

#define power_twi_enable()      (PRR &= (uint8_t)~(1 << PRTWI))
#define power_twi_disable()     (PRR |= (uint8_t)(1 << PRTWI))

#define power_all_enable()      (PRR &= (uint8_t)~((1<<PRADC)|(1<<PRSPI)|(1<<PRUSART0)|(1<<PRTIM0)|(1<<PRTIM1)|(1<<PRTIM2)|(1<<PRTWI)))
#define power_all_disable()     (PRR |= (uint8_t)((1<<PRADC)|(1<<PRSPI)|(1<<PRUSART0)|(1<<PRTIM0)|(1<<PRTIM1)|(1<<PRTIM2)|(1<<PRTWI)))


#elif defined(__AVR_ATtiny24__) \
|| defined(__AVR_ATtiny44__) \
|| defined(__AVR_ATtiny84__) \
|| defined(__AVR_ATtiny25__) \
|| defined(__AVR_ATtiny45__) \
|| defined(__AVR_ATtiny85__) \
|| defined(__AVR_ATtiny261__) \
|| defined(__AVR_ATtiny461__) \
|| defined(__AVR_ATtiny861__)

#define power_adc_enable()      (PRR &= (uint8_t)~(1 << PRADC))
#define power_adc_disable()     (PRR |= (uint8_t)(1 << PRADC))

#define power_timer0_enable()   (PRR &= (uint8_t)~(1 << PRTIM0))
#define power_timer0_disable()  (PRR |= (uint8_t)(1 << PRTIM0))

#define power_timer1_enable()   (PRR &= (uint8_t)~(1 << PRTIM1))
#define power_timer1_disable()  (PRR |= (uint8_t)(1 << PRTIM1))

/* Universal Serial Interface */
#define power_usi_enable()      (PRR &= (uint8_t)~(1 << PRUSI))
#define power_usi_disable()     (PRR |= (uint8_t)(1 << PRUSI))

#define power_all_enable()      (PRR &= (uint8_t)~((1<<PRADC)|(1<<PRTIM0)|(1<<PRTIM1)|(1<<PRUSI)))
#define power_all_disable()     (PRR |= (uint8_t)((1<<PRADC)|(1<<PRTIM0)|(1<<PRTIM1)|(1<<PRUSI)))

#endif


/*@}*/

#endif /* _AVR_POWER_H_ */
