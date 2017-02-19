#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//指针铁律2:通过*p/*p++来改变变量的值是指针存在的最大意义
//指针做函数参数
int getLen(int *p){
	*p=30;
}
int main07(int arg,char *args[]){
	int a=10;
	int *p=NULL;
	a=20;
	p=&a;//a的地址赋给p
	//getLen(int *p);
	getLen(&a);
	*p=20000;//间接赋值  如果p是a的地址，那么久间接修改a的值
	getLen(&a);
	printf("a=%d\n",a);
	{
		int c=100;
		getLen(&c);
		printf("c=%d\n",c);
	}
	system("pause");
}