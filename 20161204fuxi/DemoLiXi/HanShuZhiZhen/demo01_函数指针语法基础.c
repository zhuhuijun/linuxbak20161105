#include "stdio.h"
#include "stdlib.h"
#include "string.h"
//函数三要素名称函数返回值
//c语言通过typedefine 为类型进行重命名
//函数指针用于指向一个函数
//函数名是执行函数的入口地址
//可以通过函数类型定义函数指针
//也可以直接定义
int array2[10];
//定义一个数组类型
typedef int (ArrayType)[10];
//定义一个指向数组的   数组指针类型
typedef int (*PArrayType)[10]; //int *;
//定义一个函数类型
typedef int Func(int);
//函数名称代表函数的入口 ,函数名称本身就是一个地址
int test(int a){
	return a*a;
}
void main01(int argc,char *argv[])
{
	//由数组类型定义变量
	ArrayType array;//int array2[10];
	int ret=0;
	array[0]=10;
	{
		//用数组指针类型   去定义一个指针
		PArrayType arrayp;
		arrayp=&array;
		(*arrayp)[0]=100;
	}
	{
		//直接定义一个指向数组类型的指针
		int (*pMyArray)[10]=&array;
		(*pMyArray)[0]=300;
	}
	{
		//用函数类型定义一个函数指针
		Func *func=NULL;
		//func=test;
		//*	(*(*test));
		func=&test;//对函数0取地址和不取地址是一样的
		//通过函数指针(函数的入口地址)可以指向函数地址。言外之意可以进行函数调用
		ret=func(6);
		printf("myret=============%d\n",ret);
	}
	printf("hello,world!\n");
	system("pause");
}