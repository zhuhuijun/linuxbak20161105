#pragma once
#include "socketprotocol.h"
class SocketImpl2 :
	public SocketIF
{
public:
	SocketImpl2(void);
	~SocketImpl2(void);
public:
	//客户端初始化获取handle的上下文信息
	int cltSocketInit();
	//客户端发报文
	int cltSocketSend(unsigned char* buf,int buflen);
	//客户端收报文
	int cltSocketRecv(unsigned char* buf,int* buflen);
	//客户端释放资源
	int cltSocketDestory();
private:
	unsigned char *buf;
	int buflen;
};

