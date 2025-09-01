#!/bin/bash

lex label.l
gcc lex.yy.c -o label
./label