/* Copyright (c) 2007  Dmitry Xmelkov
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

#ifdef	__AVR__

# include <avr/pgmspace.h>

# define pgm_read_qword(addr)	({			\
    union {						\
	unsigned long __dw[2];				\
	unsigned long long __qw[1];			\
    } __u;						\
    __u.__dw[0] = pgm_read_dword (addr);		\
    __u.__dw[1] = pgm_read_dword ((void *)addr + 4);	\
    __u.__qw[0];					\
  })

#else

# define PROGMEM
# define PSTR(s)		(s)
# define pgm_read_byte(addr)	(*(unsigned char *)(addr))
# define pgm_read_word(addr)	(*(unsigned int *)(addr))
# define pgm_read_dword(addr)	(*(unsigned long *)(addr))
# define pgm_read_float(addr)	(*(float *)(addr))
# define pgm_read_qword(addr)	(*(unsigned long long *)(addr))
# define strlen_P		strlen
# define strcmp_P		strcmp
# define strcpy_P		strcpy
# define memcpy_P		memcpy

#endif
