%{
    #include<stdio.h>
    #include<stdlib.h>
    #include "y.tab.h"
    void yyerror(char*);

    int x=0,y=0,z=0;
%}

%token EAST WEST NORTH SOUTH UP DOWN

%%

prog:
    | prog pro '\n' {printf("resule x:%d y:%d z:%d \n",x,y,z);}
;

pro:
    EAST     {x++;}
    | WEST   {x--;}
    | NORTH  {y++;}
    | SOUTH   {y--;}
    | UP    {z++;}
    | DOWN  {z--;}
;

%%

int main(void){
    yyparse();
    return 0;
}

void yyerror(char* s){
    fprintf(stderr,"error %s",s);
}