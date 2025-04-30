#include<sys/shm.h>
#include<sys/mman.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>

int main()
{
	void* ptr;
	int shm_fd = shm_open("mydata",O_RDONLY,0777);
	ftruncate(shm_fd,20);
	ptr = mmap(NULL,20,PROT_READ,MAP_SHARED,shm_fd,0);
	printf("\n %s \n",(char*)ptr);
	shm_unlink("mydata");
	printf("shared memory is Removed");
	return 0;
}
