# Changes since AVR-LibC v2.2.0

## General

## ABI and API Changes

- **Parts of the startup code are now optional and have been moved
  from `crt<mcu>.o` to the device support library `lib<mcu>.a`.**\
  When specific parts of the startup code are not wanted,
  a respective symbol can be defined so that the associated code
  is no more pulled in:
  - Define `__init_sp` to skip the setting of SP in `.init2` ([#1011][1011]).
  - Define `__call_main` to skip calling `main` and `exit`
    in `.init9` ([#1012][1012]).\
    `main` must be executed by other means, e.g. by putting it in
    section `.init9` which is supported by
    [-mno-call-main](https://gcc.gnu.org/onlinedocs/gcc/AVR-Options.html#index-mno-call-main)
    since [GCC v15](https://gcc.gnu.org/gcc-15/changes.html#avr).
  - Define `__init_cvt` to skip setting CPUINT_CTRLA.CPUINT_CVT in
    `.init3` ([#1010][1010]).\
    This is only relevant when a *Compact Vector Table* is in effect,
    for example my means of
    [-mcvt](https://gcc.gnu.org/onlinedocs/gcc/AVR-Options.html#index-mcvt)
    as supported since GCC v15.

## Improvements and Additions

- Support has been added for: ATxmega16E5, ATA5791, ATA8210, ATA8510
  ([#876][876]),
  ATA5835, ATA5787, ATA5700M322, ATtiny416auto,
  AVR32DA28S, AVR32DA32S, AVR32DA48S,
  AVR64DA28S, AVR64DA32S, AVR64DA48S AVR64DA64S,
  AVR128DA28S, AVR128DA32S, AVR128DA48S, AVR128DA64S,
  AVR16DU14, AVR16DU20, AVR16DU28, AVR16DU32,
  AVR32DU14, AVR32DU20, AVR32DU28, AVR32DU32,
  AVR32EB14, AVR32EB20, AVR32EB28, AVR32EB32,
  AVR32SD20, AVR32SD28, AVR32SD32.

- Support has been added for the `stpcpy`, `stpcpy_P`, `stpcpy_F`,
  `stpcpy_PF`, `stpcpy_FX` functions ([#1015][1015]).

- Support for the `strtoll` and `strtoull` functions has been added to
  [<stdlib.h>](https://avrdudes.github.io/avr-libc/avr-libc-user-manual/group__avr__stdlib.html).
  The `strtol` and `strtoul` functions have been rewritten to increase
  performance.

- The `strtod`, `strtold`, `atof` and `atofl` functions have been
  implemented to support IEEE double, i.e. they work with `-mdouble=64`.

- Support for some non-standard functions has been added to
  [<stdlib.h>](https://avrdudes.github.io/avr-libc/avr-libc-user-manual/group__avr__stdlib.html):
   - 64-bit integer to ASCII conversions: `lltoa`, `ulltoa`, `ulltoa_base10`.
   - 16-bit integer square root: `sqrtu16_floor`.
   - 32-bit integer square root: `sqrtu32_floor`.

- Support has been added for some functions on Reduced Tiny (AVRrc):
  `memmem`, `memmem_P`, `strlcpy`, `strlcpy_P`, `strcasestr`, `strcasestr_P`,
  `strspn`, `strspn_P`, `strcspn`, `strcspn_P`, `strlcat_P`, `strsep`,
  `strsep_P`, `strpbrk_P`, `strtok_rP`, `ltoa`, `ultoa`.

- Documentation for the
  [<stdfix.h>](https://avrdudes.github.io/avr-libc/avr-libc-user-manual/group__avr__stdfix.html#details)
  header for ISO/IEC TR 18037 fixed-point support has been added.

- Support has been added for the fixed-point arithmetic
  functions `rdivi`, `urdivi`, `lrdivi`, `ulrdivi` ([#999][999]),
  `sqrthr`, `sqrtuhr` ([#1024][1024]), `sqrtur`, `atank`, `atanuk`, `atanur`,
  `acosk`, `acosuk`, `asink`, `asinuk`,
  `log2uhk`, `log2uk`, `log21puhr`, `log21pur`,
  `exp2k`, `exp2uk`, `exp2m1ur`,
  `sinpi2k`, `sinuhk_deg`, `sinpi2ur`,
  `cospi2k`, `cosuhk_deg`.

- Support has been added for fixed-point to decimal ASCII conversions:
  `ktoa`, `uktoa`, `hktoa`, `uhktoa`, `rtoa`, `urtoa`, `hrtoa`, `uhrtoa`.

- Support for `llabs` has been added to
  [<stdlib.h>](https://avrdudes.github.io/avr-libc/avr-libc-user-manual/group__avr__stdlib.html).

- Support a new header
  [<avr/flash.h>](https://avrdudes.github.io/avr-libc/avr-libc-user-manual/group__avr__flash.html#details)
  for better support of avr-gcc's
  named address spaces `__flash` and `__flashx`.  For example, it provides
  functions like `strcpy_F` and `strcpy_FX` that work
  the same like `strcpy_P` and `strcpy_PF` from
  [<avr/pgmspace.h>](https://avrdudes.github.io/avr-libc/avr-libc-user-manual/group__avr__pgmspace.html#details),
  but use proper address-space qualifiers.

- Support for Compact Vector Tables has been added as [#1010][1010].
  It is provided by `crt<mcu>-cvt.o`.  One way to use that variant
  of the startup code is by means of avr-gcc
  [-mcvt](https://gcc.gnu.org/onlinedocs/gcc/AVR-Options.html#index-mcvt)
  which is supported since
  [GCC v15](https://gcc.gnu.org/gcc-15/changes.html#avr).

- Support the `ISR_N` macro in
  [<avr/interrupt.h>](https://avrdudes.github.io/avr-libc/avr-libc-user-manual/group__avr__interrupts.html#details).
  This allows to specify
  the IRQ number as an argument to the signal attribute, which is supported
  since GCC v15 [PR116056](https://gcc.gnu.org/PR116056).
  It allows to use static functions or functions
  defined in a C++ namespace as an ISR.   It also allows to define ISR
  aliases without the penalty of an additional JMP/RJMP instruction
  ([#765][765]).

- Support for a new non-standard header
  [<util/ram-usage.h>](https://avrdudes.github.io/avr-libc/avr-libc-user-manual/group__util__ram__usage)
  has been added.  It can be used to get estimates of how much stack is
  used by a running program.

- The `uint24_t`, `int24_t` and associated types and macros have been added
  to [<stdint.h>](https://avrdudes.github.io/avr-libc/avr-libc-user-manual/group__avr__stdint.html) ([#1045][1045]).

- EEPROM routines to access signed and unsigned integer types have
  been added to
  [<avr/eeprom.h>](https://avrdudes.github.io/avr-libc/avr-libc-user-manual/group__avr__eeprom) for: `char`, `uint8_t`, `int8_t`, `uint16_t`, `int16_t`,
  `uint24_t`, `int24_t`, `uint32_t`, `int32_t`, `uint64_t`, `int64_t`.

- The C/C++ register footprint of some common simple functions has
  been improved by implementing them as extern inline assembly stubs:
  `strlen`, `strlen_P`, `strcpy`, `strcpy_P`, `strcmp`, `strcmp_P`,
  `memcpy_P`, `strchr`, `strchr_P` ([#1013][1013]), and the functions from
   [<ctype.h>](https://avrdudes.github.io/avr-libc/avr-libc-user-manual/group__ctype).

- `common/asmdef.h` used a sub-optimal definition of XJMP and XCALL ([#993][993]).
  Outcome was a sub-optimal code generation for some devices like the
  ones in `avrxmega3/short-calls`.

- Support for the floating-point functions `log2`, `log2f` and `log2l`
  has been added to
  [<math.h>](https://avrdudes.github.io/avr-libc/avr-libc-user-manual/group__avr__math) ([#1032][1032]).

- The error of `asinf` has been improved from 8 ULPs to 3 ULPs.

- The error of `logf` has been improved from 5 ULPs to 3 ULPs.

- `assert` doesn't use `fprintf` anymore, but a custom, light-weight function
  instead in order to diagnose a failed assertion.

- `strftime` doesn't use `sprintf` anymore.
  The code size of `strftime` (including all dependencies) has been
  reduced by more than the code size of `sprintf`.
  Support has been added for the `%k`, `%l` and `%P` formats.
  String literals have been moved to `.progmemx`.

- The [benchmark page](https://avrdudes.github.io/avr-libc/avr-libc-user-manual/benchmarks.html)
  has been reworked.
  It includes now fixed-point and IEEE double floating-point benchmarks.
  The IEEE single floating-point benchmarks now include the code sizes,
  precision data, average execution times, and (lower bounds for the)
  worst case execution times.

- Apart from `-Wl,-u,vfprintf -lprintf_flt` there is now the alternative
  `-Wl,--defsym,vfprintf=vfprintf_flt` which doesn't link the printf
  code when the application doesn't use printf, and when linked with
  `-Wl,--gc-sections`. Similar applies to the minimal variants and
  to the scanf functions like `-Wl,--defsym,vfscanf=vfscanf_min`.
  See [vfprintf](https://avrdudes.github.io/avr-libc/avr-libc-user-manual/group__avr__stdio.html#gaa3b98c0d17b35642c0f3e4649092b9f1)
  and [#654][654].

- With `-mdouble=64`, functions from the printf family now perform
  floating-point conversions instead of just printing a `?`.
  The value is converted to IEEE single for conversion.

- Added configure option `--with-doxygen=` to select the Doxygen executable
  for generating the documentation.

## Issues closed

- See also the list of
  <a href="https://github.com/avrdudes/avr-libc/issues?q=state%3Aclosed%20milestone%3Av2.3">issues closed for v2.3</a>.

- Since v2.2.0 ([#936][936]), `gcrt1.S` defines symbols `__DATA_REGION_ORIGIN__`
  and `__DATA_REGION_LENGTH__` to allow for more precise diagnostics from
  the linker when the data region overflows.  However, letting `.data` start
  at `__DATA_REGION_ORIGIN__` is a relatively new addition in Binutils v2.40
  [PR29741](https://sourceware.org/PR29741),
  whereas using `__DATA_REGION_LENGTH__` for `.data` size is a much
  older addition.

  Outcome may be that the linker script adopts the true
  size of `.data` but not its start address, resulting in incorrect errors
  from the linker ([#971][971]).  In order to resolve [#971][971], a configure
  test has been added that checks for PR29741, and only defines the mentioned
  symbols when PR29741 is available.

  A similar test has been added for [PR31177](https://sourceware.org/PR31177)
  which is a similar feature for the `.text` region.

- Due to several problem reports concerning the I/O headers for ATxmega64A1U
  and ATxmega128A1U
  ([#391][391], [#635][635], [#643][643], [#663][663], [#875][875], [#959][959], [#960][960], [#961][961]),
  these headers have been updated to a more recent revision.

- Added defines to `avr/io.h` that match the names in the
  ATmega324PA data sheet ([#443][443]).

- Fixed signature definitions in avr/io.h for several devices ([#877][877])
  and add some missing signatures ([#878][878]).

- Add missing ATmega328PB power reduction switches `PRPTC` and `PRSPI1`
  to `avr/power.h` ([#668][668]).

- On AVRrc Reduced Tiny, add 0x4000 to the symbol address when
  `pgm_get_far_address()` takes the address of an object in `PROGMEM_FAR`.
  This works similar to how the compiler implements the &-operator
  for `PROGMEM` objects ([#970][970]).

- Fixed `memccpy` (and `memccpy_P`) on AVRrc ([#1018][1018]).

- Fixed `atoi` and `atol` on AVRrc ([#1019][1019]).

- Define types from `stdint.h` like `int32_t` without `attribute((mode))`
  ([#496][496]).

- Fixed `ld: undefined reference to E2END` ([#973][973]).

- Don't skip 2-word instructions on cores with an according silicon bug.
  This will fix AVR-LibC build warnings as mentioned in [#994][994] like:<br>
  `libc/stdlib/ctype.S:80: Warning: skipping two-word instruction`

- The `str[n]casecmp_PF` functions used an algorithm that lead to different
  results compared to `str[n]casecmp[_P]`.  The far versions have been
  fixed so that they comply to POSIX.1-2008 ([#1009][1009]).

- `fflush()` is now implemented as a proper (non-inline) function so that
  features like `--wrap` will work as expected.  For the same reason,
  `clearerr()`, `ferror()` and `feof()` are no more implemented as macros
  but are proper (non-inline) functions, too. ([#1017][1017], [#1003][1003]).

- Distribution is missing `dox_latex_header.tex`, `filter-dox.sh`,
  `avr-libc-logo-large.png` from `doc/api/` ([#1023][1023]).

- Fixed a typo in the parameter name of `nanf` ([#1033][1033]).

- `INFINITY` from `math.h` has been turned from `double` to
  `float` ([#1036][1036]).

- `XRAMEND` for ATmega128A is now defined to 0xffff ([#629][629]).

- Fixed `strftime`'s return value ([#1040][1040])
  and  `strftime("%r")` ([#1039][1039]).

- Fixed *"Calculations in util/setbaud.h are incorrect"* [#657][657].

- Saturate the value that `_delay_us` / `_delay_ms` are passing down to
  `__builtin_avr_delay_cycles` in order to avoid UB ([#681][681])
  for large values.

- Respect freelist size for small `realloc` allocations ([#660][660]).

- Let `calloc` return NULL when the alloc size overflows ([#1007][1007]).

- Fixed: `realloc` fails if extending block in-place crosses the
  address 0xffff ([#922][922]).

- Fixed fuse defines for ATA5790 ([#909][909]).

- Fixed the `ADC_CH_MUXNEG_enum` values for ATxmega256D3 ([#661][661]).

- Fixed FUSE4_DEFAULT etc. defines in Xmega I/O headers ([#523][523]).

- Fixed `atoff` forwarding from wrong `strtod` to correct `strtof`
  ([#1052][1052]).

## Pull Requests

- Modernized the
  [A simple project](https://avrdudes.github.io/avr-libc/avr-libc-user-manual/group__demo__project.html)
  demo example project: It now uses the ATmega328P device that is widely
  used, for example on the Arduino Nano boards ([#1044][1044], [#1048][1048]).

- Fix support for ATxmega devices in avr/wdt.h ([#646][646]).

- Improve runtime performance of `free()` ([#991][991]).

## Other Changes

- New news are now in `NEWS.md` and no more in [`NEWS`](NEWS).

[391]: https://github.com/avrdudes/avr-libc/issues/391
[443]: https://github.com/avrdudes/avr-libc/issues/443
[496]: https://github.com/avrdudes/avr-libc/issues/496
[523]: https://github.com/avrdudes/avr-libc/issues/523
[629]: https://github.com/avrdudes/avr-libc/issues/629
[635]: https://github.com/avrdudes/avr-libc/issues/635
[643]: https://github.com/avrdudes/avr-libc/issues/643
[646]: https://github.com/avrdudes/avr-libc/issues/646
[654]: https://github.com/avrdudes/avr-libc/issues/654
[657]: https://github.com/avrdudes/avr-libc/issues/657
[660]: https://github.com/avrdudes/avr-libc/issues/660
[661]: https://github.com/avrdudes/avr-libc/issues/661
[663]: https://github.com/avrdudes/avr-libc/issues/663
[668]: https://github.com/avrdudes/avr-libc/issues/668
[681]: https://github.com/avrdudes/avr-libc/issues/681
[765]: https://github.com/avrdudes/avr-libc/issues/765
[875]: https://github.com/avrdudes/avr-libc/issues/875
[876]: https://github.com/avrdudes/avr-libc/issues/876
[877]: https://github.com/avrdudes/avr-libc/issues/877
[878]: https://github.com/avrdudes/avr-libc/issues/878
[909]: https://github.com/avrdudes/avr-libc/issues/909
[922]: https://github.com/avrdudes/avr-libc/issues/922
[936]: https://github.com/avrdudes/avr-libc/issues/936
[959]: https://github.com/avrdudes/avr-libc/issues/959
[960]: https://github.com/avrdudes/avr-libc/issues/960
[961]: https://github.com/avrdudes/avr-libc/issues/961
[970]: https://github.com/avrdudes/avr-libc/issues/970
[971]: https://github.com/avrdudes/avr-libc/issues/971
[973]: https://github.com/avrdudes/avr-libc/issues/973
[991]: https://github.com/avrdudes/avr-libc/issues/991
[993]: https://github.com/avrdudes/avr-libc/issues/993
[994]: https://github.com/avrdudes/avr-libc/issues/994
[999]: https://github.com/avrdudes/avr-libc/issues/999
[1003]: https://github.com/avrdudes/avr-libc/issues/1003
[1007]: https://github.com/avrdudes/avr-libc/issues/1007
[1009]: https://github.com/avrdudes/avr-libc/issues/1009
[1010]: https://github.com/avrdudes/avr-libc/issues/1010
[1011]: https://github.com/avrdudes/avr-libc/issues/1011
[1012]: https://github.com/avrdudes/avr-libc/issues/1012
[1013]: https://github.com/avrdudes/avr-libc/issues/1013
[1015]: https://github.com/avrdudes/avr-libc/issues/1015
[1017]: https://github.com/avrdudes/avr-libc/issues/1017
[1018]: https://github.com/avrdudes/avr-libc/issues/1018
[1019]: https://github.com/avrdudes/avr-libc/issues/1019
[1023]: https://github.com/avrdudes/avr-libc/issues/1023
[1024]: https://github.com/avrdudes/avr-libc/issues/1024
[1032]: https://github.com/avrdudes/avr-libc/issues/1032
[1033]: https://github.com/avrdudes/avr-libc/issues/1033
[1036]: https://github.com/avrdudes/avr-libc/issues/1036
[1039]: https://github.com/avrdudes/avr-libc/issues/1039
[1040]: https://github.com/avrdudes/avr-libc/issues/1040
[1044]: https://github.com/avrdudes/avr-libc/issues/1044
[1045]: https://github.com/avrdudes/avr-libc/issues/1045
[1048]: https://github.com/avrdudes/avr-libc/issues/1048
[1052]: https://github.com/avrdudes/avr-libc/issues/1052
