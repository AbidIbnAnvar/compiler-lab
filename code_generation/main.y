%{
    #include<stdio.h>
    #include <stdlib.h>
    #include "code_generator.h"
    #include "../interpreter/interpreter.h"
    #include "../tree/tree.h"
    #include "../helper/helper.h"
    #include <string.h>

    extern int yylex();
    void yyerror(char* s);
    struct tnode* head = NULL;
    FILE* yyin;
    Gsymbol *tableHead = NULL;
%}

%union{
    struct tnode* node;
    struct Gsymbol* gsymbol;
    int var_type;
}


%token<node> NUM ID STR
%token PLUS MUL DIV MINUS
%token READ WRITE
%token IF THEN ELSE ENDIF
%token WHILE DO ENDWHILE
%token LT LE GT GE NE EQ
%token BREAK CONTINUE
%token REPEAT UNTIL
%token DECL ENDDECL
%token INT_TYPE STR_TYPE

%type <node> expr Slist InputStmt Stmt OutputStmt AsgStmt 
%type <node> IfStmt WhileStmt 
%type <node> BreakStmt ContinueStmt
%type <node> DoWhileStmt RepeatUntilStmt
%type <gsymbol> DeclList Decl VarList
%type <var_type> Type

%left PLUS MINUS
%left MUL DIV

%nonassoc LE LT GT GE NE EQ

%%

Program : Declarations Slist {
            head = $2;
        }
        ;

Declarations :  DECL DeclList ENDDECL {
                tableHead = $2;
                ShowTable(tableHead);
            }
            | DECL ENDDECL {
                tableHead = NULL;
            }
            ;

DeclList : DeclList Decl {
            Gsymbol* curr = $1;
            Gsymbol* next = $2;
            while(curr!=NULL && curr->next!=NULL){
                curr = curr->next;
            }
            curr->next = next;
            $$ = $1;
        }
        | Decl {
            $$ = $1;
        }
        ;

Decl : Type VarList ';' {
            int type = $1;
            Gsymbol* curr = $2;
            while(curr!=NULL){
                curr->type = type;
                curr = curr->next;
            }
            $$ = $2;
        }
        ;

Type : INT_TYPE {
        $$ = TYPE_INT;
    } 
    | STR_TYPE {
        $$ = TYPE_STRING;
    }
    ;

VarList : VarList ',' ID {
            Gsymbol* curr = $1;
            while(curr!=NULL&&curr->next!=NULL){
                curr = curr->next;
            }
            curr->next = createEntry($3->varname,$3->type,1,NULL);
            $$ = $1;
        } | ID {
            $$ = createEntry($1->varname,$1->type,1,NULL);
        }
        ;

Slist : Slist Stmt {
            $$ = createTree(0,"",TYPE_NULL,NULL,NODETYPE_CONNECTOR,$1,NULL,$2,NULL);
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
           $$ = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_READ,$3,NULL,NULL,NULL); 
        }
        ;

OutputStmt : WRITE '(' expr ')' ';' {
           $$ = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_WRITE,$3,NULL,NULL,NULL); 
        }
        ;

AsgStmt : ID '=' expr ';' {
            $$ = createTree(0,"=",TYPE_NULL,NULL,NODETYPE_OP_ASSIGNMENT,$1,NULL,$3,NULL);
        };

IfStmt : IF expr THEN Slist ELSE Slist ENDIF ';' {
            $$ = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_IF,$2,$4,$6,NULL); 
        }
        | IF expr THEN Slist ENDIF ';' { 
            $$ = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_IF,$2,$4,NULL,NULL);
        }
        ;

WhileStmt : WHILE expr  DO Slist ENDWHILE ';' {
                $$ = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_WHILE,$2,NULL,$4,NULL);
            }
            ;

BreakStmt : BREAK ';' {
            $$ = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_BREAK,NULL,NULL,NULL,NULL);
        };

ContinueStmt : CONTINUE ';' {
            $$ = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_CONTINUE,NULL,NULL,NULL,NULL);
        };

DoWhileStmt : DO Slist WHILE expr ';' {
            $$ = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_DO_WHILE,$4,NULL,$2,NULL);
        }
        ;

RepeatUntilStmt : REPEAT Slist UNTIL expr ';' {
            $$ = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_REPEAT_UNTIL,$4,NULL,$2,NULL);
        };

expr:
    expr PLUS expr {
        $$ = createTree(0,"+",TYPE_INT,NULL,NODETYPE_OP_ARITHMETIC,$1,NULL,$3,NULL);
    }
    | expr MINUS expr {
        $$ = createTree(0,"-",TYPE_INT,NULL,NODETYPE_OP_ARITHMETIC,$1,NULL,$3,NULL);
    }
    | expr MUL expr {
        $$ = createTree(0,"*",TYPE_INT,NULL,NODETYPE_OP_ARITHMETIC,$1,NULL,$3,NULL);
    }
    | expr DIV expr {
        $$ = createTree(0,"/",TYPE_INT,NULL,NODETYPE_OP_ARITHMETIC,$1,NULL,$3,NULL);
    }
    | expr LT expr {
        $$ = createTree(0,"<",TYPE_INT,NULL,NODETYPE_OP_RELATIONAL,$1,NULL,$3,NULL);
    }
    | expr LE expr {
        $$ = createTree(0,"<=",TYPE_INT,NULL,NODETYPE_OP_RELATIONAL,$1,NULL,$3,NULL);
    }
    | expr GT expr {
        $$ = createTree(0,">",TYPE_INT,NULL,NODETYPE_OP_RELATIONAL,$1,NULL,$3,NULL);
    }
    | expr GE expr {
        $$ = createTree(0,">=",TYPE_INT,NULL,NODETYPE_OP_RELATIONAL,$1,NULL,$3,NULL);
    }
    | expr NE expr {
        $$ = createTree(0,"!=",TYPE_INT,NULL,NODETYPE_OP_RELATIONAL,$1,NULL,$3,NULL);
    }
    | expr EQ expr {
        $$ = createTree(0,"==",TYPE_INT,NULL,NODETYPE_OP_RELATIONAL,$1,NULL,$3,NULL);
    }
    | '(' expr ')' {
        $$ = $2;
    }
    | NUM {
        $$ = $1;
    }
    | STR {
        $$ = $1;
    }| ID {
        tnode* node = $1;
        Gsymbol* g = Lookup(node->varname);
        if(g==NULL){
            printf("Error: Variable not declared\n");
            exit(1);
        }
        node->type = g->type;
        $$ = node;
    }
    ;

%%

void yyerror(char* s){
    printf("%s\n", s);
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
    freeTree(head);
    FreeGsymbolList(tableHead);
    return 0;
}