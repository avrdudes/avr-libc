#!/bin/sh

# Convert "atmega8" etc to the proper device spelling "ATmega8".
tr a-z A-Z \
    | sed -e s/XMEGA/xmega/ -e s/MEGA/mega/ -e s/TINY/tiny/ -e s/AUTO/auto/
