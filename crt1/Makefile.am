#
# $Id$
#
# Copyright (c) 2002, 2004  Reinhard Jessich  <reinhard.jessich@telering.at>
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

## Process this file with automake to generate Makefile.in

# content of AVR_CRT_xxx is determined by configure according to the multilib
# subdir (see acinclude.m4 in top directory)
noinst_DATA = $(AVR_CRT_AT90) $(AVR_CRT_TINY) $(AVR_CRT_MEGA) $(AVR_CRT_OTHER)

# must be added to the package, but automake doesn't know them as source
# files until now
EXTRA_DIST = gcrt1.S

# if we have no sources, COMPILE is not defined by automake
COMPILE = $(CC) $(DEFS) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(AM_CFLAGS) $(CFLAGS)

# content of AVR_CRT_ASFLAGS is set by configure (see acinclude.m4 in top
# directory)

$(AVR_CRT_AT90): crt%.o: gcrt1.S
	$(COMPILE) $(AVR_CRT_ASFLAGS) -mmcu=at90$* -c $< -o $@

$(AVR_CRT_MEGA): crtm%.o: gcrt1.S
	$(COMPILE) $(AVR_CRT_ASFLAGS) -mmcu=atmega$* -c $< -o $@

$(AVR_CRT_TINY): crttn%.o: gcrt1.S
	$(COMPILE) $(AVR_CRT_ASFLAGS) -mmcu=attiny$* -c $< -o $@

# $(AVR_CRT_OTHER) - devices that don't follow a common naming convention.
crtat94k.o: gcrt1.S
	$(COMPILE) $(AVR_CRT_ASFLAGS) -mmcu=at94k -c $< -o $@

crtcan128.o: gcrt1.S
	$(COMPILE) $(AVR_CRT_ASFLAGS) -mmcu=at90can128 -c $< -o $@

crt43320.o: gcrt1.S
	$(COMPILE) $(AVR_CRT_ASFLAGS) -mmcu=at43usb320 -c $< -o $@

crt43355.o: gcrt1.S
	$(COMPILE) $(AVR_CRT_ASFLAGS) -mmcu=at43usb355 -c $< -o $@

crt76711.o: gcrt1.S
	$(COMPILE) $(AVR_CRT_ASFLAGS) -mmcu=at76c711 -c $< -o $@

crt86401.o: gcrt1.S
	$(COMPILE) $(AVR_CRT_ASFLAGS) -mmcu=at86rf401 -c $< -o $@

