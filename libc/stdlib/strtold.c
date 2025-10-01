/* Copyright (c) 2002-2005  Michael Stumpf  <mistumpf@de.pepperl-fuchs.com>
   Copyright (c) 2006,2008  Dmitry Xmelkov
   Copyright (c) 2025       Georg-Johann Lay  

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

#if !defined(__AVR_TINY__) && __SIZEOF_LONG_DOUBLE__ == 8

#include <ctype.h>
#include <errno.h>
#include <math.h>
#include <stdlib.h>
#include <stdint.h>

#include <avr/flash.h>
#include <avr/pgmspace.h>
#include <bits/attribs.h>

#include "alias.h"
#include "best_as.h"
#include "sectionname.h"

#define ARRAY_SIZE(X) (sizeof(X) / sizeof(*X))

#define INFINITYl (__builtin_infl())
#define NANl      (__builtin_nanl(""))

#define AS __BEST_AS

#ifdef __AVR_HAVE_ELPM__
// Don't assume we have __flashx.
#define READ_LD(p) pgm_read_long_double_far ((uintptr24_t) (p))
#define S_STRNCASECMP "strncasecmp_PF"
#define S_MEMCPY      "memcpy_PF"
#else
#define READ_LD(p) flash_read_long_double (p)
#define S_STRNCASECMP "strncasecmp_P"
#define S_MEMCPY      "memcpy_P"
#endif // ELPM?

int strncasecmp_AS (const char*, const AS char*, size_t) __asm(S_STRNCASECMP);

#define PROG_SECTION __attribute__((__section__(".progmemx.data.pwr_10L")))

#ifdef __WITH_LIBF7_MATH__
// Use libgcc's low level routines if we have them.  This is faster since
// when expanding the exponent, we don't have to convert double to the
// internal representation back and forth.
#include "f7/libf7.h"

#if __AVR_ARCH__ == 103
// No need to copy them constants from flash to RAM since avrxmega3
// can access them directly.  Other devices with rodata-in-flash may
// have -mrodata-in-ram, so we cannot do it there.
#  define RODATA_IN_FLASH
#  undef PROG_SECTION
#  define PROG_SECTION __attribute__((__section__(".rodata.pwr_10L")))
#  define AS_PWR // empty
#  define copy_f7(dest, src, size) (src)
#else
#  define AS_PWR AS
extern f7_t* copy_f7 (f7_t*, const AS f7_t*, size_t) __asm(S_MEMCPY);
#endif

PROG_SECTION static const AS_PWR f7_t pwr_p10L[] =
{
    F7_CONST_DEF (X, 0, 0xa0,0x00,0x00,0x00,0x00,0x00,0x00, 3),   // 1e1
    F7_CONST_DEF (X, 0, 0xc8,0x00,0x00,0x00,0x00,0x00,0x00, 6),   // 1e2
    F7_CONST_DEF (X, 0, 0x9c,0x40,0x00,0x00,0x00,0x00,0x00, 13),  // 1e4
    F7_CONST_DEF (X, 0, 0xbe,0xbc,0x20,0x00,0x00,0x00,0x00, 26),  // 1e8
    F7_CONST_DEF (X, 0, 0x8e,0x1b,0xc9,0xbf,0x04,0x00,0x00, 53),  // 1e16
    F7_CONST_DEF (X, 0, 0x9d,0xc5,0xad,0xa8,0x2b,0x70,0xb6, 106), // 1e32
    F7_CONST_DEF (X, 0, 0xc2,0x78,0x1f,0x49,0xff,0xcf,0xa7, 212), // 1e64
    F7_CONST_DEF (X, 0, 0x93,0xba,0x47,0xc9,0x80,0xe9,0x8d, 425), // 1e128
    F7_CONST_DEF (X, 0, 0xaa,0x7e,0xeb,0xfb,0x9d,0xf9,0xdf, 850)  // 1e256
};

PROG_SECTION static const AS_PWR f7_t pwr_m10L[] =
{
    F7_CONST_DEF (X, 0, 0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcd, -4),   // 1e-1
    F7_CONST_DEF (X, 0, 0xa3,0xd7,0x0a,0x3d,0x70,0xa3,0xd7, -7),   // 1e-2
    F7_CONST_DEF (X, 0, 0xd1,0xb7,0x17,0x58,0xe2,0x19,0x65, -14),  // 1e-4
    F7_CONST_DEF (X, 0, 0xab,0xcc,0x77,0x11,0x84,0x61,0xcf, -27),  // 1e-8
    F7_CONST_DEF (X, 0, 0xe6,0x95,0x94,0xbe,0xc4,0x4d,0xe1, -54),  // 1e-16
    F7_CONST_DEF (X, 0, 0xcf,0xb1,0x1e,0xad,0x45,0x39,0x95, -107), // 1e-32
    F7_CONST_DEF (X, 0, 0xa8,0x7f,0xea,0x27,0xa5,0x39,0xea, -213), // 1e-64
    F7_CONST_DEF (X, 0, 0xdd,0xd0,0x46,0x7c,0x64,0xbc,0xe5, -426), // 1e-128
    F7_CONST_DEF (X, 0, 0xc0,0x31,0x43,0x25,0x63,0x7a,0x19, -851)  // 1e-256
};

#else

extern long double __floatundidf (uint64_t); // libgcc

PROG_SECTION static const AS long double pwr_p10L[] =
{
    1e+1L, 1e+2L, 1e+4L, 1e+8L, 1e+16L, 1e+32L, 1e+64L, 1e+128L, 1e+256L
};

PROG_SECTION static const AS long double pwr_m10L[] =
{
    1.0e-1L, 1e-2L, 1e-4L, 1e-8L, 1e-16L, 1e-32L, 1e-64L, 1e-128L, 1e-256L
};

#endif // Have LibF7

#define LAST_PWR (ARRAY_SIZE (pwr_p10L) - 1)


static __ATTR_ALWAYS_INLINE__ int
mulhi10 (int i)
{
    register int r24 __asm("24") = i;
    __asm ("%~call __mulhi_const_10"
           : "+r" (r24) :: "22", "23");
    return r24;
}

// misc/madddi10.S: return 10 * a + b;
extern uint64_t madddi10 (uint64_t a, uint8_t b) __asm("__madddi_const_10");

// libc/stdlib/pstr_inf.c
extern const AS char __pstr_inf[3];
extern const AS char __pstr_inity[5];
extern const AS char __pstr_nan[3];

/**  The strtold() function converts the initial portion of the string pointed
     to by \a nptr to \c long \c double representation.

     The expected form of the string is an optional plus ( \c '+' ) or minus
     sign ( \c '-' ) followed by a sequence of digits optionally containing
     a decimal-point character, optionally followed by an exponent.  An
     exponent consists of an \c 'E' or \c 'e', followed by an optional plus
     or minus sign, followed by a sequence of digits.

     Leading white-space characters in the string are skipped.

     The strtold() function returns the converted value, if any.

     If \a endptr is not \c NULL, a pointer to the character after the last
     character used in the conversion is stored in the location referenced by
     \a endptr.

     If no conversion is performed, zero is returned and the value of
     \a nptr is stored in the location referenced by \a endptr.

     If the correct value would cause overflow, plus or minus \c INFINITY is
     returned (according to the sign of the value), and \c ERANGE is stored
     in \c errno.  If the correct value would cause underflow, zero is
     returned and \c ERANGE is stored in \c errno.
 */
