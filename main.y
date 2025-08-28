%{
    #include<stdio.h>
    #include <stdlib.h>
    // #include "code_generator.c"
    #include "interpreter.c"
    #include "tree.h"
    #include "helper.c"
    #include <string.h>

    extern int yylex();
    void yyerror(char* s);
    struct tnode* head = NULL;
    FILE* yyin;
%}

%union{
    struct tnode* node;
}


%token<node> NUM ID
%token PLUS MUL DIV MINUS
%token BEG END
%token READ WRITE

%type <node> expr Slist InputStmt Stmt OutputStmt AsgStmt

%left PLUS MINUS
%left MUL DIV

%%

Program : BEG Slist END ';' {
            head = $2;
        }
        | BEG END ';' {
            head = NULL;
        }
        ;

Slist : Slist Stmt {
            tnode* node = createTree(0,"",TYPE_NULL,"",NODETYPE_CONNECTOR,$1,$2);
            $$ = node;
        }
        | Stmt { $$ = $1; }
        ;

Stmt : InputStmt {
            $$ = $1;
        }
        | OutputStmt {
            $$ = $1;
        }
        | AsgStmt {
            $$ = $1;
        }
        ;

InputStmt : READ '(' ID ')' ';' {
           $$ = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_READ,$3,NULL); 
        }
        ;

OutputStmt : WRITE '(' expr ')' ';' {
           $$ = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_WRITE,$3,NULL); 
        }
        ;

AsgStmt : ID '=' expr ';' {
            tnode* node = createTree(0,"=",TYPE_NULL,"",NODETYPE_ASSIGNMENT,$1,$3);
            $$ = node; 
        };

expr:
    expr PLUS expr {
        tnode* node = createTree(0,"+",TYPE_NULL,"",NODETYPE_OPERATOR,$1,$3);
        $$ = node;
    }
    | expr MINUS expr {
        tnode* node = createTree(0,"-",TYPE_NULL,"",NODETYPE_OPERATOR,$1,$3);
        $$ = node;
    }
    | expr MUL expr {
        tnode* node = createTree(0,"*",TYPE_NULL,"",NODETYPE_OPERATOR,$1,$3);
        $$ = node;
    }
    | expr DIV expr {
        tnode* node = createTree(0,"/",TYPE_NULL,"",NODETYPE_OPERATOR,$1,$3);
        $$ = node;
    }
    | '(' expr ')' {
        $$ = $2;
    }
    | NUM {
        $$ = $1;
    }
    | ID {
        $$ = $1;
    }
    ;

%%

void yyerror(char* s){
    printf("%s\n", s);
}

void prefixprint(tnode* t){
    if(t==NULL){return;}
    if(!t->left && !t->right){
        if(t->varname) printf("%s ", t->varname);
        else printf("%d ", t->val); 
        return;
    }   
    prefixprint(t->left);
    if(t->op && strlen(t->op)>0){
        printf("%s ", t->op);
    }else{
        printf("__ ");
    }
    prefixprint(t->right);
    return;
}

int main(){
    yyin = fopen("input.txt", "r");
    yyparse();
    prefixprint(head);
    printf("\n");
    /* target_file = fopen("target_file.xsm","w");
    generateHeader();
    initializeStack(4095+26);
    codeGen(head);
    callExit(); */
    evaluate_tree(head);
    return 0;
}