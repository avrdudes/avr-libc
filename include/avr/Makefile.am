# Copyright (c) 2004,2005,2006,2007  Theodore A. Roth
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
# * Redistributions of source code must retain the above copyright
#   notice, this list of conditions and the following disclaimer.
# * Redistributions in binary form must reproduce the above copyright
#   notice, this list of conditions and the following disclaimer in
#   the documentation and/or other materials provided with the
#   distribution.
# * Neither the name of the copyright holders nor the names of
#   contributors may be used to endorse or promote products derived
#   from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#
# $Id$
#

avrdir = $(prefix)/avr/include/avr
avr_HEADERS = \
    boot.h \
    crc16.h \
    delay.h \
    eeprom.h \
    interrupt.h \
    io.h \
    io1200.h \
    io2313.h \
    io2323.h \
    io2333.h \
    io2343.h \
    io43u32x.h \
    io43u35x.h \
    io4414.h \
    io4433.h \
    io4434.h \
    io76c711.h \
    io8515.h \
    io8534.h \
    io8535.h \
    io86r401.h \
    ioat94k.h \
    iocan32.h \
    iocan64.h \
    iocan128.h \
    iocanxx.h \
    iousb646.h \
    iousb647.h \
    iousb1286.h \
    iousb1287.h \
    iousbxx6_7.h \
    iom103.h \
    iom128.h \
    iom1280.h \
    iom1281.h \
    iom2560.h \
    iom2561.h \
    iom16.h \
    iom161.h \
    iom162.h \
    iom163.h \
    iom164.h \
    iom165.h \
    iom165p.h \
    iom168.h \
    iom169.h \
    iom169p.h \
    iom32.h \
    iom323.h \
    iom324.h \
    iom325.h \
    iom3250.h \
    iom329.h \
    iom3290.h \
    iom3290p.h \
    iom48.h \
    iom406.h \
    iom64.h \
    iom640.h \
    iom644.h \
    iom645.h \
    iom6450.h \
    iom649.h \
    iom6490.h \
    iom8.h \
    iom8515.h \
    iom8535.h \
    iom88.h \
    iomx8.h \
    iomxx0_1.h \
    iomxx4.h \
    io90pwm1.h \
    io90pwmx.h \
    iotn11.h \
    iotn12.h \
    iotn13.h \
    iotn15.h \
    iotn22.h \
    iotn2313.h \
    iotn24.h \
    iotn25.h \
    iotn26.h \
    iotn261.h \
    iotn28.h \
    iotn44.h \
    iotn45.h \
    iotn461.h \
    iotn84.h \
    iotn85.h \
    iotn861.h \
    iotnx4.h \
    iotnx5.h \
    iotnx61.h \
    parity.h \
    pgmspace.h \
    portpins.h \
    power.h \
    sfr_defs.h \
    signal.h \
    sleep.h \
    version.h \
    wdt.h

EXTRA_DIST = \
    version.h.in

do_subst = sed \
	-e 's,[@]AVR_LIBC_MAJOR[@],$(AVR_LIBC_MAJOR),g' \
	-e 's,[@]AVR_LIBC_MINOR[@],$(AVR_LIBC_MINOR),g' \
	-e 's,[@]AVR_LIBC_REVISION[@],$(AVR_LIBC_REVISION),g' \
	-e 's,[@]AVR_LIBC_RELDATE[@],$(AVR_LIBC_RELDATE),g' \
	-e 's,[@]AVR_LIBC_VERSION[@],$(AVR_LIBC_VERSION),g' \
	-e 's,[@]AVR_LIBC_VERSION_NUMERIC[@],$(AVR_LIBC_VERSION_NUMERIC),g'

version.h: version.h.in $(top_builddir)/config.h
	$(do_subst) < $(srcdir)/version.h.in > version.h

CLEANFILES = version.h
