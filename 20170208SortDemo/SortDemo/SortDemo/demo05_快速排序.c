#include "stdio.h"
#include "stdlib.h"
#include "printarr.h"
/************************************************************************/
/* ����Ԫ��                                                                     */
/************************************************************************/
void swap5(int array[], int i, int j)
{
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}
/************************************************************************/
/* ���pv��ֵ                                                                     */
/************************************************************************/
int partition(int array[], int low, int high)
{
	int pv = array[low];

	while( low < high )
	{
		while( (low < high) && (array[high] >= pv) )
		{
			high--; //�Ȼ�׼�󣬱��������ұߣ�����highǰ�ƶ�
		}
		swap5(array, low, high);
		while( (low < high) && (array[low] <= pv) )
		{
			low++;
		}
		swap5(array, low, high);
	}

	return low;
}

void QSort(int array[], int low, int high)
{
	if( low < high )
	{
		//���pv��ֵ
		int pivot = partition(array, low, high);
		QSort(array, low, pivot-1);
		QSort(array, pivot+1, high);
	}
}

void QuickSort(int array[], int len) // O(n*logn)
{
	QSort(array, 0, len-1);
}
/************************************************************************/
/* �����������                                                                     */
/************************************************************************/
int main05(int argc,char* argv[])
{
	int array[] = {12, 5, 433, 253, 216, 7};
	int len = sizeof(array) / sizeof(*array); 
	printArrayMy(array, len);
	QuickSort(array, len);
	printArrayMy(array, len);
	system("pause");
	return 0;
}
