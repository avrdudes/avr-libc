/* Copyright (c) 2002, Alexander Popov (sasho@vip.bg)
   Copyright (c) 2002,2004 Joerg Wunsch
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

/* From: Id: printf_p_new.c,v 1.1.1.9 2002/10/15 20:10:28 joerg_wunsch Exp */
/* $Id$ */

#include <avr/pgmspace.h>
#include <inttypes.h>
#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stdio_private.h"

/*
 * This file can be compiled into more than one flavour.  The default
 * is to offer the usual modifiers and integer formatting support
 * (level 2).  Level 1 maintains a minimal version that just offers
 * integer formatting, but no modifier support whatsoever.  Level 3 is
 * intented for floating point support.
 */

#ifndef PRINTF_LEVEL
#  define PRINTF_LEVEL PRINTF_STD
#endif

#if PRINTF_LEVEL == PRINTF_MIN || PRINTF_LEVEL == PRINTF_STD \
|| PRINTF_LEVEL == PRINTF_FLT
/* OK */
#else
#  error "Not a known printf level."
#endif

#if PRINTF_LEVEL >= PRINTF_FLT
#include <math.h>
#endif

#if PRINTF_LEVEL >= PRINTF_MIN
#define FLHASPERCENT	0x01	/* first % found */
#define FLNEGATIVE	0x02	/* arg is negative int */
#define FLLONG		0x04	/* arg is long int */
#endif

#if PRINTF_LEVEL >= PRINTF_STD
#define FLPREC		0x08	/* .prec given */
#define FLSIGNPLUS	0x10	/* always print '+' sign */
#define FLSIGN		0x20	/* always print sign */
#define FLALT		0x40	/* # alternate specification given */
#define FLLPAD		0x80	/* left-align result */
#define FLZFILL		0x100	/* zero-fill up to width */
#endif

#if PRINTF_LEVEL >= PRINTF_FLT
#define FLFLOAT		0x200	/* floating-point conversion */
#define FLFCVT		0x400	/* do style `f' if set, style `e' if clear */
#define FLGCVT		0x800	/* %g format, decide about %e or %f */

/* With 4-byte floats, we can get up to 39 digits. */
#define FLTBUFLEN 40

static int8_t	flcvt(char *buf, double arg, int8_t ndigits, uint16_t *flags);
#endif /* PRINTF_LEVEL >= PRINTF_FLT */

/* Integer conversion buffer length. */
#define BUFLEN 12

