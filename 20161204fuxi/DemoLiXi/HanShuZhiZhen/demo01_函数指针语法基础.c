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
//�������ƴ���������� ,�������Ʊ������һ����ַ
int test(int a){
	return a*a;
}
void main01(int argc,char *argv[])
{
	//���������Ͷ������
	ArrayType array;//int array2[10];
	int ret=0;
	array[0]=10;
	{
		//������ָ������   ȥ����һ��ָ��
		PArrayType arrayp;
		arrayp=&array;
		(*arrayp)[0]=100;
	}
	{
		//ֱ�Ӷ���һ��ָ���������͵�ָ��
		int (*pMyArray)[10]=&array;
		(*pMyArray)[0]=300;
	}
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
	printf("hello,world!\n");
	system("pause");
}