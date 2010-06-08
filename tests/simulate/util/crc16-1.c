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
   Part 1: CRC-16, x^16 + x^15 + x^2 + 1 (0xa001), ANSI X3.28 */

#include <stdint.h>
#include <stdlib.h>

#ifdef	__AVR__
# include <util/crc16.h>
#else  /* host computer */

static uint16_t
_crc16_update(uint16_t crc, uint8_t a)
{
    int i;

    crc ^= a;
    for (i = 0; i < 8; ++i)
    {
        if (crc & 1)
            crc = (crc >> 1) ^ 0xA001;
        else
            crc = (crc >> 1);
    }

    return crc;
}

#endif  /* AVR */

const char message[] = "Hello, world!";
const size_t mlen = 13;

/*
 * See MODBUS Over Serial Line FOR LEGACY APPLICATIONS ONLY
 *
 * http://www.modbus.org/docs/PI_MBUS_300.pdf
 *
 * for an alternate (table based) reference implementation.  Note that
 * this implementation internally byte swaps the CRC, so the result
 * there is 0x4971.
 */
const uint16_t crc_result = 0x7149;

int main(void)
{
    uint16_t crc = 0xffff;
    uint8_t i;

    for (i = 0; i < mlen; i++)
        crc = _crc16_update(crc, message[i]);
    if (crc != crc_result) return __LINE__;

    return 0;
}

