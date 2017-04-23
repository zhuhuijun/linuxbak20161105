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
void readfifo(){
	int len = 0;
	char buf[1024];
	memset(buf,0,sizeof(buf));
	int fd = open("/root/daemon/fifo1",O_RDONLY);
	if (fd == -1)
	{
		printf("open fifo error %s\n",strerror(errno) );
		memset(buf,0,sizeof(buf));
		return;
	}
	while((len = read(fd,buf,sizeof(buf))) >0)
	{
		printf("%s\n", buf);
	}
	close(fd);
	return ;
}
int main(int arg,char *args[])
{
	setdaemon();
	readfifo();
	return 1;
}