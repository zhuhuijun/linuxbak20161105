#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
//使用c语言的库函数进行文件的读取
int main (int arg,char *args[]){
	if(arg<2){
		printf("input param\n");
		return -1;
	}
	FILE *p=fopen(args[1],"a");
	if(p==NULL){
		printf(" error is : %s\n",strerror(errno));
	}else
	{
		printf("success\n");
		char buf[100];
		memset(buf,0,sizeof(buf));
		strcpy(buf,"hello,world!\n");
		fwrite(buf,strlen(buf),1,p);
		fclose(p);
	}
	return 0;
}
