## Adding a New Device

* Store the device header like `ioa5791.h` in `include/avr/`.

* Add a line in `include/avr/io.h`, like
  ```
  #elif defined (__AVR_ATA5791__)
  #  include <avr/ioa5791.h>
  ```

* Add a line in `devtools/gen-avr-lib-tree.sh.in` like
  ```
  ata5791:crta5791.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
  ```

* Add the device to `devtools/generate_iosym.sh`

* Generate the iosym file by running `./generate_iosym.sh` from
  `devtools/`, like
  ```
  $ DEVS="ata5791" ATDFDIR=$HOME/atpack/atdf/ ./generate_iosym.sh
  ```

* Add device support to:
  ```
  include/avr/power.h
  include/avr/wdt.h
  libc/misc/eedef.h
  ```
  etc. as needed.

* Bootstrap, configure and build AVR-LibC as usual.
  `configure` will say something like:
  ```
  checking if avr-gcc has support for ata5791... yes, in avr5
  checking if ata5791 supports a compact vector table... no
  config.status: creating avr/devices/ata5791/Makefile
  ```
  Outcome of the build will be startup code and device library
  in `$builddir`, like:
  ```
  $ find . -name '*5791.*'
  ./avr/devices/ata5791/crtata5791.o
  ./avr/devices/ata5791/libata5791.a
  ```
  which will be installed in their multilib destination:
  ```
  $ find . -name '*5791.*'
  ./avr/include/avr/ioa5791.h
  ./avr/lib/avr5/crtata5791.o
  ./avr/lib/avr5/libata5791.a
  ./avr/lib/avr5/double64/crtata5791.o
  ./avr/lib/avr5/double64/libata5791.a
  ```

## Documenting a New Device

* Add the device in `doc/api/main_page.dox.in`.

* Re-build the ISR names table: In `doc/api/` run
  ```
  $ CC=avr-gcc ./gen-vectortable-dox.sh
  ```
  which will update `doc/api/vectortable.dox`. The script requires
  a previous bootstrap so that `tmp-device-info` is available at
  top srcdir.  When the updated `vectortable.dox` lists the device
  as only having *"deprecated `SIG_` names available"*, then it may
  be the case that the used avr-gcc doesn't support the device,
  and you can specify the compiler in `CC` as indicated above.

## Deploying

* Mention the new device in the NEWS file.

* Add the changed files and the two new files (device header
  and iosym file) to git.

