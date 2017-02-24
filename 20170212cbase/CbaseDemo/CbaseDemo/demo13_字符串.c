#include "stdio.h"
#include "stdlib.h"
#include "string.h"

char * str_cnct(char *x,char *y){
	char *str3=(char *)malloc(80);
	char *z=str3;//指针z指向数组str3
	while(*z++=*x++);
	z--;//去掉结尾的字符
	while(*z++=*y++);
	z=str3;//把str3初始化的的地址赋给指针变量
	return z;
}

int main13(int arg,char *args[]){
	char *a="aaa";
	char *b="bbb";
	char *c=str_cnct(a,b);
	printf("c:%s\n",c);
	if(c!=NULL){
		free(c);
		c=NULL;
	}
	system("pause");
	return 1;
}