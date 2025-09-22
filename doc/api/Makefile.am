#
# Copyright (c) 2002, 2003, 2005,  Theodore A. Roth
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

MATH2DOX_H = stdfix-avrlibc.h stdlib.h

MATH2DOX_DOX = bench-libm.dox bench-libf7.dox
MATH2DOX_GEN_DOX = $(MATH2DOX_DOX:.dox=.gen.dox)

MAINTAINERCLEANFILES = Makefile.in stamp-vti

CLEANFILES           = *.html *.pdf $(MATH2DOX_H) $(MATH2DOX_GEN_DOX) \
                       malloc-*.svg malloc-*.eps \
                       doxygen.config main_page.dox faq.dox doxygen-pdf.config

EXTRA_DIST           = dox.css dox_html_header dox_html_footer \
                       dox_latex_header.tex \
                       doxygen.config.in \
                       main_page.dox.in \
                       assembler.dox \
                       inline_asm.dox \
                       interrupts.dox \
                       acknowledge.dox \
                       malloc.dox \
                       $(IMAGE_SRC) \
                       avr-libc-logo-large.png \
                       sections.dox \
                       sfr.dox \
                       tools-install.dox \
                       using-tools.dox \
                       faq.dox.in \
                       bench.dox \
                       bench-libc.dox \
                       bench-libm.dox \
                       bench-libf7.dox \
                       bench-fxlib.dox \
                       reordering-code.dox \
                       overview.dox \
                       pgmspace.dox \
                       library.dox \
                       filter-dox.sh \
                       gen-vectortable-dox.sh \
                       isrs-to-dox.py \
                       mcus-to-isrs.sh \
                       vectortable.dox

SUFFIXES             = .pdf .fig .svg .eps

DOC_INST_DIR         = @DOC_INST_DIR@

USER_MANUAL          = @AVR_LIBC_USER_MANUAL@

all-local: html pdf

# Before we can build the dox, we need to build the demo project so that some
# included files get generated.
demo: example-demo

# Copy examples to builddir.
demo-examples:
	( cd $(top_builddir)/doc/examples \
	  && ${MAKE} demo-examples )


# Forward to building the very ../examples.  Just run
#
#   make all-examples
#   make example-asmdemo
#
# by hand to check that the examples can be built.

ALL_EXAMPLES = demo asmdemo largedemo stdiodemo twitest

.PHONY: all-examples $(ALL_EXAMPLES:%=example-%)

all-examples $(ALL_EXAMPLES:%=example-%):
	cd ../examples; $(MAKE) $@


# images for inclusion in HTML and LaTeX documents

FIG2DEV= fig2dev

.fig.eps:
	$(FIG2DEV) -L eps $< $@

.fig.svg:
	$(FIG2DEV) -L svg $< $@

IMAGE_SRC=	malloc-std.fig malloc-x1.fig malloc-x2.fig \
		avr-libc-logo.png avr-libc-logo.png avr-libc-logo-inverted.png

IMAGE_SVG=	$(IMAGE_SRC:.fig=.svg)

IMAGE_EPS=	$(IMAGE_SRC:.fig=.eps)

# Rule for generating html output.
html: demo demo-examples $(TARGET_DOX_HTML)

# Rule for generating PDF output
pdf: demo $(TARGET_DOX_PDF)

# General rule for installing documentation
install-data-local: $(INSTALL_DOX_HTML) $(INSTALL_DOX_PDF) \
	$(INSTALL_DOX_MAN)

uninstall-local:
	rm -rf $(DOC_INST_DIR)

clean-local:
	rm -rf $(USER_MANUAL) latex_src man
	for demo in $(DOX_DEMOS); do \
	  ( cd $(top_srcdir)/doc/examples/$$demo && \
	  ${MAKE} clean ) ; \
	done

#
# Rules for generating documentation with doxygen
#

# Notes on the logo image:
#
# The overall Gimp source file is avr-libc-logo.xcf.bz2, 518px x 182px
# It contains layers for the individual logo components:
# * the AVR logo (taken from the AVRDUDE project)
# * the "LibC" text
# * the sourcecode snippet background
# * a white background just for visibility, not to be exported
#
# The logo is then exported to avr-libc-logo-large.png, to be used in the
# PDF documentation.
# A version scaled to 200px x 70px is exported to avr-libc-logo.png, to
# be used in HTML documentation.
# This version is further color-inverted, and exported to
# avr-libc-logo-inverted.png, to be used for "dark mode" HTML display.

# Let config.status rebuild headers and dox from .in.
doxygen.config:	$(top_builddir)/include/util/delay.h \
		main_page.dox faq.dox $(MATH2DOX_H) $(MATH2DOX_GEN_DOX)

$(top_builddir)/include/util/delay.h: $(top_srcdir)/include/util/delay.h.in
	cd $(top_builddir)/include/util && $(MAKE) delay.h

