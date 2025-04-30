#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
	
int count = 0;
pthread_mutex_t lock;
void *consumer()
{	int i;
	printf("Get pid %d :\n",getpid());
	printf("Thread started\n");
	for(i=0;i<1000;i++)
	{	pthread_mutex_lock(&lock);
		count++;
		pthread_mutex_unlock(&lock);
	}
	printf("Thread ended\n");
}
void *producer()
{	int i;
	printf("Get pid %d :\n",getpid());
	printf("Thread started\n");
	for(i=0;i<1000;i++)
	{	pthread_mutex_lock(&lock);
		count++;
		pthread_mutex_unlock(&lock);
	}
	printf("Thread ended\n");
}

int main()
{
	//pthread_mutex_t lock;
	pthread_t t1,t2;
	pthread_mutex_init(&lock,NULL);
	pthread_create(&t1,NULL,&consumer,NULL);
	pthread_create(&t2,NULL,&producer,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_mutex_destroy(&lock);
	printf("Ans: %d\n",count);
	return 0;
}
