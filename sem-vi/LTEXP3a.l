%{
#include <stdio.h>
#include <string.h>
%}

/* Definitions */
digit       [0-9]
letter      [a-zA-Z]
id          {letter}({letter}|{digit})*
int_num     {digit}+
float_num   ({digit}*"."{digit}+)|({digit}+"."{digit}*)
whitespace  [ \t]
comment     \*\*\*.*

/* Rules */
%%

"if"|"for"|"while"|"do"|"exit"|"else"|"case"|"switch"|"until"    {
    printf("Keyword recognized: %s\n", yytext);
}

{float_num} {
    printf("Float number recognized: %s\n", yytext);
}

{int_num} {
    printf("Integer number recognized: %s\n", yytext);
}

{comment} {
    printf("Single line comment recognized: %s\n", yytext);
}

{whitespace}+    ;   

"["|"]"|"{"|"}"|"("|")"|"," {
    printf("Punctuation recognized: %s\n", yytext);
}

":="|"<>"|"=="|"!="|"<="|">="|"+"|"-"|"*"|"%" {
    printf("Operator recognized: %s\n", yytext);
}

\'[^\']*\' {
    printf("String constant recognized: %s\n", yytext);
}

{id} {
    printf("Identifier recognized: %s\n", yytext);
}

\n  ;  

. {
    printf("Unrecognized character: %s\n", yytext);
}

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
