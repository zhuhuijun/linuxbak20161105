#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
 struct Person{
	int id;
	char name[20];
	int age;
	int sex;
	char tel[20];
};
/*
//写文件的方法
//使用c语言的库函数进行文件的读取
int main (int arg,char *args[]){
	if(arg<2){
		printf("input param\n");
		return -1;
	}
	//windows下用wb
	FILE *p=fopen(args[1],"w");
	if(p==NULL){
		printf(" error is : %s\n",strerror(errno));
	}else
	{
		printf("success\n");
		struct Person man[10];
		int j=0;
		memset(&man,0,sizeof(man));
		for(j=0;j<10;j++){
			man[j].id=j;
			strcpy(man[j].name,"name");
			man[j].sex=1;
			strcpy(man[j].tel,"1234444");
		}
		fwrite(&man,sizeof(struct Person),10,p);
		fclose(p);
	}
	return 0;
}
*/
//读文件的方法fread和fwrite读写二进制文件比较方便
//读写文本文件不是太方便
int main (int arg,char *args[]){
	if(arg<2){
		printf("input param\n");
		return -1;
	}
	FILE *p=fopen(args[1],"rb");
	if(p==NULL){
		printf(" error is : %s\n",strerror(errno));
	}else
	{
		printf("success\n");
		struct Person man;
		int j=0;
		memset(&man,0,sizeof(man));

		while(fread(&man,sizeof(struct Person),1,p)){
			printf("id:%d\n",man.id);
			printf("name:%s\n",man.name);
			printf("age:%d\n",man.age);
			printf("tel:%s\n",man.tel);		
		}
		fclose(p);
	}
	return 0;
}