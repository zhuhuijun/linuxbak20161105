#include "stdio.h"
#include "stdlib.h"
#include "string.h"
void myfree(char *p2)
{
	if(p2 != NULL){
		free(p2);
		p2=NULL;//ָ���������ָ����ڴ�ռ�
	}
}
void myfree2(char **p2)
{
	char *tmp=*p2;
	if(tmp != NULL){
		free(tmp);
		tmp=NULL;//ָ���������ָ����ڴ�ռ�
	}
	*p2=NULL;
}
int main005555(int argc,char* args[]){
	char *p=NULL;
	p=(char *)malloc(100);
	myfree2(&p);
	if(p != NULL){
		free(p);//�ͷ�p��ָ���ڴ�ռ�
		//ָ�����������ָ���ڴ�ռ��������������
		p=NULL;
	}

	//ʡ��500��.....


	if(p != NULL){
		free(p);
		p=NULL;
	}
	system("pause");
}