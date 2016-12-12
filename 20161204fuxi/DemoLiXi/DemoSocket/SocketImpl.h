#pragma once
#include "socketprotocol.h"
class SocketImpl :
	public SocketIF
{
public:
	SocketImpl(void);
	~SocketImpl(void);
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

