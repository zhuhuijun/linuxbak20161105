#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//��һ���ڴ�ģ��
int main0100000000000(int arg,char *args[]){
	int i=0;
	int j=0;
	char *tmp=NULL;
	char *MyArray[] = {"ccccc", "aaaa", "bbbb","11111"};

	for(i=0;i<4;i++){
		printf("%s ",MyArray[i]);
	}
	printf("\n");
	for(i=0;i<4;i++){
		for(j=i+1;j<4;j++){
			if(strcmp(MyArray[i],MyArray[j])>0){
				tmp = MyArray[i];
				MyArray[i] = MyArray[j];
				MyArray[j] = tmp;
			}
		}
	}
	for(i=0;i<4;i++){
		printf("%s ",MyArray[i]);
	}
	printf("\n");
	system("pause");
	return 1;
}
/************************************************************************/
/* ��ӡ����                                                                     */
/************************************************************************/
int printArray(char **MyArray,int iNum){
	int i=0;
	for(i=0;i<iNum;i++){
		printf("%s ",MyArray[i]);
	}
	printf("\n");
}
/************************************************************************/
/* ���򷽷�                                                                     */
/************************************************************************/
int sortArray(char **MyArray,int iNum){
	int i=0;
	int j=0;
	char *tmp=NULL;
	for(i=0;i<iNum;i++){
		for(j=i+1;j<iNum;j++){
			if(strcmp(MyArray[i],MyArray[j])>0){
				//�����޸ĵ�������Ԫ��,ֻ����Ԫ������һ��,����ָ�����
				//ָ���������ָ����ڴ�ռ������������ͬ����
				tmp = MyArray[i];
				MyArray[i] = MyArray[j];
				MyArray[j] = tmp;
			}
		}
	}
}
//ָ������������
int main010101(int arg,char *args[]){
	//�����������ǵ�ַ//ѧ������ָ������
	char *MyArray[] = {"ccccc", "aaaa", "bbbb","11111"};
	printf("����֮ǰ\n");
	printArray(MyArray,4);
	sortArray(MyArray,4);
	printf("����֮��\n");
	printArray(MyArray,4);
	system("pause");
	return 1;
}