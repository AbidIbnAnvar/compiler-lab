%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "y.tab.h"
    #include "../tree/tree.h"
    extern int yylineno;
%}

%option yylineno

DIGIT   [0-9]
LETTER [a-zA-Z]

%%

"main" {return MAIN;}
"read" {return READ;}
"print" {return WRITE;}
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
"tuple" {return TUPLE_TYPE;}
"return" {return RETURN;}
"breakpoint" {return BRKP;}
"begin" {return BEGINSTMT;}
"end" {return ENDSTMT;}

"+" {return PLUS;}
"-" {return MINUS;}
"*" {return MUL;}
"/" {return DIV;}
"%" {return MOD;}

"<" {return LT;}
"<=" {return LE;}
">" {return GT;}
">=" {return GE;}
"!=" {return NE;}
"==" {return EQ;}
"||" {return OR;}
"&&" {return AND;}

{DIGIT}+ {
    yylval.node = createTree(atoi(yytext),"",createTypeTable(TYPE_INT,TYPE_NULL,1,NULL),NULL,NODETYPE_LEAF,NULL,NULL,NULL,NULL);
    return NUM;
}

{LETTER}({LETTER}|{DIGIT}|"_")* {
    yylval.node = createTree(0,NULL,createTypeTable(TYPE_NULL,TYPE_NULL,1,NULL),strdup(yytext),NODETYPE_LEAF,NULL,NULL,NULL,NULL);
    return ID;
}

\"[^"\n]*\" {
    yylval.node = createTree(0,NULL,createTypeTable(TYPE_NULL,TYPE_NULL,1,NULL),NULL,NODETYPE_LEAF,NULL,NULL,NULL,NULL);
    yylval.node->strval = strdup(yytext);
    return STR;
}

"(" {return '(';}
")" {return ')';}
";" {return ';';}
"=" {return '=';}
"," {return ',';}
"[" {return '[';}
"]" {return ']';}
"&" {return '&';}
"." {return '.';}


"{" {return '{';}
"}" {return '}';}

[ \t]+
\n          { yylloc.last_line++; yylloc.first_line++; }

%%

int yywrap(){
    return 1;
}