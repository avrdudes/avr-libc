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
 * POSSIBILITY OF SUCH DAMAGE.
 */

/* $Id$ */

/*
	Re entrant version of isotime(),  which prints the date and time in ISO 8601 format.
*/

#include <stdlib.h>
#include <time.h>

extern void __print_lz(int , char *, char );

void
isotime_r(const struct tm * tmptr, char *buffer)
{
	int             i;

	i = tmptr->tm_year + 1900;
	__print_lz(i/100, buffer, '-');
	buffer+=2;
	__print_lz(i%100, buffer,'-');
	buffer+=3;

	i = tmptr->tm_mon + 1;
	__print_lz(i, buffer,'-');
	buffer+=3;

	i = tmptr->tm_mday;
	__print_lz(i, buffer,' ');
	buffer+=3;

	i = tmptr->tm_hour;
	__print_lz(i, buffer,':');
	buffer+=3;

	i = tmptr->tm_min;
	__print_lz(i, buffer,':');
	buffer+=3;

	i = tmptr->tm_sec;
	__print_lz(i, buffer,0);

}
