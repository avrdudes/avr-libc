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

/* $Id$ */

/*
   pgmspace.h

   Contributors:
     Created by Marek Michalkiewicz <marekm@linux.org.pl>
 */

/** \defgroup avr_pgmspace Program Space String Utilities
    \code
    #include <avr/io.h>
    #include <avr/pgmspace.h>
    \endcode

    The functions in this module provide interfaces for a program to access
    data stored in program space (flash memory) of the device.  In order to
    use these functions, the target device must support either the \c LPM or
    \c ELPM instructions.

    \note These function are an attempt to provide some compatibility with
    header files that come with IAR C, to make porting applications between
    different compilers easier.  This is not 100% compatibility though (GCC
    does not have full support for multiple address spaces yet).

    \note If you are working with strings which are completely based in ram,
    use the standard string functions described in \ref avr_string. */

#ifndef __PGMSPACE_H_
#define __PGMSPACE_H_ 1

#define __need_size_t
#include <stddef.h>

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

/** \ingroup avr_pgmspace
    \def PSTR(s)

    Used to declare a static pointer to a string in program space. */

#define PSTR(s) ({static char __c[] PROGMEM = (s); __c;})

#define __LPM_enhanced__(addr) ({		\
	unsigned short __addr16 = (unsigned short)(addr); \
	unsigned char __result;			\
	__asm__ (				\
		"lpm %0, Z"			\
		: "=r" (__result)		\
		: "z" (__addr16)		\
	);					\
	__result;				\
 })

#define __LPM_classic__(addr) ({		\
	unsigned short __addr16 = (unsigned short)(addr); \
	unsigned char __result;			\
	__asm__ (				\
		"lpm" "\n\t"			\
		"mov %0, r0"			\
		: "=r" (__result)		\
		: "z" (__addr16)		\
		: "r0"				\
	);					\
	__result;				\
 })

/* Only for devices with more than 64K of program memory.
   RAMPZ must be defined (see iom103.h).  */

#define __ELPM_enhanced__(addr) ({		\
	unsigned long __addr32 = (unsigned long)(addr); \
	unsigned char __result;			\
	__asm__ (				\
		"out %2, %C1" "\n\t"		\
		"movw r30, %1" "\n\t"		\
		"elpm %0, Z"			\
		: "=r" (__result)		\
		: "r" (__addr32),		\
		  "I" (_SFR_IO_ADDR(RAMPZ))	\
		: "r30", "r31"			\
	);					\
	__result;				\
 })

#define __ELPM_classic__(addr) ({		\
	unsigned long __addr32 = (unsigned long)(addr); \
	unsigned char __result;			\
	__asm__ (				\
		"out %2, %C1" "\n\t"		\
		"mov r31, %B1" "\n\t"		\
		"mov r30, %A1" "\n\t"		\
		"elpm" "\n\t"			\
		"mov %0, r0"			\
		: "=r" (__result)		\
		: "r" (__addr32),		\
		  "I" (_SFR_IO_ADDR(RAMPZ))	\
		: "r0", "r30", "r31"		\
	);					\
	__result;				\
 })

#if defined (__AVR_ENHANCED__)
#define  __LPM(addr)  __LPM_enhanced__(addr)
#define __ELPM(addr) __ELPM_enhanced__(addr)
#else
#define  __LPM(addr)  __LPM_classic__(addr)
#define __ELPM(addr) __ELPM_classic__(addr)
#endif


static inline unsigned char __lpm_inline(unsigned short __addr) __ATTR_CONST__;
static inline unsigned char __lpm_inline(unsigned short __addr)
{
	return __LPM(__addr);
}

#ifdef RAMPZ  /* >64K program memory (ATmega103) */

/** \ingroup avr_pgmspace
    \fn inline unsigned char __elpm_inline(unsigned long __addr)

    Use this for access to >64K program memory (ATmega103, ATmega128),
    addr = RAMPZ:r31:r30

    \note If possible, put your constant tables in the lower 64K and use "lpm"
    since it is more efficient that way, and you can still use the upper 64K
    for executable code.  */

static inline unsigned char __elpm_inline(unsigned long __addr) __ATTR_CONST__;
static inline unsigned char __elpm_inline(unsigned long __addr)
{
	return __ELPM(__addr);
}
#endif

#if 0
#define PRG_RDB(addr) __lpm_inline((unsigned short)(addr))
#else
#define PRG_RDB(addr) __LPM((unsigned short)(addr))
#endif

/** \ingroup avr_pgmspace
    \def PGM_P

    Used to declare a variable that is a pointer to a string in program
    space. */

#ifndef PGM_P
#define PGM_P const prog_char *
#endif

/** \ingroup avr_pgmspace
    \def PGM_VOID_P

    Used to declare a generic pointer to an object in program space. */

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
extern char *strncat(char *, PGM_P, size_t);
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

