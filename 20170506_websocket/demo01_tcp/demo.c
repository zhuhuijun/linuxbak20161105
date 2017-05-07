#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>

int main(int argc,char *args[])
{
	int st = socket(AF_INET,SOCK_STREAM,0);
	if (st == -1){
		printf("create socket error: %s",strerror(errno));
		return -1;
	}
	return 1;
}