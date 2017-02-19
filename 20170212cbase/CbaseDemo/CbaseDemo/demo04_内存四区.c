#include "stdio.h"
#include "stdlib.h"
#include "string.h"
//c语言的灰色地带
int g_int;
int g_int=10;
char * getString1(){
	char *p1="abcdefg";
	return p1;
}
char * getString2(){
	char *p2="abcdefg";
	return p2;
}
//在被调用函数的临时区分配的内存主调函数是不能使用的
char * getString3(){
	char  buf[100];
	memset(buf,0,sizeof(100));
	strcpy(buf,"abcdefg");
	return buf;
}
char * getString4(){
	char *d;
	d=(char *)malloc(sizeof(100));
	strcpy(d,"abcdefg");
	return d;
}
int main04(int arg,char *args[])
{
	int a=10;
	int *p;
	p=&a;
	printf("&a>>>%d\n",a);
	printf("a=%d\n",&a);
	*p=1000;
	printf("a>>>%d\n",a);
	{
		char *p=NULL;//声明变量在临时区  栈区
		p=(char *)malloc(100);//内存泄漏的概念
		if(p!=NULL){
			free(p);
		}
	}
	{
		//空指针的内存地址是不能访问的不在内存四区里面
		char **********p3=NULL;//p3是个变量
		char *p1=getString1();//指针指向谁就把谁的地址赋给指针变量
		char *p2=getString2();
		char *p4=getString3();
		char *p44=getString4();
		printf(">>>>p1:%s\n",p1);
		printf(">>>>p2:%s\n",p2);
		printf(">>>>p4:%s\n",p3);
		printf(">>>>p4:%s\n",p44);
		printf(">>>>p1地址:%d\n",p1);
		printf(">>>>p2地址:%d\n",p2);
		//指针变量和它指向的内存空间变量是不同的概念
		//	strcpy(p1,p2);
	}
	system("pause");
	return 0;
}