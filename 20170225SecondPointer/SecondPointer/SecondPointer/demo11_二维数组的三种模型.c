#include "stdio.h"
#include "stdlib.h"
#include "string.h"



int main11111(int arg,char *args[]){
	char **p3=NULL;
	int i;
	//ָ������
	char *p1[]={"123","456","789"};
	//��ά����
	char p2[3][4]={"123","456","789"};
	//�ֹ������ά����
	p3=(char **)malloc(3*sizeof(char *));//int array[3]
	for(i=0;i<3;i++){
		p3[i]=(char *)malloc(100 * sizeof(char));
		sprintf(p3[i],"%d%d%d",i,i,i);
	}
	system("pause");
	return 1;
}