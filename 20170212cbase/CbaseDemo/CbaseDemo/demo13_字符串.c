#include "stdio.h"
#include "stdlib.h"
#include "string.h"

char * str_cnct(char *x,char *y){
	char *str3=(char *)malloc(80);
	char *z=str3;//ָ��zָ������str3
	while(*z++=*x++);
	z--;//ȥ����β���ַ�
	while(*z++=*y++);
	z=str3;//��str3��ʼ���ĵĵ�ַ����ָ�����
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