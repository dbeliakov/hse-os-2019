#!/usr/bin/python

import os

for k in os.environ:
    print k, "=", os.environ[k]
