#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
//gcc -o mykill mykill.c
//ps -ef | grep demo | grep -v grep

int main(int arg,char* args[])
{
	if(arg > 1)
	{
		//kill(atoi(args[1]),SIGINT);
		kill(atoi(args[1]),SIGKILL);
	}
	return 0;
}