#include "stdio.h"
#include "stdlib.h"
/************************************************************************/
/* ��ӡ�ĺ���                                                                     */
/************************************************************************/
void println(int array[],int len){
	int i = 0;

	for(i=0; i<len; i++)
	{
		printf("%d ", array[i]);
	}

	printf("\n");
}
/************************************************************************/
/* ����ֵ�ú���                                                                     */
/************************************************************************/
void swap(int array[],int i,int j){
	int temp=array[i];
	array[i]=array[j];
	array[j]=temp;
}
/************************************************************************/
/* ϣ������                                                                     */
/************************************************************************/
void ShellSort(int array[],int len){
	int i=0;
	int j=0;
	int k=-1;
	int temp=-1;
	int gap=len;
	do{
		//ҵ��ͳһʵ���ƽ��������
		gap=gap/3+1;
		for(i=gap;i<len;i+=gap){
			k=i;
			temp=array[k];
			for(j=i-gap;(j>=0)&&(array[j]>temp);j-=gap){
				array[j+gap]=array[j];
				k=j;
			}
			array[k]=temp;
		}
	}while(gap>1);

}
/************************************************************************/
/* �����������                                                                     */
/************************************************************************/
void main04(int argc,char* argv[]){
	int array[] = {12, 5, 433, 253, 216, 7};
	int len = sizeof(array) / sizeof(*array); 

	println(array, len);
	ShellSort(array, len);
	println(array, len); 
	system("pause");
}