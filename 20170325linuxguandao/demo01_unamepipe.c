#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
//无名管道的读写
//需要共享数据，父子关系进程
//程序结束后就灭了
int main(int arg,char* argss[])
{
	int fd[2];
	char buf[100];
	int len;
	pipe(fd);
	memset(buf,0,sizeof(buf));
	int pid = fork();
	if(pid == 0)
	{
		close(fd[1]);
		while((len = read(fd[0],buf,sizeof(buf)))>0)
		{
			write(STDOUT_FILENO,buf,len);
		}
		close(fd[0]);
	}else{
		close(fd[0]);
		strcpy(buf,"hello,world\n");
		write(fd[1],buf,sizeof(buf));
		close(fd[1]);
		waitpid(pid,NULL,0);
	}
	return 1;
}