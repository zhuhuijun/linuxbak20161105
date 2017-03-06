#include "stdio.h"
#include "stdlib.h"
#include "string.h"
void myfree(char *p2)
{
	if(p2 != NULL){
		free(p2);
		p2=NULL;//指针变量和它指向的内存空间
	}
}
void myfree2(char **p2)
{
	char *tmp=*p2;
	if(tmp != NULL){
		free(tmp);
		tmp=NULL;//指针变量和它指向的内存空间
	}
	*p2=NULL;
}
int main005555(int argc,char* args[]){
	char *p=NULL;
	p=(char *)malloc(100);
	myfree2(&p);
	if(p != NULL){
		free(p);//释放p所指的内存空间
		//指针变量和它所指的内存空间变量是两个概念
		p=NULL;
	}

	//省略500行.....


	if(p != NULL){
		free(p);
		p=NULL;
	}
	system("pause");
}