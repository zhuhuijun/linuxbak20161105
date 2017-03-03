#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/************************************************************************/
/* 多维数组的本质                                                                     */
/************************************************************************/
int main0909090(int arg,char *args[]){
	int i;
	int j=0;
	int tmp=0;	//myarr是数组首元素的地址
	//是一个常量指针
	//myarr是一个数组指针
	//步长就是一维的数组指针的步长
	int myarr[3][5];
	int a[5]={1,3,5,7,9};
	int (*p)[5]=&a;

	for(i=0;i<5;i++){
		printf("%d ",(*p)[i]);
	}
	printf("\n");
	for(i=0;i<3;i++){
		for(j=0;j<5;j++){
			myarr[i][j]=tmp++;
		}
	}
	p=myarr;
	for(i=0;i<3;i++){
		for(j=0;j<5;j++){
			p[i][j]=tmp++;
			printf("%d ",p[i][j]);
		}
	}
		printf("\n");
	printf("myarr:%d,myarr+1:%d\n",myarr,myarr+1);
	printf("a:%d,a+1:%d\n",&a,&a+1);

	system("pause");
}