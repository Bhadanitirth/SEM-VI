// #include <stdio.h>
// #include <stdlib.h>
// #include <ctype.h>

// char ch;
// int s;

// int getNextChar() {
//     ch = getchar();
//     if (ch != EOF && ch != '\n')
//         return 1;
//     return 0;
// }

// int main() {
//     s = 0;
//     while (getNextChar() == 1) {
//         switch (s) {
//             case 0:
//                 if (isalpha(ch) || ch == '_') {
//                     s = 1;
//                 } else if(isdigit(ch))
//                 {
//                     s = 2;
//                 } else {
//                     printf("wrong\n");
//                     exit(0);
//                 }
//                 break;

//             case 1:
//                 if (isalpha(ch) || ch == '_' || isdigit(ch)) {
//                     s = 1;
//                 } else {
//                     printf("wrong\n");
//                     exit(0);
//                 }
//                 break;

//             case 2:
//                 if (ch == '.') {
//                     s = 3;
//                 } else if(isdigit(ch))
//                 {
//                     s = 2;
//                 } else {
//                     printf("wrong\n");
//                     exit(0);
//                 }
//                 break;

//             case 3:
//                 if(isdigit(ch))
//                 {
//                     s = 3;
//                 } else {
//                     printf("wrong\n");
//                     exit(0);
//                 }
//                 break;
//         }
//     }

//     printf("correct\n");
//     return 0;
// }


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char ch;
int s=0;
int main()
{
    while((ch=getchar())!=EOF && ch!='\n'){
        switch(s){
            case 0:                
                if(isalpha(ch) || ch=='_'){
                    s=1;
                }else{
                    printf("wrong\n");
                    exit(0);
                }
                break;
            case 1:
                if(isalpha(ch) || isdigit(ch) || ch=='_'){
                }else{
                    printf("wrong\n");
                    exit(0);
                }
                break;          
        }
    }
    printf("correct\n");
    return 0;   
}