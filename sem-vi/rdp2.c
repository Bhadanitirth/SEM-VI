// S → (S) | ε

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char ch;

bool S();
int main(){
    ch = getchar(); 
    if(S()){
        printf("correct\n");
    }else{
        printf("wrong\n");
    }
    return 0;
}

bool S(){
    if(ch == '('){
        ch = getchar(); 
        if(S()){
            if(ch == ')'){
                return true;
            }
            else{
                return false;
            }
        }
    }
    return true;
}