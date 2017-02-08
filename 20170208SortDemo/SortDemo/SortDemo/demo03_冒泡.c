#include "stdio.h"
#include "stdlib.h"
#include "string.h"
void printfArray03(int array[], int len)
{
	int i = 0;

	for(i=0; i<len; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

void swap03(int array[], int i, int j)
{
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

void BubbleSort(int array[], int len) // O(n*n)
{
	int i = 0;
	int j = 0;
	int exchange = 1; //���������Ƿ��Ѿ��ź��� �Ѿ��ź���Ϊ0   1��ʾû���ź���
	for(i=0; (i<len) && exchange; i++)
	{
		exchange = 0;//��Ϊ�Ѿ��������
		for(j=len-1; j>i; j--)
		{
			if( array[j] < array[j-1] )
			{
				swap03(array, j, j-1);
				exchange = 1;//
			}
		}
	}
}

int main03()
{
	int array[] ={8,3,6,1};
	int len = sizeof(array) / sizeof(*array); 
	printfArray03(array, len);
	BubbleSort(array, len);
	printfArray03(array, len);
	system("pause");
	return 0;
}