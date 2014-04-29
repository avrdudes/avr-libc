/* Copyright (c) 2006, 2007, 2008  Eric B. Weddington
   Copyright (c) 2011 Frédéric Nadeau
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


/** \file */
/** \defgroup avr_power <avr/power.h>: Power Reduction Management

\code #include <avr/power.h>\endcode

Many AVRs contain a Power Reduction Register (PRR) or Registers (PRRx) that 
allow you to reduce power consumption by disabling or enabling various on-board 
peripherals as needed. Some devices have the XTAL Divide Control Register
(XDIV) which offer similar functionality as System Clock Prescale
Register (CLKPR).

There are many macros in this header file that provide an easy interface
to enable or disable on-board peripherals to reduce power. See the table below.

\note Not all AVR devices have a Power Reduction Register (for example
the ATmega8). On those devices without a Power Reduction Register, the
power reduction macros are not available..

\note Not all AVR devices contain the same peripherals (for example, the LCD
interface), or they will be named differently (for example, USART and 
USART0). Please consult your device's datasheet, or the header file, to 
find out which macros are applicable to your device.

\note For device using the XTAL Divide Control Register (XDIV), when prescaler
is used, Timer/Counter0 can only be used in asynchronous mode. Keep in mind
that Timer/Counter0 source shall be less than ¼th of peripheral clock.
Therefore, when using a typical 32.768 kHz crystal, one shall not scale
the clock below 131.072 kHz.

*/


