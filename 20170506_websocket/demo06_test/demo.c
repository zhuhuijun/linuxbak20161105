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
#include <pthread.h>
/*****************************************/
//接收server端socket的线程
void *recvfunc(void *arg){
	int st = *(int * )arg;
	char s[1024];
	while(1){
		memset(s,0,sizeof(s));
		int rc = recv(st,s,sizeof(s),0);
		if (rc <=0 ){//0代表socket关闭了
			break;//代表关闭或者出错了
		}else{
			printf("%s\n",s );
		}
	}
	return NULL;
}
/*****************************************/
//向server端socket发送数据的线程
void *sendfunc(void *arg){
	int st = *(int * )arg;
	char s[1024];
	while(1){
		memset(s,0,sizeof(s));
		read(STDIN_FILENO,s,sizeof(s));
		send(st,s,strlen(s),0);
	}
	return NULL;
}
int main(int argc,char *args[])
{
	if (argc < 3)
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
	pthread_t thrdrecv,thrdsend;
	pthread_create(&thrdrecv,NULL,recvfunc,&st);//客户端端接收服务端的线程
	pthread_create(&thrdsend,NULL,sendfunc,&st);//客户端向服务端发送的线程
	pthread_join(thrdrecv,NULL);//等待防止退出
	//pthread_join(thrdsend,NULL);//如果等待着就不会退出了
	close(st);
	return 1;
}

