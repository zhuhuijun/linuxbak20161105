#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "itcastlog.h"
typedef struct _SCK_HANDLE{
	char			version[16];
	char			serverip[16];
	int				serverport;
	unsigned char*	pbuf;
	int				buflen;
}SCK_HANDLE;
//------------------��һ��api�ӿ�---Begin--------------------------------//
//�ͻ��˳�ʼ�� ��ȡhandle����
__declspec(dllexport) 
	int cltSocketInit(void **handle /*out*/)
{
	int ret = 0;
	SCK_HANDLE *sb = NULL;
	sb = (SCK_HANDLE *)malloc(sizeof(SCK_HANDLE));
	if (sb == NULL)
	{
		ret = -1;
		ITCAST_LOG(__FILE__,__LINE__,LogLevel[3],23,"func cltSocketInit error");
		return ret;
	}
	strcpy (sb->version ,"1.0.0");
	strcpy (sb->serverip,"192.168.0.100");
	sb->serverport = 8080;
	*handle = sb ;
	return ret;
}

//�ͻ��˷�����
__declspec(dllexport) 
	int cltSocketSend(void *handle /*in*/, unsigned char *buf /*in*/,  int buflen /*in*/)
{
	int ret = 0;
	SCK_HANDLE *sh = NULL;
	if (handle == NULL ||buf == NULL || buflen>35536)
	{
		ret = -1;
		return ret;
	}
	sh = (SCK_HANDLE *)handle;
	sh->pbuf = (unsigned char *)malloc(buflen * sizeof(char));
	if(sh->pbuf == NULL){
		ret = -2;
		ITCAST_LOG(__FILE__,__LINE__,LogLevel[3],23,"func cltSocketSend() malloc error,buflen:%d",buflen);
		return ret;
	}
	memcpy(sh->pbuf,buf,buflen);
	sh->buflen = buflen;
	return ret;
}

//�ͻ����ձ���
__declspec(dllexport) 
	int cltSocketRev(void *handle /*in*/, unsigned char *buf /*in*/, int *buflen /*in out*/)
{
	int ret = 0;
	SCK_HANDLE *sh = NULL;
	if (handle == NULL ||buf == NULL || buflen == NULL)
	{
		ret = -1;
		return ret;
	}
	sh = (SCK_HANDLE *)handle;
	memcpy (buf,sh->pbuf,sh->buflen);
	*buflen = sh->buflen;
	return ret;
}

//�ͻ����ͷ���Դ
__declspec(dllexport) 
	int cltSocketDestory(void *handle/*in*/)
{
	int ret = 0;
	SCK_HANDLE *sh = NULL;
	if (handle == NULL )
	{
		ret = -1;
		return ret;
	}
	sh = (SCK_HANDLE *)handle;
	if (sh->pbuf != NULL){
		free(sh->pbuf);
	}
	if (sh != NULL){
		free(sh);
	}
}
//------------------��һ��api�ӿ�---End-----------------------------------//

//------------------�ڶ���api�ӿ�---Begin--------------------------------//
__declspec(dllexport) 
	int cltSocketInit2(void **handle)
{
	return cltSocketInit(handle);
}

//�ͻ��˷�����
__declspec(dllexport) 
	int cltSocketSend2(void *handle, unsigned char *buf,  int buflen)
{
	return cltSocketSend(handle,buf,buflen);
}
//�ͻ����ձ���
__declspec(dllexport) 
	int cltSocketRev2(void *handle, unsigned char **buf, int *buflen)
{
	int ret = 0;
	unsigned char *tmp = NULL;
	SCK_HANDLE *sh = NULL;
	if (handle == NULL ||buf == NULL || buflen == NULL)
	{
		ret = -1;
		return ret;
	}
	sh = (SCK_HANDLE *)handle;
	tmp = (unsigned char *) malloc(sizeof(char)*sh->buflen);
	if (tmp == NULL)
	{
		ITCAST_LOG(__FILE__,__LINE__,LogLevel[3],23,"func cltSocketRev2() malloc error");
		return ret;
	}
	memcpy(tmp,sh->pbuf,sh->buflen);

	*buf = tmp;
	*buflen = sh->buflen;
	return ret;
}
//�ͷ�
__declspec(dllexport) 
	int cltSocketRev2_Free(unsigned char **buf)//�ͷſռ�����ΪNULL
{
	int ret = 0;
	if (buf == NULL)
	{
		ret = -1;
		return ret ;
	}
	free (*buf);
	*buf = NULL;
	return ret;
}
//�ͻ����ͷ���Դ
__declspec(dllexport) 
	int cltSocketDestory2(void **handle)
{
	int ret = 0;
	SCK_HANDLE *sh = NULL;
	if (handle == NULL )
	{
		ret = -1;
		return ret;
	}
	sh = (SCK_HANDLE *)*handle;
	if (sh->pbuf != NULL){
		free(sh->pbuf);
	}
	if (sh != NULL){
		free(sh);
	}
	*handle = NULL ;//����޸�ʵ�ε�ֵ
}
//------------------�ڶ���api�ӿ�---End--------------------------------//