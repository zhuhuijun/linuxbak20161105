#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int mainiu(int arg,char *args[])
{
	char *p1=NULL;
	char *p2=NULL;
	char buf1[100]={0};
	char buf2[100]={0};
	strcpy(buf1,"abcdefgh");
	p1=buf1;
	p2=buf2;
	while(*p1!='\0'){
		*p2=*p1;
		p2++;
		p1++;
	}
	{
		char *p="avv";//avv�ĵ�ַ����ȫ����,���ܱ��޸�
		printf("p:%x\n",p);
		//*p='s';
	}
	{
		int a=10;
		int *p=NULL;
		p=&a;
		*p=100;
		//p��˭��ֵ*p�ͼ��ȥ�޸�˭��ֵ
	}
	{
		char *p="abcdfggg";
		printf("p:%x\n",p);
		//char c='s';
		p="h";//��a�ĵ�ַ��������
		printf("p:%x\n",p);
	}
	{
		//��NULL�ռ�д���ݶ�����
		//char *p=NULL;
		//*p=100;
	}
	{
		//char *p=NULL;
		//strcpy(p,"abcde");

	}
	printf("p2:%s\n",p2);
	{
		char buf3[20]={0};
		int i=0;
		char *p=NULL;
		strcpy(buf3,"123456789098764");
		p=&buf3[0];
		p=&buf3[1];
		p=&buf3[2];
		p=&buf3[3];
		for(;i<10;i++){
			p=&buf3[i];
			printf("p:%s\n",p);
		}
	}

	system("pause");
	return 1;
}