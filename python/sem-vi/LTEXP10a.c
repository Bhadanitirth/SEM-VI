// #include <stdio.h>
// #include <stdbool.h>

// char ch;

// int getChar() {
//     return getchar(); // Read a character from the user
// }

// bool E();
// bool A();
// bool B();

// int main() {
//     if(E())
//         printf("correct");
//     else
//         printf("wrong");
//     return 0;
// }

// bool E() {
//     ch = getChar(); // Get the character
//     if(A()) {
//         ch = getChar();
//         if(ch == '+') { // Check if the character is '+'
//             ch = getChar();
//             return B();
//             // if(B()) {   
//             //     return 1;
//             // }
//         }
//     }
//     else {
//         return 0;
//     }
//     return 0; // Ensure that there is a return value in case of no match
// }

// bool A() {
//     if(ch == 'a')
//         return 1;
//     else
//         return 0;
//     return 1; // Always return 1 (this can be modified based on your logic)
// }

// bool B() {
//     if(ch == 'b')
//         return 1;
//     else
//         return 0;
//     return 1; // Always return 1 (this can be modified based on your logic)
// }


// // E -> T E'  (Expression)
// // E' -> +T E' | ε  (Expression continuation)
// // T -> F T'  (Term)
// // T' -> *F T' | ε  (Term continuation)
// // F -> id | (E)  (Factor)

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

char ch; // Current character

// Function prototypes
void getNextChar();
bool E();
bool EPrime();
bool T();
bool TPrime();
bool F();

// Get the next character from input
void getNextChar() {
    ch = getchar();
}

int main() {
    // Read the first character to initialize
    getNextChar();
    
    if(E() && (ch == '\n' || ch == EOF)) {
        printf("correct\n");
    } else {
        printf("wrong\n");
    }
    return 0;
}

// E -> T E'
bool E() {
    if(T()) {
        return EPrime();
    }
    return false;
}

// E' -> +T E' | ε
bool EPrime() {
    if(ch == '+') {
        getNextChar(); // Consume '+'
        if(T()) {
            return EPrime();
        }
        return false;
    }
    
    // ε (epsilon) production - return true without consuming anything
    return true;
}

// T -> F T'
bool T() {
    if(F()) {
        return TPrime();
    }
    return false;
}

// T' -> *F T' | ε
bool TPrime() {
    if(ch == '*') {
        getNextChar(); // Consume '*'
        if(F()) {
            return TPrime();
        }
        return false;
    }
    
    // ε (epsilon) production - return true without consuming anything
    return true;
}

// F -> id | (E)
bool F() {
    if(ch == 'i') {
        getNextChar();
        if(ch == 'd') {
            getNextChar(); // Consume 'd'
            return true;
        }
        return false;
    } else if(ch == '(') {
        getNextChar(); // Consume '('
        if(E() && ch == ')') {
            getNextChar(); // Consume ')'
            return true;
        }
        return false;
    }
    
    return false;
}