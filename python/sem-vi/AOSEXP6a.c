#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#define BUF_SIZE 1024

int main() {
    int pipe1[2]; // client to server
    int pipe2[2]; // server to client

    if (pipe(pipe1) == -1 || pipe(pipe2) == -1) {
        perror("pipe");
        exit(1);
    }

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) {
        // Child (Client)
        close(pipe1[0]); // Close read end of pipe1
        close(pipe2[1]); // Close write end of pipe2

        char filename[BUF_SIZE];
        printf("Enter file name to request: ");
        fgets(filename, BUF_SIZE, stdin);
        filename[strcspn(filename, "\n")] = 0;

        write(pipe1[1], filename, strlen(filename) + 1);

        char response[BUF_SIZE];
        read(pipe2[0], response, BUF_SIZE);

        printf("Received from server:\n%s\n", response);

        close(pipe1[1]);
        close(pipe2[0]);
    } else {
        // Parent (Server)
        close(pipe1[1]); // Close write end of pipe1
        close(pipe2[0]); // Close read end of pipe2

        char filename[BUF_SIZE];
        read(pipe1[0], filename, BUF_SIZE);

        char content[BUF_SIZE];
        FILE *fp = fopen(filename, "r");
        if (fp == NULL) {
            snprintf(content, BUF_SIZE, "File \"%s\" not found.\n", filename);
        } else {
            fread(content, 1, BUF_SIZE, fp);
            fclose(fp);
        }

        write(pipe2[1], content, strlen(content) + 1);

        close(pipe1[0]);
        close(pipe2[1]);
    }

    return 0;
}