int
vfprintf(FILE *stream, const char *fmt, va_list ap) {
	union {
		char c;
		uint8_t u8;
		int8_t i8;
		long l;
		unsigned long ul;
		char *pc;
#if PRINTF_LEVEL >= PRINTF_FLT
		double d;
		div_t dv;
#endif
	} a;
	char	c;	/* holds a char from the format string */
	uint8_t	base;
	char	b[BUFLEN]; /*
			    * Contains character representation of the
			    * number and its prefix, written from back
			    * to front.
			    */
	char	*pb;	/* used as pointer to an element in b */
#if PRINTF_LEVEL > PRINTF_MIN
	int8_t	width, prec;
#endif
#if PRINTF_LEVEL >= PRINTF_FLT
	int8_t	decpt;
	char	*fb;	/* floating point buffer, malloc'ed */
#endif

#if PRINTF_LEVEL < PRINTF_STD
	uint8_t flags;
#else
	uint16_t flags;
#endif

	flags = 0;
	stream->len = 0;
#if PRINTF_LEVEL >= PRINTF_FLT
	fb = 0;
#endif

	if ((stream->flags & __SWR) == 0)
		return EOF;

	/*
	 * Do not use fmt++ in the next line.  pgm_read_byte() is a
	 * macro, so it could evaluate its argument more than once.
	 */
	while ((c = ((stream->flags & __SPGM)? pgm_read_byte(fmt): *fmt))) {

		fmt++;

		if (flags & FLHASPERCENT) {
			if (c >= '0' && c <= '9') {
#if PRINTF_LEVEL > PRINTF_MIN
				if (c == '0' && prec == 0 && width == 0) {
					flags |= FLZFILL;
				} else {
					/* digit */
					prec *= 10;
					prec += c - '0';
					if (prec < 0)
						prec = SCHAR_MAX;
					if (!(flags & FLPREC)) 
						width = prec;
				}
#endif
#if PRINTF_LEVEL >= PRINTF_FLT
			} else if ((c >= 'e' && c <= 'g') ||
				   (c >= 'E' && c <= 'G')) {
				a.d = va_arg(ap, double);
				if (fb == 0) {
					if ((fb = malloc(FLTBUFLEN)) == 0)
						/*
						 * No buffer for floating point
						 * conversion, punt.
						 */
						goto clearflags;
				}
				if (!(flags & FLPREC))
					prec = 6;
				/* FLPREC is used for integer formats only */
				flags &= ~(FLALT | FLPREC);
				if (isnan(a.d)) {
					b[0] = b[2] = 'N';
					b[1] = 'A';
					pb = b + 3;
				  dofltexcpt:
					/*
					 * XXX: this makes assumptions about
					 * ASCII being used.  Should probably
					 * use ctype, but would cause more
					 * bloat.
					 */
					if (c >= 'e' && c <= 'g') {
						b[0] += 'a' - 'A';
						b[1] += 'a' - 'A';
						b[2] += 'a' - 'A';
					}
					goto nextitem;
				} else if (isinf(a.d)) {
					b[2] = 'I';
					b[1] = 'N';
					b[0] = 'F';
					pb = b + 3;
					if (a.d < 0.0)
						*pb++ = '-';
					goto dofltexcpt;
				}
				flags |= FLFLOAT;
				switch (c) {
				case 'e':
				case 'E':
					decpt = flcvt(fb, a.d, prec, &flags);
				  dostyle_e:
					width -= 4; /* E+00 */
					if (prec > 0)
						width--; /* decimal sign */
					a.i8 = strlen(pb = fb);
					goto dofloat;

				case 'f':
				case 'F':
					flags |= FLFCVT;
					decpt = flcvt(fb, a.d, prec, &flags);
				  dostyle_f:
					if (prec > 0)
						width--; /* decimal sign */
					pb = fb;
					if (decpt > 0)
						a.i8 = strlen(pb);
					else
						a.i8 = prec + 1;
					goto dofloat;
				case 'g':
				case 'G':
					flags |= FLGCVT;
					decpt = flcvt(fb, a.d,
						      prec == 0? 1: prec,
						      &flags);
					/*
					 * Remove trailing zeros from
					 * fractional result.
					 */
					if (flags & FLFCVT) {
						for (a.i8 = decpt + prec - 1;
						     a.i8 >= 0 && a.i8 >= decpt;
						     a.i8--)
							if (fb[a.i8] != '0')
								break;
						if (a.i8 < 0 || a.i8 < decpt)
							/*
							 * No fractional
							 * digits left,
							 * don't display
							 * `.' either.
							 */
							prec = 0;
						else
							prec = a.i8 - decpt + 1;
					} else {
						/* `e' style */
						for (a.i8 = prec;
						     a.i8 > 0;
						     a.i8--)
							if (fb[a.i8] != '0')
								break;
						if (a.i8 == 0)
							/*
							 * No fractional
							 * digits left,
							 * don't display
							 * `.' either.
							 */
							prec = 0;
						else
							prec = a.i8;
					}
					fb[a.i8 + 1] = '\0';
					/*
					 * Continue depending on the %e/%f
					 * decision flcvt() has done.
					 */
					if (flags & FLFCVT)
						goto dostyle_f;
					c -= 'G' - 'E';
					goto dostyle_e;
				}
#endif /* PRINTF_LEVEL >= PRINTF_FLT */				
			} else {
#if PRINTF_LEVEL > PRINTF_MIN
				if ((flags & FLPREC) && prec == 0)
					prec = 1;
#endif /* PRINTF_LEVEL > PRINTF_MIN */
				switch (c) {
				case '+':
#if PRINTF_LEVEL > PRINTF_MIN
					flags |= FLSIGNPLUS;
					/* FALLTHROUGH */
#endif /* PRINTF_LEVEL > PRINTF_MIN */
				case ' ':
#if PRINTF_LEVEL > PRINTF_MIN
					flags |= FLSIGN;
#endif /* PRINTF_LEVEL > PRINTF_MIN */
					break;
				case '-':
#if PRINTF_LEVEL > PRINTF_MIN
					flags |= FLLPAD;
#endif /* PRINTF_LEVEL > PRINTF_MIN */
					break;
				case '#':
#if PRINTF_LEVEL > PRINTF_MIN
					flags |= FLALT;
#endif /* PRINTF_LEVEL > PRINTF_MIN */
					break;
				case '.':
#if PRINTF_LEVEL > PRINTF_MIN
					flags |= FLPREC;
					flags &= ~FLZFILL;
					prec = 0;
#endif /* PRINTF_LEVEL > PRINTF_MIN */
					break;
				case 'l':
					flags |= FLLONG;
					break;
#if PRINTF_LEVEL < PRINTF_FLT
				case 'e':
				case 'f':
				case 'g':
					a.c = '?';
#endif /* PRINTF_LEVEL < PRINTF_FLT */
#if PRINTF_LEVEL > PRINTF_MIN
					width--;
#endif /* PRINTF_LEVEL > PRINTF_MIN */
					c = 'c';
					goto nextitem;
				case 'c':
					/* char is promoted to int via va_arg */
					a.c = (char)va_arg(ap, int);
#if PRINTF_LEVEL > PRINTF_MIN
					width--;
#endif
					goto nextitem;
				case 's':
					a.pc = va_arg(ap, char *);
#if PRINTF_LEVEL > PRINTF_MIN
					if (flags & FLPREC)
						base = strnlen(a.pc, prec);
					else
						base = strlen(a.pc);
					width -= base;
#else
					base = strlen(a.pc);
#endif
					goto nextitem;
				case 'd':
				case 'i':
					a.l = flags & FLLONG ?
						va_arg(ap, long):
						va_arg(ap, int);
					if (a.l < 0) {
						flags |= FLNEGATIVE;
						a.l = -a.l;
					}
#if PRINTF_LEVEL > PRINTF_MIN
					flags &= ~FLALT;
#endif
					goto processnum;
				case 'o': /* octal number */
					base = 8;
					goto getulong;
				case 'p':
#if PRINTF_LEVEL > PRINTF_MIN
					flags |= FLALT;
#endif
					c = 'x';
					/* FALLTHROUGH */
				case 'x':
				case 'X':
					base = 16;
					/* FALLTHROUGH */
				case 'u':
				  getulong:
					a.ul = flags & FLLONG?
						va_arg(ap, unsigned long):
						va_arg(ap, unsigned int);
#if PRINTF_LEVEL > PRINTF_MIN
					flags &= ~(FLSIGNPLUS | FLSIGN);
#endif
				  processnum:
					pb = b;
					do {
						*pb = a.ul % base;
						*pb = *pb > 9?
							*pb + c - 'X' + 'A' - 10:
							*pb + '0';
						*pb++;
						a.ul /= base;
					} while (a.ul);
#if PRINTF_LEVEL > PRINTF_MIN
					/* length of converted string */
					a.i8 = pb - b;
#endif
#if PRINTF_LEVEL >= PRINTF_FLT
				  dofloat:
#endif
#if PRINTF_LEVEL > PRINTF_MIN
					/* compute length of padding */
					if (flags & (FLNEGATIVE | FLSIGN |
						     FLSIGNPLUS))
						width--;
					if (flags & FLALT)
						width -= base == 16? 2: 1;
					if (flags & FLPREC) {
						if (prec <= (uint8_t)a.i8)
							/*
							 * No space left for
							 * 0-padding
							 */
							flags &= ~FLPREC;
						else
							prec -= (uint8_t)a.i8;
					}
					if (flags & FLPREC)
						width -= prec;
					else
						width -= a.i8;

					/* do left-side padding if necessary */
					if (!(flags & (FLLPAD | FLZFILL)))
						while (width-- > 0)
							putc(' ', stream);
#endif
					if (flags & FLNEGATIVE)
						putc('-', stream);
#if PRINTF_LEVEL > PRINTF_MIN
					else if (flags & FLSIGNPLUS)
						putc('+', stream);
					else if (flags & FLSIGN)
						putc(' ', stream);
					if (flags & FLALT) {
						putc('0', stream);
						if (base == 16)
							putc(c, stream);
					}
					if ((flags & FLZFILL))
						while (width-- > 0)
							putc('0', stream);
					/*
					 * If there was no space left for
					 * precision-caused 0-padding, the
					 * flag has already been cleared
					 * above.
					 */
					if (flags & FLPREC)
						while (prec-- > 0)
							putc('0', stream);
#endif
				  nextitem:
#if PRINTF_LEVEL > PRINTF_MIN
					/*
					 * This is for %s and %c only.
					 * For numeric arguments,
					 * we've already done the
					 * padding above, and width
					 * will be negative here.
					 */
					if (!(flags & FLLPAD))
						while (width-- > 0)
							putc(' ', stream);
#endif
					if (c == 'c')
						putc(a.c, stream);
					else if (c == 's')
						while (base--)
							putc(*a.pc++, stream);
#if PRINTF_LEVEL >= PRINTF_FLT
					else if (flags & FLFLOAT) {
						if (flags & FLFCVT) {
							if (decpt > 0) {
								while (decpt--)
									putc(*pb++,
									     stream);
								decpt = 0;
							} else
								putc('0',
								     stream);
						} else
							/* 'e' format */
							putc(*pb++, stream);
						if (prec > 0)
							putc('.', stream);
						if (flags & FLFCVT)
							while (decpt++ < 0 &&
							       prec-- > 0)
								putc('0',
								     stream);
						while ((a.c = *pb++) &&
						       prec-- > 0)
							putc(a.c, stream);
						if (!(flags & FLFCVT)) {
							/* 'e' format */
							putc(c, stream);
							decpt--;
							if (decpt < 0) {
								putc('-',
								     stream);
								decpt = -decpt;
							} else
								putc('+',
								     stream);
							a.dv = div(decpt, 10);
							putc(a.dv.quot + '0',
							     stream);
							putc(a.dv.rem + '0',
							     stream);
						}
					}
#endif /* PRINTF_LEVEL >= PRINTF_FLT */
					else
						while (pb != b)
							putc(*--pb, stream);
#if PRINTF_LEVEL > PRINTF_MIN
					if (flags & FLLPAD)
						while (width-- > 0)
							putc(' ', stream);
#endif
					goto clearflags;

				default:
					putc(c, stream);
				  clearflags:
					flags = 0;
					break;
				}
			}
		} else
			if (c == '%') {
				flags = FLHASPERCENT;
#if PRINTF_LEVEL > PRINTF_MIN
				prec = width = 0;
#endif
				base = 10;
			} else
				putc(c, stream);
	}

#if PRINTF_LEVEL >= PRINTF_FLT
	free(fb);
#endif
	return stream->len;
}

