#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/************************************************************************/
/* ����ĵ�ַ                                                                     */
/************************************************************************/
//��������ͬ���͵ı��������򼯺ϲ���
//�ڴ�Ƕ���ϵ��һ��Ƭ�ڴ�ռ�
//������Ԫ�ص�ַ�������ַ��������ͬ����
//����������������Ԫ�صĵ�ַ

int main01(int arg,char *args[]){
	//������������ :�̶��ڴ���С�ı���
	typedef int(MyArrayInt10)[10];
	typedef float(MyArrayFloat10)[10];
	int i=0;
	//������a����������Ԫ�صĵ�ַ������������ĵ�ַ
	//&a ��ʾ��������ĵ�ַ,ȡ��ַ�ķ����������������
	//&a �������� ������Ԫ�ص����ͺ�����Ĵ�С��ͬ����
	int a[10]={1,2};//������ʼ��Ϊ0
	int b[]={1,2};
	int c[20]={0};
	//ʹ�ø����Ͷ������
	MyArrayInt10 inta;//�൱��int inta[5];
	MyArrayFloat10 floata;
	for (i=0;i<5;i++)
	{
		inta[i]=i+1;
	}
	for (i=0;i<5;i++)
	{
		printf("%d\n",inta[i]);
	}
	printf("inta %d\n",sizeof(inta));
	printf("&inta %d--------&inat +1:%d\n",&inta,&inta+1);
	for(i=0;i<10;i++){
		printf("%d\n",a[i]);
	}
	memset(a,0,sizeof(a));
	system("pause");
	return 1;
}
