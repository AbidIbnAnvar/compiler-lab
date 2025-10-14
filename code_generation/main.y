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
%}

%union{
    struct tnode* node;
    struct SymbolTable* symbolTable;
    int var_type;
    struct dimNode* dim;
    struct paramList* params;
    struct argList* args;
}


%token<node> NUM ID STR
%token PLUS MUL DIV MINUS MOD
%token READ WRITE
%token IF THEN ELSE ENDIF
%token WHILE DO ENDWHILE
%token LT LE GT GE NE EQ OR AND
%token BREAK CONTINUE
%token REPEAT UNTIL
%token DECL ENDDECL
%token INT_TYPE STR_TYPE
%token MAIN
%token RETURN
%token BRKP
%token BEGINSTMT ENDSTMT

%type <node> expr Slist InputStmt Stmt OutputStmt AsgStmt FunctionCallStmt ReturnStmt BreakPointStmt
%type <node> IfStmt WhileStmt 
%type <node> BreakStmt ContinueStmt
%type <node> DoWhileStmt RepeatUntilStmt
%type <node> FDefBlock MainBlock FDef
%type <symbolTable> VarList
%type <symbolTable> GDeclList GDecl GidList Gid LDecList LDecl
%type <dim> Dimlist DimDecl
%type <var_type> Type
%type <params> ParamList Param
%type <args> ArgList

%left OR
%left AND
%nonassoc LE LT GT GE NE EQ
%left PLUS MINUS
%left MUL DIV MOD

%locations

%%

 Program : GDeclBlock FDefBlock MainBlock{
            head = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_CONNECTOR,$2,NULL,$3,NULL);
        }
        | GDeclBlock MainBlock{
            head = $2;
        }
        | MainBlock{
            head = $1;
        }
        ;
GDeclBlock: DECL GDeclList ENDDECL {
                pushToScopeStack($2,&sstop);
                showTable($2);
            }
            | DECL ENDDECL{
                pushToScopeStack(NULL,&sstop);
                showTable(sstop->symbolTable);
            };

GDeclList: GDeclList GDecl {
            SymbolTable* curr = $1;
            while(curr && curr->next){
                curr = curr->next;
            }
            curr->next = $2;
            $$ = $1;
        } 
        | GDecl {
            $$ = $1;
        };

GDecl: Type GidList ';'{
        SymbolTable* curr = $2;
        while(curr){
            // set type to all except ptr variables
            if(!curr->type || curr->type!=TYPE_PTR){
                curr->type = $1;
            }else if(curr->type && curr->type==TYPE_PTR){
                curr->vartype = $1;
            }
            curr = curr->next;
        }
        $$ = $2;
    };  

GidList: GidList ',' Gid {
            SymbolTable* curr = $1;
            while(curr!=NULL&&curr->next!=NULL){
                curr = curr->next;
            }
            // Append id to the end of the symbol table
            curr->next = $3;
            $$ = $1;
        }
        | Gid {
            $$ = $1;
        }
        ;

Gid: ID {
        $$ = createEntry($1->varname,$1->type,1,-1,GLOBAL,NULL,NULL,NULL);
    }
    | ID DimDecl {
        int size = getArraySize($2);
        $$ = createEntry($1->varname,$1->type,size,-1,GLOBAL,$2,NULL,NULL);
    }
    | MUL ID {
        $$ = createEntry($2->varname,TYPE_PTR,1,-1,GLOBAL,NULL,NULL,NULL);
    }
    | ID '('ParamList')' {
        $$ = createEntry($1->varname,$1->type,1,currentFLabel++,GLOBAL,NULL,$3,NULL);
    }
    | MUL ID '('ParamList')' {
        $$ = createEntry($2->varname,$2->type,1,currentFLabel++,GLOBAL,NULL,$4,NULL);
    }
    ;

MainBlock: INT_TYPE MAIN '(' ')' {
            nextBinding = 1;
            printf("main()\n");
            pushToScopeStack(NULL,&sstop);
        } '{' LDeclBlock BEGINSTMT Slist ReturnStmt ENDSTMT '}' {
            $$ = createTree(0,NULL,TYPE_INT,"main",NODETYPE_MAIN,$9,NULL,$10,NULL);
            $$->Lentry = sstop->symbolTable;
            popFromScopeStack(&sstop);
        } 
        ;

FDefBlock: FDefBlock FDef {
            // TODO: Check if the declared function and defined function types and parameters are same
            $$ = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_CONNECTOR,$1,NULL,$2,NULL);
        }
        | FDef {
            // TODO: Check if the declared function and defined function types and parameters are same
            $$ = $1;
        } 
        ;

