#! /usr/bin/env python
#
# Simple script for validating xml files.
#
# Usage: ./Validate.py foo.xml bar.xml ...
#

import os
import sys
import glob

from xml.parsers.xmlproc import xmlval
from xml.parsers.xmlproc.utils import ErrorPrinter

for arg in sys.argv[1:]:
    for filename in glob.glob (arg):
        print 'Validating %s' % (arg)

        parser = xmlval.XMLValidator()
        parser.set_error_handler(ErrorPrinter(parser, out=sys.stdout))

        parser.parse_resource (arg)
