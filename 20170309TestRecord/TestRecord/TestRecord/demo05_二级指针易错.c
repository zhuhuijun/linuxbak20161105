/*
1.����ָ���״�ģ��                         

*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void getMem3(char **p){
	char *tmp = NULL;
	tmp = (char *)malloc(100);
	strcpy(tmp,"ssss");
	*p = tmp;
}
int main6735000(int argc, char* argv[])
{
	//char buf[100];
	char *buf =NULL;
	getMem3(&buf);//�����const ָ�벻��
	printf("%s\n",buf);
	if(buf != NULL)
	{
		free(buf);
	}
	system("pause");
}	