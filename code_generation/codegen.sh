#!/bin/bash

lex main.l
yacc -d main.y
# gcc -g -O0 -fsanitize=address lex.yy.c y.tab.c code_generator.c ../interpreter/interpreter.c ../tree/tree.c ../array/array.c ../helper/helper.c ../symbol_table/table.c ../label_translation/map.c -o program
gcc -g -O0 lex.yy.c y.tab.c code_generator.c ../interpreter/interpreter.c ../tree/tree.c ../array/array.c ../helper/helper.c ../symbol_table/table.c ../label_translation/map.c -o program
./program   