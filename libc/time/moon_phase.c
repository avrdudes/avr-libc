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
    Return an approximation to the phase of the moon. Since no attempt is made to account for
    Sol, Jupiter or Venus, it will often be off by several hours.
*/

#include <time.h>
#include <math.h>

int8_t
moon_phase(const time_t * timestamp)
{
	uint32_t        t;
	int32_t         n;
	double          mc;

	/* refer to first new moon of the epoch */
	t = *timestamp - 1744800UL;

	/* constrain to 1 lunar cycle */
	n = t % 2551443UL;

	/* offset by 1/2 lunar cycle */
	n -= 1275721L;
	mc = n;
	mc /= 1275721.0;
	mc *= M_PI;
	mc = cos(mc) * sin(mc);
	mc *= 12.5;

	/* scale to range - 100...+ 100 */
	n /= 12757L;
	n -= mc;

	return n;
}
