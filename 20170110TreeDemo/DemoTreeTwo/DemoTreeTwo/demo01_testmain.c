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
//求二叉树的深度
int GetDepth(BiTNode* T)
{
	int depthav=0,depthL=0,depthR=0;
	if(T==NULL){
		depthav=0;
		return depthav;
	}
	depthL=GetDepth(T->lchild);
	depthR=GetDepth(T->rchild);
	depthav=1+(depthL>depthR?depthL:depthR);
	return depthav;
}

void main01(int argc,char* argv[]){
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

	//构建关系
	b1.lchild=&b2;
	b1.rchild=&b3;
	b2.lchild=&b4;
	b3.lchild=&b5;

	printf(">>>>>>>>>>>>>>>>>>>>先序遍历\n");
	PreOrder(&b1);

	printf("\n>>>>>>>>>>>>>>>>>>>>后根遍历\n");
	PostOrder(&b1);
	g_count=0;
	Count_Leaf(&b1);
	printf("\n树的叶子节点的个数:%d\n",g_count);
	Count_Leaf2(&b1,&mycount);
	printf("\n树的叶子节点的个数2:%d\n",mycount);
	{
		int ncoutn = 0;
		Count_Leaf2(&b1, &ncoutn);
		printf("\n叶子结点个数:%d\n", ncoutn);
	}
	{
		int dep = GetDepth(&b1);
		printf("\n树的深度:%d\n", dep);
	}
	printf("hello,world!\n");
	system("pause");
}