/** \addtogroup avr_power

\anchor avr_powermacros
<small>
<center>
<table border="3">
  <tr>
    <td width="10%"><strong>Power Macro</strong></td>
    <td width="15%"><strong>Description</strong></td>
    <td width="75%"><strong>Applicable for device</strong></td>
  </tr>

  <tr>
    <td>power_aca_disable()</td>
    <td>Disable the Analog Comparator on PortA.</td>
    <td>ATxmega64D3, ATxmega128D3, ATxmega192D3, ATxmega256D3</td>
  </tr>

  <tr>
    <td>power_aca_enable()</td>
    <td>Enable the Analog Comparator on PortA.</td>
    <td>ATxmega64D3, ATxmega128D3, ATxmega192D3, ATxmega256D3</td>
  </tr>

  <tr>
    <td>power_adc_enable()</td>
    <td>Enable the Analog to Digital Converter module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega1284, ATmega128RFA1, ATmega2560, ATmega2561, AT90USB646, AT90USB647, AT90USB1286, AT90USB1287, AT90PWM1, AT90PWM2, AT90PWM2B, AT90PWM3, AT90PWM3B, AT90PWM216, AT90PWM316, AT90PWM81, ATmega165, ATmega165P, ATmega325, ATmega325A, ATmega325PA, ATmega3250, ATmega3250A, ATmega3250PA, ATmega645, ATmega6450, ATmega169, ATmega169P, ATmega329, ATmega329A, ATmega3290, ATmega3290A, ATmega3290PA, ATmega649, ATmega6490, ATmega164P, ATmega324P, ATmega644, ATmega48, ATmega88, ATmega168, ATtiny24, ATtiny44, ATtiny84, ATtiny84A, ATtiny25, ATtiny45, ATtiny85, ATtiny261, ATtiny461, ATtiny861, ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2, ATxmega16A4U, ATxmega32A4U</td>
  </tr>

  <tr>
    <td>power_adc_disable()</td>
    <td>Disable the Analog to Digital Converter module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega1284, ATmega128RFA1, ATmega2560, ATmega2561, AT90USB646, AT90USB647, AT90USB1286, AT90USB1287, AT90PWM1, AT90PWM2, AT90PWM2B, AT90PWM3, AT90PWM3B, AT90PWM216, AT90PWM316, AT90PWM81, ATmega165, ATmega165P, ATmega325, ATmega325A, ATmega325PA, ATmega3250, ATmega3250A, ATmega645, ATmega6450, ATmega169, ATmega169P, ATmega329, ATmega329A, ATmega3290, ATmega3290A, ATmega3290PA, ATmega649, ATmega6490, ATmega164P, ATmega324P, ATmega644, ATmega48, ATmega88, ATmega168, ATtiny24, ATtiny44, ATtiny84, ATtiny84A, ATtiny25, ATtiny45, ATtiny85, ATtiny261, ATtiny461, ATtiny861, ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2, ATxmega16A4U, ATxmega32A4U</td>
  </tr>

  <tr>
    <td>power_adca_disable()</td>
    <td>Disable the Analog to Digital Converter module on PortA</td>
    <td>ATxmega64D3, ATxmega128D3, ATxmega192D3, ATxmega256D3</td>
  </tr>

  <tr>
    <td>power_adca_enable()</td>
    <td>Enable the Analog to Digital Converter module on PortA</td>
    <td>ATxmega64D3, ATxmega128D3, ATxmega192D3, ATxmega256D3</td>
  </tr>

  <tr>
    <td>power_evsys_disable()</td>
    <td>Disable the EVSYS module</td>
    <td>ATxmega64D3, ATxmega128D3, ATxmega192D3, ATxmega256D3</td>
  </tr>

  <tr>
    <td>power_evsys_enable()</td>
    <td>Enable the EVSYS module</td>
    <td>ATxmega64D3, ATxmega128D3, ATxmega192D3, ATxmega256D3</td>
  </tr>

  <tr>
    <td>power_hiresc_disable()</td>
    <td>Disable the HIRES module on PortC</td>
    <td>ATxmega64D3, ATxmega128D3, ATxmega192D3, ATxmega256D3</td>
  </tr>

  <tr>
    <td>power_hiresc_enable()</td>
    <td>Enable the HIRES module on PortC</td>
    <td>ATxmega64D3, ATxmega128D3, ATxmega192D3, ATxmega256D3</td>
  </tr>

   <tr>
    <td>power_lcd_enable()</td>
    <td>Enable the LCD module.</td>
    <td>ATmega169, ATmega169P, ATmega329, ATmega329A, ATmega3290, ATmega3290A, ATmega649, ATmega6490, ATxmega64B1, ATxmega64B3, ATxmega128B3</td>
  </tr>

  <tr>
    <td>power_lcd_disable().</td>
    <td>Disable the LCD module.</td>
    <td>ATmega169, ATmega169P, ATmega329, ATmega329A, ATmega3290, ATmega3290A, ATmega649, ATmega6490, ATxmega64B1, ATxmega128B1, ATxmega64B3, ATxmega128B3</td>
  </tr>

  <tr>
    <td>power_pga_enable()</td>
    <td>Enable the Programmable Gain Amplifier module.</td>
    <td> ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2</td>
  </tr>

  <tr>
    <td>power_pga_disable()</td>
    <td>Disable the Programmable Gain Amplifier module.</td>
    <td> ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2</td>
  </tr>
  
  <tr>
    <td>power_pscr_enable()</td>
    <td>Enable the Reduced Power Stage Controller module.</td>
    <td>AT90PWM81</td>
  </tr>

  <tr>
    <td>power_pscr_disable()</td>
    <td>Disable the Reduced Power Stage Controller module.</td>
    <td>AT90PWM81</td>
  </tr>

  <tr>
    <td>power_psc0_enable()</td>
    <td>Enable the Power Stage Controller 0 module.</td>
    <td>AT90PWM1, AT90PWM2, AT90PWM2B, AT90PWM3, AT90PWM3B</td>
  </tr>

  <tr>
    <td>power_psc0_disable()</td>
    <td>Disable the Power Stage Controller 0 module.</td>
    <td>AT90PWM1, AT90PWM2, AT90PWM2B, AT90PWM3, AT90PWM3B</td>
  </tr>

  <tr>
    <td>power_psc1_enable()</td>
    <td>Enable the Power Stage Controller 1 module.</td>
    <td>AT90PWM1, AT90PWM2, AT90PWM2B, AT90PWM3, AT90PWM3B</td>
  </tr>

  <tr>
    <td>power_psc1_disable()</td>
    <td>Disable the Power Stage Controller 1 module.</td>
    <td>AT90PWM1, AT90PWM2, AT90PWM2B, AT90PWM3, AT90PWM3B</td>
  </tr>

  <tr>
    <td>power_psc2_enable()</td>
    <td>Enable the Power Stage Controller 2 module.</td>
    <td>AT90PWM1, AT90PWM2, AT90PWM2B, AT90PWM3, AT90PWM3B, AT90PWM81</td>
  </tr>

  <tr>
    <td>power_psc2_disable()</td>
    <td>Disable the Power Stage Controller 2 module.</td>
    <td>AT90PWM1, AT90PWM2, AT90PWM2B, AT90PWM3, AT90PWM3B, AT90PWM81</td>
  </tr>

  <tr>
    <td>power_ram0_enable()</td>
    <td>Enable the SRAM block 0 .</td>
    <td> ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2</td>
  </tr>

  <tr>
    <td>power_ram0_disable()</td>
    <td>Disable the SRAM block 0. </td>
    <td> ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2</td>
  </tr>

  <tr>
    <td>power_ram1_enable()</td>
    <td>Enable the SRAM block 1 .</td>
    <td> ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2</td>
  </tr>

  <tr>
    <td>power_ram1_disable()</td>
    <td>Disable the SRAM block 1. </td>
    <td> ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2</td>
  </tr>

  <tr>
    <td>power_ram2_enable()</td>
    <td>Enable the SRAM block 2 .</td>
    <td> ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2</td>
  </tr>

  <tr>
    <td>power_ram2_disable()</td>
    <td>Disable the SRAM block 2. </td>
    <td> ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2</td>
  </tr>

  <tr>
    <td>power_ram3_enable()</td>
    <td>Enable the SRAM block 3 .</td>
    <td> ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2</td>
  </tr>

  <tr>
    <td>power_ram3_disable()</td>
    <td>Disable the SRAM block 3. </td>
    <td> ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2</td>
  </tr>

  <tr>
    <td>power_rtc_disable()</td>
    <td>Disable the RTC module</td>
    <td>ATxmega64D3, ATxmega128D3, ATxmega192D3, ATxmega256D3</td>
  </tr>

  <tr>
    <td>power_rtc_enable()</td>
    <td>Enable the RTC module</td>
    <td>ATxmega64D3, ATxmega128D3, ATxmega192D3, ATxmega256D3</td>
  </tr>

  <tr>
    <td>power_spi_enable()</td>
    <td>Enable the Serial Peripheral Interface module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega1284, ATmega128RFA1, ATmega2560, ATmega2561, AT90USB646, AT90USB647, AT90USB1286, AT90USB1287, AT90PWM1, AT90PWM2, AT90PWM2B, AT90PWM3, AT90PWM3B, AT90PWM216, AT90PWM316, AT90PWM81, ATmega165, ATmega165P, ATmega325, ATmega325A, ATmega325PA, ATmega3250, ATmega3250A, ATmega3250PA, ATmega645, ATmega6450, ATmega169, ATmega169P, ATmega329, ATmega329A, ATmega3290, ATmega3290A, ATmega3290PA, ATmega649, ATmega6490, ATmega164P, ATmega324P, ATmega644, ATmega48, ATmega88, ATmega168, ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2, ATxmega16A4U, ATxmega32A4U</td>
  </tr>

  <tr>
    <td>power_spi_disable()</td>
    <td>Disable the Serial Peripheral Interface module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega1284, ATmega128RFA1, ATmega2560, ATmega2561, AT90USB646, AT90USB647, AT90USB1286, AT90USB1287, AT90PWM1, AT90PWM2, AT90PWM2B, AT90PWM3, AT90PWM3B, AT90PWM216, AT90PWM316, AT90PWM81, ATmega165, ATmega165P, ATmega325, ATmega325A, ATmega325PA, ATmega3250, ATmega3250A, ATmega3250PA, ATmega645, ATmega6450, ATmega169, ATmega169P, ATmega329, ATmega329A, ATmega3290, ATmega3290A, ATmega3290PA, ATmega649, ATmega6490, ATmega164P, ATmega324P, ATmega644, ATmega48, ATmega88, ATmega168, ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2, ATxmega16A4U, ATxmega32A4U</td>
  </tr>

  <tr>
    <td>power_spic_disable()</td>
    <td>Disable the SPI module on PortC</td>
    <td>ATxmega64D3, ATxmega128D3, ATxmega192D3, ATxmega256D3</td>
  </tr>

  <tr>
    <td>power_spic_enable()</td>
    <td>Enable the SPI module on PortC</td>
    <td>ATxmega64D3, ATxmega128D3, ATxmega192D3, ATxmega256D3</td>
  </tr>

  <tr>
    <td>power_spid_disable()</td>
    <td>Disable the SPI module on PortD</td>
    <td>ATxmega64D3, ATxmega128D3, ATxmega192D3, ATxmega256D3</td>
  </tr>

  <tr>
    <td>power_spid_enable()</td>
    <td>Enable the SPI module on PortD</td>
    <td>ATxmega64D3, ATxmega128D3, ATxmega192D3, ATxmega256D3</td>
  </tr>

  <tr>
    <td>power_tc0c_disable()</td>
    <td>Disable the TC0 module on PortC</td>
    <td>ATxmega64D3, ATxmega128D3, ATxmega192D3, ATxmega256D3</td>
  </tr>

  <tr>
    <td>power_tc0c_enable()</td>
    <td>Enable the TC0 module on PortC</td>
    <td>ATxmega64D3, ATxmega128D3, ATxmega192D3, ATxmega256D3</td>
  </tr>

  <tr>
    <td>power_tc0d_disable()</td>
    <td>Disable the TC0 module on PortD</td>
    <td>ATxmega64D3, ATxmega128D3, ATxmega192D3, ATxmega256D3</td>
  </tr>

  <tr>
    <td>power_tc0d_enable()</td>
    <td>Enable the TC0 module on PortD</td>
    <td>ATxmega64D3, ATxmega128D3, ATxmega192D3, ATxmega256D3</td>
  </tr>

  <tr>
    <td>power_tc0e_disable()</td>
    <td>Disable the TC0 module on PortE</td>
    <td>ATxmega64D3, ATxmega128D3, ATxmega192D3, ATxmega256D3</td>
  </tr>

  <tr>
    <td>power_tc0e_enable()</td>
    <td>Enable the TC0 module on PortE</td>
    <td>ATxmega64D3, ATxmega128D3, ATxmega192D3, ATxmega256D3</td>
  </tr>

  <tr>
    <td>power_tc0f_disable()</td>
    <td>Disable the TC0 module on PortF</td>
    <td>ATxmega64D3, ATxmega128D3, ATxmega192D3, ATxmega256D3</td>
  </tr>

  <tr>
    <td>power_tc0f_enable()</td>
    <td>Enable the TC0 module on PortF</td>
    <td>ATxmega64D3, ATxmega128D3, ATxmega192D3, ATxmega256D3</td>
  </tr>

  <tr>
    <td>power_tc1c_disable()</td>
    <td>Disable the TC1 module on PortC</td>
    <td>ATxmega64D3, ATxmega128D3, ATxmega192D3, ATxmega256D3</td>
  </tr>

  <tr>
    <td>power_tc1c_enable()</td>
    <td>Enable the TC1 module on PortC</td>
    <td>ATxmega64D3, ATxmega128D3, ATxmega192D3, ATxmega256D3</td>
  </tr>

  <tr>
    <td>power_twic_disable()</td>
    <td>Disable the Two Wire Interface module on PortC</td>
    <td>ATxmega64D3, ATxmega128D3, ATxmega192D3, ATxmega256D3</td>
  </tr>

  <tr>
    <td>power_twic_enable()</td>
    <td>Enable the Two Wire Interface module on PortC</td>
    <td>ATxmega64D3, ATxmega128D3, ATxmega192D3, ATxmega256D3</td>
  </tr>

  <tr>
    <td>power_twie_disable()</td>
    <td>Disable the Two Wire Interface module on PortE</td>
    <td>ATxmega64D3, ATxmega128D3, ATxmega192D3, ATxmega256D3</td>
  </tr>

  <tr>
    <td>power_twie_enable()</td>
    <td>Enable the Two Wire Interface module on PortE</td>
    <td>ATxmega64D3, ATxmega128D3, ATxmega192D3, ATxmega256D3</td>
  </tr>

  <tr>
    <td>power_timer0_enable()</td>
    <td>Enable the Timer 0 module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega1284, ATmega128RFA1, ATmega2560, ATmega2561, AT90USB646, AT90USB647, AT90USB1286, AT90USB1287, AT90PWM1, AT90PWM216, AT90PWM316, AT90PWM2, AT90PWM2B, AT90PWM3, AT90PWM3B, ATmega165, ATmega165P, ATmega325, ATmega325A, ATmega3250, ATmega3250A, ATmega645, ATmega6450, ATmega164P, ATmega324P, ATmega644, ATmega406, ATmega48, ATmega88, ATmega168, ATtiny24, ATtiny44, ATtiny84, ATtiny84A, ATtiny25, ATtiny45, ATtiny85, ATtiny261, ATtiny461, ATtiny861, ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2, ATxmega16A4U, ATxmega32A4U</td>
  </tr>

  <tr>
    <td>power_timer0_disable()</td>
    <td>Disable the Timer 0 module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega1284, ATmega128RFA1, ATmega2560, ATmega2561, AT90USB646, AT90USB647, AT90USB1286, AT90USB1287, AT90PWM1, AT90PWM2, AT90PWM2B, AT90PWM3, AT90PWM3B, AT90PWM216, AT90PWM316, ATmega165, ATmega165P, ATmega325, ATmega325A, ATmega3250, ATmega3250A, ATmega645, ATmega6450, ATmega164P, ATmega324P, ATmega644, ATmega406, ATmega48, ATmega88, ATmega168, ATtiny24, ATtiny44, ATtiny84, ATtiny84A, ATtiny25, ATtiny45, ATtiny85, ATtiny261, ATtiny461, ATtiny861, ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2, ATxmega16A4U, ATxmega32A4U</td>
  </tr>

  <tr>
    <td>power_timer1_enable()</td>
    <td>Enable the Timer 1 module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega1284, ATmega128RFA1, ATmega2560, ATmega2561, AT90USB646, AT90USB647, AT90USB1286, AT90USB1287, AT90PWM1, AT90PWM2, AT90PWM2B, AT90PWM3, AT90PWM3B, AT90PWM216, AT90PWM316, AT90PWM81, ATmega165, ATmega165P, ATmega325, ATmega325A, ATmega325PA, ATmega3250, ATmega3250A, ATmega3250PA, ATmega645, ATmega6450, ATmega169, ATmega169P, ATmega329, ATmega329A, ATmega3290, ATmega3290A, ATmega3290PA, ATmega649, ATmega6490, ATmega164P, ATmega324P, ATmega644, ATmega406, ATmega48, ATmega88, ATmega168, ATtiny24, ATtiny44, ATtiny84, ATtiny84A, ATtiny25, ATtiny45, ATtiny85, ATtiny261, ATtiny461, ATtiny861, ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2, ATxmega16A4U, ATxmega32A4U</td>
  </tr>

  <tr>
    <td>power_timer1_disable()</td>
    <td>Disable the Timer 1 module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega1284, ATmega128RFA1, ATmega2560, ATmega2561, AT90USB646, AT90USB647, AT90USB1286, AT90USB1287, AT90PWM1, AT90PWM2, AT90PWM2B, AT90PWM3, AT90PWM3B, AT90PWM216, AT90PWM316, AT90PWM81, ATmega165, ATmega165P, ATmega325, ATmega325A, ATmega325PA, ATmega3250, ATmega3250A, ATmega3250PA, ATmega645, ATmega6450, ATmega169, ATmega169P, ATmega329, ATmega329A, ATmega3290, ATmega3290A, ATmega3290PA, ATmega649, ATmega6490, ATmega164P, ATmega324P, ATmega644, ATmega406, ATmega48, ATmega88, ATmega168, ATtiny24, ATtiny44, ATtiny84, ATtiny84A, ATtiny25, ATtiny45, ATtiny85, ATtiny261, ATtiny461, ATtiny861, ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2, ATxmega16A4U, ATxmega32A4U</td>
  </tr>

  <tr>
    <td>power_timer2_enable()</td>
    <td>Enable the Timer 2 module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega1284, ATmega128RFA1, ATmega2560, ATmega2561, AT90USB646, AT90USB647, AT90USB1286, AT90USB1287, ATmega164P, ATmega324P, ATmega644, ATmega48, ATmega88, ATmega168, ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2</td>
  </tr>

  <tr>
    <td>power_timer2_disable()</td>
    <td>Disable the Timer 2 module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega1284, ATmega128RFA1, ATmega2560, ATmega2561, AT90USB646, AT90USB647, AT90USB1286, AT90USB1287, ATmega164P, ATmega324P, ATmega644, ATmega48, ATmega88, ATmega168, ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2</td>
  </tr>

  <tr>
    <td>power_timer3_enable()</td>
    <td>Enable the Timer 3 module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega1284, ATmega128RFA1, ATmega2560, ATmega2561, AT90USB646, AT90USB647, AT90USB1286, AT90USB1287, ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2</td>
  </tr>

  <tr>
    <td>power_timer3_disable()</td>
    <td>Disable the Timer 3 module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega1284, ATmega128RFA1, ATmega2560, ATmega2561, AT90USB646, AT90USB647, AT90USB1286, AT90USB1287, ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2</td>
  </tr>

  <tr>
    <td>power_timer4_enable()</td>
    <td>Enable the Timer 4 module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega128RFA1, ATmega2560, ATmega2561, ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2</td>
  </tr>

  <tr>
    <td>power_timer4_disable()</td>
    <td>Disable the Timer 4 module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega128RFA1, ATmega2560, ATmega2561, ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2</td>
  </tr>

  <tr>
    <td>power_timer5_enable()</td>
    <td>Enable the Timer 5 module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega128RFA1, ATmega2560, ATmega2561, ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2</td>
  </tr>

  <tr>
    <td>power_timer5_disable()</td>
    <td>Disable the Timer 5 module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega128RFA1, ATmega2560, ATmega2561, ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2</td>
  </tr>

  <tr>
    <td>power_twi_enable()</td>
    <td>Enable the Two Wire Interface module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega1284, ATmega128RFA1, ATmega2560, ATmega2561, AT90USB646, AT90USB647, AT90USB1286, AT90USB1287, ATmega164P, ATmega324P, ATmega644, ATmega406, ATmega48, ATmega88, ATmega168, ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2, ATxmega16A4U, ATxmega32A4U</td>
  </tr>

  <tr>
    <td>power_twi_disable()</td>
    <td>Disable the Two Wire Interface module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega1284, ATmega128RFA1, ATmega2560, ATmega2561, AT90USB646, AT90USB647, AT90USB1286, AT90USB1287, ATmega164P, ATmega324P, ATmega644, ATmega406, ATmega48, ATmega88, ATmega168, ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2, ATxmega16A4U, ATxmega32A4U</td>
  </tr>

  <tr>
    <td>power_usart_enable()</td>
    <td>Enable the USART module.</td>
    <td>AT90PWM2, AT90PWM2B, AT90PWM3, AT90PWM3B</td>
  </tr>

  <tr>
    <td>power_usart_disable()</td>
    <td>Disable the USART module.</td>
    <td>AT90PWM2, AT90PWM2B, AT90PWM3, AT90PWM3B</td>
  </tr>

  <tr>
    <td>power_usart0_enable()</td>
    <td>Enable the USART 0 module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega1284, ATmega128RFA1, ATmega2560, ATmega2561, ATmega165, ATmega165P, ATmega325, ATmega325A, ATmega325PA, ATmega3250, ATmega3250A, ATmega3250PA, ATmega645, ATmega6450, ATmega169, ATmega169P, ATmega329, ATmega329A, ATmega3290, ATmega3290A, ATmega3290PA, ATmega649, ATmega6490, ATmega164P, ATmega324P, ATmega644, ATmega48, ATmega88, ATmega168, ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2, ATxmega16A4U, ATxmega32A4U</td>
  </tr>

  <tr>
    <td>power_usart0_disable()</td>
    <td>Disable the USART 0 module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega1284, ATmega128RFA1, ATmega2560, ATmega2561, ATmega165, ATmega165P, ATmega325, ATmega325A, ATmega325PA, ATmega3250, ATmega3250A, ATmega3250PA, ATmega645, ATmega6450, ATmega169, ATmega169P, ATmega329, ATmega329A, ATmega3290, ATmega3290A, ATmega3290PA, ATmega649, ATmega6490, ATmega164P, ATmega324P, ATmega644, ATmega48, ATmega88, ATmega168, ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2, ATxmega16A4U, ATxmega32A4U</td>
  </tr>

  <tr>
    <td>power_usart1_enable()</td>
    <td>Enable the USART 1 module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega128RFA1, ATmega2560, ATmega2561, AT90USB646, AT90USB647, AT90USB1286, AT90USB1287, ATmega164P, ATmega324P, ATmega644, ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2, ATxmega16A4U, ATxmega32A4U</td>
  </tr>

  <tr>
    <td>power_usart1_disable()</td>
    <td>Disable the USART 1 module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega128RFA1, ATmega2560, ATmega2561, AT90USB646, AT90USB647, AT90USB1286, AT90USB1287, ATmega164P, ATmega324P, ATmega644, ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2, ATxmega16A4U, ATxmega32A4U</td>
  </tr>

  <tr>
    <td>power_usart2_enable()</td>
    <td>Enable the USART 2 module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega2560, ATmega2561</td>
  </tr>

  <tr>
    <td>power_usart2_disable()</td>
    <td>Disable the USART 2 module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega2560, ATmega2561</td>
  </tr>

  <tr>
    <td>power_usart3_enable()</td>
    <td>Enable the USART 3 module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega2560, ATmega2561</td>
  </tr>

  <tr>
    <td>power_usart3_disable()</td>
    <td>Disable the USART 3 module.</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega2560, ATmega2561</td>
  </tr>

  <tr>
    <td>power_usartc0_disable()</td>
    <td> Disable the USART0 module on PortC</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega2560, ATmega2561</td>
  </tr>

  <tr>
    <td>power_usartc0_enable()</td>
    <td> Enable the USART0 module on PortC</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega2560, ATmega2561</td>
  </tr>

  <tr>
    <td>power_usartd0_disable()</td>
    <td> Disable the USART0 module on PortD</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega2560, ATmega2561</td>
  </tr>

  <tr>
    <td>power_usartd0_enable()</td>
    <td> Enable the USART0 module on PortD</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega2560, ATmega2561</td>
  </tr>

  <tr>
    <td>power_usarte0_disable()</td>
    <td> Disable the USART0 module on PortE</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega2560, ATmega2561</td>
  </tr>

  <tr>
    <td>power_usarte0_enable()</td>
    <td> Enable the USART0 module on PortE</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega2560, ATmega2561</td>
  </tr>

  <tr>
    <td>power_usartf0_disable()</td>
    <td> Disable the USART0 module on PortF</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega2560, ATmega2561</td>
  </tr>

  <tr>
    <td>power_usartf0_enable()</td>
    <td> Enable the USART0 module on PortF</td>
    <td>ATmega640, ATmega1280, ATmega1281, ATmega2560, ATmega2561</td>
  </tr>

  <tr>
    <td>power_usb_enable()</td>
    <td>Enable the USB module.</td>
    <td>AT90USB646, AT90USB647, AT90USB1286, AT90USB1287, ATxmega64B1, ATxmega128B1, ATxmega64B3, ATxmega128B3, ATxmega16A4U, ATxmega32A4U, ATxmega128c3, ATxmega256c3, ATxmega16c4, ATxmega32c4</td>
  </tr>

  <tr>
    <td>power_usb_disable()</td>
    <td>Disable the USB module.</td>
    <td>AT90USB646, AT90USB647, AT90USB1286, AT90USB1287, ATxmega64B1, ATxmega128B1, ATxmega64B3, ATxmega128B3, ATxmega16A4U, ATxmega32A4U,ATxmega128c3, ATxmega256c3, ATxmega16c4, ATxmega32c4</td>
  </tr>

  <tr>
    <td>power_usi_enable()</td>
    <td>Enable the Universal Serial Interface module.</td>
    <td>ATtiny24, ATtiny44, ATtiny84, ATtiny84A, ATtiny25, ATtiny45, ATtiny85, ATtiny261, ATtiny461, ATtiny861</td>
  </tr>

  <tr>
    <td>power_usi_disable()</td>
    <td>Disable the Universal Serial Interface module.</td>
    <td>ATtiny24, ATtiny44, ATtiny84, ATtiny84A, ATtiny25, ATtiny45, ATtiny85, ATtiny261, ATtiny461, ATtiny861</td>
  </tr>

  <tr>
    <td>power_vadc_enable()</td>
    <td>Enable the Voltage ADC module.</td>
    <td>ATmega406</td>
  </tr>

  <tr>
    <td>power_vadc_disable()</td>
    <td>Disable the Voltage ADC module.</td>
    <td>ATmega406</td>
  </tr>

  <tr>
    <td>power_all_enable()</td>
    <td>Enable all modules.</td>
    <td>ATxmega6A4, ATxmega32A4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmegaA1, ATxmegaA1U, ATxmega128A3, ATxmega192A3, ATxmega256A3, ATxmegaA3B, ATxmega16D4, ATxmega32D4, ATxmega64D3, ATxmega128D3, ATxmega192D3, ATxmega256D3, ATmega640, ATmega1280, ATmega1281, ATmega128RFA1, ATmega2560, ATmega2561, AT90USB646, AT90USB647, AT90USB1286, AT90USB1287, AT90PWM1, AT90PWM2, AT90PWM2B, AT90PWM3, AT90PWM3B, AT90PWM216, AT90PWM316, ATmega165, ATmega165P, ATmega325, ATmega325A, ATmega325PA, ATmega3250, ATmega3250A, ATmega3250PA, ATmega645, ATmega6450, ATmega169, ATmega169P, ATmega329, ATmega329A, ATmega3290, ATmega3290A, ATmega3290PA, ATmega649, ATmega6490, ATmega164P, ATmega324P, ATmega644, ATmega406, ATmega48, ATmega88, ATmega168, ATtiny24, ATtiny44, ATtiny84, ATtiny84A, ATtiny25, ATtiny45, ATtiny85, ATtiny261, ATtiny461, ATtiny861, ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2, ATxmega64B1, ATxmega128B1, ATxmega64B3, ATxmega128B3, ATxmega16A4U, ATxmega32A4U, ATxmega64A3U, ATxmega128A3U, ATxmega192A3U, ATxmega256A3U</td>
  </tr>

  <tr>
    <td>power_all_disable()</td>
    <td>Disable all modules.</td>
    <td>ATxmega6A4, ATxmega32A4, ATxmega64A1, ATxmega64A1U, ATxmega64A3, ATxmegaA1, ATxmegaA1U, ATxmega128A3, ATxmega192A3, ATxmega256A3, ATxmegaA3B, ATxmega16D4, ATxmega32D4, ATxmega64D3, ATxmega128D3, ATxmega192D3, ATxmega256D3, ATmega640, ATmega1280, ATmega1281, ATmega128RFA1, ATmega2560, ATmega2561, AT90USB646, AT90USB647, AT90USB1286, AT90USB1287, AT90PWM1, AT90PWM2, AT90PWM2B, AT90PWM3, AT90PWM3B, AT90PWM216, AT90PWM316, ATmega165, ATmega165P, ATmega325, ATmega325A, ATmega325PA, ATmega3250, ATmega3250A, ATmega3250PA, ATmega645, ATmega6450, ATmega169, ATmega169P, ATmega329, ATmega329A, ATmega3290, ATmega3290A, ATmega3290PA, ATmega649, ATmega6490, ATmega164P, ATmega324P, ATmega644, ATmega406, ATmega48, ATmega88, ATmega168, ATtiny24, ATtiny44, ATtiny84, ATtiny84A, ATtiny25, ATtiny45, ATtiny85, ATtiny261, ATtiny461, ATtiny861, ATmega256RFR2, ATmega2564RFR2, ATmega128RFR2, ATmega1284RFR2, ATmega64RFR2, ATmega644RFR2, ATxmega64B1, ATxmega128B1, ATxmega64B3, ATxmega128B3, ATxmega16A4U, ATxmega32A4U, ATxmega64A3U, ATxmega128A3U, ATxmega192A3U, ATxmega256A3U</td>
  </tr>
</table>
</center>
</small>

@} */

