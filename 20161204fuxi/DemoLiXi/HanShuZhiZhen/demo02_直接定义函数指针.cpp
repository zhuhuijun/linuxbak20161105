#include "stdio.h"
#include "stdlib.h"
#include "string.h"
//������Ҫ�����ƺ�������ֵ
//c����ͨ��typedefine Ϊ���ͽ���������
//����ָ������ָ��һ������
//��������ִ�к�������ڵ�ַ
//����ͨ���������Ͷ��庯��ָ��
//Ҳ����ֱ�Ӷ���
int array2[10];
//����һ����������
typedef int (ArrayType)[10];
//����һ��ָ�������   ����ָ������
typedef int (*PArrayType)[10]; //int *;
//����һ����������
typedef int Func(int);
//����һ��ָ�������͵�ָ������
typedef int (*MyFunc)(int);
//MyFunc aa;
//�������ƴ���������� ,�������Ʊ������һ����ַ
int test(int a){
	return a*a;
}
void f(){
	printf("ִ����f...........\n");
}
void main02(int argc,char *argv[])
{
	int ret=0;
	{
		//�ú������Ͷ���һ������ָ��
		Func *func=NULL;
		//func=test;
		//*	(*(*test));
		func=&test;//�Ժ���0ȡ��ַ�Ͳ�ȡ��ַ��һ����
		//ͨ������ָ��(��������ڵ�ַ)����ָ������ַ������֮����Խ��к�������
		ret=func(6);
		printf("myret=============%d\n",ret);
	}
	{
		void (*myf)()=f;
		void (*myf2)()=&f;
		myf2();
		myf();
	}
	printf("hello,world!\n");
	system("pause");
}