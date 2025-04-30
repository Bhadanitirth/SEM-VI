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
	fd1=open("Seek2.txt",O_RDWR);
	write(fd1,buff,10);
	//lseek(fd,0,SEEK_SET);
	//read(fd,buff,10);
	//write(fd1,buff,10);
	close(fd);
	close(fd1);
}
