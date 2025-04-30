#include <stdio.h>
#include <fcntl.h>    // for open()
#include <unistd.h>   // for read(), write(), close()

int main() {
    int fd1 = open("ex1.txt", O_RDONLY);   // Open ex1.txt for reading
    if (fd1 < 0) {
        perror("Error opening ex1.txt");
        return 1;
    }

    int fd2 = open("ex2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);  // Open ex2.txt for writing
    if (fd2 < 0) {
        perror("Error opening ex2.txt");
        close(fd1);
        return 1;
    }

    char buf[100];   // Fixed-size buffer
    ssize_t bytesRead = read(fd1, buf, 9);  // Read up to 100 bytes
    // ssize_t bytesRead = read(fd1, buf, sizeof(buf));  // Read up to 100 bytes

    if (bytesRead > 0) {
        write(fd2, buf, bytesRead);  // Write what we read
        write(1, buf, bytesRead);
    }

    lseek(fd1, 0, SEEK_CUR);    //SEEK_CUR, SEEK_SET, SEEK_END

    bytesRead = read(fd1, buf, 9);  // Read up to 100 bytes

    if (bytesRead > 0) {
        write(fd2, buf, bytesRead);  // Write what we read
        write(1, buf, bytesRead);
    }

    close(fd1);
    close(fd2);

    return 0;
}
