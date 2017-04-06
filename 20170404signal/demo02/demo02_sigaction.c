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
int signal1(int signo,void (*func)(int))
{
	struct sigaction act,oact;
	act.sa_handler = func;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	return sigaction(signo,&act,&oact);
}
void catch_Signal(int signal)
{
	switch(signal){
		case SIGINT:
		printf("catch_signal:SIGINT\n");
		exit(0);
		break;
		case SIGALRM:
		alarm(5);
		printf("catch_signal:SIGALRM\n");
		break;
		case SIGKILL:
		printf("catch_signal:SIGKILL\n");
		break;
	}
}
//改进的信号的机制
int main(int arg,char* args[])
{
	int i = 0;
	printf("SIGINT:%d;SIGALRM:%d;\n", SIGINT,SIGALRM);
	signal(SIGINT,catch_Signal);
	signal(SIGALRM,catch_Signal);
	signal(SIGKILL,catch_Signal);
	while(1)
	{
		printf("hello %d\n",i++);
		sleep(1);
	}
	return 0;
}