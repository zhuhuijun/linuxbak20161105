#include "stdio.h"
#include "stdlib.h"
#include "string.h"
//指针做函数参数 pk 函数指针做函数参数
//回忆指针做函数参数
//2.函数指针做函数参数
//当函数指针 作为函数的参数  传递给一个被调用函数
//被调用函数就可以通过这个指针调用外部的函数这就形成了回调
int add(int a,int b);
//函数指针做函数参数
//在这个函数里面就可以通过这个函数指针，去调用外部的函数形成回调
int libfun( int (*pDis)(int a,int b) );


typedef int (*MyFunc)(int a,int b);
int libfun2(MyFunc pmyfunc,int c,int d);

void main(int argc,char *argv){
	printf("==hello,world!==\n");
	//定义函数指针
	int (*pfun)(int a ,int b);
	//函数名赋给函数指针。函数的入口地址赋给了pfun
	pfun=add;
	//
	libfun(pfun);
	libfun2(pfun,6,7);
	system("pause");
}
int add(int a,int b)
{
	return a+b;
}
//pDis是add的入口地址
int libfun(int (*pDis)(int a,int b)){
	int a,b;
	a=1;
	b=2;
	printf("==pdis的值=%d\n",pDis(a,b));
	return pDis(a,b);
}
int libfun2(MyFunc mm,int c,int d){
	
	printf("==pdis的值=%d\n",mm(c,d));
	return mm(c,d);
}
//////////////////////////////////////////////////////////////////////////
//int libfun( int (*pDis)(int a,int b) );
//第二种写法
//typedef int (*MyFunc)(int a,int b);
//int libfun2(MyFunc pmyfunc,int c,int d);