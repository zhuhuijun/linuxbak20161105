#include "stdio.h"
#include "stdlib.h"
#include "string.h"
//ָ������������ pk ����ָ������������
//����ָ������������
//2.����ָ������������
//������ָ�� ��Ϊ�����Ĳ���  ���ݸ�һ�������ú���
//�����ú����Ϳ���ͨ�����ָ������ⲿ�ĺ�������γ��˻ص�
int add(int a,int b);
//����ָ������������
//�������������Ϳ���ͨ���������ָ�룬ȥ�����ⲿ�ĺ����γɻص�
int libfun( int (*pDis)(int a,int b) );
void main(int argc,char *argv){
	printf("=========================hello,world!============================\n");
	//���庯��ָ��
	int (*pfun)(int a ,int b);
	//��������������ָ�롣��������ڵ�ַ������pfun
	pfun=add;
	//
	libfun(pfun);
	system("pause");
}
int add(int a,int b)
{
	return a+b;
}
//pDis��add����ڵ�ַ
int libfun(int (*pDis)(int a,int b)){
	int a,b;
	a=1;
	b=2;
	printf("pdis====================%d\n",pDis(a,b));
	return pDis(a,b);
}