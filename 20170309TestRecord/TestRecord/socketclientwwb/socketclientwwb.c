#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//------------------第一套api接口---Begin--------------------------------//
//客户端初始化 获取handle上下
__declspec(dllexport) 
int cltSocketInit(void **handle /*out*/){
	return 0;
}

//客户端发报文
__declspec(dllexport) 
int cltSocketSend(void *handle /*in*/, unsigned char *buf /*in*/,  int buflen /*in*/)
{
	return 0;
}

//客户端收报文
__declspec(dllexport) 
int cltSocketRev(void *handle /*in*/, unsigned char *buf /*in*/, int *buflen /*in out*/){
	return 0;
}

//客户端释放资源
__declspec(dllexport) 
int cltSocketDestory(void *handle/*in*/)
{
	return 0;
}
//------------------第一套api接口---End-----------------------------------//