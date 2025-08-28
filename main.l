%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "y.tab.h"
    #include "tree.c"
%}

DIGIT   [0-9]
LETTER [a-z]

%%

{DIGIT}+ {
    yylval.node = createTree(atoi(yytext),"",TYPE_INT,NULL,NODETYPE_LEAF,NULL,NULL);
    return NUM;
}
"begin" {return BEG;}
"end" {return END;}
"read" {return READ;}
"write" {return WRITE;}
{LETTER}+ {
    yylval.node = createTree(0,"",TYPE_INT,strdup(yytext),NODETYPE_LEAF,NULL,NULL);
    return ID;
}
"+" {return PLUS;}
"-" {return MINUS;}
"*" {return MUL;}
"/" {return DIV;}
"(" {return '(';}
")" {return ')';}
";" {return ';';}
"=" {return '=';}
[ \t\n] {}
. {}

%%

int yywrap(){
    return 1;
}