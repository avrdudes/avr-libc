/* Copyright (c) 2002,2004,2005 Joerg Wunsch
   Copyright (c) 2008  Dmitry Xmelkov
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

#if !defined(__AVR_TINY__)

#include <avr/pgmspace.h>
#include <ctype.h>
#include <math.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "sectionname.h"
#include "stdio_private.h"

#define ARRAY_SIZE(X) (sizeof(X) / sizeof(*X))

#ifndef VFSCANF_NAME
#define VFSCANF_NAME vfscanf
#endif

#if	!defined (SCANF_LEVEL)
# ifndef SCANF_WWIDTH		/* use word for width variable	*/
#  define SCANF_WWIDTH 0
# endif
# ifndef SCANF_BRACKET		/* use '%[' conversion	*/
#  define SCANF_BRACKET	0
# endif
# ifndef SCANF_FLOAT		/* use float point conversion	*/
#  define SCANF_FLOAT	0
# endif
#elif	SCANF_LEVEL == SCANF_MIN
# define SCANF_WWIDTH	0
# define SCANF_BRACKET	0
# define SCANF_FLOAT	0
#elif	SCANF_LEVEL == SCANF_STD
# define SCANF_WWIDTH	0
# define SCANF_BRACKET	1
# define SCANF_FLOAT	0
#elif	SCANF_LEVEL == SCANF_FLT
# define SCANF_WWIDTH	1
# define SCANF_BRACKET	1
# define SCANF_FLOAT	1
#else
# error	 "Not a known scanf level."
#endif

#if	SCANF_WWIDTH
typedef uint16_t width_t;
#else
typedef uint8_t width_t;
#endif

#ifndef	DISABLE_ASM
# if	 defined(__AVR__) && __AVR__
#  define DISABLE_ASM	0
# else
#  define DISABLE_ASM	1
# endif
#endif

#if  SHRT_MAX != INT_MAX
# error  "SHRT_MAX != INT_MAX for target: not supported"
#endif

/* ATTENTION: check FL_CHAR first, not FL_LONG. The last is set
   simultaneously.	*/
#define FL_STAR	    0x01	/* '*': skip assignment		*/
#define FL_WIDTH    0x02	/* width is present		*/
#define FL_LONG	    0x04	/* 'long' type modifier		*/
#define FL_CHAR	    0x08	/* 'char' type modifier		*/
#define FL_OCT	    0x10	/* octal number			*/
#define FL_DEC	    0x20	/* decimal number		*/
#define FL_HEX	    0x40	/* hexidecimal number		*/
#define FL_MINUS    0x80	/* minus flag (field or value)	*/

#ifndef	__AVR_HAVE_LPMX__
# if  defined(__AVR_ENHANCED__) && __AVR_ENHANCED__
#  define __AVR_HAVE_LPMX__	1
# endif
#endif

#ifndef	__AVR_HAVE_MOVW__
# if  defined(__AVR_ENHANCED__) && __AVR_ENHANCED__
#  define __AVR_HAVE_MOVW__	1
# endif
#endif

#if  DISABLE_ASM
# define GETBYTE(flag, mask, pnt)		\
    ({						\
	uint8_t __c = ((flag) & (mask))		\
	    ? pgm_read_byte(pnt)		\
	    : *pnt;				\
	pnt++;					\
	__c;					\
    })
#elif  defined(__AVR_HAVE_LPMX__) && __AVR_HAVE_LPMX__
# define GETBYTE(flag, mask, pnt)		\
    ({						\
	uint8_t __c;				\
	asm (					\
	    "sbrc	%2,%3"	"\n\t"		\
	    "lpm	%0,Z+"	"\n\t"		\
	    "sbrs	%2,%3"	"\n\t"		\
	    "ld	%0,Z+"				\
	    : "=&r" (__c),			\
	      "+z" (pnt)			\
	    : "r" (flag),			\
	      "I" (_FFS(mask) - 1)		\
	    );					\
	__c;					\
    })
#else
# define GETBYTE(flag, mask, pnt)		\
    ({						\
	uint8_t __c;				\
	asm (					\
	    "lpm"		"\n\t"		\
	    "sbrs	%2,%3"	"\n\t"		\
	    "ld		r0,Z"   "\n\t"		\
	    "adiw	r30,1"	"\n\t"		\
	    "mov	%0,r0"			\
	    : "=r" (__c),			\
	      "+z" (pnt)			\
	    : "r" (flag),			\
	      "I" (_FFS(mask) - 1)		\
	    : "r0");				\
	__c;					\
})
#endif

