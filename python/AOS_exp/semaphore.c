#include<semaphore.h>
#include<pthread.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>

int mails = 0;
sem_t abc;

void *routine()
{
	for(int i=0;i<100;i++)
	{
		sem_wait(&abc);
		mails++;
		sem_post(&abc);
	}
}
int main()
{
	pthread_t t1,t2;
	sem_init(&abc,0,1);
	pthread_create(&t1,NULL,&routine,NULL);
	pthread_create(&t2,NULL,&routine,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	printf("%d\n",mails);
	sem_destroy(&abc);
	return 0;
}
