/* Copyright (c) 2005, Anatoly Sokolov
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

/* avr/iotn84.h - definitions for ATtiny84 */

#ifndef _AVR_IOTN84_H_
#define _AVR_IOTN84_H_ 1

#include <avr/iotnx4.h>

#define RAMEND                0x25F
#define XRAMEND               0x25F
#define E2END                 0x1FF
#define FLASHEND              0x1FFF
#define SPM_PAGESIZE          64


/* Fuses */

#define FUSE_MEMORY_SIZE 3

/* Low Fuse Byte */
#define CKSEL0      ~_BV(0)
#define CKSEL1      ~_BV(1)
#define CKSEL2      ~_BV(2)
#define CKSEL3      ~_BV(3)
#define SUT0        ~_BV(4)
#define SUT1        ~_BV(5)
#define CKOUT       ~_BV(6)
#define CKDIV8      ~_BV(7)
#define LFUSE_DEFAULT (CKSEL0 & CKSEL2 & CKSEL3 & SUT0 & CKDIV8)

/* High Fuse Byte */
#define BODLEVEL0   ~_BV(0)
#define BODLEVEL1   ~_BV(1)
#define BODLEVEL2   ~_BV(2)
#define EESAVE      ~_BV(3)
#define WDTON       ~_BV(4)
#define SPIEN       ~_BV(5)
#define DWEN        ~_BV(6)
#define RSTDISBL    ~_BV(7)
#define HFUSE_DEFAULT (SPIEN)

/* Extended Fuse Byte */
#define SELFPRGEN   ~_BV(0)
#define EFUSE_DEFAULT (0xFF)


/* Lock Bits */
#define __LOCK_BITS_EXIST


#endif /* _AVR_IOTN84_H_ */
