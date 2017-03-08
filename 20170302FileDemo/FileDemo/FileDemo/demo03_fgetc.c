/*
fgetc() fputc() //按照字符读写文件
fgets() fputs() //按照行读写文件   读写配置文件
fread() fwrite()//按照块读写文件   大数据块的迁移
//文件控制api
文件是否结束
文件指针跳转，定位
*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
//按照字符读写文件
void main01(){
	int i;
	FILE *fp = NULL;
	//linux，win通用
	char *filename="d:/1.txt";
	char a[] = "zhuhjlinqq";
	fp = fopen(filename,"a+");
	if (fp == NULL)
	{
		printf("func fopen() err\n");
		return ;
	}
	// int fputc(int ch,FILE *stream);
	for (i=0; i<strlen(a); i++)
	{
		fputc(a[i], fp);
	}
	fclose(fp);
}
void main02(){
	int i;
	FILE *fp = NULL;
	char temp;
	//linux，win通用
	char *filename="d:/1.txt";
	char a[] = "zhuhjlinqq";
	fp = fopen(filename,"a+");
	if (fp == NULL)
	{
		printf("func fopen() err\n");
		return ;
	}
	while(!feof(fp)){
		temp=fgetc(fp);
		printf("%c",temp);
	}
	fclose(fp);
	printf("\n");
}
//按照字符读写文件
int main033333333(int argc,char* argv[])
{
	main01();
	main02();
	
	system("pause");
	return 1;

}