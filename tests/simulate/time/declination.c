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
    Declination test. We test the result at the moment of the equinoxes and solstices of
    the year 2020, as provided by the U.S. Naval Observatory.
    We consider a difference greater than 0.01 degree as an error.

*/

#include <time.h>
#include <math.h>

int main(){
time_t t;
struct tm calendar;
double e;

    calendar.tm_year = 2020 - 1900;
    calendar.tm_mon = 2;
    calendar.tm_mday = 20;
    calendar.tm_hour = 3;
    calendar.tm_min = 50;
    calendar.tm_sec = 0;
    t = mk_gmtime(&calendar);
    e = fabs(solar_declination(&t) * 57.295779513082325);
    if(e > 0.01) return (__LINE__);

    calendar.tm_mon = 5;
    calendar.tm_mday = 20;
    calendar.tm_hour = 21;
    calendar.tm_min = 44;
    t = mk_gmtime(&calendar);
    e = solar_declination(&t) * 57.295779513082325;
    e = fabs(e - 23.44);
    if(e > 0.01) return (__LINE__);

    calendar.tm_mon = 8;
    calendar.tm_mday = 22;
    calendar.tm_hour = 13;
    calendar.tm_min = 31;
    t = mk_gmtime(&calendar);
    e = fabs(solar_declination(&t) * 57.295779513082325);
    if(e > 0.01) return (__LINE__);

    calendar.tm_mon = 11;
    calendar.tm_mday = 21;
    calendar.tm_hour = 10;
    calendar.tm_min = 2;
    t = mk_gmtime(&calendar);
    e = solar_declination(&t) * 57.295779513082325;
    e = fabs(e + 23.44);
    if(e > 0.01) return (__LINE__);

    return 0;

}
