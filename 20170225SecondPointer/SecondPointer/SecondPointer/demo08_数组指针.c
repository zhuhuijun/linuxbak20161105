#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//数组指针
int main0800000(int arg,char *args[]){
	int a;
	int *p=NULL;
	typedef int(MyArr5)[5];
	//定义一个 指向  数组类型  的  指针变量
	MyArr5 *pArray;
	{
		int j=0;
		int *pi=&j;
	}
	{
		int i=0;
		//buf[10][30]
		//a1代表数组首元素的地址不是整个数组的地址
		//a1指针变量->指针常量(常量指针)
		//结论:不能随便改变指针的指向  为甚么是const?在定义[5]时编译器为了能拿到原始的内存地址编译器就把a1做成const
		//
		int a1[5]={1,2,3,45,5};
		//给数组指针赋值
		MyArr5 *pArray=&a1;//4个字节
		//使用数组指针去遍历数组
		for (i=0;i<5;i++)
		{
			//a1[i]=i;
			(*pArray)[i]=i;
			printf("%d\n",(*pArray)[i]);
		}
		{
			//定义指向数组类型的指针变量
			//	typedef int(MyArr5_1)[5];
			//声明一个   数组指针 类型
			typedef int(*PMyArr5)[5];
			//用这个类型声明变量
			PMyArr5 myp=NULL;//4个字节
			int b[5]={6,7,8,9,0};
			myp=&b;
			for (i=0;i<5;i++)
			{
				//a1[i]=i;
				//(*pArray)[i]=i;
				printf("%d  ",(*myp)[i]);
			}
		}
		{
			int c[5]={6,7,8,9,0};
			//数组指针
			//定义一个指向数组的指针变量
			int (*myarra)[5]=&c;
			for (i=0;i<5;i++)
			{
				//a1[i]=i;
				//(*pArray)[i]=i;
				printf("%d  ",(*myarra)[i]);
			}
		}
	}
	system("pause");
}