#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int getFileContent(const char *pfilename,char *pbuf,int *pbuflen){
	if(pfilename==NULL||pbuflen==NULL){
		return -1;
	}
	if(pbuf!=NULL){
		strcpy(pbuf,"aaaaaaaaaaaaaaaaaaaaaaaaaa");
	}
	*pbuflen=100;
	return -1;
}
void main01(int argc,char *argv[]){
	char *pfilename ="c:/1.txt";
	char *pmybuf=NULL;
	int buflen=0;
	//��һ�ε����󳤶�
	getFileContent(pfilename,NULL,&buflen);
	printf("buflen: %d\n",buflen);
	//���ݳ��ȷ����ڴ�
	pmybuf=(char *)malloc(sizeof(char)*buflen);
	//
	getFileContent(pfilename,pmybuf,&buflen);
	printf("content:%s\n",pmybuf);
	printf("hello,world\n");
	system("pause");
}