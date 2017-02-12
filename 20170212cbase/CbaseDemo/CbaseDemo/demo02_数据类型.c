#include "stdio.h"
#include "stdlib.h"
#include "string.h"
//数据类型是固定大小内存块的别名,typedef 可以对数据类型进行重命名,取一个别名
//变量是一段连续内存空间的别名,变量是一个标号
typedef int u32;
int main02(int arg,char *args[])
{
	int a[10]={1,2,3,4,5,6,7,8,9};
	printf("a的地址:>>>>%d\n",a);
	printf("&a的地址:>>>%d\n",&a);
	printf("a+1>>>>>>%d\n",a+1);
	printf("&a+1>>>>>%d\n",&a+1);
	printf("int 的大小:%d",sizeof(u32));
	system("pause");
}