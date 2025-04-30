#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

#define BUF_SIZE 3
#define MAX_ITEMS 5

int buffer[BUF_SIZE],in = 0, out = 0, count = 0;
sem_t mutex, full, empty;

void *producer(void *arg)
{
	for(int i=1;i<=MAX_ITEMS;i++)
	{
		sem_wait(&empty);
		sem_wait(&mutex);
		buffer[in]=i;
		printf("Produced: %d \n",i);
		in = (in + 1) % BUF_SIZE;
		sem_post(&mutex);
		sem_post(&full);
	}
	return NULL;
}

void *consumer(void *arg)
{
	for(int i=1;i<=MAX_ITEMS;i++)
	{
		sem_wait(&full);
		sem_wait(&mutex);
		buffer[in]=i;
		printf("Consumed: %d \n",buffer[out]);
		out = (out + 1) % BUF_SIZE;
		sem_post(&mutex);
		sem_post(&empty);
	}
	return NULL;
}

int main()
{
	pthread_t prod,cons;
	sem_init(&mutex,0,1);
	sem_init(&full,0,0);
	sem_init(&empty,0,BUF_SIZE);
	pthread_create(&prod,NULL,&producer,NULL);
	pthread_create(&cons,NULL,&consumer,NULL);
	pthread_join(prod,NULL);
	pthread_join(cons,NULL);
	sem_destroy(&mutex);
	sem_destroy(&full);
	sem_destroy(&empty);
	return 0;
}




















