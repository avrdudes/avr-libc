/* Header+source file to test the dtostrf() function.
   $Id$
 */

#ifndef	PATTERN_SIZE
# define PATTERN_SIZE	15
#endif

struct dtostrf_s {
    union {
	long lo;
	float fl;
    };
    signed char width;
    unsigned char prec;
    char pattern[PATTERN_SIZE];
};

#ifndef	__AVR__

# include <stdio.h>
# include <string.h>

/* This function is intended for run of test cases on the host computer.
 */
char * dtostrf (double val, signed char width, unsigned char prec, char *s)
{
    char fmt[16];	/* "%-110.100F"	*/
    
    sprintf (fmt, "%%%d.%dF", width, prec);
    sprintf (s, fmt, val);
    return s;
}
#endif	/* !__AVR__ */

#define	PZLEN	5	/* protected zone length	*/

void run_dtostrf (const struct dtostrf_s *pt, int testno)
{
    union {
	long lo;
	float fl;
    } val;
    signed char width;
    unsigned char prec;
    static char s[2*PZLEN + sizeof(pt->pattern)];
    char c, *ps;
    void *pv;
    
    memset (s, testno, sizeof(s));

#ifdef	__AVR__
    val.lo = pgm_read_dword (& pt->lo);
    width  = pgm_read_byte (& pt->width);
    prec   = pgm_read_byte (& pt->prec);
#else
    val.lo = pt->lo;
    width  = pt->width;
    prec   = pt->prec;
#endif
    ps = dtostrf (val.fl, width, prec, s + PZLEN);

    if (ps != s + PZLEN)
	exit (testno + 0x1000);
    for (ps = s; ps != s + PZLEN; ps++) {
	if ((unsigned char)*ps != (testno & 0377))
	    exit (testno + 0x2000);
    }

    pv = & pt->pattern;
#ifdef	__AVR__
    do {
	c = pgm_read_byte(pv++);
	if (*ps++ != c) {
	    exit (testno + 0x3000);
	}
    } while (c);
#else
    do {
	c = *(char *)(pv++);
	if (*ps++ != c) {
	    printf ("*** testno= %d:  must= %s  was= %s\n",
		testno, pt->pattern, s + PZLEN);
	    exit (testno + 0x3000);
	}
    } while (c);
#endif

    for (; ps != s + sizeof(s); ps++) {
	if ((unsigned char)*ps != (testno & 0377))
	    exit (testno + 0x4000);
    }
}
