#include "stdio.h"
#include "stdlib.h"
#include "string.h"


/*
有一个字符串符合以下特征（”abcdef,acccd,eeee,aaaa,e3eeeee,sssss,";）,要求写一个函数（接口），输出以下结果
1）	以逗号分割字符串，形成二维数组，并把结果传出；
2）	把二维数组行数运算结果也传出。
strchr(“aa,aa”,’,’ );
请自己定义一个接口（函数）。
要求1：能正确表达功能的要求，定义出接口（函数）（30分）；
要求2：正确实现接口（函数），并实现功能（40分）；
要求3：编写正确的测试用例。（30分）。
*/
int mySpitString6(const char *buf1, const char c, char buf[10][30], int *mycount)
{
	char *p = NULL;
	int count = 0;
	int ret;
	int tmpcount = 0;
	char *pTmp = NULL;
	char buf2[1024*10];
	if (buf1 == NULL || buf == NULL || mycount == NULL){
		ret=-1;
	}
	if(strlen(buf1)>1024*10-1){
		ret= -2;
		return ret;
	}
	if(buf1[strlen(buf1)] != ','){
		strcpy(buf2,buf1);
		strcat(buf2,",");
	}
	pTmp = buf2;
	p = buf2;
	do 
	{
		p = strchr(p, c);
		if (p!= NULL) //如果找到
		{
			tmpcount = p - pTmp;
			memcpy(buf[count], pTmp , tmpcount);
			buf[count][tmpcount] = '\0';
			printf("%s \n", buf[count]);
			pTmp = p = p + 1;
			count ++;
		}
		else
		{
			break;
		}
	} while (*p != '\0');
	*mycount=count;
	return 0;
}
/************************************************************************/
/* 使用第三种内存模型                                                                     */
/************************************************************************/
int mySpitString61(const char *buf1, const char c, char **buf, int *mycount)
{
	char *p = NULL;
	int count = 0;
	int ret;
	int tmpcount = 0;
	char *pTmp = NULL;
	char buf2[1024*10];
	if (buf1 == NULL || buf == NULL || mycount == NULL){
		ret=-1;
	}
	if(strlen(buf1)>1024*10-1){
		ret= -2;
		return ret;
	}
	if(buf1[strlen(buf1)] != ','){
		strcpy(buf2,buf1);
		strcat(buf2,",");
	}
	pTmp = buf2;
	p = buf2;
	do 
	{
		p = strchr(p, c);
		if (p!= NULL) //如果找到
		{
			tmpcount = p - pTmp;
			memcpy(buf[count], pTmp , tmpcount);
			buf[count][tmpcount] = '\0';
			printf("%s \n", buf[count]);
			pTmp = p = p + 1;
			count ++;
		}
		else
		{
			break;
		}
	} while (*p != '\0');
	*mycount=count;
	return 0;
}
int printArray62(char **MyArray,int iNum){
	int i=0;
	for(i=0;i<iNum;i++){
		printf("%s ",MyArray[i]);
	}
	printf("\n");
}
int main0603(int arg,char *args[]){
	char *p = "abcdef,acccd,eeee,aaaa,e3eeeee,sssss";
	char c = ',';
	char buf[10][30];
	int ncount;
	int ret;
	int i;
	char **myarr=(char **)malloc(10*(sizeof(char *)));
	if(myarr==NULL){
		return -1;
	}
	for (i=0;i<10;i++)
	{
		myarr[i]=(char *)malloc(100);
	}
	//ret = mySpitString6(p,c,buf,&ncount);
	ret = mySpitString61(p,c,myarr,&ncount);
	//ret = mySpitString1(p,c,NULL,&ncount);
	if (ret != 0){
		printf("func mySpitString1() error\n",ret);
		return ret;
	}
	printf("nocount:%d\n",ncount);
	printArray62(myarr,ncount);
	for (i=0;i<10;i++)
	{
		free(myarr[i]);
	}
	if(myarr!=NULL)
		free(myarr);

	system("pause");
	return 1;
}