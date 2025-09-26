#!/bin/bash

lex stage1.l
yacc -d stage1.y
gcc -g -O0 -fsanitize=address lex.yy.c y.tab.c -o sol
