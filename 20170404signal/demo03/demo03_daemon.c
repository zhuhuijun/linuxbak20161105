#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <syslog.h>

int main(int argc,char *args[])
{
	pid_t pid=fork();
	if (pid == -1)
	{
		return -1;
	}
	if (pid > 0){
		exit(0);
	}
	if (pid == 0)
	{
		setsid();//和控制台脱离关系
		chdir("/");//改为根目录
		umask(0);//文件权限
		close(STDIN_FILENO);
		close(STDOUT_FILENO);
		close(STDERR_FILENO);
	}
	syslog(LOG_INFO,"my daemon is ok");

	return 1;
}