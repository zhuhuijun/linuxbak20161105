#include "stdio.h"
#include "stdlib.h"
#include "string.h"
//演示栈的生长方向
//p1>p2开口向下
int main41(int arg,char *args[]){
	float *p1=NULL;
	int *p2=NULL;
	int a=0;
	int b=0;
	char buf[16];
	printf("&p1:%x,  &p2:%x,&a:%x, &b:%x \n",&p1,&p2,&a,&b);
	printf("&buf[0]:%x, &buf[2]:%x\n",&buf[0],&buf[1]);
	system("pause");
	return 1;
}
//堆得生长方向
int main05(int arg,char *args[]){
	char *p1=NULL;
	char *p2=NULL;
	p1=(char *)malloc(16);
	p2=(char *)malloc(17);
	printf("\n p1:%x p2:%x",p1,p2);
	printf("\n &p1:%x &p2:%x",&p1,&p2);
	system("pause");
	return 1;
}