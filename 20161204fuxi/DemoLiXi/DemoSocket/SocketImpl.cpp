#include "SocketImpl.h"
#include "iostream"

SocketImpl::SocketImpl(void)
{
	buf=NULL;
	buflen=0;
}


SocketImpl::~SocketImpl(void)
{
	if(this->buf){
		free(this->buf);
	}
	this->buflen=0;
}
//�ͻ��˳�ʼ����ȡhandle����������Ϣ
int SocketImpl::cltSocketInit(){
	buf=NULL;
	buflen=0;
	return 0;
}
//�ͻ��˷�����
int SocketImpl::cltSocketSend(unsigned char* buf,int buflen){
	if(buf==NULL||buflen>3232322332){
		return -1;
	}
	this->buf=(unsigned char*)malloc(buflen * sizeof(char));
	if(this->buf==NULL){
		return -1;
	}
	memcpy(this->buf,buf,buflen);
	this->buflen=buflen;
	return 0;
}
//�ͻ����ձ���
int SocketImpl::cltSocketRecv(unsigned char* buf,int* buflen){
	if(buf==NULL||buflen==NULL){
		return -1;
	}
	memcpy(buf,this->buf,this->buflen);
	*buflen=this->buflen;
	return 0;
}
//�ͻ����ͷ���Դ
int SocketImpl::cltSocketDestory(){
	buf=NULL;
	buflen=0;
	return 0;
}