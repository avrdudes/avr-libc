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
#
# Contributors:
#
# $Id$
#

MAINTAINERCLEANFILES = Makefile.in

DEMO_SRCS            = \
                       asmdemo/Makefile \
                       asmdemo/asmdemo.c \
                       asmdemo/isrs.S \
                       asmdemo/project.h \
                       demo/Makefile \
                       demo/demo.c \
                       demo/iocompat.h \
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
                       demo/demo.fig \
                       demo/demo.dox \
                       largedemo/largedemo-setup.jpg \
                       largedemo/largedemo-wiring.jpg \
                       largedemo/largedemo-wiring2.jpg \
                       largedemo/largedemo.dox \
                       stdiodemo/stdiodemo-setup.jpg \
                       stdiodemo/stdiodemo.dox \
                       twitest/twitest.dox

# Install demo source files.
install-data-local:
	$(mkinstalldirs) $(DOC_INST_DIR)/examples
	for dir in $(DEMO_DIRS) ; do \
	  $(mkinstalldirs) $(DOC_INST_DIR)/examples/$$dir; \
	done
	for file in $(DEMO_SRCS) ; do \
	  echo "Installing $$file into $(DOC_INST_DIR)/examples/$$file"; \
	  $(INSTALL_DATA) $(top_srcdir)/doc/examples/$$file \
	    $(DOC_INST_DIR)/examples/$$file; \
	done

uninstall-local:
	for file in $(DEMO_SRCS) ; do \
	  echo "Removing $(DOC_INST_DIR)/examples/$$file"; \
	  rm -f $(DOC_INST_DIR)/examples/$$file; \
	done
	for dir in $(DEMO_DIRS) ; do \
	  rmdir $(DOC_INST_DIR)/examples/$$dir || \
	  echo "rmdir $(DOC_INST_DIR)/examples/$$dir failed."; \
	done
	rmdir $(DOC_INST_DIR)/examples ||\
	  echo "rmdir $(DOC_INST_DIR)/examples failed."
