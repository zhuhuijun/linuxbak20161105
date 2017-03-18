#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(int argc,char *argv[])
{	
	pid_t pid = fork();
	int status;
	if(pid == -1)
	{
		printf("fork error\n");
		return -1;
	}
	if(pid == 0)
	{
		printf("child start\n");
		sleep(2);
		printf("child start\n");
		return 100;
	}else{
		printf("parent start\n");
		wait(&status);
		printf("%d\n",WEXITSTATUS(status) );
		printf("parent start\n");
		return 0;
	}
	return 1;
}