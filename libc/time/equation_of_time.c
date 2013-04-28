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

    The eccentricity of Earths orbit contributes about 7.7 minutes of variation to the result. It
    has a period of 1 anomalous year, with zeroes at perihelion and aphelion.

    The tilt of Earths rotational axis (obliquity) contributes about 9.9 minutes of variation. It
    has a period of 1/2 tropical year, with zeroes at solstices and equinoxes. The time of Earths
    arrival at these events is influenced by the eccentricity, which causes it to progress along its
    orbital path faster as it approaches perihelion, imposing a 'modulation' on the tropical phase.

    The algorithm employed computes the orbital position with respect to perihelion, deriving
    from that a 'velocity correction factor'. The orbital position with respect to the winter solstice
    is then computed, as modulated by that factor. The individual contributions of the obliquity and the
    eccentricity components are then summed, and returned as an integer value in seconds.

*/

#include <time.h>
#include <math.h>
#include "ephemera_common.h"

int
equation_of_time(const time_t * timer)
{
    int32_t         s, p;
    double          pf, sf, dV;

    /* compute orbital position relative to perihelion */
    p = *timer % ANOM_YEAR;
    p += PERIHELION;
    pf = p;
    pf /= ANOM_CYCLE;
    pf = sin(pf);

    /* Derive a velocity correction factor from the perihelion angle */
    dV = pf * DELTA_V;

    /* compute approximate position relative to solstice */
    s = *timer % TROP_YEAR;
    s += SOLSTICE;
    s *= 2;
    sf = s;
    sf /= TROP_CYCLE;

    /* modulate to derive actual position */
    sf += dV;
    sf = sin(sf);

    /* compute contributions */
    sf *= 592.2;
    pf *= 459.6;
    s = pf + sf;
    return -s;

}
