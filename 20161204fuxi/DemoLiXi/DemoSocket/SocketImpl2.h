#pragma once
#include "socketprotocol.h"
class SocketImpl2 :
	public SocketIF
{
public:
	SocketImpl2(void);
	~SocketImpl2(void);
public:
	//�ͻ��˳�ʼ����ȡhandle����������Ϣ
	int cltSocketInit();
	//�ͻ��˷�����
	int cltSocketSend(unsigned char* buf,int buflen);
	//�ͻ����ձ���
	int cltSocketRecv(unsigned char* buf,int* buflen);
	//�ͻ����ͷ���Դ
	int cltSocketDestory();
private:
	unsigned char *buf;
	int buflen;
};

