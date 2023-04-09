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

# $Id$

Register usage of internally-used functions, common archs:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    eeprom_read_blraw:
	Input:
	    r27,r26	- data space address (destination)
	    r25,r24	- EEPROM address
	    r21,r20	- number of bytes
	Scratch:
	    common call-used regs.

    eeprom_update_r18:
	Input:
	    r18		- byte to write
	    r25,r24	- EEPROM address
	Output:
	    r25,r24	- decremented EEPROM address
	Scratch:
	    r0

    eeprom_update_byte:
	Input:
	    r22		- byte to write
	    r25,r24	- EEPROM address
	Output:
	    r25,r24	- decremented EEPROM address
	Scratch:
	    r18,r0

    eeprom_write_r18:
	Input:
	    r18		- byte to write
	    r25,r24	- EEPROM address
	Output:
	    r25,r24	- incremented EEPROM address
	Scratch:
	    r0

    eeprom_write_byte:
	Input:
	    r22		- byte to write
	    r25,r24	- EEPROM address
	Output:
	    r25,r24	- incremented EEPROM address
	Scratch:
	    r18,r0


Register usage of internally-used functions, XMEGA arch:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    eeprom_mapen:
	Input:
	    r25,r24	- EEPROM address
	Output:
	    ZH,ZL	- EEPROM address + 0x2000 (to use mapping)
	Scratch:
	    r19

    eeprom_update_r18:
	Input:
	    r18		- byte to write
	    r25,r24	- EEPROM address
	Output:
	    r25,r24	- decremented EEPROM address
	Scratch:
	    r31,r30,r19,r18,r0

    eeprom_update_byte:
	Input:
	    r22		- byte to write
	    r25,r24	- EEPROM address
	Output:
	    r25,r24	- decremented EEPROM address
	Scratch:
	    r31,r30,r19,r18,r0

    eeprom_write_r18:
	Input:
	    r18		- byte to write
	    r25,r24	- EEPROM address
	Output:
	    r25,r24	- incremented EEPROM address
	Scratch:
	    r31,r30,r19,r18

    eeprom_write_byte:
	Input:
	    r22		- byte to write
	    r25,r24	- EEPROM address
	Output:
	    r25,r24	- incremented EEPROM address
	Scratch:
	    r31,r30,r27,r26,r19,r18
	    Only r27,r26 is used when EEPROM is always memory mapped
