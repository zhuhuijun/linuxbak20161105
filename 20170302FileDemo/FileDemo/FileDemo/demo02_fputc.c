/*
fgetc() fputc() //�����ַ���д�ļ�
fgets() fputs() //�����ж�д�ļ�   ��д�����ļ�
fread() fwrite()//���տ��д�ļ�   �����ݿ��Ǩ��
//�ļ�����api
�ļ��Ƿ����
�ļ�ָ����ת����λ
*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//�����ַ���д�ļ�
int main022222(int argc,char* argv[])
{
	int i;
	FILE *fp = NULL;
	//linux��winͨ��
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
	system("pause");
	return 1;

}