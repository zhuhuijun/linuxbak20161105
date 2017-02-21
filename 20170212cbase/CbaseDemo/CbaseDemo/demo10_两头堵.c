#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main1001(int arg,char *args[]){
	int icount=0;
	int i=0;
	int j=0;
	char *p="            abcd          ";
	j=strlen(p)-1;
	while( isspace(p[i])  && p[i] != '\0'){
		i++;
	}
	while( isspace(p[j])  && j>0){
		j--;
	}
	icount=j-i+1;
	printf("icount=%d\n",icount);
	system("pause");
	return 1;
}
//在这种方法不推荐
int trimspace(char *p){
	int icount=0;
	int i=0;
	int j=0;
	if(p==NULL){
		return -1;
	}
	j=strlen(p)-1;
	while( isspace(p[i])  && p[i] != '\0'){
		i++;
	}
	while( isspace(p[j])  && j>0){
		j--;
	}
	icount=j-i+1;
	memcpy(p,p+i,icount);
	p[icount]='\0';
	printf("icount =%d\n",icount);
	return 0;
}
int trimspace_ok( char *mybuf,char *outbuf){
	int icount=0;
	int i=0;
	int j=0;
	char *p=NULL;
	p=mybuf;
	if(p==NULL){
		return -1;
	}
	j=strlen(p)-1;
	while( isspace(p[i])  && p[i] != '\0'){
		i++;
	}
	while( isspace(p[j])  && j>0){
		j--;
	}
	icount=j-i+1;
	memcpy(outbuf,p+i,icount);
	outbuf[icount]='\0';
	printf("icount =%d\n",icount);
	return 0;
}
int main(int arg,char *args[]){
	int ret;
	//字符串可以在 堆 栈 常量区
	char *p="            abcd          ";
	char buf2[100];
	/*
	char buf[]="            abcd          ";
	ret=trimspace(buf);//如果用p的话它指的是常量去内存块，不能修改
	if(ret!=0){
		printf("func trimspace error:code%d\n",ret);
		return;
	}
	printf("buf:%s\n",buf);
	*/

	ret=trimspace_ok(p,buf2);
		printf("buf2:%s\n",buf2);
	system("pause");
	return 1;
}