/* Add noinline attribute to avoid GCC 4.2 optimization.	*/

__attribute__((noinline))
ATTRIBUTE_CLIB_SECTION
static void putval (void *addr, long val, uint8_t flags)
{
    if (!(flags & FL_STAR))
    {
#if  DISABLE_ASM
	if (flags & FL_CHAR)
	    *(char*) addr = val;
	else if (flags & FL_LONG)
	    *(long*) addr = val;
	else
	    *(int*) addr = val;
#else
	asm volatile (
	    "sbrc    %[flags], %[bit_char]	\n\t"
	    "rjmp    1f				\n\t"
	    "sbrs    %[flags], %[bit_long]	\n\t"
	    "rjmp    2f				\n\t"
	    "std     Z+3, %D1			\n\t"
	    "std     Z+2, %C1			\n"
    "2:      std     Z+1, %B1			\n"
    "1:      std     Z+0, %A1"
	    :
	    : "z"(addr), "r"(val), [flags]"r"(flags),
	      [bit_char] "M"(_FFS(FL_CHAR) - 1),
	      [bit_long] "M"(_FFS(FL_LONG) - 1)
	    : "memory");
#endif
    }
}

__attribute__((noinline))
ATTRIBUTE_CLIB_SECTION
static unsigned long
mulacc (unsigned long val, uint8_t flags, uint8_t c)
{
    uint8_t cnt;

    if (flags & FL_OCT)
	cnt = 3;
    else if (flags & FL_HEX)
	cnt = 4;
    else
    {
#if  DISABLE_ASM
	val += val << 2;
#else
	asm (
# if  defined(__AVR_HAVE_MOVW__) && __AVR_HAVE_MOVW__
	    "movw    r26, %A0"		"\n\t"
	    "movw    r30, %C0"		"\n"
# else
	    "mov     r26, %A0"		"\n\t"
	    "mov     r27, %B0"		"\n\t"
	    "mov     r30, %C0"		"\n\t"
	    "mov     r31, %D0"		"\n"
# endif
    "1:      lsl     r26"		"\n\t"
	    "rol     r27"		"\n\t"
	    "rol     r30"		"\n\t"
	    "rol     r31"		"\n\t"
	    "com     __zero_reg__"	"\n\t"
	    "brne    1b"		"\n\t"
	    "add     %A0, r26"		"\n\t"
	    "adc     %B0, r27"		"\n\t"
	    "adc     %C0, r30"		"\n\t"
	    "adc     %D0, r31"
	    : "+r" (val)
	    :
	    : "r26", "r27", "r30", "r31");
#endif
	cnt = 1;
    }

    do
	val <<= 1;
    while (--cnt);

    return val + c;
}

__attribute__((noinline))
ATTRIBUTE_CLIB_SECTION
static uint8_t
conv_int (FILE *stream, width_t width, void *addr, uint8_t flags)
{
    int i = getc (stream);			// after ungetc()

    switch ((uint8_t) i)
    {
	case '-':
	    flags |= FL_MINUS;
	    /* FALLTHROUGH */

	case '+':
	    if (!--width || (i = getc(stream)) < 0)
		goto err;
    }

    uint32_t val = 0;
    flags &= ~FL_WIDTH;

    if (!(flags & (FL_DEC | FL_OCT)) && (uint8_t) i == '0')
    {
	if (!--width || (i = getc (stream)) < 0)
	    goto putval;
	flags |= FL_WIDTH;
	if ((uint8_t) i == 'x' || (uint8_t) i == 'X')
	{
	    flags |= FL_HEX;
	    if (!--width || (i = getc(stream)) < 0)
		goto putval;
	}
	else
	{
	    if (!(flags & FL_HEX))
		flags |= FL_OCT;
	}
    }

/* This fact is used below to parse hexidecimal digit.	*/
#if	('A' - '0') != (('a' - '0') & ~('A' ^ 'a'))
# error
#endif
    do {
	uint8_t c = i;
	c -= '0';
	if (c > 7)
	{
	    if (flags & FL_OCT)
		goto unget;
	    if (c > 9)
	    {
		if (!(flags & FL_HEX))
		    goto unget;
		c &= ~('A' ^ 'a');
		c += '0' - 'A';
		if (c > 5)
		{
		unget:
		    ungetc (i, stream);
		    break;
		}
		c += 10;
	    }
	}
	val = mulacc (val, flags, c);
	flags |= FL_WIDTH;
	if (!--width)
	    goto putval;
    }
    while ((i = getc(stream)) >= 0);

    if (!(flags & FL_WIDTH))
	goto err;

putval:
    if (flags & FL_MINUS)
	val = -val;
    putval (addr, val, flags);
    return 1;

err:
    return 0;
}

