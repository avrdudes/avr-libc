# Copyright (c) 2002,2005, Reinhard Jessich  <reinhard.jessich@telering.at>
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

noinst_LIBRARIES = lib.a

eeprom_asm_sources = \
	ee_rb.S   \
	ee_rblk.S \
	ee_rw.S   \
	ee_wb.S   \
	ee_ww.S   \
	ee_wblk.S 

lib_a_asm_sources = \
	itoa.S    \
	ltoa.S    \
	mulsi10.S \
	mul10.S   \
	ultoa.S   \
	utoa.S

lib_a_SOURCES = $(lib_a_asm_sources)

lib_a_asm_objs = $(lib_a_asm_sources:%.S=%.o)

lib_a_LIBADD = $(eeprom_asm_sources:%.S=%.1F2021.o) \
               $(eeprom_asm_sources:%.S=%.1C1D1E.o)

lib_a_DEPENDENCIES = $(eeprom_asm_sources:%.S=%.1F2021.o) \
                     $(eeprom_asm_sources:%.S=%.1C1D1E.o)

# must be added to the package, but automake doesn't know it as source
# file until now
EXTRA_DIST = eeprom.S $(eeprom_asm_sources)

# content of AVRLIB_CFLAGS and AVRLIB_ASFLAGS is determined by configure
# according to the multilib subdir (see acinclude.m4 in top directory)

$(lib_a_asm_objs): %.o: %.S
	$(COMPILE) $(AVRLIB_ASFLAGS) -c $< -o $@

%.1C1D1E.o: %.S
	$(COMPILE) $(AVRLIB_ASFLAGS) -c $< -o $@ -DEEPROM_REG_LOCATIONS_OVERRIDE=1C1D1E

%.1F2021.o: %.S
	$(COMPILE) $(AVRLIB_ASFLAGS) -c $< -o $@ -DEEPROM_REG_LOCATIONS_OVERRIDE=1F2021
