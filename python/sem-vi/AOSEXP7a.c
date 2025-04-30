#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <time.h>
// #include <sys/shm.h>   
// #include <string.h>     
// #include <stdlib.h>     

int main(){
	int size = 20;
	int shm_fd;
	void* ptr;
	shm_fd=shm_open("mydata",O_CREAT|O_RDWR,0777);
	ftruncate(shm_fd,size);
	ptr=mmap(NULL,size,PROT_WRITE,MAP_SHARED,shm_fd,0);
	time_t now=time(NULL);
	char* timestr=ctime(&now);
	sprintf(ptr,"time %s\n",(char* )timestr);
	printf("\n data written to shm \n");
	return 0;
}
