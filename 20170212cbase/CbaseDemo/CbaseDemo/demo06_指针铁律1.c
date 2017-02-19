#include "stdio.h"
#include "stdlib.h"
#include "string.h"
//指针是一种数据类型
//1.指针也是一种变量占有内存空间用来保存内存地址
//2.*p操作指针
//在指针声明时,*表示所声明的变量为指针
//在指针使用时,*号表示 操作 指针所指向内存空间的值
//3.指针变量和它指向的内存块是两个不同的概念
//3.1给p赋值 p=0x0011;只会改变指针变量的值（指针指向的值）
//不会改变所指的内容
//3.2 *p='a'；不会改变指针变量的值，只会改变所指内存块的值
//4.指针也是一种数据类型,指针的数据类型是指它指向的内存空间的数据类型
//char *p1是形参 是变量
//形参只不过是提供了对外访问的属性
void getData01(char *p1){
	printf("getData01() beign>>>>>\n");
}
//cahr *pp2 是形参 是变量
void getData02(char **p2){
	printf("getData02() beign>>>>>\n");
}
//对指针参数的理解
//从编译器的角度理解:对形参如果是指针类型,编译器只会分配四个自己的内存
void sendData(char *p1);
int main06fgg(int arg,char *args[])
{
	char *p1=NULL;
	char **p2=NULL;
	int a=10;
	//在指针声明时,*p表示所声明的变量为指针
	int *p3=NULL;
	int c=0;
	a=20;//直接通过变量修改值
	p3=&a;
	//*p放在等号的左边去修改内存空间的值
	*p3=30;//通过指针间接修改内存空间的值
	//*p放在等号的右边
	c=*p3;//从内存空间里取值
	printf("p1的大小:%d\n",sizeof(p1));
	printf("p2的大小:%d\n",sizeof(p2));
	{
		//*p的意义:*就像一把钥匙，根据一个指针变量的值，修改门后面的内存空间
		//char *p2=0x0077;
		//*p2=100;
	}
	//3.1
	{
		char *p1=NULL;
		char *p2=NULL;
		char buf1[100]={0};
		char buf2[100]={0};
		strcpy(buf1,"abcdefgh");
		p1=buf1;
		while(*p1!='\0'){
			*p2=*p1;
			 p2++;
			 p1++;
		}
		//buf2=*p2;
		//printf("%s",buf2);
	}
	system("pause");
	return 1;
}