// Xmega A series has AES, EBI and DMA bits
// Include any other device on need basis
#if defined(__AVR_ATxmega16A4__) \
|| defined(__AVR_ATxmega16A4U__) \
|| defined(__AVR_ATxmega32A4U__) \
|| defined(__AVR_ATxmega32A4__) \
|| defined(__AVR_ATxmega64A1__) \
|| defined(__AVR_ATxmega64A1U__) \
|| defined(__AVR_ATxmega64A3__) \
|| defined(__AVR_ATxmega64A3U__) \
|| defined(__AVR_ATxmega64A4U__) \
|| defined(__AVR_ATxmega128A1__) \
|| defined(__AVR_ATxmega128A1U__) \
|| defined(__AVR_ATxmega128A3__) \
|| defined(__AVR_ATxmega128A3U__) \
|| defined(__AVR_ATxmega128A4U__) \
|| defined(__AVR_ATxmega192A3__) \
|| defined(__AVR_ATxmega192A3U__) \
|| defined(__AVR_ATxmega256A3__) \
|| defined(__AVR_ATxmega256A3U__) \
|| defined(__AVR_ATxmega256A3B__) \
|| defined(__AVR_ATxmega256A3BU__) \
|| defined(__AVR_ATxmega384C3__)


#define power_aes_enable()  (PR_PRGEN &= (uint8_t)~(PR_AES_bm))
#define power_aes_disable() (PR_PRGEN |= (uint8_t)PR_AES_bm)

#define power_ebi_enable()  (PR_PRGEN &= (uint8_t)~(PR_EBI_bm))
#define power_ebi_disable() (PR_PRGEN |= (uint8_t)PR_EBI_bm)

#define power_dma_enable()    (PR_PRGEN &= (uint8_t)~(PR_DMA_bm))
#define power_dma_disable()   (PR_PRGEN |= (uint8_t)PR_DMA_bm)

#define power_daca_enable()     (PR_PRPA &= (uint8_t)~(PR_DAC_bm))
#define power_daca_disable()    (PR_PRPA |= (uint8_t)PR_DAC_bm)
#define power_dacb_enable()     (PR_PRPB &= (uint8_t)~(PR_DAC_bm))
#define power_dacb_disable()    (PR_PRPB |= (uint8_t)PR_DAC_bm)

#define power_usartc1_enable()  (PR_PRPC &= (uint8_t)~(PR_USART1_bm))
#define power_usartc1_disable() (PR_PRPC |= (uint8_t)PR_USART1_bm)
#define power_usartd1_enable()  (PR_PRPD &= (uint8_t)~(PR_USART1_bm))
#define power_usartd1_disable() (PR_PRPD |= (uint8_t)PR_USART1_bm)
#define power_usarte1_enable()  (PR_PRPE &= (uint8_t)~(PR_USART1_bm))
#define power_usarte1_disable() (PR_PRPE |= (uint8_t)PR_USART1_bm)
#define power_usartf1_enable()  (PR_PRPF &= (uint8_t)~(PR_USART1_bm))
#define power_usartf1_disable() (PR_PRPF |= (uint8_t)PR_USART1_bm)

#if defined(__AVR_ATxmega384C3__) \
|| defined(__AVR_ATxmega256A3BU__) \
|| defined(__AVR_ATxmega16A4U__) \
|| defined(__AVR_ATxmega32A4U__) \
|| defined(__AVR_ATxmega64A3U__) \
|| defined(__AVR_ATxmega64A4U__) \
|| defined(__AVR_ATxmega128A3U__) \
|| defined(__AVR_ATxmega128A4U__) \
|| defined(__AVR_ATxmega192A3U__) \
|| defined(__AVR_ATxmega256A3U__) 

#define power_usb_enable()   (PR_PRGEN &= (uint8_t)~(PR_USB_bm))
#define power_usb_disable()  (PR_PRGEN &= (uint8_t)(PR_USB_bm))

#define power_all_enable() \
do { \
    PR_PRGEN &= (uint8_t)~(PR_AES_bm|PR_EBI_bm|PR_RTC_bm|PR_EVSYS_bm|PR_DMA_bm|PR_USB_bm); \
    PR_PRPA &= (uint8_t)~(PR_DAC_bm|PR_ADC_bm|PR_AC_bm); \
    PR_PRPB &= (uint8_t)~(PR_DAC_bm|PR_ADC_bm|PR_AC_bm); \
    PR_PRPC &= (uint8_t)~(PR_TWI_bm|PR_USART1_bm|PR_USART0_bm|PR_SPI_bm|PR_HIRES_bm|PR_TC1_bm|PR_TC0_bm); \
    PR_PRPD &= (uint8_t)~(PR_TWI_bm|PR_USART1_bm|PR_USART0_bm|PR_SPI_bm|PR_HIRES_bm|PR_TC1_bm|PR_TC0_bm); \
    PR_PRPE &= (uint8_t)~(PR_TWI_bm|PR_USART1_bm|PR_USART0_bm|PR_SPI_bm|PR_HIRES_bm|PR_TC1_bm|PR_TC0_bm); \
    PR_PRPF &= (uint8_t)~(PR_TWI_bm|PR_USART1_bm|PR_USART0_bm|PR_SPI_bm|PR_HIRES_bm|PR_TC1_bm|PR_TC0_bm); \
} while(0)

#define power_all_disable() \
do { \
    PR_PRGEN |= (uint8_t)(PR_AES_bm|PR_EBI_bm|PR_RTC_bm|PR_EVSYS_bm|PR_DMA_bm|PR_USB_bm); \
    PR_PRPA |= (uint8_t)(PR_DAC_bm|PR_ADC_bm|PR_AC_bm); \
    PR_PRPB |= (uint8_t)(PR_DAC_bm|PR_ADC_bm|PR_AC_bm); \
    PR_PRPC |= (uint8_t)(PR_TWI_bm|PR_USART1_bm|PR_USART0_bm|PR_SPI_bm|PR_HIRES_bm|PR_TC1_bm|PR_TC0_bm); \
    PR_PRPD |= (uint8_t)(PR_TWI_bm|PR_USART1_bm|PR_USART0_bm|PR_SPI_bm|PR_HIRES_bm|PR_TC1_bm|PR_TC0_bm); \
    PR_PRPE |= (uint8_t)(PR_TWI_bm|PR_USART1_bm|PR_USART0_bm|PR_SPI_bm|PR_HIRES_bm|PR_TC1_bm|PR_TC0_bm); \
    PR_PRPF |= (uint8_t)(PR_TWI_bm|PR_USART1_bm|PR_USART0_bm|PR_SPI_bm|PR_HIRES_bm|PR_TC1_bm|PR_TC0_bm); \
} while(0)

#else

#define power_all_enable() \
do { \
    PR_PRGEN &= (uint8_t)~(PR_AES_bm|PR_EBI_bm|PR_RTC_bm|PR_EVSYS_bm|PR_DMA_bm); \
    PR_PRPA &= (uint8_t)~(PR_DAC_bm|PR_ADC_bm|PR_AC_bm); \
    PR_PRPB &= (uint8_t)~(PR_DAC_bm|PR_ADC_bm|PR_AC_bm); \
    PR_PRPC &= (uint8_t)~(PR_TWI_bm|PR_USART1_bm|PR_USART0_bm|PR_SPI_bm|PR_HIRES_bm|PR_TC1_bm|PR_TC0_bm); \
    PR_PRPD &= (uint8_t)~(PR_TWI_bm|PR_USART1_bm|PR_USART0_bm|PR_SPI_bm|PR_HIRES_bm|PR_TC1_bm|PR_TC0_bm); \
    PR_PRPE &= (uint8_t)~(PR_TWI_bm|PR_USART1_bm|PR_USART0_bm|PR_SPI_bm|PR_HIRES_bm|PR_TC1_bm|PR_TC0_bm); \
    PR_PRPF &= (uint8_t)~(PR_TWI_bm|PR_USART1_bm|PR_USART0_bm|PR_SPI_bm|PR_HIRES_bm|PR_TC1_bm|PR_TC0_bm); \
} while(0)


#define power_all_disable() \
do { \
    PR_PRGEN|= (uint8_t)(PR_AES_bm|PR_EBI_bm|PR_RTC_bm|PR_EVSYS_bm|PR_DMA_bm); \
    PR_PRPA |= (uint8_t)(PR_DAC_bm|PR_ADC_bm|PR_AC_bm); \
    PR_PRPB |= (uint8_t)(PR_DAC_bm|PR_ADC_bm|PR_AC_bm); \
    PR_PRPC |= (uint8_t)(PR_TWI_bm|PR_USART1_bm|PR_USART0_bm|PR_SPI_bm|PR_HIRES_bm|PR_TC1_bm|PR_TC0_bm); \
    PR_PRPD |= (uint8_t)(PR_TWI_bm|PR_USART1_bm|PR_USART0_bm|PR_SPI_bm|PR_HIRES_bm|PR_TC1_bm|PR_TC0_bm); \
    PR_PRPE |= (uint8_t)(PR_TWI_bm|PR_USART1_bm|PR_USART0_bm|PR_SPI_bm|PR_HIRES_bm|PR_TC1_bm|PR_TC0_bm); \
    PR_PRPF |= (uint8_t)(PR_TWI_bm|PR_USART1_bm|PR_USART0_bm|PR_SPI_bm|PR_HIRES_bm|PR_TC1_bm|PR_TC0_bm); \
} while(0)
#endif

#endif

#if defined(__AVR_ATxmega64D3__) \
|| defined(__AVR_ATxmega128D3__) \
|| defined(__AVR_ATxmega192D3__) \
|| defined(__AVR_ATxmega256D3__)

#define power_rtc_enable()      (PR_PRGEN &= (uint8_t)~(PR_RTC_bm))
#define power_rtc_disable()     (PR_PRGEN |= (uint8_t)PR_RTC_bm)

#define power_evsys_enable()    (PR_PRGEN &= (uint8_t)~(PR_EVSYS_bm))
#define power_evsys_disable()   (PR_PRGEN |= (uint8_t)PR_EVSYS_bm)

#define power_adca_enable()     (PR_PRPA &= (uint8_t)~(PR_ADC_bm))
#define power_adca_disable()    (PR_PRPA |= (uint8_t)PR_ADC_bm)

#define power_aca_enable()      (PR_PRPA &= (uint8_t)~(PR_AC_bm))
#define power_aca_disable()     (PR_PRPA |= (uint8_t)PR_AC_bm)

#define power_twic_enable()     (PR_PRPC &= (uint8_t)~(PR_TWI_bm))
#define power_twic_disable()    (PR_PRPC |= (uint8_t)PR_TWI_bm)
#define power_twie_enable()     (PR_PRPE &= (uint8_t)~(PR_TWI_bm))
#define power_twie_disable()    (PR_PRPE |= (uint8_t)PR_TWI_bm)

#define power_usartc0_enable()  (PR_PRPC &= (uint8_t)~(PR_USART0_bm))
#define power_usartc0_disable() (PR_PRPC |= (uint8_t)PR_USART0_bm)
#define power_usartd0_enable()  (PR_PRPD &= (uint8_t)~(PR_USART0_bm))
#define power_usartd0_disable() (PR_PRPD |= (uint8_t)PR_USART0_bm)
#define power_usarte0_enable()  (PR_PRPE &= (uint8_t)~(PR_USART0_bm))
#define power_usarte0_disable() (PR_PRPE |= (uint8_t)PR_USART0_bm)
#define power_usartf0_enable()  (PR_PRPF &= (uint8_t)~(PR_USART0_bm))
#define power_usartf0_disable() (PR_PRPF |= (uint8_t)PR_USART0_bm)

#define power_spic_enable()     (PR_PRPC &= (uint8_t)~(PR_SPI_bm))
#define power_spic_disable()    (PR_PRPC |= (uint8_t)PR_SPI_bm)
#define power_spid_enable()     (PR_PRPD &= (uint8_t)~(PR_SPI_bm))
#define power_spid_disable()    (PR_PRPD |= (uint8_t)PR_SPI_bm)

#define power_hiresc_enable()   (PR_PRPC &= (uint8_t)~(PR_HIRES_bm))
#define power_hiresc_disable()  (PR_PRPC |= (uint8_t)PR_HIRES_bm)

#define power_tc1c_enable()     (PR_PRPC &= (uint8_t)~(PR_TC1_bm))
#define power_tc1c_disable()    (PR_PRPC |= (uint8_t)PR_TC1_bm)

#define power_tc0c_enable()     (PR_PRPC &= (uint8_t)~(PR_TC0_bm))
#define power_tc0c_disable()    (PR_PRPC |= (uint8_t)PR_TC0_bm)
#define power_tc0d_enable()     (PR_PRPD &= (uint8_t)~(PR_TC0_bm))
#define power_tc0d_disable()    (PR_PRPD |= (uint8_t)PR_TC0_bm)
#define power_tc0e_enable()     (PR_PRPE &= (uint8_t)~(PR_TC0_bm))
#define power_tc0e_disable()    (PR_PRPE |= (uint8_t)PR_TC0_bm)
#define power_tc0f_enable()     (PR_PRPF &= (uint8_t)~(PR_TC0_bm))
#define power_tc0f_disable()    (PR_PRPF |= (uint8_t)PR_TC0_bm)

#define power_all_enable() \
do { \
    PR_PRGEN &= (uint8_t)~(PR_RTC_bm|PR_EVSYS_bm); \
    PR_PRPA &= (uint8_t)~(PR_ADC_bm|PR_AC_bm); \
    PR_PRPC &= (uint8_t)~(PR_TWI_bm|PR_USART0_bm|PR_SPI_bm|PR_HIRES_bm|PR_TC1_bm|PR_TC0_bm); \
    PR_PRPD &= (uint8_t)~(PR_USART0_bm|PR_SPI_bm|PR_TC0_bm); \
    PR_PRPE &= (uint8_t)~(PR_TWI_bm|PR_USART0_bm|PR_TC0_bm); \
    PR_PRPF &= (uint8_t)~(PR_USART0_bm|PR_TC0_bm); \
} while(0)


#define power_all_disable() \
do { \
    PR_PRGEN|= (uint8_t)(PR_RTC_bm|PR_EVSYS_bm); \
    PR_PRPA |= (uint8_t)(PR_ADC_bm|PR_AC_bm); \
    PR_PRPC |= (uint8_t)(PR_TWI_bm|PR_USART0_bm|PR_SPI_bm|PR_HIRES_bm|PR_TC1_bm|PR_TC0_bm); \
    PR_PRPD |= (uint8_t)(PR_USART0_bm|PR_SPI_bm|PR_TC0_bm); \
    PR_PRPE |= (uint8_t)(PR_TWI_bm|PR_USART0_bm|PR_TC0_bm); \
    PR_PRPF |= (uint8_t)(PR_USART0_bm|PR_TC0_bm); \
} while(0)
#endif

#if defined(__AVR_ATxmega16C4__) \
|| defined(__AVR_ATxmega32C4__) \
|| defined(__AVR_ATxmega64C3__) \
|| defined(__AVR_ATxmega128C3__) \
|| defined(__AVR_ATxmega192C3__) \
|| defined(__AVR_ATxmega256C3__) 

#define power_usb_enable()   (PR_PRGEN &= (uint8_t)~(PR_USB_bm))
#define power_usb_disable()  (PR_PRGEN &= (uint8_t)(PR_USB_bm))

#define power_aes_enable()  (PR_PRGEN &= (uint8_t)~(PR_AES_bm))
#define power_aes_disable() (PR_PRGEN |= (uint8_t)PR_AES_bm)

#define power_rtc_enable()  (PR_PRGEN &= (uint8_t)~(PR_RTC_bm))
#define power_rtc_disable() (PR_PRGEN |= (uint8_t)PR_RTC_bm)

#define power_evsys_enable()    (PR_PRGEN &= (uint8_t)~(PR_EVSYS_bm))
#define power_evsys_disable()   (PR_PRGEN |= (uint8_t)PR_EVSYS_bm)

#define power_dma_enable()    (PR_PRGEN &= (uint8_t)~(PR_DMA_bm))
#define power_dma_disable()   (PR_PRGEN |= (uint8_t)PR_DMA_bm)

#define power_adca_enable()     (PR_PRPA &= (uint8_t)~(PR_ADC_bm))
#define power_adca_disable()    (PR_PRPA |= (uint8_t)PR_ADC_bm)

#define power_aca_enable()      (PR_PRPA &= (uint8_t)~(PR_AC_bm))
#define power_aca_disable()     (PR_PRPA |= (uint8_t)PR_AC_bm)

#define power_twic_enable()     (PR_PRPC &= (uint8_t)~(PR_TWI_bm))
#define power_twic_disable()    (PR_PRPC |= (uint8_t)PR_TWI_bm)
#define power_twie_enable()     (PR_PRPE &= (uint8_t)~(PR_TWI_bm))
#define power_twie_disable()    (PR_PRPE |= (uint8_t)PR_TWI_bm)

#define power_usartc1_enable()  (PR_PRPC &= (uint8_t)~(PR_USART1_bm))
#define power_usartc1_disable() (PR_PRPC |= (uint8_t)PR_USART1_bm)

