# Changes since AVR-LibC v2.2.0

## General

## ABI and API Changes

- **Parts of the startup code are now optional and have been moved
  from `crt<mcu>.o` to the device support library `lib<mcu>.a`.**\
  When a specific part of the startup code are not wanted,
  a respective symbol can be defined so that the associated code
  is no more pulled in:
  - Define `__init_sp` to skip the setting of SP in `.init2` (#1011).
  - Define `__call_main` to skip calling `main` and `exit`
    in `.init9` (#1012).\
    `main` must be executed by other means, e.g. by putting it in
    section `.init9` which is supported by
    [-mno-call-main](https://gcc.gnu.org/onlinedocs/gcc/AVR-Options.html#index-mno-call-main)
    since [GCC v15](https://gcc.gnu.org/gcc-15/changes.html#avr).
  - Define `__init_cvt` to skip setting CPUINT_CTRLA.CPUINT_CVT in
    `.init3` (#1010).\
    This is only relevant when a *Compact Vector Table* is in effect,
    for example my means of
    [-mcvt](https://gcc.gnu.org/onlinedocs/gcc/AVR-Options.html#index-mcvt)
    as supported since GCC v15.

## Improvements and Additions

- Support has been added for: ATxmega16E5, ATA5791, ATA8210, ATA8510 (#876),
  ATA5835, ATA5787, ATA5700M322, ATtiny416auto,
  AVR16DU14, AVR16DU20, AVR16DU28, AVR16DU32,
  AVR32DU14, AVR32DU20, AVR32DU28, AVR32DU32.

- Support has been added for the `stpcpy`, `stpcpy_P`, `stpcpy_F`,
  `stpcpy_PF`, `stpcpy_FX` functions (#1015).

- Support has been added for some functions on Reduced Tiny (AVRrc):
  `memmem`, `memmem_P`, `strlcpy`, `strlcpy_P`, `strcasestr`, `strcasestr_P`,
  `strspn`, `strspn_P`, `strcspn`, `strcspn_P`, `strlcat_P`, `strsep`,
  `strsep_P`, `strpbrk_P`, `strtok_rP`, `ltoa`, `ultoa`.

- Support has beed added for the ISO/IEC TR 18037 functions
  `rdivi`, `urdivi`, `lrdivi`, `ulrdivi` (#999).

- Support a new header
  [<avr/flash.h>](https://avrdudes.github.io/avr-libc/avr-libc-user-manual/group__avr__flash.html#details)
  for better support of avr-gcc's
  named address spaces `__flash` and `__flashx`.  For example, it provides
  functions like `strcpy_F` and `strcpy_FX` that work
  the same like `strcpy_P` and `strcpy_PF` from
  `<avr/pgmspace.h>`, but use proper address-space qualifiers.

- Support for Compact Vector Tables has been added as #1010.
  It is provided by `crt<mcu>-cvt.o`.  One way to use that variant
  of the startup code is by means of avr-gcc
  [-mcvt](https://gcc.gnu.org/onlinedocs/gcc/AVR-Options.html#index-mcvt)
  which is supported since GCC v15.

- Support the `ISR_N` macro in
  [avr/interrupt.h](https://avrdudes.github.io/avr-libc/avr-libc-user-manual/group__avr__interrupts.html#details).
  This allows to specify
  the IRQ number as an argument to the signal attribute, which is supported
  since GCC v15 [PR116056](https://gcc.gnu.org/PR116056).
  It allows to use static functions or functions
  defined in a C++ namespace as an ISR.   It also allows to define ISR
  aliases without the penalty of an additional JMP/RJMP instruction (#765).

- The C/C++ register footprint of some common simple functions has
  been improved by implementing them as extern inline assembly stubs:
  `strlen`, `strlen_P`, `strcpy`, `strcpy_P`, `strcmp`, `strcmp_P`,
  `memcpy_P` (#1013).

- `common/asmdef.h` used a sub-optimal definition of XJMP and XCALL (#993).
  Outcome was a sub-optimal code generation for some devices like the
  ones in `avrxmega3/short-calls`.

- avr-gcc v15 and up issues a diagnostic for `__int24` and `__uint24` when
  `-pedantic` or similar options are on.  Hence `__extension__` was
  added when using these types in `avr/pgmspace.h`.

## Issues closed

- Since v2.2.0 (#936), `gcrt1.S` defines symbols `__DATA_REGION_ORIGIN__`
  and `__DATA_REGION_LENGTH__` to allow for more precise diagnostics from
  the linker when the data region overflows.  However, letting `.data` start
  at `__DATA_REGION_ORIGIN__` is a relatively new addition in Binutils v2.40
  [PR29741](https://sourceware.org/PR29741),
  whereas using `__DATA_REGION_LENGTH__` for `.data` size is a much
  older addition.

  Outcome may be that the linker script adopts the true
  size of `.data` but not its start address, resulting in incorrect errors
  from the linker (#971).  In order to resolve #971, a configure
  test has been added that checks for PR29741, and only defines the mentioned
  symbols when PR29741 is available.

  A similar test has been added for [PR31177](https://sourceware.org/PR31177)
  which is a similar feature for the `.text` region.

- On Reduced Tiny, add 0x4000 to the symbol address when
  `pgm_get_far_address()` takes the address of an object in `PROGMEM_FAR`.
  This works similar to how the compiler implements the &-operator
  for `PROGMEM` objects (#970).

- Fixed `memccpy` (and `memccpy_P`) on AVRrc (#1018).

- Fixed `atoi` and `atol` on AVRrc (#1019).

- Define types from `stdint.h` like `int32_t` without `attribute((mode))`
  (#496).

- Fixed `ld: undefined reference to E2END` (#973).

- Don't skip 2-word instructions on cores with an according silicon bug.
  This will fix AVR-LibC build warnings as mentioned in #994 like:<br>
  `libc/stdlib/ctype.S:80: Warning: skipping two-word instruction`

- The `str[n]casecmp_PF` functions used an algorithm that lead to different
  results compared to `str[n]casecmp[_P]`.  The far versions have been
  fixed so that they comply to POSIX.1-2008 (#1009).

- `fflush()` is now implemented as a proper (non-inline) function so that
  features like `-wrap` will work as expected (#1017, #1003).

## Pull Requests

- Improve runtime performance of `free()` (#991).

## Other Changes

- New news are now in `NEWS.md` and no more in [`NEWS`](NEWS).
