#include "stdio.h"
#include "stdlib.h"
#include "string.h"
//�Զ���һ����������  �������͵ı����ǹ̶���С�ڴ��ı���
//c++��c �ṹ���ڶ���ṹ�����͵ı���ʱ���������Ĵ����ǲ�һ����

struct TeacherBak{
	char name[64];//˳��һ���ڴ��С��һ��,�����ڴ�����Ĵ�С��ŵĿ��ܻ��������ֽ�
	int age;
};
/************************************************************************/
/* ��һ�ֲ�ʹ��ָ��ķ�ʽ(�ṹ������������ʱ���˻���ʲô��)                                                                     */
/************************************************************************/
int copy01(struct TeacherBak from,struct TeacherBak to){
	memcpy(&to,&from,sizeof(struct TeacherBak));
	return 1;
}
int copy02(struct TeacherBak *from,struct TeacherBak *to){
	memcpy(to,from,sizeof(struct TeacherBak));
	return 1;
}
int main(int argc,char* args[]){
	struct TeacherBak t1={"t1",34};
	struct TeacherBak t2;
	struct TeacherBak t3={"t3",34};
	//�ṹ�������Ǹ�������,�ṹ��һ��������һ��ָ��
	struct TeacherBak *p=NULL;
	t2=t1;//����"="�������ǳ�ʼ��
	p=&t1;
	printf("t2.name:%s\n",t2.name);
	printf("p->name:%s\n",p->name);
	//ʹ��memcpy��������ṹ���copy
	memcpy(&t2,&t1,sizeof(struct TeacherBak));
	printf("t2.name:%s\n",t2.name);
	printf("p->name:%s\n",p->name);
	//�ṹ��copy���Լ����帳ֵ�ķ�ʽ
	copy01(t1,t3);//��������Ϊ��t1 copy ��from 
	//�� t3 copy �� to ��copy01�н�from copy��to
	//��t3 û��ϵ//��е���޸��βκ�ʵ��û���κι�ϵ
	printf("copy01 after t3.name:%s\n",t3.name);
	copy02(&t1,&t3);//�޸���ʵ����ָ���ڴ�ռ�
	printf("copy02 after t3.name:%s\n",t3.name);
	system("pause");
}