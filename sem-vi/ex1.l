%{
    #include<stdio.h>
    #include<stdlib.h>
    #include "y.tab.h"
    void yyerror(char* );    
%}

%%
north {return NORTH;}
south {return SOUTH;}
east {return EAST;}
west {return WEST;}
up {return UP;}
down {return DOWN;}  
\n  {return '\n';}
[ \t ]  { }
.   {yyerror("invalid");return 0;}
%%

int yywrap(){
    return 1;
}