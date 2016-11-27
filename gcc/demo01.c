#include <stdio.h>
#include <stdlib.h>
int main(int arg,char *args[])
{
	if(arg<3)
		printf("请输入两个参数\n");
	
	else{
		int a=atoi(args[1]);
		int b=atoi(args[2]);
		printf("%d加%d等于%d\n",a,b,a+b );
	}
	return 0;
}