#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
void main()
{
	int fd,fd1;
	char buff[10];
	fd=open("Seek.txt",O_RDWR);
	read(fd,buff,10);
	write(1,buff,10);
	
	read(fd,buff,10);
	write(1,buff,10);
	close(fd);
}
