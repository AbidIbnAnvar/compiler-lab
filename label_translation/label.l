%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>
    #include "map.c"
    int line_no = 0;
    FILE* target_file;
    bool fetchedAddress = false;
%}

DIGIT   [0-9]

%%

"L"{DIGIT}+: {
    int address = 2056+2*(line_no-8);
    yytext[yyleng - 1] = '\0';
    put(yytext,address);
}

"L"{DIGIT}+ {
    if(fetchedAddress){
        fprintf(target_file,"%d",get(yytext));
    }else{
        fprintf(target_file,"%s",yytext);
    }
}

[\n] {
    if(!fetchedAddress){
        line_no++;
    }
    fprintf(target_file,"\n");
}
. {
    fprintf(target_file,"%s",yytext);
}

%%

int yywrap(){
    return 1;
}

int main(){
    yyin = fopen("../target_file.xsm","r");
    target_file = fopen("../temp.xsm","w");
    if (!yyin) {
        perror("Cannot open file");
        exit(1);
    }
    yylex();
    fclose(yyin);
    fclose(target_file);
    fetchedAddress = true;
    yyin = fopen("../temp.xsm","r");
    target_file = fopen("../target_file.xsm","w");
    yylex();
    fclose(yyin);
    fclose(target_file);
    remove("../temp.xsm");
    return 0;
}