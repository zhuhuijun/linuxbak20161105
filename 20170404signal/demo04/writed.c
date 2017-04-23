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
void writefifo(){
	char buf[1024];
	memset(buf,0,sizeof(buf));
	int fd=open("/root/daemon/fifo1",O_WRONLY);
	if (fd == -1 )
	{
		printf("fd open error:%s\n",strerror(errno) );
	}
	while(1)
	{
		memset(buf,0,sizeof(buf));
		scanf("%s",buf);
		write(fd,buf,sizeof(buf));
	}

	close(fd);
	return ;
}
int main(int arg,char *args[])
{
	writefifo();
	return 1;
}