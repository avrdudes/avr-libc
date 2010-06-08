/* Copyright (c) 2010  Joerg Wunsch
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

/* $Id$ */

/* Test the various CRC algorithms.
   Part 2: CCITT-CRC x^16 + x^12 + x^5 + 1 (0x8408) */

#include <stdint.h>
#include <stdlib.h>

#ifdef	__AVR__
# include <util/crc16.h>
#else  /* host computer */

static uint16_t
_crc_ccitt_update (uint16_t crc, uint8_t data)
{
    data ^= crc & 0xff;
    data ^= data << 4;

    return ((((uint16_t)data << 8) | ((crc & 0xff00) >> 8))
            ^ (uint8_t)(data >> 4)
            ^ ((uint16_t)data << 3));
}

#endif  /* AVR */

/*
 * Test vector taken from IEEE 802.15.4 standard.  This is a complete
 * frame that already includes the frame-check sequence (FCS), so
 * recalculating it must yield 0.
 */
const char message[] = "\x02\x00\x6a\xe4\x79";
const size_t mlen = 5;


int main(void)
{
    uint16_t crc = 0;
    uint8_t i;

    for (i = 0; i < mlen; i++)
        crc = _crc_ccitt_update(crc, message[i]);
    if (crc != 0) return __LINE__;

    return 0;
}

