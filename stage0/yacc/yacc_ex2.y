%{
#include <stdio.h>
#include <ctype.h>
#include <string.h>
%}

%token VAR

%%
program : VAR { printf("Valid variable\n"); }
        ;
%%

int yylex(void) {
    char word[100];
    if (scanf("%s", word) != 1) return 0;
    if (isalpha(word[0])) {
        for (int i = 1; word[i]; i++) {
            if (!isalnum(word[i])) return 0;
        }
        return VAR;
    }
    return 0;
}

void yyerror(const char *s) {
    fprintf(stderr, "Invalid variable\n");
}

int main() {
    yyparse();
    return 0;
}
