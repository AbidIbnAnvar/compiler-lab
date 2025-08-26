%{
#include <stdio.h>
#include <stdlib.h>
%}

%union {
    char c;
}

%token <c> ID
%token <c> PLUS MINUS MUL DIV
%type  <c> expr
%left PLUS MINUS
%left MUL DIV

%%

input : expr { printf("\n"); }
      ;

expr  : expr PLUS expr   { printf("%c", $2);  }
      | expr MINUS expr   { printf("%c", $2);  }
      | expr MUL expr   { printf("%c", $2);  }
      | expr DIV expr   { printf("%c", $2);  }
      | '(' expr ')'   { }
      | ID             { printf("%c", $1);}
      ;

%%

void yyerror(const char *s) {
    fprintf(stderr,"Error: %s\n",s);
}

int main() {
    yyparse();
    return 0;
}
