# AVR-LibC

This is the standard library for Microchip (formerly Atmel) AVR
devices together with the AVR-GCC compiler.

The library contains most of the functionality required by the ISO C
standard, with the notable exception of `wchar_t` support. It also
contains a lot of auxiliary functionality targeted to the AVR
controller family. Further, it includes customizable startup code,
tailored to work together with the linker scripts provided by the GNU
Binutils, so for most AVR applications, there is usually no need to
provide project-specific files for that purpose.

See the [documentation](https://avrdudes.github.io/avr-libc/)
for details.

The library is distributed using a modified BSD-style
[license](LICENSE).

## AVR-LibC Source Code

The official source code repository is located at
https://github.com/avrdudes/avr-libc/

### Building AVR-LibC from the Source Code

AVR-LibC depends on [GNU Binutils](https://sourceware.org/binutils/) (>= 2.13)
and [GCC](https://gcc.gnu.org/) (>= 3.3) that should be built for the AVR
target (configure --target=avr). Detailed instructions how to build these from
source can be found on
[Building and Installing the GNU Tool Chain](http://https://avrdudes.github.io/avr-libc/avr-libc-user-manual/install_tools.html) documentation page.

Note that to build AVR-LibC directly by cloning the GitHub repository, you will
need to run the `bootstrap` script in the root directory first. AVR-LibC uses
[autoconf]() so be sure to use resent versions of `autoconf` (>= 1.9)
and `automake` (>= 2.59) in order to generate the `configure`
script and `Makefiles`. This also requires Python being installed and available
in the system path.