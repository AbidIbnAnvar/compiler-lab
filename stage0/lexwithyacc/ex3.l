%{
#include "y.tab.h"
#include <string.h>
%}

%%
[a-zA-Z]+   { yylval.c = strdup(yytext); return ID; }
"+"         { yylval.c = strdup(yytext); return PLUS; }
"-"         { yylval.c = strdup(yytext); return MINUS; }
"*"         { yylval.c = strdup(yytext); return MUL; }
"/"         { yylval.c = strdup(yytext); return DIV; }
[ \t\n]     ;
.           { return yytext[0]; }
%%

int yywrap(){
    return 1;
}