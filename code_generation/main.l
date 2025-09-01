%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "y.tab.h"
    #include "../tree/tree.c"
%}

DIGIT   [0-9]
LETTER [a-z]

%%

{DIGIT}+ {
    yylval.node = createTree(atoi(yytext),"",TYPE_INT,NULL,NODETYPE_LEAF,NULL,NULL,NULL);
    return NUM;
}

"begin" {return BEGIN_STMT;}
"end" {return END_STMT;}
"read" {return READ;}
"write" {return WRITE;}
"if" {return IF;}
"then" {return THEN;}
"else" {return ELSE;}
"endif" {return ENDIF;}
"while" {return WHILE;}
"do" {return DO;}
"endwhile" {return ENDWHILE;}
"break" {return BREAK;}
"continue" {return CONTINUE;}

{LETTER}+ {
    yylval.node = createTree(0,"",TYPE_INT,strdup(yytext),NODETYPE_LEAF,NULL,NULL,NULL);
    return ID;
}

"+" {return PLUS;}
"-" {return MINUS;}
"*" {return MUL;}
"/" {return DIV;}

"<" {return LT;}
"<=" {return LE;}
">" {return GT;}
">=" {return GE;}
"!=" {return NE;}
"==" {return EQ;}

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