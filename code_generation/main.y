%{
    #include<stdio.h>
    #include <stdlib.h>
    #include "code_generator.c"
    #include "../interpreter/interpreter.c"
    #include "../tree/tree.h"
    #include "../helper/helper.c"
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
%token BEGIN_STMT END_STMT
%token READ WRITE
%token IF THEN ELSE ENDIF
%token WHILE DO ENDWHILE
%token LT LE GT GE NE EQ
%token BREAK CONTINUE
%token REPEAT UNTIL

%type <node> expr Slist InputStmt Stmt OutputStmt AsgStmt 
%type <node> IfStmt WhileStmt 
%type <node> BreakStmt ContinueStmt
%type <node> DoWhileStmt RepeatUntilStmt

%left PLUS MINUS
%left MUL DIV

%nonassoc LE LT GT GE NE EQ

%%

Program : BEGIN_STMT Slist END_STMT ';' {
            head = $2;
        }
        | BEGIN_STMT END_STMT ';' {
            head = NULL;
        }
        ;

Slist : Slist Stmt {
            tnode* node = createTree(0,"",TYPE_NULL,"",NODETYPE_CONNECTOR,$1,NULL,$2);
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
        | IfStmt {
            $$ = $1;
        }
        | WhileStmt {
            $$ = $1;
        }
        | BreakStmt {
            $$ = $1;
        }
        | ContinueStmt {
            $$ = $1;
        }
        | DoWhileStmt {
            $$ = $1;
        }
        | RepeatUntilStmt {
            $$ = $1;
        }
        ;

InputStmt : READ '(' ID ')' ';' {
           $$ = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_READ,$3,NULL,NULL); 
        }
        ;

OutputStmt : WRITE '(' expr ')' ';' {
           $$ = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_WRITE,$3,NULL,NULL); 
        }
        ;

AsgStmt : ID '=' expr ';' {
            tnode* node = createTree(0,"=",TYPE_NULL,"",NODETYPE_OP_ASSIGNMENT,$1,NULL,$3);
            $$ = node; 
        };

IfStmt : IF expr THEN Slist ELSE Slist ENDIF ';' {
            tnode* node = createTree(0,NULL,TYPE_NULL,"",NODETYPE_IF,$2,$4,$6);
            $$ = node; 
        }
        | IF expr THEN Slist ENDIF ';' {
            tnode* node = createTree(0,NULL,TYPE_NULL,"",NODETYPE_IF,$2,$4,NULL);
            $$ = node;
        }
        ;

WhileStmt : WHILE expr  DO Slist ENDWHILE ';' {
                tnode* node = createTree(0,NULL,TYPE_NULL,"",NODETYPE_WHILE,$2,NULL,$4);
                $$ = node;
            }
            ;

BreakStmt : BREAK ';' {
            tnode* node = createTree(0,NULL,TYPE_NULL,"",NODETYPE_BREAK,NULL,NULL,NULL);
            $$ = node;
        };

ContinueStmt : CONTINUE ';' {
            tnode* node = createTree(0,NULL,TYPE_NULL,"",NODETYPE_CONTINUE,NULL,NULL,NULL);
            $$ = node;
        };

DoWhileStmt : DO Slist WHILE expr ';' {
            tnode* node = createTree(0,NULL,TYPE_NULL,"",NODETYPE_DO_WHILE,$4,NULL,$2);
            $$ = node;
        }
        ;

RepeatUntilStmt : REPEAT Slist UNTIL expr ';' {
            tnode* node = createTree(0,NULL,TYPE_NULL,"",NODETYPE_REPEAT_UNTIL,$4,NULL,$2);
            $$ = node;
        };

expr:
    expr PLUS expr {
        tnode* node = createTree(0,"+",TYPE_INT,"",NODETYPE_OP_ARITHMETIC,$1,NULL,$3);
        $$ = node;
    }
    | expr MINUS expr {
        tnode* node = createTree(0,"-",TYPE_INT,"",NODETYPE_OP_ARITHMETIC,$1,NULL,$3);
        $$ = node;
    }
    | expr MUL expr {
        tnode* node = createTree(0,"*",TYPE_INT,"",NODETYPE_OP_ARITHMETIC,$1,NULL,$3);
        $$ = node;
    }
    | expr DIV expr {
        tnode* node = createTree(0,"/",TYPE_INT,"",NODETYPE_OP_ARITHMETIC,$1,NULL,$3);
        $$ = node;
    }
    | expr LT expr {
        tnode* node = createTree(0,"<",TYPE_INT,"",NODETYPE_OP_RELATIONAL,$1,NULL,$3);
        $$ = node;
    }
    | expr LE expr {
        tnode* node = createTree(0,"<=",TYPE_INT,"",NODETYPE_OP_RELATIONAL,$1,NULL,$3);
        $$ = node;
    }
    | expr GT expr {
        tnode* node = createTree(0,">",TYPE_INT,"",NODETYPE_OP_RELATIONAL,$1,NULL,$3);
        $$ = node;
    }
    | expr GE expr {
        tnode* node = createTree(0,">=",TYPE_INT,"",NODETYPE_OP_RELATIONAL,$1,NULL,$3);
        $$ = node;
    }
    | expr NE expr {
        tnode* node = createTree(0,"!=",TYPE_INT,"",NODETYPE_OP_RELATIONAL,$1,NULL,$3);
        $$ = node;
    }
    | expr EQ expr {
        tnode* node = createTree(0,"==",TYPE_INT,"",NODETYPE_OP_RELATIONAL,$1,NULL,$3);
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
    yyin = fopen("../input.txt", "r");
    yyparse();
    target_file = fopen("../target_file.xsm","w");
    generateHeader();
    initializeStack(4095+26);
    codeGen(head,-1,-1);
    addBreakpoint();
    callExit();
    /* evaluate_tree(head); */
    return 0;
}