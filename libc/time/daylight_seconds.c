/*
 * Copyright (C) 2012 Michael Duane Rice All rights reserved.
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
    Determine the amount of time the sun is above the horizon. At high latitudes, around the
    solstices, this can be zero or greater than ONE_DAY.

*/

#include <math.h>
#include <time.h>
#include "time-private.h"
#include "sectionname.h"

ATTRIBUTE_CLIB_SECTION
long
daylight_seconds(const time_t * timer)
{
    long n;

    /* convert latitude to radians */
    float l = __latitude / 206264.806f;

    float d = -solar_declinationf(timer);

    /* partial 'Sunrise Equation' */
    d = tanf(l) * tanf(d);

    /* magnitude of d may exceed 1.0 at near solstices */
    if (d > 1.0f)
        d = 1.0f;

    if (d < -1.0f)
        d = -1.0f;

    /* derive hour angle */
    d = acosf(d);

    /* but for atmospheric refraction, this would be d /= M_PI */
    d /= 3.112505f;

    n = ONE_DAY * d;

    return n;
}
