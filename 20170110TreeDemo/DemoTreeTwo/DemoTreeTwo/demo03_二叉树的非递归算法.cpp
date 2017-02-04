#include "iostream"
#include "stack"
using namespace std;
//二叉链表 
typedef struct BiTNode
{
	int data;
	struct BiTNode *lchild, *rchild; //左孩子 右孩子
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
	BiTNode *t = GoFarLeft(T, s); //中序遍历的起点

	while(t)
	{
		printf("%d ", t->data);
		if (t->rchild) //如果有右孩子 重复12步骤
		{
			t = GoFarLeft(T->rchild, s);
		}
		else if (!s.empty())  //如果没有右孩子，说明该节点的树放完毕，需要返回。
		{
			t  = s.top(); //非空就从栈顶拿元素
			s.pop();
		}
		else //如果没有右孩子，并且栈为空 t = NULL;
		{
			t = NULL;
		}
	}
}
void main03(int argc,char* argv[]){
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
	inOrder2(&b1);
	printf("hello,world!\n");
	system("pause");
}