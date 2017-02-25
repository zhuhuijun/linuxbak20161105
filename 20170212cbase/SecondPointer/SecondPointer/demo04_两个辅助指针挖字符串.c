#include "stdio.h"
#include "stdlib.h"
#include "string.h"


/*
    有一个字符串符合以下特征（”abcdef,acccd,eeee,aaaa,e3eeeee,sssss,";）,要求写一个函数（接口），输出以下结果
	1）	以逗号分割字符串，形成二维数组，并把结果传出；
	2）	把二维数组行数运算结果也传出。
	strchr(“aa,aa”,’,’ );
    请自己定义一个接口（函数）。
	要求1：能正确表达功能的要求，定义出接口（函数）（30分）；
	要求2：正确实现接口（函数），并实现功能（40分）；
	要求3：编写正确的测试用例。（30分）。
*/
int spitString(const char *buf1, const char c, char buf[10][30], int *mycount)
{
	char *p = NULL;
	int count = 0;
	int tmpcount = 0;
	char *pTmp = NULL;
	char buf2[1024];

	pTmp = buf1;
	p = buf1;
	do 
	{
		p = strchr(p, c);
		if (p!= NULL) //如果找到
		{
			tmpcount = p - pTmp;
			memcpy(buf[count], pTmp , tmpcount);
			buf[count][tmpcount] = '\0';
			printf("%s \n", buf[count]);
			pTmp = p = p + 1;
			count ++;
		}
		else
		{
			break;
		}
	} while (*p != '\0');
	*mycount=count;
}
int main(int arg,char *args[]){
	char *p = "abcdef,acccd,eeee,aaaa,e3eeeee,sssss,";
	char c = ',';
	char buf[10][30];
	int ncount;
	spitString(p, c, buf, &ncount);
	printf("nocount:%d\n",ncount);
	system("pause");
	return 1;
}