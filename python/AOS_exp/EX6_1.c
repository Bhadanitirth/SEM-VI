#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	int C[2];
	int P[2];		
	char* buff[10];
	if(pipe(C) < 0)
	{
		printf("error");
		exit(1);
		
	}
	else if(pipe(P) < 0)
	{
		printf("error");
		exit(1);
	}
	write(C[1],buff,10);
	sleep(2);
	close(C[1]);
	read(C[0],buff,10);
	printf("C:%d\n",C[1]);
	printf("C:%d\n",C[2]);

	write(P[1],buff,10);
	sleep(2);
	close(P[1]);
	read(P[0],buff,10);
	printf("P:%d\n",P[1]);
	printf("P:%d\n",P[2]);
	
	return 0;
}

