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
	//*��[]������,*p�൱�ڳ���Ա�ֹ����ü�Ӹ�ֵȥ�޸��ڴ�
	//[]c++������Ҳ������*
	printf("\n");
	system("pause");
}