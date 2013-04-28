/*
 * (c)2012 Michael Duane Rice All rights reserved.
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
    Compute the ISO 8601 week number of the year.
    We return 0 if the week is the final one of the previous year.
    We return 54 if the week is the first week of the following year.
    Otherwise we return week numbers 1 to 53
*/

#include <time.h>

uint8_t
iso_weeknum(const struct tm * timestruct)
{
    int             d, w;

    /* convert to a MONDAY based week */
    d = timestruct->tm_wday;
    if (d == 0)
        d = 7;

    /* compute tentative ISO 8601 week number */
    w = timestruct->tm_yday + 11 - d;
    w /= 7;

    /*
     * handle the special case where week 53 may actually be week 1 of
     * the following year
     */
    if (w == 53) {
        /* week 53 must include its thursday in the same year */
        d = timestruct->tm_mday - 1;
        d -= timestruct->tm_wday;
        d += THURSDAY;
        if (d > 30)
            w++;    /* signal first week of the following year */
    }
    return w;
}