#define power_usartc0_enable()  (PR_PRPC &= (uint8_t)~(PR_USART0_bm))
#define power_usartc0_disable() (PR_PRPC |= (uint8_t)PR_USART0_bm)
#define power_usartd0_enable()  (PR_PRPD &= (uint8_t)~(PR_USART0_bm))
#define power_usartd0_disable() (PR_PRPD |= (uint8_t)PR_USART0_bm)
#define power_usarte0_enable()  (PR_PRPE &= (uint8_t)~(PR_USART0_bm))
#define power_usarte0_disable() (PR_PRPE |= (uint8_t)PR_USART0_bm)
#define power_usartf0_enable()  (PR_PRPF &= (uint8_t)~(PR_USART0_bm))
#define power_usartf0_disable() (PR_PRPF |= (uint8_t)PR_USART0_bm)

#define power_spic_enable()     (PR_PRPC &= (uint8_t)~(PR_SPI_bm))
#define power_spic_disable()    (PR_PRPC |= (uint8_t)PR_SPI_bm)
#define power_spid_enable()     (PR_PRPD &= (uint8_t)~(PR_SPI_bm))
#define power_spid_disable()    (PR_PRPD |= (uint8_t)PR_SPI_bm)

#define power_hiresc_enable()   (PR_PRPC &= (uint8_t)~(PR_HIRES_bm))
#define power_hiresc_disable()  (PR_PRPC |= (uint8_t)PR_HIRES_bm)

#define power_tc1c_enable()     (PR_PRPC &= (uint8_t)~(PR_TC1_bm))
#define power_tc1c_disable()    (PR_PRPC |= (uint8_t)PR_TC1_bm)

#define power_tc0c_enable()     (PR_PRPC &= (uint8_t)~(PR_TC0_bm))
#define power_tc0c_disable()    (PR_PRPC |= (uint8_t)PR_TC0_bm)
#define power_tc0d_enable()     (PR_PRPD &= (uint8_t)~(PR_TC0_bm))
#define power_tc0d_disable()    (PR_PRPD |= (uint8_t)PR_TC0_bm)
#define power_tc0e_enable()     (PR_PRPE &= (uint8_t)~(PR_TC0_bm))
#define power_tc0e_disable()    (PR_PRPE |= (uint8_t)PR_TC0_bm)
#define power_tc0f_enable()     (PR_PRPF &= (uint8_t)~(PR_TC0_bm))
#define power_tc0f_disable()    (PR_PRPF |= (uint8_t)PR_TC0_bm)

#define power_all_enable() \
do { \
    PR_PRGEN &= (uint8_t)~(PR_USB_bm|PR_AES_bm|PR_DMA_bm|PR_RTC_bm|PR_EVSYS_bm); \
    PR_PRPA &= (uint8_t)~(PR_ADC_bm|PR_AC_bm); \
    PR_PRPC &= (uint8_t)~(PR_TWI_bm|PR_USART0_bm|PR_USART1_bm|PR_SPI_bm|PR_HIRES_bm|PR_TC1_bm|PR_TC0_bm); \
    PR_PRPD &= (uint8_t)~(PR_USART0_bm|PR_SPI_bm|PR_TC0_bm); \
    PR_PRPE &= (uint8_t)~(PR_TWI_bm|PR_USART0_bm|PR_TC0_bm); \
    PR_PRPF &= (uint8_t)~(PR_USART0_bm|PR_TC0_bm); \
    } while(0)

#define power_all_disable() \
do { \
    PR_PRGEN |= (uint8_t)(PR_USB_bm|PR_AES_bm|PR_DMA_bm|PR_RTC_bm|PR_EVSYS_bm); \
    PR_PRPA |= (uint8_t)(PR_ADC_bm|PR_AC_bm); \
    PR_PRPC |= (uint8_t)(PR_TWI_bm|PR_USART0_bm|PR_USART1_bm|PR_SPI_bm|PR_HIRES_bm|PR_TC1_bm|PR_TC0_bm); \
    PR_PRPD |= (uint8_t)(PR_USART0_bm|PR_SPI_bm|PR_TC0_bm); \
    PR_PRPE |= (uint8_t)(PR_TWI_bm|PR_USART0_bm|PR_TC0_bm); \
    PR_PRPF |= (uint8_t)(PR_USART0_bm|PR_TC0_bm); \
    } while(0)

#endif

#if defined(__AVR_ATxmega16A4__) \
|| defined(__AVR_ATxmega16A4U__) \
|| defined(__AVR_ATxmega16D4__) \
|| defined(__AVR_ATxmega32A4__) \
|| defined(__AVR_ATxmega32A4U__) \
|| defined(__AVR_ATxmega32D4__) \
|| defined(__AVR_ATxmega64A1__) \
|| defined(__AVR_ATxmega64A1U__) \
|| defined(__AVR_ATxmega64A3__) \
|| defined(__AVR_ATxmega64A3U__) \
|| defined(__AVR_ATxmega64A4U__) \
|| defined(__AVR_ATxmega128A1__) \
|| defined(__AVR_ATxmega128A1U__) \
|| defined(__AVR_ATxmega128A3__) \
|| defined(__AVR_ATxmega128A3U__) \
|| defined(__AVR_ATxmega128A4U__) \
|| defined(__AVR_ATxmega192A3__) \
|| defined(__AVR_ATxmega192A3U__) \
|| defined(__AVR_ATxmega256A3__) \
|| defined(__AVR_ATxmega256A3U__) \
|| defined(__AVR_ATxmega256A3B__) \
|| defined(__AVR_ATxmega256A3BU__) \
|| defined(__AVR_ATxmega384C3__)


#define power_rtc_enable()  (PR_PRGEN &= (uint8_t)~(PR_RTC_bm))
#define power_rtc_disable() (PR_PRGEN |= (uint8_t)PR_RTC_bm)

#define power_evsys_enable()    (PR_PRGEN &= (uint8_t)~(PR_EVSYS_bm))
#define power_evsys_disable()   (PR_PRGEN |= (uint8_t)PR_EVSYS_bm)

#define power_adca_enable()     (PR_PRPA &= (uint8_t)~(PR_ADC_bm))
#define power_adca_disable()    (PR_PRPA |= (uint8_t)PR_ADC_bm)
#define power_adcb_enable()     (PR_PRPB &= (uint8_t)~(PR_ADC_bm))
#define power_adcb_disable()    (PR_PRPB |= (uint8_t)PR_ADC_bm)

#define power_aca_enable()      (PR_PRPA &= (uint8_t)~(PR_AC_bm))
#define power_aca_disable()     (PR_PRPA |= (uint8_t)PR_AC_bm)
#define power_acb_enable()      (PR_PRPB &= (uint8_t)~(PR_AC_bm))
#define power_acb_disable()     (PR_PRPB |= (uint8_t)PR_AC_bm)

#define power_twic_enable()     (PR_PRPC &= (uint8_t)~(PR_TWI_bm))
#define power_twic_disable()    (PR_PRPC |= (uint8_t)PR_TWI_bm)
#define power_twid_enable()     (PR_PRPD &= (uint8_t)~(PR_TWI_bm))
#define power_twid_disable()    (PR_PRPD |= (uint8_t)PR_TWI_bm)
#define power_twie_enable()     (PR_PRPE &= (uint8_t)~(PR_TWI_bm))
#define power_twie_disable()    (PR_PRPE |= (uint8_t)PR_TWI_bm)
#define power_twif_enable()     (PR_PRPF &= (uint8_t)~(PR_TWI_bm))
#define power_twif_disable()    (PR_PRPF |= (uint8_t)PR_TWI_bm)

#define power_usartc0_enable()  (PR_PRPC &= (uint8_t)~(PR_USART0_bm))
#define power_usartc0_disable() (PR_PRPC |= (uint8_t)PR_USART0_bm)
#define power_usartd0_enable()  (PR_PRPD &= (uint8_t)~(PR_USART0_bm))
#define power_usartd0_disable() (PR_PRPD |= (uint8_t)PR_USART0_bm)
#define power_usarte0_enable()  (PR_PRPE &= (uint8_t)~(PR_USART0_bm))
#define power_usarte0_disable() (PR_PRPE |= (uint8_t)PR_USART0_bm)
#define power_usartf0_enable()  (PR_PRPF &= (uint8_t)~(PR_USART0_bm))
#define power_usartf0_disable() (PR_PRPF |= (uint8_t)PR_USART0_bm)

#define power_spic_enable()     (PR_PRPC &= (uint8_t)~(PR_SPI_bm))
#define power_spic_disable()    (PR_PRPC |= (uint8_t)PR_SPI_bm)
#define power_spid_enable()     (PR_PRPD &= (uint8_t)~(PR_SPI_bm))
#define power_spid_disable()    (PR_PRPD |= (uint8_t)PR_SPI_bm)
#define power_spie_enable()     (PR_PRPE &= (uint8_t)~(PR_SPI_bm))
#define power_spie_disable()    (PR_PRPE |= (uint8_t)PR_SPI_bm)
#define power_spif_enable()     (PR_PRPF &= (uint8_t)~(PR_SPI_bm))
#define power_spif_disable()    (PR_PRPF |= (uint8_t)PR_SPI_bm)

#define power_hiresc_enable()   (PR_PRPC &= (uint8_t)~(PR_HIRES_bm))
#define power_hiresc_disable()  (PR_PRPC |= (uint8_t)PR_HIRES_bm)
#define power_hiresd_enable()   (PR_PRPD &= (uint8_t)~(PR_HIRES_bm))
#define power_hiresd_disable()  (PR_PRPD |= (uint8_t)PR_HIRES_bm)
#define power_hirese_enable()   (PR_PRPE &= (uint8_t)~(PR_HIRES_bm))
#define power_hirese_disable()  (PR_PRPE |= (uint8_t)PR_HIRES_bm)
#define power_hiresf_enable()   (PR_PRPF &= (uint8_t)~(PR_HIRES_bm))
#define power_hiresf_disable()  (PR_PRPF |= (uint8_t)PR_HIRES_bm)

#define power_tc1c_enable()     (PR_PRPC &= (uint8_t)~(PR_TC1_bm))
#define power_tc1c_disable()    (PR_PRPC |= (uint8_t)PR_TC1_bm)
#define power_tc1d_enable()     (PR_PRPD &= (uint8_t)~(PR_TC1_bm))
#define power_tc1d_disable()    (PR_PRPD |= (uint8_t)PR_TC1_bm)
#define power_tc1e_enable()     (PR_PRPE &= (uint8_t)~(PR_TC1_bm))
#define power_tc1e_disable()    (PR_PRPE |= (uint8_t)PR_TC1_bm)
#define power_tc1f_enable()     (PR_PRPF &= (uint8_t)~(PR_TC1_bm))
#define power_tc1f_disable()    (PR_PRPF |= (uint8_t)PR_TC1_bm)

#define power_tc0c_enable()     (PR_PRPC &= (uint8_t)~(PR_TC0_bm))
#define power_tc0c_disable()    (PR_PRPC |= (uint8_t)PR_TC0_bm)
#define power_tc0d_enable()     (PR_PRPD &= (uint8_t)~(PR_TC0_bm))
#define power_tc0d_disable()    (PR_PRPD |= (uint8_t)PR_TC0_bm)
#define power_tc0e_enable()     (PR_PRPE &= (uint8_t)~(PR_TC0_bm))
#define power_tc0e_disable()    (PR_PRPE |= (uint8_t)PR_TC0_bm)
#define power_tc0f_enable()     (PR_PRPF &= (uint8_t)~(PR_TC0_bm))
#define power_tc0f_disable()    (PR_PRPF |= (uint8_t)PR_TC0_bm)

#endif

#if defined(__AVR_ATxmega64D4__) \
|| defined(__AVR_ATxmega128D4__) 

#define power_rtc_enable()  (PR_PRGEN &= (uint8_t)~(PR_RTC_bm))
#define power_rtc_disable() (PR_PRGEN |= (uint8_t)PR_RTC_bm)

#define power_evsys_enable()    (PR_PRGEN &= (uint8_t)~(PR_EVSYS_bm))
#define power_evsys_disable()   (PR_PRGEN |= (uint8_t)PR_EVSYS_bm)

#define power_adca_enable()     (PR_PRPA &= (uint8_t)~(PR_ADC_bm))
#define power_adca_disable()    (PR_PRPA |= (uint8_t)PR_ADC_bm)

#define power_aca_enable()      (PR_PRPA &= (uint8_t)~(PR_AC_bm))
#define power_aca_disable()     (PR_PRPA |= (uint8_t)PR_AC_bm)

#define power_twic_enable()     (PR_PRPC &= (uint8_t)~(PR_TWI_bm))
#define power_twic_disable()    (PR_PRPC |= (uint8_t)PR_TWI_bm)
#define power_twie_enable()     (PR_PRPE &= (uint8_t)~(PR_TWI_bm))
#define power_twie_disable()    (PR_PRPE |= (uint8_t)PR_TWI_bm)

#define power_usartc0_enable()  (PR_PRPC &= (uint8_t)~(PR_USART0_bm))
#define power_usartc0_disable() (PR_PRPC |= (uint8_t)PR_USART0_bm)
#define power_usartd0_enable()  (PR_PRPD &= (uint8_t)~(PR_USART0_bm))
#define power_usartd0_disable() (PR_PRPD |= (uint8_t)PR_USART0_bm)
#define power_usarte0_enable()  (PR_PRPE &= (uint8_t)~(PR_USART0_bm))
#define power_usarte0_disable() (PR_PRPE |= (uint8_t)PR_USART0_bm)
#define power_usartf0_enable()  (PR_PRPF &= (uint8_t)~(PR_USART0_bm))
#define power_usartf0_disable() (PR_PRPF |= (uint8_t)PR_USART0_bm)

#define power_spic_enable()     (PR_PRPC &= (uint8_t)~(PR_SPI_bm))
#define power_spic_disable()    (PR_PRPC |= (uint8_t)PR_SPI_bm)
#define power_spid_enable()     (PR_PRPD &= (uint8_t)~(PR_SPI_bm))
#define power_spid_disable()    (PR_PRPD |= (uint8_t)PR_SPI_bm)

#define power_hiresc_enable()   (PR_PRPC &= (uint8_t)~(PR_HIRES_bm))
#define power_hiresc_disable()  (PR_PRPC |= (uint8_t)PR_HIRES_bm)

#define power_tc1c_enable()     (PR_PRPC &= (uint8_t)~(PR_TC1_bm))
#define power_tc1c_disable()    (PR_PRPC |= (uint8_t)PR_TC1_bm)

#define power_tc0c_enable()     (PR_PRPC &= (uint8_t)~(PR_TC0_bm))
#define power_tc0c_disable()    (PR_PRPC |= (uint8_t)PR_TC0_bm)
#define power_tc0d_enable()     (PR_PRPD &= (uint8_t)~(PR_TC0_bm))
#define power_tc0d_disable()    (PR_PRPD |= (uint8_t)PR_TC0_bm)
#define power_tc0e_enable()     (PR_PRPE &= (uint8_t)~(PR_TC0_bm))
#define power_tc0e_disable()    (PR_PRPE |= (uint8_t)PR_TC0_bm)
#define power_tc0f_enable()     (PR_PRPF &= (uint8_t)~(PR_TC0_bm))
#define power_tc0f_disable()    (PR_PRPF |= (uint8_t)PR_TC0_bm)

#define power_all_enable() \
do { \
    PR_PRGEN &= (uint8_t)~(PR_RTC_bm|PR_EVSYS_bm); \
    PR_PRPA &= (uint8_t)~(PR_ADC_bm|PR_AC_bm); \
    PR_PRPC &= (uint8_t)~(PR_TWI_bm|PR_USART0_bm|PR_SPI_bm|PR_HIRES_bm|PR_TC1_bm|PR_TC0_bm); \
    PR_PRPD &= (uint8_t)~(PR_USART0_bm|PR_SPI_bm|PR_TC0_bm); \
    PR_PRPE &= (uint8_t)~(PR_TWI_bm|PR_USART0_bm|PR_TC0_bm); \
    PR_PRPF &= (uint8_t)~(PR_USART0_bm|PR_TC0_bm); \
    } while(0)

