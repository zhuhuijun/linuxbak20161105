#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//------------------��һ��api�ӿ�---Begin--------------------------------//
//�ͻ��˳�ʼ�� ��ȡhandle����
__declspec(dllexport) 
int cltSocketInit(void **handle /*out*/){
	return 0;
}

//�ͻ��˷�����
__declspec(dllexport) 
int cltSocketSend(void *handle /*in*/, unsigned char *buf /*in*/,  int buflen /*in*/)
{
	return 0;
}

//�ͻ����ձ���
__declspec(dllexport) 
int cltSocketRev(void *handle /*in*/, unsigned char *buf /*in*/, int *buflen /*in out*/){
	return 0;
}

//�ͻ����ͷ���Դ
__declspec(dllexport) 
int cltSocketDestory(void *handle/*in*/)
{
	return 0;
}
//------------------��һ��api�ӿ�---End-----------------------------------//