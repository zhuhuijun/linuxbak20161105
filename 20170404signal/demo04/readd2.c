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
//ps -ef  | grep myreadd | grep -v grep
//mkdififo fifo1
void listenfifo(){
	const char *fifoname="/root/daemon/fifo1";
	int len = 0;
	char buf[128];
	memset(buf,0,sizeof(buf));
	int fd = open(fifoname,O_RDONLY);
	if (fd == -1)
	{
		printf(" open %s failed :%s\n",fifoname,strerror(errno));
	}
	len = read (fd,buf,sizeof(buf));
	if (len > 0)
	{
		if(buf[strlen(buf) - 1 ] == '\n')
		{
			buf [strlen(buf) -1 ] = 0;
		}
		close(STDOUT_FILENO);
		open(buf,O_WRONLY);
	}
	close(fd);
}
//信号控制函数
void signalctrl(int sign){
	switch(sign){
		case SIGINT:
		listenfifo();
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
		puts("hello,world!\n");
		sleep(1);
	}
	return 1;
}