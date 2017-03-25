#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
int main(int argc,char *argv[])
{
	if(argc >1)
	{
		int pid = atoi(argv[1]);
		kill(pid,SIGKILL);
	}else
	{
		printf("pid=>>>>%d\n",getpid() );
		sleep(60);
	}
	return EXIT_SUCCESS;
}