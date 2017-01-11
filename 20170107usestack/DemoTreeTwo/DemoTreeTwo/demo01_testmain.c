#include "stdlib.h"
#include "stdio.h"
#include "string.h"

typedef struct BiTNode{
	int data;
	BiTNode* lchild;
	BiTNode* rchild;
}BiTNode;
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

	//������ϵ
	b1.lchild=&b2;
	b1.rchild=&b3;
	b2.lchild=&b4;
	b3.lchild=&b5;


	printf("hello,world!\n");
	system("pause");
}