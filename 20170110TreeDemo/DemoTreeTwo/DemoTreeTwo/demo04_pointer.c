#include "stdio.h"
#include "stdlib.h"

void main(int argc,char *argv[]){
	int a=10,*p=&a;
	printf("*p的值:%d\n",*p);
	{
		int b=0;
		int *pp;
		pp=&b;
		*pp=100;
		printf("b的值:%d\n",b);
	}
	printf("hello,world\n");
	system("pause");
}