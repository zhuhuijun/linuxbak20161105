#include "stdio.h"
#include "stdlib.h"
#include "string.h"
//����������ҵ�����ݵ���������
typedef struct linkList{
	int age;
	char name[64];//ҵ������
	struct linkList *next;
} linkList;

typedef struct AdvLinkList{
	struct linkList *next;
} AdvLinkList;

//ҵ�����ݰ�������
struct AdvTeacher{
	char name[32];
	int age;
	char *p;
	AdvLinkList *node;
};
//�ṹ���ƫ������
int main5001(int argc,char* argv[])
{
	int i=0;
	struct AdvTeacher *p = NULL;
	struct AdvTeacher t1;

	p = &t1;
	printf("age:%d\n",p->age);

	p = p+1;
	p = p -1;
	p = p -p;
	i = (int ) (&(p->age));
	printf("i:%d\n",i);
	system("pause");
	return 1;
}

int main555555555(int argc,char* argv[])
{
	int i=0;
	//��0����ռ�����ַת��
	//ֻ�ǰѵ�ַ�ռ�����һ������ת��
	((struct AdvTeacher *) 0);
	// -> ֻ�����Ǹ�Ѱַ�������Ǽ���age�ĵ�ַ�����û����age���ڵ��ڴ�ռ��д����
	//Ѱַ����ֻ��cpu��+ -����
	//����Ԫ������� 0 ƫ���˶���
	//�ṹ���и�����������ڽṹ������˶���
	i = (int )&(((struct AdvTeacher *) 0)->age);
	printf("i:%d\n",i);
	system("pause");
	return 1;
}