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

/*
   eeprom.h

   Contributors:
     Created by Marek Michalkiewicz <marekm@linux.org.pl>
 */

#ifndef _EEPROM_H_
#define _EEPROM_H_ 1

#define __need_size_t
#include <stddef.h>

#include <io.h>

/* return 1 if EEPROM is ready for a new read/write operation, 0 if not */
#define eeprom_is_ready() bit_is_clear(EECR, EEWE)

#ifdef __cplusplus
extern "C" {
#endif

/* read one byte from EEPROM address ADDR */
extern unsigned char eeprom_rb(unsigned int addr);

/* read one 16-bit word (little endian) from EEPROM address ADDR */
extern unsigned int eeprom_rw(unsigned int addr);

/* write a byte VAL to EEPROM address ADDR */
extern void eeprom_wb(unsigned int addr, unsigned char val);

/* read a block of SIZE bytes from EEPROM address ADDR to BUF */
extern void eeprom_read_block(void *buf, unsigned int addr, size_t n);


#ifdef __cplusplus
}
#endif

/* IAR C compatibility defines */
#define _EEPUT(addr, val) eeprom_wb(addr, val)
#define _EEGET(var, addr) (var) = eeprom_rb(addr)

#endif /* _EEPROM_H_ */
