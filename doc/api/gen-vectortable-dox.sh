#!/usr/bin/env sh

# Compiler can be set by CC=...

./mcus-to-isrs.sh ../../tmp-device-info | ./isrs-to-dox.py > vectortable.dox
