#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//10 + 10 = 20
char **sortArray1Array2_03(char **pArray1, int nArray1Num, char (*pArray2)[30], int nArray2Num,  int *nArray3Num)
{
	//��һά
	int length=nArray1Num+nArray2Num;
	int i=0,j=0; int k = 0;

	char **pTmp = (char **)malloc(  (nArray1Num+nArray2Num)*sizeof(char *));

	for (i=0; i<length; i++)
	{
		pTmp[i] = (char*)malloc(sizeof(char)*30);
		memset(pTmp[i], 0, sizeof(char)*30   );
	}

	for (i=0;i<nArray1Num;i++)
	{
		strcpy(pTmp[i], pArray1[i]);	
	}

	for (k=0; k<nArray2Num; i++,k++)
	{
		strcpy(pTmp[i], pArray2[k]);
	}

	for (i=0;i<length;i++)
	{
		for (j=i+1;j<length;j++)
		{
			if(strcmp(pTmp[i],pTmp[j])>0)
			{
				char *t = NULL;;
				t = pTmp[i];//���������Ѿ��������ڴ�
				pTmp[i] = pTmp[j];//�ı�ָ���ָ��
				pTmp[j] = t;
			}
		}
	}
	*nArray3Num=length;

	return pTmp;

}
void free_arr03(char** arr,int length)
{
	int i=0;
	if(arr==NULL)
	{
		return ;
	}
	for(i=0;i<length;i++)
	{
		if(arr[i]!=NULL)
		{
			free(arr[i]);
		}
	}
	if(arr!=NULL)
	{
		free(arr);
	}
}
char ** mainXXXXXX(int* nn)
{

	int i = 0;
	char **pArray3 = NULL;
	int nArray3Num = 0;
	//ָ������
	char *array1[] = {"bbbbb", "aaaaa", "ccccc", "22222", "11111", "44444"};

	//��ά����
	char array2[10][30] = {"zzzz", "yyyy", "333333"};

	pArray3 = sortArray1Array2_03(array1, 6, array2, 3,  &nArray3Num);
	if (pArray3 == NULL)
	{
		printf("func sortArray1Array() err\n");
	}

	for (i=0; i<nArray3Num;i++)
	{
		printf("%s \n", pArray3[i]);
	}
	*nn = nArray3Num;
	return pArray3;

}

int main3000 (int argc, char* argv){
	int nArray3Num = 0;
	char **tm = mainXXXXXX(&nArray3Num);
	if (tm != NULL)
	{
		free_arr03(tm,nArray3Num);
		tm = NULL ;
	}
	system("pause");
	return 1;
}