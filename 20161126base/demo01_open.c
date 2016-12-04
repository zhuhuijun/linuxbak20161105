#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
int main (void)
{
	char s[]="abc.txt";
	close(STDOUT_FILENO);
	int fd1=open("/dev/pts/1",O_WRONLY);
	int fd=open(s,O_RDONLY);

	if(fd==-1)
	{
		printf("%s\n",strerror(errno) );
	}
	else{
		int i=0;
		while(1)
		{
			i++;
			printf("fd==%d,i=======%d\n",fd ,i);
			//sleep(1);
			usleep(1000);
		}

		close(fd);
	}

	return 0;
}