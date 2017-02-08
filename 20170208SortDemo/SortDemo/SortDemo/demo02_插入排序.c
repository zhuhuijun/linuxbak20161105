#include "stdio.h"
#include "stdlib.h"
/************************************************************************/
/* 打印的方法                                                                     */
/************************************************************************/
void printArray02(int array[],int len)
{
	int i=0;
	for(;i<len;i++){
		printf("%d ",array[i]);
	}
	printf("\n");
}
/************************************************************************/
/* 插入排序的实现                                                                     */
/************************************************************************/
void InsertSort(int array[],int len){
	int i=0;
	int j=0;
	int k=-1;
	int temp=-1;
	for(i=1;i<len;i++){
		k=i;//待插入的位置
		temp=array[k];
		for(j=i-1;(j>=0)&&(array[j]>temp);j--)
		{
			array[j+1]=array[j];//元素后移
			k=j;//k需要插入的位置
		}
		array[k]=temp;
	}
}
void main02(int argc,char* argv[])
{
	int array[] = {12, 5, 433, 253, 216, 7};
	int len = sizeof(array) / sizeof(*array); 
	printArray02(array, len);
	InsertSort(array,len);
	printArray02(array,len);
	system("pause");
}