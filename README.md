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
https://github.com/avrdudes/avr-libc/.

### Building and installing AVR-LibC from source

AVR-LibC depends on [GNU Binutils](https://sourceware.org/binutils/) and
[GCC](https://gcc.gnu.org/) that should be built for the AVR target. We
recommend to use the most recent versions of these tools. Detailed instructions
on building these tools from source can be found in
[Building and Installing the GNU Tool Chain](https://avrdudes.github.io/avr-libc/avr-libc-user-manual/install_tools.html).

Note that to build AVR-LibC directly by cloning the GitHub repository, you will
need to run the `bootstrap` script in the root directory first. AVR-LibC uses
[autoconf](https://www.gnu.org/software/autoconf/) so be sure to use recent
versions of `autoconf` and `automake` to generate the `configure` script and
the `Makefile`s. This also requires Python being installed and available in
the system path.
