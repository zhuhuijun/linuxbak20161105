#include "stdio.h"
#include "stdlib.h"
#include "printarr.h"
void printArrayMy(int array[], int len)
{
	int i = 0;

	for(i=0; i<len; i++)
	{
		printf("%d ", array[i]);
	}

	printf("\n");
}