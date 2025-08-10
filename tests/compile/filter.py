#!/usr/bin/env python

from __future__ import print_function

import sys, re

mcus = sys.argv[1].split()
globs = sys.argv[2].split()

# * = Zero or more letters or digits that may occur in -mmcu.
# . = Exactly one such character.
# ! = Exclude the pattern instead of including it.
# Example:  "atmega8* !atmega8*a"
def to_regex (s):
    want = not s.startswith ("!")
    r = s .replace("*", "[a-z0-9]*") .replace (".", "[a-z0-9]")
    # re.fullmatch is only added in Python v3.4, hence do it by hand.
    return (want, re.compile (r"\b" + (r if want else r[1:]) + r"\b"))

globs = tuple ( to_regex(s) for s in globs )

def flt (mcu):
    ok = False
    for (want, g) in globs:
        if g.match (mcu):
            ok = want
    return ok

print (" ".join (filter (flt, mcus)))
