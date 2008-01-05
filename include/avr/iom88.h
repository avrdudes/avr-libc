/* Copyright (c) 2004, Theodore A. Roth
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

#ifndef _AVR_IOM88_H_
#define _AVR_IOM88_H_ 1

#include <avr/iomx8.h>

/* Constants */
#define SPM_PAGESIZE 64
#define RAMEND      0x4FF
#define XRAMEND     0x4FF
#define E2END       0x1FF
#define FLASHEND    0x1FFF


/* Fuses */
#define FUSE_MEMORY_SIZE 3

/* Low Fuse Byte */
#define FUSE_CKSEL0 ~_BV(0)  /* Select Clock Source */
#define FUSE_CKSEL1 ~_BV(1)  /* Select Clock Source */
#define FUSE_CKSEL2 ~_BV(2)  /* Select Clock Source */
#define FUSE_CKSEL3 ~_BV(3)  /* Select Clock Source */
#define FUSE_SUT0   ~_BV(4)  /* Select start-up time */
#define FUSE_SUT1   ~_BV(5)  /* Select start-up time */
#define FUSE_CKOUT  ~_BV(6)  /* Clock output */
#define FUSE_CKDIV8 ~_BV(7) /* Divide clock by 8 */
#define LFUSE_DEFAULT (CKSEL0 & CKSEL2 & CKSEL3 & SUT0 & CKDIV8)

/* High Fuse Byte */
#define FUSE_BODLEVEL0 ~_BV(0)  /* Brown-out Detector trigger level */
#define FUSE_BODLEVEL1 ~_BV(1)  /* Brown-out Detector trigger level */
#define FUSE_BODLEVEL2 ~_BV(2)  /* Brown-out Detector trigger level */
#define FUSE_EESAVE    ~_BV(3)  /* EEPROM memory is preserved through chip erase */
#define FUSE_WDTON     ~_BV(4)  /* Watchdog Timer Always On */
#define FUSE_SPIEN     ~_BV(5)  /* Enable Serial programming and Data Downloading */
#define FUSE_DWEN      ~_BV(6)  /* debugWIRE Enable */
#define FUSE_RSTDISBL  ~_BV(7)  /* External reset disable */
#define HFUSE_DEFAULT (SPIEN)

/* Extended Fuse Byte */
#define FUSE_SELFPRGEN ~_BV(0)  /* Self Programming Enable */
#define EFUSE_DEFAULT (0xFF)


/* Lock Bits */
#define __LOCK_BITS_EXIST
#define __BOOT_LOCK_BITS_0_EXIST
#define __BOOT_LOCK_BITS_1_EXIST 


#endif /* _AVR_IOM88_H_ */

