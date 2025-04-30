#include<sys/shm.h>
#include<sys/mman.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main()
{
	int shm_Fd;
	void* ptr;
	const char* name = "mydata";
	int size=4096;
	
	shm_Fd = shm_open(name,O_RDONLY,0777);
	if(shm_Fd == -1)
	{
		printf("error");
		return 1;
	}
	ftruncate(shm_Fd,size);
	ptr = mmap(NULL,20,PROT_READ,MAP_SHARED,shm_Fd,0);
	//sprintf(ptr,"%s","i am shared memory\n");
	
		printf("%s\n",(char *)ptr);
	shm_unlink("mydata");
		//sleep(10);
	
	//read(shm_Fd,buff,20);
	//write(1,buff,20);
	//printf("\n %s \n",(char*)ptr);
	printf("data  from shared memory\n");
	
	return 0;
}