#if PRINTF_LEVEL >= PRINTF_FLT

/*
 * Floating point to string conversion.
 *
 * Featured after the Unix fcvt()/ecvt() functions.  The argument is
 * converted into a digit string.
 *
 * For style `f' conversion (*flags & FLFCVT is set), the position of
 * the decimal point is returned, where a negative position means the
 * decimal point is outside our buffer to the left.  The buffer will
 * then start with the first non-zero digit.  For numbers greater then
 * 1, trailing zeros will be added into the buffer though.  prec
 * determines the number of digits after the decimal point.  (Note
 * that the decimal point itself will not be added into the buffer.)
 *
 * For style `e' conversion (*flags & FLFCVT is clear), decpt is
 * effectively the exponent of our conversion minus 1, and the
 * conversion is always done so that the first digit in the conversion
 * buffer is considered to be the digit before the decimal point, with
 * prec digits following.
 *
 * For style `g' conversion (*flags & FLGCVT is set), after
 * determining the exponent of the conversion, it will be decided
 * whether an `e' style or an `f' style conversion needs to be done.
 * In the former case, *flags will have FLFCVT set upon return.
 *
 * For negative numbers, *flags will get FLNEGATIVE set upon return,
 * while the conversion itself will be handled as if a positive number
 * was given.
 */

