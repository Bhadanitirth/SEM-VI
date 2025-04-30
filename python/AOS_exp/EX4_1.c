#include<stdio.h>
#include<unistd.h>
void main()
{
	pid_t id;
	id=fork();
	printf("Shared Space ...\n");
	printf("Process id of EX4_1 is %d\n",getpid());
	if(id == 0){
		char *args[]={"./EX4_2",NULL};
		execv(args[0],args);
	}
	else if(id > 0)
	{
		printf("Parent so NOP\n");
	}
	
	printf("Back to EX4_1\n");
}
