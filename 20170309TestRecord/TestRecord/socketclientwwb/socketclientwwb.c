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
//------------------第一套api接口---Begin--------------------------------//
//客户端初始化 获取handle上下
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

//客户端发报文
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
	//
	memcpy(sh->pbuf,buf,buflen);
	sh->buflen = buflen;
	return ret;
}

//客户端收报文
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

//客户端释放资源
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
//------------------第一套api接口---End-----------------------------------//

//------------------第二套api接口---Begin--------------------------------//
__declspec(dllexport) 
	int cltSocketInit2(void **handle)
{
	return cltSocketInit(handle);
}

//客户端发报文
__declspec(dllexport) 
	int cltSocketSend2(void *handle, unsigned char *buf,  int buflen)
{
	return cltSocketSend(handle,buf,buflen);
}
//客户端收报文
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
//释放
__declspec(dllexport) 
	int cltSocketRev2_Free(unsigned char **buf)//释放空间设置为NULL
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
//客户端释放资源
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
	*handle = NULL ;//间接修改实参的值
}
//------------------第二套api接口---End--------------------------------//