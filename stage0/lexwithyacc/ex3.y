%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
%}

%union {
    char* c;
}

%token <c> PLUS MINUS MUL DIV ID
%type  <c> expr
%left PLUS MINUS
%left MUL DIV

%%

input : expr { printf("%s\n", $1); }
      ;

expr  : expr PLUS expr   { int len = strlen($1) + strlen($3) + 4;
                          char *buf = malloc(len);
                          sprintf(buf, "+ %s %s", $1, $3);
                          $$ = buf; }
    | expr MINUS expr  { int len = strlen($1) + strlen($3) + 4;
                          char *buf = malloc(len);
                          sprintf(buf, "- %s %s", $1, $3);
                          $$ = buf; }
    | expr MUL expr    { int len = strlen($1) + strlen($3) + 4;
                          char *buf = malloc(len);
                          sprintf(buf, "* %s %s", $1, $3);
                          $$ = buf; }
    | expr DIV expr    { int len = strlen($1) + strlen($3) + 4;
                          char *buf = malloc(len);
                          sprintf(buf, "/ %s %s", $1, $3);
                          $$ = buf; }
      | '(' expr ')'   { $$=$2; }
      | ID             { $$=$1; }
      ;

%%

void yyerror(const char *s) {
    fprintf(stderr,"Error: %s\n",s);
}

int main() {
    yyparse();
    return 0;
}
