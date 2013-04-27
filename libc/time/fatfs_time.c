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
	Return a value suitable for use as a file system time stamp.
*/

#include <time.h>

uint32_t
fat_time(const struct tm * timeptr)
{
	uint32_t        ret;
	uint32_t        n;

	n = timeptr->tm_year - 80;
	n <<= 25;
	ret = n;

	n = timeptr->tm_mon + 1;
	n <<= 21;
	ret |= n;

	n = timeptr->tm_mday;
	n <<= 16;
	ret |= n;

	n = timeptr->tm_hour;
	n <<= 11;
	ret |= n;

	n = timeptr->tm_min;
	n <<= 5;
	ret |= n;

	ret |= (timeptr->tm_sec / 2);

	return ret;
}
