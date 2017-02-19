#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int main(int arg,char *args[])
{
		char *p1=NULL;
		char *p2=NULL;
		char buf1[100]={0};
		char buf2[100]={0};
		strcpy(buf1,"abcdefgh");
		p1=buf1;
		p2=buf2;
		while(*p1!='\0'){
			*p2=*p1;
			 p2++;
			 p1++;
		}
		{
			char *p="avv";//avv的地址是在全局区,不能被修改
			printf("p:%x",p);
			*p='s';
		}
	printf("p2:%s\n",p2);
	system("pause");
	return 1;
}