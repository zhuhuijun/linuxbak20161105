#include "stdio.h"
#include "stdlib.h"
#include "string.h"


int main0101(int arg,char *args[]){
	int i = 0, j = 0;
	char *tmp = NULL;

	char *MyArray[] = {"ccccc", "aaaa", "bbbb","11111"};

	for (i=0; i<4; i++)
	{
		printf("%s  ", MyArray[i]);
	}
	printf("\n");
	for (i=0; i<4; i++)
	{
		for (j=i+1; j<4; j++)
		{
			if (strcmp(MyArray[i],MyArray[j]) > 0)
			{
				tmp = MyArray[i];
				MyArray[i] = MyArray[j];
				MyArray[j] = tmp;
			}
		}
	}

	for (i=0; i<4; i++)
	{
		printf("%s   ", MyArray[i]);
	}
	printf("\n");
	system("pause");
	return 1;
}