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
void main03(){
	int i;
	FILE *fp = NULL;
	char str[100];
	//linux��winͨ��
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
	//linux��winͨ��
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
//�����ַ���д�ļ�
int main400000(int argc,char* argv[])
{
	main04();
	main03();
	system("pause");
	return 1;

}