#include "stdio.h"
#include "stdlib.h"
#include "string.h"
//c���ԵĻ�ɫ�ش�
int g_int;
int g_int=10;
char * getString1(){
	char *p1="abcdefg";
	return p1;
}
char * getString2(){
	char *p2="abcdefg";
	return p2;
}
//�ڱ����ú�������ʱ��������ڴ����������ǲ���ʹ�õ�
char * getString3(){
	char  buf[100];
	memset(buf,0,sizeof(100));
	strcpy(buf,"abcdefg");
	return buf;
}
char * getString4(){
	char *d;
	d=(char *)malloc(sizeof(100));
	strcpy(d,"abcdefg");
	return d;
}
int main04(int arg,char *args[])
{
	int a=10;
	int *p;
	p=&a;
	printf("&a>>>%d\n",a);
	printf("a=%d\n",&a);
	*p=1000;
	printf("a>>>%d\n",a);
	{
		char *p=NULL;//������������ʱ��  ջ��
		p=(char *)malloc(100);//�ڴ�й©�ĸ���
		if(p!=NULL){
			free(p);
		}
	}
	{
		//��ָ����ڴ��ַ�ǲ��ܷ��ʵĲ����ڴ���������
		char **********p3=NULL;//p3�Ǹ�����
		char *p1=getString1();//ָ��ָ��˭�Ͱ�˭�ĵ�ַ����ָ�����
		char *p2=getString2();
		char *p4=getString3();
		char *p44=getString4();
		printf(">>>>p1:%s\n",p1);
		printf(">>>>p2:%s\n",p2);
		printf(">>>>p4:%s\n",p3);
		printf(">>>>p4:%s\n",p44);
		printf(">>>>p1��ַ:%d\n",p1);
		printf(">>>>p2��ַ:%d\n",p2);
		//ָ���������ָ����ڴ�ռ�����ǲ�ͬ�ĸ���
		//	strcpy(p1,p2);
	}
	system("pause");
	return 0;
}