#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define buff 1024

int main()
{
    int p1[2], p2[2];
    pid_t pid;

    if (pipe(p1) == -1 || pipe(p2) == -1)
    {
        perror("Pipe error");
        exit(1);
    }

    pid = fork();

    if (pid == 0)
    {
        // Child process – Client
        close(p1[0]); // Close read end of p1
        close(p2[1]); // Close write end of p2

        char filename[buff];
        printf("Client Enter the file name: ");
        fflush(stdout);  // Ensure prompt is shown before input

        int len = read(0, filename, buff);
        filename[len - 1] = '\0'; // Remove newline if present

        write(p1[1], filename, strlen(filename) + 1); // Send filename to parent

        char response[buff];
        int n = read(p2[0], response, buff); // Read file content or error
        if (n > 0)
        {
            response[n] = '\0';
            printf("Client received:\n%s\n", response);
        }

        close(p1[1]);
        close(p2[0]);
    }
    else if (pid > 0)
    {
        // Parent process – Server
        close(p1[1]); // Close write end of p1
        close(p2[0]); // Close read end of p2

        char filename[buff];
        int n = read(p1[0], filename, buff); // Read filename from child
        if (n <= 0)
        {
            char error_msg[] = "Error reading from pipe";
            write(p2[1], error_msg, strlen(error_msg) + 1);
            exit(1);
        }
        filename[n] = '\0';

        char buffer[buff];
        int file = open(filename, O_RDONLY);
        if (file < 0)
        {
            char error_msg[] = "Error: File not found or could not be opened.";
            write(p2[1], error_msg, strlen(error_msg) + 1);
        }
        else
        {
            while ((n = read(file, buffer, buff)) > 0)
            {
                write(p2[1], buffer, n);
            }
            close(file);
        }

        close(p1[0]);
        close(p2[1]);
        wait(NULL);
    }
    else
    {
        perror("Fork failed");
        exit(1);
    }

    return 0;
}
