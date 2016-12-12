#include "SocketImpl2.h"
#include "iostream"

SocketImpl2::SocketImpl2(void)
{
	buf=NULL;
	buflen=0;
}


SocketImpl2::~SocketImpl2(void)
{
	if(this->buf){
		free(this->buf);
	}
	this->buflen=0;
	printf("SocketImpl2的析构函数.....\n");
}
//客户端初始化获取handle的上下文信息
int SocketImpl2::cltSocketInit(){
	buf=NULL;
	buflen=0;
	return 0;
}
//客户端发报文
int SocketImpl2::cltSocketSend(unsigned char* buf,int buflen){
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
//客户端收报文
int SocketImpl2::cltSocketRecv(unsigned char* buf,int* buflen){
	if(buf==NULL||buflen==NULL){
		return -1;
	}
	memcpy(buf,this->buf,this->buflen);
	*buflen=this->buflen;
	return 0;
}
//客户端释放资源
int SocketImpl2::cltSocketDestory(){
	buf=NULL;
	buflen=0;
	return 0;
}