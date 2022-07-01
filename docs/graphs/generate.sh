#!/bin/bash

rm -f *.png
dot -Tpng -oobjects.png objects.dot
dot -Tpng -ooverview.png overview.dot
