#include "iostream"
#include "SocketImpl.h"
#include "SocketProtocol.h"
#include "SocketImpl2.h"
using namespace std;
//主框架
void mainOP(){
	SocketIF *slf=new SocketImpl();
	unsigned char buf[1024];
	strcpy((char *)buf,"fffffffffffffff");

	unsigned char outbuf[1024];
	int outlen=10;
	int buflen=10;
	slf->cltSocketInit();
	slf->cltSocketSend(buf,buflen);
	slf->cltSocketRecv(outbuf,&outlen);
}
int mainOP2(SocketIF *slf,unsigned char *in,int inlen,
	unsigned char *out,int *outlen){
		slf->cltSocketInit();
		slf->cltSocketSend(in,inlen);
		slf->cltSocketRecv(out,outlen);
		return 0;
}
//业务类的定义地方
class MainOpTest{
public:
	MainOpTest(SocketIF *iif)
	{
		this->slf=iif;
	}
	MainOpTest()
	{
	}
public:
	int mainOP2(unsigned char *in,int inlen,
		unsigned char *out,int *outlen){
			int ret=0;
			this->slf->cltSocketInit();
			this->slf->cltSocketSend(in,inlen);
			this->slf->cltSocketRecv(out,outlen);
			return ret;
	}
	int mainOP3(SocketIF *slf,unsigned char *in,int inlen,
		unsigned char *out,int *outlen){
			slf->cltSocketInit();
			slf->cltSocketSend(in,inlen);
			slf->cltSocketRecv(out,outlen);
			return 0;
	}
public:
	void setSIF(SocketIF *sf){
		this->slf=sf;
	}
	SocketIF* getSif(){
		return this->slf;
	}
private:
	SocketIF *slf;
};
void main01(int argc,char* argv[])
{
	SocketIF *slf=new SocketImpl2();
	unsigned char buf[1024];
	strcpy((char *)buf,"fffffffffffffff");

	unsigned char outbuf[1024]={0};
	int outlen=10;
	int buflen=10;
	//mainOP();
	mainOP2(slf,buf,buflen,outbuf,&outlen);

	cout<<"out="<<outbuf<<endl;
	cout<<"hello,world!"<<endl;
	delete slf;
	system("pause");
}
//注入的例子
void main003(int argc,char* argv[])
{
	SocketIF *slf=new SocketImpl2();
	unsigned char buf[1024];
	strcpy((char *)buf,"fffffffffffffff");

	unsigned char outbuf[1024]={0};
	int outlen=10;
	int buflen=10;
	MainOpTest mop(slf);
	mop.mainOP2(buf,buflen,outbuf,&outlen);

	cout<<"out="<<outbuf<<endl;
	cout<<"hello,world!"<<endl;
	delete slf;
	system("pause");

}
//弱关联的例子
void main(int argc,char* argv[])
{
	SocketIF *slf=new SocketImpl2();
	unsigned char buf[1024];
	strcpy((char *)buf,"fffffffffffffff");

	unsigned char outbuf[1024]={0};
	int outlen=10;
	int buflen=10;
	MainOpTest mop;
	mop.mainOP3(slf,buf,buflen,outbuf,&outlen);

	cout<<"out="<<outbuf<<endl;
	cout<<"hello,world!"<<endl;
	delete slf;
	system("pause");
}