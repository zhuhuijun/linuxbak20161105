#include "stdio.h"
#include "stdlib.h"
#include "string.h"
char * mergerZ(char *x,char *y)
{
	char *str=(char *)malloc(100);
	char *z=str;//指针z指向数组str3
	while(*z++=*x++);
	z--;
	while(*z++=*y++);
	z=str;//将str3的地址赋给指针z
	return (z);
}

int main13333(int arg,char *args[]){
	char *x="xxxxxx";
	char *y="yyyyyyyyyyy";
	char *z=mergerZ(x,y);
	printf("z=%s\n",z);
	system("pause");
	return 1;
}