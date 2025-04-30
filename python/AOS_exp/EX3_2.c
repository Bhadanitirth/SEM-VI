#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>


int main()
{
	printf("Process ID:%d\n",getpid());
	printf("Parent Process ID:%d\n",getppid());
	printf("Read user ID:%d\n",getuid());
	printf("Real group ID:%d\n",getgid());
	printf("Effective user ID:%d\n",geteuid());
	printf("effective group ID:%d\n",getegid());
}
