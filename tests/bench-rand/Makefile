# Test the performance of our random number generators (RNGs) using
# TestU01 suite from
#    https://simul.iro.umontreal.ca/testu01/tu01.html
# TestU01 has a git repo at
#    https://github.com/umontreal-simul/TestU01-2009
# though the build system has some issues, and to date it requires
# int to be a 32-bit type.

.PHONY: help test check_home clean

help:
	@echo "Run some random number generator (RNG) tests against RNGs"
	@echo "implemented in AVR-LibC now and then."
	@echo "See https://simul.iro.umontreal.ca/testu01/tu01.html"
	@echo "Run"
	@echo "   make test RNG=<rng> TESTU01_HOME=<dir>"
	@echo "where <rng> is one of random, rand, oldrand, 0, 1, 2."
	@echo "and <dir> is the install location of TESTU01."
	@echo ""

check_home:
	@if [ -z $(TESTU01_HOME) ] || [ ! -d $(TESTU01_HOME) ]; then \
		echo "error: TESTU01_HOME=$(TESTU01_HOME)" is not a directory;\
		exit 1; \
	fi

LIBS = -Wl,--start-group -ltestu01 -lmylib -lprobdist -Wl,--end-group -lm

testu01.x: $(TESTU01_HOME)/lib/libtestu01.a
testu01.x: $(TESTU01_HOME)/lib/libmylib.a
testu01.x: $(TESTU01_HOME)/lib/libprobdist.a
testu01.x: $(TESTU01_HOME)/include/unif01.h

testu01.x: testu01.c check_home
	gcc -std=c99 -Wall -O2 -c $< -o testu01.o -I$(TESTU01_HOME)/include
	gcc testu01.o -o $@ -static -L$(TESTU01_HOME)/lib $(LIBS)

test: testu01.x
	./testu01.x $(RNG)

clean:
	rm -f -- $(wildcard *.[isox])
