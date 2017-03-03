#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/************************************************************************/
/* 数组的地址                                                                     */
/************************************************************************/
//数组是相同类型的变量的有序集合测试
//内存角度联系的一大片内存空间
//数组首元素地址和数组地址是两个不同概念
//数组名代表数组首元素的地址

int main01(int arg,char *args[]){
	//声明数组类型 :固定内存块大小的变量
	typedef int(MyArrayInt10)[10];
	typedef float(MyArrayFloat10)[10];
	int i=0;
	//数组名a代表数组首元素的地址不是整个数组的地址
	//&a 表示整个数组的地址,取地址的方法解决布长的问题
	//&a 数组类型 由数组元素的类型和数组的大小共同决定
	int a[10]={1,2};//其它初始化为0
	int b[]={1,2};
	int c[20]={0};
	//使用该类型定义变量
	MyArrayInt10 inta;//相当于int inta[5];
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
