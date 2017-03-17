#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "clientsocketwwb.h"
#include "itcastlog.h"

int main(int arg,char* argv[])
{
	int ret;
	void *handle = NULL;

	unsigned char buf[128]={0};
	int buflen = 11;

	unsigned char *outbuf = NULL;
	int outbuflen;

	strcpy(buf,"fafafwtqtggag45353");
	ITCAST_LOG(__FILE__,__LINE__,LogLevel[3],23,"hello,world");
	ret =  cltSocketInit2(&handle);
	if(ret != 0){
		printf("cltSocketInit error\n");
		goto end;
	}
	//客户端发报文
	ret = cltSocketSend2(handle,buf,buflen);
	if (ret != 0){
		printf("func cltSocketSend() error\n");
		goto end;
	}

	//客户端收报文
	ret =cltSocketRev2(handle,&outbuf,&outbuflen);
	if(ret != 0){
		printf("func cltSocketRev() error\n");
		goto end;
	}
	printf("%s\n",outbuf);
	cltSocketRev2_Free(&outbuf);

end:
	if (handle != NULL)
	{
		cltSocketDestory2(&handle);
	}
	system("pause");
	return 1;
}