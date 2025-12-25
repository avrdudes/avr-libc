/* Copyright (c) 2025  Georg-Johann Lay
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.

   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.

   * Neither the name of the copyright holders nor the names of
     contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE. */

#ifndef _UTIL_RAM_USAGE_H_
#define _UTIL_RAM_USAGE_H_

#include <stdint.h>
#include <bits/attribs.h>

#ifdef __cplusplus
extern "C" {
#endif

/** \file */
/** \defgroup util_ram_usage <util/ram-usage.h>: Determine dynamic RAM usage
    \code
    #include <util/ram-usage.h>
    \endcode

    This header provides a single function, _get_ram_unused(), that can
    be used during development to get a rough estimate of how much RAM might
    be used by an application.  This works as follows:

    -# The startup code paints the RAM location with a specific value.  This
    happens in \ref sec_dot_init ".init3", and only when _get_ram_unused()
    is actually used.  The coloring extends from #__heap_start (which is
    the RAM location right after static storage) up to and
    including \c RAMEND as defined in <avr/io.h>.

    -# The application calls _get_ram_unused() and determines how much
    of the colored bytes are still intact.  This can be used to calculate
    a <b>lower bound</b> of how much RAM is used by the application.

    \since AVR-LibC v2.3
*/

/** \ingroup util_ram_usage

    Determines how much of the initial RAM coloring is still intact.
    It can be used to get a <b>lower bound</b> of how much RAM might be
    used by an application.

    The function is written in such a way that it has a small register foot
    print, so that it is not a big issue to call it in an #ISR.
    Though that's not required for the intended purpose:
    _get_ram_unused() can simply be called after some time has elapsed
    and enough ISRs and other functions have been invoked.

    \return The value returned by _get_ram_unused() is an <em>upper bound</em>
    for how much bytes of RAM are still
    <em>unused at the time of invocation</em>.<br>
    The return value will never increase with time (except for very rare
    occasions where #__ram_color_value is written to the top of the stack).

    \par Limitations
    - The start of the coloring is hard coded as #__heap_start, which
    is the beginning of the RAM area after static storage.
    - The algorithm assumes that the stack is located <em>after
    static storage</em> and grows downwards towards #__heap_start.
    - The current implementation is <b>not compatible with malloc</b> et al.
    (alloca() is no problem though, since it allocates on the stack.)
*/
#ifdef __DOXYGEN__
extern inline uint16_t _get_ram_unused (void);
#else
extern __ATTR_ALWAYS_INLINE__ __ATTR_GNU_INLINE__
uint16_t _get_ram_unused (void)
{
  register uint16_t __r24 __asm("r24");
  __asm ("%~call _get_ram_unused"
         : "=r" (__r24) :: "r30", "r31");
  return __r24;
}
#endif /* !DOXYGEN */

#ifdef __DOXYGEN__

/** \name Symbols */

/** \ingroup util_ram_usage
    A symbol defined in the default linker script.
    It points one byte past static storage (\ref sec_dot_data ".data",
    \ref sec_dot_bss ".bss", \ref sec_dot_noinit ".noinit"). */
extern __heap_start;

/** \ingroup util_ram_usage
    A weak symbol that defaults to  <tt>RAMEND + 1</tt>.
    It points one byte past the last location that is colored by
    the startup code.
    It can be adjusted by say<br>
\code
    avr-gcc ... -Wl,-defsym,__ram_color_end=<value>
\endcode
    in the link command, or by means of a global inline assembly statement
    like:
\code
    __asm (".global __ram_color_end\n"
           "__ram_color_end = <value>");
\endcode */
__ram_color_end;

/** \ingroup util_ram_usage
    A weak symbol that defaults to 0xaa.
    It represents the "color" that's being used by the startup code to
    paint the RAM, and the value that _get_ram_unused() will check against.
    It can be adjusted by say
\code
    avr-gcc ... -Wl,-defsym,__ram_color_value=<value>
\endcode
    in the link command. */
__ram_color_value;

#endif /* DOXYGEN */

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* _UTIL_RAM_USAGE_H_ */
