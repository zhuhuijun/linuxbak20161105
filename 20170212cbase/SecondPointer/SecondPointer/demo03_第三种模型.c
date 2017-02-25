#include "stdio.h"
#include "stdlib.h"
#include "string.h"
/************************************************************************/
/* 第三种内存模型是程序员自己打造数组指针,
二级指针做输入模型的建立*/
/************************************************************************/
int main0301(int arg,char *args[])
{
	int i;
	int j=0;
	char tmp[100];
	char  **myarr = (char **)malloc(10*sizeof(char *)); //int array[10];
	if(myarr==NULL){
		return 0;
	}
	for(i=0;i<10;i++){
		myarr[i]=(char *)malloc(100*sizeof(char));//char buf[100];
		sprintf(myarr[i],"%d%d%d",9-i,9-i,9-i);
	}
	for (i=0;i<10;i++)
	{
		printf("%s ",myarr[i]);
	}
	printf("\n");

	for(i=0;i<10;i++){
		for(j=i+1;j<10;j++){
			if(strcmp(myarr[i],myarr[j])>0){
				strcpy(tmp,myarr[i]);
				strcpy(myarr[i],myarr[j]);
				strcpy(myarr[j],tmp);
			}
		}
	}
	printf("排序之后\n");
	for (i=0;i<10;i++)
	{
		printf("%s ",myarr[i]);
	}
	printf("\n");

	for (i=0;i<10;i++)
	{
		free(myarr[i]);
	}
	if(myarr!=NULL)
		free(myarr);
	system("pause");
	return 1;
}
/************************************************************************/
/* 打印功能                                                                     */
/************************************************************************/
int printArray3(char **MyArray,int iNum){
	int i=0;
	for(i=0;i<iNum;i++){
		printf("%s ",MyArray[i]);
	}
	printf("\n");
}
/************************************************************************/
/* 排序方法                                                                     */
/************************************************************************/
int sortArray3(char **MyArray,int iNum){
	int i=0;
	int j=0;
	char *tmp=NULL;
	for(i=0;i<iNum;i++){
		for(j=i+1;j<iNum;j++){
			if(strcmp(MyArray[i],MyArray[j])>0){
				//我们修改的是数组元素,只不过元素特殊一点,他是指针变量
				//指针变量和它指向的内存空间变量是两个不同概念
				tmp = MyArray[i];
				MyArray[i] = MyArray[j];
				MyArray[j] = tmp;
			}
		}
	}
}
int main0302(int arg,char *args[])
{
	int i;
	int j=0;
	char tmp[100];
	char  **myarr = (char **)malloc(10*sizeof(char *)); //int array[10];
	if(myarr==NULL){
		return 0;
	}
	for(i=0;i<10;i++){
		myarr[i]=(char *)malloc(100*sizeof(char));//char buf[100];
		sprintf(myarr[i],"%d%d%d",9-i,9-i,9-i);
	}
	printf("排序之前\n");
	printArray3(myarr,10);

	sortArray3(myarr,10);
	printf("排序之后\n");
	printArray3(myarr,10);

	for (i=0;i<10;i++)
	{
		free(myarr[i]);
	}
	if(myarr!=NULL)
		free(myarr);
	system("pause");
	return 1;
}