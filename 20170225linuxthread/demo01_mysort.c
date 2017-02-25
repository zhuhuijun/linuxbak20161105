#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(int argc, char const *argv[])
{
	FILE *p1=fopen("a.txt","r");
	if(p1==NULL){
		printf("err is %s\n",strerror(errno) );
		return -1;
	}
	int buf[1024];
	memset(buf,0,sizeof(buf));
	char val[32];
	int len=0;
	while(1){
		memset(val,0,sizeof(val));
		if(fgets(val,sizeof(val),p1)==NULL){
			break;
		}
	}
	return 0;
}