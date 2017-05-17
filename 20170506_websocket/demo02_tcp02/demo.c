#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
int main(int argc,char *args[])
{
	int st = socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in addr;
	if (st == -1){
		printf("create socket error: %s",strerror(errno));
		return -1;
	}


	memset(&addr,0,sizeof(addr));
	addr.sin_family=AF_INET;
	addr.sin_port=htons(9001);
	addr.sin_addr.s_addr = inet_addr("101.201.43.141");
	if (connect(st,(struct sockaddr *)&addr,sizeof(addr)) == -1)
	{
		printf("connect error %s\n",strerror(errno) );
		return -1;
	}
	char s[1024];
	memset(s,0,sizeof(s));
	strcpy(s,"hello,world");
	if (send(st,s,strlen(s),0) == -1)
	{
		printf("send failed %s\n",strerror(errno) );
		return -1;
	}
	sleep(100);
	close(st);

	return 1;
}