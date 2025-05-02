#include <stdio.h>
#include <fcntl.h>    // for open()
#include <unistd.h>   // for read(), write(), close(), fork(), lseek()
#include <sys/wait.h> // for wait()

int main() {
    int fd = open("ex1.txt", O_RDONLY);
    if (fd < 0) {
        perror("Error opening ex1.txt");
        return 1;
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        close(fd);
        return 1;
    }
    else if (pid == 0) {
        // Child Process
        char buf[20];
        ssize_t bytesRead;

        printf("\n--- Child reading ---\n");
        bytesRead = read(fd, buf, 9);
        // bytesRead = read(fd, buf, sizeof(buf));
        if (bytesRead > 0) {
            write(1, buf, bytesRead);  // Write to stdout
        }
        printf("\n--- Child done ---\n");

        close(fd);
    }
    else {
        // Parent Process
        wait(NULL); // wait for child to finish

        char buf[20];
        ssize_t bytesRead;

        printf("\n--- Parent reading ---\n");
        bytesRead = read(fd, buf, sizeof(buf));
        if (bytesRead > 0) {
            write(1, buf, bytesRead);  // Write to stdout
        }
        printf("\n--- Parent done ---\n");

        close(fd);
    }

    return 0;
}

