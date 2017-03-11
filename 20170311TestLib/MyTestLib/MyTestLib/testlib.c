#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "clientsocketwwb.h"


int main(int arg,char* argv[])
{
	int ret;
	void *handle = NULL;

	unsigned char buf[128];
	int buflen = 11;

	unsigned char outbuf[128];
	int outbuflen;

	strcpy(buf,"fafafwtqtggag45353");

	ret =  cltSocketInit(&handle);
	if(ret != 0){
		printf("cltSocketInit error\n");
		goto end;
	}
	//�ͻ��˷�����
	ret = cltSocketSend(handle,buf,buflen);
	if (ret != 0){
		printf("func cltSocketSend() error\n");
		goto end;
	}

	//�ͻ����ձ���
	ret =cltSocketRev(handle,outbuf,&outbuflen);
	if(ret != 0){
		printf("func cltSocketRev() error\n");
		goto end;
	}
	printf("%s\n",outbuf);
end:
	if (handle != NULL)
	{
		cltSocketDestory(handle);
	}
	system("pause");
	return 1;
}