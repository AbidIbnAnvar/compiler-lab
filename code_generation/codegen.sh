#!/bin/bash

lex main.l
yacc -d main.y

gcc_flags="-g -O0"
gcc_files="lex.yy.c y.tab.c code_generator.c ../interpreter/interpreter.c ../tree/tree.c ../array/array.c ../helper/helper.c ../symbol_table/table.c ../label_translation/map.c"
gcc_output="-o program"

if [[ "$1" == "-d" ]]; then
    gcc_flags="$gcc_flags -fsanitize=address"
fi

gcc $gcc_flags $gcc_files $gcc_output

./program