FDef: Type ID '(' ParamList ')' {
            printf("%s()\n",$2->varname);
            SymbolTable* st = lookupEntry($2->varname,sstop);
            // printParamList($4);
            checkparams(st->paramList,$4,$2->varname);
            nextBinding = -3;
            SymbolTable* params = convertParamListToSymbolTable($4);
            pushToScopeStack(params,&sstop);
            nextBinding = 1;
    }
     '{' LDeclBlock BEGINSTMT Slist ReturnStmt ENDSTMT '}' {
        $$ = createTree(0,NULL,TYPE_NULL,$2->varname,NODETYPE_FUNC,$10,NULL,$11,NULL);
        $$->Lentry = sstop->symbolTable;
        popFromScopeStack(&sstop);
    }
    | Type MUL ID '(' ParamList ')' {
            printf("%s()\n",$3->varname);
            SymbolTable* st = lookupEntry($3->varname,sstop);
            checkparams(st->paramList,$5,$3->varname);
            nextBinding = -3;
            SymbolTable* params = convertParamListToSymbolTable($5);
            pushToScopeStack(params,&sstop);
            nextBinding = 1;
    }
     '{' LDeclBlock BEGINSTMT Slist ReturnStmt ENDSTMT '}' {
        $$ = createTree(0,NULL,TYPE_NULL,$3->varname,NODETYPE_FUNC,$11,NULL,$12,NULL);
        $$->Lentry = sstop->symbolTable;
        popFromScopeStack(&sstop);
    }
    ;

ParamList: ParamList ',' Param {
            paramList* curr = $1;
            while(curr->next){
                curr = curr->next;
            }   
            curr->next = $3;
            $$ = $1;
        } 
        | Param {
            $$ = $1;
        } 
        | { 
            $$ = NULL;
        }
        ;

Param: Type ID {
        $$ = createParamList($1,TYPE_NULL,$2->varname);
    }
    | Type MUL ID {
        $$ = createParamList(TYPE_PTR,$1,$3->varname);
    }
    ;

Type : INT_TYPE {
        $$ = TYPE_INT;
    } 
    | STR_TYPE {
        $$ = TYPE_STR;
    }
    ;

LDeclBlock: DECL LDecList ENDDECL {
            if(!sstop->symbolTable){
                sstop->symbolTable = $2;
            }else{
                SymbolTable* curr = sstop->symbolTable;
                while(curr->next){
                    curr = curr->next;
                }
                curr->next = $2;
            }
            showTable(sstop->symbolTable);
        } 
        | DECL ENDDECL {
            // showTable(sstop->symbolTable);
        }
        | {
            // showTable(sstop->symbolTable);
        }
        ;

LDecList: LDecList LDecl {
            SymbolTable* curr = $1;
            while(curr && curr->next){
                curr = curr->next;
            }
            curr->next = $2;
            $$ = $1;
        }
        | LDecl {
            $$ = $1;
        }
        ;

LDecl: Type VarList ';' {
        SymbolTable* curr = $2;
        while(curr){
            // set type to all except ptr variables
            if(!curr->type || curr->type!=TYPE_PTR){
                curr->type = $1;
            }else if(curr->type && curr->type==TYPE_PTR){
                curr->vartype = $1;
            }
            curr = curr->next;
        }
        $$ = $2;    
    }
    ;

VarList : VarList ',' ID {
            // Get symbol table pointer for varlist
            SymbolTable* curr = $1;
            while(curr->next){
                curr = curr->next;
            }
            // Append entry to the end of the symbol table
            curr->next = createEntry($3->varname,$3->type,1,-1,LOCAL,NULL,NULL,NULL);
            $$ = $1;
        } 
        | ID {
            $$ = createEntry($1->varname,$1->type,1,-1,LOCAL,NULL,NULL,NULL);
        } 
        | VarList ',' ID DimDecl {
            SymbolTable* curr = $1;
            while(curr->next){
                curr = curr->next;
            }

            int size = getArraySize($4);
            curr->next = createEntry($3->varname,$3->type,size,-1,LOCAL,$4,NULL,NULL);
            $$ = $1;
        }
        | ID DimDecl {
            int size = getArraySize($2);
            $$ = createEntry($1->varname,$1->type,size,-1,LOCAL,$2,NULL,NULL);
        }
        | VarList ',' MUL ID {
            SymbolTable* curr = $1;
            while(curr->next){
                curr = curr->next;
            }
            curr->next = createEntry($4->varname,TYPE_PTR,1,-1,GLOBAL,NULL,NULL,NULL);
            $$ = $1;
        }
        | MUL ID {
            $$ = createEntry($2->varname,TYPE_PTR,1,-1,GLOBAL,NULL,NULL,NULL);
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
        | FunctionCallStmt {
            $$ = $1;
        }
        | BreakPointStmt {
            $$ = $1;
        }
        ;

InputStmt : READ '(' ID ')' ';' {
            $3->STentry = lookupEntry($3->varname,sstop);
            $$ = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_READ,$3,NULL,NULL,NULL); 
        }
        | READ '(' ID Dimlist ')' ';'{
            // Fetch record containing the varname in the symbol table
            $3->STentry = lookupEntry($3->varname,sstop);
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
            SymbolTable* st = lookupEntry($1->varname,sstop);
            $1->STentry = st;
            $$ = createTree(0,"=",st->type,NULL,NODETYPE_OP_ASSIGNMENT,$1,NULL,$3,NULL);
        }
        | ID Dimlist '=' expr ';' {
            SymbolTable* st = lookupEntry($1->varname,sstop);
            $1->STentry = st;
            $1->type = st->type;
            $1->nodetype = NODETYPE_ARRAY;
            $1->dimNode = $2;
            $$ = createTree(0,"=",TYPE_NULL,NULL,NODETYPE_OP_ASSIGNMENT,$1,NULL,$4,NULL);
        }
        | MUL ID '=' expr ';' {
            SymbolTable* st = lookupEntry($2->varname,sstop);
            $2->STentry = st;
            tnode* left = createTree(0,"*",st->type,NULL,NODETYPE_ACCESS,$2,NULL,NULL,NULL);
            $$ = createTree(0,"=",st->type,NULL,NODETYPE_OP_ASSIGNMENT,left,NULL,$4,NULL);
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
FunctionCallStmt: ID '(' ArgList ')' ';' {
                    SymbolTable* st = lookupEntry($1->varname,sstop);
                    checkargs($3,st->paramList,$1->varname);
                    $1->STentry = st;
                    $$ = createTree(0,NULL,st->type,$1->varname,NODETYPE_FUNC_CALL,NULL,NULL,NULL,NULL);
                    $$->argList = $3;
                }
                | ID '('')'';' {
                    SymbolTable* st = lookupEntry($1->varname,sstop);
                    checkargs(NULL,st->paramList,$1->varname);
                    $1->STentry = st;
                    $$ = createTree(0,NULL,st->type,$1->varname,NODETYPE_FUNC_CALL,NULL,NULL,NULL,NULL);
                }
                ;
ReturnStmt: RETURN expr ';' {
            $$ = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_RETURN,$2,NULL,NULL,NULL);
        }
        ;

