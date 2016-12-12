#pragma  once
class SocketIF{
public:
	//客户端初始化获取handle的上下文信息
	virtual int cltSocketInit()=0;
	//客户端发报文
	virtual int cltSocketSend(unsigned char* buf,int buflen)=0;
	//客户端收报文
	virtual int cltSocketRecv(unsigned char* buf,int* buflen)=0;
	//客户端释放资源
	virtual	int cltSocketDestory()=0;
public:
	//释放子类的析构函数
	virtual	~SocketIF(){

	}
};