#include <math.h>

static int8_t
flcvt(char *buf, double arg, int8_t prec, uint16_t *flags)
{
	int8_t decpt;
	double dnum, dnum2;
	char *p, *p1, *pend;

	/*
	 * Limit prec to what we can handle.  The -3 below is since
	 * style `e' will further increase prec by 1, and there needs
	 * to be space for one insignificant digit used for rounding,
	 * as well as for the trailing '\0'.
	 */
	if (prec < 0)
		prec = 0;
	if (prec > FLTBUFLEN - 3)
		prec = FLTBUFLEN - 3;
	decpt = 0;
	p = buf;
	pend = buf + FLTBUFLEN;
	/*
	 * First, make number positive, and split into integer and
	 * fractional part.
	 */
	if (arg < 0) {
		*flags |= FLNEGATIVE;
		arg = -arg;
	}
	arg = modf(arg, &dnum);
	/*
	 * Handle integer part.  Digits are written in the conversion
	 * buffer back to front, until the integer part becomes 0.
	 * Then, the conversion result is copied to the beginning of
	 * our buffer.
	 */
	if (dnum != 0) {
		for (p1 = pend; dnum != 0 && p1 > p; decpt++) {
			dnum2 = modf(dnum * 0.1, &dnum);
			*--p1 = (int)(dnum2 * 10.1) + '0';
		}
		while (p1 < pend)
			*p++ = *p1++;
	}
	/*
	 * If the number was less than 0, just shift it up into the
	 * range of [0.1 .. 1.0), and remember the number of digits
	 * we needed to shift.
	 */
	else if (arg > 0) {
		while ((dnum = arg * 10) < 1) {
			arg = dnum;
			decpt--;
		}
	}
	if (*flags & FLGCVT) {
		/*
		 * Now decide whether we're going to use style `e' or
		 * style `f' for the conversion.  "Style `e' is used
		 * if the exponent is less than -4 or greater than or
		 * equal to the precision."  Note that we can only
		 * estimate the exponent here since the rounding below
		 * could cause the exponent to further increase; in
		 * order to keep the code small, we simply accept this
		 * possible error which could lead to an `e' conversion
		 * being done where an `f' conversion would still had
		 * sufficed.
		 *
		 * The exponent is equal to decpt - 1 at this point.
		 */
		if (decpt >= -3 && decpt < prec + 1)
			*flags |= FLFCVT;
	}
	/*
	 * For an `e' style conversion, we increase prec so to account
	 * for the digit before the decimal point internally as well.
	 */
	if (!(*flags & FLFCVT))
		prec++;
	p1 = buf + prec;
	if (*flags & FLFCVT)
		p1 += decpt;
	/*
	 * For an `f' style conversion, if prec is too small to hold
	 * any significant digit, the conversion result will consist
	 * solely of 0 digits (which need to be printed by the caller
	 * based on the decpt we return).
	 */
	if (p1 < buf) {
		buf[0] = '\0';
		return decpt;
	}
	/*
	 * Now convert trailing digits from the fractional part, until
	 * we either got the desired precision (p1 points to the last
	 * desired character) or the end of our buffer.
	 */
	while (p <= p1 && p < pend) {
		arg *= 10;
		arg = modf(arg, &dnum);
		*p++ = (int)dnum + '0';
	}
	/*
	 * If we hit the end of the buffer, just terminate the string
	 * and return.  We might have lost precision in that case.
	 */
	if (p1 >= pend) {
		buf[FLTBUFLEN-1] = '\0';
		return decpt;
	}
	/*
	 * If we got here, round the conversion result, beginning from
	 * the last (insignificant) digit, possibly carrying the
	 * overflow to the previous digit(s).  Note that the
	 * insignificant digit will be blanked out below, so we can
	 * just gratitously add a `5' here.
	 */
	p = p1;
	*p1 += 5;
	while (*p1 > '9') {
		*p1 = '0';
		if (p1 > buf)
			++*--p1;
		else {
			*p1 = '1';
			decpt++;
			if (*flags & FLFCVT) {
				if (p > buf)
					*p = '0';
				p++;
			}
		}
	}
	*p = '\0';
	return decpt;
}

#endif /* PRINTF_LEVEL >= PRINTF_FLT */
