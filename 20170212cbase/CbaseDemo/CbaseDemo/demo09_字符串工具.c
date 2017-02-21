#include "stdio.h"
#include "stdlib.h"
#include "string.h"
/************************************************************************/
/* 字符串的copy                                                                     */
/************************************************************************/

int main0902(int arg,char *args[]){
	char *p="abcslfs111lfaf111ui";
	char *ret=NULL;
	ret=strstr(p,"111");
	if(ret == NULL){
		printf("no have \n");
	}else{
		printf("找到:%s\n",ret);
	}
	system("pause");
}

int main0903(int arg,char *args[]){
	//111出现的次数
	int count=0;
	char *sub="111";
	char *p="abcslfs111lfaf111ui";
	do 
	{
		p=strstr(p,sub);
		if( p != NULL){
			count++;
			p=p+strlen(sub);
		}else{
			break;
		}
	} while (*p != '\0');

	printf("count:%d\n",count);
	system("pause");
}
int mytest(char *str,char *sub,int *cout){
	int count=0;
	char *p=str;
	if(p==NULL||sub==NULL||cout==NULL){
		return -1;
	}
	while (p=strstr(p,sub)){
		count++;
		p=p+strlen(sub);
		if(*p=='\0'){
			break;
		}
	}
	//给输出参数赋值
	*cout=count;
	return 1;
}
int main090203(int arg,char *args[]){
	//111出现的次数
	char *p="abcslfs111lfaf111ui";
	char *sub="111";
	int cout;
	mytest(p,sub,&cout);
	printf("cout:%d\n",cout);
	printf("p:%s\n",p);
	system("pause");
}