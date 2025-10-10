#!/bin/bash

if [[ "$1" == "-d" ]]; then
    (cd code_generation && ./codegen.sh -d)
else
    (cd code_generation && ./codegen.sh)
fi
(cd label_translation && ./label.sh)