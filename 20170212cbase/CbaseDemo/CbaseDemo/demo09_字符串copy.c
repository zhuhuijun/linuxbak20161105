#include "stdio.h"
#include "stdlib.h"
#include "string.h"
/************************************************************************/
/* 字符串的copy                                                                     */
/************************************************************************/
int copy_str2(char *from ,char *to){
	int ret = 0;
	if (from ==NULL || to== NULL)
	{
		ret = -1;
		printf("func copy_str2() err: %d, (from ==NULL || to== NULL)", ret);
		return ret;
	}

	for (; *from!='\0'; from ++, to++ )
	{
		*to = *from;
	}
	*to = '\0';
	return ret;
}
void copy_str3(char *from ,char *to){
	while(*from!='\0'){
		*to=*from;
		from++;
		to++;
	}
	*to='\0';
}
int  copy_str4(char *from ,char *to){
	if(from==NULL||to==NULL){
		return -1;
	}
	while(*from!='\0'){
		//后缀++的优先级高于*p
		*to++=*from++;
	}
	*to='\0';
}

void copy_str5(char *from ,char *to){
	while((	*to++=*from++)!='\0'){
		;
	}
}
int main09(int arg,char *args[]){
	int rv = 0;
	char from[100]={0};
	char to[100]={0};
	char to1[100]={0};
	strcpy(from,"fromaaaaabc");
	rv = copy_str2(from, to);
	if (rv != 0)
	{
		printf("func copy_str2:%d", rv);
		return ;
	}
	copy_str5(from,to1);
	printf("%s\n",to);
	printf("%s\n",to1);
	system("pause");
}