#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>

#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<sys/ipc.h>

void main()
{
	int fd,fd1;
	char buff[10];
	fd=open("Seek.txt",O_RDWR);
	read(fd,buff,10);
	write(1,buff,10);
	fd1=open("Seek2.txt",O_RDWR);
	write(fd1,buff,10);
	
	read(fd,buff,10);
	write(1,buff,10);
	close(fd);
	close(fd1);
}

