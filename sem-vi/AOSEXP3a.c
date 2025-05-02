#include <stdio.h>
#include <unistd.h>    // for fork(), getpid(), getppid(), getuid(), getgid(), geteuid(), getegid()
#include <stdlib.h>    // for exit()
#include <sys/wait.h>  // for wait()

int main() {
    pid_t pid;

    printf("Real User ID (UID): %d\n", getuid());
    printf("Real Group ID (GID): %d\n", getgid());
    printf("Effective User ID (EUID): %d\n", geteuid());
    printf("Effective Group ID (EGID): %d\n", getegid());

    int x = 10;

    pid = fork();
    
    if (pid == 0) {
        // Child process
        // wait(NULL);
        printf("Child Process\n");
        printf("Child PID: %d\n", getpid());
        printf("Parent PID (from child): %d\n", getppid());
        x=x+2;
        printf("X : %d\n",x);
        exit(0);  // Child exits
    } 
    else if (pid > 0) {
        // Parent process
        wait(NULL); // Parent waits for child to finish
        printf("Parent Process\n");
        printf("Parent PID: %d\n", getpid());
        x=x-2;
        printf("X : %d\n",x);
    } 
    else {
        printf("Fork failed (error)\n");
    }
    
    return 0;
}
