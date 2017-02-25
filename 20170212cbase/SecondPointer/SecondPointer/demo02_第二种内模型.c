#include "stdio.h"
#include "stdlib.h"
#include "string.h"
/************************************************************************/
/* 打印函数                                                                     */
/************************************************************************/
//指针类型不一样->内存模型不一样
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
/* 排序方法                                                                     */
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
//第二种内存模型
int main0202(int arg,char *args[]){
	int i=0;
	int j=0;
	char tmp[30];//数组名代表首元素的地址
	char MyArray[10][30]={"ccccc", "aaaa", "bbbb","11111"};
//MyArry代表的意思?
	printf("排序之前\n");
	printArray22(MyArray,4);
	sortArray2(MyArray,4);
	printf("排序之后\n");
	printArray22(MyArray,4);
	system("pause");
	return 1;
}