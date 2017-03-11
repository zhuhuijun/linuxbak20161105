/*
1.二级指针易错模型                         

*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int getMem(char ********p8){
	*p8 = 0x98a;
}
int main(int argc, char* argv[])
{	
	char *******p7 = NULL;
	char ********p8 = NULL;
	p7 = 0x34;
	p8 = &p7;
	*p8 = 0x56;
	getMem(&p7);
	printf("%d\n",p7);
	system("pause");
	return 1;
}	