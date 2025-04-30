#include<semaphore.h>
#include<pthread.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>

sem_t abc;

void *routine()
{
	
		sem_wait(&abc);
		printf("\n Entered \n ");
		
		sleep(4);

		printf("\n Just Exiting \n");
		sem_post(&abc);
}
int main()
{
	pthread_t t1,t2;
	sem_init(&abc,0,1);
	pthread_create(&t1,NULL,&routine,NULL);
	sleep(2);
	pthread_create(&t2,NULL,&routine,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	sem_destroy(&abc);
	return 0;
}
