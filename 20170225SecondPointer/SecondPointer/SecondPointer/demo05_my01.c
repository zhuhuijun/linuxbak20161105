#include "stdio.h"
#include "stdlib.h"
#include "string.h"


/*
��һ���ַ�������������������abcdef,acccd,eeee,aaaa,e3eeeee,sssss,";��,Ҫ��дһ���������ӿڣ���������½��
1��	�Զ��ŷָ��ַ������γɶ�ά���飬���ѽ��������
2��	�Ѷ�ά��������������Ҳ������
strchr(��aa,aa��,��,�� );
���Լ�����һ���ӿڣ���������
Ҫ��1������ȷ��﹦�ܵ�Ҫ�󣬶�����ӿڣ���������30�֣���
Ҫ��2����ȷʵ�ֽӿڣ�����������ʵ�ֹ��ܣ�40�֣���
Ҫ��3����д��ȷ�Ĳ�����������30�֣���
*/
int mySpitString(const char *buf1, const char c, char buf[10][30], int *mycount)
{
	char *p = NULL;
	int count = 0;
	int tmpcount = 0;
	char *pTmp = NULL;
	char buf2[1024];

	pTmp = buf1;
	p = buf1;
	do 
	{
		p = strchr(p, c);
		if (p!= NULL) //����ҵ�
		{
			tmpcount = p - pTmp;
			memcpy(buf[count], pTmp , tmpcount);
			buf[count][tmpcount] = '\0';
			printf("%s \n", buf[count]);
			pTmp = p = p + 1;
			count ++;
		}
		else
		{
			break;
		}
	} while (*p != '\0');
	*mycount=count;
	return 1;
}
int printArray52(char MyArray[10][30],int iNum){
	int i=0;
	for(i=0;i<iNum;i++){
		printf("%s ",MyArray[i]);
	}
	printf("\n");
}
int main05(int arg,char *args[]){
	char *p = "abcdef,acccd,eeee,aaaa,e3eeeee,sssss,";
	char c = ',';
	char buf[10][30];
	int ncount;
	mySpitString(p,c,buf,&ncount);
	printf("nocount:%d\n",ncount);
	printArray52(buf,ncount);
	system("pause");
	return 1;
}