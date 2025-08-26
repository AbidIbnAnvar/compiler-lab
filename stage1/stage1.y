%{
    #include<stdio.h>
    #include <stdlib.h>
    #include "stage1.h"

    extern int yylex();
    void yyerror(char* s);
    struct tnode* head = NULL;
    FILE* yyin;
%}

%union{
    struct tnode* node;
}


%token<node> NUM 
%token PLUS NL MUL DIV MINUS
%type <node> expr

%left PLUS MINUS
%left MUL DIV

%%

Program : expr NL {
    head = $1;
}

expr:
     PLUS expr expr {
        tnode* op = makeOperatorNode("+",$2,$3);
        $$ = op;
    }
    | MINUS expr expr {
        tnode* op = makeOperatorNode("-",$2,$3);
        $$ = op;
    }
    | MUL expr expr {
        tnode* op = makeOperatorNode("*",$2,$3);
        $$ = op;
    }
    | DIV expr expr {
        tnode* op = makeOperatorNode("/",$2,$3);
        $$ = op;
    }
    | '(' expr ')' {
        $$ = $2;
    }
    | NUM {
        $$ = $1;
    }
    ;

%%

void yyerror(char* s){
    printf("%s\n", s);
}

void postfixprint(tnode* t){
    if(!t->left && !t->right){
        printf("%d ", t->val);
        return;
    }
    postfixprint(t->left);
    postfixprint(t->right);
    printf("%s ", t->op);
    return;
}

void prefixprint(tnode* t){
    if(!t->left && !t->right){
        printf("%d ", t->val);
        return;
    }
    printf("%s ", t->op);
    prefixprint(t->left);
    prefixprint(t->right);
    return;
}

int main(){
    yyin = fopen("a.txt", "r");
    target_file = fopen("target_file.xsm","w");
    generateHeader();
    initializeStack(4096);
    yyparse();
    codeGen(head);
    storeInStack(current_register,4096);
    printAddress(4096);
    callExit();
    /* postfixprint(head);
    printf("\n");
    prefixprint(head);
    printf("\n"); */
    return 0;
}