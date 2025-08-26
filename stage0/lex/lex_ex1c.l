%{
#include <stdio.h>
%}

%%
"A"[a-zA-Z]{2}       { printf("%s\n", yytext); }
.|\n                 ;
%%

int main() {
    yylex();
    return 0;
}

int yywrap() { return 1; }
