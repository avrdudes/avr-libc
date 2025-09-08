#
# Copyright (c) 2002,2005  Theodore A. Roth
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
# 3. The name of the author may not be used to endorse or promote products
#    derived from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
# IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
# OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN
# NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
# SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
# TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
# PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
# LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
# NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
# SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
# Author: Theodore A. Roth <troth@verinet.com>

MAINTAINERCLEANFILES = Makefile.in

DEMO_SRCS            = \
                       asmdemo/Makefile \
                       asmdemo/asmdemo.c \
                       asmdemo/isrs.S \
                       asmdemo/project.h \
                       demo/Makefile \
                       demo/demo.c \
                       largedemo/Makefile \
                       largedemo/largedemo.c \
                       stdiodemo/Makefile \
                       stdiodemo/defines.h \
                       stdiodemo/hd44780.c \
                       stdiodemo/hd44780.h \
                       stdiodemo/lcd.c \
                       stdiodemo/lcd.h \
                       stdiodemo/stdiodemo.c \
                       stdiodemo/uart.c \
                       stdiodemo/uart.h \
                       twitest/Makefile \
                       twitest/twitest.c

DEMO_DIRS            = asmdemo \
                       demo \
                       largedemo \
                       stdiodemo \
                       twitest

EXTRA_DIST           = ${DEMO_SRCS} \
                       all-demos.dox \
                       asmdemo/asmdemo.dox \
                       demo/demo.dox \
                       largedemo/largedemo-setup.jpg \
                       largedemo/largedemo.dox \
                       stdiodemo/stdiodemo-setup.jpg \
                       stdiodemo/stdiodemo.dox \
                       twitest/twitest.dox

dir_examples = $(DOC_INST_DIR)/$(AVR_LIBC_USER_MANUAL)/examples
obj_examples = $(top_builddir)/doc/api/$(AVR_LIBC_USER_MANUAL)/examples

# Install demo source files.
install-data-local:
	$(mkinstalldirs) $(dir_examples)
	for dir in $(DEMO_DIRS) ; do \
	  $(mkinstalldirs) $(dir_examples)/$$dir; \
	done
	for file in $(DEMO_SRCS) ; do \
	  echo "Installing $$file into $(dir_examples)/$$file"; \
	  $(INSTALL_DATA) $(top_srcdir)/doc/examples/$$file \
	    $(dir_examples)/$$file; \
	done

uninstall-local:
	for file in $(DEMO_SRCS) ; do \
	  echo "Removing $(dir_examples)/$$file"; \
	  rm -f $(dir_examples)/$$file; \
	done
	for dir in $(DEMO_DIRS) ; do \
	  rmdir $(dir_examples)/$$dir || \
	  echo "rmdir $(dir_examples)/$$dir failed."; \
	done
	rmdir $(dir_examples) ||\
	  echo "rmdir $(dir_examples) failed."

# Copy the examples to builddir.  This is needed so that the
# HTML tarball contains the examples.  Actions are the same like
# for install-data-local above except that the target dir differs.
demo-examples:
	$(mkinstalldirs) $(obj_examples)
	for dir in $(DEMO_DIRS) ; do \
	  $(mkinstalldirs) $(obj_examples)/$$dir; \
	done
	for file in $(DEMO_SRCS) ; do \
	  echo "Installing $$file into $(obj_examples)/$$file"; \
	  $(INSTALL_DATA) $(top_srcdir)/doc/examples/$$file \
	    $(obj_examples)/$$file; \
	done

.PHONY: demo-examples

#############################################################################
## Make sure that the provided examples can be built.
## Except for example-demo used by doc/api/Makefile.am, the targets
## are used from nowhere, but can be run by hand like:
##
##    make all-examples
##    make example-asmdemo
##
## The requirement is that the respective demo Makefiles all compile
## and link with CC, and have $(LIBS) at the end of the link command.
##
## All the required prerequisites are build by hand below so that you
## can build an example without building the entire avr-libc first.

.PHOMNY: all-examples $(DEMO_DIRS:%=example-%)

all-examples: $(DEMO_DIRS:%=example-%)

# We must know the MCUs so we can build the prerequisite crt and multilib.
MCU_demo = atmega328p
MCU_asmdemo = attiny13
MCU_twitest = atmega128
MCU_stdiodemo = atmega328p
MCU_largedemo = atmega16

# The relative multilib path for mcu $1.
Pml = $(shell $(CC) -print-multi-directory -mmcu=$1)

# Map multilib directory to ident: avr2/tiny-stack => avr2_tiny_stack.
Mdir2Id = $(subst -,_,$(subst /,_,$(subst .,avr2,$1)))

# The absolute path to the multilib for mcu $1 in $builddir/avr/lib.
McuMlib = $(abs_top_builddir)/avr/lib/$(call Mdir2Id,$(call Pml,$1))

# The absolute path to mcu $1 in $builddir/avr/devices.
McuDevi = $(abs_top_builddir)/avr/devices/$1

# Filter out elements containing "cvt" from list $1.
FiltCvt = $(foreach w,$1,$(if $(findstring cvt,$w),,$w))

# The absolut path to crt*.o for mcu $1.
McuCrto = $(call FiltCvt,$(wildcard $(call McuDevi,$1)/crt*.o))

# The device library for $1 as -l<mcu>, if any.
if HAS_DEV_LIB
lMcuLib = -l$1
endif

# CC to build the demos.
CCdemo = $(CC) -I$(abs_top_srcdir)/include -I$(abs_top_builddir)/include

# LIBS passed to Makefiles.
LIBSdemo = -nostartfiles -nodefaultlibs \
	   $(call McuCrto,$1) \
	   -L$(call McuMlib,$1) \
	   -L$(call McuDevi,$1) \
	   -Wl,--start-group -lm -lc -lgcc $(call lMcuLib,$1) -Wl,--end-group

$(DEMO_DIRS:%=example-%) : example-%:
	@echo ""
	@echo "== $@: $(MCU_$*): prerequisites =="
	cd $(call McuMlib,$(MCU_$*)); $(MAKE)
	cd $(call McuDevi,$(MCU_$*)); $(MAKE)
	@echo ""
	@echo "== $@: $(MCU_$*) =="
	cd $(top_srcdir)/doc/examples/$*; $(MAKE) clean
	cd $(top_srcdir)/doc/examples/$*; $(MAKE) AWK=$(AWK) \
		CC="$(call CCdemo,$(MCU_$*))" \
		LIBS="$(call LIBSdemo,$(MCU_$*))"
