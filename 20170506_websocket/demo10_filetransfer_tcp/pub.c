/*
 ============================================================================
 Name        : pub.c
 Author      : zhujy
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#ifdef WIN
#include <WinSock2.h>
#else
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>
#define SOCKET int
#endif

#include <stdio.h>
#include "pub.h"

#define BUFSIZE 262144 //16k

void getfilename(const char *filename,char *name)
{
	int len = strlen(filename);
	int i=0;
	for (i = (len-1);i>=0;i--){
		if ((filename[i] == '\\') || (filename == '/')){
			break;
		}
	}
	strcpy(name,&filename[i+1]);
	return ;
}



SOCKET init_socket()
{
//如果是windos
#ifdef WIN
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	wVersionRequested = MAKEWORD(1,1);
	err = WSAStartup(wVersionRequested,&wsaData);
	if ( err != 0)
	{
		return -1;
	}

	if (LOBYTE (wsaData.wVersion) != 1 || HIBYTE(wsaData.wVersion) != 1)
	{
		WSACleanup();
		return -1;
	}
#endif

	return 0;
}

SOCKET scoket_connect(const char *hostname,int port)
{
	if (init_socket() == -1)
		return 0;

	SOCKET st = socket(AF_INET,SOCK_STREAM,0);
	if (st == 0 )
		return 0;
	struct sockaddr_in addr;
	memset(&addr,0,sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = inet_addr(hostname);
	if (connect(st, (struct sockaddr *) &addr,sizeof(addr)) == -1)
	{
		printf("connect to %s:%d is error: %s\n", hostname,port,strerror(errno));
		return 0;
	}else
	{
		return st;
	}
}

SOCKET scoket_create(int port)
{
	if (init_socket() == -1)
		return 0;
	
	SOCKET st = socket(AF_INET,SOCK_STREAM,0);
	if (st == 0)
		return 0;

#ifdef WIN
	const char on =0;
#else
	int on = 0;
#endif

	if (setsockopt(st,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on)) == -1)
	{
		printf("setsockopt failed %s\n",strerror(errno) );
		return 0;
	}	
	struct sockaddr_in addr;
	memset(&addr,0,sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(st,(struct sockaddr *)&addr,sizeof(addr)) == -1)
	{
		printf("bind failed %s\n",strerror(errno) );
		return    0;
	}
	if (listen(st,20) == -1)
	{
		printf("listen failed %s\n",strerror(errno) );
		return 0;
	}
	printf("listen %d success \n",port );
	return st;
}

SOCKET scoket_accept(SOCKET listen_st)
{
	struct sockaddr_in client_addr;

#ifdef WIN
	int len = 0;
#else
	unsigned int len = 1;
#endif

	len = sizeof(client_addr);
	memset (&client_addr,0,sizeof(client_addr));
	SOCKET client_st = accept(listen_st,(struct sockaddr *)&client_addr,
		&len);//accept阻塞直到有client 连接到server
	if (client_st == -1 )
	{
		printf("accept failed %s\n",strerror(errno) );
		return 0;
	}else
	{
		printf("accept by %s\n", inet_ntoa(client_addr.sin_addr));
		return client_st;
	}
}

int send_work (const char *hostname,int port,const char *filename)
{
	SOCKET st = scoket_connect(hostname,port);//建立发送数据的tcp Socket
	if (st == 0)
		return 0;

	FILE *fd = fopen(filename,"rb");//以只读方式打开文件
	if (fd == NULL)
	{
		printf("open %s failed:%s\n",filename,strerror(errno) );
		return 0;
	}

	char *buf =malloc(BUFSIZE);//申请缓冲区用于接受发送的内容
	memset(buf,0,BUFSIZE);
	getfilename(filename,buf);
	size_t rc = send(st,buf,sizeof(buf),0);
	if (rc <= 0)
	{
		if (rc < 0)
			printf(" send failed %s\n",strerror(errno) );
		else
			printf(" socket disconnect \n");
	
	}else
	{
  		
		memset(buf,0,sizeof(buf));
		if (recv(st,buf,BUFSIZE,0) <= 0)//接收来自server端的消息
		{
			if (rc < 0)
				printf("recv failed %s\n",strerror(errno) );
			else
				printf("socket disconnect \n");
		}else
		{
			if ( strncmp(buf,"OK",2) == 0)
			{
				while (1)
				{
					memset(buf,0,BUFSIZE);
					rc  =fread(buf,1,BUFSIZE,fd);
					if (rc <= 0)
					{
						if (rc < 0 )
							printf("fread failed %s\n",strerror(errno) );
						break;
					}else
					{

						rc =send(st,buf,rc,0);
						if ( rc <= 0)
						{
							if ( rc < 0)
								printf("send failed %s\n",strerror(errno) );
							else
								printf("sock disconnect \n");
							break;
						}
					}
				}
			}
		}

	}
	fclose(fd);
	free(buf);

#ifdef WIN
	closesocket(st);
	WSACleanup();
#else
	close(st);
#endif
	return 1;	
}

int recv_work(int port)//接收子客户端的数据
{
	SOCKET listen_st =scoket_create(port);//建立server端的socket在指定端口listen
	if (listen_st == 0)
		return 0;
	SOCKET st  = scoket_accept(listen_st);
	if ( st == 0)
		return 0;

	char *buf = malloc(BUFSIZE);
	FILE *fd = NULL;

	memset(buf,0,BUFSIZE);
	size_t rc = recv(st,buf,BUFSIZE,0);//第一次接收文件的名称
	if (rc <= 0 )
	{
		if (rc<0)
			printf("recv failed %s\n",strerror(errno) );
		else
			printf("socket disconnect \n");
	}else
	{
		printf("recving %s\n",buf );

		fd = fopen(buf,"wb");

		if (fd == NULL)
		{
			printf("open %s failed :%s\n",buf,strerror(errno) );
		}else
		{
			memset(buf,0,BUFSIZE);
			strcpy(buf,"OK");
			rc = send(st,buf,strlen(buf),0);
			if ( rc <= 0 )
			{
				if (rc<0)
					printf("send failed %s\n",strerror(errno) );
				else
					printf("socket disconnect\n");
			}

			while (1)
			{
				memset(buf,0,BUFSIZE);
				rc = recv (st,buf,BUFSIZE,0);
				if ( rc <= 0 )
				{
					if (rc<0)
						printf("recv failed %s\n",strerror(errno) );
					else
						printf("socket disconnect\n");
					break;
				}else
				{
					fwrite(buf,1,rc,fd);
				}
			}
		}
	}
	if (fd)
		fclose(fd);
	free(buf);
#ifdef WIN
	closesocket(st);
	closesocket(listen_st);
	WSACleanup();
#else
	close (st);
	close(listen_st);
#endif
	return 1;
}