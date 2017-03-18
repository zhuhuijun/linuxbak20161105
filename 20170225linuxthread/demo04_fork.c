#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main(int argc,char *argv[])
{
	printf("begin\n");
	pid_t chid = fork();
	if (chid == -1)
	{
		return -1;
	}
	if (chid == 0)
	{
		while(1)
		{
			sleep(1);
			printf("this is child pid >> %d\n",getpid());
		}
	}else{
		while(1)
		{
			sleep(1);
			printf("this is parent pid >> %d\n",getpid());
		}
	}
	printf("end\n");
	return EXIT_SUCCESS;
}