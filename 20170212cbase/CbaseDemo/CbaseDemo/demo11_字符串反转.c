#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main11(int arg,char *args[])
{
	//char *str="abcdefghijk";
	char str[]="abcdefghijk";
	char c;
	int len=strlen(str);
	char *p1=str;
	char *p2=str+len-1;
	while(p1<p2){
		c=*p1;
		*p1=*p2;
		*p2=c;
		p1++;
		p2--;
	}
	printf("str===:%s\n",str);
	system("pause");
	return 1;
}