#define power_all_disable() \
do { \
    PR_PRGEN |= (uint8_t)(PR_RTC_bm|PR_EVSYS_bm); \
    PR_PRPA |= (uint8_t)(PR_ADC_bm|PR_AC_bm); \
    PR_PRPC |= (uint8_t)(PR_TWI_bm|PR_USART0_bm|PR_SPI_bm|PR_HIRES_bm|PR_TC1_bm|PR_TC0_bm); \
    PR_PRPD |= (uint8_t)(PR_USART0_bm|PR_SPI_bm|PR_TC0_bm); \
    PR_PRPE |= (uint8_t)(PR_TWI_bm|PR_USART0_bm|PR_TC0_bm); \
    PR_PRPF |= (uint8_t)(PR_USART0_bm|PR_TC0_bm); \
    } while(0)

#endif

#if defined(__AVR_ATxmega16D4__) \
|| defined(__AVR_ATxmega32D4__) 

#define power_all_enable() \
do { \
    PR_PRGEN &= (uint8_t)~(PR_RTC_bm|PR_EVSYS_bm); \
    PR_PRPA &= (uint8_t)~(PR_ADC_bm|PR_AC_bm); \
    PR_PRPB &= (uint8_t)~(PR_ADC_bm|PR_AC_bm); \
    PR_PRPC &= (uint8_t)~(PR_TWI_bm|PR_USART0_bm|PR_SPI_bm|PR_HIRES_bm|PR_TC1_bm|PR_TC0_bm); \
    PR_PRPD &= (uint8_t)~(PR_TWI_bm|PR_USART0_bm|PR_SPI_bm|PR_HIRES_bm|PR_TC1_bm|PR_TC0_bm); \
    PR_PRPE &= (uint8_t)~(PR_TWI_bm|PR_USART0_bm|PR_SPI_bm|PR_HIRES_bm|PR_TC1_bm|PR_TC0_bm); \
    PR_PRPF &= (uint8_t)~(PR_TWI_bm|PR_USART0_bm|PR_SPI_bm|PR_HIRES_bm|PR_TC1_bm|PR_TC0_bm); \
} while(0)


#define power_all_disable() \
do { \
    PR_PRGEN|= (uint8_t)(PR_EBI_bm|PR_RTC_bm|PR_EVSYS_bm|PR_DMA_bm); \
    PR_PRPA |= (uint8_t)(PR_ADC_bm|PR_AC_bm); \
    PR_PRPB |= (uint8_t)(PR_ADC_bm|PR_AC_bm); \
    PR_PRPC |= (uint8_t)(PR_TWI_bm|PR_USART0_bm|PR_SPI_bm|PR_HIRES_bm|PR_TC1_bm|PR_TC0_bm); \
    PR_PRPD |= (uint8_t)(PR_TWI_bm|PR_USART0_bm|PR_SPI_bm|PR_HIRES_bm|PR_TC1_bm|PR_TC0_bm); \
    PR_PRPE |= (uint8_t)(PR_TWI_bm|PR_USART0_bm|PR_SPI_bm|PR_HIRES_bm|PR_TC1_bm|PR_TC0_bm); \
    PR_PRPF |= (uint8_t)(PR_TWI_bm|PR_USART0_bm|PR_SPI_bm|PR_HIRES_bm|PR_TC1_bm|PR_TC0_bm); \
} while(0)

#elif defined (__AVR_ATxmega64B1__) \
|| defined (__AVR_ATxmega64B3__) \
|| defined (__AVR_ATxmega128B1__) \
|| defined (__AVR_ATxmega128B3__) 
#define power_lcd_enable()  (PR_PRGEN &= (uint8_t)~(PR_LCD_bm))
#define power_lcd_disable() (PR_PRGEN |= (uint8_t)PR_LCD_bm)

#define power_usb_enable()  (PR_PRGEN &= (uint8_t)~(PR_USB_bm))
#define power_usb_disable() (PR_PRGEN |= (uint8_t)PR_USB_bm)

#define power_aes_enable()  (PR_PRGEN &= (uint8_t)~(PR_AES_bm))
#define power_aes_disable() (PR_PRGEN |= (uint8_t)PR_AES_bm)

#define power_rtc_enable()  (PR_PRGEN &= (uint8_t)~(PR_RTC_bm))
#define power_rtc_disable() (PR_PRGEN |= (uint8_t)PR_RTC_bm)

#define power_evsys_enable()    (PR_PRGEN &= (uint8_t)~(PR_EVSYS_bm))
#define power_evsys_disable()   (PR_PRGEN |= (uint8_t)PR_EVSYS_bm)

#define power_dma_enable()    (PR_PRGEN &= (uint8_t)~(PR_DMA_bm))
#define power_dma_disable()   (PR_PRGEN |= (uint8_t)PR_DMA_bm)

#define power_adca_enable()     (PR_PRPA &= (uint8_t)~(PR_ADC_bm))
#define power_adca_disable()    (PR_PRPA |= (uint8_t)PR_ADC_bm)
#define power_adcb_enable()     (PR_PRPB &= (uint8_t)~(PR_ADC_bm))
#define power_adcb_disable()    (PR_PRPB |= (uint8_t)PR_ADC_bm)

#define power_aca_enable()      (PR_PRPA &= (uint8_t)~(PR_AC_bm))
#define power_aca_disable()     (PR_PRPA |= (uint8_t)PR_AC_bm)
#define power_acb_enable()      (PR_PRPB &= (uint8_t)~(PR_AC_bm))
#define power_acb_disable()     (PR_PRPB |= (uint8_t)PR_AC_bm)

#define power_twic_enable()     (PR_PRPC &= (uint8_t)~(PR_TWI_bm))
#define power_twic_disable()    (PR_PRPC |= (uint8_t)PR_TWI_bm)

#define power_usartc0_enable()  (PR_PRPC &= (uint8_t)~(PR_USART0_bm))
#define power_usartc0_disable() (PR_PRPC |= (uint8_t)PR_USART0_bm)
#define power_usarte0_enable()  (PR_PRPE &= (uint8_t)~(PR_USART0_bm))
#define power_usarte0_disable() (PR_PRPE |= (uint8_t)PR_USART0_bm)

#define power_spic_enable()     (PR_PRPC &= (uint8_t)~(PR_SPI_bm))
#define power_spic_disable()    (PR_PRPC |= (uint8_t)PR_SPI_bm)

#define power_hiresc_enable()     (PR_PRPC &= (uint8_t)~(PR_HIRES_bm))
#define power_hiresc_disable()    (PR_PRPC |= (uint8_t)PR_HIRES_bm)

#define power_tc1c_enable()     (PR_PRPC &= (uint8_t)~(PR_TC1_bm))
#define power_tc1c_disable()    (PR_PRPC |= (uint8_t)PR_TC1_bm)

#define power_tc0c_enable()  (PR_PRPC &= (uint8_t)~(PR_TC0_bm))
#define power_tc0c_disable() (PR_PRPC |= (uint8_t)PR_TC0_bm)
#define power_tc0e_enable()  (PR_PRPE &= (uint8_t)~(PR_TC0_bm))
#define power_tc0e_disable() (PR_PRPE |= (uint8_t)PR_TC0_bm)

#define power_all_enable() \
do { \
    PR_PRGEN &= (uint8_t)~(PR_LCD_bm|PR_USB_bm|PR_AES_bm|PR_RTC_bm|PR_EVSYS_bm|PR_DMA_bm); \
    PR_PRPA &= (uint8_t)~(PR_ADC_bm|PR_AC_bm); \
    PR_PRPB &= (uint8_t)~(PR_ADC_bm|PR_AC_bm); \
    PR_PRPC &= (uint8_t)~(PR_TWI_bm|PR_USART0_bm|PR_SPI_bm|PR_HIRES_bm|PR_TC1_bm|PR_TC0_bm); \
    PR_PRPE &= (uint8_t)~(PR_USART0_bm|PR_TC0_bm); \
    } while(0)

#define power_all_disable() \
do { \
    PR_PRGEN |= (uint8_t)(PR_LCD_bm|PR_USB_bm|PR_AES_bm|PR_RTC_bm|PR_EVSYS_bm|PR_DMA_bm); \
    PR_PRPA |= (uint8_t)(PR_ADC_bm|PR_AC_bm); \
    PR_PRPB |= (uint8_t)(PR_ADC_bm|PR_AC_bm); \
    PR_PRPC |= (uint8_t)(PR_TWI_bm|PR_USART0_bm|PR_SPI_bm|PR_HIRES_bm|PR_TC1_bm|PR_TC0_bm); \
    PR_PRPE |= (uint8_t)(PR_USART0_bm|PR_TC0_bm); \
    } while(0)

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


#elif defined(__AVR_ATmega128RFA1__)

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

#define power_all_enable() \
do{ \
    PRR0 &= (uint8_t)~((1<<PRADC)|(1<<PRSPI)|(1<<PRTWI)|(1<<PRTIM0)|(1<<PRTIM1)|(1<<PRTIM2)|(1<<PRUSART0)); \
    PRR1 &= (uint8_t)~((1<<PRTIM3)|(1<<PRTIM4)|(1<<PRTIM5)|(1<<PRTIM5)|(1<<PRUSART1)); \
}while(0)

#define power_all_disable() \
do{ \
    PRR0 |= (uint8_t)((1<<PRADC)|(1<<PRSPI)|(1<<PRTWI)|(1<<PRTIM0)|(1<<PRTIM1)|(1<<PRTIM2)|(1<<PRUSART0)); \
    PRR1 |= (uint8_t)((1<<PRTIM3)|(1<<PRTIM4)|(1<<PRTIM5)|(1<<PRTIM5)|(1<<PRUSART1)); \
}while(0)

#elif defined(__AVR_ATmega256RFR2__) \
|| defined(__AVR_ATmega128RFR2__) \
|| defined(__AVR_ATmega64RFR2__) \
|| defined(__AVR_ATmega2564RFR2__) \
|| defined(__AVR_ATmega1284RFR2__) \
|| defined(__AVR_ATmega644RFR2__) \

#define power_adc_enable()           (PRR0 &= (uint8_t)~(1 << PRADC))
#define power_adc_disable()          (PRR0 |= (uint8_t)(1 << PRADC))

#define power_usart0_enable()        (PRR0 &= (uint8_t)~(1 << PRUSART0))
#define power_usart0_disable()       (PRR0 |= (uint8_t)(1 << PRUSART0))

#define power_spi_enable()           (PRR0 &= (uint8_t)~(1 << PRSPI))
#define power_spi_disable()          (PRR0 |= (uint8_t)(1 << PRSPI))

#define power_timer1_enable()        (PRR0 &= (uint8_t)~(1 << PRTIM1))
#define power_timer1_disable()       (PRR0 |= (uint8_t)(1 << PRTIM1))

#define power_pga_enable()           (PRR0 &= (uint8_t)~(1 << PRPGA))
#define power_pga_disable()          (PRR0 |= (uint8_t)(1 << PRPGA))

#define power_timer0_enable()        (PRR0 &= (uint8_t)~(1 << PRTIM0))
#define power_timer0_disable()       (PRR0 |= (uint8_t)(1 << PRTIM0))

#define power_timer2_enable()        (PRR0 &= (uint8_t)~(1 << PRTIM2))
#define power_timer2_disable()       (PRR0 |= (uint8_t)(1 << PRTIM2))

#define power_twi_enable()           (PRR0 &= (uint8_t)~(1 << PRTWI))
#define power_twi_disable()          (PRR0 |= (uint8_t)(1 << PRTWI))

#define power_usart1_enable()        (PRR1 &= (uint8_t)~(1 << PRUSART1))
#define power_usart1_disable()       (PRR1 |= (uint8_t)(1 << PRUSART1))

#define power_timer3_enable()        (PRR1 &= (uint8_t)~(1 << PRTIM3))
#define power_timer3_disable()       (PRR1 |= (uint8_t)(1 << PRTIM3))

#define power_timer4_enable()        (PRR1 &= (uint8_t)~(1 << PRTIM4))
#define power_timer4_disable()       (PRR1 |= (uint8_t)(1 << PRTIM4))

#define power_timer5_enable()        (PRR1 &= (uint8_t)~(1 << PRTIM5))
#define power_timer5_disable()       (PRR1 |= (uint8_t)(1 << PRTIM5))

#define power_transceiver_enable()   (PRR1 &= (uint8_t)~(1 << PRTRX24))
#define power_transceiver_disable()  (PRR1 |= (uint8_t)(1 << PRTRX24))

#define power_ram0_enable()          (PRR2 &= (uint8_t)~(1 << PRRAM0))
#define power_ram0_disable()         (PRR2 |= (uint8_t)(1 << PRRAM0))

#define power_ram1_enable()          (PRR2 &= (uint8_t)~(1 << PRRAM1))
#define power_ram1_disable()         (PRR2 |= (uint8_t)(1 << PRRAM1))

#define power_ram2_enable()          (PRR2 &= (uint8_t)~(1 << PRRAM2))
#define power_ram2_disable()         (PRR2 |= (uint8_t)(1 << PRRAM2))

#define power_ram3_enable()          (PRR2 &= (uint8_t)~(1 << PRRAM3))
#define power_ram3_disable()         (PRR2 |= (uint8_t)(1 << PRRAM3))

#define power_all_enable() \
do{ \
    PRR0 &= (uint8_t)~((1<<PRADC)|(1<<PRSPI)|(1<<PRTWI)|(1<<PRTIM0)|(1<<PRTIM1)|(1<<PRTIM2)|(1<<PRUSART0)); \
    PRR1 &= (uint8_t)~((1<<PRUSART1)|(1<<PRTIM3)|(1<<PRTIM4)|(1<<PRTIM5)|(1<<PRTRX24)); \
    PRR2 &= (uint8_t)~((1<<PRRAM0)|(1<<PRRAM1)|(1<<PRRAM2)|(1<<PRRAM3)); \
}while(0)

#define power_all_disable() \
do{ \
    PRR0 |= (uint8_t)((1<<PRADC)|(1<<PRSPI)|(1<<PRTWI)|(1<<PRTIM0)|(1<<PRTIM1)|(1<<PRTIM2)|(1<<PRUSART0)); \
    PRR1 |= (uint8_t)((1<<PRUSART1)|(1<<PRTIM3)|(1<<PRTIM4)|(1<<PRTIM5)|(1<<PRTRX24)); \
    PRR2 |= (uint8_t)((1<<PRRAM0)|(1<<PRRAM1)|(1<<PRRAM2)|(1<<PRRAM3)); \
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


#elif defined(__AVR_ATmega32U4__) \
|| defined(__AVR_ATmega16U4__)


#define power_adc_enable()      (PRR0 &= (uint8_t)~(1 << PRADC))
#define power_adc_disable()     (PRR0 |= (uint8_t)(1 << PRADC))

#define power_usart0_enable()   (PRR0 &= (uint8_t)~(1 << PRUSART0))
#define power_usart0_disable()  (PRR0 |= (uint8_t)(1 << PRUSART0))

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
    PRR0 &= (uint8_t)~((1<<PRADC)|(1<<PRUSART0)|(1<<PRSPI)|(1<<PRTWI)|(1<<PRTIM0)|(1<<PRTIM1)|(1<<PRTIM2)); \
    PRR1 &= (uint8_t)~((1<<PRTIM3)|(1<<PRUSART1)|(1<<PRUSB)); \
}while(0)

#define power_all_disable() \
do{ \
    PRR0 |= (uint8_t)((1<<PRADC)|(1<<PRUSART0)|(1<<PRSPI)|(1<<PRTWI)|(1<<PRTIM0)|(1<<PRTIM1)|(1<<PRTIM2)); \
    PRR1 |= (uint8_t)((1<<PRTIM3)|(1<<PRUSART1)|(1<<PRUSB)); \
}while(0)


#elif defined(__AVR_ATmega32U6__)


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
|| defined(__AVR_AT90PWM2B__) \
|| defined(__AVR_AT90PWM3__) \
|| defined(__AVR_AT90PWM3B__) \
|| defined(__AVR_AT90PWM216__) \
|| defined(__AVR_AT90PWM316__)

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


#elif defined(__AVR_AT90PWM81__) \
|| defined(__AVR_AT90PWM161__)

#define power_adc_enable()      (PRR &= (uint8_t)~(1 << PRADC))
#define power_adc_disable()     (PRR |= (uint8_t)(1 << PRADC))

#define power_spi_enable()      (PRR &= (uint8_t)~(1 << PRSPI))
#define power_spi_disable()     (PRR |= (uint8_t)(1 << PRSPI))

#define power_timer1_enable()   (PRR &= (uint8_t)~(1 << PRTIM1))
#define power_timer1_disable()  (PRR |= (uint8_t)(1 << PRTIM1))

/* Reduced Power Stage Controller */
#define power_pscr_enable()     (PRR &= (uint8_t)~(1 << PRPSCR))
#define power_pscr_disable()    (PRR |= (uint8_t)(1 << PRPSCR))

