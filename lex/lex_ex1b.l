%{
#include <stdio.h>
int integers = 0, floats = 0;
%}

DIGIT   [0-9]

%%
{DIGIT}+                         { integers++; }
{DIGIT}+"."{DIGIT}+              { floats++; }
.|\n                             ;
%%

int main() {
    yylex();
    printf("Integers: %d\nFloating point numbers: %d\n", integers, floats);
    return 0;
}

int yywrap() { return 1; }