# Some Doxygen styles / environments render very poorly.
# Tweak that, e.g. by resorting to the original environment.
TEX_FIXES = -e 's:begin{DoxyDescription}:begin{DoxyDescription}[labelwidth=\\linewidth, labelsep=0pt, noitemsep]:'

latex_src/refman.tex: doxygen.config $(IMAGE_EPS) $(IMAGE_SVG) main_page.dox
	@DOXYGEN@ doxygen.config
	cp $(top_srcdir)/doc/api/avr-libc-logo.png $(AVR_LIBC_USER_MANUAL)/
	cp $(top_srcdir)/doc/api/avr-libc-logo-inverted.png $(AVR_LIBC_USER_MANUAL)/
	cp $(top_srcdir)/doc/api/avr-libc-logo-large.png latex_src/
	for t in latex_src/*.tex; do \
	   $(SED) -i $(TEX_FIXES) $$t; \
	   done

if HAVE_PYTHON
# stdfix-avrlibc.h has some simple formulae that are mistreated by Doxygen,
# in particular for the man pages.  Invoke a simple math -> dox processor.
$(MATH2DOX_H) : % : $(top_srcdir)/include/% \
		  $(top_builddir)/devtools/math2dox
	cat $< | $(top_builddir)/devtools/math2dox > $@

$(MATH2DOX_GEN_DOX) : %.gen.dox : $(top_srcdir)/doc/api/%.dox \
		  $(top_builddir)/devtools/math2dox
	cat $< | $(top_builddir)/devtools/math2dox > $@

# math2dox is a filter from STDIN to STDOUT.
$(top_builddir)/devtools/math2dox: $(top_srcdir)/devtools/math2dox.in
	cd $(top_builddir) && $(SHELL) ./config.status --file=devtools/math2dox
else
# Without Python, just remove the {{{ ... }}} markers.
$(MATH2DOX_H) : % : $(top_srcdir)/include/%
	cat $< | $(SED) -e 's:{{{::g' -e 's:}}}::g' > $@

$(MATH2DOX_GEN_DOX) : %.gen.dox : $(top_srcdir)/doc/api/%.dox
	cat $< | $(SED) -e 's:{{{::g' -e 's:}}}::g' > $@
endif

# XXX currently, HTML and LaTeX documentation will always be built
# together.  HTML doesn't need any postprocessing, while latex is only
# a prerequisite for ps.
dox-html: demo $(USER_MANUAL)/index.html $(USER_MANUAL).tar.bz2

$(USER_MANUAL)/index.html: latex_src/refman.tex

dox-pdf: $(USER_MANUAL).pdf

$(USER_MANUAL).pdf: latex_src/refman.tex
	cd latex_src && ${MAKE} refman.pdf
	cp latex_src/refman.pdf $(USER_MANUAL).pdf

$(USER_MANUAL).tar.bz2: demo-examples $(USER_MANUAL)/index.html
	tar -cjf $(USER_MANUAL).tar.bz2 $(USER_MANUAL)

# Install rules for the various documentation parts.  The actual
# access to those rules is from the install-data-local target above,
# where the toplevel configure decides which of them will become a
# prerequisite of install-data-local.
install-dox-html: dox-html
	$(mkinstalldirs) $(DOC_INST_DIR)/$(USER_MANUAL)/search
	@list='$(wildcard $(USER_MANUAL)/*.html $(USER_MANUAL)/*.css \
	                  $(USER_MANUAL)/*.jpg \
	                  $(USER_MANUAL)/*.png \
	                  $(USER_MANUAL)/*.svg \
	                  $(USER_MANUAL)/*.js \
	                  $(USER_MANUAL)/search/*.js \
	                  $(USER_MANUAL)/search/*.css \
	                  $(USER_MANUAL)/search/*.svg)'; \
	for file in $$list ; do \
	  echo " $(INSTALL_DATA) $$file $(DOC_INST_DIR)/$$file"; \
	  $(INSTALL_DATA) $$file $(DOC_INST_DIR)/$$file; \
	done
	cd $(top_builddir)/doc/examples; make install-data-local

install-dox-pdf: dox-pdf
	$(mkinstalldirs) $(DOC_INST_DIR)
	$(INSTALL_DATA) $(USER_MANUAL).pdf $(DOC_INST_DIR)/$(USER_MANUAL).pdf

install-dox-man: dox-html
	$(mkinstalldirs) $(DESTDIR)$(mandir)/man3
	$(INSTALL_DATA) man/man3/*.3 $(DESTDIR)$(mandir)/man3

.PHONY: html latex pdf demo demo-examples \
	dox-html dox-pdf install-pdf install-html \
	install-dox-html install-dox-pdf \
	install-dox-man
