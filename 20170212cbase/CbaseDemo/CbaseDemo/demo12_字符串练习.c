#include "stdio.h"
#include "stdlib.h"
#include "string.h"
//1.c��û���ַ�������������ͨ���ַ����� char buf[100] ��ģ���
//2.�ַ������ַ������������ '\0'

void  copystr_ok(char *from ,char *to){
	char *tmpfrom=from;
	char *tmpto=to;
	for(;*from != '\0';from++,to++){
		*to=*from;
	}
	*to='\0';
	printf("copystr() from :%s\n",tmpfrom);
	printf("copystr() ---to:%s\n",tmpto);
}
int main12(int arg,char *args[]){
	char buf[]={'a','b','c'};//buf ��ָ���ǳ���ָ��
	//2ָ������
	char buf2[10]={'a','b','c'};
	//3.�ַ������ַ����������
	char buf3[]={'a','b','c','\0'};
	//printf������c�⺯�������ǰ���c����ַ��������������
	//ͨ���ַ���������ʼ���ַ�������
	//ͨ�����ַ������Զ�����\0
	char buf4[]="abcdrefg";
	//strlen() ��һ���������ַ����ĳ���(�������ַ�����ĳ���)�����ĳ��Ȳ�����'\0'
	//��һ��������,���������͵�(ʵ��)�Ĵ�С
	{
		char buf[20]="aaa";
		int a=10;//������
		char buf56[]="bbb";
		char *p1="100000";
		char *p2=(char *)malloc(100);
		strcpy(p2,"dddd");
	}
	{
		char *from="abcddeee";
		char to[100]={0};
		copystr_ok(from,to);
		printf("to:%s\n",to);
	}
	printf("%s\n",buf4);
	system("pause");
	return 1;
}