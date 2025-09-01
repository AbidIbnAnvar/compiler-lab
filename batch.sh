#!/bin/bash

(cd code_generation && ./codegen.sh)
(cd label_translation && ./label.sh)