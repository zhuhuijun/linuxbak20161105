#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main (int arg,char *args[]){
	if(arg<2){
		printf("input param\n");
		return -1;
	}
	FILE *p=fopen(args[1],"w");
	if(p==NULL){
		printf(" error is : %s\n",strerror(errno));
	}else
	{
		printf("success\n");
		char buf[100];
		memset(buf,0,sizeof(buf));
		int i=0;
		for(;i<100;i++){
			sprintf(buf,"zhuhj>>i = %d\n",i);
			fputs(buf,p);
		}
		fclose(p);
	}
	return 0;
}
