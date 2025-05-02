// #include <stdio.h>
// #include <stdbool.h>
// #include <stdlib.h>

// char ch;
// bool S();
// bool A();

// int main(){
//     if(S()){
//         printf("correct\n");
//     }else{
//         printf("wrong\n");
//     }
//     return 0;
// }

// bool S(){
//     ch = getchar();
//     if(ch == 'a'){
//         if(A()){
//             ch = getchar();
//             if(ch == 'b')
//                 return true;
//         }
//     }
//     return false;
// }

// bool A(){
//     ch = getchar();
//     if(ch == 'c'){
//         return A();
//     }
//     ungetc(ch, stdin);  // Push back non-'c' character for S to handle
//     return true;
// }

// S → a A b
// A → c A | ε

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char ch;
bool S();
bool A();

int main(){
    if(S()){
        printf("correct\n");
    }else{
        printf("wrong\n");
    }
    return 0;
}

bool S(){
    ch = getchar();
    if(ch == 'a'){
        ch = getchar();
        if(A()){
            if(ch == 'b')
                return true;
        }
    }
    return false;
}

bool A(){
    if(ch == 'c'){
        ch = getchar();
        return A();
    }
    return true;
}
