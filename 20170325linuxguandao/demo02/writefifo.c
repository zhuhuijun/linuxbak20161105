#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
//有名管道
int main(int arg,char* argss[])
{	
	char buf[100];
	memset(buf,0,sizeof(buf));
	int fd = open("fifo1",O_WRONLY);
	while(1)
	{
		scanf("%s",buf);
		if(buf[0] == '0')
		{
			break;
		}
		write(fd,buf,sizeof(buf));
	}
	close(fd);
	return 1;
}