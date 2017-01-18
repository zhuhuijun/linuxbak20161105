#include "iostream"
#include "stack"
using namespace std;
//�������� 
typedef struct BiTNode
{
	int data;
	struct BiTNode *lchild, *rchild; //���� �Һ���
}BiTNode,*BiTree;

BiTNode* GoFarLeft(BiTNode* T,stack<BiTNode *> &s){
	if(T==NULL){
		return NULL;
	}
	while(T->lchild)
	{
		s.push(T);
		T=T->lchild;
	}
	return T;
}
void inOrder2(BiTNode* T){
	stack<BiTNode *>s;
	BiTNode *t = GoFarLeft(T, s); //������������

	while(t)
	{
		printf("%d ", t->data);
		if (t->rchild) //������Һ��� �ظ�12����
		{
			t = GoFarLeft(T->rchild, s);
		}
		else if (!s.empty())  //���û���Һ��ӣ�˵���ýڵ��������ϣ���Ҫ���ء�
		{
			t  = s.top(); //�ǿվʹ�ջ����Ԫ��
			s.pop();
		}
		else //���û���Һ��ӣ�����ջΪ�� t = NULL;
		{
			t = NULL;
		}
	}
}
void main(int argc,char* argv[]){
	BiTNode b1,b2,b3,b4,b5;
	BiTNode* pnew=NULL;
	int mycount=0;
	memset(&b1,0,sizeof(BiTNode));
	memset(&b2,0,sizeof(BiTNode));
	memset(&b3,0,sizeof(BiTNode));
	memset(&b4,0,sizeof(BiTNode));
	memset(&b5,0,sizeof(BiTNode));
	b1.data=1;
	b2.data=2;
	b3.data=3;
	b4.data=4;
	b5.data=5;

	//������ϵ
	b1.lchild=&b2;
	b1.rchild=&b3;
	b2.lchild=&b4;
	b3.lchild=&b5;
	inOrder2(&b1);
	printf("hello,world!\n");
	system("pause");
}