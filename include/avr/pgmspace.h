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

/*
   pgmspace.h

   Contributors:
     Created by Marek Michalkiewicz <marekm@linux.org.pl>
 */

/*
   pgmspace.h - this is an attempt to provide some compatibility with
   header files that come with IAR C, to make porting applications
   between different compilers easier.  No 100% compatibility though
   (GCC does not have full support for multiple address spaces yet).
 */

#ifndef __PGMSPACE_H_
#define __PGMSPACE_H_ 1

#define __need_size_t
#include <stddef.h>

/* #include <io.h> */

#ifndef __ATTR_CONST__
#define __ATTR_CONST__ __attribute__((__const__))
#endif

#ifndef __ATTR_PROGMEM__
#define __ATTR_PROGMEM__ __attribute__((__progmem__))
#endif

#ifndef __ATTR_PURE__
#define __ATTR_PURE__ __attribute__((__pure__))
#endif

#define PROGMEM __ATTR_PROGMEM__

#ifdef __cplusplus
extern "C" {
#endif

typedef void prog_void PROGMEM;
typedef char prog_char PROGMEM;
typedef unsigned char prog_uchar PROGMEM;
typedef int prog_int PROGMEM;
typedef long prog_long PROGMEM;
typedef long long prog_long_long PROGMEM;

#define PSTR(s) ({static char __c[] PROGMEM = (s); __c;})

/* _LPM(), _ELPM() */
#include <ina90.h>

static inline unsigned char __lpm_inline(unsigned short __addr) __ATTR_CONST__;
static inline unsigned char __lpm_inline(unsigned short __addr)
{
	return _LPM(__addr);
}

#ifdef RAMPZ  /* >64K program memory (ATmega103) */
/*
   use this for access to >64K program memory (ATmega103),
   addr = RAMPZ:r31:r30 (if possible, put your constant tables in the
   lower 64K and use "lpm" - it is more efficient that way, and you can
   still use the upper 64K for executable code).
 */

static inline unsigned char __elpm_inline(unsigned long __addr) __ATTR_CONST__;
static inline unsigned char __elpm_inline(unsigned long __addr)
{
	return _ELPM(__addr);
}
#endif

#if 0
#define PRG_RDB(addr) __lpm_inline((unsigned short)(addr))
#else
#define PRG_RDB(addr) _LPM((unsigned short)(addr))
#endif

#ifndef PGM_P
#define PGM_P const prog_char *
#endif

#ifndef PGM_VOID_P
#define PGM_VOID_P const prog_void *
#endif

extern void *memcpy_P(void *, PGM_VOID_P, size_t);
extern char *strcat_P(char *, PGM_P);
extern int strcmp_P(const char *, PGM_P) __ATTR_PURE__;
extern char *strcpy_P(char *, PGM_P);
extern int strcasecmp_P(const char *, PGM_P) __ATTR_PURE__;
extern size_t strlen_P(PGM_P) __ATTR_CONST__; /* program memory can't change */
extern int strncmp_P(const char *, PGM_P, size_t) __ATTR_PURE__;
extern int strncasecmp_P(const char *, PGM_P, size_t) __ATTR_PURE__;
extern char *strncpy_P(char *, PGM_P, size_t);

#if 0  /* not implemented yet */
extern int printf_P(PGM_P, ...);
extern int puts_P(PGM_P);
extern int scanf_P(PGM_P, ...);
extern int sprintf_P(char *, PGM_P, ...);
extern int sscanf_P(const char *, PGM_P, ...);
extern PGM_P strerror_P(int);
#endif

#ifdef __cplusplus
}
#endif

#endif /* __PGMSPACE_H_ */

