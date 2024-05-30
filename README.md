# AVR LibC

This is the standard library for Atmel AVR devices together with the
AVR-GCC compiler.

The library contains most of the functionality required by the ISO C
standard, with the notable exception of `wchar_t` support. It also
contains a lot of auxiliary functionality targeted to the AVR
controller family. Further, it includes customizable startup code,
tailored to work together with the linker scripts provided by the GNU
Binutils, so for most AVR applications, there is usually no need to
provide project-specific files for that purpose.

See the [documentation](https://www.nongnu.org/avr-libc/user-manual/)
for details.

The library is distributed using a modified BSD-style
[license](LICENSE).

## AVR LibC Source Code

The official source code repository is located at
https://github.com/avrdudes/avr-libc/
