#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>


int main()
{
	pid_t id;
	id = fork();
	if(id == 0)
	{	//sleep(3);
		printf("Child executed\n");
		printf("%d \n",id);
		printf("process id child %d,%d\n",getpid(),getppid());
	}
	else if(id > 0)
	{
		sleep(3);
		printf("Parent executed\n");
		printf("%d \n",id);
		printf("process id parent %d,%d\n",getpid(),getppid());
	}
	else if(id == -1)
	{
		printf("error\n");
	}
	printf("shared memory\n");
}
