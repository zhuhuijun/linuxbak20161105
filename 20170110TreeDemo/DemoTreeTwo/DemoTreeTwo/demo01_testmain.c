#include "stdlib.h"
#include "stdio.h"
#include "string.h"

typedef struct BiTNode{
	int data;
	BiTNode* lchild;
	BiTNode* rchild;
}BiTNode;
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


void main(int argc,char* argv[]){
	BiTNode b1,b2,b3,b4,b5;
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


	printf("hello,world!\n");
	system("pause");
}