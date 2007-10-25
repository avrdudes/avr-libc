/* Copyright (c) 2007, Atmel Corporation
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

/* avr/lock.h - Lock Bits API */

#ifndef _AVR_LOCK_H_
#define _AVR_LOCK_H_  1


#ifndef __ASSEMBLER__

#define LOCKMEM  __attribute__((section (".lock")))

#define LOCKBITS unsigned char __lock LOCKMEM

#endif  /* !__ASSEMBLER */


/* Lock Bit Modes */
#if defined(__LOCK_BITS_EXIST)
#define LB_MODE_1  (0xFF)
#define LB_MODE_2  (0xFE)
#define LB_MODE_3  (0xFC)
#endif

#if defined(__BOOT_LOCK_BITS_0_EXIST)
#define BLB0_MODE_1  (0xFF)
#define BLB0_MODE_2  (0xFB)
#define BLB0_MODE_3  (0xF3)
#define BLB0_MODE_4  (0xF7)
#endif

#if defined(__BOOT_LOCK_BITS_1_EXIST)
#define BLB1_MODE_1  (0xFF)
#define BLB1_MODE_2  (0xEF)
#define BLB1_MODE_3  (0xCF)
#define BLB1_MODE_4  (0xDF)
#endif

#define LOCKBITS_DEFAULT (0xFF)

#endif /* _AVR_LOCK_H_ */