/* Power Stage Controller 2 */
#define power_psc2_enable()     (PRR &= (uint8_t)~(1 << PRPSC2))
#define power_psc2_disable()    (PRR |= (uint8_t)(1 << PRPSC2))

#define power_all_enable()      (PRR &= (uint8_t)~((1<<PRADC)|(1<<PRSPI)|(1<<PRTIM1)|(1<<PRPSCR)|(1<<PRPSC2)))
#define power_all_disable()     (PRR |= (uint8_t)((1<<PRADC)|(1<<PRSPI)|(1<<PRTIM1)|(1<<PRPSCR)|(1<<PRPSC2)))


#elif defined(__AVR_ATmega165__) \
|| defined(__AVR_ATmega165A__) \
|| defined(__AVR_ATmega165P__) \
|| defined(__AVR_ATmega165PA__) \
|| defined(__AVR_ATmega325__) \
|| defined(__AVR_ATmega325A__) \
|| defined(__AVR_ATmega325PA__) \
|| defined(__AVR_ATmega3250__) \
|| defined(__AVR_ATmega3250A__) \
|| defined(__AVR_ATmega3250PA__) \
|| defined(__AVR_ATmega645__) \
|| defined(__AVR_ATmega645A__) \
|| defined(__AVR_ATmega645P__) \
|| defined(__AVR_ATmega6450__) \
|| defined(__AVR_ATmega6450A__) \
|| defined(__AVR_ATmega6450P__)

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
|| defined(__AVR_ATmega169A__) \
|| defined(__AVR_ATmega169P__) \
|| defined(__AVR_ATmega169PA__) \
|| defined(__AVR_ATmega329__) \
|| defined(__AVR_ATmega329A__) \
|| defined(__AVR_ATmega329P__) \
|| defined(__AVR_ATmega329PA__) \
|| defined(__AVR_ATmega3290__) \
|| defined(__AVR_ATmega3290A__) \
|| defined(__AVR_ATmega3290P__) \
|| defined(__AVR_ATmega3290PA__) \
|| defined(__AVR_ATmega649__) \
|| defined(__AVR_ATmega649A__) \
|| defined(__AVR_ATmega649P__) \
|| defined(__AVR_ATmega6490__) \
|| defined(__AVR_ATmega6490A__) \
|| defined(__AVR_ATmega6490P__)

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


#elif defined(__AVR_ATmega164A__) \
|| defined(__AVR_ATmega164P__) \
|| defined(__AVR_ATmega324A__) \
|| defined(__AVR_ATmega324P__) \
|| defined(__AVR_ATmega324PA__) \
|| defined(__AVR_ATmega644P__) \
|| defined(__AVR_ATmega644A__) \
|| defined(__AVR_ATmega644PA__)

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

#define power_all_enable()      (PRR0 &= (uint8_t)~((1<<PRADC)|(1<<PRSPI)|(1<<PRUSART0)|(1<<PRUSART1)|(1<<PRTIM0)|(1<<PRTIM1)|(1<<PRTIM2)|(1<<PRTWI)))
#define power_all_disable()     (PRR0 |= (uint8_t)((1<<PRADC)|(1<<PRSPI)|(1<<PRUSART0)|(1<<PRUSART1)|(1<<PRTIM0)|(1<<PRTIM1)|(1<<PRTIM2)|(1<<PRTWI)))


#elif defined(__AVR_ATmega644__) \
|| defined(__AVR_ATmega164PA__)

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
|| defined(__AVR_ATmega48A__) \
|| defined(__AVR_ATmega48PA__) \
|| defined(__AVR_ATmega48P__) \
|| defined(__AVR_ATmega88__) \
|| defined(__AVR_ATmega88A__) \
|| defined(__AVR_ATmega88P__) \
|| defined(__AVR_ATmega88PA__) \
|| defined(__AVR_ATmega168__) \
|| defined(__AVR_ATmega168A__) \
|| defined(__AVR_ATmega168P__) \
|| defined(__AVR_ATmega168PA__) \
|| defined(__AVR_ATmega328__) \
|| defined(__AVR_ATmega328P__) \
|| defined(__AVR_ATtiny48__) \
|| defined(__AVR_ATtiny88__) \
|| defined(__AVR_ATtiny828__)

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

#if !defined(__AVR_ATtiny828__)

#define power_timer2_enable()   (PRR &= (uint8_t)~(1 << PRTIM2))
#define power_timer2_disable()  (PRR |= (uint8_t)(1 << PRTIM2))

#endif

#define power_twi_enable()      (PRR &= (uint8_t)~(1 << PRTWI))
#define power_twi_disable()     (PRR |= (uint8_t)(1 << PRTWI))

#if defined(__AVR_ATtiny828__)

#define power_all_enable()      (PRR &= (uint8_t)~((1<<PRADC)|(1<<PRSPI)|(1<<PRUSART0)|(1<<PRTIM0)|(1<<PRTIM1)|(1<<PRTWI)))
#define power_all_disable()     (PRR |= (uint8_t)((1<<PRADC)|(1<<PRSPI)|(1<<PRUSART0)|(1<<PRTIM0)|(1<<PRTIM1)|(1<<PRTWI)))

#else

#define power_all_enable()      (PRR &= (uint8_t)~((1<<PRADC)|(1<<PRSPI)|(1<<PRUSART0)|(1<<PRTIM0)|(1<<PRTIM1)|(1<<PRTIM2)|(1<<PRTWI)))
#define power_all_disable()     (PRR |= (uint8_t)((1<<PRADC)|(1<<PRSPI)|(1<<PRUSART0)|(1<<PRTIM0)|(1<<PRTIM1)|(1<<PRTIM2)|(1<<PRTWI)))

#endif

#elif defined(__AVR_ATtiny24__) \
|| defined(__AVR_ATtiny24A__) \
|| defined(__AVR_ATtiny44__) \
|| defined(__AVR_ATtiny44A__) \
|| defined(__AVR_ATtiny84__) \
|| defined(__AVR_ATtiny84A__) \
|| defined(__AVR_ATtiny25__) \
|| defined(__AVR_ATtiny45__) \
|| defined(__AVR_ATtiny85__) \
|| defined(__AVR_ATtiny261__) \
|| defined(__AVR_ATtiny261A__) \
|| defined(__AVR_ATtiny461__) \
|| defined(__AVR_ATtiny461A__) \
|| defined(__AVR_ATtiny861__) \
|| defined(__AVR_ATtiny861A__) \
|| defined(__AVR_ATtiny43U__)

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

#elif defined(__AVR_ATmega1284__)

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

#define power_usart0_enable()   (PRR0 &= (uint8_t)~(1 << PRUSART0))
#define power_usart0_disable()  (PRR0 |= (uint8_t)(1 << PRUSART0))

#define power_all_enable() \
do{ \
    PRR0 &= (uint8_t)~((1<<PRADC)|(1<<PRSPI)|(1<<PRTWI)|(1<<PRTIM0)|(1<<PRTIM1)|(1<<PRTIM2)|(1<<PRUSART0)); \
    PRR1 &= (uint8_t)~(1<<PRTIM3); \
}while(0)

#define power_all_disable() \
do{ \
    PRR0 |= (uint8_t)((1<<PRADC)|(1<<PRSPI)|(1<<PRTWI)|(1<<PRTIM0)|(1<<PRTIM1)|(1<<PRTIM2)|(1<<PRUSART0)); \
    PRR1 |= (uint8_t)(1<<PRTIM3); \
}while(0)

#elif defined(__AVR_ATmega1284P__)


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

#define power_usart0_enable()   (PRR0 &= (uint8_t)~(1 << PRUSART0))
#define power_usart0_disable()  (PRR0 |= (uint8_t)(1 << PRUSART0))

#define power_usart1_enable()   (PRR0 &= (uint8_t)~(1 << PRUSART1))
#define power_usart1_disable()  (PRR0 |= (uint8_t)(1 << PRUSART1))

#define power_all_enable() \
do{ \
    PRR0 &= (uint8_t)~((1<<PRADC)|(1<<PRSPI)|(1<<PRTWI)|(1<<PRTIM0)|(1<<PRTIM1)|(1<<PRTIM2)|(1<<PRUSART0)|(1<<PRUSART1)); \
    PRR1 &= (uint8_t)~(1<<PRTIM3); \
}while(0)

#define power_all_disable() \
do{ \
    PRR0 |= (uint8_t)((1<<PRADC)|(1<<PRSPI)|(1<<PRTWI)|(1<<PRTIM0)|(1<<PRTIM1)|(1<<PRTIM2)|(1<<PRUSART0)|(1<<PRUSART1)); \
    PRR1 |= (uint8_t)(1<<PRTIM3); \
}while(0)


#elif defined(__AVR_ATmega32HVB__) \
|| defined(__AVR_ATmega32HVBREVB__) \
|| defined(__AVR_ATmega16HVB__) \
|| defined(__AVR_ATmega16HVBREVB__)


#define power_twi_enable()      (PRR0 &= (uint8_t)~(1 << PRTWI))
#define power_twi_disable()     (PRR0 |= (uint8_t)(1 << PRTWI))

#define power_timer0_enable()   (PRR0 &= (uint8_t)~(1 << PRTIM0))
#define power_timer0_disable()  (PRR0 |= (uint8_t)(1 << PRTIM0))

#define power_timer1_enable()   (PRR0 &= (uint8_t)~(1 << PRTIM1))
#define power_timer1_disable()  (PRR0 |= (uint8_t)(1 << PRTIM1))

/* Voltage ADC */
#define power_vadc_enable()     (PRR0 &= (uint8_t)~(1 << PRVADC))
#define power_vadc_disable()    (PRR0 |= (uint8_t)(1 << PRVADC))

#define power_spi_enable()      (PRR0 &= (uint8_t)~(1 << PRSPI))
#define power_spi_disable()     (PRR0 |= (uint8_t)(1 << PRSPI))

#define power_vrm_enable()      (PRR0 &= (uint8_t)~(1 << PRVRM))
#define power_vrm_disable()     (PRR0 |= (uint8_t)(1 << PRVRM))

#define power_all_enable()      (PRR0 &= (uint8_t)~((1<<PRTWI)|(1<<PRTIM0)|(1<<PRTIM1)|(1<<PRVADC)|(1<<PRSPI)|(1<<PRVRM)))
#define power_all_disable()     (PRR0 |= (uint8_t)((1<<PRTWI)|(1<<PRTIM0)|(1<<PRTIM1)|(1<<PRVADC)|(1<<PRSPI)|(1<<PRVRM)))


#elif defined (__AVR_ATA5790__) \
|| defined (__AVR_ATA5795__)

// Enable the voltage monitor 
#define power_vmonitor_enable()          (PRR0 &= (uint8_t)~(1 << PRVM))
#define power_vmonitor_disable()         (PRR0 |= (uint8_t)(1 << PRVM))

#define power_irdriver_enable()          (PRR0 &= (uint8_t)~(1 << PRDS))
#define power_irdriver_disable()         (PRR0 |= (uint8_t)(1 << PRDS))

#define power_crypto_enable()            (PRR0 &= (uint8_t)~(1 << PRCU))
#define power_crypto_disable()           (PRR0 |= (uint8_t)(1 << PRCU))

#define power_timermodulator_enable()    (PRR0 &= (uint8_t)~(1 << PRTM))
#define power_timermodulator_disable()   (PRR0 |= (uint8_t)(1 << PRTM))

#define power_timer1_enable()            (PRR0 &= (uint8_t)~(1 << PRT1))
#define power_timer1_disable()           (PRR0 |= (uint8_t)(1 << PRT1))

#define power_timer2_enable()            (PRR0 &= (uint8_t)~(1 << PRT2))
#define power_timer2_disable()           (PRR0 |= (uint8_t)(1 << PRT2))

#define power_timer3_enable()            (PRR0 &= (uint8_t)~(1 << PRT3))
#define power_timer3_disable()           (PRR0 |= (uint8_t)(1 << PRT3))

#define power_spi_enable()               (PRR1 &= (uint8_t)~(1 << PRSPI))
#define power_spi_disable()              (PRR1 |= (uint8_t)(1 << PRSPI))

#define power_cinterface_enable()        (PRR1 &= (uint8_t)~(1 << PRCI))
#define power_cinterface_disable()       (PRR1 |= (uint8_t)(1 << PRCI))

#if defined(__AVR_ATA5790__) 

#define power_lfreceiver_enable()        (PRR0 &= (uint8_t)~(1 << PRLFR))            
#define power_lfreceiver_disable()       (PRR0 |= (uint8_t)(1 << PRLFR))            

#define power_all_enable() \
do{ \
    PRR0 &= (uint8_t)~((1<<PRVM)|(1<<PRDS)|(1<<PRCU)|(1<<PRTM)|(1<<PRT3)|(1<<PRT2)|(1<<PRT1)|(1<<PRLFR)); \
    PRR1 &= (uint8_t)~((1<<PRSPI)|(1<<PRCI)); \
}while(0)

#define power_all_disable() \
do{ \
    PRR0 |= (uint8_t)((1<<PRVM)|(1<<PRDS)|(1<<PRCU)|(1<<PRTM)|(1<<PRT3)|(1<<PRT2)|(1<<PRT1)|(1<<PRLFR)); \
    PRR1 |= (uint8_t)((1<<PRSPI)|(1<<PRCI)); \
}while(0)

#elif defined(__AVR_ATA5795__)

#define power_all_enable() \
do{ \
    PRR0 &= (uint8_t)~((1<<PRVM)|(1<<PRDS)|(1<<PRCU)|(1<<PRTM)|(1<<PRT3)|(1<<PRT2)|(1<<PRT1)); \
    PRR1 &= (uint8_t)~((1<<PRSPI)|(1<<PRCI)); \
}while(0)

#define power_all_disable() \
do{ \
    PRR0 |= (uint8_t)((1<<PRVM)|(1<<PRDS)|(1<<PRCU)|(1<<PRTM)|(1<<PRT3)|(1<<PRT2)|(1<<PRT1)); \
    PRR1 |= (uint8_t)((1<<PRSPI)|(1<<PRCI)); \
}while(0)

#endif

#elif defined(__AVR_ATmega16M1__) \
|| defined(__AVR_ATmega32C1__) \
|| defined(__AVR_ATmega32M1__) \
|| defined(__AVR_ATmega64C1__) \
|| defined(__AVR_ATmega64M1__)

#define power_adc_enable()      (PRR &= (uint8_t)~(1 << PRADC))
#define power_adc_disable()     (PRR |= (uint8_t)(1 << PRADC))

#define power_lin_enable()      (PRR &= (uint8_t)~(1 << PRLIN))
#define power_lin_disable()     (PRR |= (uint8_t)(1 << PRLIN))

#define power_spi_enable()      (PRR &= (uint8_t)~(1 << PRSPI))
#define power_spi_disable()     (PRR |= (uint8_t)(1 << PRSPI))

#define power_timer0_enable()   (PRR &= (uint8_t)~(1 << PRTIM0))
#define power_timer0_disable()  (PRR |= (uint8_t)(1 << PRTIM0))

#define power_timer1_enable()   (PRR &= (uint8_t)~(1 << PRTIM1))
#define power_timer1_disable()  (PRR |= (uint8_t)(1 << PRTIM1))

#define power_psc_enable()      (PRR &= (uint8_t)~(1 << PRPSC))
#define power_psc_disable()     (PRR |= (uint8_t)(1 << PRPSC))

#define power_can_enable()      (PRR &= (uint8_t)~(1 << PRCAN))
#define power_can_disable()     (PRR |= (uint8_t)(1 << PRCAN))

#define power_all_enable()      (PRR &= (uint8_t)~((1<<PRADC)|(1<<PRLIN)|(1<<PRSPI)|(1<<PRTIM0)|(1<<PRTIM1)|(1<<PRPSC)|(1<<PRCAN)))
#define power_all_disable()     (PRR |= (uint8_t)((1<<PRADC)|(1<<PRLIN)|(1<<PRSPI)|(1<<PRTIM0)|(1<<PRTIM1)|(1<<PRPSC)|(1<<PRCAN)))


#elif defined(__AVR_ATtiny167__) \
|| defined(__AVR_ATtiny87__) \
|| defined(__AVR_ATA5505__) \
|| defined(__AVR_ATA5272__)

#define power_adc_enable()      (PRR &= (uint8_t)~(1 << PRADC))
#define power_adc_disable()     (PRR |= (uint8_t)(1 << PRADC))

#define power_usi_enable()      (PRR &= (uint8_t)~(1 << PRUSI))
#define power_usi_disable()     (PRR |= (uint8_t)(1 << PRUSI))

