#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main(int argc,char *argv[])
{
	printf("begin\n");
	pid_t chid = fork();
	//fork之后的代码执行两次，所以是2个end 1个start
	if (chid == -1)
	{
		return -1;
	}
	if (chid == 0)
	{
		printf("this is child pid >> %d\n",getpid());
	}else{

		printf("this is parent pid >> %d\n",getpid());
		
	}
	printf("end\n");
	return EXIT_SUCCESS;
}