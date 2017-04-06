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
//kill -s 2 pid
int status=0;
int func1(int a,int b){
	return a+b;
}
void signalctrl(int sign){
	switch(sign){
		case SIGINT:
		printf("Sigint\n");
		exit(0);
		break;
		case SIGUSR1:
		status=1;
		printf("SIGUSER1\n");
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
		return ;
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
int main(){
	setdaemon();
	int (*p)(int,int);
	p=func1;
	printf("p=%d\n",p(4,6) );
	signal(SIGINT,signalctrl);
	mysingal(SIGUSR1,signalctrl);
	printf("end\n");
	while(1){
		if(status==1)
			printf("hello %d\n",status);
		sleep(1);
	}
	return 0;
}