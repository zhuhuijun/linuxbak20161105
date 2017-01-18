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
}BiTNode,*BiTree;
void PreOrder1(BiTNode *T)
{
	if (T != NULL)
	{
		printf("%d\n ", T->data);
		PreOrder1(T->lchild);
		PreOrder1(T->rchild);
	}
}
//////////////////////////////////////////////////////////////////////////
//�������ĸ���
BiTNode* copyTree(BiTNode* T){
	BiTNode* newtree=NULL,*BiL=NULL,*BiR=NULL;

	if(T==NULL){
		return NULL;
	}
	if(T->lchild!=NULL){
		BiL = copyTree(T->lchild);
	}else{
		BiL=NULL;
	}
	if(T->rchild!=NULL){
		BiR = copyTree(T->rchild);
	}else{
		BiR=NULL;
	}
	newtree=(BiTNode *)malloc(sizeof(BiTNode));
	newtree->lchild=BiL;
	newtree->rchild=BiR;
	newtree->data=T->data;
	return newtree;
}
void main02(int argc,char* argv[]){
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
	pnew = copyTree(&b1);
	printf("����copy���:\n");
	PreOrder1(pnew);
	printf("hello,world!\n");
	system("pause");
}