#if  SCANF_BRACKET
__attribute__((noinline))
ATTRIBUTE_CLIB_SECTION
static const char *
conv_brk (FILE *stream, width_t width, char *addr, const char *fmt)
{
    uint8_t msk[32];
    uint8_t fnegate;
    uint8_t frange;
    uint8_t cabove;
    int i;

    memset (msk, 0, sizeof(msk));
    fnegate = 0;
    frange = 0;
    cabove = 0;			/* init to avoid compiler warning	*/

    for (i = 0; ; i++)
    {
	uint8_t c = GETBYTE(stream->flags, __SPGM, fmt);

	if (c == 0)
	{
	    return 0;
	}
	else if (c == '^' && !i)
	{
	    fnegate = 1;
	    continue;
	}
	else if (i > fnegate)
	{
	    if (c == ']')
		break;
	    if (c == '-' && !frange)
	    {
		frange = 1;
		continue;
	    }
	}

	if (!frange)
	    cabove = c;

	for (;;)
	{
	    msk[c >> 3] |= 1 << (c & 7);
	    if (c == cabove)
		break;
	    if (c < cabove)
		c++;
	    else
		c--;
	}

	frange = 0;
    }
    if (frange)
	msk['-' / 8] |= 1 << ('-' & 7);

    if (fnegate)
    {
	uint8_t *p = msk;
	do {
	    uint8_t c = *p;
	    *p++ = ~c;
	} while (p != msk + sizeof(msk));
    }

    /* And now it is a flag of fault.	*/
    fnegate = 1;

    /* NUL ('\0') is considered as a normal character. This is match to Glibc.
       Note, there is no method to include NUL into symbol list.	*/
    do {
	i = getc (stream);
	if (i < 0)
	    break;
	if (!((msk[(uint8_t) i >> 3] >> (i & 7)) & 1))
	{
	    ungetc (i, stream);
	    break;
	}
	if (addr)
	    *addr++ = i;
	fnegate = 0;
    } while (--width);

    if (fnegate)
	return 0;
    else
    {
	if (addr)
	    *addr = 0;
        return fmt;
    }
}
#endif	/* SCANF_BRACKET */

#if  SCANF_FLOAT

/* GCC before 4.2 does not use a library function to convert an unsigned
   long to float.  Instead it uses a signed long to float conversion
   function along with a large inline code to correct the result.
   Seems, GCC 4.3 does not use it also.	*/
extern float __floatunsisf (uint32_t);

/* In libc/stdio/pwr_10.c */
extern const float __avrlibc_pwr_p10[6];
extern const float __avrlibc_pwr_m10[6];

#define LAST_PWR (ARRAY_SIZE (__avrlibc_pwr_p10) - 1)

PROGMEM_FAR static const char pstr_nfinity[] = "nfinity";
PROGMEM_FAR static const char pstr_an[] = "an";

