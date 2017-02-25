#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//第一种内存模型
int main01(int arg,char *args[]){
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
/* 打印函数                                                                     */
/************************************************************************/
int printArray(char **MyArray,int iNum){
	int i=0;
	for(i=0;i<iNum;i++){
		printf("%s ",MyArray[i]);
	}
	printf("\n");
}
/************************************************************************/
/* 排序方法                                                                     */
/************************************************************************/
int sortArray(char **MyArray,int iNum){
	int i=0;
	int j=0;
	char *tmp=NULL;
	for(i=0;i<iNum;i++){
		for(j=i+1;j<iNum;j++){
			if(strcmp(MyArray[i],MyArray[j])>0){
				//我们修改的是数组元素,只不过元素特殊一点,他是指针变量
				//指针变量和它指向的内存空间变量是两个不同概念
				tmp = MyArray[i];
				MyArray[i] = MyArray[j];
				MyArray[j] = tmp;
			}
		}
	}
}
//指针做函数参数
int main010101(int arg,char *args[]){
	//数组里面存的是地址//学术名叫指针数组
	char *MyArray[] = {"ccccc", "aaaa", "bbbb","11111"};
	printf("排序之前\n");
	printArray(MyArray,4);
	sortArray(MyArray,4);
	printf("排序之后\n");
	printArray(MyArray,4);
	system("pause");
	return 1;
}