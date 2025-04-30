#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<unistd.h>
#include<string.h>

#define buff 1024

int main()
{
	int p1[2],p2[2];
	pid_t pid;
	
	if(pipe(p1) == -1 || pipe(p2) == -1)	
	{
		printf("error");
		exit(1);
	}

	pid= fork();
	if(pid < 0)
	{
		close(p1[0]);
		close(P2[1]);
		char filename[buff];
		printf("Client Enter the file name:");
		fgets(filename,buff,stdin);
		filename[strcspn(filename,"\n")]='\0';
		write(pipe[1],filename,strlen(filename)+1);
		
		char response[buff];
		int n= read(p2[0],response,buff);
		if(n >0)
		{
			response[n] = '\0';
			printf("Client received \n%s\n",response);
		}
		close(p1[1]);
		close(p2[0]);
	}
	else
	{
		close(p1[1]);
		close(p2[0]);
		char filename[buff];
		int n = read(p1[0]],filename,buff);
		if(n < 0)
		{
			char error_msg[] = "Error reading from pipe";
			exit(1);
		}
		filename[n] = '\0';
	
	char buffer[buff];
	int file = open(filename,O_RDONLY);
	if(file < 0)
	{
		char error_msg[] = "Error File notfound or could not be opened.";
		write(p2[1]),error_msg,strlen(error_msg)+1);
	}
	else
	{
		while((n = read(file,buffer,buff)) > 0)
		{
			write(p2[1],buffer,n);
		}
		close(file);
	}
	close(p1[0]);
	close(p2[1]);
	wait(NULL);


	}	
		
	

	return 0;
}

