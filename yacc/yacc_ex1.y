%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int nesting = 0;
%}

%union {
    int num;
}

%token IF ENDIF
%type <num> program stmts stmt

%%

program : stmts { printf("Valid nested IF statements. Max nesting level: %d\n", $1); }
        ;
stmts  : stmt stmts   { $$ = ($1 > $2 ? $1 : $2); } 
       |    { $$ = 0; }
       ;
stmt: IF stmts ENDIF {$$ = $2+1;};
%%

int yylex(void){
    char word[100];
    if(scanf("%s",word)!=1)return 0;
    if(strcmp(word,"if")==0)return IF;
    if(strcmp(word,"endif")==0)return ENDIF;
    return 0;
}

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main() {
    yyparse();
    return 0;
}