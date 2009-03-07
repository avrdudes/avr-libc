/* Copyright (c) 2008  Dmitry Xmelkov
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
   POSSIBILITY OF SUCH DAMAGE.
 */

/* GCC bug #31644: [avr] can't find a register in class 'BASE_POINTER_REGS'
   while reloading 'asm'
   This is compile-time bug.
   $Id$	*/

#ifndef	__AVR__
int main ()	{ return 0; }
#else

#include <avr/eeprom.h>

uint8_t pwm_tab_1[126];

static uint16_t ee_chan_1_min EEMEM = 140,
    ee_chan_1_cent EEMEM = 188,
    ee_chan_1_max EEMEM = 240,
    ee_chan_1_forw_min EEMEM = 20,
    ee_chan_1_forw_max EEMEM = 90,
    ee_chan_1_back_max EEMEM = 80;

void fill_pwm_table(int8_t chan_num,
		    uint8_t pwm[],
		    int16_t forward_max,
		    int16_t center,
		    int16_t reverse_min,
		    int16_t forward_high,
		    int16_t forward_low,
		    int16_t reverse_high)
{
    pwm[0] = chan_num;
    pwm[1] = forward_max;
    pwm[2] = center;
    pwm[3] = reverse_min;
    pwm[4] = forward_high;
    pwm[5] = forward_low;
    pwm[6] = reverse_high;
}

void build_pwm_table (void)
{
    int16_t center_1,
	    forward_max_1,
	    reverse_min_1,
	    forward_high_1,
	    forward_low_1,
	    reverse_high_1;

    center_1 = eeprom_read_word (&ee_chan_1_cent);

    forward_max_1 = eeprom_read_word (&ee_chan_1_max);
    reverse_min_1 = eeprom_read_word (&ee_chan_1_min);
    forward_high_1 = eeprom_read_word (&ee_chan_1_forw_max);
    forward_low_1 = eeprom_read_word (&ee_chan_1_forw_min);
    reverse_high_1 = eeprom_read_word (&ee_chan_1_back_max);

    fill_pwm_table (1, pwm_tab_1, forward_max_1, center_1,
		    reverse_min_1,
		    forward_high_1, forward_low_1, reverse_high_1);

    fill_pwm_table (1, pwm_tab_1, forward_max_1, center_1,
		    reverse_min_1,
		    forward_high_1, forward_low_1, reverse_high_1);
}

int main ()
{
    build_pwm_table ();
    return 0;
}
#endif
