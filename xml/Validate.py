#! /usr/bin/env python
#
# Simple script for validating xml files.
#
# Usage: ./Validate.py foo.xml
#

import os
import sys

from xml.parsers.xmlproc import xmlval
from xml.parsers.xmlproc.utils import validate_doc, ErrorPrinter

parser = xmlval.XMLValidator()
parser.set_error_handler(ErrorPrinter(parser, out=sys.stdout))
parser.parse_resource(sys.argv[1])
