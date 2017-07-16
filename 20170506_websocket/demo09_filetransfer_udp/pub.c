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

#define BUFSIZE 16384 //16k

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

SOCKET create_recv_socket(int port)//在port端口上建立接收数据的udp socket
{
	//if (init_socket() == -1)
	//	return -1;
	
	SOCKET st = socket (AF_INET,SOCK_DGRAM,0);
	if (st == 0 )
		return 0;

	struct sockaddr_in addr;
	memset (&addr,0,sizeof(addr));
	addr.sin_family =AF_INET;
	addr.sin_port htons(port);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(st,(struct sockaddr *)&addr,sizeof(addr)) == -1)//服务端需要bind一下
	{
		printf("bind failed:%s\n", strerror(errno));
		return 0;
	}
	return st;
}

SOCKET create_send_scoket()
{//建立发送的socket
	if (init_socket() == -1)
		return 0;

	SOCKET st = socket (AF_INET,SOCK_DGRAM,0);//UDP socket
	if (st ==0)
		return 0;
	return st;//成功返回描述符
}

int send_work (const char *hostname,int port,const char *filename){
	SOCKET st_send = create_send_scoket();//建立发送数据的UDP Socket
	SOCKET st_recv = create_recv_socket(port+1);//建立接收数据的UDP socket
	if (st_send == 0)
		return 0;
	if (st_recv == 0)
		return 0;



	FILE *fd = fopen(filename,"rb");//以只读方式打开文件
	if (fd == NULL)
	{
		printf("open %s failed:%s\n",filename,strerror(errno) );
		return 0;
	}

	char *buf =malloc(BUFSIZE);
	memset(buf,0,BUFSIZE);
	getfilename(filename,buf);

	struct sockaddr_in addr;
	memset(&addr,0,sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons (port);
	addr.sin_addr.s_addr = inet_addr(hostname);

	size_t rc = sendto(st_send,buf,strlen(buf),0,
		(struct sockaddr *)&addr,
		sizeof(addr));
	//发送失败
	if (rc <=0)
	{
		printf("send failed %s\n",strerror(errno) );
	}else
	{
		struct sockaddr_in client_addr;
		//if window
#ifdef WIN
		int len = 0;
#else 
		unsigned int len =0;
#endif

		len =sizeof(client_addr);
		memset(&client_addr, 0, sizeof(client_addr));


		memset(buf,0,BUFSIZE);
		if (recvfrom(st_recv,buf,BUFSIZE,0,
		(struct sockaddr *)&client_addr,&len) <= 0)//接收server的恢复
		{
			printf("recv failed %s\n", strerror(errno));

		}else
		{
			if (strncmp (buf,"OK",2) == 0)
			{
				while(1)
				{
					memset(buf,0,BUFSIZE);
					rc = fread(buf,1,BUFSIZE,fd);//循环读取文件
					if (rc <=0)
					{
						break;
					}else
					{
						rc = sendto(st_send,buf,rc,0,
							(struct sockaddr *)&addr,
							sizeof(addr));//从文件中读取数据
						if (rc <= 0)
						{
							printf("send failed %s\n",strerror(errno) );
							break;
						}
					}
				}
			}
			memset(buf,0,BUFSIZE);
			rc = sendto(st_send,buf,128,0,(struct sockaddr *)&addr,
					sizeof(addr));//连发128字节0代表结束

		}
	}

	fclose(fd);
	free(buf);

#ifdef WIN
	closesocket(st_send);
	closesocket(st_recv);
	WSACleanup();
#else
	close(st_send);
	close (st_recv);
#endif
	return 1;	
}

int recv_work(int port)//接收子客户端的数据
{
	SOCKET st_send =create_send_scoket();
	SOCKET st_recv = create_recv_socket(port);
	if (st_send == 0)
		return 0;

	if (st_recv == 0)
		return 0;

	char buf = malloc(BUFSIZE);
	FILE *fd = NULL;

#ifdef WIN
	int len = 0;
#else
	unsigned int len =1;
#endif


	struct sockaddr_in client_addr;
	len = sizeof(client_addr);
	memset(&client_addr,0,sizeof(client_addr));
	size_t rc = recvfrom(st_recv,buf,BUFSIZE,0,
		(struct sockaddr *)&client_addr,&len);
	if(rc <= 0)
	{
		printf("recv failed %s\n",strerror(errno) );
	}
	else
	{
		printf("recving %s\n",buf );

		fd = fopen(buf,"wb");
		if (fd == NULL)
		{
			printf("open %s failed %s\n",buf,strerror(errno) );
		}else
		{
			client_addr.sin_port = htons(port+1);
			memset(buf,0,sizeof(BUFSIZE));
			strcpy(buf,"OK");
			rc = sendto(st_send,buf,strlen(buf),0,
				(struct sockaddr *)&client_addr,sizeof(client_addr));
			if (rc <=0 )
			{
				printf("send failed %s\n", strerror(errno));
			}

			while (1)
			{
				memset(buf,0,BUFSIZE);
				rc = recvfrom(st_recv,buf,BUFSIZE,0,
					(struct sockaddr *)&client_addr,&len);

				char tmp[128];
				memset(tmp,0,sizeof(tmp));
				if (memcmp(buf,tmp,sizeof(tmp)) == 0 )
					break;

				if (rc <= 0)//代表client 连接断开
				{
					printf("recv failed %s\n",strerror(errno) );
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
	closesocket(st_send);
	closesocket(st_recv);
	WSACleanup();
#else
	close (st_send);
	close(st_recv);
#endif
	return 1;
}
