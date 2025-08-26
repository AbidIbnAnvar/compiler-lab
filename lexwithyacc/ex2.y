%{
#include <stdio.h>
#include <stdlib.h>
%}

%union {
    char *c;  
}

%token <c> ID
%token <c> PLUS MINUS MUL DIV
%type  <c> expr
%left PLUS MINUS
%left MUL DIV

%%

input : expr { printf("\n"); }
      ;

expr  : expr PLUS expr   { printf("%s ", $2);}
      | expr MINUS expr   { printf("%s ", $2);}
      | expr MUL expr   { printf("%s ", $2);}
      | expr DIV expr   { printf("%s ", $2);}
      | '(' expr ')'   { }
      | ID             { printf("%s ", $1);  }
      ;

%%

void yyerror(const char *s) {
    fprintf(stderr,"Error: %s\n",s);
}

int main() {
    yyparse();
    return 0;
}
