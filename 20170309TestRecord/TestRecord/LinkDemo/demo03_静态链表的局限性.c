#include "stdio.h"
#include "stdlib.h"
#include "string.h"
typedef struct Student{
	char name[64];
	int age;
	struct Student *next;
} Student;
//��̬�����ʹ��
Student* main21()
{
	Student t1,t2,t3;
	struct Student *p;
	t1.age=10;
	t2.age=20;
	t3.age=30;
	t1.next=&t2;
	t2.next=&t3;
	t3.next=NULL;
	//��������׼������
	p = &t1;
	while(p){
		printf("age:%d \n",p->age);
		p = p->next;
	}
	return &t1;
}
//��̬����ķ�Χ�ͷ��ʾ�����
int main300000(int argc,char* argv[])
{
	struct Student *head = main21();//��ʱ���ı����޷����س���
	struct Student *p;
	p =head;
	while(p){
		printf("age:%d \n",p->age);
		p = p->next;
	}
	system("pause");
	return 1;
}