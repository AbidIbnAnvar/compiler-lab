%{
#include "y.tab.h"
%}

%%
[a-zA-Z]   { yylval.c = yytext[0]; return ID; }
"+"  { yylval.c = yytext[0]; return PLUS; }
"-"  { yylval.c = yytext[0]; return MINUS; }
"*"  { yylval.c = yytext[0]; return MUL; }
"/"  { yylval.c = yytext[0]; return DIV; }
[ \t\n]    ;
.          { return yytext[0]; }
%%

int yywrap(){
    return 1;
}