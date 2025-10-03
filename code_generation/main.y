%{
    #include<stdio.h>
    #include <stdlib.h>
    #include "code_generator.h"
    #include "../interpreter/interpreter.h"
    #include "../tree/tree.h"
    #include "../array/array.h"
    #include "../helper/helper.h"
    #include <string.h>

    extern int yylex();
    extern int yylineno;
    extern char *yytext; 
    void yyerror(char* s);
    struct tnode* head = NULL;
    FILE* yyin;
    Gsymbol *tableHead = NULL;
    // extern YYLTYPE yylloc;
%}

%union{
    struct tnode* node;
    struct Gsymbol* gsymbol;
    int var_type;
    struct dimNode* dim;
}


%token<node> NUM ID STR
%token PLUS MUL DIV MINUS MOD
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
%type <dim> Dimlist DimDecl
%type <var_type> Type


%nonassoc LE LT GT GE NE EQ
%left PLUS MINUS
%left MUL DIV MOD

%locations

%%

Program : Declarations Slist {
            head = $2;
            printTree(head);
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
            while(curr!=NULL && curr->next!=NULL){
                curr = curr->next;
            }
            curr->next = $2;
            $$ = $1;
        }
        | Decl {
            $$ = $1;
        }
        ;

Decl : Type VarList ';' {
            Gsymbol* curr = $2;
            while(curr!=NULL){
                // set type to all except ptr variables
                if(!curr->type || curr->type!=TYPE_PTR){
                    curr->type = $1;
                }else if(curr->type && curr->type!=TYPE_PTR){
                    curr->vartype = $1;
                }
                curr = curr->next;
            }
            $$ = $2;
        }
        ;

Type : INT_TYPE {
        $$ = TYPE_INT;
    } 
    | STR_TYPE {
        $$ = TYPE_STR;
    }
    ;

VarList : VarList ',' ID {
            // Get symbol table pointer for varlist
            Gsymbol* curr = $1;
            while(curr!=NULL&&curr->next!=NULL){
                curr = curr->next;
            }
            // Append entry to the end of the symbol table
            curr->next = createEntry($3->varname,$3->type,1,NULL,NULL);
            $$ = $1;
        } 
        | ID {
            $$ = createEntry($1->varname,$1->type,1,NULL,NULL);
        } 
        | VarList ',' ID DimDecl {
            Gsymbol* curr = $1;
            while(curr!=NULL&&curr->next!=NULL){
                curr = curr->next;
            }

            int size = getArraySize($4);
            curr->next = createEntry($3->varname,$3->type,size,$4,NULL);
            $$ = $1;
        }
        | ID DimDecl {
            int size = getArraySize($2);
            $$ = createEntry($1->varname,$1->type,size,$2,NULL);
        }
        | VarList ',' MUL ID {
            Gsymbol* curr = $1;
            while(curr!=NULL&&curr->next!=NULL){
                curr = curr->next;
            }
            curr->next = createEntry($4->varname,TYPE_PTR,1,NULL,NULL);
            $$ = $1;
        }
        | MUL ID {
            $$ = createEntry($2->varname,TYPE_PTR,1,NULL,NULL);
        }
        ;

Slist : Slist Stmt {
            $$ = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_CONNECTOR,$1,NULL,$2,NULL);
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
        | READ '(' ID Dimlist ')' ';'{
            // Fetch record containing the varname in the symbol table
            Gsymbol* g = Lookup($3->varname);
            $3->nodetype = NODETYPE_ARRAY;
            $3->dimNode = $4;
            $$ = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_READ,$3,NULL,NULL,NULL); 
        }
        ;

OutputStmt : WRITE '(' expr ')' ';' {
           $$ = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_WRITE,$3,NULL,NULL,NULL); 
        }
        ;

AsgStmt : ID '=' expr ';' {
            $$ = createTree(0,"=",TYPE_NULL,NULL,NODETYPE_OP_ASSIGNMENT,$1,NULL,$3,NULL);
        }
        | ID Dimlist '=' expr ';' {
            Gsymbol* g = Lookup($1->varname);
            $1->nodetype = NODETYPE_ARRAY;
            $1->dimNode = $2;
            $$ = createTree(0,"=",TYPE_NULL,NULL,NODETYPE_OP_ASSIGNMENT,$1,NULL,$4,NULL);
        }
        | MUL ID '=' expr ';' {
            tnode* left = createTree(0,"*",TYPE_NULL,NULL,NODETYPE_ACCESS,$2,NULL,NULL,NULL);
            $$ = createTree(0,"=",TYPE_NULL,NULL,NODETYPE_OP_ASSIGNMENT,left,NULL,$4,NULL);
        }
        ;

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
DimDecl: '[' NUM ']' DimDecl {
                $$ = addDimension($2->val,$2,$4);
            }
            | '[' NUM ']' {
                $$ = addDimension($2->val,$2,NULL);
            }
            ;

Dimlist : '[' expr ']' Dimlist {
            if($2->type == TYPE_STR){
                fprintf(stderr,"int type is required for indexing\n");
                exit(1);
            }
            $$ = addDimension($2->val,$2,$4);
        }   
        | '[' expr ']' {
            if($2->type == TYPE_STR){
                fprintf(stderr,"int type is required for indexing\n");
                exit(1);
            }
            $$ = addDimension($2->val,$2,NULL);
        }
        ;

expr:
    expr PLUS expr {
        int type = TYPE_INT;
        if($1->type==TYPE_STR||$3->type==TYPE_STR){
            type = TYPE_STR;
        }
        $$ = createTree(0,"+",type,NULL,NODETYPE_OP_ARITHMETIC,$1,NULL,$3,NULL);
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
    | expr MOD expr {
        $$ = createTree(0,"%",TYPE_INT,NULL,NODETYPE_OP_ARITHMETIC,$1,NULL,$3,NULL);
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
    | ID Dimlist {
        Gsymbol* g = Lookup($1->varname);
        $1->type = g->type;
        $1->nodetype = NODETYPE_ARRAY;
        $1->dimNode = $2;
        $$ = $1;
    }
    | MUL ID {
        Gsymbol* g = Lookup($2->varname);
        if(g->type!=TYPE_PTR){
            fprintf(stderr,"Trying to access non pointer values\n");
            exit(1);
        }
        $$ = createTree(0,"*",TYPE_NULL,NULL,NODETYPE_ACCESS,$2,NULL,NULL,NULL);
    }
    | '&' ID {
        $$ = createTree(0,"&",TYPE_NULL,NULL,NODETYPE_REF,$2,NULL,NULL,NULL);
    }
    | ID {
        Gsymbol* g = Lookup($1->varname);
        $1->type = g->type;
        $$ = $1;
    }
    | NUM {
        $$ = $1;
    }
    | STR {
        $$ = $1;
    }
    ;

%%

void yyerror(char *s) {
    fprintf(stderr,
        "Syntax error: %s at line %d near '%s'\n",
        s,
        yylloc.first_line,
        yytext
    );
}

void code_generate(){
    codegen_generate_header();
    stack_top = nextBinding-1;
    codegen_initialize_stack(stack_top);
    codegen(head,-1,-1);
    codegen_add_breakpoint();
    codegen_call_exit();
}

void free_memory(){
    freeTree(head);
    FreeGsymbolList(tableHead);
}

int main(){
    yyin = fopen("../input.txt", "r");
    yyparse();
    target_file = fopen("../target_file.xsm","w");
    code_generate();
    free_memory();
    return 0;
}