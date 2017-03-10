#include "stdio.h"
#include "stdlib.h"
#include "string.h"
/************************************************************************/
/* 排序的算法                                                                     */
/************************************************************************/
char **sortArray(char **pArray1,int nArray1Num,char (*pArray2)[30],int nArray2Num,int *nArray3Num)
{
	int i = 0;
	int j = 0;
	int k = 0;
	char tmp[30]={0};
	int leng = nArray1Num + nArray2Num;

	char **pTmp = (char **)malloc(  leng*sizeof(char *));

	for (i=0; i<leng; i++)
	{
		pTmp[i] = (char*)malloc(sizeof(char)*30);
		memset(pTmp[i], 0, sizeof(char)*30   );
	}

	for (i=0;i<nArray1Num;i++)
	{
		strcpy(pTmp[i], pArray1[i]);	
	}

	for (k = 0;k<nArray2Num; i++, k++){
		strcpy(pTmp[i],pArray2[k]);
	}

	for (i = 0; i<leng; i++)
	{
		for (j=i+1; j < leng; j++){
			if(strcmp(pTmp[i],pTmp[j]) > 0){
				strcpy(tmp,pTmp[i]);
				strcpy (pTmp[i],pTmp[j]);
				strcpy (pTmp[j] , tmp);
			}
		}
	}
	*nArray3Num = leng;

	return pTmp;
}

void free_arr(char** arr,int len){
	int i=0;
	if(arr == NULL){
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
	//指针数组
	char *array1[] = {"bbbbb", "aaaaa", "ccccc", "22222", "11111", "44444"};
	//二维数组
	char array2[10][30]={"zzzz","yyyy","3333"};
	pArray3=sortArray(array1,6,array2,3,&narray3Num);
	if(pArray3 == NULL){
		printf("func sortArray error \n");
	}
	for(i=0;i<narray3Num;i++){
		printf("%s \n",pArray3[i]);
	}
	if(pArray3 != NULL)
	{
		free_arr(pArray3,narray3Num);
		pArray3 = NULL;
	}
	system("pause");
	return 1;
}