
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
//孤儿进程
int main(int argc,char *argv[])
{
	pid_t pid=fork();
	if (pid < 0){
		printf("fork failed : %s\n",strerror(errno));
		return -1;
	}
	if (pid > 0 ){
		exit(0);
	}
	if (pid == 0)//如果pid是0就代表是子进程
	{
		int i = 0;
		for (; i<100; i++)
		{
			pid_t tmp = fork();
			if(tmp == 0){
				exit(0);//子进程退出后由于父进程没有waitpid,子进程就成为孤儿进程
			}
		}
		pause();//进程暂停
	}
	return 0 ;
}