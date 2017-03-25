#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
int main(int argc,char *argv[])
{
	printf("begin\n");
	pid_t pid = 0;
	pid = fork();
	if (pid == -1)
	{
		return -1;
	}
	if (pid == 0)
	{
		//孤儿进程
		while(1)
		{
			printf("child \n");
			sleep(1);
			printf("getppid = %d\n",getppid() );
		}
	}else{
		exit(0);
	}
	return EXIT_SUCCESS;
}