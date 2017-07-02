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
int status = 0;
struct  psparam
{
	int st;
	pthread_t *thr;
};
/*****************************************/
//接收client端socket的线程
void *recvfunc(void *arg){
	struct psparam *p = (struct psparam *)arg;
	int st = p->st;
	//int st = *(int * )arg;
	char s[1024];
	while(1){
		memset(s,0,sizeof(s));
		int rc = recv(st,s,sizeof(s),0);
		if (rc <=0 ){
			break;//代表关闭或者出错了
		}else{
			printf("%s\n",s );
		}
	}
	status = 0;
	pthread_cancel(*(p->thr));
	return NULL;
}
/*****************************************/
//向client端socket发送数据的线程
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
	if (argc < 2)
	{
		return -1;
	}

	int port = atoi(args[1]);
	int st = socket(AF_INET,SOCK_STREAM,0);
	int on = 1;
	if (setsockopt(st,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on)) == -1){
		printf("setsocketopt failed%s\n",strerror(errno) );
		return -1;
	}
	struct sockaddr_in addr;
	if (st == -1){
		printf("create socket error: %s",strerror(errno));
		return -1;
	}


	memset(&addr,0,sizeof(addr));
	addr.sin_family=AF_INET;
	addr.sin_port=htons(port);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	//绑定
	if (bind(st,(struct sockaddr *)&addr,sizeof(addr)) == -1)
	{
		printf("bind error %s\n",strerror(errno) );
		return -1;
	}
	//20个连接同时
	if (listen(st,20) == -1)
	{
		printf("listen failed %s\n",strerror(errno) );
		return -1;
	}
	char s[1024];
	memset(s,0,sizeof(s));
	int client_st = 0; //client 端
	struct sockaddr_in client_addr;
	void *p = &client_addr;
	pthread_t thrdrecv,thrdsend;
	while (1){
		memset(&client_addr ,0, sizeof(client_addr));
		socklen_t len = sizeof(client_addr);
		//accept会阻塞直到有客户端连到这里
		client_st = accept (st,(struct sockaddr *)&client_addr,&len);
		status ++;
		if (status >1){//这是第二次的连接了
			close(client_st);
			continue;
		}
		if (client_st == -1){
			printf("accept failed %s\n",strerror(errno) );
			return -1;
		}
		printf("accept form :%s\n",inet_ntoa(client_addr.sin_addr));
		struct psparam ps1;
		ps1.st = client_st;
		ps1.thr = &thrdsend;
		pthread_create(&thrdrecv,NULL,recvfunc,&ps1);//服务端接收客户端的线程
		pthread_create(&thrdsend,NULL,sendfunc,&client_st);//服务端向客户端发送的线程
	}
	close(st);

	return 1;
}