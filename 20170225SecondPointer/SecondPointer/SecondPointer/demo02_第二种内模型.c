#include "stdio.h"
#include "stdlib.h"
#include "string.h"
/************************************************************************/
/* ��ӡ����                                                                     */
/************************************************************************/
//ָ�����Ͳ�һ��->�ڴ�ģ�Ͳ�һ��
int printArray2(char **MyArray,int iNum){
	int i=0;
	for(i=0;i<iNum;i++){
		printf("%s ",MyArray[i]);
	}
	printf("\n");
}
int printArray22(char MyArray[10][30],int iNum){
	int i=0;
	for(i=0;i<iNum;i++){
		printf("%s ",MyArray[i]);
	}
	printf("\n");
}
/************************************************************************/
/* ���򷽷�                                                                     */
/************************************************************************/
int sortArray2(char MyArray[10][30],int iNum){
	int i=0;
	int j=0;
	char tmp[30];
	for(i=0;i<iNum;i++){
		for(j=i+1;j<iNum;j++){
			if(strcmp(MyArray[i],MyArray[j])>0){
				strcpy(tmp,MyArray[i]);
				strcpy(MyArray[i],MyArray[j]);
				strcpy(MyArray[j],tmp);
			}
		}
	}
}
//�ڶ����ڴ�ģ��
int main0202(int arg,char *args[]){
	int i=0;
	int j=0;
	char tmp[30];//������������Ԫ�صĵ�ַ
	char MyArray[10][30]={"ccccc", "aaaa", "bbbb","11111"};
//MyArry�������˼?
	printf("����֮ǰ\n");
	printArray22(MyArray,4);
	sortArray2(MyArray,4);
	printf("����֮��\n");
	printArray22(MyArray,4);
	system("pause");
	return 1;
}