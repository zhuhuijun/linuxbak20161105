#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//ָ������2:ͨ��*p/*p++���ı������ֵ��ָ����ڵ��������
//ָ������������
int getLen(int *p){
	*p=30;
}
int main07(int arg,char *args[]){
	int a=10;
	int *p=NULL;
	a=20;
	p=&a;//a�ĵ�ַ����p
	//getLen(int *p);
	getLen(&a);
	*p=20000;//��Ӹ�ֵ  ���p��a�ĵ�ַ����ô�ü���޸�a��ֵ
	getLen(&a);
	printf("a=%d\n",a);
	{
		int c=100;
		getLen(&c);
		printf("c=%d\n",c);
	}
	system("pause");
}