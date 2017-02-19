#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main03(int arg,char *args[])
{
	int a=10;
	int *p;
	p=&a;
	printf("&a>>>%d",a);
	printf("%d\n",&a);
	*p=1000;
	printf("a>>>%d",a);
	system("pause");
	return 0;
}