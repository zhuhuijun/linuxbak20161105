#include "stdlib.h"
#include "stdio.h"
#include "seqstack.h"
#include "seqlist.h"
//使用线性表创建栈
SeqStack* SeqStack_Create(int capacity){
	return SeqList_Create(capacity);
}
void SeqStack_Destory(SeqStack* stack){
	SeqList_Destroy(stack);
}
void SeqStack_Clear(SeqStack* stack)
{
	SeqList_Clear(stack);
}
int SeqStack_Push(SeqStack* stack,void* item)
{
	SeqList_Insert(stack,item,SeqList_Length(stack));
	return 0;
}
void* SeqStack_Pop(SeqStack* stack){
	return SeqList_Delete(stack,SeqList_Length(stack)-1);
}
void* SeqStack_Top(SeqStack* stack){
	return SeqList_Get(stack,SeqList_Length(stack)-1);
}
int SeqStack_Size(SeqStack* stack)
{
	return SeqList_Length(stack);
}
int SeqStack_Capacity(SeqStack* stack){
	return SeqList_Capacity(stack);
}