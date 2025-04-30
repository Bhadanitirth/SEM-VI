#include<sys/shm.h>
#include<sys/mman.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<time.h>


int main()
{
	const char* filename="mydata";

	int size=4096;
	int shmfd=shm_open(filename,O_CREAT|O_RDWR,0777);
	if(shmfd==-1){
		printf("error");
		return 1;	
	} 
	ftruncate(shmfd,size);
	void *ptr;
	ptr=mmap(NULL,size,PROT_WRITE,MAP_SHARED,shmfd,0);
	while(1){

	// time_t ct;
	// time(&ct);
	// struct tm*lt=localtime(&ct);
	// sprintf(ptr,"%s",asctime(lt));
	// printf("%s",(char *)ptr);
	time_t now=time(NULL);
	char* curtime=ctime(&now);
	sprintf(ptr,"%s",(char* )curtime);
	
	sleep(1);	
	

	printf("Data written to shared memory\n");
	}
}
