/*
1.����ָ���״�ģ��                         

*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct Teacher{
	char name[64];
	int age;
}Teacher;


Teacher *createTeacher(){
	Teacher *tmp = (Teacher *)malloc(sizeof(struct Teacher));
	return tmp;
}

int createTeacher2(Teacher **p){
	Teacher *tmp = NULL;
	if(p ==NULL){//��Ҫ���ű��˴��ĵ�ַ�ǿ��õ�
		return -1;
	}
	tmp= (Teacher *)malloc(sizeof(struct Teacher));
	*p =tmp;
	return 0;
}
//
int main6094395(int argc, char* argv[])
{	
	Teacher *tmp2 = NULL;
	Teacher *tmp =createTeacher();
	tmp2 =createTeacher2(&tmp2);
	if (tmp2 != NULL){
		free(tmp2);
	}
	{
		char **p2 = NULL;
		char ***p3 = NULL;
		p2 = 0x1;
		p3 = 0x3;

		p3 = &p2;
		*p3 = 0x89;//����޸�p2��ֵ
		printf("%d\n",p2);
	}
	system("pause");
	return 1;
}	