#include "stdlib.h"
#include "stdio.h"
#include "seqstack.h"
#include "seqlist.h"
//使用线性表创建栈
SeqStack* SeqStack_Create(int capacity){
	return SeqList_Create(capacity);
}
void SeqStack_Destory(SeqStack* stack){

}
void SeqStack_Clear(SeqStack* stack)
{

}
int SeqStack_Push(SeqStack* stack,void* item)
{

	return 0;
}
void* SeqStack_Pop(SeqStack* stack){
	return NULL;
}
void* SeqStack_Top(SeqStack* stack){
	return NULL;
}
int SeqStack_Size(SeqStack* stack)
{
	return 0;
}
int SeqStack_Capacity(SeqStack* stack){
	return 0;
}