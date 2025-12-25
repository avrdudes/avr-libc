/*
 * Copyright (c) 2012 Michael Duane Rice All rights reserved.
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

#ifndef USA_DST_H
#define USA_DST_H

#ifdef __cplusplus
extern "C" {
#endif

#include <time.h>
#include <stdint.h>

/** \file */
/** \defgroup usa_dst <util/usa_dst.h>: Daylight Saving function for the USA.
    \code #include <util/usa_dst.h> \endcode
    Daylight Saving function for the USA. */

/** \ingroup usa_dst
    \fn int usa_dst (const time_t *timer, int32_t *z)
    To utilize this function, call
    \code set_dst(usa_dst); \endcode

    Given the time stamp and time zone parameters provided, the Daylight
    Saving function must return a value appropriate for the tm structures'
    tm_isdst element. That is:

    - \c 0 : If Daylight Saving is not in effect.

    - \c -1 : If it cannot be determined if Daylight Saving is in effect.

    - A positive integer : Represents the number of seconds a clock is
    advanced for Daylight Saving.  This will typically be ONE_HOUR.

    Daylight Saving 'rules' are subject to frequent change. For production
    applications it is recommended to write your own DST function, which
    uses 'rules' obtained from, and modifiable by, the end user
    (perhaps stored in EEPROM).
*/
int usa_dst (const time_t *timer, int32_t *z);

#ifdef __cplusplus
}
#endif

#endif
