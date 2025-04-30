#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
	
int count = 0;
pthread_mutex_t lock;
void *routine()
{	int i;
	printf("Get pid %d :\n",getpid());
	printf("Thread started\n");
	for(i=0;i<1000;i++)
	{
		count++;
	}
	printf("Thread ended\n");
}

int main()
{
	pthread_t t1,t2;
	pthread_create(&t1,NULL,&routine,NULL);
	pthread_create(&t2,NULL,&routine,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	printf("Ans: %d\n",count);
	return 0;
}
