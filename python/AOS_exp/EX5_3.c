#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
	

pthread_mutex_t lock;
void *routine()
{ 
	printf("Get pid %d :\n",getpid());
	printf("Thread started\n");
	printf("Thread ended\n");
}

int main()
{
	pthread_t t1,t2;
	pthread_create(&t1,NULL,&routine,NULL);
	pthread_create(&t2,NULL,&routine,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	return 0;
}
