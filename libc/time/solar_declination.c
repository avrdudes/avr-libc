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

/* Were it not for the eccentricity of Earths orbit, this would be a trivial
   function.  We compute the Earths orbital position with respect to
   perihelion, from which we derive a 'velocity correction factor'.
   We then compute the orbital angle with respect to the December solstice,
   as 'modulated' by that correction factor.

   Due to the accumulation of rounding errors, the computed December solstice
   of 2135 will lag the actual solstice by many hours. A fudge factor, 'LAG',
   distributes the error across the 136 year range of this library.  */

#include <time.h>
#include <math.h>
#include "ephemera_common.h"
#include "alias.h"

#define LAG 38520

#include "sectionname.h"

ATTRIBUTE_CLIB_SECTION
float
solar_declinationf(const time_t * timer)
{
    uint32_t fT, oV;
    float dV, dT;

    /* Determine orbital angle relative to perihelion of January 1999 */
    oV = *timer % ANOM_YEAR;
    oV += (float) PERIHELION;
    dV = oV;
    dV /= (float) ANOM_CYCLE;

    /* Derive velocity correction factor from the perihelion angle */
    dV = sinf(dV);
    dV *= (float) DELTA_V;

    /* Determine orbital angle relative to solstice of December 1999 */
    fT = *timer % TROP_YEAR;
    fT += (float) (SOLSTICE + LAG);
    dT = fT;
    dT /= (float) TROP_CYCLE;
    dT += dV;

    /* Finally having the solstice angle, we can compute the declination */
    dT = cosf(dT) * (float) INCLINATION;

    return -dT;
}

DALIAS (solar_declinationf) double solar_declination (const time_t*);
LALIAS (solar_declinationf) long double solar_declinationl (const time_t*);
