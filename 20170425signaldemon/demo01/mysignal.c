#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <signal.h>
#include <syslog.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
int status=0;
//信号控制函数
void signalctrl(int sign){
	switch(sign){
		case SIGINT:
		if (status == 0)
			status = 1;
		else
			status = 0;
		break;
		case SIGPIPE:
			;
		break;	
	}
}
int mysingal(int signo,void (*func)(int)){
	struct sigaction act,oact;
	act.sa_handler=func;
	sigemptyset(&act.sa_mask);
	act.sa_flags=0;
	return sigaction(signo,&act,&oact);
}
void setdaemon(){
	pid_t pid=fork();
	if (pid == -1)
	{
		printf("fork error\n");
		exit(0) ;
	}
	if (pid > 0){
		exit(0);
	}
	if (pid == 0)
	{
		setsid();//和控制台脱离关系
		chdir("/");//改为根目录
		umask(0);//文件权限
		//close(STDIN_FILENO);
		//close(STDOUT_FILENO);
		//close(STDERR_FILENO);
	}
	syslog(LOG_INFO,"my daemon is ok");
}
int main(int arg,char *args[])
{
	setdaemon();
	mysingal(SIGINT,signalctrl);//捕捉信号
	mysingal(SIGPIPE,signalctrl);//捕捉信号
	while(1)
	{
		if(status){
			printf("hello...\n");
		}
		sleep(1);
	}
	return 1;
}