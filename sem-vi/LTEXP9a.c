#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 20
#define N 10

char production[N][N]; // Grammar productions
int numProductions;
char nonTerminals[N]; // List of non-terminals
char terminals[MAX]; // List of terminals

// To keep track of First and Follow sets
bool first[MAX][MAX], follow[MAX][MAX];

// Function to check if a character is terminal
bool isTerminal(char c) {
    return (c >= 'a' && c <= 'z'); // Assuming small letters are terminals
}

// Function to find First set
void findFirst(int i) {
    for (int j = 0; j < numProductions; j++) {
        if (production[j][0] == nonTerminals[i]) { // Check if production is for non-terminal
            if (isTerminal(production[j][2])) {
                first[i][production[j][2] - 'a'] = true; // Add terminal to First set
            } else if (production[j][2] == nonTerminals[i]) {
                continue; // Avoid infinite recursion
            } else {
                for (int k = 0; k < numProductions; k++) {
                    if (production[k][0] == production[j][2]) {
                        findFirst(k); // Recursive call to find First for non-terminal
                    }
                }
            }
        }
    }
}

// Function to find Follow set
void findFollow(int i) {
    for (int j = 0; j < numProductions; j++) {
        for (int k = 2; k < strlen(production[j]); k++) {
            if (production[j][k] == nonTerminals[i]) {
                if (production[j][k + 1] != '\0') {
                    if (isTerminal(production[j][k + 1])) {
                        follow[i][production[j][k + 1] - 'a'] = true;
                    }
                }
            }
        }
    }
}

// Function to print sets
void printSets(char name[], bool set[MAX][MAX]) {
    printf("%s: ", name);
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (set[i][j]) {
                printf("%c ", terminals[j]);
            }
        }
    }
    printf("\n");
}

int main() {
    printf("Enter number of productions: ");
    scanf("%d", &numProductions);
    getchar(); // To consume the newline character

    // Input productions
    for (int i = 0; i < numProductions; i++) {
        printf("Enter production %d: ", i + 1);
        fgets(production[i], sizeof(production[i]), stdin);
        production[i][strlen(production[i]) - 1] = '\0'; // Remove newline
    }

    // Identify non-terminals and terminals
    for (int i = 0; i < numProductions; i++) {
        if (!isTerminal(production[i][0])) {
            nonTerminals[i] = production[i][0];
        }
    }

    // Initialize First and Follow sets to false
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < MAX; j++) {
            first[i][j] = false;
            follow[i][j] = false;
        }
    }

    // Find the First set for all non-terminals
    for (int i = 0; i < numProductions; i++) {
        if (isTerminal(production[i][2])) {
            first[i][production[i][2] - 'a'] = true;
        } else {
            findFirst(i);
        }
    }

    // Find the Follow set for all non-terminals
    for (int i = 0; i < numProductions; i++) {
        if (production[i][0] == nonTerminals[i]) {
            findFollow(i);
        }
    }

    // Print the First and Follow sets
    printSets("First", first);
    printSets("Follow", follow);

    return 0;
}