#define power_timer0_enable()   (PRR &= (uint8_t)~(1 << PRTIM0))
#define power_timer0_disable()  (PRR |= (uint8_t)(1 << PRTIM0))

#define power_timer1_enable()   (PRR &= (uint8_t)~(1 << PRTIM1))
#define power_timer1_disable()  (PRR |= (uint8_t)(1 << PRTIM1))

#define power_spi_enable()      (PRR &= (uint8_t)~(1 << PRSPI))
#define power_spi_disable()     (PRR |= (uint8_t)(1 << PRSPI))

#define power_lin_enable()      (PRR &= (uint8_t)~(1 << PRLIN))
#define power_lin_disable()     (PRR |= (uint8_t)(1 << PRLIN))

#define power_all_enable()      (PRR &= (uint8_t)~((1<<PRADC)|(1<<PRUSI)|(1<<PRTIM0)|(1<<PRTIM1)|(1<<PRSPI)|(1<<PRLIN)))
#define power_all_disable()     (PRR |= (uint8_t)((1<<PRADC)|(1<<PRUSI)|(1<<PRTIM0)|(1<<PRTIM1)|(1<<PRSPI)|(1<<PRLIN)))


#elif defined(__AVR_ATtiny1634__)

#define power_adc_enable()      (PRR &= (uint8_t)~(1 << PRADC))
#define power_adc_disable()     (PRR |= (uint8_t)(1 << PRADC))

#define power_usart0_enable()      (PRR &= (uint8_t)~(1 << PRUSART0))
#define power_usart0_disable()     (PRR |= (uint8_t)(1 << PRUSART0))

#define power_usart1_enable()      (PRR &= (uint8_t)~(1 << PRUSART1))
#define power_usart1_disable()     (PRR |= (uint8_t)(1 << PRUSART1))

#define power_usi_enable()      (PRR &= (uint8_t)~(1 << PRUSI))
#define power_usi_disable()     (PRR |= (uint8_t)(1 << PRUSI))

#define power_timer0_enable()   (PRR &= (uint8_t)~(1 << PRTIM0))
#define power_timer0_disable()  (PRR |= (uint8_t)(1 << PRTIM0))

#define power_timer1_enable()   (PRR &= (uint8_t)~(1 << PRTIM1))
#define power_timer1_disable()  (PRR |= (uint8_t)(1 << PRTIM1))

#define power_twi_enable()      (PRR &= (uint8_t)~(1 << PRTWI))
#define power_twi_disable()     (PRR |= (uint8_t)(1 << PRTWI))

#define power_all_enable()      (PRR &= (uint8_t)~((1 << PRTWI)|(1 << PRUSI)|(1 << PRTIM0)|(1 << PRTIM1)|(1 << PRUSART0)|(1 << PRUSART1)|(1 << PRADC)))
#define power_all_disable()     (PRR |= (uint8_t)((1 << PRTWI)|(1 << PRUSI)|(1 << PRTIM0)|(1 << PRTIM1)|(1 << PRUSART0)|(1 << PRUSART1)|(1 << PRADC)))


#elif defined(__AVR_AT90USB82__) \
|| defined(__AVR_AT90USB162__) \
|| defined(__AVR_ATmega8U2__) \
|| defined(__AVR_ATmega16U2__) \
|| defined(__AVR_ATmega32U2__)

#define power_spi_enable()      (PRR0 &= (uint8_t)~(1 << PRSPI))
#define power_spi_disable()     (PRR0 |= (uint8_t)(1 << PRSPI))

#define power_timer0_enable()   (PRR0 &= (uint8_t)~(1 << PRTIM0))
#define power_timer0_disable()  (PRR0 |= (uint8_t)(1 << PRTIM0))

#define power_timer1_enable()   (PRR0 &= (uint8_t)~(1 << PRTIM1))
#define power_timer1_disable()  (PRR0 |= (uint8_t)(1 << PRTIM1))

#define power_usb_enable()      (PRR1 &= (uint8_t)~(1 << PRUSB))
#define power_usb_disable()     (PRR1 |= (uint8_t)(1 << PRUSB))

#define power_usart1_enable()   (PRR1 &= (uint8_t)~(1 << PRUSART1))
#define power_usart1_disable()  (PRR1 |= (uint8_t)(1 << PRUSART1))

#define power_all_enable() \
do{ \
    PRR0 &= (uint8_t)~((1<<PRSPI)|(1<<PRTIM0)|(1<<PRTIM1)); \
    PRR1 &= (uint8_t)~((1<<PRUSB)|(1<<PRUSART1)); \
}while(0)

#define power_all_disable() \
do{ \
    PRR0 |= (uint8_t)((1<<PRSPI)|(1<<PRTIM0)|(1<<PRTIM1)); \
    PRR1 |= (uint8_t)((1<<PRUSB)|(1<<PRUSART1)); \
}while(0)


#elif defined(__AVR_AT90SCR100__)

#define power_usart0_enable()   (PRR0 &= (uint8_t)~(1 << PRUSART0))
#define power_usart0_disable()  (PRR0 |= (uint8_t)(1 << PRUSART0))

#define power_spi_enable()      (PRR0 &= (uint8_t)~(1 << PRSPI))
#define power_spi_disable()     (PRR0 |= (uint8_t)(1 << PRSPI))

#define power_timer1_enable()   (PRR0 &= (uint8_t)~(1 << PRTIM1))
#define power_timer1_disable()  (PRR0 |= (uint8_t)(1 << PRTIM1))

#define power_timer0_enable()   (PRR0 &= (uint8_t)~(1 << PRTIM0))
#define power_timer0_disable()  (PRR0 |= (uint8_t)(1 << PRTIM0))

#define power_timer2_enable()   (PRR0 &= (uint8_t)~(1 << PRTIM2))
#define power_timer2_disable()  (PRR0 |= (uint8_t)(1 << PRTIM2))

#define power_twi_enable()      (PRR0 &= (uint8_t)~(1 << PRTWI))
#define power_twi_disable()     (PRR0 |= (uint8_t)(1 << PRTWI))

#define power_usbh_enable()     (PRR1 &= (uint8_t)~(1 << PRUSBH))
#define power_usbh_disable()    (PRR1 |= (uint8_t)(1 << PRUSBH))

#define power_usb_enable()      (PRR1 &= (uint8_t)~(1 << PRUSB))
#define power_usb_disable()     (PRR1 |= (uint8_t)(1 << PRUSB))

#define power_hsspi_enable()    (PRR1 &= (uint8_t)~(1 << PRHSSPI))
#define power_hsspi_disable()   (PRR1 |= (uint8_t)(1 << PRHSSPI))

#define power_sci_enable()      (PRR1 &= (uint8_t)~(1 << PRSCI))
#define power_sci_disable()     (PRR1 |= (uint8_t)(1 << PRSCI))

#define power_aes_enable()      (PRR1 &= (uint8_t)~(1 << PRAES))
#define power_aes_disable()     (PRR1 |= (uint8_t)(1 << PRAES))

#define power_kb_enable()       (PRR1 &= (uint8_t)~(1 << PRKB))
#define power_kb_disable()      (PRR1 |= (uint8_t)(1 << PRKB))

#define power_all_enable() \
do{ \
    PRR0 &= (uint8_t)~((1<<PRUSART0)|(1<<PRSPI)|(1<<PRTIM1)|(1<<PRTIM0)|(1<<PRTIM2)|(1<<PRTWI)); \
    PRR1 &= (uint8_t)~((1<<PRUSBH)|(1<<PRUSB)|(1<<PRHSSPI)|(1<<PRSCI)|(1<<PRAES)|(1<<PRKB)); \
}while(0)

#define power_all_disable() \
do{ \
    PRR0 |= (uint8_t)((1<<PRUSART0)|(1<<PRSPI)|(1<<PRTIM1)|(1<<PRTIM0)|(1<<PRTIM2)|(1<<PRTWI)); \
    PRR1 |= (uint8_t)((1<<PRUSBH)|(1<<PRUSB)|(1<<PRHSSPI)|(1<<PRSCI)|(1<<PRAES)|(1<<PRKB)); \
}while(0)


#elif defined(__AVR_ATtiny4__) \
|| defined(__AVR_ATtiny5__) \
|| defined(__AVR_ATtiny9__) \
|| defined(__AVR_ATtiny10__) \
|| defined(__AVR_ATtiny13A__) \

#define power_adc_enable()   (PRR &= (uint8_t)~(1 << PRADC))
#define power_adc_disable()  (PRR |= (uint8_t)(1 << PRADC))

#define power_timer0_enable()   (PRR &= (uint8_t)~(1 << PRTIM0))
#define power_timer0_disable()  (PRR |= (uint8_t)(1 << PRTIM0))

#define power_all_enable()      (PRR &= (uint8_t)~((1<<PRADC)|(1<<PRTIM0)))
#define power_all_disable()     (PRR |= (uint8_t)((1<<PRADC)|(1<<PRTIM0)))


#elif defined(__AVR_ATtiny20__) \
|| defined(__AVR_ATtiny40__)

#define power_adc_enable()   (PRR &= (uint8_t)~(1 << PRADC))
#define power_adc_disable()  (PRR |= (uint8_t)(1 << PRADC))

#define power_timer0_enable()   (PRR &= (uint8_t)~(1 << PRTIM0))
#define power_timer0_disable()  (PRR |= (uint8_t)(1 << PRTIM0))

#define power_timer1_enable()   (PRR &= (uint8_t)~(1 << PRTIM1))
#define power_timer1_disable()  (PRR |= (uint8_t)(1 << PRTIM1))

#define power_spi_enable()   (PRR &= (uint8_t)~(1 << PRSPI))
#define power_spi_disable()  (PRR |= (uint8_t)(1 << PRSPI))

#define power_twi_enable()   (PRR &= (uint8_t)~(1 << PRTWI))
#define power_twi_disable()  (PRR |= (uint8_t)(1 << PRTWI))

#define power_all_enable()      (PRR &= (uint8_t)~((1<<PRADC)|(1<<PRTIM0)|(1<<PRTIM1)|(1<<PRSPI)|(1<<PRTWI)))
#define power_all_disable()     (PRR |= (uint8_t)((1<<PRADC)|(1<<PRTIM0)|(1<<PRTIM1)|(1<<PRSPI)|(1<<PRTWI)))

#endif


#if defined(__AVR_AT90CAN32__) \
|| defined(__AVR_AT90CAN64__) \
|| defined(__AVR_AT90CAN128__) \
|| defined(__AVR_AT90PWM1__) \
|| defined(__AVR_AT90PWM2__) \
|| defined(__AVR_AT90PWM2B__) \
|| defined(__AVR_AT90PWM3__) \
|| defined(__AVR_AT90PWM3B__) \
|| defined(__AVR_AT90PWM81__) \
|| defined(__AVR_AT90PWM161__) \
|| defined(__AVR_AT90PWM216__) \
|| defined(__AVR_AT90PWM316__) \
|| defined(__AVR_AT90SCR100__) \
|| defined(__AVR_AT90USB646__) \
|| defined(__AVR_AT90USB647__) \
|| defined(__AVR_AT90USB82__) \
|| defined(__AVR_AT90USB1286__) \
|| defined(__AVR_AT90USB1287__) \
|| defined(__AVR_AT90USB162__) \
|| defined(__AVR_ATA5505__) \
|| defined(__AVR_ATA5272__) \
|| defined(__AVR_ATmega1280__) \
|| defined(__AVR_ATmega1281__) \
|| defined(__AVR_ATmega1284__) \
|| defined(__AVR_ATmega128RFA1__) \
|| defined(__AVR_ATmega1284RFR2__) \
|| defined(__AVR_ATmega128RFR2__) \
|| defined(__AVR_ATmega1284P__) \
|| defined(__AVR_ATmega162__) \
|| defined(__AVR_ATmega164A__) \
|| defined(__AVR_ATmega164P__) \
|| defined(__AVR_ATmega164PA__) \
|| defined(__AVR_ATmega165__) \
|| defined(__AVR_ATmega165A__) \
|| defined(__AVR_ATmega165P__) \
|| defined(__AVR_ATmega165PA__) \
|| defined(__AVR_ATmega168__) \
|| defined(__AVR_ATmega168P__) \
|| defined(__AVR_ATmega168PA__) \
|| defined(__AVR_ATmega169__) \
|| defined(__AVR_ATmega169A__) \
|| defined(__AVR_ATmega169P__) \
|| defined(__AVR_ATmega169PA__) \
|| defined(__AVR_ATmega16U4__) \
|| defined(__AVR_ATmega2560__) \
|| defined(__AVR_ATmega2561__) \
|| defined(__AVR_ATmega2564RFR2__) \
|| defined(__AVR_ATmega256RFR2__) \
|| defined(__AVR_ATmega324A__) \
|| defined(__AVR_ATmega324P__) \
|| defined(__AVR_ATmega325__) \
|| defined(__AVR_ATmega325A__) \
|| defined(__AVR_ATmega325PA__) \
|| defined(__AVR_ATmega3250__) \
|| defined(__AVR_ATmega3250A__) \
|| defined(__AVR_ATmega3250PA__) \
|| defined(__AVR_ATmega328__) \
|| defined(__AVR_ATmega328P__) \
|| defined(__AVR_ATmega329__) \
|| defined(__AVR_ATmega329A__) \
|| defined(__AVR_ATmega329P__) \
|| defined(__AVR_ATmega329PA__) \
|| defined(__AVR_ATmega3290__) \
|| defined(__AVR_ATmega3290A__) \
|| defined(__AVR_ATmega3290PA__) \
|| defined(__AVR_ATmega32C1__) \
|| defined(__AVR_ATmega32M1__) \
|| defined(__AVR_ATmega32U2__) \
|| defined(__AVR_ATmega32U4__) \
|| defined(__AVR_ATmega32U6__) \
|| defined(__AVR_ATmega48__) \
|| defined(__AVR_ATmega48A__) \
|| defined(__AVR_ATmega48PA__) \
|| defined(__AVR_ATmega48P__) \
|| defined(__AVR_ATmega640__) \
|| defined(__AVR_ATmega649P__) \
|| defined(__AVR_ATmega644__) \
|| defined(__AVR_ATmega644A__) \
|| defined(__AVR_ATmega644P__) \
|| defined(__AVR_ATmega644PA__) \
|| defined(__AVR_ATmega645__) \
|| defined(__AVR_ATmega645A__) \
|| defined(__AVR_ATmega645P__) \
|| defined(__AVR_ATmega6450__) \
|| defined(__AVR_ATmega6450A__) \
|| defined(__AVR_ATmega6450P__) \
|| defined(__AVR_ATmega649__) \
|| defined(__AVR_ATmega649A__) \
|| defined(__AVR_ATmega6490__) \
|| defined(__AVR_ATmega6490A__) \
|| defined(__AVR_ATmega6490P__) \
|| defined(__AVR_ATmega644RFR2__) \
|| defined(__AVR_ATmega64RFR2__) \
|| defined(__AVR_ATmega88__) \
|| defined(__AVR_ATmega88P__) \
|| defined(__AVR_ATmega8U2__) \
|| defined(__AVR_ATmega16U2__) \
|| defined(__AVR_ATmega32U2__) \
|| defined(__AVR_ATtiny48__) \
|| defined(__AVR_ATtiny167__) \
|| defined(__DOXYGEN__)


/** \addtogroup avr_power

Some of the newer AVRs contain a System Clock Prescale Register (CLKPR) that
allows you to decrease the system clock frequency and the power consumption
when the need for processing power is low.
On some earlier AVRs (ATmega103, ATmega64, ATmega128), similar
functionality can be achieved through the XTAL Divide Control Register.
Below are two macros and an enumerated type that can be used to
interface to the Clock Prescale Register or
XTAL Divide Control Register.

\note Not all AVR devices have a clock prescaler. On those devices
without a Clock Prescale Register or XTAL Divide Control Register, these
macros are not available.
*/


