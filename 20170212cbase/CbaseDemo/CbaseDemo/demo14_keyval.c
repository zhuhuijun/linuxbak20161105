#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int trimspace_ok2( char *mybuf,char *outbuf){
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
int getKeyByValude(char *keyvaluebuf /*in*/,  char *keybuf  /*in*/,  
	char *valuebuf /*in out*/, int * valuebuflen /*in out*/)
{
	char tmp[2048*10];
	int rv=0;
	char *p=NULL;
	//查关键字
	p=strstr(keyvaluebuf,keybuf);
	if(p==NULL){
		return 0;
	}
	p=p+strlen(keybuf);
	//查等号
	p=strstr(keyvaluebuf,"=");
	if(p==NULL){
		return 0;
	}
	p=p+1;
	//去左右空格
	rv=trimspace_ok2(p,tmp);
	//trimspace_ok2(p,valuebuf);
	if(rv!=0){
		printf("trimspace_ok2 error:%s\n",rv);
		return rv;
	}
	*valuebuflen=strlen(tmp);
	strcpy(valuebuf,tmp);
	return 0;
}

int main(int arg,char *args[]){
	char keyvalbuf[]="oraclename=itcast";
	char *keybuf="oraclename";
	char valbuf[1024]={0};
	int vallen=0;
	int rv=0;
	rv=getKeyByValude(keyvalbuf,keybuf,valbuf,&rv);
	if(rv!=0){
		printf("getKeyByValude() error:%d\n",rv);
		return 0;
	}
	printf("valbuf:%s\n",valbuf);
	system("pause");
	return 1;
}