BreakPointStmt: BRKP ';' {
            $$ = createTree(0,NULL,TYPE_NULL,NULL,NODETYPE_BRKP,NULL,NULL,NULL,NULL);
            }
            ;

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
ArgList: ArgList ',' expr {
            $1->next = createArgList($3);
            $$ = $1;
        }
        | expr {
            $$ = createArgList($1);
        }
        ;
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
    | expr OR expr {
        $$ = createTree(0,"||",TYPE_INT,NULL,NODETYPE_OP_RELATIONAL,$1,NULL,$3,NULL);
    }
    | expr AND expr {
        $$ = createTree(0,"&&",TYPE_INT,NULL,NODETYPE_OP_RELATIONAL,$1,NULL,$3,NULL);
    }
    | '(' expr ')' {
        $$ = $2;
    }
    | ID Dimlist {
        SymbolTable* st = lookupEntry($1->varname,sstop);
        $1->STentry = st;
        $1->type = st->type;
        $1->nodetype = NODETYPE_ARRAY;
        $1->dimNode = $2;
        $$ = $1;
    }
    | MUL ID {
        SymbolTable* st = lookupEntry($2->varname,sstop);
        if(st->type!=TYPE_PTR){
            fprintf(stderr,"Error: Trying to access non pointer values\n");
            exit(1);
        }
        $2->STentry = st;
        $$ = createTree(0,"*",st->vartype,NULL,NODETYPE_ACCESS,$2,NULL,NULL,NULL);
    }
    | '&' ID {
        SymbolTable* st = lookupEntry($2->varname,sstop);
        if(st->type==TYPE_PTR){
            fprintf(stderr,"Error: Trying to reference a pointer\n");
            exit(1);
        }
        $2->STentry = st;
        $2->type = st->type;
        $$ = createTree(0,"&",st->type,NULL,NODETYPE_REF,$2,NULL,NULL,NULL);
    }
    | ID '('')'{
        SymbolTable* st = lookupEntry($1->varname,sstop);
        checkargs(NULL,st->paramList,$1->varname);
        $$->STentry = st;
        $$ = createTree(0,NULL,st->type,$1->varname,NODETYPE_FUNC_CALL,NULL,NULL,NULL,NULL);
    }
    | ID '('ArgList')'{
        SymbolTable* st = lookupEntry($1->varname,sstop);
        checkargs($3,st->paramList,$1->varname);
        $$->STentry = st;
        $$ = createTree(0,NULL,st->type,$1->varname,NODETYPE_FUNC_CALL,NULL,NULL,NULL,NULL);
        $$->argList = $3;
    }
    | ID {
        SymbolTable* st = lookupEntry($1->varname,sstop);
        $1->STentry = st;
        $1->type = st->type;
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
    stack_top = initialStackTop;
    codegen_initialize_stack(initialStackTop);
    fprintf(target_file,"MOV BP, 4095\n");
    fprintf(target_file,"CALL F0\n");
    fprintf(target_file,"JMP L_EXIT\n");
    codegen(head,-1,-1);
    fprintf(target_file,"L_EXIT:");
    codegen_call_exit();
}

void free_memory(){
    freeTree(head);
}

int main(){
    yyin = fopen("../input.expl", "r");
    yyparse();
    printTree(head);
    target_file = fopen("../target_file.xsm","w");
    code_generate();
    /* free_memory(); */
    return 0;
}