%{
#include <stdio.h>
#include <stdlib.h>
void yyerror(char* );
#include "y.tab.h"  
%}

%%

[0-9]+      { yylval = atoi(yytext); return NUM; } 
[+\-*/%()]  { return yytext[0]; }  
[ \t]       { }
\n          { return '\n'; } 
.           { yyerror("invalid"); return 0; } 

%%

int yywrap() {
    return 1;
}
