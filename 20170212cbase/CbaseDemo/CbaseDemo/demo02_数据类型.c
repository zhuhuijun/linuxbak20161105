#include "stdio.h"
#include "stdlib.h"
#include "string.h"
//���������ǹ̶���С�ڴ��ı���,typedef ���Զ��������ͽ���������,ȡһ������
//������һ�������ڴ�ռ�ı���,������һ�����
typedef int u32;
int main02(int arg,char *args[])
{
	int a[10]={1,2,3,4,5,6,7,8,9};
	printf("a�ĵ�ַ:>>>>%d\n",a);
	printf("&a�ĵ�ַ:>>>%d\n",&a);
	printf("a+1>>>>>>%d\n",a+1);
	printf("&a+1>>>>>%d\n",&a+1);
	printf("int �Ĵ�С:%d",sizeof(u32));
	system("pause");
}