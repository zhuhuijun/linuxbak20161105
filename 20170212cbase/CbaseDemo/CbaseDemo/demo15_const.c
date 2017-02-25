#include "stdio.h"
#include "stdlib.h"
#include "string.h"



int main15(int arg,char *args[]){
	const int a=10;//const 和下面的意义一样
	int const b=11;

	const int *c;//修改的内存空间不能被写但是可以读
	int * const d;//指针不能改变指向修饰的是指针，常量指针
	const int * const e;
	system("pause");
}