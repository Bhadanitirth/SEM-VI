#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
// #include <sys/shm.h>   
// #include <string.h>    
// #include <stdlib.h>

int main(){
	int size = 20;
	int shm_fd;
	void* ptr;
	shm_fd=shm_open("mydata",O_RDONLY,0777);
	ftruncate(shm_fd,size);
	ptr=mmap(NULL,size,PROT_READ,MAP_SHARED,shm_fd,0);
	printf("\n %s \n",(char*)ptr);
	shm_unlink("mydata");
}
