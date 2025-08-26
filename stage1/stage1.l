%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "y.tab.h"
    #include "stage1.c"
%}

DIGIT   [0-9]

%%

{DIGIT}+ {
    yylval.node = makeLeafNode(atoi(yytext));
    return NUM;
    }

"+" {return PLUS;}
"-" {return MINUS;}
"*" {return MUL;}
"/" {return DIV;}

[()] {return yytext[0];}

"\n" {return NL;}
[ \t] {}

. {}

%%

int yywrap(){
    return 1;
}