ATTRIBUTE_CLIB_SECTION
long double
strtold (const char *nptr, char **endptr)
{
    union
    {
	uint64_t u64;
	long double ldbl;
#ifdef __WITH_LIBF7_MATH__
	f7_t f7;
#endif
    } x;
    uint8_t c;
    uint8_t flag = 0;

#define FL_MINUS    0x01	// number is negative
#define FL_ANY	    0x02	// any digit was read
#define FL_OVFL	    0x04	// mantissa overflow: dropping excess precision
#define FL_DOT	    0x08	// decimal '.' was seen
#define FL_MEXP	    0x10	// exponent 'e' is neg

    if (endptr)
	*endptr = (char*) nptr;

    do
	c = *nptr++;
    while (isspace (c));

    if (c == '-')
    {
	flag = FL_MINUS;
	c = *nptr++;
    }
    else if (c == '+')
	c = *nptr++;

    if (!strncasecmp_AS (nptr - 1, __pstr_inf, sizeof (__pstr_inf)))
    {
	nptr += sizeof (__pstr_inf) - 1;
	if (!strncasecmp_AS (nptr, __pstr_inity, sizeof (__pstr_inity)))
	    nptr += sizeof (__pstr_inity);
	if (endptr)
	    *endptr = (char*) nptr;
	return flag & FL_MINUS ? -INFINITYl : +INFINITYl;
    }

    // NAN() construction is not realised.
    // Length would be 3 characters only.
    if (!strncasecmp_AS (nptr - 1, __pstr_nan, sizeof (__pstr_nan)))
    {
	if (endptr)
	    *endptr = (char*) nptr + sizeof (__pstr_nan) - 1;
	return NANl;
    }

    x.u64 = 0;
    int expo = 0;

    // Read the mantissa, keeping stock of dot's (if any) position in expo.
    for (;;)
    {
	c -= '0';

	if (c <= 9)
	{
	    flag |= FL_ANY;
	    if (flag & FL_OVFL)
	    {
		if (!(flag & FL_DOT))
		    expo += 1;
	    }
	    else
	    {
		if (flag & FL_DOT)
		    expo -= 1;
		// x.u64 = 10 * x.u64 + c
		x.u64 = madddi10 (x.u64, c);
		if (x.u64 >= (UINT64_MAX - 9) / 10)
		    flag |= FL_OVFL;
	    }
	}
	else if (c == (('.'-'0') & 0xff) && !(flag & FL_DOT))
	    flag |= FL_DOT;
	else
	    break;

	c = *nptr++;
    }

    // Read the exponent (if any).
    if (c == (('e'-'0') & 0xff) || c == (('E'-'0') & 0xff))
    {
	c = *nptr++;
	int i = 2;
	if (c == '-')
	{
	    flag |= FL_MEXP;
	    c = *nptr++;
	}
	else if (c == '+')
	    c = *nptr++;
	else
	    i = 1;
	c -= '0';
	if (c > 9)
	    nptr -= i;
	else
	{
	    i = 0;
	    do
	    {
		if (i < 3200)
		    i = mulhi10 (i) + c;	// i = 10*i + c
		c = *nptr++ - '0';
	    } while (c <= 9);
	    if (flag & FL_MEXP)
		i = -i;
	    expo += i;
	}
    }

    if ((flag & FL_ANY) && endptr)
	*endptr = (char*) nptr - 1;

#ifdef __WITH_LIBF7_MATH__

    f7_t *xx = &x.f7;

    // Convert mantissa and sign to f7_t.
    f7_set_u64 (xx, x.u64);

    if ((flag & FL_MINUS) && (flag & FL_ANY))
	xx->sign ^= F7_FLAG_sign;

    // Apply the exponent using its binary expansion.
    if (f7_is_nonzero (xx))
    {
	const AS_PWR f7_t *l_pwr;
#ifndef RODATA_IN_FLASH
	f7_t pp10;
#endif

	if (expo < 0)
	{
	    l_pwr = pwr_m10L + LAST_PWR;
	    expo = -expo;
	}
	else
	    l_pwr = pwr_p10L + LAST_PWR;

	for (int pwr = 1 << LAST_PWR; pwr; pwr >>= 1, --l_pwr)
	    for (; expo >= pwr; expo -= pwr)
		f7_Imul (xx, copy_f7 (&pp10, l_pwr, sizeof (f7_t)));

	uint8_t x_class = f7_classify (xx);
	if (!f7_class_number (x_class) || f7_class_zero (x_class))
	    errno = ERANGE;
    }

    // f7_get_double() returns double as uint64_t.
    x.u64 = f7_get_double (xx);

#else // Do vanilla double arithmetic

    // Convert mantissa and sign to long double.
    x.ldbl = __floatundidf (x.u64);
    if ((flag & FL_MINUS) && (flag & FL_ANY))
	x.ldbl = -x.ldbl;

    // Apply the exponent using its binary expansion.
    if (x.ldbl != 0)
    {
	const AS long double *l_pwr;

	if (expo < 0)
	{
	    l_pwr = pwr_m10L + LAST_PWR;
	    expo = -expo;
	}
	else
	    l_pwr = pwr_p10L + LAST_PWR;

	for (int pwr = 1 << LAST_PWR; pwr; pwr >>= 1, --l_pwr)
	    for (; expo >= pwr; expo -= pwr)
		x.ldbl *= READ_LD (l_pwr);

	if (!isfinitel (x.ldbl) || x.ldbl == 0)
	    errno = ERANGE;
    }
#endif

    return x.ldbl;
}


DALIAS_LD (strtold)
double strtod (const char*, char**);

#endif // !AVR_TINY && long double is 64-bit
