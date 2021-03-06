/*
 ============================================================================
 Name        : sock.c
 Author      : zhujy
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
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
	if (args < 3)
		return -1;

	int port = atoi(args[2]);
	int st = socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in addr;
	if (st == -1){
		printf("create socket error: %s",strerror(errno));
		return -1;
	}


	memset(&addr,0,sizeof(addr));
	addr.sin_family=AF_INET;
	addr.sin_port=htons(port);
	addr.sin_addr.s_addr = inet_addr(args[1]);
	if (connect(st,(struct sockaddr *)&addr,sizeof(addr)) == -1)
	{
		printf("connect error %s\n",strerror(errno) );
		return -1;
	}
	char s[1024];
	while(1){
		memset(s,0,sizeof(s));

		read(STDIN_FILENO,s,sizeof(s));

		if (send(st,s,strlen(s),0) == -1)
		{
			printf("send failed %s\n",strerror(errno) );
			return -1;
		}
		memset(s,0,sizeof(1024));
		if ( recv(st,s,sizeof(s),0 ) > 0){
			printf("client-receive:%s\n",s );//如果接收数据失败循环break;
		}
		else{
			break;
		}
	}
	close(st);
	return 1;
}

