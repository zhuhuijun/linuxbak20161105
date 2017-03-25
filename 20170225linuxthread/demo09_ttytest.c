#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
int main(int argc,char *argv[])
{	
	close(STDOUT_FILENO);
	int fd = open("/dev/pts/1",O_WRONLY);
	pid_t pid = fork();
	/*
	while(1)
	{
		sleep(2);
		printf("hello world！fd=%d\n", fd);
	}
	*/
	if (pid == 0)
	{
		char *args[] = {"/bin/ls","-l",NULL};
		execve("/bin/ls",args,NULL);
		//ls共享了标准输出和文件描述符
		//子进程被ls占据了，文件描述符共享了
	}
	return 1;
}