__attribute__((noinline))
ATTRIBUTE_CLIB_SECTION
static uint8_t conv_flt (FILE *stream, width_t width, float *addr)
{
    union
    {
	uint32_t u32;
	float flt;
    } x;

#ifndef __AVR_HAVE_ELPM__
    const char *p;
#else
    uint_farptr_t pf;
#endif

#define FL_MINUS    0x80	/* number is negative	*/
#define FL_ANY	    0x02	/* any digit was read	*/
#define FL_OVFL	    0x04	/* overflow was		*/
#define FL_DOT	    0x08	/* decimal '.' was	*/
#define FL_MEXP	    0x10	/* exponent 'e' is neg.	*/

    int i = getc (stream);	/* after ungetc()	*/
    uint8_t flag = 0;
    int exp;

    switch ((uint8_t) i)
    {
	case '-':
	    flag = FL_MINUS;
	    /* FALLTHROUGH */

	case '+':
	    if (!--width || (i = getc (stream)) < 0)
		goto err;
    }

    switch (tolower (i))
    {
#ifndef __AVR_HAVE_ELPM__
	case 'n':
	    p = pstr_an;
	    goto operate_pstr;

	case 'i':
	    p = pstr_nfinity;
	operate_pstr:
	    {
		uint8_t c;

		while ((c = pgm_read_byte (p++)) != 0)
		{
		    if (!--width
			|| (i = getc (stream)) < 0
			|| ((uint8_t) tolower(i) != c
			    && (ungetc (i, stream), 1)))
		    {
			if (p == pstr_nfinity + 3)
			    break;
			goto err;
		    }
		}
	    }
	    x.flt = (p == pstr_an + 3) ? NAN : INFINITY;
	    break;

#else /* ..ELPM.. */
	case 'n':
	    pf = pgm_get_far_address (pstr_an[0]);
	    goto operate_pstr;

	case 'i':
	    pf = pgm_get_far_address (pstr_nfinity[0]);
	operate_pstr:
	    {
		uint8_t c;

		while ((c = pgm_read_u8_far (pf++)) != 0)
		{
		    if (!--width
			|| (i = getc (stream)) < 0
			|| ((uint8_t) tolower(i) != c
			    && (ungetc (i, stream), 1)))
		    {
			if (pf == pgm_get_far_address (pstr_nfinity[3]))
			    break;
			goto err;
		    }
		}
	    }
	    x.flt = pf == pgm_get_far_address (pstr_an[3])
		? NAN
		: INFINITY;
	    break;
#endif /* ELPM ? */

	default:
	    exp = 0;
	    x.u32 = 0;
	    do
	    {
		uint8_t c = i - '0';

		if (c <= 9)
		{
		    flag |= FL_ANY;
		    if (flag & FL_OVFL)
		    {
			if (!(flag & FL_DOT))
			    exp += 1;
		    }
		    else
		    {
			if (flag & FL_DOT)
			    exp -= 1;
			x.u32 = mulacc (x.u32, FL_DEC, c);
			if (x.u32 >= (UINT32_MAX - 9) / 10)
			    flag |= FL_OVFL;
		    }
		}
		else if (c == (('.'-'0') & 0xff) && !(flag & FL_DOT))
		    flag |= FL_DOT;
		else
		    break;
	    }
	    while (--width && (i = getc (stream)) >= 0);

	    if (!(flag & FL_ANY))
		goto err;

	    if ((uint8_t) i == 'e' || (uint8_t) i == 'E')
	    {
		int expacc;

		if (!--width || (i = getc (stream)) < 0)
		    goto err;
		switch ((uint8_t) i)
		{
		    case '-':
			flag |= FL_MEXP;
			/* FALLTHROUGH */

		    case '+':
			if (!--width)
			    goto err;
			i = getc (stream);	// test EOF will below
		}

		if (!isdigit (i))
		    goto err;

		expacc = 0;
		do
		    expacc = mulacc (expacc, FL_DEC, i - '0');
		while (--width && isdigit (i = getc(stream)));
		if (flag & FL_MEXP)
		    expacc = -expacc;
		exp += expacc;
	    }

	    if (width && i >= 0)
		ungetc (i, stream);

	    x.flt = __floatunsisf (x.u32);

#ifndef __AVR_HAVE_ELPM__
	    const float *f_pwr;
	    if (exp < 0)
	    {
		f_pwr = __avrlibc_pwr_m10 + LAST_PWR;
		exp = -exp;
	    }
	    else
		f_pwr = __avrlibc_pwr_p10 + LAST_PWR;

	    for (width = 1 << LAST_PWR; width; width >>= 1, --f_pwr)
		for (; (uint16_t) exp >= width; exp -= width)
		    x.flt *= pgm_read_float (f_pwr);
#else
	    uint_farptr_t f_pwr;
	    if (exp < 0)
	    {
		f_pwr = pgm_get_far_address (__avrlibc_pwr_m10[LAST_PWR]);
		exp = -exp;
	    }
	    else
		f_pwr = pgm_get_far_address (__avrlibc_pwr_p10[LAST_PWR]);

	    for (width = 1 << LAST_PWR; width; width >>= 1)
	    {
		for (; (uint16_t) exp >= width; exp -= width)
		    x.flt *= pgm_read_float_far (f_pwr);
		f_pwr -= sizeof (float);
	    }
#endif /* ELPM ? */
    } /* switch */

    if (flag & FL_MINUS)
	x.flt = -x.flt;
    if (addr)
	*addr = x.flt;
    return 1;

  err:
    return 0;
}
#endif	/* SCANF_FLOAT	*/

