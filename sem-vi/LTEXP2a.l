%{
#include <stdio.h>
%}

digit[ 0-9 ]
char[ a-z A-Z _]

%%
username: {printf("Current Logged-in Username: %s\n", getlogin());}

{digit}+ {printf("\n digit recognized");}
{digit}+"."{digit}+ {printf("\n float digit recognized");}
{char}({char}|{digit})* {
                if (strcmp(yytext, "int") == 0 || strcmp(yytext, "float") == 0 ||
                    strcmp(yytext, "if") == 0 || strcmp(yytext, "else") == 0 ||
                    strcmp(yytext, "while") == 0 || strcmp(yytext, "return") == 0) {
                    printf("\nKeyword recognized: %s", yytext);
                } else {
                    printf("\nIdentifier recognized: %s", yytext);
                }
            }

.   { printf("\n not recognized"); }


%%

int main()
{
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}

