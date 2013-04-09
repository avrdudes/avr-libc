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

#include <time.h>
#include <math.h>
#include "ephemera_common.h"

#define DELTA_V 0.033
#define LAG 37800

double
solar_declination(time_t * timer)
{

    uint32_t        fT, oV;
    double          dV, dT;

    /*
     * Determine approximate orbital angle, relative to the winter
     * solstice
     */
    fT = *timer % TROP_YEAR;
    fT += SOLSTICE;
    fT += LAG;
    dT = fT;
    dT /= TROP_CYCLE;

    /* Determine approximate orbital angle, relative to perihelion */
    oV = *timer % ANOM_YEAR;
    oV += PERIHELION;
    dV = oV;
    dV /= ANOM_CYCLE;

    /* Derive a velocity correction factor from the perihelion angle */
    dV = sin(dV);
    dV *= DELTA_V;

    /* compute declination */
    dT = cos(dT + dV) * INCLINATION;

    return -dT;
}
