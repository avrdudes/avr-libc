#!/bin/sh

# Convert "atmega8" etc to the proper device spelling "ATmega8".
tr abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ \
    | sed -e s/XMEGA/xmega/ -e s/MEGA/mega/ -e s/TINY/tiny/ -e s/AUTO/auto/
