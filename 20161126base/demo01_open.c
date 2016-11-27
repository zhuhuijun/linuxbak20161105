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
	int fd=open(s,O_RDONLY);

	if(fd==-1)
	{
		printf("%s\n",strerror(errno) );
	}
	else{
		while(1)
		{
			printf("fd==%d\n",fd );
			sleep(1);
		}

		close(fd);
	}

	return 0;
}