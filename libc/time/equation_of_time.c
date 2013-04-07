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
    The so called Equation of Time.
*/

#include <time.h>
#include <math.h>

#define TROP_YEAR 31556925
#define ANOM_YEAR 31558433
#define PERIHELION 31218166 /* perihelion of 1999 */
#define SOLSTICE 836160 /* winter solstice of 1999 */
#define TWO_PI 6.283185307179586

int
equation_of_time(time_t * timer)
{
    unsigned long   s, p, y;
    double          d, lf, hf;

    /* s = time since solstice */
    s = * timer % TROP_YEAR;
    s += SOLSTICE;

    /* p = time since perihelion */
    p = *timer % ANOM_YEAR;
    p += PERIHELION;

    /* low frequency component has 1 year period */
    lf = p;
    lf /= ANOM_YEAR;

    /* high frequency component has 1/2 year period */
    y = TROP_YEAR / 2;
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
