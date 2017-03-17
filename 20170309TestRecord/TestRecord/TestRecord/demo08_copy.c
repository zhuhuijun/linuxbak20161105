#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void copyStr2(char *from,char *to)
{
	for(;*from != '\0';from ++,to++){
		*to = *from;
	}
	*to = '\0';
}
void copyStr3(char *from,char **to)
{
	*to = from;
}

int main8044ffs(int argc,char* argv[])
{
	char from[100] = {0};
	char to[100] ={0};
	char *to2 = NULL;
	strcpy(from,"fromaaa");
	copyStr2(from,to);
	printf("from:%s\n",from);
	printf("to:%s\n",to);
	copyStr3(from,&to2);
	printf("to2:%s\n",to2);
	system("pause");
	return 1;
}