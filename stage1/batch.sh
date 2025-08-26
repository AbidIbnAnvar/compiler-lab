#!/bin/bash

lex stage1.l
yacc -d stage1.y
gcc lex.yy.c y.tab.c -o sol
