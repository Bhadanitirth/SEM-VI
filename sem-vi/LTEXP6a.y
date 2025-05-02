%{
#include <stdio.h>
#include <stdlib.h>
int yylex(void);
void yyerror(char* );
%}

%token NUM
%left '+' '-'
%left '*' '/' '%'
%left '(' ')'

%%

program:
    | program expr '\n' { 
        printf("Result = %d\n", $2); 
    }
;

expr: 
    NUM  { $$ = $1; }
    | expr '+' expr { $$ = $1 + $3; }
    | expr '-' expr { $$ = $1 - $3; }
    | expr '*' expr { $$ = $1 * $3; }
    | expr '/' expr { $$ = $1 / $3; }
    | expr '%' expr { $$ = $1 % $3; }
    | '(' expr ')' { $$ = $2; }
;

%%

int main(void) {
    printf("Enter an expression: ");
    yyparse();
    return 0;
}

void yyerror(char *s) {
    fprintf(stderr, "Error: %s\n", s);
}
