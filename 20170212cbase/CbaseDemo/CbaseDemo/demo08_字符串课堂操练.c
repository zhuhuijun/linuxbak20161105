#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int main08(int arg,char *args[]){
	int i=0;
	char buf[100]="abcdefg";
	char *p=NULL;
	for(;i<strlen(buf);i++){
		printf("%c",buf[i]);
	}
		printf("\n");
	p=buf;
	for(i=0;i<strlen(buf);i++){
		printf("%c",p[i]);
	}
	printf("\n");
	for(i=0;i<strlen(buf);i++){
		printf("%c",*(p+i));
	}
	//*和[]的区别,*p相当于程序员手工利用间接赋值去修改内存
	//[]c++编译器也会编译成*
	printf("\n");
	system("pause");
}