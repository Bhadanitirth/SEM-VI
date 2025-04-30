#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
void main()
{
	int fd;
	pid_t id;
	char* buff[10];
	fd=open("Seek.txt",O_RDWR);
	id = fork();
	if(id == 0)
	{	
		printf("Child\n");
		read(fd,buff,10);
		write(1,buff,5);
		printf("\n");
		printf("%d\n",fd);
	}
	else if(id > 0)
	{
		printf("Parent\n");
		read(fd,buff,10);
		write(1,buff,5);
		printf("\n");
		printf("%d\n",fd);
	}
	else
	{
		printf("Error\n");
	}
	close(fd);
}
