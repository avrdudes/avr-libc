#
# Copyright (c) 2002  Theodore A. Roth
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
MAINTAINERCLEANFILES = Makefile.in stamp-vti

CLEANFILES           = *.html *.pdf *.ma *.mas *.ps

EXTRA_DIST           = dox.css dox_html_header dox_html_footer

SUFFIXES             = .pdf

DOC_INST_DIR         = $(DESTDIR)$(datadir)/doc/osavr-$(VERSION)

all-local: ps html $(TARGET_PDF)

# Rule for generating postscript output.
ps: $(TARGET_DOX_PS)

install-ps: ps $(INSTALL_DOX_PS)
	$(mkinstalldirs) $(DOC_INST_DIR)
	$(INSTALL_DATA) avr-libc-api.ps $(DOC_INST_DIR)/avr-libc-api.ps

# Rule for generating html output.
html: $(TARGET_DOX_HTML)

install-html: $(INSTALL_DOX_HTML)

# General rule for installing documentation
install-data-local: install-html install-ps $(INSTALL_PDF)

uninstall-local:
	rm -rf $(DOC_INST_DIR)

clean-local:
	rm -rf html latex

# Rule for generating PDF output
pdf: $(TARGET_DOX_PDF)

install-pdf: $(INSTALL_DOX_PDF)
	$(mkinstalldirs) $(DOC_INST_DIR)
	$(INSTALL_DATA) avr-libc-api.pdf $(DOC_INST_DIR)/avr-libc-api.pdf

#
# Rules for generating documentation with doxygen
#

dox: html latex

html latex:
	doxygen doxygen.config

dox-html: html

dox-pdf: latex
	make -C latex pdf
	cp latex/refman.pdf avr-libc-api.pdf

dox-ps: latex
	make -C latex ps
	cp latex/refman.ps avr-libc-api.ps

install-dox-html: html
	$(mkinstalldirs) $(DOC_INST_DIR)/html
	@list='$(wildcard html/*.html html/*.css)' ; \
	for file in $$list ; do \
	  echo " $(INSTALL_DATA) $$file $(DOC_INST_DIR)/$$file"; \
	  $(INSTALL_DATA) $$file $(DOC_INST_DIR)/$$file; \
	done

install-dox-pdf: dox-pdf
	$(mkinstalldirs) $(DOC_INST_DIR)
	$(INSTALL_DATA) latex/refman.pdf $(DOC_INST_DIR)/avr-libc-api.pdf

install-dox-ps: dox-ps
	$(mkinstalldirs) $(DOC_INST_DIR)
	$(INSTALL_DATA) latex/refman.ps $(DOC_INST_DIR)/avr-libc-api.ps

.PHONY: ps pdf dox dox-pdf install-pdf install-html install-ps install-dox-html \
	install-dox-ps install-dox-pdf

