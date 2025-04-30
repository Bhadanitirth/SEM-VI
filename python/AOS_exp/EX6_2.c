#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{
	int C[2];
	int P[2];		
	char* buff[10];
	int pid = fork();

	if(pid == 0)
	{
		int y;
		close(C[1]);
		close(P[0]);
		read(C[1],buff,10);
		printf("child %d\n",y);
		y = y+4;
		write(P[1],buff,10);
		printf("child_d:%d\n",y);
		close(C[0]);
		close(P[1]);
	}

	else if(pid > 0)
	{
		int x = 5;
		int z;
		close(C[0]);
		close(P[1]);
		write(C[1],buff,10);
		printf("Parent x: %d\n",x);
		wait(NULL);
		read(P[0],buff,10);
		printf("parent_d:%d\n",z);
		close(C[1]);
		close(P[0]);
	}
	else
	{
		printf("error\n");
	}	
		
	

	return 0;
}