__attribute__((noinline))
ATTRIBUTE_CLIB_SECTION
static int skip_spaces (FILE *stream)
{
    int i;
    do {
	if ((i = getc (stream)) < 0)
	    return i;
    } while (isspace (i));
    ungetc (i, stream);
    return i;
}

/**
   Formatted input.  This function is the heart of the \b scanf family of
   functions.

   Characters are read from \a stream and processed in a way described by
   \a fmt.  Conversion results will be assigned to the parameters passed
   via \a ap.

   The format string \a fmt is scanned for conversion specifications.
   Anything that doesn't comprise a conversion specification is taken as
   text that is matched literally against the input.  White space in the
   format string will match any white space in the data (including none),
   all other characters match only itself. Processing is aborted as soon
   as the data and format string no longer match, or there is an error or
   end-of-file condition on \a stream.

   Most conversions skip leading white space before starting the actual
   conversion.

   Conversions are introduced with the character \b %.  Possible options
   can follow the \b %:

   - a \c * indicating that the conversion should be performed but
     the conversion result is to be discarded; no parameters will
     be processed from \c ap,
   - the character \c h indicating that the argument is a pointer
     to <tt>short int</tt> (rather than <tt>int</tt>),
   - the 2 characters \c hh indicating that the argument is a pointer
     to <tt>char</tt> (rather than <tt>int</tt>).
   - the character \c l indicating that the argument is a pointer
     to <tt>long int</tt> (rather than <tt>int</tt>, for integer
     type conversions), or a pointer to \c float (for floating
     point conversions),

   In addition, a maximal field width may be specified as a nonzero
   positive decimal integer, which will restrict the conversion to at
   most this many characters from the input stream.  This field width is
   limited to at most 255 characters which is also the default value
   (except for the <tt>%c</tt> conversion that defaults to 1).

   The following conversion flags are supported:

   - \c % Matches a literal \c % character.  This is not a conversion.
   - \c d Matches an optionally signed decimal integer; the next
     pointer must be a pointer to \c int.
   - \c i Matches an optionally signed integer; the next pointer must
     be a pointer to \c int.  The integer is read in base 16 if it
     begins with \b 0x or \b 0X, in base 8 if it begins with \b 0, and
     in base 10 otherwise.  Only characters that correspond to the
     base are used.
   - \c o Matches an octal integer; the next pointer must be a pointer to
     <tt>unsigned int</tt>.
   - \c u Matches an optionally signed decimal integer; the next
     pointer must be a pointer to <tt>unsigned int</tt>.
   - \c x Matches an optionally signed hexadecimal integer; the next
     pointer must be a pointer to <tt>unsigned int</tt>.
   - \c f Matches an optionally signed floating-point number; the next
     pointer must be a pointer to \c float.
   - <tt>e, g, F, E, G</tt> Equivalent to \c f.
   - \c s
     Matches a sequence of non-white-space characters; the next pointer
     must be a pointer to \c char, and the array must be large enough to
     accept all the sequence and the terminating \c NUL character.  The
     input string stops at white space or at the maximum field width,
     whichever occurs first.
   - \c c
     Matches a sequence of width count characters (default 1); the next
     pointer must be a pointer to \c char, and there must be enough room
     for all the characters (no terminating \c NUL is added).  The usual
     skip of leading white space is suppressed.  To skip white space
     first, use an explicit space in the format.
   - <tt>[</tt>
     Matches a nonempty sequence of characters from the specified set
     of accepted characters; the next pointer must be a pointer to \c
     char, and there must be enough room for all the characters in the
     string, plus a terminating \c NUL character.  The usual skip of
     leading white space is suppressed.  The string is to be made up
     of characters in (or not in) a particular set; the set is defined
     by the characters between the open bracket <tt>[</tt> character and a
     close bracket <tt>]</tt> character.  The set excludes those characters
     if the first character after the open bracket is a circumflex
     \c ^.  To include a close bracket in the set, make it the first
     character after the open bracket or the circumflex; any other
     position will end the set.  The hyphen character \c - is also
     special; when placed between two other characters, it adds all
     intervening characters to the set.  To include a hyphen, make it
     the last character before the final close bracket.  For instance,
     <tt>[^]0-9-]</tt> means the set of <em>everything except close
     bracket, zero through nine, and hyphen</em>.  The string ends
     with the appearance of a character not in the (or, with a
     circumflex, in) set or when the field width runs out.  Note that
     usage of this conversion enlarges the stack expense.
   - \c p
     Matches a pointer value (as printed by <tt>%p</tt> in printf()); the
     next pointer must be a pointer to \c void.
   - \c n
     Nothing is expected; instead, the number of characters consumed
     thus far from the input is stored through the next pointer, which
     must be a pointer to \c int.  This is not a conversion, although it
     can be suppressed with the \c * flag.
.

     These functions return the number of input items assigned, which can
     be fewer than provided for, or even zero, in the event of a matching
     failure.  Zero indicates that, while there was input available, no
     conversions were assigned; typically this is due to an invalid input
     character, such as an alphabetic character for a <tt>%d</tt>
     conversion.  The value \c EOF is returned if an input failure occurs
     before any conversion such as an end-of-file occurs.  If an error or
     end-of-file occurs after conversion has begun, the number of
     conversions which were successfully completed is returned.

     By default, all the conversions described above are available except
     the floating-point conversions and the width is limited to 255
     characters.  The floating-point conversion will be available in the
     extended version.  Also in
     this case the width is not limited (exactly, it is limited to 65535
     characters).

     A third version is available for environments that are tight on
     space.  In addition to the restrictions of the standard one, this
     version implements no <tt>%[</tt> specification.

     To link a program against the respective version, use the
     following \ref gcc_minusW "compiler flags" in the link stage:

     <dl>
     <dt>Classic approach</dt>
     <dd>
     - In order to use the extended version, link with:
     \code
     -Wl,-u,vfscanf -lscanf_flt
     \endcode

     - In order to use the minimal version, link with:
     \code
     -Wl,-u,vfscanf -lscanf_min
     \endcode

     This approach will always link the requested scanf implementation,
     even when the application doesn't use scanf.
     </dd>
     <dt>Since AVR-LibC v2.3</dt>
     <dd>
     - In order to use the extended version, link with:
     \code
     -Wl,--defsym,vfscanf=vfscanf_flt
     \endcode

     - In order to use the minimal version, link with:
     \code
     -Wl,--defsym,vfscanf=vfscanf_min
     \endcode

     This approach will not link the requested scanf implementation
     provided the application doesn't use scanf,
     and <tt>-Wl,\--gc-sections</tt> is added to the link options.
     </dd>
     </dl>
*/
ATTRIBUTE_CLIB_SECTION
#ifdef __DOXYGEN__
int vfscanf (FILE * stream, const char *fmt, va_list ap)
#else
int VFSCANF_NAME (FILE * stream, const char *fmt, va_list ap)
#endif
{
    uint8_t nconvs;
    uint8_t stream_flags;
    uint8_t c;
    width_t width;
    void *addr;
    uint8_t flags;
    int i;

    nconvs = 0;
    stream->len = 0;

    /* Initialization of stream_flags at each pass simplifies the register
       allocation with GCC 3.3 - 4.2.  Only the GCC 4.3 is good to move it
       to the begin.	*/
    while ((c = GETBYTE (stream_flags = stream->flags, __SPGM, fmt)) != 0)
    {

	if (isspace (c))
	{
	    skip_spaces (stream);

	}
	else if (c != '%'
		 || (c = GETBYTE (stream_flags, __SPGM, fmt)) == '%')
	{
	    /* Ordinary character.	*/
	    if ((i = getc (stream)) < 0)
		goto eof;
	    if ((uint8_t)i != c)
	    {
		ungetc (i, stream);
		break;
	    }

	}
	else
	{
	    flags = 0;

	    if (c == '*')
	    {
		flags = FL_STAR;
		c = GETBYTE (stream_flags, __SPGM, fmt);
	    }

	    width = 0;
	    while ((c -= '0') < 10)
	    {
		flags |= FL_WIDTH;
		width = mulacc (width, FL_DEC, c);
		c = GETBYTE (stream_flags, __SPGM, fmt);
	    }
	    c += '0';
	    if (flags & FL_WIDTH)
	    {
		/* C99 says that width must be greater than zero.
		   To simplify program do treat 0 as error in format.	*/
		if (!width)
		    break;
	    }
	    else
	    {
		width = ~0;
	    }

	    /* ATTENTION: with FL_CHAR the FL_LONG is set also.	*/
	    switch (c)
	    {
		case 'h':
		    if ((c = GETBYTE (stream_flags, __SPGM, fmt)) != 'h')
			break;
		    flags |= FL_CHAR;
		    /* FALLTHROUGH */
		case 'l':
		    flags |= FL_LONG;
		    c = GETBYTE (stream_flags, __SPGM, fmt);
	    }

#define CNV_BASE	"cdinopsuxX"
#if	SCANF_BRACKET
# define CNV_BRACKET	"["
#else
# define CNV_BRACKET	""
#endif
#if	SCANF_FLOAT
# define CNV_FLOAT	"efgEFG"
#else
# define CNV_FLOAT	""
#endif
#define CNV_LIST	CNV_BASE CNV_BRACKET CNV_FLOAT

#ifndef __AVR_HAVE_ELPM__
	    if (!c || !strchr_P (PSTR (CNV_LIST), c))
		break;
#else
	    if (!c || !strchr_PF (PSTR_FAR (CNV_LIST), c))
		break;
#endif

	    addr = (flags & FL_STAR) ? 0 : va_arg (ap, void*);

	    if (c == 'n')
	    {
		putval (addr, (unsigned)(stream->len), flags);
		continue;
	    }

	    if (c == 'c')
	    {
		if (!(flags & FL_WIDTH))
		    width = 1;
		do {
		    if ((i = getc (stream)) < 0)
			goto eof;
		    if (addr) *(char*) addr++ = i;
		} while (--width);
		c = 1;			/* no matter with smart GCC	*/

#if  SCANF_BRACKET
	    }
	    else if (c == '[')
	    {
		fmt = conv_brk (stream, width, addr, fmt);
		c = (fmt != 0);
#endif
	    }
	    else
	    {
		if (skip_spaces (stream) < 0)
		    goto eof;

		switch (c)
		{
		    case 's':
			/* Now we have 1 nospace symbol.	*/
			do
			{
			    if ((i = getc (stream)) < 0)
				break;
			    if (isspace (i))
			    {
				ungetc (i, stream);
				break;
			    }
			    if (addr)
				*(char*) addr++ = i;
			} while (--width);
			if (addr)
			    *(char*) addr = 0;
			c = 1;		/* no matter with smart GCC	*/
			break;

#if  SCANF_FLOAT
		    case 'p':
		    case 'x':
		    case 'X':
			flags |= FL_HEX;
			goto conv_int;

		    case 'd':
		    case 'u':
			flags |= FL_DEC;
			goto conv_int;

		    case 'o':
			flags |= FL_OCT;
			/* FALLTHROUGH */
		    case 'i':
		    conv_int:
			c = conv_int (stream, width, addr, flags);
			break;

		    default:		/* e,E,f,F,g,G	*/
			c = conv_flt (stream, width, addr);
#else
		    case 'd':
		    case 'u':
			flags |= FL_DEC;
			goto conv_int;

		    case 'o':
			flags |= FL_OCT;
			/* FALLTHROUGH */
		    case 'i':
			goto conv_int;

		    default:			// p,x,X
			flags |= FL_HEX;
		    conv_int:
			c = conv_int (stream, width, addr, flags);
#endif
		}
	    } /* else */

	    if (!c)
	    {
		if (stream->flags & (__SERR | __SEOF))
		    goto eof;
		break;
	    }
	    if (!(flags & FL_STAR))
		nconvs += 1;
	} /* else */
    } /* while */
    return nconvs;

eof:
    return nconvs ? nconvs : EOF;
}

#endif /* !defined(__AVR_TINY__) */
