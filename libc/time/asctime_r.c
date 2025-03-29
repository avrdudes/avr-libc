/*
 * (C)2012 Michael Duane Rice All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer. Redistributions in binary
 * form must reproduce the above copyright notice, this list of conditions
 * and the following disclaimer in the documentation and/or other materials
 * provided with the distribution. Neither the name of the copyright holders
 * nor the names of contributors may be used to endorse or promote products
 * derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE. */

/*
	Re-entrant version of asctime().

*/
#include <time.h>
#include <stdlib.h>

#ifdef __MEMX
const __memx char ascmonths[] = "JanFebMarAprMayJunJulAugSepOctNovDec";
const __memx char ascdays[] = "SunMonTueWedThuFriSat";
#else
const char      ascmonths[] = "JanFebMarAprMayJunJulAugSepOctNovDec";
const char      ascdays[] = "SunMonTueWedThuFriSat";
#endif

extern void __print_lz (int, char *, char);

#include "sectionname.h"

ATTRIBUTE_CLIB_SECTION
void
asctime_r(const struct tm * timeptr, char *buffer)
{
	unsigned char   i, m, d;
	div_t result;

	d = timeptr->tm_wday * 3;
	m = timeptr->tm_mon * 3;
	for (i = 0; i < 3; i++) {
	    buffer[i] = ascdays[d++];
	    buffer[i+4] = ascmonths[m++];
	}
	buffer[3]=buffer[7]=' ';
	buffer += 8;

	__print_lz(timeptr->tm_mday,buffer,' ');
	buffer += 3;

	__print_lz(timeptr->tm_hour,buffer,':');
	buffer += 3;

	__print_lz(timeptr->tm_min,buffer,':');
	buffer += 3;

	__print_lz(timeptr->tm_sec,buffer,' ');
	buffer += 3;

	result = div(timeptr->tm_year + 1900 , 100);

	__print_lz(result.quot,buffer,' ');
	buffer += 2;

	__print_lz(result.rem,buffer,0);
}
