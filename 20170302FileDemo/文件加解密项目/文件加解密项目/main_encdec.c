#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "des.h"

void main01()
{
	int ret = 0;
	unsigned char pInData[128];
	int            nInDataLen ;
	unsigned char pOutData[1024];
	int           pOutDataLen  = 0;

	unsigned char plain[1024];
	int  plainlen = 0;

	char *p = "11112222222233344";
	strcpy(pInData, p);
	nInDataLen = strlen(p);


	//�û�ʹ�õĺ���
	ret = DesEnc(pInData, nInDataLen, pOutData, &pOutDataLen);
	if (ret !=0) 
	{
		printf("func DesEnc() err:%d\n", ret);
		return ;
	}

	//�û�ʹ�ú���des����
	ret = DesDec(pOutData, pOutDataLen, plain, &plainlen);
	if (ret !=0) 
	{
		printf("func DesDec() err:%d\n", ret);
		return ;
	}

	if (nInDataLen != plainlen)
	{
		printf("���ĳ��Ȳ�һ��\n");
		return ;
	}
	else
	{
		printf("���ĳ���һ��\n");
	}
	if (memcmp(plain, pInData, nInDataLen) == 0)
	{
		printf("����conһ��\n");
	}
	else
	{
		printf("����content ��һ��\n");
		return ;
	}

	system("pause");
}

int copyfile(char *filename1, char *filename2);

void main()
{
	int ret = 0;
	char *file1 = "c:/socketclient.dll";
	char *file2 = "c:/socketclient2222.dll";
	ret = copyfile(file1, file2);
	if (ret != 0)
	{
		printf("copyfile() :%d\n ", ret);
	}
	system("pause");
}

