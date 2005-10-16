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
   string.h

   Contributors:
     Created by Marek Michalkiewicz <marekm@linux.org.pl>
 */

#ifndef	_STRING_H_
#define	_STRING_H_ 1

#define	__need_NULL
#define	__need_size_t
#include <stddef.h>

#ifndef __ATTR_PURE__
#define __ATTR_PURE__ __attribute__((__pure__))
#endif

#ifdef __cplusplus
extern "C" {
#endif

/** \defgroup avr_string <string.h>: Strings
    \code #include <string.h> \endcode

    The string functions perform string operations on NULL terminated
    strings. 

    \note If the strings you are working on resident in program space (flash),
    you will need to use the string functions described in \ref avr_pgmspace. */

/** \ingroup avr_string

    This function find the first (least significant) bit set in the input value.
    
    \returns The ffs() function returns the position of the first
    (least significant) bit set in the word val, or 0 if no bits are set.
    The least significant bit is position 1.
    
    \note The ffs() (and only ffs()) is implemented as macro, that evaluates
    a constant argument at compile time.	*/
extern int ffs (int val) __attribute__((const));

/* FIXME: expression, like 'ffs(ffs(ffs(...(CONSTANT)))', take very
   large amount of memory at compile time.	*/
#define	ffs(x) ( \
    __builtin_constant_p (x) ?	\
	( (x) & 1 ? 1		\
	: (x) & 2 ? 2		\
	: (x) & 4 ? 3		\
	: (x) & 010 ? 4		\
	: (x) & 020 ? 5		\
	: (x) & 040 ? 6		\
	: (x) & 0100 ? 7	\
	: (x) & 0200 ? 8	\
	: (x) & 0400 ? 9	\
	: (x) & 01000 ? 10	\
	: (x) & 02000 ? 11	\
	: (x) & 04000 ? 12	\
	: (x) & 010000 ? 13	\
	: (x) & 020000 ? 14	\
	: (x) & 040000 ? 15	\
	: (x) & 0100000 ? 16	\
	: 0 )			\
    : ffs(x) )

/** \ingroup avr_string
    Same as ffs(), for an argument of type long.	*/
extern int ffsl (long val) __attribute__((const));

/** \ingroup avr_string
    Same as ffs(), for an argument of type long long.	*/
extern int ffsll (long long val) __attribute__((const));

extern void *memccpy(void *, const void *, int, size_t);
extern void *memchr(const void *, int, size_t) __ATTR_PURE__;
extern int memcmp(const void *, const void *, size_t) __ATTR_PURE__;
extern void *memcpy(void *, const void *, size_t);
extern void *memmove(void *, const void *, size_t);
extern void *memset(void *, int, size_t);
extern char *strcat(char *, const char *);
extern char *strchr(const char *, int) __ATTR_PURE__;
extern int strcmp(const char *, const char *) __ATTR_PURE__;
extern char *strcpy(char *, const char *);
extern int strcasecmp(const char *, const char *) __ATTR_PURE__;
extern size_t strlcat(char *, const char *, size_t);
extern size_t strlcpy(char *, const char *, size_t);
extern size_t strlen(const char *) __ATTR_PURE__;
extern char *strlwr(char *);
extern char *strncat(char *, const char *, size_t);
extern int strncmp(const char *, const char *, size_t) __ATTR_PURE__;
extern char *strncpy(char *, const char *, size_t);
extern int strncasecmp(const char *, const char *, size_t) __ATTR_PURE__;
extern size_t strnlen(const char *, size_t) __ATTR_PURE__;
extern char *strrchr(const char *, int) __ATTR_PURE__;
extern char *strrev(char *);
extern char *strsep(char **, const char *);
extern char *strstr(const char *, const char *) __ATTR_PURE__;
extern char *strtok_r(char *, const char *, char **);
extern char *strupr(char *);

#ifdef __cplusplus
}
#endif

#endif /* _STRING_H_ */

