#include "stdio.h"
#include "stdlib.h"
#include "string.h"
/*
1 指针也是一种变量，占有内存空间用于保存内存地址
2 测试指针变量占有内存空间的大小
*/
int getLen(int *p){
	*p=2000;
	return 1;
}
void update2p(char **p2){
	*p2 = 0x56;
	*p2 = (char *)malloc(100);//原来是指向NULL的现在可以分配空间了
}
int main40000(int argc,char* argv[])
{
	int a = 0;//定义一个实参变量
	int *p = NULL;
	p = &a;
	*p = 200;
	getLen(p);
	printf("a=%d\n",a);
	{
		char *p = NULL;
		char **p2 = NULL;
		p = 0x11;
		p2 = &p;//p2是p的地址,*p2去间接修改p的值
		*(p2) = 0x23;
		update2p(&p);
		printf("p:%x\n",p);
	}
	printf("hello,world!\n");
	system("pause");
}