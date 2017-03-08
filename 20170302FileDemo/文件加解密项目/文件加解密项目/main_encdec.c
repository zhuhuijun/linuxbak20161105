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


	//用户使用的函数
	ret = DesEnc(pInData, nInDataLen, pOutData, &pOutDataLen);
	if (ret !=0) 
	{
		printf("func DesEnc() err:%d\n", ret);
		return ;
	}

	//用户使用函数des解密
	ret = DesDec(pOutData, pOutDataLen, plain, &plainlen);
	if (ret !=0) 
	{
		printf("func DesDec() err:%d\n", ret);
		return ;
	}

	if (nInDataLen != plainlen)
	{
		printf("明文长度不一致\n");
		return ;
	}
	else
	{
		printf("明文长度一致\n");
	}
	if (memcmp(plain, pInData, nInDataLen) == 0)
	{
		printf("明文con一致\n");
	}
	else
	{
		printf("明文content 不一致\n");
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

