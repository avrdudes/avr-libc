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
	The so called Equation of Time. We determine the orbital position of the mothership,
	and solve a two term polynomial. More accurate equations are available (more terms), but
	without a true double there is little point in that.
*/

#include <time.h>
#include "time_private.h"
#include <math.h>

int
equation_of_time(time_t * timer)
{
	unsigned long   s, p, y;
	double          d, lf, hf;

	/* s = time since solstice */
	s = *timer + 836160UL;

	/* p = time since perihelion */
	p = *timer - 191857UL;

	/* limit to 1 tropical year */
	y = tropical_year;
	s %= y;
	p %= y;

	/* low frequency component has 1 year period */
	lf = p;
	lf /= y;

	/* high frequency component has 1/2 year period */
	y /= 2;
	hf = s;
	hf /= y;

	/* convert years to radians */
	d = 6.283185307179586;
	hf *= d;
	lf *= d;

	/* hf has magnitude 592.2 */
	hf = sin(hf) * 592.2;

	/* lf has magnitude 451.8 */
	lf = sin(lf) * 451.8;

	d = lf + hf;

	return -d;
}
