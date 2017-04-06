#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <signal.h>
int func1(int f1,int f2){
	return f1+f2;
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
//自己的sleep
void mysleep(int i)
{
	alarm(i);
	pause();
	return;
}
int main(int arg,char* args[])
{
	/*
	int (*pfunc)(int,int);
	pfunc = func1;
	printf("ret = %d\n",pfunc(10,45));
	*/
	int i = 0;
	printf("SIGINT:%d;SIGALRM:%d;\n", SIGINT,SIGALRM);
	signal(SIGINT,catch_Signal);
	signal(SIGALRM,catch_Signal);
	signal(SIGKILL,catch_Signal);
	//kill -s 2|14 pid
	mysleep(10);
	printf("mysleep...\n");
	alarm(5);
	while(1)
	{
		scanf("%d",&i);
		printf("hello %d\n",i++);
		//sleep(1);
	}
	return 0;
}