#include "stdlib.h"
#include "stdio.h"
#include "string.h"
//��������
typedef struct TriTNode 
{
	int data;
	//���Һ���ָ��
	struct TriTNode *lchild, *rchild;
	struct TriTNode *parent;
}TriTNode, *TriTree;


//˫������
#define MAX_TREE_SIZE 100
typedef struct BPTNode
{
	int data;
	int *parent; //ָ��˫�׵�ָ��
	char LRTag; //���Һ��ӱ�־��
}BPTNode;

typedef struct BPTree
{
	BPTNode nodes[MAX_TREE_SIZE]; //��Ϊ�ڵ�֮���Ƿ�ɢ�ģ���Ҫ�ѽڵ�洢��������
	int num_node;  //�ڵ���Ŀ
	int root; //������λ�� //ע�����洢���Ǹ��׽ڵ���������±�
}BPTree;

//�������� 
typedef struct BiTNode
{
	int data;
	struct BiTNode *lchild, *rchild; //���� �Һ���
}BiTNode;

void PreOrder(BiTNode *T)
{
	if (T != NULL)
	{
		printf("%d ", T->data);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}
void PostOrder(BiTNode *T)
{
	if (T != NULL)
	{
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		printf("%d ", T->data);
	}
}
void InOrder(BiTNode *T)
{
	if (T != NULL)
	{
		InOrder(T->lchild);
		printf("%d ", T->data);
		InOrder(T->rchild);
	}
}
int g_count=0;
void Count_Leaf(BiTNode* T){
	if(T!=NULL)
	{
		if(T->lchild==NULL&&T->rchild==NULL){
			g_count++;
		}
		Count_Leaf(T->lchild);
		Count_Leaf(T->rchild);
	}
}
void Count_Leaf2(BiTNode* T,int *ncount){
	if(T!=NULL)
	{

		Count_Leaf2(T->lchild,ncount);
		Count_Leaf2(T->rchild,ncount);
		if(T->lchild==NULL&&T->rchild==NULL){
			(*ncount) ++;
		}
	}
}

void main(int argc,char* argv[]){
	BiTNode b1,b2,b3,b4,b5;
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

	printf(">>>>>>>>>>>>>>>>>>>>�������\n");
	PreOrder(&b1);

	printf("\n>>>>>>>>>>>>>>>>>>>>�������\n");
	PostOrder(&b1);
	g_count=0;
	Count_Leaf(&b1);
	printf("\n����Ҷ�ӽڵ�ĸ���:%d\n",g_count);
	Count_Leaf2(&b1,&mycount);
	printf("\n����Ҷ�ӽڵ�ĸ���2:%d\n",mycount);
	{
		int ncoutn = 0;
		Count_Leaf2(&b1, &ncoutn);
		printf("\nҶ�ӽ�����:%d\n", ncoutn);
	}
	printf("hello,world!\n");
	system("pause");
}