/** \addtogroup avr_power
\code 
typedef enum
{
    clock_div_1 = 0,
    clock_div_2 = 1,
    clock_div_4 = 2,
    clock_div_8 = 3,
    clock_div_16 = 4,
    clock_div_32 = 5,
    clock_div_64 = 6,
    clock_div_128 = 7,
    clock_div_256 = 8,
    clock_div_1_rc = 15, // ATmega128RFA1 only
} clock_div_t;
\endcode
Clock prescaler setting enumerations for device using
System Clock Prescale Register.

\code
typedef enum
{
    clock_div_1 = 1,
    clock_div_2 = 2,
    clock_div_4 = 4,
    clock_div_8 = 8,
    clock_div_16 = 16,
    clock_div_32 = 32,
    clock_div_64 = 64,
    clock_div_128 = 128
} clock_div_t;
\endcode
Clock prescaler setting enumerations for device using
XTAL Divide Control Register.

*/
typedef enum
{
    clock_div_1 = 0,
    clock_div_2 = 1,
    clock_div_4 = 2,
    clock_div_8 = 3,
    clock_div_16 = 4,
    clock_div_32 = 5,
    clock_div_64 = 6,
    clock_div_128 = 7,
    clock_div_256 = 8
#if defined(__AVR_ATmega128RFA1__) \
|| defined(__AVR_ATmega2564RFR2__) \
|| defined(__AVR_ATmega1284RFR2__) \
|| defined(__AVR_ATmega644RFR2__) \
|| defined(__AVR_ATmega256RFR2__) \
|| defined(__AVR_ATmega128RFR2__) \
|| defined(__AVR_ATmega64RFR2__)
    , clock_div_1_rc = 15
#endif
} clock_div_t;


static __inline__ void clock_prescale_set(clock_div_t) __attribute__((__always_inline__));

/** \addtogroup avr_power
\code clock_prescale_set(x) \endcode

Set the clock prescaler register select bits, selecting a system clock
division setting. This function is inlined, even if compiler
optimizations are disabled.

The type of \c x is \c clock_div_t.

\note For device with XTAL Divide Control Register (XDIV), \c x can actually range
from 1 to 129. Thus, one does not need to use \c clock_div_t type as argument.
*/
void clock_prescale_set(clock_div_t __x)
{
    uint8_t __tmp = _BV(CLKPCE);
    __asm__ __volatile__ (
        "in __tmp_reg__,__SREG__" "\n\t"
        "cli" "\n\t"
        "sts %1, %0" "\n\t"
        "sts %1, %2" "\n\t"
        "out __SREG__, __tmp_reg__"
        : /* no outputs */
        : "d" (__tmp),
          "M" (_SFR_MEM_ADDR(CLKPR)),
          "d" (__x)
        : "r0");
}

/** \addtogroup avr_power
\code clock_prescale_get() \endcode
Gets and returns the clock prescaler register setting. The return type is \c clock_div_t.

\note For device with XTAL Divide Control Register (XDIV), return can actually
range from 1 to 129. Care should be taken has the return value could differ from the
typedef enum clock_div_t. This should only happen if clock_prescale_set was previously
called with a value other than those defined by \c clock_div_t.
*/
#define clock_prescale_get()  (clock_div_t)(CLKPR & (uint8_t)((1<<CLKPS0)|(1<<CLKPS1)|(1<<CLKPS2)|(1<<CLKPS3)))

#elif defined(__AVR_ATmega16HVB__) \
|| defined(__AVR_ATmega16HVBREVB__) \
|| defined(__AVR_ATmega32HVB__) \
|| defined(__AVR_ATmega32HVBREVB__)

typedef enum
{
    clock_div_1 = 0,
    clock_div_2 = 1,
    clock_div_4 = 2,
    clock_div_8 = 3
} clock_div_t;

static __inline__ void clock_prescale_set(clock_div_t) __attribute__((__always_inline__));

void clock_prescale_set(clock_div_t __x)
{
    uint8_t __tmp = _BV(CLKPCE);
    __asm__ __volatile__ (
        "in __tmp_reg__,__SREG__" "\n\t"
        "cli" "\n\t"
        "sts %1, %0" "\n\t"
        "sts %1, %2" "\n\t"
        "out __SREG__, __tmp_reg__"
        : /* no outputs */
        : "d" (__tmp),
          "M" (_SFR_MEM_ADDR(CLKPR)),
          "d" (__x)
        : "r0");
}

#define clock_prescale_get()  (clock_div_t)(CLKPR & (uint8_t)((1<<CLKPS0)|(1<<CLKPS1)))

#elif defined(__AVR_ATA5790__) \
|| defined (__AVR_ATA5795__)

typedef enum
{
    clock_div_1 = 0,
    clock_div_2 = 1,
    clock_div_4 = 2,
    clock_div_8 = 3,
    clock_div_16 = 4,
    clock_div_32 = 5,
    clock_div_64 = 6,
    clock_div_128 = 7,
} clock_div_t;

static __inline__ void system_clock_prescale_set(clock_div_t) __attribute__((__always_inline__));

void system_clock_prescale_set(clock_div_t __x)
{
    uint8_t __tmp = _BV(CLKPCE);
    __asm__ __volatile__ (
        "in __tmp_reg__,__SREG__" "\n\t"
        "cli" "\n\t"
        "out %1, %0" "\n\t"
        "out %1, %2" "\n\t"
        "out __SREG__, __tmp_reg__"
        : /* no outputs */
        : "d" (__tmp),
          "I" (_SFR_IO_ADDR(CLKPR)),
          "d" (__x)
        : "r0");
}

#define system_clock_prescale_get()  (clock_div_t)(CLKPR & (uint8_t)((1<<CLKPS0)|(1<<CLKPS1)|(1<<CLKPS2)))

typedef enum
{
    timer_clock_div_reset = 0,
    timer_clock_div_1 = 1,
    timer_clock_div_2 = 2,
    timer_clock_div_4 = 3,
    timer_clock_div_8 = 4,
    timer_clock_div_16 = 5,
    timer_clock_div_32 = 6,
    timer_clock_div_64 = 7
} timer_clock_div_t;

static __inline__ void timer_clock_prescale_set(timer_clock_div_t) __attribute__((__always_inline__));

void timer_clock_prescale_set(timer_clock_div_t __x)
{
    uint8_t __t;
    __asm__ __volatile__ (
        "in __tmp_reg__,__SREG__" "\n\t"
        "cli" "\n\t"
        "in %[temp],%[clkpr]" "\n\t"
        "out %[clkpr],%[enable]" "\n\t"
        "andi %[temp],%[not_CLTPS]" "\n\t"
        "or %[temp], %[set_value]" "\n\t"
        "out %[clkpr],%[temp]" "\n\t"
        "sei" "\n\t"
        "out __SREG__,__tmp_reg__" "\n\t"
        : /* no outputs */
        : [temp] "r" (__t),
          [clkpr] "I" (_SFR_IO_ADDR(CLKPR)),
          [enable] "r" (_BV(CLKPCE)),
          [not_CLTPS] "M" (0xFF & (~ ((1 << CLTPS2) | (1 << CLTPS1) | (1 << CLTPS0)))),
          [set_value] "r" ((__x & 7) << 3)
        : "r0");
}

#define timer_clock_prescale_get()  (timer_clock_div_t)(CLKPR & (uint8_t)((1<<CLTPS0)|(1<<CLTPS1)|(1<<CLTPS2)))

#elif defined(__AVR_ATA6285__) \
|| defined(__AVR_ATA6286__)

typedef enum
{
    clock_div_1 = 0,
    clock_div_2 = 1,
    clock_div_4 = 2,
    clock_div_8 = 3,
    clock_div_16 = 4,
    clock_div_32 = 5,
    clock_div_64 = 6,
    clock_div_128 = 7
} clock_div_t;

static __inline__ void system_clock_prescale_set(clock_div_t) __attribute__((__always_inline__));

void system_clock_prescale_set(clock_div_t __x)
{
    uint8_t __t;
    __asm__ __volatile__ (
        "in __tmp_reg__,__SREG__" "\n\t"
        "cli" "\n\t"
        "in %[temp],%[clpr]" "\n\t"
        "out %[clpr],%[enable]" "\n\t"
        "andi %[temp],%[not_CLKPS]" "\n\t"
        "or %[temp], %[set_value]" "\n\t"
        "out %[clpr],%[temp]" "\n\t"
        "sei" "\n\t"
        "out __SREG__,__tmp_reg__" "\n\t"
        : /* no outputs */
        : [temp] "r" (__t),
          [clpr] "I" (_SFR_IO_ADDR(CLKPR)),
          [enable] "r" _BV(CLPCE),
          [not_CLKPS] "M" (0xFF & (~ ((1 << CLKPS2) | (1 << CLKPS1) | (1 << CLKPS0)))),
          [set_value] "r" (__x & 7)
        : "r0");
}

#define system_clock_prescale_get()  (clock_div_t)(CLKPR & (uint8_t)((1<<CLKPS0)|(1<<CLKPS1)|(1<<CLKPS2)))

typedef enum
{
    timer_clock_div_reset = 0,
    timer_clock_div_1 = 1,
    timer_clock_div_2 = 2,
    timer_clock_div_4 = 3,
    timer_clock_div_8 = 4,
    timer_clock_div_16 = 5,
    timer_clock_div_32 = 6,
    timer_clock_div_64 = 7
} timer_clock_div_t;

static __inline__ void timer_clock_prescale_set(timer_clock_div_t) __attribute__((__always_inline__));

void timer_clock_prescale_set(timer_clock_div_t __x)
{
    uint8_t __t;
    __asm__ __volatile__ (
        "in __tmp_reg__,__SREG__" "\n\t"
        "cli" "\n\t"
        "in %[temp],%[clpr]" "\n\t"
        "out %[clpr],%[enable]" "\n\t"
        "andi %[temp],%[not_CLTPS]" "\n\t"
        "or %[temp], %[set_value]" "\n\t"
        "out %[clpr],%[temp]" "\n\t"
        "sei" "\n\t"
        "out __SREG__,__tmp_reg__" "\n\t"
        : /* no outputs */
        : [temp] "r" (__t),
          [clpr] "I" (_SFR_IO_ADDR(CLKPR)),
          [enable] "r" (_BV(CLPCE)),	  
          [not_CLTPS] "M" (0xFF & (~ ((1 << CLTPS2) | (1 << CLTPS1) | (1 << CLTPS0)))),
          [set_value] "r" ((__x & 7) << 3)
        : "r0");
}

#define timer_clock_prescale_get()  (timer_clock_div_t)(CLKPR & (uint8_t)((1<<CLTPS0)|(1<<CLTPS1)|(1<<CLTPS2)))

#elif defined(__AVR_ATtiny24__) \
|| defined(__AVR_ATtiny24A__) \
|| defined(__AVR_ATtiny44__) \
|| defined(__AVR_ATtiny44A__) \
|| defined(__AVR_ATtiny84__) \
|| defined(__AVR_ATtiny84A__) \
|| defined(__AVR_ATtiny25__) \
|| defined(__AVR_ATtiny45__) \
|| defined(__AVR_ATtiny85__) \
|| defined(__AVR_ATtiny261A__) \
|| defined(__AVR_ATtiny261__) \
|| defined(__AVR_ATtiny461__) \
|| defined(__AVR_ATtiny461A__) \
|| defined(__AVR_ATtiny861__) \
|| defined(__AVR_ATtiny861A__) \
|| defined(__AVR_ATtiny2313__) \
|| defined(__AVR_ATtiny2313A__) \
|| defined(__AVR_ATtiny4313__) \
|| defined(__AVR_ATtiny13__) \
|| defined(__AVR_ATtiny13A__) \
|| defined(__AVR_ATtiny43U__) \

typedef enum
{
    clock_div_1 = 0,
    clock_div_2 = 1,
    clock_div_4 = 2,
    clock_div_8 = 3,
    clock_div_16 = 4,
    clock_div_32 = 5,
    clock_div_64 = 6,
    clock_div_128 = 7,
    clock_div_256 = 8
} clock_div_t;

static __inline__ void clock_prescale_set(clock_div_t) __attribute__((__always_inline__));

void clock_prescale_set(clock_div_t __x)
{
    uint8_t __tmp = _BV(CLKPCE);
    __asm__ __volatile__ (
        "in __tmp_reg__,__SREG__" "\n\t"
        "cli" "\n\t"
        "out %1, %0" "\n\t"
        "out %1, %2" "\n\t"
        "out __SREG__, __tmp_reg__"
        : /* no outputs */
        : "d" (__tmp),
          "I" (_SFR_IO_ADDR(CLKPR)),
          "d" (__x)
        : "r0");
}


#define clock_prescale_get()  (clock_div_t)(CLKPR & (uint8_t)((1<<CLKPS0)|(1<<CLKPS1)|(1<<CLKPS2)|(1<<CLKPS3)))

#elif defined(__AVR_ATmega64__) \
|| defined(__AVR_ATmega103__) \
|| defined(__AVR_ATmega128__)

//Enum is declared for code compatibility
typedef enum
{
    clock_div_1 = 1,
    clock_div_2 = 2,
    clock_div_4 = 4,
    clock_div_8 = 8,
    clock_div_16 = 16,
    clock_div_32 = 32,
    clock_div_64 = 64,
    clock_div_128 = 128
} clock_div_t;

static __inline__ void clock_prescale_set(clock_div_t) __attribute__((__always_inline__));

void clock_prescale_set(clock_div_t __x)
{
    if((__x <= 0) || (__x > 129))
    {
        return;//Invalid value.
    }
    else
    {
        uint8_t __tmp = 0;
        //Algo explained:
        //1 - Clear XDIV in order for it to accept a new value (actually only
        //    XDIVEN need to be cleared, but clearing XDIV is faster than
        //    read-modify-write since we will rewrite XDIV later anyway)
        //2 - wait 8 clock cycle for stability, see datasheet erreta
        //3 - Exist if requested prescaller is 1
        //4 - Calculate XDIV6..0 value = 129 - __x
        //5 - Set XDIVEN bit in calculated value
        //6 - write XDIV with calculated value
        //7 - wait 8 clock cycle for stability, see datasheet erreta
        __asm__ __volatile__ (
            "in __tmp_reg__,__SREG__" "\n\t"
            "cli" "\n\t"
            "out %1, __zero_reg__" "\n\t"
            "nop" "\n\t"
            "nop" "\n\t"
            "nop" "\n\t"
            "nop" "\n\t"
            "nop" "\n\t"
            "nop" "\n\t"
            "nop" "\n\t"
            "nop" "\n\t"
            "cpi %0, 0x01" "\n\t"
            "breq L_%=" "\n\t"
            "ldi %2, 0x81" "\n\t" //129
            "sub %2, %0" "\n\t"
            "ori %2, 0x80" "\n\t" //128
            "out %1, %2" "\n\t"
            "nop" "\n\t"
            "nop" "\n\t"
            "nop" "\n\t"
            "nop" "\n\t"
            "nop" "\n\t"
            "nop" "\n\t"
            "nop" "\n\t"
            "nop" "\n\t"
            "L_%=: " "out __SREG__, __tmp_reg__"
            : /* no outputs */
            :"d" (__x),
             "I" (_SFR_IO_ADDR(XDIV)),
             "d" (__tmp)
            : "r0");
    }
}

static __inline__ clock_div_t clock_prescale_get(void) __attribute__((__always_inline__));

clock_div_t clock_prescale_get(void)
{
    if(bit_is_clear(XDIV, XDIVEN))
    {
        return 1;
    }
    else
    {
        return (clock_div_t)(129 - (XDIV & 0x7F));
    }
}
 
#elif defined(__AVR_ATtiny4__) \
|| defined(__AVR_ATtiny5__) \
|| defined(__AVR_ATtiny9__) \
|| defined(__AVR_ATtiny10__) \
|| defined(__AVR_ATtiny20__) \
|| defined(__AVR_ATtiny40__) \

typedef enum 
{ 
    clock_div_1 = 0, 
    clock_div_2 = 1, 
    clock_div_4 = 2, 
    clock_div_8 = 3, 
    clock_div_16 = 4, 
    clock_div_32 = 5, 
    clock_div_64 = 6, 
    clock_div_128 = 7, 
    clock_div_256 = 8 
} clock_div_t; 

static __inline__ void clock_prescale_set(clock_div_t) __attribute__((__always_inline__));

void clock_prescale_set(clock_div_t __x)
{
    uint8_t __tmp = 0xD8;
    __asm__ __volatile__ (
        "in __tmp_reg__,__SREG__" "\n\t"
        "cli" "\n\t"
        "out %1, %0" "\n\t"
        "out %2, %3" "\n\t"
        "out __SREG__, __tmp_reg__"
        : /* no outputs */
        : "d" (__tmp),
          "I" (_SFR_IO_ADDR(CCP)),
          "I" (_SFR_IO_ADDR(CLKPSR)),
          "d" (__x)
        : "r16");
}

#define clock_prescale_get()  (clock_div_t)(CLKPSR & (uint8_t)((1<<CLKPS0)|(1<<CLKPS1)|(1<<CLKPS2)|(1<<CLKPS3)))
 
#endif

#endif /* _AVR_POWER_H_ */
