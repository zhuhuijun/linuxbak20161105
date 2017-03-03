#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define  DIM(a) (sizeof(a)/sizeof(char *))
/************************************************************************/
/* ��ؼ����ڱ��е�λ��                                                                     */
/************************************************************************/
int searchKeyTable(const char *table[],const int size,const char *key,int *pos){
	int rv=0;
	int i=0;
	if(table==NULL||key==NULL||pos==NULL){
		rv=-1;
		printf("searchKeyTable() null pointer:%d\n",rv);
		return rv;
	}
	for(i=0;i<size;i++){
		if(strcmp(key,table[i])==0){
			*pos=i;
			return rv;
		}
	}
	//û���ҵ�����
	if(i==size){
		*pos=-1;
	}
	return rv;
}
/************************************************************************/
/* ָ���������ϰ                                                                     */
/************************************************************************/
int main1222(int arg,char *args[]){
	int pos=0;
	int a[10];
	int i=0;
	char *c_keyword[]={
		"static",
		"case",
		"which",
		"do"
	};
	searchKeyTable(c_keyword,DIM(c_keyword),"do",&pos);
	printf("pos:%d\n",pos);
	printf("hello,world\n");
	system("pause");
}