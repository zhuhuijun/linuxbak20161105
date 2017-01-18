#include "stdlib.h"
#include "stdio.h"
#include "string.h"
//三叉链表
typedef struct TriTNode 
{
	int data;
	//左右孩子指针
	struct TriTNode *lchild, *rchild;
	struct TriTNode *parent;
}TriTNode, *TriTree;


//双亲链表
#define MAX_TREE_SIZE 100
typedef struct BPTNode
{
	int data;
	int *parent; //指向双亲的指针
	char LRTag; //左右孩子标志域
}BPTNode;

typedef struct BPTree
{
	BPTNode nodes[MAX_TREE_SIZE]; //因为节点之间是分散的，需要把节点存储到数组中
	int num_node;  //节点数目
	int root; //根结点的位置 //注意此域存储的是父亲节点在数组的下标
}BPTree;

//二叉链表 
typedef struct BiTNode
{
	int data;
	struct BiTNode *lchild, *rchild; //左孩子 右孩子
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
//二叉树的复制
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

	//构建关系
	b1.lchild=&b2;
	b1.rchild=&b3;
	b2.lchild=&b4;
	b3.lchild=&b5;
	pnew = copyTree(&b1);
	printf("树的copy结果:\n");
	PreOrder1(pnew);
	printf("hello,world!\n");
	system("pause");
}