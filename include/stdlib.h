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

#ifndef _STDLIB_H_
#define	_STDLIB_H_ 1

#define __need_NULL
#define __need_size_t
#define __need_wchar_t
#include <stddef.h>

#ifndef __ptr_t
#define __ptr_t void *
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	int quot;
	int rem;
} div_t;

typedef struct {
	long quot;
	long rem;
} ldiv_t;

typedef int (*__compar_fn_t)(const void *, const void *);

#define	RAND_MAX 0x7FFFFFFF

#ifndef __ATTR_CONST__
#define __ATTR_CONST__ __attribute__((__const__))
#endif

#ifndef __ATTR_MALLOC__
#define __ATTR_MALLOC__ __attribute__((__malloc__))
#endif

#ifndef __ATTR_NORETURN__
#define __ATTR_NORETURN__ __attribute__((__noreturn__))
#endif

#ifndef __ATTR_PURE__
#define __ATTR_PURE__ __attribute__((__pure__))
#endif

extern __inline__ void abort(void) __ATTR_NORETURN__;
extern __inline__ void
abort(void)
{
	for (;;);
}

extern __inline__ int abs(int __x) __ATTR_CONST__;
extern __inline__ int
abs(int __x)
{
	return (__x < 0) ? -__x : __x;
}

extern __inline__ long labs(long __x) __ATTR_CONST__;
extern __inline__ long
labs(long __x)
{
	return (__x < 0) ? -__x : __x;
}

extern void *bsearch(const void *, const void *, size_t, size_t,
	int (*)(const void *, const void *));

/* __divmodhi4 and __divmodsi4 from libgcc.a */
extern div_t div(int, int) __asm__("__divmodhi4") __ATTR_CONST__;
extern ldiv_t ldiv(long, long) __asm__("__divmodsi4") __ATTR_CONST__;

extern void qsort(void *, size_t, size_t, __compar_fn_t);

extern long strtol(const char *, char **, int);
extern unsigned long strtoul(const char *, char **, int);

extern __inline__ long atol(const char *) __ATTR_PURE__;
extern __inline__ long
atol(const char *__p)
{
	return strtol(__p, (char **) 0, 10);
}

#if 0
extern __inline__ int atoi(const char *__p) __ATTR_PURE__;
extern __inline__ int
atoi(const char *__p)
{
	return (int) atol(__p);
}
#else
/* optimized asm version, much smaller if strtol() not used elsewhere */
extern int atoi(const char *) __ATTR_PURE__;
#endif

extern void exit(int) __ATTR_NORETURN__;

extern void *malloc(size_t) __ATTR_MALLOC__;
extern void free(void *);

/*
 * When extending the data segment, the allocator will not try to go
 * beyond the current stack limit, decreased by __malloc_margin bytes.
 * Thus, all possible stack frames of interrupt routines that could
 * interrupt the current function, plus all further nested function
 * calls must not require more stack space, or they'll risk to collide
 * with the data segment.
 *
 * The default is set to 32.  __malloc_margin should be changed before
 * the very first call to malloc() within the application.
 */
extern size_t __malloc_margin;

extern char *__malloc_heap_start;
extern char *__malloc_heap_end;

/* implemented but not tested */
extern double strtod(const char *, char **);

/* non-standard (i.e. non-ANSI C) functions */
extern char *itoa(int __val, char *__s, int __radix);
extern char *ltoa(long int __val, char *__s, int __radix);
extern char *utoa(unsigned int __val, char *__s, int __radix);
extern char *ultoa(unsigned long int __val, char *__s, int __radix);
extern char *dtostre(double __val, char *__s, unsigned char __ndig, unsigned char __flags);
extern char *dtostrf(double __val, char __width, char __prec, char *__s);

#if 0  /* not yet implemented */
extern int atexit(void (*)(void));
extern double atof(const char *);
extern void *calloc(size_t, size_t);
extern int rand(void);
extern void *realloc(void *, size_t);
extern void srand(unsigned int);
#endif

#ifdef __cplusplus
}
#endif

#endif /* _STDLIB_H_ */
