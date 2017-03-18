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
		exit(0);
	}else{
		printf("parent start\n");
		wait(&status);//这句话可以避免僵死进程，因为不等待收集子进程的信息进程表不会释放记录
		sleep(100);
		printf("%d\n",WEXITSTATUS(status) );
		printf("parent end\n");
		return 0;
	}
	return 1;
}