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
	addr.sin_port=htons(9001);
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
	socklen_t len = 0;
	struct sockaddr_in client_addr;
	void *p = &client_addr;
	int i = 0;
	for (i=0;i < 5 ; i++){
		memset(&client_addr ,0, sizeof(client_addr));
		socklen_t len = sizeof(client_addr);
		//accept会阻塞直到有客户端连到这里
		client_st = accept (st,(struct sockaddr *)&client_addr,&len);
		if (client_st == -1){
			printf("accept failed %s\n",strerror(errno) );
			return -1;
		}
		printf("accept form %s:",inet_ntoa(client_addr.sin_addr));
		while(1){
			memset(s,0,sizeof(s));
			int rc = recv(client_st,s,sizeof(s),0);
			if ( rc >0){
				printf("server>>>>recv:%s\n",s );
			}else{
				if (rc == 0 ){
					printf("client  close success \n" );
				}else
				printf("recv failed %s\n",strerror(errno) );
				
				//close(client_st);
				break;
			}
		}
	}
	close(st);

	return 1;
}