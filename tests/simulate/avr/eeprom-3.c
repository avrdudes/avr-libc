/* Copyright (c) 2009  Dmitry Xmelkov
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
   POSSIBILITY OF SUCH DAMAGE.	*/

/* Test of update EEPROM functions.
   $Id$	*/

#include <avr/eeprom.h>
#include <avr/pgmspace.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
    void *p;

    /* Fill all EEPROM.	*/
    for (p = 0; p <= (void *)E2END; p++)
	eeprom_write_byte (p, (int)(p + 1));
    
    /* Update a byte.	*/
    {
	unsigned char *p = (unsigned char *)1;
	
	eeprom_update_byte (p, 2);	/* the same value	*/
	if (!eeprom_is_ready ()) exit (__LINE__);
	if (eeprom_read_byte (p) != 2) exit (__LINE__);

	eeprom_update_byte (p, 0x12);	/* different value	*/
	if (eeprom_is_ready ()) exit (__LINE__);
	if (eeprom_read_byte (p) != 0x12) exit (__LINE__);
    }

    /* Update a word.	*/
    {
	unsigned int *p = (unsigned int *)2;

	eeprom_update_word (p, 0x0403);		/* the same value	*/
	if (!eeprom_is_ready ()) exit (__LINE__);
	if (eeprom_read_word (p) != 0x0403) exit (__LINE__);

	eeprom_update_word (p, 0x0413);
	if (eeprom_is_ready ()) exit (__LINE__);
	if (eeprom_read_word (p) != 0x0413) exit (__LINE__);

	eeprom_update_word (p, 0x1413);
	if (!eeprom_is_ready ()) exit (__LINE__);
	if (eeprom_read_word (p) != 0x1413) exit (__LINE__);
    }

    /* Update a double word.	*/
    {
	unsigned long *p = (unsigned long *)4;

	eeprom_update_dword (p, 0x08070605);	/* the same value	*/
	if (!eeprom_is_ready ()) exit (__LINE__);
	if (eeprom_read_dword (p) != 0x08070605) exit (__LINE__);

	eeprom_update_dword (p, 0x08070615);
	if (eeprom_is_ready ()) exit (__LINE__);
	if (eeprom_read_dword (p) != 0x08070615) exit (__LINE__);

	eeprom_update_dword (p, 0x08071615);
	if (!eeprom_is_ready ()) exit (__LINE__);
	if (eeprom_read_dword (p) != 0x08071615) exit (__LINE__);

	eeprom_update_dword (p, 0x08171615);
	if (!eeprom_is_ready ()) exit (__LINE__);
	if (eeprom_read_dword (p) != 0x08171615) exit (__LINE__);

	eeprom_update_dword (p, 0x18171615);
	if (!eeprom_is_ready ()) exit (__LINE__);
	if (eeprom_read_dword (p) != 0x18171615) exit (__LINE__);
    }

    /* Update a block.	*/
    {
	unsigned char *p = (unsigned char *)8;
	unsigned char s[5];
	
	memcpy_P (s, PSTR ("\x09\x0A\x0B\x0C\x0D"), 5);
	eeprom_update_block (s, p, 5);
	if (!eeprom_is_ready ()) exit (__LINE__);
	memset (s, 0, sizeof (s));
	eeprom_read_block (s, p, 5);
	if (memcmp_P (s, PSTR ("\x09\x0A\x0B\x0C\x0D"), 5)) exit (__LINE__);

	memcpy_P (s, PSTR ("\x19\x0A\x0B\x0C\x0D"), 5);
	eeprom_update_block (s, p, 5);
	if (eeprom_is_ready ()) exit (__LINE__);
	memset (s, 0, sizeof (s));
	eeprom_read_block (s, p, 5);
	if (memcmp_P (s, PSTR ("\x19\x0A\x0B\x0C\x0D"), 5)) exit (__LINE__);

	memcpy_P (s, PSTR ("\x19\x0A\x0B\x0C\x1D"), 5);
	eeprom_update_block (s, p, 5);
	if (!eeprom_is_ready ()) exit (__LINE__);
	memset (s, 0, sizeof (s));
	eeprom_read_block (s, p, 5);
	if (memcmp_P (s, PSTR ("\x19\x0A\x0B\x0C\x1D"), 5)) exit (__LINE__);
	
	memcpy_P (s, PSTR ("\x1A\x1B\x1C"), 3);
	eeprom_update_block (s, p + 1, 1);
	eeprom_update_block (s + 1, p + 2, 2);
    }

    /* Check all EEPROM.	*/
    for (p = 0; p <= (void *)E2END; p++) {
	unsigned char c;
	c = (int)p + ((p && (p < (void *)13)) ? 0x11 : 1);
	if (eeprom_read_byte (p) != c)
	    exit (__LINE__);
    }

    return 0;
}
