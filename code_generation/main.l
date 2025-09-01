%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "y.tab.h"
    #include "../tree/tree.h"
%}

DIGIT   [0-9]
LETTER [a-z]

%%


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
"repeat" {return REPEAT;}
"until" {return UNTIL;}
"decl" {return DECL;}
"enddecl" {return ENDDECL;}
"int" {return INT_TYPE;}
"str" {return STR_TYPE;}

{DIGIT}+ {
    yylval.node = createTree(atoi(yytext),"",TYPE_INT,NULL,NODETYPE_LEAF,NULL,NULL,NULL);
    return NUM;
}

{LETTER}+ {
    yylval.node = createTree(0,"",TYPE_NULL,strdup(yytext),NODETYPE_LEAF,NULL,NULL,NULL);
    return ID;
}

\"[^"\n]*\" {
    yylval.node = createTree(0,"",TYPE_STRING,strdup(yytext),NODETYPE_LEAF,NULL,NULL,NULL);
    return STR;
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