#include "stdio.h"
#include "stdlib.h"
#include "string.h"
/************************************************************************/
/* 排序的算法                                                                     */
/************************************************************************/
char ** sortArray(char *pArray1,int nArrayNum,char (*parry2)[30],int nArraynum2,int *narray3num)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int leng = nArrayNum + nArraynum2;
	char tmp[30]={0};
	char **pTemp=(char **)malloc(leng*sizeof(char *));
	for (i=0; i<leng; i++)
	{
		pTemp[i] = (char *)malloc( sizeof(char) * 30);
		memset(pTemp[i] , 0 , sizeof(char) * 30);
	}
	for(i = 0; i<nArrayNum; i++){
		strcpy(pTemp[i],pArray1[i]);
	}
	for (k = 0;k<nArraynum2; i++, k++){
		strcpy(pTemp[i],parry2[k]);
	}

	for (i = 0; i<leng; i++)
	{
		for (j=i+1; j < leng; j++){
			if(strcmp(pTemp[i],pTemp[j]) > 0){
				strcpy(tmp,pTemp[i]);
				strcpy (pTemp[i],pTemp[j]);
				strcpy (pTemp[j] , tmp);
			}
		}
	}
	*narray3num = leng;

	return pTemp;
}

void free_arr(char** arr,int len){
	int i=0;
	if(arr = NULL){
		return ;
	}
	for (i=0; i <len; i++)
	{
		if (arr[i] != NULL){
			free (arr[i]);
		}
	}
	if (arr != NULL){
		free(arr);
	}
}

int main(int argc,char* argv[])
{
	int i=0;
	char **pArray3 = NULL;
	int narray3Num = 0;
	//指针数组
	char* array[]={"bbbb","aaaa","cccc"};
	//二维数组
	char array2[10][30]={"zzzz","yyyy","3333"};
	pArray3=sortArray(array,3,array2,3,&narray3Num);
	if(pArray3 == NULL){
		printf("func sortArray error \n");
	}
	for(i=0;i<narray3Num;i++){
		printf("%s",pArray3[i]);
	}
	if(pArray3 != NULL)
	{
		free_arr(pArray3,narray3Num);
		pArray3 = NULL;
	}
	system("pause");
	return 1;
}