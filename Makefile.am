# Copyright (c) 2002, 2005 Reinhard Jessich  <reinhard.jessich@telering.at>
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

# Multilib support variables.
MULTISRCTOP =
MULTIBUILDTOP =
MULTIDIRS =
MULTISUBDIR =
MULTIDO = true
MULTICLEAN = true

# Work around what appears to be a GNU make bug handling MAKEFLAGS
# values defined in terms of make variables, as is the case for CC and
# friends when we are called from the top level Makefile.
AM_MAKEFLAGS = \
	"AR_FLAGS=$(AR_FLAGS)" \
	"CC_FOR_BUILD=$(CC_FOR_BUILD)" \
	"CFLAGS=$(CFLAGS)" \
	"CFLAGS_FOR_BUILD=$(CFLAGS_FOR_BUILD)" \
	"CFLAGS_FOR_TARGET=$(CFLAGS_FOR_TARGET)" \
	"LDFLAGS=$(LDFLAGS)" \
	"LIBCFLAGS=$(LIBCFLAGS)" \
	"LIBCFLAGS_FOR_TARGET=$(LIBCFLAGS_FOR_TARGET)" \
	"MAKE=$(MAKE)" \
	"MAKEINFO=$(MAKEINFO) $(MAKEINFOFLAGS)" \
	"PICFLAG=$(PICFLAG)" \
	"PICFLAG_FOR_TARGET=$(PICFLAG_FOR_TARGET)" \
	"SHELL=$(SHELL)" \
	"EXPECT=$(EXPECT)" \
	"RUNTEST=$(RUNTEST)" \
	"RUNTESTFLAGS=$(RUNTESTFLAGS)" \
	"exec_prefix=$(exec_prefix)" \
	"infodir=$(infodir)" \
	"libdir=$(libdir)" \
	"prefix=$(prefix)" \
	"tooldir=$(tooldir)" \
	"AR=$(AR)" \
	"AS=$(AS)" \
	"CC=$(CC)" \
	"LD=$(LD)" \
	"NM=$(NM)" \
	"PICFLAG=$(PICFLAG)" \
	"RANLIB=$(RANLIB)" \
	"DESTDIR=$(DESTDIR)"

FLAGS_TO_PASS = $(AM_MAKEFLAGS)

SUBDIRS = crt1 libc libm scripts @DOCSDIR@
DIST_SUBDIRS = crt1 libc libm doc scripts

tooldir = $(exec_prefix)/$(host_alias)
toollibdir = $(tooldir)/lib$(MULTISUBDIR)

AR_FLAGS = rc

toollib_LIBRARIES = libc.a libm.a \
	libprintf_min.a libprintf_flt.a \
	libscanf_min.a libscanf_flt.a
toollib_DATA = $(AVR_CRT_AT90) $(AVR_CRT_TINY) $(AVR_CRT_MEGA) $(AVR_CRT_OTHER)

# must be defined as empty, so that make dist will work
libc_a_SOURCES =
libm_a_SOURCES =
libprintf_min_a_SOURCES =
libprintf_flt_a_SOURCES =
libscanf_min_a_SOURCES =
libscanf_flt_a_SOURCES =

EXTRA_DIST = config-ml.in doconf dodist domake reconf LICENSE common include \
             ChangeLog-2004 \
             ChangeLog-2003 \
             ChangeLog-2002

libc.a: libc/libc.a
	rm -f $@
	ln libc/libc.a $@ >/dev/null 2>/dev/null || cp libc/libc.a $@

libc/libc.a: ; @true

libm.a: libm/libm.a
	rm -f $@
	ln libm/libm.a $@ >/dev/null 2>/dev/null || cp libm/libm.a $@

libm/libm.a: ; @true

libprintf_min.a: libc/stdio/libprintf_min.a
	rm -f $@
	ln libc/stdio/libprintf_min.a $@ >/dev/null 2>/dev/null ||\
	cp libc/stdio/libprintf_min.a $@

libprintf_flt.a: libc/stdio/libprintf_flt.a
	rm -f $@
	ln libc/stdio/libprintf_flt.a $@ >/dev/null 2>/dev/null ||\
	cp libc/stdio/libprintf_flt.a $@

libscanf_min.a: libc/stdio/libscanf_min.a
	rm -f $@
	ln libc/stdio/libscanf_min.a $@ >/dev/null 2>/dev/null ||\
	cp libc/stdio/libscanf_min.a $@

libscanf_flt.a: libc/stdio/libscanf_flt.a
	rm -f $@
	ln libc/stdio/libscanf_flt.a $@ >/dev/null 2>/dev/null ||\
	cp libc/stdio/libscanf_flt.a $@

crt%.o: crt1/crt%.o
	rm -f $@
	ln $< $@ >/dev/null 2>/dev/null || cp $< $@

crt1/crt%.o: ; @true

install-data-local:	install-toollibLIBRARIES
	$(MULTIDO) $(AM_MAKEFLAGS) DO=install multi-do
	-if [ -z "$(MULTISUBDIR)" ]; then \
	  $(mkinstalldirs) $(DESTDIR)$(tooldir)/include; \
	  for i in $(srcdir)/include/*.h; do \
	   $(INSTALL_DATA) $$i $(DESTDIR)$(tooldir)/include/`basename $$i`; \
	  done; \
	  $(mkinstalldirs) $(DESTDIR)$(tooldir)/include/avr; \
	  for i in $(srcdir)/include/avr/*.h; do \
	   $(INSTALL_DATA) $$i $(DESTDIR)$(tooldir)/include/avr/`basename $$i`; \
	  done; \
	else true; fi

# Multilib support.
.PHONY: all-multi mostlyclean-multi clean-multi distclean-multi \
	maintainer-clean-multi

all-recursive: all-multi
mostlyclean-recursive: mostlyclean-multi
clean-recursive: clean-multi
distclean-recursive: distclean-multi
maintainer-clean-recursive: maintainer-clean-multi

all-multi:
	$(MULTIDO) $(AM_MAKEFLAGS) DO=all multi-do
mostlyclean-multi:
	$(MULTICLEAN) $(AM_MAKEFLAGS) DO=mostlyclean multi-clean
clean-multi:
	$(MULTICLEAN) $(AM_MAKEFLAGS) DO=clean multi-clean
distclean-multi:
	$(MULTICLEAN) $(AM_MAKEFLAGS) DO=distclean multi-clean
maintainer-clean-multi:
	$(MULTICLEAN) $(AM_MAKEFLAGS) DO=maintainer-clean multi-clean

dist-hook:
	cp avr-libc.spec $(distdir)/avr-libc.spec
	rm -rf $(distdir)/common/CVS
	rm -rf $(distdir)/include/CVS
	rm -rf $(distdir)/include/avr/CVS
	rm -rf $(distdir)/doc/CVS
	rm -rf $(distdir)/doc/examples/CVS


MAKEOVERRIDES=
