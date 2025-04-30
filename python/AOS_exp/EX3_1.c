// #include<unistd.h>
// #include<sys/types.h>
// #include<stdio.h>
// #include<stdlib.h>
// #include<sys/wait.h>


// int main()
// {
// 	pid_t id;
// 	id = fork();
// 	int x=10;
// 	if(id == 0)
// 	{	
// 		x += 5;
// 		printf("%d\n",x);
// 	}
// 	else if(id > 0)
// 	{
// 		x = x-5;
// 		printf("%d\n",x);	
// 	}
// 	else if(id == -1)
// 	{
// 		printf("error\n");
// 	}
// 	x = x*5;
// 	printf("%d\n",x);
// }

#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>

int x;

int main()
{
	pid_t id;
	id = fork();
	if(id == 0)
	{	
		// sleep(3);
		printf("Child process\n");
		x += 5;
		printf("%d\n",x);
	}
	else if(id > 0)
	{
		printf("Parent process\n");
		// wait(NULL);
		x = x-5;
		printf("%d\n",x);	
	}
	else if(id == -1)
	{
		printf("error\n");
	}
	 x=10;
	 x = x*5;
	 printf("o-%d\n",x);
}
