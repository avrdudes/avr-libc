/* Copyright (c) 2008,2009  Dmitry Xmelkov
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

/* $Id$	*/

#include <avr/eeprom.h>
#include <stdlib.h>
#include <string.h>

/* Note: GCC permits arithmetic with 'void *'.	*/

int main ()
{
    void *p;
#define MAXLEN	(RAMEND > 0x15F ? 260 : (RAMEND - 0x60 - 30))
    unsigned char s[E2END > MAXLEN ? MAXLEN : E2END];

    /* Fill all EEPROM.	*/
    for (p = 0; p <= (void *)E2END; p++)
	eeprom_write_byte (p, ~(int)p);

    /* Read bytes.	*/
    for (p = 0; p <= (void *)E2END; p++)
	if (eeprom_read_byte (p) != (~(int)p & 0xFF))
	    exit (__LINE__);

    /* Read words.	*/
    for (p = 0; p <= (void *)E2END - 1; p += 2) {
	if (eeprom_read_word (p)
	    != ((~(unsigned)p & 0xFF) | (~(unsigned)(p+1) & 0xFF) << 8))
	{
	    exit (__LINE__);
	}
    }

    /* Read double words.	*/
    for (p = 0; p <= (void *)E2END - 3; p += 4) {
	if (eeprom_read_dword (p)
	    != ((~(unsigned)p & 0xFF)
		| (~(unsigned)(p+1) & 0xFF) << 8
		| (unsigned long)(~(unsigned)(p+2) & 0xFF) << 16
		| (unsigned long)(~(unsigned)(p+3) & 0xFF) << 24))
	{
	    exit (__LINE__);
	}
    }

    /* Read blocks.	*/
    for (p = 0; p <= (void *)E2END; ) {
	size_t i, n;
	if ( (n = E2END + 1 - (unsigned)p) > sizeof(s))
	    n = sizeof(s);
	eeprom_read_block (s, p, n);
	for (i = 0; i < n; i++) {
	    if (s[i] != (~(int)p & 0xFF))
		exit (__LINE__);
	    p += 1;
	}
    }

    /* Write only 1 byte.	*/
    eeprom_write_byte ((unsigned char *)5, 1);
    for (p = 0; p <= (void *)E2END; p++) {
	if ((unsigned)p != 5
	    && eeprom_read_byte (p) != (~(int)p & 0xFF))
	{
	    exit (__LINE__);
	}
    }
    if (eeprom_read_byte ((unsigned char *)5) != 1)
	exit (__LINE__);

    /* Write only 1 word.	*/
    /* Avr-gcc 4.2.2 produces incorrect code: the comparison of address
       with 5 and 6 values is omited. In result exit with error.
       Versions 3.3.6, 3.4.6, 4.0.4, 4.1.2, 4.2.3, 4.3.0(pre) give
       correct code and are simulated OK.	*/
    eeprom_write_word ((unsigned *)5, 0x1234);
    for (p = 0; p <= (void *)E2END; p++) {
	if ((unsigned)p != 5
	    && (unsigned)p != 6
	    && eeprom_read_byte (p) != (~(int)p & 0xFF))
	{
	    exit (__LINE__);
	}
    }
    if (eeprom_read_word ((unsigned *)5) != 0x1234)
	exit (__LINE__);

    /* Write only 1 double word.	*/
    eeprom_write_dword ((unsigned long *)5, 0x12345678);
    for (p = 0; p <= (void *)E2END; p++) {
	if (((unsigned)p < 5 || (unsigned)p > 8)
	    && eeprom_read_byte (p) != (~(int)p & 0xFF))
	{
	    exit (__LINE__);
	}
    }
    if (eeprom_read_dword ((unsigned long *)5) != 0x12345678)
	exit (__LINE__);

    /* Write block.	*/
    eeprom_write_block ("\x90\xAB\xCD\xEF\x01", (void *)5, 5);
    for (p = 0; p <= (void *)E2END; p++) {
	if (((unsigned)p < 5 || (unsigned)p > 9)
	    && eeprom_read_byte (p) != (~(int)p & 0xFF))
	{
	    exit (__LINE__);
	}
    }
    eeprom_read_block (s, (const void *)5, 5);
    if (memcmp (s, "\x90\xAB\xCD\xEF\x01", 5))
	exit (__LINE__);

    return 0;
}
