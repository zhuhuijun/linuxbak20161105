#include "stdio.h"
#include "stdlib.h"
#include "string.h"
/*
1 ָ��Ҳ��һ�ֱ�����ռ���ڴ�ռ����ڱ����ڴ��ַ
2 ����ָ�����ռ���ڴ�ռ�Ĵ�С
*/
int getLen(int *p){
	*p=2000;
	return 1;
}
void update2p(char **p2){
	*p2 = 0x56;
	*p2 = (char *)malloc(100);//ԭ����ָ��NULL�����ڿ��Է���ռ���
}
int main40000(int argc,char* argv[])
{
	int a = 0;//����һ��ʵ�α���
	int *p = NULL;
	p = &a;
	*p = 200;
	getLen(p);
	printf("a=%d\n",a);
	{
		char *p = NULL;
		char **p2 = NULL;
		p = 0x11;
		p2 = &p;//p2��p�ĵ�ַ,*p2ȥ����޸�p��ֵ
		*(p2) = 0x23;
		update2p(&p);
		printf("p:%x\n",p);
	}
	printf("hello,world!\n");
	system("pause");
}