#include "stdio.h"
#include "stdlib.h"
#include "string.h"
//1.c中没有字符串这种类型是通过字符数组 char buf[100] 来模拟的
//2.字符串和字符数组的区别是 '\0'

void  copystr_ok(char *from ,char *to){
	char *tmpfrom=from;
	char *tmpto=to;
	for(;*from != '\0';from++,to++){
		*to=*from;
	}
	*to='\0';
	printf("copystr() from :%s\n",tmpfrom);
	printf("copystr() ---to:%s\n",tmpto);
}
int main12(int arg,char *args[]){
	char buf[]={'a','b','c'};//buf 是指针是常量指针
	//2指定长度
	char buf2[10]={'a','b','c'};
	//3.字符串和字符数组的区别
	char buf3[]={'a','b','c','\0'};
	//printf函数是c库函数，就是按照c风格字符串进行输出数据
	//通过字符串常量初始化字符串数组
	//通过这种方法会自动给你\0
	char buf4[]="abcdrefg";
	//strlen() 是一个函数求字符串的长度(不是求字符数组的长度)，它的长度不包括'\0'
	//是一个操作符,求数据类型的(实体)的大小
	{
		char buf[20]="aaa";
		int a=10;//字面量
		char buf56[]="bbb";
		char *p1="100000";
		char *p2=(char *)malloc(100);
		strcpy(p2,"dddd");
	}
	{
		char *from="abcddeee";
		char to[100]={0};
		copystr_ok(from,to);
		printf("to:%s\n",to);
	}
	printf("%s\n",buf4);
	system("pause");
	return 1;
}