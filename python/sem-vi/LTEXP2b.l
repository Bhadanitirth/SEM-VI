%{
#include <stdio.h>

int char_count = 0;
int line_count = 0;
%}

%%

\n      { line_count++; char_count++; printf("\nTotal characters: %d\n", char_count);}    // Newline counts as a character and a line
.       { char_count++; printf("\nTotal lines: %d\n", line_count);}                  // Any other character increments char count

%%

int main()
{
    yylex();
    printf("\nTotal characters: %d", char_count);
    printf("\nTotal lines: %d\n", line_count);
    return 0;
}

int yywrap()
{
    return 1;
}

