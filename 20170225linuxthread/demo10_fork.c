#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
int main(int argc,char *argv[])
{
	printf("begin\n");
	pid_t chid = fork();
	int status;
	//fork之后的代码执行两次，所以是2个end 1个start
	if (chid == -1)
	{
		return -1;
	}
	if (chid == 0)
	{

		printf("this is child start pid >> %d\n",getpid());
		sleep(5);
		printf("this is child end pid >> %d\n",getpid());
		return 9;
	}else{
		wait(&status);//阻塞调用
		printf(">>>>>status:%d\n", WEXITSTATUS(status));
		printf("this is parent pid >> %d\n",getpid());
	}
	printf("all end pid=%d \n",getpid());
	return EXIT_SUCCESS;
}