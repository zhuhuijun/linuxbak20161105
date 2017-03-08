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
void main03(){
	int i;
	FILE *fp = NULL;
	char str[100];
	//linux，win通用
	char *filename="d:/1.txt";
	char a[] = "zhuhjlinqq";

	fp = fopen(filename,"rb");
	if (fp == NULL)
	{
		printf("func fopen() err\n");
		return ;
	}
	// int fputc(int ch,FILE *stream);
	while(!feof(fp)){
		char *tt = fgets(str,10,fp);
		if(tt != NULL){
			printf("%s",str);
		}

	}
	fclose(fp);

}
void main04(){
	int i;
	FILE *fp = NULL;
	char temp;
	//linux，win通用
	char *filename="d:/1.txt";
	char a[] = "123456789";
	fp = fopen(filename,"a+");
	if (fp == NULL)
	{
		printf("func fopen() err\n");
		return ;
	}
	fputs(a,fp);
	fclose(fp);
	printf("\n");
}
//按照字符读写文件
int main400000(int argc,char* argv[])
{
	main04();
	main03();
	system("pause");
	return 1;

}