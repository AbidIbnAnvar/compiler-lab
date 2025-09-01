#!/bin/bash

lex label.l
gcc lex.yy.c map.c -o label
./label