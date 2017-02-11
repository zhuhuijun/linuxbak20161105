#include "stdio.h"
#include "stdlib.h"
#include "string.h"
typedef struct TeacherRSet{
	char *p1;
	char *p2;
} TeacherRSet;
int getTeacher(TeacherRSet **p){
		TeacherRSet *temp=NULL;
	if(p==NULL){
		return -1;
	}

	temp=(TeacherRSet *)malloc(sizeof(TeacherRSet));
	temp->p1=(char *)malloc(sizeof(20));
	temp->p2=(char *)malloc(sizeof(40));
	*p=temp;
	return 1;
}
void main(int argc,char *argv[]){
	TeacherRSet *p=NULL;
	int ret=0;
	ret = getTeacher(&p);
	if(p!=NULL){
		free(p);
	}
	printf("hello,world\n");
	system("pause");
}